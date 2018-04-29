#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <float.h>

#include <coatl.h>

#include <picotest.h>

#include "testCoatl.h"

#ifdef _MSC_VER
#   pragma warning(disable: 4996)
#endif

/*
 *---------------------------------------------------------------------------
 *
 * testNumber --
 *
 *---------------------------------------------------------------------------
 */

static void compare(Col_Word rope, const char *string);

PICOTEST_SUITE(testNumber, 
    testInt, testFloat
)

PICOTEST_FIXTURE_SETUP(testNumber) {
    Col_Init(COL_SINGLE);
    Col_SetErrorProc(ERROR_PROC);

    Col_PauseGC();
}
PICOTEST_FIXTURE_TEARDOWN(testNumber) {
    if (!PICOTEST_FAIL) {
        Col_ResumeGC();
    }
    Col_Cleanup();
}


/*
 *---------------------------------------------------------------------------
 *
 * testInt --
 *
 *---------------------------------------------------------------------------
 */

PICOTEST_SUITE(testInt, 
    testIntPredefined, testIntRadix, testIntPrefix
)

#define READ_EXPECTED_INT(expected, value, format) { \
    Col_Word w; \
    Col_RopeIterator begin, end; \
    size_t len = strlen(value); \
    Col_RopeIterString(begin, COL_UCS1, value, len); \
    Col_RopeIterSet(end, begin); Col_RopeIterForward(end, len); \
    ASSERT(Coatl_ReadIntWord(begin, end, (format), COATL_INTREAD_NATIVE, &w)); \
    ASSERT(Col_IntWordValue(w) == (expected), "value=%s", value); \
    ASSERT(Col_RopeIterCompare(begin, end) == 0, "value=%s,begin index=%u", value, Col_RopeIterIndex(begin)); \
}
#define WRITE_EXPECTED_INT(value, expected, format) { \
    Col_Word number = Col_NewIntWord(value); \
    Col_Word strbuf = Col_NewStringBuffer(0, COL_UCS1); \
    Col_RopeIterator it; \
    \
    ASSERT(Coatl_WriteIntWord(strbuf, number, format) == (size_t) strlen(expected), "value=%d", value); \
    for (Col_RopeIterFirst(it, Col_StringBufferFreeze(strbuf)); \
            !Col_RopeIterEnd(it); Col_RopeIterNext(it)) { \
        ASSERT(Col_RopeIterAt(it) == (Col_Char) expected[Col_RopeIterIndex(it)], "value=%u,index=%u", value, Col_RopeIterIndex(it)); \
    } \
}

PICOTEST_CASE(testIntPredefined, testNumber) {
    int value;
    char buf[100];
    static Coatl_NumWriteFormat ignore;
    struct {
        const char *cFormat;
        const Coatl_NumReadFormat *formatR;
        const Coatl_NumWriteFormat *formatW;
    } formats[] = {
        {"%d",  COATL_NUMREAD_DEFAULT, COATL_NUMWRITE_DEFAULT},
        {"%#x", COATL_INTREAD_C, COATL_NUMWRITE_C16},
        {"%#X", COATL_INTREAD_C, &ignore},
        {"%#o", COATL_INTREAD_C, COATL_INTWRITE_C8},
    };
    size_t i, j;

    srand(0);

    for (i=0; i < 1000; i++) {
        if (i == 0) {
            /*
             * Ensure zero is tested at least once.
             */

            value = 0;
        } else {
            value = (int) (((((double)(rand())/RAND_MAX)-0.5)*2.0)*INT_MAX);
        }

        for (j=0; j < sizeof(formats)/sizeof(*formats); j++) {
            if (value < 0) {
                /*
                 * Contrary to C, CoATL uses a signed format for nondecimal radices.
                 */

                buf[0] = '-';
                snprintf(buf+1, sizeof(buf)-1, formats[j].cFormat, -value);
            } else {
                snprintf(buf, sizeof(buf), formats[j].cFormat, value);
            }
            READ_EXPECTED_INT(value, buf, formats[j].formatR);
            if (formats[j].formatW != &ignore) WRITE_EXPECTED_INT(value, buf, formats[j].formatW);
        }
    }
}
PICOTEST_CASE(testIntRadix, testNumber) {
    int value;
    char buf[100];
    static char *digits  = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    static char *digitsL = "0123456789abcdefghijklmnopqrstuvwxyz";
    static const Col_Char prefixChars[] = {'r', COL_CHAR_INVALID};
    Coatl_NumReadFormat formatR = {0, NULL, prefixChars, NULL, NULL, NULL, NULL};
    Coatl_NumWriteFormat formatW = {0, 0, 0, ' ', 0, 0, 0};
    unsigned int radix;

    for (radix=2; radix <= 62; radix++) {
        formatR.radix = radix;
        formatW.radix = radix;

        /*
         * Zero.
         */

        /* empty */
        formatW.flags = 0;
        formatW.minDigits = 0;
        value = 0;
        sprintf(buf, "");
        WRITE_EXPECTED_INT(value, buf, &formatW);

        /* forced sign */
        formatW.flags = COATL_NUMWRITE_PLUS;
        formatW.minDigits = 0;
        value = 0;
        sprintf(buf, "+");
        WRITE_EXPECTED_INT(value, buf, &formatW);

        /* forced pad */
        formatW.flags = COATL_NUMWRITE_SIGNPAD;
        formatW.minDigits = 0;
        value = 0;
        sprintf(buf, " ");
        WRITE_EXPECTED_INT(value, buf, &formatW);

        /* empty even with prefix */
        formatW.flags = 0;
        formatW.prefixChar = 'r';
        formatW.minDigits = 0;
        value = 0;
        sprintf(buf, "", formatW.radix);
        WRITE_EXPECTED_INT(value, buf, &formatW);

        /* no digits but forced prefix */
        formatW.flags = COATL_NUMWRITE_PREFIX_0;
        formatW.prefixChar = 'r';
        formatW.minDigits = 0;
        value = 0;
        sprintf(buf, "%ur", formatW.radix);
        WRITE_EXPECTED_INT(value, buf, &formatW);

        /* at least one digit */
        formatW.flags = 0;
        formatW.prefixChar = COL_CHAR_INVALID;
        formatW.minDigits = 1;
        value = 0;
        sprintf(buf, "0", formatW.radix);
        READ_EXPECTED_INT(value, buf, &formatR);
        WRITE_EXPECTED_INT(value, buf, &formatW);
        formatW.flags |= COATL_NUMWRITE_PLUS;
        sprintf(buf, "+0");
        READ_EXPECTED_INT(value, buf, &formatR);
        WRITE_EXPECTED_INT(value, buf, &formatW);
        sprintf(buf, "-0");
        READ_EXPECTED_INT(value, buf, &formatR);

        /* at least one digit with forced prefix */
        formatW.flags = COATL_NUMWRITE_PREFIX_0;
        formatW.prefixChar = 'r';
        formatW.minDigits = 1;
        value = 0;
        sprintf(buf, "%ur0", formatW.radix);
        READ_EXPECTED_INT(value, buf, &formatR);
        WRITE_EXPECTED_INT(value, buf, &formatW);

        /* ten digits */
        value = 0;
        formatW.prefixChar = COL_CHAR_INVALID;
        formatW.minDigits = 10;
        sprintf(buf, "0000000000");
        READ_EXPECTED_INT(value, buf, &formatR);
        WRITE_EXPECTED_INT(value, buf, &formatW);
        formatW.flags = COATL_NUMWRITE_PLUS;
        sprintf(buf, "+0000000000");
        READ_EXPECTED_INT(value, buf, &formatR);
        WRITE_EXPECTED_INT(value, buf, &formatW);
        sprintf(buf, "-0000000000");
        READ_EXPECTED_INT(value, buf, &formatR);

        /*
         * Well-known digit strings.
         */

        /* 10 = radix */
        formatW.flags = 0;
        formatW.prefixChar = COL_CHAR_INVALID;
        formatW.minDigits = 0;
        value = radix;
        sprintf(buf, "10");
        READ_EXPECTED_INT(value, buf, &formatR);
        WRITE_EXPECTED_INT(value, buf, &formatW);
        formatW.minDigits = 10;
        sprintf(buf, "0000000010");
        READ_EXPECTED_INT(value, buf, &formatR);
        WRITE_EXPECTED_INT(value, buf, &formatW);

        /* 101 = radix*radix + 1 */
        formatW.flags = 0;
        formatW.minDigits = 0;
        value = radix*radix+1;
        sprintf(buf, "101");
        READ_EXPECTED_INT(value, buf, &formatR);
        WRITE_EXPECTED_INT(value, buf, &formatW);
        formatW.minDigits = 10;
        sprintf(buf, "0000000101");
        READ_EXPECTED_INT(value, buf, &formatR);
        WRITE_EXPECTED_INT(value, buf, &formatW);

        /* radix-1 = highest digit */
        formatW.flags = 0;
        formatW.minDigits = 0;
        value = radix-1;
        sprintf(buf, "%c", digits[value]);
        READ_EXPECTED_INT(value, buf, &formatR);
        WRITE_EXPECTED_INT(value, buf, &formatW);
        if (formatR.radix <= 36) {
            formatW.flags = COATL_NUMWRITE_L;
            sprintf(buf, "%c", digitsL[value]);
            READ_EXPECTED_INT(value, buf, &formatR);
            WRITE_EXPECTED_INT(value, buf, &formatW);
        }
    }
}
PICOTEST_CASE(testIntPrefix, testNumber) {
    int value;
    char buf[100];
    static char *digits  = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    static char *digitsL = "0123456789abcdefghijklmnopqrstuvwxyz";
    static Col_Char prefix[] = {'r', COL_CHAR_INVALID};
    Coatl_NumReadFormat formatR = {0, NULL, prefix, NULL, NULL, NULL, NULL};
    Coatl_NumWriteFormat formatW = {0, 0, 0, ' ', 'r', 0, 0};
    unsigned int radix;

    for (radix=2; radix <= 62; radix++) {
        formatW.radix = radix;

        /*
         * Well-known digit strings.
         */

        /* 10 = radix */
        formatW.flags = 0;
        formatW.minDigits = 0;
        value = radix;
        sprintf(buf, "%dr10", radix);
        READ_EXPECTED_INT(value, buf, &formatR);
        WRITE_EXPECTED_INT(value, buf, &formatW);
        formatW.flags = COATL_NUMWRITE_PLUS;
        sprintf(buf, "+%dr10", radix);
        READ_EXPECTED_INT(value, buf, &formatR);
        WRITE_EXPECTED_INT(value, buf, &formatW);
        sprintf(buf, "-%dr10", radix);
        READ_EXPECTED_INT(-value, buf, &formatR);

        formatW.flags = 0;
        formatW.minDigits = 10;
        value = radix;
        sprintf(buf, "%dr0000000010", radix);
        READ_EXPECTED_INT(value, buf, &formatR);
        WRITE_EXPECTED_INT(value, buf, &formatW);
        formatW.flags = COATL_NUMWRITE_PLUS;
        sprintf(buf, "+%dr0000000010", radix);
        READ_EXPECTED_INT(value, buf, &formatR);
        WRITE_EXPECTED_INT(value, buf, &formatW);
        sprintf(buf, "-%dr0000000010", radix);
        READ_EXPECTED_INT(-value, buf, &formatR);

        /* 101 = radix*radix + 1 */
        formatW.flags = 0;
        formatW.minDigits = 0;
        value = radix*radix+1;
        sprintf(buf, "%dr101", radix);
        READ_EXPECTED_INT(value, buf, &formatR);
        WRITE_EXPECTED_INT(value, buf, &formatW);
        formatW.flags = COATL_NUMWRITE_PLUS;
        sprintf(buf, "+%dr101", radix);
        READ_EXPECTED_INT(value, buf, &formatR);
        WRITE_EXPECTED_INT(value, buf, &formatW);
        sprintf(buf, "-%dr101", radix);
        READ_EXPECTED_INT(-value, buf, &formatR);

        formatW.flags = 0;
        formatW.minDigits = 10;
        value = radix*radix+1;
        sprintf(buf, "%dr0000000101", radix);
        WRITE_EXPECTED_INT(value, buf, &formatW);
        READ_EXPECTED_INT(value, buf, &formatR);
        formatW.flags = COATL_NUMWRITE_PLUS;
        sprintf(buf, "+%dr0000000101", radix);
        WRITE_EXPECTED_INT(value, buf, &formatW);
        READ_EXPECTED_INT(value, buf, &formatR);
        sprintf(buf, "-%dr0000000101", radix);
        READ_EXPECTED_INT(-value, buf, &formatR);

        /* radix-1 = highest digit */
        formatW.flags = 0;
        formatW.minDigits = 0;
        value = radix-1;
        sprintf(buf, "%dr%c", radix, digits[value]);
        READ_EXPECTED_INT(value, buf, &formatR);
        WRITE_EXPECTED_INT(value, buf, &formatW);
        formatW.flags = COATL_NUMWRITE_PLUS;
        sprintf(buf, "+%dr%c", radix, digits[value]);
        READ_EXPECTED_INT(value, buf, &formatR);
        WRITE_EXPECTED_INT(value, buf, &formatW);
        sprintf(buf, "-%dr%c", radix, digits[value]);
        READ_EXPECTED_INT(-value, buf, &formatR);
        if (radix <= 36) {
            formatW.flags = COATL_NUMWRITE_L;
            formatW.minDigits = 0;
            value = radix-1;
            sprintf(buf, "%dr%c", radix, digitsL[value]);
            READ_EXPECTED_INT(value, buf, &formatR);
            WRITE_EXPECTED_INT(value, buf, &formatW);
            formatW.flags = COATL_NUMWRITE_L|COATL_NUMWRITE_PLUS;
            sprintf(buf, "+%dr%c", radix, digitsL[value]);
            WRITE_EXPECTED_INT(value, buf, &formatW);
            READ_EXPECTED_INT(value, buf, &formatR);
            sprintf(buf, "-%dr%c", radix, digitsL[value]);
            READ_EXPECTED_INT(-value, buf, &formatR);
        }
    }
}


/*
 *---------------------------------------------------------------------------
 *
 * testFloat --
 *
 *---------------------------------------------------------------------------
 */

PICOTEST_SUITE(testFloat,
    testFloatPredefined, testFloatPrintf
)

#define READ_EXPECTED_FLOAT(expected, value, format, epsilon) { \
    Col_Word w; \
    Col_RopeIterator begin, end; \
    size_t len = strlen(value); \
    Col_RopeIterString(begin, COL_UCS1, value, len); \
    Col_RopeIterSet(end, begin); Col_RopeIterForward(end, len); \
    ASSERT(Coatl_ReadFloatWord(begin, end, (format), COATL_FLOATREAD_NATIVE, &w)); \
    ASSERT(Col_FloatWordValue(w) - (expected) <= (epsilon), "value=%s", value); \
    ASSERT(Col_RopeIterCompare(begin, end) == 0, "value=%s,begin index=%u", value, Col_RopeIterIndex(begin)); \
}
#define WRITE_EXPECTED_FLOAT(value, expected, format, max) { \
    Col_Word number = Col_NewFloatWord(value); \
    Col_Word strbuf = Col_NewStringBuffer(0, COL_UCS1); \
    Col_RopeIterator it; \
    size_t len = Coatl_WriteFloatWord(strbuf, number, format); \
    \
    ASSERT(len == (size_t) strlen(expected), "value=%g,length=%u", value, len); \
    for (Col_RopeIterFirst(it, Col_StringBufferFreeze(strbuf)); \
            !Col_RopeIterEnd(it) && Col_RopeIterIndex(it) < max; Col_RopeIterNext(it)) { \
        ASSERT(Col_RopeIterAt(it) == (Col_Char) expected[Col_RopeIterIndex(it)], "value=%g,index=%u", value, Col_RopeIterIndex(it)); \
    } \
}

PICOTEST_CASE(testFloatPredefined, testNumber) {
    double value;
    char buf[100];

    value = 0;
    sprintf(buf, "0");
    READ_EXPECTED_FLOAT(value, buf, COATL_NUMREAD_DEFAULT, 0);
    WRITE_EXPECTED_FLOAT(value, buf, COATL_NUMWRITE_DEFAULT, SIZE_MAX);

    value = 0;
    sprintf(buf, "0");
    READ_EXPECTED_FLOAT(value, buf, COATL_FLOATREAD_C, 0);
    WRITE_EXPECTED_FLOAT(value, buf, COATL_NUMWRITE_C16, SIZE_MAX);

    value = 1000;
    sprintf(buf, "1e3");
    READ_EXPECTED_FLOAT(value, buf, COATL_NUMREAD_DEFAULT, 0);
    WRITE_EXPECTED_FLOAT(value, buf, COATL_NUMWRITE_DEFAULT, SIZE_MAX);
    sprintf(buf, "1e+3");
    READ_EXPECTED_FLOAT(value, buf, COATL_NUMREAD_DEFAULT, 0);
    sprintf(buf, "1e+03");
    READ_EXPECTED_FLOAT(value, buf, COATL_NUMREAD_DEFAULT, 0);

    value = 0x1000;
    sprintf(buf, "0x1p12");
    READ_EXPECTED_FLOAT(value, buf, COATL_FLOATREAD_C, 0);
    WRITE_EXPECTED_FLOAT(value, buf, COATL_NUMWRITE_C16, SIZE_MAX);
    sprintf(buf, "0x1p+12");
    READ_EXPECTED_FLOAT(value, buf, COATL_FLOATREAD_C, 0);
    sprintf(buf, "0x01p+012");
    READ_EXPECTED_FLOAT(value, buf, COATL_FLOATREAD_C, 0);

    value = 0.125;
    sprintf(buf, "1.25e-1");
    READ_EXPECTED_FLOAT(value, buf, COATL_NUMREAD_DEFAULT, 0);
    WRITE_EXPECTED_FLOAT(value, buf, COATL_NUMWRITE_DEFAULT, SIZE_MAX);
    sprintf(buf, "01.25e-01");
    READ_EXPECTED_FLOAT(value, buf, COATL_NUMREAD_DEFAULT, 0);

    value = 0.125; /* = 1.0/8 = 2.0/16 = 16r2@-1 = 0x2p-4*/
    sprintf(buf, "0x2p-4");
    READ_EXPECTED_FLOAT(value, buf, COATL_FLOATREAD_C, 0);
    WRITE_EXPECTED_FLOAT(value, buf, COATL_NUMWRITE_C16, SIZE_MAX);
    sprintf(buf, "0x02p-04");
    READ_EXPECTED_FLOAT(value, buf, COATL_FLOATREAD_C, 0);

    value = 1.0/0x1000;
    sprintf(buf, "0x1p-12");
    READ_EXPECTED_FLOAT(value, buf, COATL_FLOATREAD_C, 0);
    WRITE_EXPECTED_FLOAT(value, buf, COATL_NUMWRITE_C16, SIZE_MAX);
    sprintf(buf, "0x01p-012");
    READ_EXPECTED_FLOAT(value, buf, COATL_FLOATREAD_C, 0);
}

PICOTEST_CASE(testFloatPrintf, testNumber) {
    static double values[] = {
        123456789e-23, 123456789e-22, 123456789e-21, 123456789e-20, 
        123456789e-19, 123456789e-18, 123456789e-17, 123456789e-16, 
        123456789e-15, 123456789e-14, 123456789e-13, 123456789e-12, 
        123456789e-15, 123456789e-14, 123456789e-13, 123456789e-12, 
        123456789e-11, 123456789e-10, 123456789e-9,  123456789e-8, 
        123456789e-7,  123456789e-6,  123456789e-5,  123456789e-4, 
        123456789e-3,  123456789e-2,  123456789e-1,  123456789e0, 
        123456789e1,   123456789e2,   123456789e3,   123456789e4, 
        123456789e5,   123456789e6,   123456789e7,   123456789e8, 
        123456789e9,   123456789e10,  123456789e11,  123456789e12, 
        123456789e13,  123456789e14,  123456789e15,  123456789e16,
        999999999999999e-27, 999999999999999e-26, 999999999999999e-25, 999999999999999e-24, 
        999999999999999e-23, 999999999999999e-22, 999999999999999e-21, 999999999999999e-20, 
        999999999999999e-19, 999999999999999e-18, 999999999999999e-17, 999999999999999e-16, 
        999999999999999e-15, 999999999999999e-14, 999999999999999e-13, 999999999999999e-12, 
        999999999999999e-11, 999999999999999e-10, 999999999999999e-9,  999999999999999e-8, 
        999999999999999e-7,  999999999999999e-6,  999999999999999e-5,  999999999999999e-4, 
        999999999999999e-3,  999999999999999e-2,  999999999999999e-1,  999999999999999e0, 
        999999999999999e1,   999999999999999e2,   999999999999999e3,   999999999999999e4, 
        999999999999999e5,   999999999999999e6,   999999999999999e7,   999999999999999e8, 
        999999999999999e9,   999999999999999e10,  999999999999999e11,  999999999999999e12, 
        999999999999999e13,  999999999999999e14,  999999999999999e15,  999999999999999e16,
    };
#   define EXPWIDTH 2
    char buf[100], buf2[10];
    Coatl_NumWriteFormat formatE = {COATL_NUMWRITE_EXP_PLUS, 10, 0, ' ', COL_CHAR_INVALID, 0, 0, 1, 0,        0, 0,        EXPWIDTH, LONG_MAX, LONG_MIN, '.', 1,         'e'};
    Coatl_NumWriteFormat formatF = {0,                       10, 0, ' ', COL_CHAR_INVALID, 0, 0, 1, SIZE_MAX, 0, 0,        EXPWIDTH, LONG_MIN, LONG_MAX, '.', ULONG_MAX, 'e'};
    Coatl_NumWriteFormat formatG = {COATL_NUMWRITE_EXP_PLUS, 10, 0, ' ', COL_CHAR_INVALID, 0, 0, 1, 0,        0, SIZE_MAX, EXPWIDTH, -3,       0,        '.', 1,         'e'};
    size_t i, precision;
    char *point;

    for (i=0; i < sizeof(values)/sizeof(*values); i++) {
        for (precision=0; precision < DBL_DIG; precision++) {
            /* %e format */
            formatE.maxDigitsSigd = precision+1;
            formatE.minDigitsFrac = formatE.maxDigitsFrac = precision;
            sprintf(buf2, "%%.%ue", precision);
            sprintf(buf, buf2, values[i]);
            WRITE_EXPECTED_FLOAT(values[i], buf, &formatE, SIZE_MAX);
            READ_EXPECTED_FLOAT(strtod(buf, NULL), buf, COATL_FLOATREAD_C, 0);

            /* %f format */
            formatF.minDigitsFrac = formatF.maxDigitsFrac = precision;
            sprintf(buf2, "%%.%uf", precision);
            sprintf(buf, buf2, values[i]);
            if (((point = strchr(buf, '.')) ? point-buf+precision : strlen(buf)) > DBL_DIG) {
                /* Cases with fixed-point rounding issues. Note that CoATL does
                * a better job than stdlib. */
                //fprintf(stderr, "skip %u %u %s\n", i, precision, buf);
                WRITE_EXPECTED_FLOAT(values[i], buf, &formatF, 8);
            } else {
                WRITE_EXPECTED_FLOAT(values[i], buf, &formatF, SIZE_MAX);
            }
            READ_EXPECTED_FLOAT(strtod(buf, NULL), buf, COATL_FLOATREAD_C, 0);

            /* %g format */
            formatG.maxDigitsSigd = (precision ? precision : 1);
            formatG.maxFixed = formatG.maxDigitsSigd;
            sprintf(buf2, "%%.%ug", precision);
            sprintf(buf, buf2, values[i]);
            WRITE_EXPECTED_FLOAT(values[i], buf, &formatG, SIZE_MAX);
            READ_EXPECTED_FLOAT(strtod(buf, NULL), buf, COATL_FLOATREAD_C, 0);
        }
    }
}
