#include <stdio.h>
#include <limits.h>
#include <float.h>

#include <coatl.h>

#include <picotest.h>

#include "testCoatl.h"

/*
 *---------------------------------------------------------------------------
 *
 * testJson --
 *
 *---------------------------------------------------------------------------
 */

PICOTEST_SUITE(testJson, 
    testJsonLiteral, testJsonInt, testJsonFloat, testJsonString, testJsonArray,
    testJsonObject, testJsonValue
)

#define WRITE_EXPECTED_JSON(value, indent, expected) { \
    Col_Word strbuf = Col_NewStringBuffer(0, COL_UCS1); \
    Col_RopeIterator it; \
    \
    ASSERT(Coatl_WriteJson(strbuf, value, indent) == (size_t) strlen(expected)); \
    for (Col_RopeIterFirst(it, Col_StringBufferFreeze(strbuf)); \
            !Col_RopeIterEnd(it); Col_RopeIterNext(it)) { \
        ASSERT(Col_RopeIterAt(it) == (Col_Char) expected[Col_RopeIterIndex(it)], "index=%u", Col_RopeIterIndex(it)); \
    } \
}

PICOTEST_FIXTURE_SETUP(testJson) {
    Col_Init(COL_SINGLE);
    Col_SetErrorProc(ERROR_PROC);

    Col_PauseGC();
}
PICOTEST_FIXTURE_TEARDOWN(testJson) {
    if (!PICOTEST_FAIL) {
        Col_ResumeGC();
    }
    Col_Cleanup();
}
PICOTEST_CASE(testJsonLiteral, testJson) {
    char str[100];
    size_t len;
    Col_Word v;
    Col_RopeIterator begin, end;

    sprintf(str, "false");
    len = strlen(str);
    Col_RopeIterString(begin, COL_UCS1, str, len);
    Col_RopeIterSet(end, begin); Col_RopeIterForward(end, len);
    ASSERT(Coatl_ReadJson(begin, end, &v));
    ASSERT(Col_RopeIterCompare(begin, end) == 0);
    ASSERT(Col_WordType(v) == COL_BOOL);
    ASSERT(!Col_BoolWordValue(v));
    ASSERT(v == WORD_FALSE);
    WRITE_EXPECTED_JSON(v, 0, "false");

    sprintf(str, "true");
    len = strlen(str);
    Col_RopeIterString(begin, COL_UCS1, str, len);
    Col_RopeIterSet(end, begin); Col_RopeIterForward(end, len);
    ASSERT(Coatl_ReadJson(begin, end, &v));
    ASSERT(Col_RopeIterCompare(begin, end) == 0);
    ASSERT(Col_WordType(v) == COL_BOOL);
    ASSERT(Col_BoolWordValue(v));
    ASSERT(v == WORD_TRUE);
    WRITE_EXPECTED_JSON(v, 0, "true");

    sprintf(str, "null");
    len = strlen(str);
    Col_RopeIterString(begin, COL_UCS1, str, len);
    Col_RopeIterSet(end, begin); Col_RopeIterForward(end, len);
    ASSERT(Coatl_ReadJson(begin, end, &v));
    ASSERT(Col_RopeIterCompare(begin, end) == 0);
    ASSERT(Col_WordType(v) == COL_NIL);
    ASSERT(v == WORD_NIL);
    WRITE_EXPECTED_JSON(v, 0, "null");
}
PICOTEST_CASE(testJsonInt, testJson) {
    char str[100];
    size_t len;
    Col_Word v;
    Col_RopeIterator begin, end;

    /* Native integers. */
    sprintf(str, "%lld", (intmax_t) INTPTR_MAX);
    len = strlen(str);
    Col_RopeIterString(begin, COL_UCS1, str, len);
    Col_RopeIterSet(end, begin); Col_RopeIterForward(end, len);
    ASSERT(Coatl_ReadJson(begin, end, &v));
    ASSERT(Col_RopeIterCompare(begin, end) == 0);
    ASSERT(Col_WordType(v) & COL_INT);
    ASSERT(Col_IntWordValue(v) == INTPTR_MAX);

    sprintf(str, "%lld", (intmax_t) INTPTR_MIN);
    len = strlen(str);
    Col_RopeIterString(begin, COL_UCS1, str, len);
    Col_RopeIterSet(end, begin); Col_RopeIterForward(end, len);
    ASSERT(Coatl_ReadJson(begin, end, &v));
    ASSERT(Col_RopeIterCompare(begin, end) == 0);
    ASSERT(Col_WordType(v) & COL_INT);
    ASSERT(Col_IntWordValue(v) == INTPTR_MIN);

    /* Large integers. */
    sprintf(str, "%lld", INTMAX_MAX);
    len = strlen(str);
    Col_RopeIterString(begin, COL_UCS1, str, len);
    Col_RopeIterSet(end, begin); Col_RopeIterForward(end, len);
    ASSERT(Coatl_ReadJson(begin, end, &v));
    ASSERT(Col_RopeIterCompare(begin, end) == 0);
    ASSERT(Coatl_WordIsLargeInt(v));
    ASSERT(Coatl_LargeIntWordValue(v) == INTMAX_MAX);

    sprintf(str, "%lld", INTMAX_MIN);
    len = strlen(str);
    Col_RopeIterString(begin, COL_UCS1, str, len);
    Col_RopeIterSet(end, begin); Col_RopeIterForward(end, len);
    ASSERT(Coatl_ReadJson(begin, end, &v));
    ASSERT(Col_RopeIterCompare(begin, end) == 0);
    ASSERT(Coatl_WordIsLargeInt(v));
    ASSERT(Coatl_LargeIntWordValue(v) == INTMAX_MIN);

    /* Multiple precision integers. */
    sprintf(str, "%lld123456", INTMAX_MAX);
    len = strlen(str);
    Col_RopeIterString(begin, COL_UCS1, str, len);
    Col_RopeIterSet(end, begin); Col_RopeIterForward(end, len);
    ASSERT(Coatl_ReadJson(begin, end, &v));
    ASSERT(Col_RopeIterCompare(begin, end) == 0);
    ASSERT(Coatl_WordIsMpInt(v));

    sprintf(str, "%lld123456", INTMAX_MIN);
    len = strlen(str);
    Col_RopeIterString(begin, COL_UCS1, str, len);
    Col_RopeIterSet(end, begin); Col_RopeIterForward(end, len);
    ASSERT(Coatl_ReadJson(begin, end, &v));
    ASSERT(Col_RopeIterCompare(begin, end) == 0);
    ASSERT(Coatl_WordIsMpInt(v));
}
PICOTEST_CASE(testJsonFloat, testJson) {
    char str[1000];
    size_t len;
    Col_Word v;
    Col_RopeIterator begin, end;

    /* Native floats. */
    sprintf(str, "   2.06158430208e+11  "/* = 12 x 2^34 */);
    len = strlen(str);
    Col_RopeIterString(begin, COL_UCS1, str, len);
    Col_RopeIterSet(end, begin); Col_RopeIterForward(end, len);
    ASSERT(Coatl_ReadJson(begin, end, &v));
    ASSERT(Col_RopeIterCompare(begin, end) == 0);
    ASSERT(Col_WordType(v) & COL_FLOAT);
    ASSERT(Col_FloatWordValue(v) == 2.06158430208e+11);

    sprintf(str, "   -2.06158430208e+11  ");
    len = strlen(str);
    Col_RopeIterString(begin, COL_UCS1, str, len);
    Col_RopeIterSet(end, begin); Col_RopeIterForward(end, len);
    ASSERT(Coatl_ReadJson(begin, end, &v));
    ASSERT(Col_RopeIterCompare(begin, end) == 0);
    ASSERT(Col_WordType(v) & COL_FLOAT);
    ASSERT(Col_FloatWordValue(v) == -2.06158430208e+11);

    sprintf(str, "  6.9849193096160888671875e-10  "/* = 12 x 2^-34 */);
    len = strlen(str);
    Col_RopeIterString(begin, COL_UCS1, str, len);
    Col_RopeIterSet(end, begin); Col_RopeIterForward(end, len);
    ASSERT(Coatl_ReadJson(begin, end, &v));
    ASSERT(Col_RopeIterCompare(begin, end) == 0);
    ASSERT(Col_WordType(v) & COL_FLOAT);
    ASSERT(Col_FloatWordValue(v) == 6.984919309616088867e-10);

    sprintf(str, "  -6.9849193096160888671875e-10  ");
    len = strlen(str);
    Col_RopeIterString(begin, COL_UCS1, str, len);
    Col_RopeIterSet(end, begin); Col_RopeIterForward(end, len);
    ASSERT(Coatl_ReadJson(begin, end, &v));
    ASSERT(Col_RopeIterCompare(begin, end) == 0);
    ASSERT(Col_WordType(v) & COL_FLOAT);
    ASSERT(Col_FloatWordValue(v) == -6.984919309616088867e-10);

    /* Multiple precision floats. */
    sprintf(str, "  12345e+%d  ", DBL_MAX_10_EXP+1);
    len = strlen(str);
    Col_RopeIterString(begin, COL_UCS1, str, len);
    Col_RopeIterSet(end, begin); Col_RopeIterForward(end, len);
    ASSERT(Coatl_ReadJson(begin, end, &v));
    ASSERT(Col_RopeIterCompare(begin, end) == 0);
    ASSERT(Coatl_WordIsMpFloat(v));
    sprintf(str, "1.2345e%d  ", DBL_MAX_10_EXP+5);
    
    sprintf(str, "  12345e%d  ", DBL_MIN_10_EXP-1);
    len = strlen(str);
    Col_RopeIterString(begin, COL_UCS1, str, len);
    Col_RopeIterSet(end, begin); Col_RopeIterForward(end, len);
    ASSERT(Coatl_ReadJson(begin, end, &v));
    ASSERT(Col_RopeIterCompare(begin, end) == 0);
    ASSERT(Coatl_WordIsMpFloat(v));
    sprintf(str, "1.2345e%d  ", DBL_MAX_10_EXP+3);
}
PICOTEST_CASE(testJsonString, testJson) {
    const char *str;
    size_t len;
    Col_Word v;
    Col_RopeIterator begin, end;

    str = "  \"abcd\\u1234efgh\"  ";
    len = strlen(str);
    Col_RopeIterString(begin, COL_UCS1, str, len);
    Col_RopeIterSet(end, begin); Col_RopeIterForward(end, len);
    ASSERT(Coatl_ReadJson(begin, end, &v));
    ASSERT(Col_RopeIterCompare(begin, end) == 0);
    ASSERT(Col_WordType(v) & COL_ROPE);
    ASSERT(Col_RopeLength(v) == 9);
    ASSERT(Col_RopeAt(v, 4) == 0x1234);

    str = "   \"abcd\\\"efgh\" ";
    len = strlen(str);
    Col_RopeIterString(begin, COL_UCS1, str, len);
    Col_RopeIterSet(end, begin); Col_RopeIterForward(end, len);
    ASSERT(Coatl_ReadJson(begin, end, &v));
    ASSERT(Col_RopeIterCompare(begin, end) == 0);
    ASSERT(Col_WordType(v) & COL_ROPE);
    WRITE_EXPECTED_JSON(v, 0, "\"abcd\\\"efgh\"");
}
PICOTEST_CASE(testJsonArray, testJson) {
    const char *str;
    size_t len;
    Col_Word v;
    const Col_Word *elements;
    Col_RopeIterator begin, end;

    str = "  [ null, true, false, 1, 2.0, 34.5, \"678\" ] ";
    len = strlen(str);
    Col_RopeIterString(begin, COL_UCS1, str, len);
    Col_RopeIterSet(end, begin); Col_RopeIterForward(end, len);
    ASSERT(Coatl_ReadJson(begin, end, &v));
    ASSERT(Col_RopeIterCompare(begin, end) == 0);
    ASSERT(Col_WordType(v) & COL_LIST);
    ASSERT(Col_WordType(v) & COL_VECTOR);
    ASSERT(Col_VectorLength(v) == 7);
    elements = Col_VectorElements(v);
    ASSERT(Col_WordType(elements[0]) == COL_NIL);
    ASSERT(elements[0] == WORD_NIL);
    ASSERT(Col_WordType(elements[1]) == COL_BOOL);
    ASSERT(elements[1] == WORD_TRUE);
    ASSERT(Col_WordType(elements[2]) == COL_BOOL);
    ASSERT(elements[2] == WORD_FALSE);
    ASSERT(Col_WordType(elements[3]) & COL_INT);
    ASSERT(Col_IntWordValue(elements[3]) == 1);
    ASSERT(Col_WordType(elements[4]) & COL_FLOAT);
    ASSERT(Col_FloatWordValue(elements[4]) == 2.0);
    ASSERT(Col_WordType(elements[5]) & COL_FLOAT);
    ASSERT(Col_FloatWordValue(elements[5]) == 34.5);
    ASSERT(Col_WordType(elements[6]) & COL_ROPE);
    ASSERT(Col_RopeLength(elements[6]) == 3);
    WRITE_EXPECTED_JSON(v, 0, 
        "["
            "null,"
            "true,"
            "false,"
            "1,"
            "2.0,"
            "3.45e1,"
            "\"678\""
        "]"
    );
    WRITE_EXPECTED_JSON(v, 2, 
        "["             "\n"
        "  null,"       "\n"
        "  true,"       "\n"
        "  false,"      "\n"
        "  1,"          "\n"
        "  2.0,"        "\n"
        "  3.45e1,"     "\n"
        "  \"678\""     "\n"
        "]"
    );
}
PICOTEST_CASE(testJsonObject, testJson) {
    const char *str;
    size_t len;
    Col_Word v, e;
    Col_RopeIterator begin, end;

    str = " { \"a\" : 1, \"b\" : 2.0, \"c\" : 34.5, \"d\" : \"678\" } ";
    len = strlen(str);
    Col_RopeIterString(begin, COL_UCS1, str, len);
    Col_RopeIterSet(end, begin); Col_RopeIterForward(end, len);
    ASSERT(Coatl_ReadJson(begin, end, &v));
    ASSERT(Col_RopeIterCompare(begin, end) == 0);
    ASSERT(Col_WordType(v) & COL_MAP);
    ASSERT(Col_MapSize(v) == 4);
    ASSERT(Col_MapGet(v, Col_NewRopeFromString("a"), &e));
    ASSERT(Col_WordType(e) & COL_INT);
    ASSERT(Col_IntWordValue(e) == 1);
    ASSERT(Col_MapGet(v, Col_NewRopeFromString("b"), &e));
    ASSERT(Col_WordType(e) & COL_FLOAT);
    ASSERT(Col_FloatWordValue(e) == 2.0);
    ASSERT(Col_MapGet(v, Col_NewRopeFromString("c"), &e));
    ASSERT(Col_WordType(e) & COL_FLOAT);
    ASSERT(Col_FloatWordValue(e) == 34.5);
    ASSERT(Col_MapGet(v, Col_NewRopeFromString("d"), &e));
    ASSERT(Col_WordType(e) & COL_ROPE);
    ASSERT(Col_RopeLength(e) == 3);
    WRITE_EXPECTED_JSON(v, 0, 
        "{"
            "\"a\":1,"
            "\"b\":2.0,"
            "\"c\":3.45e1,"
            "\"d\":\"678\""
        "}"
    );
    WRITE_EXPECTED_JSON(v, 2, 
        "{"                     "\n"
        "  \"a\": 1,"           "\n"
        "  \"b\": 2.0,"         "\n"
        "  \"c\": 3.45e1,"      "\n"
        "  \"d\": \"678\""      "\n"
        "}"
    );
}
PICOTEST_CASE(testJsonValue, testJson) {
    const char *str;
    size_t len;
    Col_Word v, e;
    Col_RopeIterator begin, end;

    str = " { \"a\" :   [ null, true, false, 1, 2.0, 34.5, \"678\" ] , \"b\" : 2.0, \"c\" :  { \"a\" : 1, \"b\" : [     1, 2.0, 34.5, \"678\"  ] , \"c\" : 34.5, \"d\" : \"678\" } , \"d\" : \"678\" } ";
    len = strlen(str);
    Col_RopeIterString(begin, COL_UCS1, str, len);
    Col_RopeIterSet(end, begin); Col_RopeIterForward(end, len);
    ASSERT(Coatl_ReadJson(begin, end, &v));
    ASSERT(Col_RopeIterCompare(begin, end) == 0);
    ASSERT(Col_WordType(v) & COL_MAP);
    ASSERT(Col_MapSize(v) == 4);
    ASSERT(Col_MapGet(v, Col_NewRopeFromString("a"), &e));
    ASSERT(Col_WordType(e) & COL_LIST);
    ASSERT(Col_ListLength(e) == 7);
    ASSERT(Col_MapGet(v, Col_NewRopeFromString("b"), &e));
    ASSERT(Col_WordType(e) & COL_FLOAT);
    ASSERT(Col_FloatWordValue(e) == 2.0);
    ASSERT(Col_MapGet(v, Col_NewRopeFromString("c"), &e));
    ASSERT(Col_WordType(e) & COL_MAP);
    ASSERT(Col_MapSize(e) == 4);
    ASSERT(Col_MapGet(v, Col_NewRopeFromString("d"), &e));
    ASSERT(Col_WordType(e) & COL_ROPE);
    ASSERT(Col_RopeLength(e) == 3);
    WRITE_EXPECTED_JSON(v, 0, 
        "{"
            "\"a\":["
                "null,"
                "true,"
                "false,"
                "1,"
                "2.0,"
                "3.45e1,"
                "\"678\""
            "],"
            "\"b\":2.0,"
            "\"c\":{"
                "\"a\":1,"
                "\"b\":["
                    "1,"
                    "2.0,"
                    "3.45e1,"
                    "\"678\""
                "],"
                "\"c\":3.45e1,"
                "\"d\":\"678\""
            "},"
            "\"d\":\"678\""
        "}"
    );
    WRITE_EXPECTED_JSON(v, 2, 
        "{"                     "\n"
        "  \"a\": ["            "\n"
        "    null,"             "\n"
        "    true,"             "\n"
        "    false,"            "\n"
        "    1,"                "\n"
        "    2.0,"              "\n"
        "    3.45e1,"           "\n"
        "    \"678\""           "\n"
        "  ],"                  "\n"
        "  \"b\": 2.0,"         "\n"
        "  \"c\": {"            "\n"
        "    \"a\": 1,"         "\n"
        "    \"b\": ["          "\n"
        "      1,"              "\n"
        "      2.0,"            "\n"
        "      3.45e1,"         "\n"
        "      \"678\""         "\n"
        "    ],"                "\n"
        "    \"c\": 3.45e1,"    "\n"
        "    \"d\": \"678\""    "\n"
        "  },"                  "\n"
        "  \"d\": \"678\""      "\n"
        "}"
    );
}

