#include <colibri.h>
#include <coatl.h>
#include <picotest.h>
#include <limits.h>
#include <float.h>
#include <math.h>

#define STRINGIZE(s) COL_STRINGIZE(s)

/*
 * Numbers
 */

#include "hooks.h"
#include "colibriFixture.h"

PICOTEST_SUITE(testNumbers, testMultiplePrecisionIntegerWords,
               testMultiplePrecisionFloatingPointWords, testNumberIO,
               testNumberConversion);

/* Multiple precision integers */
PICOTEST_SUITE(testMultiplePrecisionIntegerWords,
               testMultiplePrecisionIntegerWordPredicates);

PICOTEST_SUITE(testMultiplePrecisionIntegerWordPredicates, testWordIsMpInt);
PICOTEST_CASE(testWordIsMpInt, colibriFixture) {
    Col_Word rope = Col_NewRopeFromString("1");
    Col_Word word = Coatl_RopeToIntWord(rope, NULL, COATL_INTREAD_MP);
    PICOTEST_ASSERT(Coatl_WordIsMpInt(word));
}

/* Multiple precision floating points */
PICOTEST_SUITE(testMultiplePrecisionFloatingPointWords,
               testMultiplePrecisionFloatingPointPredicates);

PICOTEST_SUITE(testMultiplePrecisionFloatingPointPredicates, testWordIsMpFloat);
PICOTEST_CASE(testWordIsMpFloat, colibriFixture) {
    Col_Word rope = Col_NewRopeFromString("1.0");
    Col_Word word = Coatl_RopeToFloatWord(rope, NULL, COATL_FLOATREAD_MP);
    PICOTEST_ASSERT(Coatl_WordIsMpFloat(word));
}

/* Number input/output */
PICOTEST_SUITE(testNumberIO, testReadIntWord, testReadFloatWord,
               testWriteIntWord, testWriteFloatWord);

static void initIterators(const char *str, Col_RopeIterator begin,
                          Col_RopeIterator end) {
    const size_t len = strlen(str);
    Col_RopeIterString(begin, COL_UCS1, str, len);
    Col_RopeIterSet(end, begin);
    Col_RopeIterForward(end, len);
}
PICOTEST_SUITE(testReadIntWord, testReadIntWordErrors, testReadIntWordNative,
               testReadIntWordMp, testReadIntWordFormat);

static void checkReadIntWord(const char *str, size_t length,
                             const Coatl_NumReadFormat *format, int types,
                             Col_Word *wordPtr) {
    Col_RopeIterator begin, begin2, end;

    initIterators(str, begin, end);
    Col_RopeIterSet(begin2, begin);

    PICOTEST_ASSERT(Coatl_ReadIntWord(begin, end, format, types, wordPtr));
    PICOTEST_ASSERT(
        !types ||
        ((types & COATL_INTREAD_NATIVE) &&
         (Col_WordType(*wordPtr) == COL_INT)) ||
        ((types & COATL_INTREAD_MP) && Coatl_WordIsMpInt(*wordPtr)));

    PICOTEST_ASSERT(Coatl_ReadIntWord(begin2, end, format, types, NULL));
    PICOTEST_VERIFY(Col_RopeIterCompare(begin, begin2) == 0);

    if (length == -1) {
        PICOTEST_ASSERT(Col_RopeIterEnd(begin));
    } else {
        PICOTEST_ASSERT(Col_RopeIterIndex(begin) == length);
    }
}
static void checkReadIntWordNative(const char *str, intptr_t value,
                                   size_t length,
                                   const Coatl_NumReadFormat *format) {
    Col_Word v;
    checkReadIntWord(str, length, format, COATL_INTREAD_NATIVE, &v);
    PICOTEST_ASSERT(Col_IntWordValue(v) == value);
}
static void checkReadIntWordMp(const char *str,
                               // mpz_t value, TODO compare value?
                               size_t length,
                               const Coatl_NumReadFormat *format) {
    Col_Word v;
    checkReadIntWord(str, length, format, COATL_INTREAD_MP, &v);
}

PICOTEST_SUITE(testReadIntWordErrors, testReadIntWordEmpty,
               testReadIntWordNoDigit);
PICOTEST_CASE(testReadIntWordEmpty, colibriFixture) {
    Col_RopeIterator begin, end;
    Col_Word value;

    initIterators("", begin, end);
    PICOTEST_ASSERT(!Coatl_ReadIntWord(begin, end, NULL, 0, NULL));
    PICOTEST_ASSERT(!Coatl_ReadIntWord(begin, end, NULL, 0, &value));
}
PICOTEST_CASE(testReadIntWordNoDigit, colibriFixture) {
    Col_RopeIterator begin, end;
    Col_Word value;

    initIterators("$", begin, end);
    PICOTEST_ASSERT(!Coatl_ReadIntWord(begin, end, NULL, 0, NULL));
    PICOTEST_VERIFY(Col_RopeIterIndex(begin) == 0);

    initIterators("&", begin, end);
    PICOTEST_ASSERT(!Coatl_ReadIntWord(begin, end, NULL, 0, &value));
    PICOTEST_VERIFY(Col_RopeIterIndex(begin) == 0);
    // TODO with ignored chars
}

PICOTEST_CASE(testReadIntWordNative, colibriFixture) {
    checkReadIntWordNative("1", 1, -1, COATL_INTREAD_C);
    checkReadIntWordNative("0x10000000", 0x10000000, -1, COATL_INTREAD_C);
}
PICOTEST_CASE(testReadIntWordMp, colibriFixture) {
    checkReadIntWordMp("1", -1, COATL_INTREAD_C);
    checkReadIntWordMp("0x100000000", -1, COATL_INTREAD_C);
    checkReadIntWordMp("0x10000000000000000", -1, COATL_INTREAD_C);
    checkReadIntWordMp("0x1000000000000000000000000000000000000"
                       "0000000000000000000000000000",
                       -1, COATL_INTREAD_C);
}

PICOTEST_SUITE(testReadIntWordFormat, testReadIntWordDefault, testReadIntWordC,
               testReadIntWordPrefixChars, testReadIntWordRadixChars);

PICOTEST_CASE(testReadIntWordDefault, colibriFixture) {
    checkReadIntWordNative("1234", 1234, -1, NULL);
    checkReadIntWordNative("+1234", 1234, -1, NULL);
    checkReadIntWordNative("-1234", -1234, -1, NULL);
    checkReadIntWordNative("123aBc", 123, 3, NULL);
}

PICOTEST_SUITE(testReadIntWordC, testReadIntWordCDecimal, testReadIntWordCHex,
               testReadIntWordCOctal);

PICOTEST_CASE(testReadIntWordCDecimal, colibriFixture) {
    checkReadIntWordNative("1234", 1234, -1, COATL_INTREAD_C);
    checkReadIntWordNative("+1234", 1234, -1, COATL_INTREAD_C);
    checkReadIntWordNative("-1234", -1234, -1, COATL_INTREAD_C);
    checkReadIntWordNative("123aBc", 123, 3, COATL_INTREAD_C);
}

PICOTEST_CASE(testReadIntWordCHex, colibriFixture) {
    checkReadIntWordNative("0x1234", 0x1234, -1, COATL_INTREAD_C);
    checkReadIntWordNative("0X1234", 0x1234, -1, COATL_INTREAD_C);
    checkReadIntWordNative("+0x1234", 0x1234, -1, COATL_INTREAD_C);
    checkReadIntWordNative("+0X1234", 0x1234, -1, COATL_INTREAD_C);
    checkReadIntWordNative("-0x1234", -0x1234, -1, COATL_INTREAD_C);
    checkReadIntWordNative("-0X1234", -0x1234, -1, COATL_INTREAD_C);
    checkReadIntWordNative("0xAbCdEf", 0xABCDEF, -1, COATL_INTREAD_C);
    checkReadIntWordNative("0XaBcDeF", 0xABCDEF, -1, COATL_INTREAD_C);
    checkReadIntWordNative("0xDeFgH", 0xDEF, 5, COATL_INTREAD_C);
}

PICOTEST_CASE(testReadIntWordCOctal, colibriFixture) {
    checkReadIntWordNative("01234", 01234, -1, COATL_INTREAD_C);
    checkReadIntWordNative("+01234", 01234, -1, COATL_INTREAD_C);
    checkReadIntWordNative("-01234", -01234, -1, COATL_INTREAD_C);
    checkReadIntWordNative("05678", 0567, 4, COATL_INTREAD_C);
}

PICOTEST_CASE(testReadIntWordPrefixChars, colibriFixture) {
    const Col_Char prefixChars[] = {'r', 'R', COL_CHAR_INVALID};
    const Coatl_NumReadFormat format = {
        /* .radix       = */ 10,
        /* .ignoreChars = */ NULL,
        /* .prefixChars = */ prefixChars,
        /* .radixChars  = */ NULL,
        /* .pointChars  = */ NULL,
        /* .expChars    = */ NULL,
        /* .expC2Chars  = */ NULL,
    };

    /* Decimal */
    checkReadIntWordNative("1234", 1234, -1, &format);
    checkReadIntWordNative("+1234", 1234, -1, &format);
    checkReadIntWordNative("-1234", -1234, -1, &format);
    checkReadIntWordNative("123AbC", 123, 3, &format);

    /* Binary */
    checkReadIntWordNative("2r0101", 5, -1, &format);
    checkReadIntWordNative("+2R0101", 5, -1, &format);
    checkReadIntWordNative("-2r0101", -5, -1, &format);
    checkReadIntWordNative("2R0123", 1, 4, &format);

    /* Base-4 */
    checkReadIntWordNative("4R123", 27, -1, &format);
    checkReadIntWordNative("+4r123", 27, -1, &format);
    checkReadIntWordNative("-4R123", -27, -1, &format);
    checkReadIntWordNative("4r12345", 27, 5, &format);

    /* Base-8 */
    checkReadIntWordNative("8r123", 83, -1, &format);
    checkReadIntWordNative("+8R123", 83, -1, &format);
    checkReadIntWordNative("-8r123", -83, -1, &format);
    checkReadIntWordNative("8R5678", 375, 5, &format);

    /* Base-16 */
    checkReadIntWordNative("16rF", 15, -1, &format);
    checkReadIntWordNative("16rf", 15, -1, &format);
    checkReadIntWordNative("16r123", 291, -1, &format);
    checkReadIntWordNative("+16R123", 291, -1, &format);
    checkReadIntWordNative("-16r123", -291, -1, &format);
    checkReadIntWordNative("16rAbCdEf", 11259375, -1, &format);
    checkReadIntWordNative("16RcDeFgH", 52719, 7, &format);

    /* Base-32 */
    checkReadIntWordNative("32rV", 31, -1, &format);
    checkReadIntWordNative("32rv", 31, -1, &format);
    checkReadIntWordNative("32r123", 1091, -1, &format);
    checkReadIntWordNative("+32R123", 1091, -1, &format);
    checkReadIntWordNative("-32r123", -1091, -1, &format);
    checkReadIntWordNative("32RRStUv", 29259743, -1, &format);
    checkReadIntWordNative("32rRStUv", 29259743, -1, &format);
    checkReadIntWordNative("32RrStUv", 29259743, -1, &format);
    checkReadIntWordNative("32rrStUv", 29259743, -1, &format);
    checkReadIntWordNative("32rUvWx", 991, 5, &format);

    /* Base-36 */
    checkReadIntWordNative("36rZ", 35, -1, &format);
    checkReadIntWordNative("36rz", 35, -1, &format);
    checkReadIntWordNative("36r123", 1371, -1, &format);
    checkReadIntWordNative("+36R123", 1371, -1, &format);
    checkReadIntWordNative("-36r123", -1371, -1, &format);
    checkReadIntWordNative("36RvWxYz", 53605115, -1, &format);
    checkReadIntWordNative("36rvWxYz", 53605115, -1, &format);
    checkReadIntWordNative("36RVwXyZ", 53605115, -1, &format);
    checkReadIntWordNative("36rVwXyZ", 53605115, -1, &format);
    checkReadIntWordNative("36rxYz$", 44027, 6, &format);

    /* Base-62 */
    checkReadIntWordNative("62rZ", 35, -1, &format);
    checkReadIntWordNative("62rz", 61, -1, &format);
    checkReadIntWordNative("62r123", 3971, -1, &format);
    checkReadIntWordNative("+62R123", 3971, -1, &format);
    checkReadIntWordNative("-62r123", -3971, -1, &format);
    checkReadIntWordNative("62RvWxYz", 850106613, -1, &format);
    checkReadIntWordNative("62rvWxYz", 850106613, -1, &format);
    checkReadIntWordNative("62RVwXyZ", 472020047, -1, &format);
    checkReadIntWordNative("62rVwXyZ", 472020047, -1, &format);
    checkReadIntWordNative("62rxYz@", 228965, 6, &format);
}

PICOTEST_CASE(testReadIntWordRadixChars, colibriFixture) {
    const Coatl_NumReadFormat_RadixChar radixChars[] = {
        {'b', 2}, {'$', 3}, {'\0', 4}, {COL_CHAR_INVALID}};
    const Coatl_NumReadFormat format = {
        /* .radix       = */ 10,
        /* .ignoreChars = */ NULL,
        /* .prefixChars = */ NULL,
        /* .radixChars  = */ radixChars,
        /* .pointChars  = */ NULL,
        /* .expChars    = */ NULL,
        /* .expC2Chars  = */ NULL,
    };

    /* Decimal */
    checkReadIntWordNative("1234", 1234, -1, &format);
    checkReadIntWordNative("+1234", 1234, -1, &format);
    checkReadIntWordNative("-1234", -1234, -1, &format);
    checkReadIntWordNative("123ABC", 123, 3, &format);

    /* Binary */
    checkReadIntWordNative("0b0101", 5, -1, &format);
    checkReadIntWordNative("+0b0101", 5, -1, &format);
    checkReadIntWordNative("-0b0101", -5, -1, &format);
    checkReadIntWordNative("0b0123", 1, 4, &format);

    /* Base-3 */
    checkReadIntWordNative("0$12", 5, -1, &format);
    checkReadIntWordNative("+0$12", 5, -1, &format);
    checkReadIntWordNative("-0$12", -5, -1, &format);
    checkReadIntWordNative("0$12345", 5, 4, &format);

    /* Base-4 */
    checkReadIntWordNative("0123", 27, -1, &format);
    checkReadIntWordNative("+0123", 27, -1, &format);
    checkReadIntWordNative("-0123", -27, -1, &format);
    checkReadIntWordNative("012345", 27, 4, &format);
}

PICOTEST_SUITE(testReadFloatWord, testReadFloatWordErrors,
               testReadFloatWordNative, testReadFloatWordMp,
               testReadFloatWordFormat);

PICOTEST_SUITE(testReadFloatWordErrors, testReadFloatWordEmpty,
               testReadFloatWordNoDigit, testReadFloatWordNoMantissa,
               testReadFloatWordNoExponentDigits);

static int checkReadFloatLength(const char *str, int expectedLength,
                                const Coatl_NumReadFormat *format,
                                Col_Word *wordPtr) {
    Col_RopeIterator begin, end;
    initIterators(str, begin, end);
    const int result = Coatl_ReadFloatWord(begin, end, format, 0, NULL);
    PICOTEST_ASSERT(Col_RopeIterIndex(begin) == expectedLength);
    return result;
}
PICOTEST_CASE(testReadFloatWordEmpty, colibriFixture) {
    Col_Word value;
    PICOTEST_ASSERT(!checkReadFloatLength("", 0, NULL, NULL));
    PICOTEST_ASSERT(!checkReadFloatLength("", 0, NULL, &value));
}
PICOTEST_CASE(testReadFloatWordNoDigit, colibriFixture) {
    Col_Word value;

    PICOTEST_ASSERT(!checkReadFloatLength("$", 0, NULL, NULL));
    PICOTEST_ASSERT(!checkReadFloatLength("$", 0, NULL, &value));

    PICOTEST_ASSERT(!checkReadFloatLength(".", 1, NULL, NULL));
    PICOTEST_ASSERT(!checkReadFloatLength(".", 1, NULL, &value));
}
PICOTEST_CASE(testReadFloatWordNoMantissa, colibriFixture) {
    Col_Word value;

    PICOTEST_ASSERT(!checkReadFloatLength("e1", 0, NULL, NULL));
    PICOTEST_ASSERT(!checkReadFloatLength("e1", 0, NULL, &value));

    PICOTEST_ASSERT(!checkReadFloatLength("E+2", 0, NULL, NULL));
    PICOTEST_ASSERT(!checkReadFloatLength("E+2", 0, NULL, &value));

    PICOTEST_ASSERT(!checkReadFloatLength("p3", 0, COATL_FLOATREAD_C, NULL));
    PICOTEST_ASSERT(!checkReadFloatLength("p3", 0, COATL_FLOATREAD_C, &value));

    PICOTEST_ASSERT(!checkReadFloatLength("P-4", 0, COATL_FLOATREAD_C, NULL));
    PICOTEST_ASSERT(!checkReadFloatLength("P-4", 0, COATL_FLOATREAD_C, &value));
}
PICOTEST_CASE(testReadFloatWordNoExponentDigits, colibriFixture) {
    Col_Word value;

    PICOTEST_ASSERT(!checkReadFloatLength("1e", 2, NULL, NULL));
    PICOTEST_ASSERT(!checkReadFloatLength("1e", 2, NULL, &value));

    PICOTEST_ASSERT(!checkReadFloatLength("2.E+", 4, NULL, NULL));
    PICOTEST_ASSERT(!checkReadFloatLength("2.E+", 4, NULL, &value));

    PICOTEST_ASSERT(!checkReadFloatLength("3.4p", 4, COATL_FLOATREAD_C, NULL));
    PICOTEST_ASSERT(
        !checkReadFloatLength("3.4p", 4, COATL_FLOATREAD_C, &value));

    PICOTEST_ASSERT(!checkReadFloatLength(".56P-", 5, COATL_FLOATREAD_C, NULL));
    PICOTEST_ASSERT(
        !checkReadFloatLength(".56P-", 5, COATL_FLOATREAD_C, &value));
}

static void checkReadFloatWord(const char *str, size_t length,
                               const Coatl_NumReadFormat *format, int types,
                               Col_Word *wordPtr) {
    Col_RopeIterator begin, begin2, end;

    initIterators(str, begin, end);
    Col_RopeIterSet(begin2, begin);

    PICOTEST_ASSERT(Coatl_ReadFloatWord(begin, end, format, types, wordPtr));
    PICOTEST_ASSERT(
        !types ||
        ((types & COATL_FLOATREAD_NATIVE) &&
         (Col_WordType(*wordPtr) == COL_FLOAT)) ||
        ((types & COATL_FLOATREAD_MP) && Coatl_WordIsMpFloat(*wordPtr)));

    PICOTEST_ASSERT(Coatl_ReadFloatWord(begin2, end, format, types, NULL));
    PICOTEST_VERIFY(Col_RopeIterCompare(begin, begin2) == 0);

    if (length == -1) {
        PICOTEST_ASSERT(Col_RopeIterEnd(begin));
    } else {
        PICOTEST_ASSERT(Col_RopeIterIndex(begin) == length);
    }
}
static void checkReadFloatWordNative(const char *str, double value,
                                     size_t length,
                                     const Coatl_NumReadFormat *format) {
    Col_Word v;
    checkReadFloatWord(str, length, format, COATL_FLOATREAD_NATIVE, &v);
    // "Good enough" double comparison
    const double value2 = Col_FloatWordValue(v);
    PICOTEST_ASSERT(value2 == value ||
                    fabs((value2 - value) / value) <= DBL_EPSILON);
}
static void checkReadFloatWordMp(const char *str,
                                 // mpf_t value, TODO compare value?
                                 size_t length,
                                 const Coatl_NumReadFormat *format) {
    Col_Word v;
    checkReadFloatWord(str, length, format, COATL_FLOATREAD_MP, &v);
}

PICOTEST_CASE(testReadFloatWordNative, colibriFixture) {
    checkReadFloatWordNative("1", 1, -1, COATL_FLOATREAD_C);
    checkReadFloatWordNative("1.25", 1.25, -1, COATL_FLOATREAD_C);
    checkReadFloatWordNative("1e10", 1e10, -1, COATL_FLOATREAD_C);
    checkReadFloatWordNative("0x10000000", 0x10000000, -1, COATL_FLOATREAD_C);
    checkReadFloatWordNative(STRINGIZE(DBL_MAX), DBL_MAX, -1,
                                       COATL_FLOATREAD_C);
    checkReadFloatWordNative("0x1p1023", 0x1p1023, -1, COATL_FLOATREAD_C);
    checkReadFloatWordNative("0x1p" STRINGIZE(DBL_MAX_EXP), INFINITY, -1,
                                              COATL_FLOATREAD_C);
}
PICOTEST_CASE(testReadFloatWordMp, colibriFixture) {
    checkReadFloatWordMp("1", -1, COATL_FLOATREAD_C);
    checkReadFloatWordMp("1.25", -1, COATL_FLOATREAD_C);
    checkReadFloatWordMp("1e10", -1, COATL_FLOATREAD_C);
    checkReadFloatWordMp("1000000000000000000000.25e10", -1, COATL_FLOATREAD_C);
    checkReadFloatWordMp("0x100000000", -1, COATL_FLOATREAD_C);
    checkReadFloatWordMp("0x10000000000000000", -1, COATL_FLOATREAD_C);
    checkReadFloatWordMp("0x1000000000000000000000000000000000000"
                         "0000000000000000000000000000",
                         -1, COATL_FLOATREAD_C);
    checkReadFloatWordMp("0x1p1023", -1, COATL_FLOATREAD_C);
    checkReadFloatWordMp("0x100000000000000000p100000", -1, COATL_FLOATREAD_C);
}
PICOTEST_SUITE(testReadFloatWordFormat, testReadFloatWordDefault,
               testReadFloatWordC, testReadFloatWordPrefixChars,
               testReadFloatWordRadixChars, testReadFloatWordPointChars,
               testReadFloatWordExpChars, testReadFloatWordExpC2Chars);
PICOTEST_CASE(testReadFloatWordDefault, colibriFixture) {
    checkReadFloatWordNative("1234", 1234, -1, NULL);
    checkReadFloatWordNative("1234.56", 1234.56, -1, NULL);
    checkReadFloatWordNative("1234e56", 1234e56, -1, NULL);
    checkReadFloatWordNative("1234e+56", 1234e56, -1, NULL);
    checkReadFloatWordNative("1234e-56", 1234e-56, -1, NULL);
    checkReadFloatWordNative("+1234", 1234, -1, NULL);
    checkReadFloatWordNative("+1234.56", 1234.56, -1, NULL);
    checkReadFloatWordNative("+1234e56", 1234e56, -1, NULL);
    checkReadFloatWordNative("+1234e+56", 1234e56, -1, NULL);
    checkReadFloatWordNative("+1234e-56", 1234e-56, -1, NULL);
    checkReadFloatWordNative("-1234", -1234, -1, NULL);
    checkReadFloatWordNative("-1234.56", -1234.56, -1, NULL);
    checkReadFloatWordNative("-1234e56", -1234e56, -1, NULL);
    checkReadFloatWordNative("-1234e+56", -1234e56, -1, NULL);
    checkReadFloatWordNative("-1234e-56", -1234e-56, -1, NULL);
    checkReadFloatWordNative("123aBc", 123, 3, NULL);
    checkReadFloatWordNative("123e4aBc", 123e4, 5, NULL);
}

PICOTEST_SUITE(testReadFloatWordC, testReadFloatWordCDecimal,
               testReadFloatWordCHex);

PICOTEST_CASE(testReadFloatWordCDecimal, colibriFixture) {
    checkReadFloatWordNative("1234", 1234, -1, COATL_FLOATREAD_C);
    checkReadFloatWordNative("1234.56", 1234.56, -1, COATL_FLOATREAD_C);
    checkReadFloatWordNative("1234e56", 1234e56, -1, COATL_FLOATREAD_C);
    checkReadFloatWordNative("123.4e+56", 123.4e56, -1, COATL_FLOATREAD_C);
    checkReadFloatWordNative("12.34e-56", 12.34e-56, -1, COATL_FLOATREAD_C);
    checkReadFloatWordNative("+1234", 1234, -1, COATL_FLOATREAD_C);
    checkReadFloatWordNative("+1234.56", 1234.56, -1, COATL_FLOATREAD_C);
    checkReadFloatWordNative("+1234e56", 1234e56, -1, COATL_FLOATREAD_C);
    checkReadFloatWordNative("+.1234e+56", .1234e56, -1, COATL_FLOATREAD_C);
    checkReadFloatWordNative("+1234e-56", 1234e-56, -1, COATL_FLOATREAD_C);
    checkReadFloatWordNative("-1234", -1234, -1, COATL_FLOATREAD_C);
    checkReadFloatWordNative("-1234.56", -1234.56, -1, COATL_FLOATREAD_C);
    checkReadFloatWordNative("-1234e56", -1234e56, -1, COATL_FLOATREAD_C);
    checkReadFloatWordNative("-1234e+56", -1234e56, -1, COATL_FLOATREAD_C);
    checkReadFloatWordNative("-1234e-56", -1234e-56, -1, COATL_FLOATREAD_C);
    checkReadFloatWordNative("123aBc", 123, 3, COATL_FLOATREAD_C);
    checkReadFloatWordNative("123e4aBc", 123e4, 5, COATL_FLOATREAD_C);
}

PICOTEST_CASE(testReadFloatWordCHex, colibriFixture) {
    checkReadFloatWordNative("0x1234", 0x1234, -1, COATL_FLOATREAD_C);
    checkReadFloatWordNative("0X123.4", 0x123.4p0, -1, COATL_FLOATREAD_C);
    checkReadFloatWordNative("0x12.34p45", 0x12.34p45, -1, COATL_FLOATREAD_C);
    checkReadFloatWordNative("0X1.234p45", 0x1.234p45, -1, COATL_FLOATREAD_C);
    checkReadFloatWordNative("0x.1234P45", 0x.1234P45, -1, COATL_FLOATREAD_C);
    checkReadFloatWordNative("0X1234P45", 0x1234P45, -1, COATL_FLOATREAD_C);
    checkReadFloatWordNative("0x1234p+45", 0x1234p45, -1, COATL_FLOATREAD_C);
    checkReadFloatWordNative("0X1234p+45", 0x1234p45, -1, COATL_FLOATREAD_C);
    checkReadFloatWordNative("0x1234P+45", 0x1234P45, -1, COATL_FLOATREAD_C);
    checkReadFloatWordNative("0X1234P+45", 0x1234P45, -1, COATL_FLOATREAD_C);
    checkReadFloatWordNative("0x1234p-45", 0x1234p-45, -1, COATL_FLOATREAD_C);
    checkReadFloatWordNative("0X1234p-45", 0x1234p-45, -1, COATL_FLOATREAD_C);
    checkReadFloatWordNative("0x1234P-45", 0x1234P-45, -1, COATL_FLOATREAD_C);
    checkReadFloatWordNative("0X1234P-45", 0x1234P-45, -1, COATL_FLOATREAD_C);
    checkReadFloatWordNative("+0x1234", 0x1234, -1, COATL_FLOATREAD_C);
    checkReadFloatWordNative("+0X1234", 0x1234, -1, COATL_FLOATREAD_C);
    checkReadFloatWordNative("+0x1234p45", 0x1234p45, -1, COATL_FLOATREAD_C);
    checkReadFloatWordNative("+0X1234p45", 0x1234p45, -1, COATL_FLOATREAD_C);
    checkReadFloatWordNative("+0x1234P45", 0x1234P45, -1, COATL_FLOATREAD_C);
    checkReadFloatWordNative("+0X1234P45", 0x1234P45, -1, COATL_FLOATREAD_C);
    checkReadFloatWordNative("+0x1234p+45", 0x1234p45, -1, COATL_FLOATREAD_C);
    checkReadFloatWordNative("+0X1234p+45", 0x1234p45, -1, COATL_FLOATREAD_C);
    checkReadFloatWordNative("+0x1234P+45", 0x1234P45, -1, COATL_FLOATREAD_C);
    checkReadFloatWordNative("+0X1234P+45", 0x1234P45, -1, COATL_FLOATREAD_C);
    checkReadFloatWordNative("+0x1234p-45", 0x1234p-45, -1, COATL_FLOATREAD_C);
    checkReadFloatWordNative("+0X1234p-45", 0x1234p-45, -1, COATL_FLOATREAD_C);
    checkReadFloatWordNative("+0x1234P-45", 0x1234P-45, -1, COATL_FLOATREAD_C);
    checkReadFloatWordNative("+0X1234P-45", 0x1234P-45, -1, COATL_FLOATREAD_C);
    checkReadFloatWordNative("-0x1234", -0x1234, -1, COATL_FLOATREAD_C);
    checkReadFloatWordNative("-0X1234", -0x1234, -1, COATL_FLOATREAD_C);
    checkReadFloatWordNative("-0x1234p45", -0x1234p45, -1, COATL_FLOATREAD_C);
    checkReadFloatWordNative("-0X1234p45", -0x1234p45, -1, COATL_FLOATREAD_C);
    checkReadFloatWordNative("-0x1234P45", -0x1234P45, -1, COATL_FLOATREAD_C);
    checkReadFloatWordNative("-0X1234P45", -0x1234P45, -1, COATL_FLOATREAD_C);
    checkReadFloatWordNative("-0x1234p+45", -0x1234p45, -1, COATL_FLOATREAD_C);
    checkReadFloatWordNative("-0X1234p+45", -0x1234p45, -1, COATL_FLOATREAD_C);
    checkReadFloatWordNative("-0x1234P+45", -0x1234P45, -1, COATL_FLOATREAD_C);
    checkReadFloatWordNative("-0X1234P+45", -0x1234P45, -1, COATL_FLOATREAD_C);
    checkReadFloatWordNative("-0x1234p-45", -0x1234p-45, -1, COATL_FLOATREAD_C);
    checkReadFloatWordNative("-0X1234p-45", -0x1234p-45, -1, COATL_FLOATREAD_C);
    checkReadFloatWordNative("-0x1234P-45", -0x1234P-45, -1, COATL_FLOATREAD_C);
    checkReadFloatWordNative("-0X1234P-45", -0x1234P-45, -1, COATL_FLOATREAD_C);
    checkReadFloatWordNative("0xAbCdEf", 0xABCDEF, -1, COATL_FLOATREAD_C);
    checkReadFloatWordNative("0XaBcDeF", 0xABCDEF, -1, COATL_FLOATREAD_C);
    checkReadFloatWordNative("0xAbCdEf", 0xABCDEF, -1, COATL_FLOATREAD_C);
    checkReadFloatWordNative("0XaBcDeF", 0xABCDEF, -1, COATL_FLOATREAD_C);
    checkReadFloatWordNative("0xDeFgH", 0xDEF, 5, COATL_FLOATREAD_C);
    checkReadFloatWordNative("0x123p789AB", 0x123p789, 9, COATL_FLOATREAD_C);
}

PICOTEST_CASE(testReadFloatWordPrefixChars, colibriFixture) {
    const Col_Char pointChars[] = {'.', COL_CHAR_INVALID};
    const Col_Char prefixChars[] = {'r', 'R', COL_CHAR_INVALID};
    const Coatl_NumReadFormat format = {
        /* .radix       = */ 10,
        /* .ignoreChars = */ NULL,
        /* .prefixChars = */ prefixChars,
        /* .radixChars  = */ NULL,
        /* .pointChars  = */ pointChars,
        /* .expChars    = */ NULL,
        /* .expC2Chars  = */ NULL,
    };

    /* Decimal */
    checkReadFloatWordNative("1234", 1234, -1, &format);
    checkReadFloatWordNative("+123.4", 123.4, -1, &format);
    checkReadFloatWordNative("-12.34", -12.34, -1, &format);
    checkReadFloatWordNative("123AbC", 123, 3, &format);
    checkReadFloatWordNative("12.3AbC", 12.3, 4, &format);

    /* Binary */
    checkReadFloatWordNative("2r0101", 5.0, -1, &format);
    checkReadFloatWordNative("+2R010.1", 5.0 / 2, -1, &format);
    checkReadFloatWordNative("-2r01.01", -5.0 / 4, -1, &format);
    checkReadFloatWordNative("2R0123", 1.0, 4, &format);
    checkReadFloatWordNative("2R0.123", 1.0 / 2, 5, &format);

    /* Base-4 */
    checkReadFloatWordNative("4R123", 27.0, -1, &format);
    checkReadFloatWordNative("+4r12.3", 27.0 / 4, -1, &format);
    checkReadFloatWordNative("-4R1.23", -27.0 / 16, -1, &format);
    checkReadFloatWordNative("4r12345", 27.0, 5, &format);
    checkReadFloatWordNative("4r12.345", 27.0 / 4, 6, &format);

    /* Base-8 */
    checkReadFloatWordNative("8r123", 83.0, -1, &format);
    checkReadFloatWordNative("+8R12.3", 83.0 / 8, -1, &format);
    checkReadFloatWordNative("-8r1.23", -83.0 / 64, -1, &format);
    checkReadFloatWordNative("8R5678", 375.0, 5, &format);
    checkReadFloatWordNative("8R56.78", 375.0 / 8, 6, &format);

    /* Base-16 */
    checkReadFloatWordNative("16rF", 15, -1, &format);
    checkReadFloatWordNative("16rf", 15, -1, &format);
    checkReadFloatWordNative("16r123", 291.0, -1, &format);
    checkReadFloatWordNative("+16R12.3", 291.0 / 16, -1, &format);
    checkReadFloatWordNative("-16r1.23", -291.0 / (16 * 16), -1, &format);
    checkReadFloatWordNative("16rAbCdEf", 11259375.0, -1, &format);
    checkReadFloatWordNative("16rAbC.dEf", 11259375.0 / (16 * 16 * 16), -1,
                             &format);
    checkReadFloatWordNative("16RcDeFgH", 52719.0, 7, &format);
    checkReadFloatWordNative("16RcD.eFgH", 52719.0 / (16 * 16), 8, &format);

    /* Base-32 */
    checkReadFloatWordNative("32rV", 31, -1, &format);
    checkReadFloatWordNative("32rv", 31, -1, &format);
    checkReadFloatWordNative("32r123", 1091.0, -1, &format);
    checkReadFloatWordNative("+32R12.3", 1091.0 / 32, -1, &format);
    checkReadFloatWordNative("-32r1.23", -1091.0 / (32 * 32), -1, &format);
    checkReadFloatWordNative("32RRStUv", 29259743.0, -1, &format);
    checkReadFloatWordNative("32rRStU.v", 29259743.0 / 32, -1, &format);
    checkReadFloatWordNative("32RrSt.Uv", 29259743.0 / (32 * 32), -1, &format);
    checkReadFloatWordNative("32rrS.tUv", 29259743.0 / (32 * 32 * 32), -1,
                             &format);
    checkReadFloatWordNative("32rUvWx", 991.0, 5, &format);
    checkReadFloatWordNative("32rU.vWx", 991.0 / 32, 6, &format);

    /* Base-36 */
    checkReadFloatWordNative("36rZ", 35, -1, &format);
    checkReadFloatWordNative("36rz", 35, -1, &format);
    checkReadFloatWordNative("36r123", 1371.0, -1, &format);
    checkReadFloatWordNative("+36R12.3", 1371.0 / 36, -1, &format);
    checkReadFloatWordNative("-36r1.23", -1371.0 / (36 * 36), -1, &format);
    checkReadFloatWordNative("36RvWxYz", 53605115.0, -1, &format);
    checkReadFloatWordNative("36rvWxY.z", 53605115.0 / 36, -1, &format);
    checkReadFloatWordNative("36RVwX.yZ", 53605115.0 / (36 * 36), -1, &format);
    checkReadFloatWordNative("36rVw.XyZ", 53605115.0 / (36 * 36 * 36), -1,
                             &format);
    checkReadFloatWordNative("36rxYz$", 44027.0, 6, &format);
    checkReadFloatWordNative("36rxY.z$", 44027.0 / 36, 7, &format);

    /* Base-62 */
    checkReadFloatWordNative("62rZ", 35, -1, &format);
    checkReadFloatWordNative("62rz", 61, -1, &format);
    checkReadFloatWordNative("62r123", 3971.0, -1, &format);
    checkReadFloatWordNative("+62R12.3", 3971.0 / 62, -1, &format);
    checkReadFloatWordNative("-62r1.23", -3971.0 / (62 * 62), -1, &format);
    checkReadFloatWordNative("62RvWxYz", 850106613.0, -1, &format);
    checkReadFloatWordNative("62rvWxY.z", 850106613.0 / 62, -1, &format);
    checkReadFloatWordNative("62RVwXyZ", 472020047.0, -1, &format);
    checkReadFloatWordNative("62rVwXy.Z", 472020047.0 / 62, -1, &format);
    checkReadFloatWordNative("62rxYz@", 228965.0, 6, &format);
    checkReadFloatWordNative("62rxY.z@", 228965.0 / 62, 7, &format);
}
PICOTEST_CASE(testReadFloatWordRadixChars, colibriFixture) {
    const Col_Char pointChars[] = {'.', COL_CHAR_INVALID};
    const Coatl_NumReadFormat_RadixChar radixChars[] = {
        {'b', 2}, {'$', 3}, {'\0', 4}, {COL_CHAR_INVALID}};
    const Coatl_NumReadFormat format = {
        /* .radix       = */ 10,
        /* .ignoreChars = */ NULL,
        /* .prefixChars = */ NULL,
        /* .radixChars  = */ radixChars,
        /* .pointChars  = */ pointChars,
        /* .expChars    = */ NULL,
        /* .expC2Chars  = */ NULL,
    };

    /* Decimal */
    checkReadFloatWordNative("1234", 1234, -1, &format);
    checkReadFloatWordNative("+123.4", 123.4, -1, &format);
    checkReadFloatWordNative("-12.34", -12.34, -1, &format);
    checkReadFloatWordNative("123ABC", 123, 3, &format);
    checkReadFloatWordNative("12.3ABC", 12.3, 4, &format);

    /* Binary */
    checkReadFloatWordNative("0b0101", 5.0, -1, &format);
    checkReadFloatWordNative("+0b010.1", 5.0 / 2, -1, &format);
    checkReadFloatWordNative("-0b01.01", -5.0 / 4, -1, &format);
    checkReadFloatWordNative("0b0123", 1.0, 4, &format);
    checkReadFloatWordNative("0b0.123", 1.0 / 2, 5, &format);

    /* Base-3 */
    checkReadFloatWordNative("0$12", 5.0, -1, &format);
    checkReadFloatWordNative("+0$1.2", 5.0 / 3, -1, &format);
    checkReadFloatWordNative("-0$.12", -5.0 / (3 * 3), -1, &format);
    checkReadFloatWordNative("0$12345", 5.0, 4, &format);
    checkReadFloatWordNative("0$1.2345", 5.0 / 3, 5, &format);

    /* Base-4 */
    checkReadFloatWordNative("0123", 27.0, -1, &format);
    checkReadFloatWordNative("+012.3", 27.0 / 4, -1, &format);
    checkReadFloatWordNative("-01.23", -27.0 / (4 * 4), -1, &format);
    checkReadFloatWordNative("012345", 27.0, 4, &format);
    checkReadFloatWordNative("012.345", 27.0 / 4, 5, &format);
    checkReadFloatWordNative("0123123123123123123", 29451204315.0, -1, &format);
    checkReadFloatWordNative("0123123123123123.123",
                             29451204315.0 / (4 * 4 * 4), -1, &format);
}
PICOTEST_CASE(testReadFloatWordPointChars, colibriFixture) {
    const Col_Char pointChars[] = {',', COL_CHAR_INVALID};
    const Coatl_NumReadFormat_RadixChar radixChars[] = {
        {'b', 2}, {'$', 3}, {'\0', 4}, {COL_CHAR_INVALID}};
    const Coatl_NumReadFormat format = {
        /* .radix       = */ 10,
        /* .ignoreChars = */ NULL,
        /* .prefixChars = */ NULL,
        /* .radixChars  = */ NULL,
        /* .pointChars  = */ pointChars,
        /* .expChars    = */ NULL,
        /* .expC2Chars  = */ NULL,
    };

    checkReadFloatWordNative("1234", 1234, -1, &format);
    checkReadFloatWordNative("+123,4", 123.4, -1, &format);
    checkReadFloatWordNative("-12,34", -12.34, -1, &format);
    checkReadFloatWordNative("0,5678", .5678, -1, &format);
    checkReadFloatWordNative(",5678", .5678, -1, &format);
    checkReadFloatWordNative("+,5678", .5678, -1, &format);
    checkReadFloatWordNative("-,5678", -.5678, -1, &format);
    checkReadFloatWordNative("123ABC", 123, 3, &format);
    checkReadFloatWordNative("12.3ABC", 12, 2, &format);
    checkReadFloatWordNative("12,3ABC", 12.3, 4, &format);
}
PICOTEST_CASE(testReadFloatWordExpChars, colibriFixture) {
    const Col_Char pointChars[] = {'.', COL_CHAR_INVALID};
    const Col_Char expChars[] = {'x', 'Y', '%', COL_CHAR_INVALID};
    const Coatl_NumReadFormat format = {
        /* .radix       = */ 10,
        /* .ignoreChars = */ NULL,
        /* .prefixChars = */ NULL,
        /* .radixChars  = */ NULL,
        /* .pointChars  = */ pointChars,
        /* .expChars    = */ expChars,
        /* .expC2Chars  = */ NULL,
    };

    checkReadFloatWordNative("+123x4", 123e4, -1, &format);
    checkReadFloatWordNative("-12.3Y-4", -12.3e-4, -1, &format);
    checkReadFloatWordNative("1%+23", 1e+23, -1, &format);
    checkReadFloatWordNative("12e34", 12, 2, &format);
    checkReadFloatWordNative("12.3E4", 12.3, 4, &format);
}
PICOTEST_CASE(testReadFloatWordExpC2Chars, colibriFixture) {
    const Col_Char pointChars[] = {'.', COL_CHAR_INVALID};
    const Col_Char expC2Chars[] = {'x', 'Y', '%', COL_CHAR_INVALID};
    const Coatl_NumReadFormat format = {
        /* .radix       = */ 10,
        /* .ignoreChars = */ NULL,
        /* .prefixChars = */ NULL,
        /* .radixChars  = */ NULL,
        /* .pointChars  = */ pointChars,
        /* .expChars    = */ NULL,
        /* .expC2Chars  = */ expC2Chars,
    };

    checkReadFloatWordNative("+123x45", 0x7Bp45, -1, &format);
    checkReadFloatWordNative("-1.2Y34", -0xCp34 / 10, -1, &format);
    checkReadFloatWordNative("1%-23", 0x1p-23, -1, &format);
    checkReadFloatWordNative("12p34", 12, 2, &format);
    checkReadFloatWordNative("12.3P4", 12.3, 4, &format);
}

PICOTEST_SUITE(testWriteIntWord, testWriteIntWordErrors,
               testWriteIntWordDefault, testWriteIntWordC16,
               testWriteIntWordC8);

PICOTEST_SUITE(testWriteIntWordErrors, testWriteIntWordBadRadix);
PICOTEST_CASE(testWriteIntWordBadRadix, colibriFixture) {
    const Col_Word word = Col_NewIntWord(1);
    const Col_Word strbuf = Col_NewStringBuffer(0, COL_UCS1);

    Coatl_NumWriteFormat format;
    memset(&format, 0, sizeof(format));
    format.radix = 1;
    PICOTEST_ASSERT(Coatl_WriteIntWord(strbuf, word, &format) == 0);
    format.radix = 63;
    PICOTEST_ASSERT(Coatl_WriteIntWord(strbuf, word, &format) == 0);
}

static void checkWriteIntWord(Col_Word word, const char *expected,
                              const Coatl_NumWriteFormat *format) {
    Col_Word strbuf = Col_NewStringBuffer(0, COL_UCS1);
    PICOTEST_ASSERT(Coatl_WriteIntWord(strbuf, word, format) > 0);
    Col_Word str = Col_NewRopeFromString(expected);
    PICOTEST_ASSERT(Col_CompareRopes(str, Col_StringBufferFreeze(strbuf)) == 0);
}
PICOTEST_CASE(testWriteIntWordDefault, colibriFixture) {
    checkWriteIntWord(Col_NewIntWord(0), "0", NULL);
    checkWriteIntWord(Col_NewIntWord(1), "1", NULL);
    checkWriteIntWord(Col_NewIntWord(-1), "-1", NULL);
    checkWriteIntWord(Col_NewIntWord(12345), "12345", NULL);
    checkWriteIntWord(Col_NewIntWord(-12345), "-12345", NULL);
}
PICOTEST_CASE(testWriteIntWordC16, colibriFixture) {
    checkWriteIntWord(Col_NewIntWord(0), "0", COATL_NUMWRITE_C16);
    checkWriteIntWord(Col_NewIntWord(1), "0x1", COATL_NUMWRITE_C16);
    checkWriteIntWord(Col_NewIntWord(-1), "-0x1", COATL_NUMWRITE_C16);
    checkWriteIntWord(Col_NewIntWord(9), "0x9", COATL_NUMWRITE_C16);
    checkWriteIntWord(Col_NewIntWord(10), "0xa", COATL_NUMWRITE_C16);
    checkWriteIntWord(Col_NewIntWord(16), "0x10", COATL_NUMWRITE_C16);
}
PICOTEST_CASE(testWriteIntWordC8, colibriFixture) {
    checkWriteIntWord(Col_NewIntWord(0), "0", COATL_INTWRITE_C8);
    checkWriteIntWord(Col_NewIntWord(1), "01", COATL_INTWRITE_C8);
    checkWriteIntWord(Col_NewIntWord(-1), "-01", COATL_INTWRITE_C8);
    checkWriteIntWord(Col_NewIntWord(7), "07", COATL_INTWRITE_C8);
    checkWriteIntWord(Col_NewIntWord(8), "010", COATL_INTWRITE_C8);
}

PICOTEST_SUITE(testWriteFloatWord, testWriteFloatWordErrors,
               testWriteFloatWordDefault, testWriteFloatWordC16);

PICOTEST_SUITE(testWriteFloatWordErrors, testWriteFloatWordBadRadix,
               testWriteFloatWordBadFormat);
PICOTEST_CASE(testWriteFloatWordBadRadix, colibriFixture) {
    const Col_Word word = Col_NewFloatWord(1.25);
    const Col_Word strbuf = Col_NewStringBuffer(0, COL_UCS1);

    Coatl_NumWriteFormat format;
    memset(&format, 0, sizeof(format));
    format.radix = 1;
    PICOTEST_ASSERT(Coatl_WriteFloatWord(strbuf, word, &format) == 0);
    format.radix = 63;
    PICOTEST_ASSERT(Coatl_WriteFloatWord(strbuf, word, &format) == 0);
}
PICOTEST_CASE(testWriteFloatWordBadFormat, colibriFixture) {
    const Col_Word word = Col_NewFloatWord(1.25);
    const Col_Word strbuf = Col_NewStringBuffer(0, COL_UCS1);

    PICOTEST_ASSERT(Coatl_WriteFloatWord(strbuf, word, COATL_INTWRITE_C8) == 0);
}

static void checkWriteFloatWord(Col_Word word, const char *expected,
                                const Coatl_NumWriteFormat *format) {
    Col_Word strbuf = Col_NewStringBuffer(0, COL_UCS1);
    PICOTEST_ASSERT(Coatl_WriteFloatWord(strbuf, word, format) > 0);
    Col_Word str = Col_NewRopeFromString(expected);
    PICOTEST_ASSERT(Col_CompareRopes(str, Col_StringBufferFreeze(strbuf)) == 0);
}
PICOTEST_CASE(testWriteFloatWordDefault, colibriFixture) {
    checkWriteFloatWord(Col_NewFloatWord(0), "0", NULL);
    checkWriteFloatWord(Col_NewFloatWord(1), "1", NULL);
    checkWriteFloatWord(Col_NewFloatWord(-1), "-1", NULL);
    checkWriteFloatWord(Col_NewFloatWord(0.25), "2.5e-1", NULL);
    checkWriteFloatWord(Col_NewFloatWord(-0.125), "-1.25e-1", NULL);
    checkWriteFloatWord(Col_NewFloatWord(12345), "1.2345e4", NULL);
    checkWriteFloatWord(Col_NewFloatWord(-12345), "-1.2345e4", NULL);
    checkWriteFloatWord(Col_NewFloatWord(0x100000000), "4.294967296e9", NULL);
    checkWriteFloatWord(Col_NewFloatWord(-0x100000000), "-4.294967296e9", NULL);
}
PICOTEST_CASE(testWriteFloatWordC16, colibriFixture) {
    checkWriteFloatWord(Col_NewFloatWord(0), "0", COATL_NUMWRITE_C16);
    checkWriteFloatWord(Col_NewFloatWord(1), "0x1", COATL_NUMWRITE_C16);
    checkWriteFloatWord(Col_NewFloatWord(-1), "-0x1", COATL_NUMWRITE_C16);
    checkWriteFloatWord(Col_NewFloatWord(9), "0x9", COATL_NUMWRITE_C16);
    checkWriteFloatWord(Col_NewFloatWord(10), "0xa", COATL_NUMWRITE_C16);
    checkWriteFloatWord(Col_NewFloatWord(16), "0x1p4", COATL_NUMWRITE_C16);
    checkWriteFloatWord(Col_NewFloatWord(0x1p-1), "0x8p-4", COATL_NUMWRITE_C16);
    checkWriteFloatWord(Col_NewFloatWord(0x1.1p-1), "0x8.8p-4",
                        COATL_NUMWRITE_C16);
    checkWriteFloatWord(Col_NewFloatWord(0x1p-2), "0x4p-4", COATL_NUMWRITE_C16);
    checkWriteFloatWord(Col_NewFloatWord(0x1p-3), "0x2p-4", COATL_NUMWRITE_C16);
    checkWriteFloatWord(Col_NewFloatWord(0x1p-4), "0x1p-4", COATL_NUMWRITE_C16);
    checkWriteFloatWord(Col_NewFloatWord(0x1p-1), "0x8p-4", COATL_NUMWRITE_C16);
    checkWriteFloatWord(Col_NewFloatWord(0.25), "0x4p-4", COATL_NUMWRITE_C16);
    checkWriteFloatWord(Col_NewFloatWord(-0.125), "-0x2p-4",
                        COATL_NUMWRITE_C16);
    checkWriteFloatWord(Col_NewFloatWord(0x123456789), "0x1.23456789p32",
                        COATL_NUMWRITE_C16);
    checkWriteFloatWord(Col_NewFloatWord(-0x1AbCdEf0), "-0x1.abcdefp28",
                        COATL_NUMWRITE_C16);
}

/* Number conversion */
PICOTEST_SUITE(testNumberConversion, testRopeToIntWord, testRopeToFloatWord,
               testIntWordToRope, testFloatWordToRope);

PICOTEST_SUITE(testRopeToIntWord, testEmptyRopeToIntWord,
               testInvalidRopeToIntWord, testDecimalRopeToIntWord,
               testHexadecimalRopeToIntWord);
PICOTEST_CASE(testEmptyRopeToIntWord, colibriFixture) {
    const Col_Word rope = Col_NewRopeFromString("");
    const Col_Word word = Coatl_RopeToIntWord(rope, NULL, 0);
    PICOTEST_ASSERT(word == COL_NIL);
}
PICOTEST_CASE(testInvalidRopeToIntWord, colibriFixture) {
    const Col_Word rope = Col_NewRopeFromString("$%123");
    const Col_Word word = Coatl_RopeToIntWord(rope, NULL, 0);
    PICOTEST_ASSERT(word == COL_NIL);
}
PICOTEST_CASE(testDecimalRopeToIntWord, colibriFixture) {
    const Col_Word rope = Col_NewRopeFromString("123");
    const Col_Word word = Coatl_RopeToIntWord(rope, NULL, COATL_INTREAD_NATIVE);
    PICOTEST_ASSERT(Col_IntWordValue(word) == 123);
}
PICOTEST_CASE(testHexadecimalRopeToIntWord, colibriFixture) {
    const Col_Word rope = Col_NewRopeFromString("0x123");
    const Col_Word word =
        Coatl_RopeToIntWord(rope, COATL_INTREAD_C, COATL_INTREAD_NATIVE);
    PICOTEST_ASSERT(Col_IntWordValue(word) == 0x123);
}

PICOTEST_SUITE(testRopeToFloatWord, testEmptyRopeToFloatWord,
               testInvalidRopeToFloatWord, testDecimalRopeToFloatWord,
               testHexadecimalRopeToFloatWord);
PICOTEST_CASE(testEmptyRopeToFloatWord, colibriFixture) {
    const Col_Word rope = Col_NewRopeFromString("");
    const Col_Word word = Coatl_RopeToFloatWord(rope, NULL, 0);
    PICOTEST_ASSERT(word == COL_NIL);
}
PICOTEST_CASE(testInvalidRopeToFloatWord, colibriFixture) {
    const Col_Word rope = Col_NewRopeFromString("$%123");
    const Col_Word word = Coatl_RopeToFloatWord(rope, NULL, 0);
    PICOTEST_ASSERT(word == COL_NIL);
}
PICOTEST_CASE(testDecimalRopeToFloatWord, colibriFixture) {
    const Col_Word rope = Col_NewRopeFromString("1234.5");
    const Col_Word word =
        Coatl_RopeToFloatWord(rope, NULL, COATL_FLOATREAD_NATIVE);
    PICOTEST_ASSERT(Col_FloatWordValue(word) == 1234.5);
}
PICOTEST_CASE(testHexadecimalRopeToFloatWord, colibriFixture) {
    const Col_Word rope = Col_NewRopeFromString("0x123p4");
    const Col_Word word =
        Coatl_RopeToFloatWord(rope, COATL_FLOATREAD_C, COATL_FLOATREAD_NATIVE);
    PICOTEST_ASSERT(Col_FloatWordValue(word) == 0x123p4);
}

PICOTEST_SUITE(testIntWordToRope, testIntWordToDecimalRope,
               testIntWordToHexadecimalRope);
PICOTEST_CASE(testIntWordToDecimalRope, colibriFixture) {
    const Col_Word word = Col_NewIntWord(123);
    const Col_Word rope = Coatl_IntWordToRope(word, COL_UCS1, NULL);
    PICOTEST_ASSERT(Col_CompareRopes(rope, Col_NewRopeFromString("123")) == 0);
}
PICOTEST_CASE(testIntWordToHexadecimalRope, colibriFixture) {
    const Col_Word word = Col_NewIntWord(0x123);
    const Col_Word rope =
        Coatl_IntWordToRope(word, COL_UCS1, COATL_NUMWRITE_C16);
    PICOTEST_ASSERT(Col_CompareRopes(rope, Col_NewRopeFromString("0x123")) ==
                    0);
}

PICOTEST_SUITE(testFloatWordToRope, testFloatWordToDecimalRope,
               testFloatWordToHexadecimalRope);
PICOTEST_CASE(testFloatWordToDecimalRope, colibriFixture) {
    const Col_Word word = Col_NewFloatWord(1234.5);
    const Col_Word rope = Coatl_FloatWordToRope(word, COL_UCS1, NULL);
    PICOTEST_ASSERT(Col_CompareRopes(rope, Col_NewRopeFromString("1.2345e3")) ==
                    0);
}
PICOTEST_CASE(testFloatWordToHexadecimalRope, colibriFixture) {
    const Col_Word word = Col_NewFloatWord(0x123p4);
    const Col_Word rope =
        Coatl_FloatWordToRope(word, COL_UCS1, COATL_NUMWRITE_C16);
    PICOTEST_ASSERT(
        Col_CompareRopes(rope, Col_NewRopeFromString("0x1.23p12")) == 0);
}
