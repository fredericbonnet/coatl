#include <colibri.h>
#include <coatl.h>
#include <picotest.h>

#include <stdio.h>

/*
 * JSON Input/Output
 */

#include "hooks.h"
#include "colibriFixture.h"

PICOTEST_SUITE(testJson, testReadJson, testWriteJson);

PICOTEST_SUITE(testReadJson, testReadJsonEmpty, testReadJsonWhitespace,
               testReadJsonLiteral, testReadJsonString, testReadJsonNumber,
               testReadJsonArray, testReadJsonObject);

static void initIterators(const char *str, Col_RopeIterator begin,
                          Col_RopeIterator end) {
    const size_t len = strlen(str);
    Col_RopeIterString(begin, COL_UCS1, str, len);
    Col_RopeIterSet(end, begin);
    Col_RopeIterForward(end, len);
}
static void checkReadJsonError(const char *json) {
    Col_RopeIterator begin, end;
    Col_Word value;

    initIterators(json, begin, end);
    PICOTEST_ASSERT(!Coatl_ReadJson(begin, end, NULL));

    initIterators(json, begin, end);
    PICOTEST_ASSERT(!Coatl_ReadJson(begin, end, &value));
}

PICOTEST_CASE(testReadJsonEmpty, colibriFixture) {
    Col_RopeIterator begin, end;
    Col_Word value;
    const char *json = "";

    initIterators(json, begin, end);
    PICOTEST_ASSERT(!Coatl_ReadJson(begin, end, NULL));
    PICOTEST_ASSERT(Col_RopeIterEnd(begin));

    initIterators(json, begin, end);
    PICOTEST_ASSERT(!Coatl_ReadJson(begin, end, &value));
    PICOTEST_ASSERT(Col_RopeIterEnd(begin));
    PICOTEST_ASSERT(value == WORD_NIL);
}
PICOTEST_CASE(testReadJsonWhitespace, colibriFixture) {
    Col_RopeIterator begin, end;
    Col_Word value;
    const char *json = " \t\n\r";

    initIterators(json, begin, end);
    PICOTEST_ASSERT(!Coatl_ReadJson(begin, end, NULL));
    PICOTEST_ASSERT(Col_RopeIterEnd(begin));

    initIterators(json, begin, end);
    PICOTEST_ASSERT(!Coatl_ReadJson(begin, end, &value));
    PICOTEST_ASSERT(Col_RopeIterEnd(begin));
    PICOTEST_ASSERT(value == WORD_NIL);
}

static void checkReadJsonLiterals(const char *json, Col_Word expected) {
    Col_RopeIterator begin, end;
    Col_Word value;

    initIterators(json, begin, end);
    PICOTEST_ASSERT(Coatl_ReadJson(begin, end, NULL));
    PICOTEST_ASSERT(Col_RopeIterEnd(begin));

    initIterators(json, begin, end);
    PICOTEST_ASSERT(Coatl_ReadJson(begin, end, &value));
    PICOTEST_ASSERT(Col_RopeIterEnd(begin));
    PICOTEST_ASSERT(value == expected);
}
PICOTEST_CASE(testReadJsonLiteral, colibriFixture) {
    checkReadJsonLiterals("true", WORD_TRUE);
    checkReadJsonLiterals("false", WORD_FALSE);
    checkReadJsonLiterals("null", WORD_NIL);

    checkReadJsonError("t");
    checkReadJsonError("f");
    checkReadJsonError("n");
    checkReadJsonError("true2");
    checkReadJsonError("false2");
    checkReadJsonError("null2");
}

PICOTEST_SUITE(testReadJsonString, testReadJsonEmptyString,
               testReadJsonSimpleString, testReadJsonEscapedCharacters,
               testReadJsonUnicodeCharacters, testReadJsonComplexString);

static void checkReadJsonRope(const char *json, Col_Word expected) {
    Col_RopeIterator begin, end;
    Col_Word value;

    initIterators(json, begin, end);
    PICOTEST_ASSERT(Coatl_ReadJson(begin, end, NULL));
    PICOTEST_ASSERT(Col_RopeIterEnd(begin));

    initIterators(json, begin, end);
    PICOTEST_ASSERT(Coatl_ReadJson(begin, end, &value));
    PICOTEST_ASSERT(Col_RopeIterEnd(begin));
    PICOTEST_ASSERT(Col_CompareRopes(value, expected) == 0);
}
static void checkReadJsonString(const char *json, const char *expected) {
    checkReadJsonRope(json, Col_NewRopeFromString(expected));
}

PICOTEST_CASE(testReadJsonEmptyString, colibriFixture) {
    checkReadJsonString("\"\"", "");
}
PICOTEST_CASE(testReadJsonSimpleString, colibriFixture) {
    checkReadJsonString("\"abcd\"", "abcd");
}
PICOTEST_CASE(testReadJsonEscapedCharacters, colibriFixture) {
    checkReadJsonString("\"\\\"\"", "\"");
    checkReadJsonString("\"\\\\\"", "\\");
    checkReadJsonString("\"\\/\"", "/");
    checkReadJsonString("\"\\b\"", "\b");
    checkReadJsonString("\"\\f\"", "\f");
    checkReadJsonString("\"\\n\"", "\n");
    checkReadJsonString("\"\\r\"", "\r");
    checkReadJsonString("\"\\t\"", "\t");

    checkReadJsonError("\"\\a\"");
    for (Col_Char c = 1; c < 0x20; c++) {
        char s[10];
        snprintf(s, 10, "\"%c\"", c);
        checkReadJsonError(s);
    }
}
PICOTEST_CASE(testReadJsonUnicodeCharacters, colibriFixture) {
    checkReadJsonString("\"\\u0041\"", "A");
    checkReadJsonRope("\"\\u1234\"", Col_NewCharWord(0x1234));

    checkReadJsonError("\"\\u\"");
    checkReadJsonError("\"\\u$\"");
    checkReadJsonError("\"\\u1\"");
    checkReadJsonError("\"\\u12\"");
    checkReadJsonError("\"\\u123\"");
    checkReadJsonError("\"\\u123$\"");
}
PICOTEST_CASE(testReadJsonComplexString, colibriFixture) {
    checkReadJsonString("  \"Hello,\\tworld\\u0021\" ", "Hello,\tworld!");
}

PICOTEST_SUITE(testReadJsonNumber, testReadJsonInteger, testReadJsonReal)

static void checkReadJsonInteger(const char *json, intmax_t expected) {
    Col_RopeIterator begin, end;
    Col_Word value;

    initIterators(json, begin, end);
    PICOTEST_ASSERT(Coatl_ReadJson(begin, end, NULL));
    PICOTEST_ASSERT(Col_RopeIterEnd(begin));

    initIterators(json, begin, end);
    PICOTEST_ASSERT(Coatl_ReadJson(begin, end, &value));
    PICOTEST_ASSERT(Col_RopeIterEnd(begin));
    PICOTEST_ASSERT(Coatl_WordIsLargeInt(value));
    PICOTEST_ASSERT(Coatl_LargeIntWordValue(value) == expected);
}
PICOTEST_CASE(testReadJsonInteger, colibriFixture) {
    checkReadJsonInteger("0", 0);
    checkReadJsonInteger("-0", 0);
    checkReadJsonInteger("1", 1);
    checkReadJsonInteger("-234", -234);

    checkReadJsonError("+5");
    checkReadJsonError("06");
    checkReadJsonError("-a");
}

static void checkReadJsonReal(const char *json, double expected) {
    Col_RopeIterator begin, end;
    Col_Word value;

    initIterators(json, begin, end);
    PICOTEST_ASSERT(Coatl_ReadJson(begin, end, NULL));
    PICOTEST_ASSERT(Col_RopeIterEnd(begin));

    initIterators(json, begin, end);
    PICOTEST_ASSERT(Coatl_ReadJson(begin, end, &value));
    PICOTEST_ASSERT(Col_RopeIterEnd(begin));
    PICOTEST_ASSERT(Col_WordType(value) == COL_FLOAT);
    PICOTEST_ASSERT(Col_FloatWordValue(value) == expected);
}
PICOTEST_CASE(testReadJsonReal, colibriFixture) {
    checkReadJsonReal("1.0", 1.0);
    checkReadJsonReal("-2.5", -2.5);
    checkReadJsonReal("3.25", 3.25);
    checkReadJsonReal("4e5", 4e5);
    checkReadJsonReal("56.7E+8", 56.7e8);
    checkReadJsonReal("5e-1", 5e-1);
    checkReadJsonReal("1e12", 1e12);

    checkReadJsonError(".");
    checkReadJsonError("1.");
    checkReadJsonError("2e");
    checkReadJsonError("3E+");
    checkReadJsonError(".0e");
    checkReadJsonError(".e2");
    checkReadJsonError("3.e4");
}

static void checkReadJsonArray(const char *json, size_t length) {
    Col_RopeIterator begin, end;
    Col_Word value;

    initIterators(json, begin, end);
    PICOTEST_ASSERT(Coatl_ReadJson(begin, end, NULL));
    PICOTEST_ASSERT(Col_RopeIterEnd(begin));

    initIterators(json, begin, end);
    PICOTEST_ASSERT(Coatl_ReadJson(begin, end, &value));
    PICOTEST_ASSERT(Col_RopeIterEnd(begin));
    PICOTEST_ASSERT(Col_WordType(value) & COL_LIST);
    PICOTEST_ASSERT(Col_ListLength(value) == length);
}
PICOTEST_CASE(testReadJsonArray, colibriFixture) {
    checkReadJsonArray("[]", 0);
    checkReadJsonArray("[1]", 1);
    checkReadJsonArray("[1,2]", 2);
    checkReadJsonArray("[ 1, 2 ,3  ,  4,5 ]", 5);
    checkReadJsonArray("[0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]", 16);

    checkReadJsonError("[");
    checkReadJsonError("[,]");
    checkReadJsonError("[1,]");
    checkReadJsonError("[]a");
}

static Col_Word checkReadJsonObject(const char *json, size_t length) {
    Col_RopeIterator begin, end;
    Col_Word value;

    initIterators(json, begin, end);
    PICOTEST_ASSERT(Coatl_ReadJson(begin, end, NULL));
    PICOTEST_ASSERT(Col_RopeIterEnd(begin));

    initIterators(json, begin, end);
    PICOTEST_ASSERT(Coatl_ReadJson(begin, end, &value));
    PICOTEST_ASSERT(Col_RopeIterEnd(begin));
    PICOTEST_ASSERT(Col_WordType(value) & COL_MAP);
    PICOTEST_ASSERT(Col_MapSize(value) == length);
    return value;
}
PICOTEST_CASE(testReadJsonObject, colibriFixture) {
    Col_Word object, value;

    checkReadJsonObject("{}", 0);

    object = checkReadJsonObject("{\"a\": true}", 1);
    PICOTEST_ASSERT(Col_MapGet(object, Col_NewCharWord('a'), &value));
    PICOTEST_VERIFY(value == WORD_TRUE);

    object = checkReadJsonObject("{\"\": \"b\"}", 1);
    PICOTEST_ASSERT(Col_MapGet(object, Col_EmptyRope(), &value));
    PICOTEST_VERIFY(value == Col_NewCharWord('b'));

    object = checkReadJsonObject("{\"abcd\" : false, \"b\": 1}", 2);
    PICOTEST_ASSERT(Col_MapGet(object, Col_NewRopeFromString("abcd"), &value));
    PICOTEST_VERIFY(value == WORD_FALSE);
    PICOTEST_ASSERT(Col_MapGet(object, Col_NewRopeFromString("b"), &value));
    PICOTEST_VERIFY(value == Col_NewIntWord(1));

    object = checkReadJsonObject("{   \"key\" :2,\"key\": null   }", 1);
    PICOTEST_ASSERT(Col_MapGet(object, Col_NewRopeFromString("key"), &value));
    PICOTEST_VERIFY(value == WORD_NIL);

    checkReadJsonError("{");
    checkReadJsonError("{}a");
    checkReadJsonError("{1: 2}");
    checkReadJsonError("{\"ab\"}");
    checkReadJsonError("{\"cde\":}");
    checkReadJsonError("{\"fg\":1,}");
    checkReadJsonError("{\"hij\":,\"k\": 3}");
}

PICOTEST_SUITE(testWriteJson, testWriteJsonLiteral, testWriteJsonString,
               testWriteJsonNumber, testWriteJsonArray, testWriteJsonObject);

static void checkWriteJson(Col_Word word, size_t indent, const char *expected) {
    Col_Word strbuf = Col_NewStringBuffer(0, COL_UCS1);

    const size_t length = Coatl_WriteJson(strbuf, word, indent);
    PICOTEST_ASSERT(length == strlen(expected));
    PICOTEST_ASSERT(Col_CompareRopes(Col_StringBufferFreeze(strbuf),
                                     Col_NewRopeFromString(expected)) == 0);
}

PICOTEST_CASE(testWriteJsonLiteral, colibriFixture) {
    checkWriteJson(WORD_NIL, 0, "null");
    checkWriteJson(WORD_TRUE, 0, "true");
    checkWriteJson(WORD_FALSE, 0, "false");
    checkWriteJson(WORD_NIL, 2, "null");
    checkWriteJson(WORD_TRUE, 2, "true");
    checkWriteJson(WORD_FALSE, 2, "false");
}

PICOTEST_SUITE(testWriteJsonString, testWriteJsonSimpleString,
               testWriteJsonEscapedCharacters, testWriteJsonComplexString);
PICOTEST_CASE(testWriteJsonSimpleString, colibriFixture) {
    checkWriteJson(Col_NewRopeFromString("abcd"), 0, "\"abcd\"");
}
PICOTEST_CASE(testWriteJsonEscapedCharacters, colibriFixture) {
    checkWriteJson(Col_NewCharWord('\"'), 0, "\"\\\"\"");
    checkWriteJson(Col_NewCharWord('\\'), 0, "\"\\\\\"");
    for (Col_Char c = 0; c < 0x20; c++) {
        switch (c) {
        case '\b':
            checkWriteJson(Col_NewCharWord('\b'), 0, "\"\\b\"");
            break;
        case '\f':
            checkWriteJson(Col_NewCharWord('\f'), 0, "\"\\f\"");
            break;
        case '\n':
            checkWriteJson(Col_NewCharWord('\n'), 0, "\"\\n\"");
            break;
        case '\r':
            checkWriteJson(Col_NewCharWord('\r'), 0, "\"\\r\"");
            break;
        case '\t':
            checkWriteJson(Col_NewCharWord('\t'), 0, "\"\\t\"");
            break;
        default:
            char s[10];
            snprintf(s, 10, "\"\\u%04x\"", c);
            checkWriteJson(Col_NewCharWord(c), 0, s);
        }
    }
}
PICOTEST_CASE(testWriteJsonComplexString, colibriFixture) {
    checkWriteJson(Col_NewRopeFromString("ab\bcd\fe\nfg\x01h\ri\tjkl\"mn\\o"),
                   0, "\"ab\\bcd\\fe\\nfg\\u0001h\\ri\\tjkl\\\"mn\\\\o\"");
}

PICOTEST_CASE(testWriteJsonNumber, colibriFixture) {
    checkWriteJson(Col_NewIntWord(123), 0, "123");
    checkWriteJson(Col_NewIntWord(-45), 0, "-45");
    checkWriteJson(Col_NewFloatWord(4.0), 0, "4.0");
    checkWriteJson(Col_NewFloatWord(-567.0), 0, "-5.67e2");
    checkWriteJson(Col_NewFloatWord(0.25), 0, "2.5e-1");
}
PICOTEST_CASE(testWriteJsonArray, colibriFixture) {
    checkWriteJson(Col_EmptyList(), 0, "[]");
    checkWriteJson(Col_NewVectorV(WORD_TRUE, WORD_FALSE, WORD_NIL,
                                  Col_NewIntWord(1),
                                  Col_NewRopeFromString("abcd")),
                   0, "[true,false,null,1,\"abcd\"]");
    checkWriteJson(Col_NewVectorV(WORD_TRUE, WORD_FALSE, WORD_NIL,
                                  Col_NewIntWord(1),
                                  Col_NewRopeFromString("abcd")),
                   2, "[\n  true,\n  false,\n  null,\n  1,\n  \"abcd\"\n]");
}
PICOTEST_CASE(testWriteJsonObject, colibriFixture) {
    Col_Word map = Col_NewStringTrieMap();
    checkWriteJson(map, 0, "{}");
    Col_MapSet(map, Col_NewRopeFromString("a"), WORD_TRUE);
    checkWriteJson(map, 0, "{\"a\":true}");
    checkWriteJson(map, 1, "{\n \"a\": true\n}");
    Col_MapSet(map, Col_NewRopeFromString("bcd"), Col_NewIntWord(123));
    checkWriteJson(map, 0, "{\"a\":true,\"bcd\":123}");
    checkWriteJson(map, 2, "{\n  \"a\": true,\n  \"bcd\": 123\n}");
    Col_MapSet(map, Col_NewRopeFromString("ab"), Col_EmptyList());
    checkWriteJson(map, 0, "{\"a\":true,\"ab\":[],\"bcd\":123}");
    checkWriteJson(map, 3,
                   "{\n   \"a\": true,\n   \"ab\": [],\n   \"bcd\": 123\n}");
    Col_MapSet(map, Col_NewRopeFromString("b"),
               Col_NewVectorV(WORD_TRUE, WORD_FALSE, Col_NewFloatWord(2.0)));
    checkWriteJson(map, 0,
                   "{\"a\":true,\"ab\":[],\"b\":[true,false,2.0],\"bcd\":123}");
    checkWriteJson(map, 4,
                   "{\n    \"a\": true,\n    \"ab\": [],\n    \"b\": [\n   "
                   "     true,\n   "
                   "     false,\n        2.0\n    ],\n    \"bcd\": 123\n}");
}
