/*
 * File: coatlJson.c
 *
 *	This file implements the JSON features of CoATL.
 *
 * See also:
 *	<coatlJson.h>
 */

#include "include/coatl.h"
#include "coatlInternal.h"

#include "coatlParseInt.h"
#include "coatlNumberInt.h"

#include <limits.h>


//FIXME
int			ParseJsonObject(Col_RopeIterator begin, 
			    Col_RopeIterator end, Col_Word *mapPtr);
int			ParseJsonArray(Col_RopeIterator begin, 
			    Col_RopeIterator end, Col_Word *listPtr);

static const Col_Char whitespace[] = {0x20, 0x09, 0x0A, 0x0D, COL_CHAR_INVALID};


/*---------------------------------------------------------------------------
 * Internal Function: ParseJsonLiteral
 *
 *	Parse a JSON literal. The following literals are recognized:
 *
 *	true    - Boolean true, gives the integer word 1.
 *	false   - Boolean false, gives the integer word 0.
 *	null    - Null value, gives the nil word.
 *
 * Arguments:
 *	begin	- Beginning of sequence to parse (including backslash char).
 *	end	- End of sequence.
 *
 * Results:
 *	Nonzero if success. Additionally:
 *
 *	valuePtr    - If non-NULL, resulting value upon success.
 *
 * Side effects:
 *	*begin* is moved just past the parsed sequence.
 *---------------------------------------------------------------------------*/

int
ParseJsonLiteral(
    Col_RopeIterator begin,
    Col_RopeIterator end,
    Col_Char *valuePtr)
{
    Col_Char c;

    ASSERT(Col_RopeIterCompare(begin, end) < 0);
    switch (Col_RopeIterAt(begin)) {
    case 't':
	/*
	 * 'true'.
	 */
	
	NEXT_CHAR(c, begin, end) break;
	if (c != 'r') break;
	NEXT_CHAR(c, begin, end) break;
	if (c != 'u') break;
	NEXT_CHAR(c, begin, end) break;
	if (c != 'e') break;
	if (valuePtr) *valuePtr = Col_NewIntWord(1);
	return 1;

    case 'f':
	/*
	 * 'false'.
	 */
	
	NEXT_CHAR(c, begin, end) break;
	if (c != 'a') break;
	NEXT_CHAR(c, begin, end) break;
	if (c != 'l') break;
	NEXT_CHAR(c, begin, end) break;
	if (c != 's') break;
	NEXT_CHAR(c, begin, end) break;
	if (c != 'e') break;
	if (valuePtr) *valuePtr = Col_NewIntWord(0);
	return 1;

    case 'n':
	/*
	 * 'null'.
	 */
	
	NEXT_CHAR(c, begin, end) break;
	if (c != 'u') break;
	NEXT_CHAR(c, begin, end) break;
	if (c != 'l') break;
	NEXT_CHAR(c, begin, end) break;
	if (c != 'l') break;
	if (valuePtr) *valuePtr = COL_NIL;
	return 1;
    }
    
    /*
     * Invalid syntax.
     */

    return 0;
}

/*---------------------------------------------------------------------------
 * Internal Function: ParseJsonNumber
 *
 *	Parse a JSON number. The following formats are recognized:
 *
 *	true    - Boolean true, gives the integer word 1.
 *	false   - Boolean false, gives the integer word 0.
 *	null    - Null value, gives the nil word.
 *
 * Arguments:
 *	begin	- Beginning of sequence to parse (including backslash char).
 *	end	- End of sequence.
 *
 * Results:
 *	Nonzero if success. Additionally:
 *
 *	valuePtr    - If non-NULL, resulting value upon success.
 *	realPtr	    - If non-NULL, whether number was real or integer.
 *
 * Side effects:
 *	*begin* is moved just past the parsed sequence.
 *---------------------------------------------------------------------------*/

int
ParseJsonNumber(
    Col_RopeIterator begin,
    Col_RopeIterator end,
    Col_Word *valuePtr,
    int *realPtr)
{
    Col_Char c;

    if (valuePtr) {
	/*
	 * First check syntax.
	 */

	Col_RopeIterator it;
	int real = 0, neg = 0;
	Col_RopeIterSet(it, begin);
	if (!ParseJsonNumber(begin, end, NULL, &real)) return 0;

	/*
	 * Then scan number.
	 */

	if (real) {
	    REQUIRE(Coatl_ReadFloatWord(it, begin, NULL, 0, valuePtr));
	} else {
	    REQUIRE(Coatl_ReadIntWord(it, begin, NULL, 0, valuePtr));
	}
	ASSERT(Col_RopeIterCompare(it, begin) == 0);
	if (realPtr) *realPtr = real;
	return 1;
    }

    if (realPtr) *realPtr = 0;
    GET_CHAR(c, begin, end) return 0;
    if (c == '-') {	
	/*
	 * Minus sign.
	 */

	NEXT_CHAR(c, begin, end) return 0;
    }
    if (c == '0') {
	/*
	 * Leading zero must not be alone.
	 */

	NEXT_CHAR(c, begin, end) return 1;
    } else if (c >= '1' && c <= '9') {
	/*
	 * Digit sequence.
	 */

	NEXT_CHAR(c, begin, end) return 1;
	while (c >= '0' && c <= '9') {
	    NEXT_CHAR(c, begin, end) return 1;
	}
    } else return 0;
    if (c == '.') {
	/*
	 * Decimal point must be followed by 1+ digits.
	 */

	if (realPtr) *realPtr = 1;
	NEXT_CHAR(c, begin, end) return 0;
	if (!(c >= '0' && c <= '9')) return 0;
	NEXT_CHAR(c, begin, end) return 1;
	while (c >= '0' && c <= '9') {
	    NEXT_CHAR(c, begin, end) return 1;
	}
    }
    if (c == 'e' || c == 'E') {
	/*
	 * Exponent.
	 */

	if (realPtr) *realPtr = 1;
	NEXT_CHAR(c, begin, end) return 0;
	if (c == '+' || c == '-') {
	    /*
	     * Exponent sign.
	     */

	    NEXT_CHAR(c, begin, end) return 0;
	}

	/*
	 * Exponent value.
	 */

	if (!(c >= '0' && c <= '9')) return 0;
	NEXT_CHAR(c, begin, end) return 1;
	while (c >= '0' && c <= '9') {
	    NEXT_CHAR(c, begin, end) return 1;
	}
    }
    return 1;
}


/*---------------------------------------------------------------------------
 * Internal Function: ParseJsonBackslash
 *
 *	Parse a backslash expression using JSON syntax.
 *
 * Arguments:
 *	begin	- Beginning of sequence to parse (including backslash char).
 *	end	- End of sequence.
 *
 * Results:
 *	Nonzero if success. Additionally:
 *
 *	charPtr    - If non-NULL, resulting character upon success.
 *
 * Side effects:
 *	*begin* is moved just past the parsed sequence.
 *---------------------------------------------------------------------------*/

int
ParseJsonBackslash(
    Col_RopeIterator begin,
    Col_RopeIterator end,
    Col_Char *charPtr)
{
    Col_Char c;
    uintmax_t v;

    ASSERT(Col_RopeIterCompare(begin, end) < 0);
    ASSERT(Col_RopeIterAt(begin) == '\\');
    NEXT_CHAR(c, begin, end) return 0;
    switch (c) {
    /*
     * Know escapes. Use numeric values instead of C escapes for known sequence,
     * to ensure compiler independence.
     */

    case '"':
    case '\\':
    case '/':
	break;
    case 'b': c = 0x8; break;
    case 'f': c = 0xc; break;
    case 'n': c = 0xa; break;
    case 'r': c = 0xd; break;
    case 't': c = 0x9; break;

    case 'u':
	/*
	 * Consume 4 hex digits.
	 */

	NEXT_CHAR(c, begin, end) return 0;
	if (charPtr) {
	    Col_RopeIterator it;
	    Col_RopeIterSet(it, begin);
	    if (!ParseUInt(it, end, 4, 4, 16, NULL)) return 0;
	    REQUIRE(ReadUInt(begin, it, 16, NULL, &v));
	    *charPtr = (Col_Char) v;
	    return 1;
	} else {
	    return ParseUInt(begin, end, 4, 4, 16, NULL);
	}

    default:
	/*
	 * Unknown sequence.
	 */

	return 0;
    }

    Col_RopeIterNext(begin);
    if (charPtr) *charPtr = c;
    return 1;
}

/*---------------------------------------------------------------------------
 * Internal Function: ParseJsonString
 *
 *	Parse a JSON string.
 *
 * Arguments:
 *	begin	- Beginning of sequence to parse (including open quote).
 *	end	- End of sequence.
 *
 * Results:
 *	Nonzero if success. Additionally:
 *
 *	stringPtr    - If non-NULL, resulting string upon success.
 *
 * Side effects:
 *	*begin* is moved just past the parsed sequence.
 *---------------------------------------------------------------------------*/

int
ParseJsonString(
    Col_RopeIterator begin,
    Col_RopeIterator end,
    Col_Word *stringPtr)
{
    Col_RopeIterator firstUnchanged = COL_ROPEITER_NULL;
    Col_Word strbuf;
    Col_Char c;
    
    ASSERT(Col_RopeIterCompare(begin, end) < 0);
    ASSERT(Col_RopeIterAt(begin) == '"');
    Col_RopeIterNext(begin);

    if (stringPtr) strbuf = Col_NewStringBuffer(0, COL_UCS);//TODO optimize buffer length?

    for (;;) {
	GET_CHAR(c, begin, end) return 0;
	switch (c) {
	case '"':
	    /*
	     * End of string.
	     */

	    if (stringPtr && !Col_RopeIterNull(firstUnchanged)) {
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
	    if (stringPtr) *stringPtr = Col_StringBufferFreeze(strbuf);
	    return 1;

	case '\\':
	    /*
	     * Backslash sequence.
	     */

	    if (stringPtr && !Col_RopeIterNull(firstUnchanged)) {
		/*
		 * Append regular character sequence.
		 */

		Col_StringBufferAppendSequence(strbuf, firstUnchanged, begin);
		Col_RopeIterSetNull(firstUnchanged);
	    }

	    /*
	     * Unescape character.
	     * TODO: handle escaped surrogate pairs?
	     */

	    if (!ParseJsonBackslash(begin, end, stringPtr?&c:NULL)) return 0;
	    if (stringPtr) Col_StringBufferAppendChar(strbuf, c);
	    break;

	default:
	    /*
	     * Regular character, remember position.
	     */

	    if (Col_RopeIterNull(firstUnchanged)) {
		Col_RopeIterSet(firstUnchanged, begin);
	    }
	    Col_RopeIterNext(begin);
	}
    }
}

/*---------------------------------------------------------------------------
 * Internal Function: ParseJsonValue
 *
 *	Parse a JSON value.
 *
 * Arguments:
 *	begin	- Beginning of sequence to parse.
 *	end	- End of sequence.
 *
 * Results:
 *	Nonzero if success. Additionally:
 *
 *	valuePtr    - If non-NULL, resulting value upon success.
 *
 * Side effects:
 *	*begin* is moved just past the parsed sequence.
 *---------------------------------------------------------------------------*/

int
ParseJsonValue(
    Col_RopeIterator begin,
    Col_RopeIterator end,
    Col_Word *valuePtr)
{
    ASSERT(Col_RopeIterCompare(begin, end) < 0);
    switch (Col_RopeIterAt(begin)) {
    case '"':
	/*
	 * String.
	 */

	return ParseJsonString(begin, end, valuePtr);

    case '-':
    case '0':
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
    case '8':
    case '9':
	/*
	 * Number.
	 */

	return ParseJsonNumber(begin, end, valuePtr, NULL);

    case '{':
	/*
	 * Object.
	 */

	return ParseJsonObject(begin, end, valuePtr);

    case '[':
	/*
	 * Array.
	 */

	return ParseJsonArray(begin, end, valuePtr);

    case 't':
    case 'f':
    case 'n':
	/*
	 * Literals.
	 */

	return ParseJsonLiteral(begin, end, valuePtr);

    default:
	/*
	 * Invalid character.
	 */

	return 0;
    }
}

/*---------------------------------------------------------------------------
 * Internal Function: ParseJsonObject
 *
 *	Parse a JSON object (braced block).
 *
 * Arguments:
 *	begin	- Beginning of sequence to parse (including open brace).
 *	end	- End of sequence.
 *
 * Results:
 *	Nonzero if success. Additionally:
 *
 *	mapPtr    - If non-NULL, resulting map upon success.
 *
 * Side effects:
 *	*begin* is moved just past the parsed sequence.
 *---------------------------------------------------------------------------*/

int
ParseJsonObject(
    Col_RopeIterator begin,
    Col_RopeIterator end,
    Col_Word *mapPtr)
{
    size_t nb;
    Col_Word map, key, value;
    Col_Char c;

    ASSERT(Col_RopeIterCompare(begin, end) < 0);
    ASSERT(Col_RopeIterAt(begin) == '{');
    Col_RopeIterNext(begin);

    if (mapPtr) map = Col_NewStringHashMap(0);

    for (nb = 0; ; nb++) {
	GET_CHAR(c, begin, end) return 0;
	SKIP_CHARS(whitespace, c, begin, end) return 0;

	if (c == '}') {
	    /*
	     * End of object. Consume close brace and return map.
	     */

	    Col_RopeIterNext(begin);
	    if (mapPtr) *mapPtr = map;
	    return 1;
	}

	if (nb > 0) {
	    /*
	     * Entry separator.
	     */

	    if (c != ',') return 0;
	    NEXT_CHAR(c, begin, end) return 0;
	    SKIP_CHARS(whitespace, c, begin, end) return 0;
	}

	/*
	 * Key.
	 */

	if (!ParseJsonString(begin, end, mapPtr?&key:NULL)) return 0;

	/*
	 * Key-value separator.
	 */

	GET_CHAR(c, begin, end) return 0;
	SKIP_CHARS(whitespace, c, begin, end) return 0;
	if (c != ':') return 0;
	NEXT_CHAR(c, begin, end) return 0;
	SKIP_CHARS(whitespace, c, begin, end) return 0;

	/*
	 * Value.
	 */

	if (!ParseJsonValue(begin, end, mapPtr?&value:NULL)) return 0;

	/*
	 * Add entry.
	 */

	if (mapPtr) Col_HashMapSet(map, key, value);

    }

    /*
     * Reached end of sequence, syntax is invalid.
     */

    return 0;
}

/*---------------------------------------------------------------------------
 * Internal Function: ParseJsonArray
 *
 *	Parse a JSON array (bracketed block).
 *
 * Arguments:
 *	begin	- Beginning of sequence to parse (including open bracket).
 *	end	- End of sequence.
 *
 * Results:
 *	Nonzero if success. Additionally:
 *
 *	listPtr    - If non-NULL, resulting list upon success.
 *
 * Side effects:
 *	*begin* is moved just past the parsed sequence.
 *---------------------------------------------------------------------------*/

int
ParseJsonArray(
    Col_RopeIterator begin,
    Col_RopeIterator end,
    Col_Word *listPtr)
{
    size_t nb, i;
    Col_RopeIterator it;
    Col_Char c;

    ASSERT(Col_RopeIterCompare(begin, end) < 0);
    ASSERT(Col_RopeIterAt(begin) == '[');
    Col_RopeIterNext(begin);

    /*
     * First count number of elements.
     */

    Col_RopeIterSet(it, begin);
    for (nb = 0; ; nb++) {
	GET_CHAR(c, begin, end) return 0;
	SKIP_CHARS(whitespace, c, begin, end) return 0;

	if (c == ']') {
	    /*
	     * End of array. Consume close bracket and exit loop.
	     */

	    Col_RopeIterNext(begin);
	    break;
	}

	if (nb > 0) {
	    /*
	     * Separator.
	     */

	    if (c != ',') return 0;
	    NEXT_CHAR(c, begin, end) return 0;
	    SKIP_CHARS(whitespace, c, begin, end) return 0;
	}

	/*
	 * Element.
	 */

	if (!ParseJsonValue(begin, end, NULL)) return 0;
    }

    if (!listPtr) return 1;

    /*
     * Now extract elements.
     */

    if (nb <= Col_MaxMVectorLength()) {
	/*
	 * Array fits a mutable vector.
	 */

	Col_Word mvector = Col_NewMVector(0, nb, NULL);
	Col_Word *elements = Col_MVectorElements(mvector);
	for (i = 0; i < nb; i++) {
	    GET_CHAR(c, it, end) ASSERT(0);
	    SKIP_CHARS(whitespace, c, it, end) ASSERT(0);
	    if (i > 0) {
		ASSERT(c == ',');
		NEXT_CHAR(c, it, end) ASSERT(0);
		SKIP_CHARS(whitespace, c, it, end) ASSERT(0);
	    }
	    REQUIRE(ParseJsonValue(it, end, elements+i));
	}
	*listPtr = mvector;
    } else {
	/*
	 * Array is too large, use a mutable list.
	 */

	Col_Word mlist = Col_NewMList(), element;
	Col_MListSetLength(mlist, nb);
	GET_CHAR(c, it, end) ASSERT(0);
	for (i = 0; i < nb; i++) {
	    GET_CHAR(c, it, end) ASSERT(0);
	    SKIP_CHARS(whitespace, c, it, end) ASSERT(0);
	    if (i > 0) {
		ASSERT(c == ',');
		NEXT_CHAR(c, it, end) ASSERT(0);
		SKIP_CHARS(whitespace, c, it, end) ASSERT(0);
	    }
	    REQUIRE(ParseJsonValue(it, end, &element));
	    Col_MListSetAt(mlist, i, element);
	}
	*listPtr = mlist;
    }

    return 1;
}

/*---------------------------------------------------------------------------
 * Function: Coatl_ReadJson
 *
 *	Read JSON data from a character sequence.
 *
 * Arguments:
 *	begin	- Beginning of sequence to parse.
 *	end	- End of sequence (just past the last character to scan).
 *
 * Results:
 *	Nonzero if success. Additionally:
 *
 *	wordPtr    - If non-NULL, resulting data upon success.
 *
 * Side effects:
 *	*begin* is moved just past the parsed sequence.
 *---------------------------------------------------------------------------*/


int
Coatl_ReadJson(
    Col_RopeIterator begin, 
    Col_RopeIterator end, 
    Col_Word *wordPtr)
{
    Col_Char c;

    if (wordPtr) *wordPtr = WORD_NIL;

    /*
     * Skip leading whitespace.
     */

    GET_CHAR(c, begin, end) return 1;
    SKIP_CHARS(whitespace, c, begin, end) return 1;

    /*
     * Parse value.
     */

    if (!ParseJsonValue(begin, end, wordPtr)) return 0;

    /*
     * Skip trailing whitespace.
     */

    GET_CHAR(c, begin, end) return 1;
    SKIP_CHARS(whitespace, c, begin, end) return 1;

    /*
     * Invalid trailing characters.
     */

    return 0;
}
