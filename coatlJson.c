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

/*
 * Prototypes for functions used only in this file.
 */

static int		ReadJsonLiteral(Col_RopeIterator begin,
			    Col_RopeIterator end, Col_Word *wordPtr);
static int		ReadJsonNumber(Col_RopeIterator begin,
			    Col_RopeIterator end, Col_Word *wordPtr,
			    int *realPtr);
static int		ReadJsonBackslash(Col_RopeIterator begin,
			    Col_RopeIterator end, Col_Char *charPtr);
static int		ReadJsonString(Col_RopeIterator begin, 
			    Col_RopeIterator end, Col_Word *wordPtr);
static int		ReadJsonObject(Col_RopeIterator begin, 
			    Col_RopeIterator end, Col_Word *wordPtr);
static int		ReadJsonArray(Col_RopeIterator begin, 
			    Col_RopeIterator end, Col_Word *wordPtr);
static int		ReadJsonValue(Col_RopeIterator begin, 
			    Col_RopeIterator end, Col_Word *wordPtr);
static size_t		WriteJsonString(Col_Word strbuf, Col_Word word);
static size_t		WriteJsonArray(Col_Word strbuf, Col_Word word,
			    size_t indent, size_t indented);
static size_t		WriteJsonObject(Col_Word strbuf, Col_Word word,
			    size_t indent, size_t indented);
static size_t		WriteJsonValue(Col_Word strbuf, Col_Word word,
			    size_t indent, size_t indented);


/*
================================================================================
Section: JSON Input/Output
================================================================================
*/

//TODO
static const Col_Char whitespace[] = {0x20, 0x09, 0x0A, 0x0D, COL_CHAR_INVALID};

/*---------------------------------------------------------------------------
 * Internal Variable: jsonFloatFormat
 *
 *	JSON Float writing format. Ensures floats have at least one fractional
 *	digit.
 *
 *	- Base-10.
 *	- No prefix.
 *	- No digit grouping.
 *	- No leading zeroes in integral part.
 *	- At least one fractional digit.
 *	- No truncation.
 *	- Radix point is dot character *'.'*.
 *	- Optional exponent character is lowercase *'e'*.
 *
 * See also:
 *	<COATL_NUMWRITE_DEFAULT>
 *---------------------------------------------------------------------------*/

static const Coatl_NumWriteFormat jsonFloatFormat = {
    /* .flags = */		0,
    /* .radix = */		10,
    /* .minWidth = */		0,
    /* .padChar = */		' ',
    /* .prefixChar = */		COL_CHAR_INVALID,
    /* .groupSize = */		0,
    /* .groupChar = */		COL_CHAR_INVALID,
    /* .minDigits = */		1,
    /* .maxDigitsSigd = */	SIZE_MAX,
    /* .minDigitsFrac = */	1,
    /* .maxDigitsFrac = */	SIZE_MAX,
    /* .minDigitsExp = */	0,
    /* .minFixed = */		INT_MAX,
    /* .maxFixed = */		INT_MIN,
    /* .pointChar = */		'.',
    /* .expMul = */		1,
    /* .expChar = */		'e',
};


/*---------------------------------------------------------------------------
 * Internal Function: ReadJsonLiteral
 *
 *	Read a JSON literal as a word. The following literals are recognized:
 *
 *	true    - Boolean true, gives the integer word 1.
 *	false   - Boolean false, gives the integer word 0.
 *	null    - Null value, gives the nil word.
 *
 * Arguments:
 *	begin	- Beginning of sequence to read (including backslash char).
 *	end	- End of sequence.
 *
 * Results:
 *	Nonzero if success. Additionally:
 *
 *	valuePtr	- If non-NULL, resulting character upon success.
 *
 * Side effects:
 *	*begin* is moved just past the read sequence.
 *---------------------------------------------------------------------------*/

static int
ReadJsonLiteral(
    Col_RopeIterator begin,
    Col_RopeIterator end,
    Col_Word *wordPtr)
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
	if (wordPtr) *wordPtr = Col_NewIntWord(1);
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
	if (wordPtr) *wordPtr = Col_NewIntWord(0);
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
	if (wordPtr) *wordPtr = COL_NIL;
	return 1;
    }
    
    /*
     * Invalid syntax.
     */

    return 0;
}

/*---------------------------------------------------------------------------
 * Internal Function: ReadJsonNumber
 *
 *	Read a JSON number (integer or floating point) as a number word.
 *
 * Arguments:
 *	begin	- Beginning of sequence to read (including backslash char).
 *	end	- End of sequence.
 *
 * Results:
 *	Nonzero if success. Additionally:
 *
 *	wordPtr	- If non-NULL, resulting word upon success. May be a Colibri
 *		  integer or floating point word, a CoATL large integer word, 
 *		  or a CoATL multiple integer or floating point word.
 *	realPtr	- If non-NULL, whether number was real or integer.
 *
 * Side effects:
 *	*begin* is moved just past the last scanned character.
  *
 * See also:
 *	<Coatl_ReadIntWord>, <Coatl_ReadFloatWord>
*---------------------------------------------------------------------------*/

static int
ReadJsonNumber(
    Col_RopeIterator begin,
    Col_RopeIterator end,
    Col_Word *wordPtr,
    int *realPtr)
{
    Col_Char c;

    if (wordPtr) {
	/*
	 * First check syntax.
	 */

	Col_RopeIterator it;
	int real = 0, neg = 0;
	Col_RopeIterSet(it, begin);
	if (!ReadJsonNumber(begin, end, NULL, &real)) return 0;

	/*
	 * Then scan number.
	 */

	if (real) {
	    REQUIRE(Coatl_ReadFloatWord(it, begin, NULL, 0, wordPtr));
	} else {
	    REQUIRE(Coatl_ReadIntWord(it, begin, NULL, 0, wordPtr));
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
 * Internal Function: ReadJsonBackslash
 *
 *	Read a JSON backslash sequence as a character.
 *
 * Arguments:
 *	begin	- Beginning of sequence to read (including backslash char).
 *	end	- End of sequence.
 *
 * Results:
 *	Nonzero if success. Additionally:
 *
 *	charPtr    - If non-NULL, resulting character upon success.
 *
 * Side effects:
 *	*begin* is moved just past the last scanned character.
 *---------------------------------------------------------------------------*/

static int
ReadJsonBackslash(
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
 * Internal Function: ReadJsonString
 *
 *	Read a JSON string as a string word.
 *
 * Arguments:
 *	begin	- Beginning of sequence to read (including open quote).
 *	end	- End of sequence.
 *
 * Results:
 *	Nonzero if success. Additionally:
 *
 *	wordPtr	- If non-NULL, resulting string word upon success.
 *
 * Side effects:
 *	*begin* is moved just past the last scanned character.
 *
 * See also:
 *	<ReadJsonBackslash>
 *---------------------------------------------------------------------------*/

static int
ReadJsonString(
    Col_RopeIterator begin,
    Col_RopeIterator end,
    Col_Word *wordPtr)
{
    Col_RopeIterator firstUnchanged = COL_ROPEITER_NULL;
    Col_Word strbuf;
    Col_Char c;
    
    ASSERT(Col_RopeIterCompare(begin, end) < 0);
    ASSERT(Col_RopeIterAt(begin) == '"');
    Col_RopeIterNext(begin);

    if (wordPtr) strbuf = Col_NewStringBuffer(0, COL_UCS);//TODO optimize buffer length?

    for (;;) {
	GET_CHAR(c, begin, end) return 0;
	switch (c) {
	case '"':
	    /*
	     * End of string.
	     */

	    if (wordPtr && !Col_RopeIterNull(firstUnchanged)) {
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
	    if (wordPtr) *wordPtr = Col_StringBufferFreeze(strbuf);
	    return 1;

	case '\\':
	    /*
	     * Backslash sequence.
	     */

	    if (wordPtr && !Col_RopeIterNull(firstUnchanged)) {
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

	    if (!ReadJsonBackslash(begin, end, wordPtr?&c:NULL)) return 0;
	    if (wordPtr) Col_StringBufferAppendChar(strbuf, c);
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
 * Internal Function: ReadJsonObject
 *
 *	Read a JSON object (braced block) as a map word.
 *
 * Arguments:
 *	begin	- Beginning of sequence to read (including open brace).
 *	end	- End of sequence.
 *
 * Results:
 *	Nonzero if success. Additionally:
 *
 *	wordPtr	- If non-NULL, resulting map word upon success.
 *
 * Side effects:
 *	*begin* is moved just past the last scanned character.
 *
 * See also:
 *	<ReadJsonString>, <ReadJsonValue>
 *---------------------------------------------------------------------------*/

static int
ReadJsonObject(
    Col_RopeIterator begin,
    Col_RopeIterator end,
    Col_Word *wordPtr)
{
    size_t nb;
    Col_Word map, key, value;
    Col_Char c;

    ASSERT(Col_RopeIterCompare(begin, end) < 0);
    ASSERT(Col_RopeIterAt(begin) == '{');
    Col_RopeIterNext(begin);

    if (wordPtr) map = Col_NewStringHashMap(0);

    for (nb = 0; ; nb++) {
	GET_CHAR(c, begin, end) return 0;
	SKIP_CHARS(whitespace, c, begin, end) return 0;

	if (c == '}') {
	    /*
	     * End of object. Consume close brace and return map.
	     */

	    Col_RopeIterNext(begin);
	    if (wordPtr) *wordPtr = map;
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

	if (!ReadJsonString(begin, end, wordPtr?&key:NULL)) return 0;

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

	if (!ReadJsonValue(begin, end, wordPtr?&value:NULL)) return 0;

	/*
	 * Add entry.
	 */

	if (wordPtr) Col_HashMapSet(map, key, value);

    }

    /*
     * Reached end of sequence, syntax is invalid.
     */

    return 0;
}

/*---------------------------------------------------------------------------
 * Internal Function: ReadJsonArray
 *
 *	Read a JSON array (bracketed block) as a list word.
 *
 * Arguments:
 *	begin	- Beginning of sequence to read (including open bracket).
 *	end	- End of sequence.
 *
 * Results:
 *	Nonzero if success. Additionally:
 *
 *	wordPtr	- If non-NULL, resulting list word upon success.
 *
 * Side effects:
 *	*begin* is moved just past the last scanned character.
 *
 * See also:
 *	<ReadJsonValue>
 *---------------------------------------------------------------------------*/

static int
ReadJsonArray(
    Col_RopeIterator begin,
    Col_RopeIterator end,
    Col_Word *wordPtr)
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

	if (!ReadJsonValue(begin, end, NULL)) return 0;
    }

    if (!wordPtr) return 1;

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
	    REQUIRE(ReadJsonValue(it, end, elements+i));
	}
	*wordPtr = mvector;
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
	    REQUIRE(ReadJsonValue(it, end, &element));
	    Col_MListSetAt(mlist, i, element);
	}
	*wordPtr = mlist;
    }

    return 1;
}

/*---------------------------------------------------------------------------
 * Internal Function: ReadJsonValue
 *
 *	Read a JSON value as a word.
 *
 * Arguments:
 *	begin	- Beginning of sequence to read.
 *	end	- End of sequence.
 *
 * Results:
 *	Nonzero if success. Additionally:
 *
 *	wordPtr	- If non-NULL, resulting value upon success.
 *
 * Side effects:
 *	*begin* is moved just past the last scanned character.
 *
 * See also:
 *	<Coatl_ReadJson>, <ReadJsonString>, <ReadJsonNumber>, <ReadJsonObject>,
 *	<ReadJsonArray>, <ReadJsonLiteral>
 *---------------------------------------------------------------------------*/

static int
ReadJsonValue(
    Col_RopeIterator begin,
    Col_RopeIterator end,
    Col_Word *wordPtr)
{
    ASSERT(Col_RopeIterCompare(begin, end) < 0);
    switch (Col_RopeIterAt(begin)) {
    case '"':
	/*
	 * String.
	 */

	return ReadJsonString(begin, end, wordPtr);

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

	return ReadJsonNumber(begin, end, wordPtr, NULL);

    case '{':
	/*
	 * Object.
	 */

	return ReadJsonObject(begin, end, wordPtr);

    case '[':
	/*
	 * Array.
	 */

	return ReadJsonArray(begin, end, wordPtr);

    case 't':
    case 'f':
    case 'n':
	/*
	 * Literals.
	 */

	return ReadJsonLiteral(begin, end, wordPtr);

    default:
	/*
	 * Invalid character.
	 */

	return 0;
    }
}

/*---------------------------------------------------------------------------
 * Function: WriteJsonString
 *
 *	Write a string word to a string buffer using the JSON format.
 *
 *	Double quotes are escaped.
 *
 * Arguments:
 *	strbuf	- Output string buffer.
 *	word	- Word to write.
 *
 * Result:
 *	Number of characters written.
 *
 * Side effects:
 *	Characters are appended to the string buffer.
 *
 * See also:
 *	<WriteJsonValue>
 *---------------------------------------------------------------------------*/

static size_t
WriteJsonString(
    Col_Word strbuf, 
    Col_Word word)
{
    size_t oldLen = Col_StringBufferLength(strbuf);
    Col_RopeIterator begin, end;
    size_t pos;

    Col_StringBufferAppendChar(strbuf, '"');
    for (pos = 0;;) {
	Col_RopeIterBegin(begin, word, pos);
	pos = Col_RopeFind(word, '"', pos, SIZE_MAX, 0);
	Col_RopeIterBegin(end, word, pos);
	Col_StringBufferAppendSequence(strbuf, begin, end);
	if (pos == SIZE_MAX) break;
	Col_StringBufferAppendChar(strbuf, '\\');
	Col_StringBufferAppendChar(strbuf, '"');
	pos++;
    }
    Col_StringBufferAppendChar(strbuf, '"');

    return Col_StringBufferLength(strbuf) - oldLen;
}

/*---------------------------------------------------------------------------
 * Function: WriteJsonArray
 *
 *	Write a list word to a string buffer using the JSON format.
 *
 *	Double quotes are escaped.
 *
 * Arguments:
 *	strbuf		- Output string buffer.
 *	word		- Word to write.
 *	indent		- If zero, output uses no whitespace. Else, output is 
 *			  pretty-printed using the given number of indentation
 *			  spaces.
 *	indented	- If zero, output uses no whitespace. Else, value has 
 *			  been indented by the given number of spaces.
 *
 * Result:
 *	Number of characters written.
 *
 * Side effects:
 *	Characters are appended to the string buffer.
 *
 * See also:
 *	<WriteJsonValue>
 *---------------------------------------------------------------------------*/

static size_t
WriteJsonArray(
    Col_Word strbuf, 
    Col_Word word,
    size_t indent,
    size_t indented)
{
    size_t oldLen = Col_StringBufferLength(strbuf);
    size_t i;
    Col_ListIterator it;
    int first;
    
    Col_StringBufferAppendChar(strbuf, '[');

    for (Col_ListIterFirst(it, word), first = 1; !Col_ListIterEnd(it); 
	    Col_ListIterNext(it)) {
	if (first) first = 0;
	else Col_StringBufferAppendChar(strbuf, ',');

	/*
	 * Indent & output element.
	 */

	if (indent) {
	    Col_StringBufferAppendChar(strbuf, '\n');
	    for (i=0; i < indented+indent; i++) {
		Col_StringBufferAppendChar(strbuf, ' ');
	    }
	}
	WriteJsonValue(strbuf, Col_ListIterAt(it), indent, indented+indent);
    }


    /*
     * Indent closing bracket unless list is empty.
     */

    if (indent && Col_ListLength(word)) {
	Col_StringBufferAppendChar(strbuf, '\n');
	for (i=0; i < indented; i++) Col_StringBufferAppendChar(strbuf, ' ');
    }
    Col_StringBufferAppendChar(strbuf, ']');

    return Col_StringBufferLength(strbuf) - oldLen;
}

/*---------------------------------------------------------------------------
 * Function: WriteJsonObject
 *
 *	Write a string-keyed map word to a string buffer using the JSON format.
 *
 *	Double quotes are escaped.
 *
 * Arguments:
 *	strbuf		- Output string buffer.
 *	word		- Word to write.
 *	indent		- If zero, output uses no whitespace. Else, output is 
 *			  pretty-printed using the given number of indentation
 *			  spaces.
 *	indented	- If zero, output uses no whitespace. Else, value has 
 *			  been indented by the given number of spaces.
 *
 * Result:
 *	Number of characters written.
 *
 * Side effects:
 *	Characters are appended to the string buffer.
 *
 * See also:
 *	<WriteJsonValue>
 *---------------------------------------------------------------------------*/

static size_t
WriteJsonObject(
    Col_Word strbuf, 
    Col_Word word,
    size_t indent,
    size_t indented)
{
    size_t oldLen = Col_StringBufferLength(strbuf);
    size_t i;
    Col_MapIterator it;
    int first;
    
    Col_StringBufferAppendChar(strbuf, '{');

    for (Col_MapIterBegin(it, word), first = 1; !Col_MapIterEnd(it); 
	    Col_MapIterNext(it)) {
	if (first) first = 0;
	else Col_StringBufferAppendChar(strbuf, ',');

	/*
	 * Indent & output element.
	 */

	if (indent) {
	    Col_StringBufferAppendChar(strbuf, '\n');
	    for (i=0; i < indented+indent; i++) {
		Col_StringBufferAppendChar(strbuf, ' ');
	    }
	}
	WriteJsonValue(strbuf, Col_MapIterGetKey(it), indent, indented+indent);
	Col_StringBufferAppendChar(strbuf, ':');
	if (indent) Col_StringBufferAppendChar(strbuf, ' ');
	WriteJsonValue(strbuf, Col_MapIterGetValue(it), indent, indented+indent);
    }


    /*
     * Indent closing bracket unless list is empty.
     */

    if (indent && Col_MapSize(word)) {
	Col_StringBufferAppendChar(strbuf, '\n');
	for (i=0; i < indented; i++) Col_StringBufferAppendChar(strbuf, ' ');
    }
    Col_StringBufferAppendChar(strbuf, '}');

    return Col_StringBufferLength(strbuf) - oldLen;
}

/*---------------------------------------------------------------------------
 * Function: WriteJsonValue
 *
 *	Write a word to a string buffer using the JSON format.
 *
 *	Uses the following mapping (for symmetry with <Coatl_ReadJson>):
 *
 *	- Nil is mapped to JSON null.
 *	- Integers and floating point numbers are mapped to the matching JSON 
 *	  number types.
 *	- Strings are mapped to JSON Unicode strings; double quotes are escaped.
 *	- Lists are mapped to arrays.
 *	- String-keyed maps are mapped to objects.
 *	
 *	Moreover, JSON booleans have no matching word type and so are never 
 *	output, and word types with no matching JSON type are mapped to null
 *	(e.g. integer- or custom-keyed maps). Word synonym chains are scanned 
 *	for compatible types when necessary.
 *
 * Arguments:
 *	strbuf		- Output string buffer.
 *	word		- Word to write.
 *	indent		- If zero, output uses no whitespace. Else, output is 
 *			  pretty-printed using the given number of indentation
 *			  spaces.
 *	indented	- If zero, output uses no whitespace. Else, value has 
 *			  been indented by the given number of spaces.
 *
 * Result:
 *	Number of characters written.
 *
 * Side effects:
 *	Characters are appended to the string buffer.
 *
 * See also:
 *	<Coatl_WriteJson>
 *---------------------------------------------------------------------------*/

static size_t
WriteJsonValue(
    Col_Word strbuf, 
    Col_Word word,
    size_t indent,
    size_t indented)
{
    Col_Word w = word;
    int type;

    do {
	type = Col_WordType(w);
	if (type == COL_NIL) {
	    /*
	     * Colibri nil => JSON null.
	     */

	    Col_StringBufferAppendChar(strbuf, 'n');
	    Col_StringBufferAppendChar(strbuf, 'u');
	    Col_StringBufferAppendChar(strbuf, 'l');
	    Col_StringBufferAppendChar(strbuf, 'l');
	    return 4;
	} else if (type & COL_INT) {
	    /*
	     * Colibri integer => JSON integer. Use default CoATL formatting.
	     */

	    return Coatl_WriteIntWord(strbuf, word, NULL);
	} else if (type & COL_FLOAT) {
	    /*
	     * Colibri float => JSON float. Use default CoATL formatting.
	     */

	    return Coatl_WriteFloatWord(strbuf, word, &jsonFloatFormat);
	} else if (type & COL_STRING) {
	    /*
	     * Colibri string => JSON strings.
	     */

	    return WriteJsonString(strbuf, word);
	} else if (type & COL_LIST) {
	    /*
	     * Colibri list => JSON arrays.
	     */

	    return WriteJsonArray(strbuf, word, indent, indented);
	} else if ((type & COL_MAP) && !(type & COL_CUSTOM)) {
	    /*
	     * Colibri string-keyed map => JSON objects.
	     */

	    return WriteJsonObject(strbuf, word, indent, indented);
	} else if (Coatl_WordIsLargeInt(word) || Coatl_WordIsMpInt(word)) {
	    /*
	     * CoATL integer => JSON integer. Use default CoATL formatting.
	     */

	    return Coatl_WriteIntWord(strbuf, word, NULL);
	} else if (Coatl_WordIsMpFloat(word)) {
	    /*
	     * CoATL float => JSON float. Use default CoATL formatting.
	     */

	    return Coatl_WriteFloatWord(strbuf, word, NULL);
	}

	/*
	 * Unhandled type, try next synonym.
	 */

	w = Col_WordSynonym(w);

    } while (w && w != word);

    /*
     * Unhandled word type => JSON null.
     */

    return WriteJsonValue(strbuf, COL_NIL, indent, indented);
}

/*---------------------------------------------------------------------------
 * Function: Coatl_ReadJson
 *
 *	Read JSON data as a word from a character sequence.
 *
 * Arguments:
 *	begin	- Beginning of sequence to read.
 *	end	- End of sequence (just past the last character to scan).
 *
 * Results:
 *	Nonzero if success. Additionally:
 *
 *	wordPtr	- If non-NULL, resulting data upon success.
 *
 * Side effects:
 *	*begin* is moved just past the last scanned character.
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
     * Read value.
     */

    if (!ReadJsonValue(begin, end, wordPtr)) return 0;

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

/*---------------------------------------------------------------------------
 * Function: Coatl_WriteJson
 *
 *	Write a word to a string buffer using the JSON format.
 *
 *	Uses the following mapping (for symmetry with <Coatl_ReadJson>):
 *
 *	- Nil is mapped to JSON null.
 *	- Strings, integers and floating point numbers are mapped to the 
 *	  matching JSON types.
 *	- Lists are mapped to arrays.
 *	- String-keyed maps are mapped to objects.
 *	
 *	Moreover, JSON booleans have no matching word type and so are never 
 *	output, and word types with no matching JSON type are mapped to null
 *	(e.g. integer- or custom-keyed maps). Word synonym chains are scanned 
 *	for compatible types when necessary.
 *
 * Arguments:
 *	strbuf	- Output string buffer.
 *	word	- Word to write.
 *	indent	- If zero, output uses no whitespace. Else, output is 
 *		  pretty-printed using the given number of indentation spaces.
 *
 * Result:
 *	Number of characters written.
 *
 * Side effects:
 *	Characters are appended to the string buffer.
 *---------------------------------------------------------------------------*/

size_t
Coatl_WriteJson(
    Col_Word strbuf, 
    Col_Word word,
    size_t indent)
{
    return WriteJsonValue(strbuf, word, indent, 0);
}
