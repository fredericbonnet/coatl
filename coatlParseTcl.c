/*
 * File: coatlParseTcl.c
 *
 *	TODO
 */

#include "include/coatl.h"
#include "coatlInternal.h"

#include "coatlParseInt.h"
#include "coatlNumberInt.h"

#include <limits.h>


/*---------------------------------------------------------------------------
 * Internal Function: ParseTclBackslash
 *
 *	Parse a backslash expression using Tcl syntax (Dodekalogue rule [9]).
 *
 * Arguments:
 *	begin	- Beginning of sequence to parse (including backslash char).
 *	end	- End of sequence.
 *
 * Results:
 *	Nonzero if success. Additionally:
 *
 *	charPtr    - Resulting character upon success.
 *
 * Side effects:
 *	*begin* is moved just past the parsed sequence.
 *---------------------------------------------------------------------------*/

int
ParseTclBackslash(
    Col_RopeIterator begin,
    Col_RopeIterator end,
    Col_Char *charPtr)
{
    Col_Char c;
    uintmax_t v;

    ASSERT(Col_RopeIterAt(begin) == '\\');
    Col_RopeIterNext(begin);

    if (Col_RopeIterCompare(begin, end) >= 0) {
	/*
	 * Single trailing backslash.
	 */

	*charPtr = '\\';
	return 1;
    }

    c = Col_RopeIterAt(begin);
    switch (c) {
    /*
     * Know escapes. Use numeric values instead of C escapes for known sequence,
     * to ensure compiler independence.
     */

    case 'a': c = 0x7; break;
    case 'b': c = 0x8; break;
    case 'f': c = 0xc; break;
    case 'n': c = 0xa; break;
    case 'r': c = 0xd; break;
    case 't': c = 0x9; break;
    case 'v': c = 0xb; break;

    case '\n': 
	/*
	 * Backslash-newline, consume all space and tab chars and substitute
	 * by space.
	 */

	for (Col_RopeIterNext(begin); Col_RopeIterCompare(begin, end) < 0;
		Col_RopeIterNext(begin)) {
	    switch (Col_RopeIterAt(begin)) {
	    case ' ': 
	    case '\t': continue;
	    }
	    break;
	}
	*charPtr = ' ';
	return 1;

    case 'x':
	/*
	 * If no trailing digits, return first character.
	 */

	Col_RopeIterNext(begin);
	if (Col_RopeIterCompare(begin, end) >= 0) {
	    *charPtr = c;
	    return 1;
	}

	/*
	 * Consume all hex digits, only keep last 2 (i.e. lower 8 bits).
	 */

	if (charPtr) {
	    Col_RopeIterator it;
	    Col_RopeIterSet(it, begin);
	    if (!ParseUInt(it, end, 0, SIZE_MAX, 16, NULL)) return 0;
	    if (Col_RopeIterIndex(it) - Col_RopeIterIndex(begin) > 2) {
		/*
		 * Only keep last 2 characters.
		 */
		 
		Col_RopeIterSet(begin, it);
		Col_RopeIterBackward(begin, 2);
	    }
	    REQUIRE(ReadUInt(begin, it, 16, NULL, &v));
	    ASSERT(v <= 0xFF);
	    *charPtr = (Col_Char) v;
	    return 1;
	} else {
	    return ParseUInt(begin, end, 0, SIZE_MAX, 16, NULL);
	}

    case 'u':
	/*
	 * If no trailing digits, return first character.
	 */

	Col_RopeIterNext(begin);
	if (Col_RopeIterCompare(begin, end) >= 0) {
	    *charPtr = c;
	    return 1;
	}


	/*
	 * Consume up to 4 hex digits.
	 */

	if (charPtr) {
	    Col_RopeIterator it;
	    Col_RopeIterSet(it, begin);
	    if (!ParseUInt(it, end, 0, 4, 16, NULL)) return 0;
	    REQUIRE(ReadUInt(begin, it, 16, NULL, &v));
	    *charPtr = (Col_Char) v;
	    return 1;
	} else {
	    return ParseUInt(begin, end, 0, 4, 16, NULL);
	}

    default:
	if (c >= '0' && c <= '7') {
	    /*
	     * Octal digits, give Unicode codepoint. Assume octal digits 
	     * codepoints are contiguous (true in Unicode locale).
	     */

	    if (charPtr) {
		Col_RopeIterator it;
		Col_RopeIterSet(it, begin);
		if (!ParseUInt(it, end, 0, 3, 8, NULL)) return 0;
		REQUIRE(ReadUInt(begin, it, 8, NULL, &v));
		*charPtr = (Col_Char) v;
		return 1;
	    } else {
		return ParseUInt(begin, end, 0, 3, 8, NULL);
	    }
	}

	/*
	 * Unknown sequence, return character as is.
	 */
    }

    Col_RopeIterNext(begin);
    *charPtr = c;
    return 1;
}

/*---------------------------------------------------------------------------
 * Internal Function: ParseTclString
 *
 *	Parse a string using Tcl syntax (Dodekalogue rules [4] and [9]).
 *
 * Arguments:
 *	begin	- Beginning of sequence to parse (including open quote).
 *	end	- End of sequence.
 *
 * Results:
 *	Nonzero if success. Additionally:
 *
 *	stringPtr    - Resulting string upon success.
 *
 * Side effects:
 *	*begin* is moved just past the parsed sequence.
 *---------------------------------------------------------------------------*/

int
ParseTclString(
    Col_RopeIterator begin,
    Col_RopeIterator end,
    Col_Word *stringPtr)
{
    Col_RopeIterator firstUnchanged = COL_ROPEITER_NULL;
    Col_Word strbuf = Col_NewStringBuffer(0, COL_UCS);//TODO optimize buffer length?

    ASSERT(Col_RopeIterAt(begin) == '"');
    for (Col_RopeIterNext(begin); Col_RopeIterCompare(begin, end) < 0;
	    Col_RopeIterNext(end)) {
	Col_Char c = Col_RopeIterAt(begin);
	switch (c) {
	case '"':
	    /*
	     * End of string.
	     */

	    if (!Col_RopeIterNull(firstUnchanged)) {
		/*
		 * Append regular character sequence.
		 */

		Col_StringBufferAppendSequence(strbuf, firstUnchanged, begin);
		Col_RopeIterSetNull(firstUnchanged);
	    }

	    /*
	     * Consume close quote and return frozen buffer.
	     */

	    Col_RopeIterNext(begin);
	    *stringPtr = Col_StringBufferFreeze(strbuf);
	    return 1;

	case '\\':
	    /*
	     * Backslash sequence.
	     */

	    if (!Col_RopeIterNull(firstUnchanged)) {
		/*
		 * Append regular character sequence.
		 */

		Col_StringBufferAppendSequence(strbuf, firstUnchanged, begin);
		Col_RopeIterSetNull(firstUnchanged);
	    }

	    /*
	     * Unescape character.
	     */

	    if (!ParseTclBackslash(begin, end, &c)) return 0;
	    Col_StringBufferAppendChar(strbuf, c);
	    break;

	default:
	    /*
	     * Regular character, remember position.
	     */

	    if (Col_RopeIterNull(firstUnchanged)) {
		Col_RopeIterSet(firstUnchanged, begin);
	    }
	}

    }

    /*
     * Reached end of sequence, syntax is invalid.
     */

    return 0;
}

/*---------------------------------------------------------------------------
 * Internal Function: ParseTclBraces
 *
 *	Parse a braced block using Tcl syntax (Dodekalogue rule [6]).
 *
 * Arguments:
 *	begin	- Beginning of sequence to parse (including open brace).
 *	end	- End of sequence.
 *
 * Results:
 *	Nonzero if success. Additionally:
 *
 *	stringPtr    - Resulting string upon success.
 *
 * Side effects:
 *	*begin* is moved just past the parsed sequence.
 *---------------------------------------------------------------------------*/

int
ParseTclBraces(
    Col_RopeIterator begin,
    Col_RopeIterator end,
    Col_Word *stringPtr)
{
    Col_RopeIterator firstUnchanged = COL_ROPEITER_NULL;
    Col_Word strbuf = Col_NewStringBuffer(0, COL_UCS);//TODO optimize buffer length?
    size_t nest;
    int escape;

    ASSERT(Col_RopeIterAt(begin) == '{');
    for (Col_RopeIterNext(begin), nest = 0, escape = 0; 
	    Col_RopeIterCompare(begin, end) < 0; Col_RopeIterNext(end)) {
	Col_Char c = Col_RopeIterAt(begin);
	if (escape) {
	    /*
	     * Escaped sequence, previous char was a backslash.
	     */

	    ASSERT(Col_RopeIterNull(firstUnchanged));
	    if (c != '\n') {
		/*
		 * Regular character, remember position.
		 */

		Col_RopeIterSet(firstUnchanged, begin);
		escape = 0;
		continue;
	    }

	    /*
	     * Backslash-newline, consume all space and tab chars and substitute
	     * by single space.
	     */

	    for (Col_RopeIterNext(begin); Col_RopeIterCompare(begin, end) < 0;
		    Col_RopeIterNext(begin)) {
		c = Col_RopeIterAt(begin);
		switch (c) {
		case ' ': 
		case '\t': continue;
		}
		break;
	    }
	    if (Col_RopeIterCompare(begin, end) >= 0) break;
	    Col_StringBufferAppendChar(strbuf, ' ');

	    /*
	     * Resume character processing below.
	     */
	}

	switch (c) {
	case '{':
	    /*
	     * Open nested block.
	     */

	    nest++;
	    break;

	case '}':
	    if (nest--) {
		/*
		 * Close nested block.
		 */

		continue;
	    }

	    /*
	     * End of braced block.
	     */

	    if (!Col_RopeIterNull(firstUnchanged)) {
		/*
		 * Append regular character sequence.
		 */

		Col_StringBufferAppendSequence(strbuf, firstUnchanged, begin);
		Col_RopeIterSetNull(firstUnchanged);
	    }

	    /*
	     * Consume close brace and return frozen buffer.
	     */

	    Col_RopeIterNext(begin);
	    *stringPtr = Col_StringBufferFreeze(strbuf);
	    return 1;

	case '\\':
	    /*
	     * Backslash sequence.
	     */

	    if (!Col_RopeIterNull(firstUnchanged)) {
		/*
		 * Append regular character sequence.
		 */

		Col_StringBufferAppendSequence(strbuf, firstUnchanged, begin);
		Col_RopeIterSetNull(firstUnchanged);
	    }
	    escape = 1;
	    break;

	default:
	    /*
	     * Regular character, remember position.
	     */

	    if (Col_RopeIterNull(firstUnchanged)) {
		Col_RopeIterSet(firstUnchanged, begin);
	    }
	}

    }

    /*
     * Reached end of sequence, syntax is invalid.
     */

    return 0;
}
