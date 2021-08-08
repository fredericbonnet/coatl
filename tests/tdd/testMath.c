#include <colibri.h>
#include <coatl.h>
#include <picotest.h>

/*
 * Failure test cases (must be defined before test hooks)
 */

#include "failureFixture.h"

/* Coatl_CompareNumbers */
PICOTEST_CASE(compareNumbers_typeCheck_number1, failureFixture, context) {
    EXPECT_FAILURE(context, COL_TYPECHECK, Coatl_GetErrorDomain(),
                   COATL_ERROR_NUMBER);
    PICOTEST_ASSERT(Coatl_CompareNumbers(WORD_NIL, Col_NewIntWord(0)) == 1);
}
PICOTEST_CASE(compareNumbers_typeCheck_number2, failureFixture, context) {
    EXPECT_FAILURE(context, COL_TYPECHECK, Coatl_GetErrorDomain(),
                   COATL_ERROR_NUMBER);
    PICOTEST_ASSERT(Coatl_CompareNumbers(Col_NewIntWord(0), WORD_NIL) == -1);
}

/*
 * Mathematical operations
 */

#include "hooks.h"
#include "colibriFixture.h"

PICOTEST_SUITE(testMath, testCompareNumbers, testAddNumbers,
               testSubtractNumbers, testMultiplyNumbers, testDivideNumbers);

PICOTEST_SUITE(testCompareNumbers, testCompareNumbersTypeChecks,
               testCompareNumbersIdentity, testCompareInt, testCompareFloat,
               testCompareMpInt, testCompareMpFloat);

PICOTEST_CASE(testCompareNumbersTypeChecks, colibriFixture) {
    PICOTEST_ASSERT(compareNumbers_typeCheck_number1(NULL) == 1);
    PICOTEST_ASSERT(compareNumbers_typeCheck_number2(NULL) == 1);
};

#define INT(number) Col_NewIntWord(number)
#define FLOAT(number) Col_NewFloatWord(number)
#define MPINT(number)                                                          \
    Coatl_RopeToIntWord(Col_NewRopeFromString(#number), COATL_INTREAD_C,       \
                        COATL_INTREAD_MP)
#define MPFLOAT(number)                                                        \
    Coatl_RopeToFloatWord(Col_NewRopeFromString(#number), COATL_FLOATREAD_C,   \
                          COATL_FLOATREAD_MP)

PICOTEST_CASE(testCompareNumbersIdentity, colibriFixture) {
    Col_Word one = INT(1);
    PICOTEST_ASSERT(Coatl_CompareNumbers(one, one) == 0);
}

PICOTEST_SUITE(testCompareInt, testCompareIntWithInt, testCompareIntToFloat,
               testCompareIntWithMpInt, testCompareIntWithMpFloat);
PICOTEST_CASE(testCompareIntWithInt, colibriFixture) {
    PICOTEST_VERIFY(Coatl_CompareNumbers(INT(1), INT(1)) == 0);
    PICOTEST_VERIFY(Coatl_CompareNumbers(INT(1), INT(-1)) > 0);
    PICOTEST_VERIFY(Coatl_CompareNumbers(INT(-1), INT(1)) < 0);
    PICOTEST_VERIFY(Coatl_CompareNumbers(INT(1), INT(2)) < 0);
    PICOTEST_VERIFY(Coatl_CompareNumbers(INT(2), INT(1)) > 0);
}
PICOTEST_CASE(testCompareIntToFloat, colibriFixture) {
    PICOTEST_VERIFY(Coatl_CompareNumbers(INT(1), FLOAT(1)) == 0);
    PICOTEST_VERIFY(Coatl_CompareNumbers(INT(1), FLOAT(-1)) > 0);
    PICOTEST_VERIFY(Coatl_CompareNumbers(INT(-1), FLOAT(1)) < 0);
    PICOTEST_VERIFY(Coatl_CompareNumbers(INT(1), FLOAT(2)) < 0);
    PICOTEST_VERIFY(Coatl_CompareNumbers(INT(2), FLOAT(1)) > 0);
}
PICOTEST_CASE(testCompareIntWithMpInt, colibriFixture) {
    PICOTEST_VERIFY(Coatl_CompareNumbers(INT(1), MPINT(1)) == 0);
    PICOTEST_VERIFY(Coatl_CompareNumbers(INT(1), MPINT(-1)) > 0);
    PICOTEST_VERIFY(Coatl_CompareNumbers(INT(-1), MPINT(1)) < 0);
    PICOTEST_VERIFY(Coatl_CompareNumbers(INT(1), MPINT(2)) < 0);
    PICOTEST_VERIFY(Coatl_CompareNumbers(INT(2), MPINT(1)) > 0);
}
PICOTEST_CASE(testCompareIntWithMpFloat, colibriFixture) {
    PICOTEST_VERIFY(Coatl_CompareNumbers(INT(1), MPFLOAT(1)) == 0);
    PICOTEST_VERIFY(Coatl_CompareNumbers(INT(1), MPFLOAT(-1)) > 0);
    PICOTEST_VERIFY(Coatl_CompareNumbers(INT(-1), MPFLOAT(1)) < 0);
    PICOTEST_VERIFY(Coatl_CompareNumbers(INT(1), MPFLOAT(2)) < 0);
    PICOTEST_VERIFY(Coatl_CompareNumbers(INT(2), MPFLOAT(1)) > 0);
}

PICOTEST_SUITE(testCompareFloat, testCompareFloatWithInt,
               testCompareFloatWithFloat, testCompareFloatWithMpInt,
               testCompareFloatWithMpFloat);
PICOTEST_CASE(testCompareFloatWithInt, colibriFixture) {
    PICOTEST_VERIFY(Coatl_CompareNumbers(FLOAT(1), INT(1)) == 0);
    PICOTEST_VERIFY(Coatl_CompareNumbers(FLOAT(1), INT(-1)) > 0);
    PICOTEST_VERIFY(Coatl_CompareNumbers(FLOAT(-1), INT(1)) < 0);
    PICOTEST_VERIFY(Coatl_CompareNumbers(FLOAT(1), INT(2)) < 0);
    PICOTEST_VERIFY(Coatl_CompareNumbers(FLOAT(2), INT(1)) > 0);
}
PICOTEST_CASE(testCompareFloatWithFloat, colibriFixture) {
    PICOTEST_VERIFY(Coatl_CompareNumbers(FLOAT(1), FLOAT(1)) == 0);
    PICOTEST_VERIFY(Coatl_CompareNumbers(FLOAT(1), FLOAT(-1)) > 0);
    PICOTEST_VERIFY(Coatl_CompareNumbers(FLOAT(-1), FLOAT(1)) < 0);
    PICOTEST_VERIFY(Coatl_CompareNumbers(FLOAT(1), FLOAT(2)) < 0);
    PICOTEST_VERIFY(Coatl_CompareNumbers(FLOAT(2), FLOAT(1)) > 0);
}
PICOTEST_CASE(testCompareFloatWithMpInt, colibriFixture) {
    PICOTEST_VERIFY(Coatl_CompareNumbers(FLOAT(1), MPINT(1)) == 0);
    PICOTEST_VERIFY(Coatl_CompareNumbers(FLOAT(1), MPINT(-1)) > 0);
    PICOTEST_VERIFY(Coatl_CompareNumbers(FLOAT(-1), MPINT(1)) < 0);
    PICOTEST_VERIFY(Coatl_CompareNumbers(FLOAT(1), MPINT(2)) < 0);
    PICOTEST_VERIFY(Coatl_CompareNumbers(FLOAT(2), MPINT(1)) > 0);
}
PICOTEST_CASE(testCompareFloatWithMpFloat, colibriFixture) {
    PICOTEST_VERIFY(Coatl_CompareNumbers(FLOAT(1), MPFLOAT(1)) == 0);
    PICOTEST_VERIFY(Coatl_CompareNumbers(FLOAT(1), MPFLOAT(-1)) > 0);
    PICOTEST_VERIFY(Coatl_CompareNumbers(FLOAT(-1), MPFLOAT(1)) < 0);
    PICOTEST_VERIFY(Coatl_CompareNumbers(FLOAT(1), MPFLOAT(2)) < 0);
    PICOTEST_VERIFY(Coatl_CompareNumbers(FLOAT(2), MPFLOAT(1)) > 0);
}

PICOTEST_SUITE(testCompareMpInt, testCompareMpIntWithInt,
               testCompareMpIntWithFloat, testCompareMpIntWithMpInt,
               testCompareMpIntWithMpFloat);
PICOTEST_CASE(testCompareMpIntWithInt, colibriFixture) {
    PICOTEST_VERIFY(Coatl_CompareNumbers(MPINT(1), INT(1)) == 0);
    PICOTEST_VERIFY(Coatl_CompareNumbers(MPINT(1), INT(-1)) > 0);
    PICOTEST_VERIFY(Coatl_CompareNumbers(MPINT(-1), INT(1)) < 0);
    PICOTEST_VERIFY(Coatl_CompareNumbers(MPINT(1), INT(2)) < 0);
    PICOTEST_VERIFY(Coatl_CompareNumbers(MPINT(2), INT(1)) > 0);
}
PICOTEST_CASE(testCompareMpIntWithFloat, colibriFixture) {
    PICOTEST_VERIFY(Coatl_CompareNumbers(MPINT(1), FLOAT(1)) == 0);
    PICOTEST_VERIFY(Coatl_CompareNumbers(MPINT(1), FLOAT(-1)) > 0);
    PICOTEST_VERIFY(Coatl_CompareNumbers(MPINT(-1), FLOAT(1)) < 0);
    PICOTEST_VERIFY(Coatl_CompareNumbers(MPINT(1), FLOAT(2)) < 0);
    PICOTEST_VERIFY(Coatl_CompareNumbers(MPINT(2), FLOAT(1)) > 0);
}
PICOTEST_CASE(testCompareMpIntWithMpInt, colibriFixture) {
    PICOTEST_VERIFY(Coatl_CompareNumbers(MPINT(1), MPINT(1)) == 0);
    PICOTEST_VERIFY(Coatl_CompareNumbers(MPINT(1), MPINT(-1)) > 0);
    PICOTEST_VERIFY(Coatl_CompareNumbers(MPINT(-1), MPINT(1)) < 0);
    PICOTEST_VERIFY(Coatl_CompareNumbers(MPINT(1), MPINT(2)) < 0);
    PICOTEST_VERIFY(Coatl_CompareNumbers(MPINT(2), MPINT(1)) > 0);
}
PICOTEST_CASE(testCompareMpIntWithMpFloat, colibriFixture) {
    PICOTEST_VERIFY(Coatl_CompareNumbers(MPINT(1), MPFLOAT(1)) == 0);
    PICOTEST_VERIFY(Coatl_CompareNumbers(MPINT(1), MPFLOAT(-1)) > 0);
    PICOTEST_VERIFY(Coatl_CompareNumbers(MPINT(-1), MPFLOAT(1)) < 0);
    PICOTEST_VERIFY(Coatl_CompareNumbers(MPINT(1), MPFLOAT(2)) < 0);
    PICOTEST_VERIFY(Coatl_CompareNumbers(MPINT(2), MPFLOAT(1)) > 0);
}

PICOTEST_SUITE(testCompareMpFloat, testCompareMpFloatWithInt,
               testCompareMpFloatWithFloat, testCompareMpFloatWithMpInt,
               testCompareMpFloatWithMpFloat);
PICOTEST_CASE(testCompareMpFloatWithInt, colibriFixture) {
    PICOTEST_VERIFY(Coatl_CompareNumbers(MPFLOAT(1), INT(1)) == 0);
    PICOTEST_VERIFY(Coatl_CompareNumbers(MPFLOAT(1), INT(-1)) > 0);
    PICOTEST_VERIFY(Coatl_CompareNumbers(MPFLOAT(-1), INT(1)) < 0);
    PICOTEST_VERIFY(Coatl_CompareNumbers(MPFLOAT(1), INT(2)) < 0);
    PICOTEST_VERIFY(Coatl_CompareNumbers(MPFLOAT(2), INT(1)) > 0);
}
PICOTEST_CASE(testCompareMpFloatWithFloat, colibriFixture) {
    PICOTEST_VERIFY(Coatl_CompareNumbers(MPFLOAT(1), FLOAT(1)) == 0);
    PICOTEST_VERIFY(Coatl_CompareNumbers(MPFLOAT(1), FLOAT(-1)) > 0);
    PICOTEST_VERIFY(Coatl_CompareNumbers(MPFLOAT(-1), FLOAT(1)) < 0);
    PICOTEST_VERIFY(Coatl_CompareNumbers(MPFLOAT(1), FLOAT(2)) < 0);
    PICOTEST_VERIFY(Coatl_CompareNumbers(MPFLOAT(2), FLOAT(1)) > 0);
}
PICOTEST_CASE(testCompareMpFloatWithMpInt, colibriFixture) {
    PICOTEST_VERIFY(Coatl_CompareNumbers(MPFLOAT(1), MPINT(1)) == 0);
    PICOTEST_VERIFY(Coatl_CompareNumbers(MPFLOAT(1), MPINT(-1)) > 0);
    PICOTEST_VERIFY(Coatl_CompareNumbers(MPFLOAT(-1), MPINT(1)) < 0);
    PICOTEST_VERIFY(Coatl_CompareNumbers(MPFLOAT(1), MPINT(2)) < 0);
    PICOTEST_VERIFY(Coatl_CompareNumbers(MPFLOAT(2), MPINT(1)) > 0);
}
PICOTEST_CASE(testCompareMpFloatWithMpFloat, colibriFixture) {
    PICOTEST_VERIFY(Coatl_CompareNumbers(MPFLOAT(1), MPFLOAT(1)) == 0);
    PICOTEST_VERIFY(Coatl_CompareNumbers(MPFLOAT(1), MPFLOAT(-1)) > 0);
    PICOTEST_VERIFY(Coatl_CompareNumbers(MPFLOAT(-1), MPFLOAT(1)) < 0);
    PICOTEST_VERIFY(Coatl_CompareNumbers(MPFLOAT(1), MPFLOAT(2)) < 0);
    PICOTEST_VERIFY(Coatl_CompareNumbers(MPFLOAT(2), MPFLOAT(1)) > 0);
}

PICOTEST_SUITE(testAddNumbers, testAddInt, testAddFloat, testAddMpInt,
               testAddMpFloat);

static void checkAddNumbers(Col_Word number1, Col_Word number2,
                            Col_Word result) {
    PICOTEST_VERIFY(
        Coatl_CompareNumbers(Coatl_AddNumbers(number1, number2), result) == 0);
}

PICOTEST_SUITE(testAddInt, testAddIntWithInt, testAddIntWithFloat,
               testAddIntWithMpInt, testAddIntWithMpFloat);
PICOTEST_CASE(testAddIntWithInt, colibriFixture) {
    checkAddNumbers(INT(1), INT(2), INT(3));
    checkAddNumbers(INT(0x7fffffffffffffff), INT(1), MPINT(0x8000000000000000));
}
PICOTEST_CASE(testAddIntWithFloat, colibriFixture) {
    checkAddNumbers(INT(1), FLOAT(2), FLOAT(3));
    checkAddNumbers(INT(0x1fffffffffffff), FLOAT(2), MPFLOAT(0x20000000000001));
}
PICOTEST_CASE(testAddIntWithMpInt, colibriFixture) {
    checkAddNumbers(INT(1), MPINT(2), INT(3));
    checkAddNumbers(INT(0x7fffffffffffffff), MPINT(1),
                    MPINT(0x8000000000000000));
}
PICOTEST_CASE(testAddIntWithMpFloat, colibriFixture) {
    checkAddNumbers(INT(1), MPFLOAT(2), FLOAT(3));
    checkAddNumbers(INT(0x1fffffffffffff), MPFLOAT(2),
                    MPFLOAT(0x20000000000001));
}

PICOTEST_SUITE(testAddFloat, testAddFloatWithInt, testAddFloatWithFloat,
               testAddFloatWithMpInt, testAddFloatWithMpFloat);
PICOTEST_CASE(testAddFloatWithInt, colibriFixture) {
    checkAddNumbers(FLOAT(1), INT(2), FLOAT(3));
    checkAddNumbers(FLOAT(0x1fffffffffffff), INT(2), MPFLOAT(0x20000000000001));
}
PICOTEST_CASE(testAddFloatWithFloat, colibriFixture) {
    checkAddNumbers(FLOAT(1), FLOAT(2), FLOAT(3));
    checkAddNumbers(FLOAT(0x1fffffffffffff), FLOAT(2),
                    MPFLOAT(0x20000000000001));
}
PICOTEST_CASE(testAddFloatWithMpInt, colibriFixture) {
    checkAddNumbers(FLOAT(1), MPINT(2), FLOAT(3));
    checkAddNumbers(FLOAT(0x1fffffffffffff), MPINT(2),
                    MPFLOAT(0x20000000000001));
}
PICOTEST_CASE(testAddFloatWithMpFloat, colibriFixture) {
    checkAddNumbers(FLOAT(1), MPFLOAT(2), FLOAT(3));
    checkAddNumbers(FLOAT(0x1fffffffffffff), MPFLOAT(2),
                    MPFLOAT(0x20000000000001));
}

PICOTEST_SUITE(testAddMpInt, testAddMpIntWithInt, testAddMpIntWithFloat,
               testAddMpIntWithMpInt, testAddMpIntWithMpFloat);
PICOTEST_CASE(testAddMpIntWithInt, colibriFixture) {
    checkAddNumbers(MPINT(1), INT(2), INT(3));
    checkAddNumbers(MPINT(0x7fffffffffffffff), INT(1),
                    MPINT(0x8000000000000000));
}
PICOTEST_CASE(testAddMpIntWithFloat, colibriFixture) {
    checkAddNumbers(MPINT(1), FLOAT(2), FLOAT(3));
    checkAddNumbers(MPINT(0x1fffffffffffff), FLOAT(2),
                    MPFLOAT(0x20000000000001));
}
PICOTEST_CASE(testAddMpIntWithMpInt, colibriFixture) {
    checkAddNumbers(MPINT(1), MPINT(2), INT(3));
    checkAddNumbers(MPINT(0x7fffffffffffffff), MPINT(1),
                    MPINT(0x8000000000000000));
}
PICOTEST_CASE(testAddMpIntWithMpFloat, colibriFixture) {
    checkAddNumbers(MPINT(1), MPFLOAT(2), FLOAT(3));
    checkAddNumbers(MPINT(0x1fffffffffffff), MPFLOAT(2),
                    MPFLOAT(0x20000000000001));
}

PICOTEST_SUITE(testAddMpFloat, testAddMpFloatWithInt, testAddMpFloatWithFloat,
               testAddMpFloatWithMpInt, testAddMpFloatWithMpFloat);
PICOTEST_CASE(testAddMpFloatWithInt, colibriFixture) {
    checkAddNumbers(MPFLOAT(1), INT(2), FLOAT(3));
    checkAddNumbers(MPFLOAT(0x7fffffffffffffff), INT(1),
                    MPFLOAT(0x8000000000000000));
}
PICOTEST_CASE(testAddMpFloatWithFloat, colibriFixture) {
    checkAddNumbers(MPFLOAT(1), FLOAT(2), FLOAT(3));
    checkAddNumbers(MPFLOAT(0x1fffffffffffff), FLOAT(2),
                    MPFLOAT(0x20000000000001));
}
PICOTEST_CASE(testAddMpFloatWithMpInt, colibriFixture) {
    checkAddNumbers(MPFLOAT(1), MPINT(2), FLOAT(3));
    checkAddNumbers(MPFLOAT(0x7fffffffffffffff), MPINT(1),
                    MPFLOAT(0x8000000000000000));
}
PICOTEST_CASE(testAddMpFloatWithMpFloat, colibriFixture) {
    checkAddNumbers(MPFLOAT(1), MPFLOAT(2), FLOAT(3));
    checkAddNumbers(MPFLOAT(0x1fffffffffffff), MPFLOAT(2),
                    MPFLOAT(0x20000000000001));
}

PICOTEST_SUITE(testSubtractNumbers, testSubtractInt, testSubtractFloat,
               testSubtractMpInt, testSubtractMpFloat);

static void checkSubtractNumbers(Col_Word number1, Col_Word number2,
                                 Col_Word result) {
    PICOTEST_VERIFY(Coatl_CompareNumbers(
                        Coatl_SubtractNumbers(number1, number2), result) == 0);
}

PICOTEST_SUITE(testSubtractInt, testSubtractIntWithInt,
               testSubtractIntWithFloat, testSubtractIntWithMpInt,
               testSubtractIntWithMpFloat);
PICOTEST_CASE(testSubtractIntWithInt, colibriFixture) {
    checkSubtractNumbers(INT(-1), INT(2), INT(-3));
    checkSubtractNumbers(INT(-0x7fffffffffffffff), INT(1),
                         MPINT(-0x8000000000000000));
}
PICOTEST_CASE(testSubtractIntWithFloat, colibriFixture) {
    checkSubtractNumbers(INT(-1), FLOAT(2), FLOAT(-3));
    checkSubtractNumbers(INT(-0x1fffffffffffff), FLOAT(2),
                         MPFLOAT(-0x20000000000001));
}
PICOTEST_CASE(testSubtractIntWithMpInt, colibriFixture) {
    checkSubtractNumbers(INT(-1), MPINT(2), INT(-3));
    checkSubtractNumbers(INT(-0x7fffffffffffffff), MPINT(1),
                         MPINT(-0x8000000000000000));
}
PICOTEST_CASE(testSubtractIntWithMpFloat, colibriFixture) {
    checkSubtractNumbers(INT(-1), MPFLOAT(2), FLOAT(-3));
    checkSubtractNumbers(INT(-0x1fffffffffffff), MPFLOAT(2),
                         MPFLOAT(-0x20000000000001));
}

PICOTEST_SUITE(testSubtractFloat, testSubtractFloatWithInt,
               testSubtractFloatWithFloat, testSubtractFloatWithMpInt,
               testSubtractFloatWithMpFloat);
PICOTEST_CASE(testSubtractFloatWithInt, colibriFixture) {
    checkSubtractNumbers(FLOAT(-1), INT(2), FLOAT(-3));
    checkSubtractNumbers(FLOAT(-0x1fffffffffffff), INT(2),
                         MPFLOAT(-0x20000000000001));
}
PICOTEST_CASE(testSubtractFloatWithFloat, colibriFixture) {
    checkSubtractNumbers(FLOAT(-1), FLOAT(2), FLOAT(-3));
    checkSubtractNumbers(FLOAT(-0x1fffffffffffff), FLOAT(2),
                         MPFLOAT(-0x20000000000001));
}
PICOTEST_CASE(testSubtractFloatWithMpInt, colibriFixture) {
    checkSubtractNumbers(FLOAT(-1), MPINT(2), FLOAT(-3));
    checkSubtractNumbers(FLOAT(-0x1fffffffffffff), MPINT(2),
                         MPFLOAT(-0x20000000000001));
}
PICOTEST_CASE(testSubtractFloatWithMpFloat, colibriFixture) {
    checkSubtractNumbers(FLOAT(-1), MPFLOAT(2), FLOAT(-3));
    checkSubtractNumbers(FLOAT(-0x1fffffffffffff), MPFLOAT(2),
                         MPFLOAT(-0x20000000000001));
}

PICOTEST_SUITE(testSubtractMpInt, testSubtractMpIntWithInt,
               testSubtractMpIntWithFloat, testSubtractMpIntWithMpInt,
               testSubtractMpIntWithMpFloat);
PICOTEST_CASE(testSubtractMpIntWithInt, colibriFixture) {
    checkSubtractNumbers(MPINT(-1), INT(2), INT(-3));
    checkSubtractNumbers(MPINT(-0x7fffffffffffffff), INT(1),
                         MPINT(-0x8000000000000000));
}
PICOTEST_CASE(testSubtractMpIntWithFloat, colibriFixture) {
    checkSubtractNumbers(MPINT(-1), FLOAT(2), FLOAT(-3));
    checkSubtractNumbers(MPINT(-0x1fffffffffffff), FLOAT(2),
                         MPFLOAT(-0x20000000000001));
}
PICOTEST_CASE(testSubtractMpIntWithMpInt, colibriFixture) {
    checkSubtractNumbers(MPINT(-1), MPINT(2), INT(-3));
    checkSubtractNumbers(MPINT(-0x7fffffffffffffff), MPINT(1),
                         MPINT(-0x8000000000000000));
}
PICOTEST_CASE(testSubtractMpIntWithMpFloat, colibriFixture) {
    checkSubtractNumbers(MPINT(-1), MPFLOAT(2), FLOAT(-3));
    checkSubtractNumbers(MPINT(-0x1fffffffffffff), MPFLOAT(2),
                         MPFLOAT(-0x20000000000001));
}

PICOTEST_SUITE(testSubtractMpFloat, testSubtractMpFloatWithInt,
               testSubtractMpFloatWithFloat, testSubtractMpFloatWithMpInt,
               testSubtractMpFloatWithMpFloat);
PICOTEST_CASE(testSubtractMpFloatWithInt, colibriFixture) {
    checkSubtractNumbers(MPFLOAT(-1), INT(2), FLOAT(-3));
    checkSubtractNumbers(MPFLOAT(-0x7fffffffffffffff), INT(1),
                         MPFLOAT(-0x8000000000000000));
}
PICOTEST_CASE(testSubtractMpFloatWithFloat, colibriFixture) {
    checkSubtractNumbers(MPFLOAT(-1), FLOAT(2), FLOAT(-3));
    checkSubtractNumbers(MPFLOAT(-0x1fffffffffffff), FLOAT(2),
                         MPFLOAT(-0x20000000000001));
}
PICOTEST_CASE(testSubtractMpFloatWithMpInt, colibriFixture) {
    checkSubtractNumbers(MPFLOAT(-1), MPINT(2), FLOAT(-3));
    checkSubtractNumbers(MPFLOAT(-0x7fffffffffffffff), MPINT(1),
                         MPFLOAT(-0x8000000000000000));
}
PICOTEST_CASE(testSubtractMpFloatWithMpFloat, colibriFixture) {
    checkSubtractNumbers(MPFLOAT(-1), MPFLOAT(2), FLOAT(-3));
    checkSubtractNumbers(MPFLOAT(-0x1fffffffffffff), MPFLOAT(2),
                         MPFLOAT(-0x20000000000001));
}

PICOTEST_SUITE(testMultiplyNumbers, testMultiplyInt, testMultiplyFloat,
               testMultiplyMpInt, testMultiplyMpFloat);

static void checkMultiplyNumbers(Col_Word number1, Col_Word number2,
                                 Col_Word result) {
    PICOTEST_VERIFY(Coatl_CompareNumbers(
                        Coatl_MultiplyNumbers(number1, number2), result) == 0);
}

PICOTEST_SUITE(testMultiplyInt, testMultiplyIntWithInt,
               testMultiplyIntWithFloat, testMultiplyIntWithMpInt,
               testMultiplyIntWithMpFloat);
PICOTEST_CASE(testMultiplyIntWithInt, colibriFixture) {
    checkMultiplyNumbers(INT(2), INT(3), INT(6));
    checkMultiplyNumbers(INT(0x4000000000000000), INT(2),
                         MPINT(0x8000000000000000));
}
PICOTEST_CASE(testMultiplyIntWithFloat, colibriFixture) {
    checkMultiplyNumbers(INT(2), FLOAT(3), FLOAT(6));
    checkMultiplyNumbers(INT(0x10000000000001), FLOAT(3),
                         MPFLOAT(0x30000000000003));
}
PICOTEST_CASE(testMultiplyIntWithMpInt, colibriFixture) {
    checkMultiplyNumbers(INT(2), MPINT(3), INT(6));
    checkMultiplyNumbers(INT(0x4000000000000000), MPINT(2),
                         MPINT(0x8000000000000000));
}
PICOTEST_CASE(testMultiplyIntWithMpFloat, colibriFixture) {
    checkMultiplyNumbers(INT(2), MPFLOAT(3), FLOAT(6));
    checkMultiplyNumbers(INT(0x10000000000001), MPFLOAT(3),
                         MPFLOAT(0x30000000000003));
}

PICOTEST_SUITE(testMultiplyFloat, testMultiplyFloatWithInt,
               testMultiplyFloatWithFloat, testMultiplyFloatWithMpInt,
               testMultiplyFloatWithMpFloat);
PICOTEST_CASE(testMultiplyFloatWithInt, colibriFixture) {
    checkMultiplyNumbers(FLOAT(2), INT(3), FLOAT(6));
    checkMultiplyNumbers(FLOAT(0x10000000000001), INT(3),
                         MPFLOAT(0x30000000000003));
}
PICOTEST_CASE(testMultiplyFloatWithFloat, colibriFixture) {
    checkMultiplyNumbers(FLOAT(2), FLOAT(3), FLOAT(6));
    checkMultiplyNumbers(FLOAT(0x10000000000001), FLOAT(3),
                         MPFLOAT(0x30000000000003));
}
PICOTEST_CASE(testMultiplyFloatWithMpInt, colibriFixture) {
    checkMultiplyNumbers(FLOAT(2), MPINT(3), FLOAT(6));
    checkMultiplyNumbers(FLOAT(0x10000000000001), MPINT(3),
                         MPFLOAT(0x30000000000003));
}
PICOTEST_CASE(testMultiplyFloatWithMpFloat, colibriFixture) {
    checkMultiplyNumbers(FLOAT(2), MPFLOAT(3), FLOAT(6));
    checkMultiplyNumbers(FLOAT(0x10000000000001), MPFLOAT(3),
                         MPFLOAT(0x30000000000003));
}

PICOTEST_SUITE(testMultiplyMpInt, testMultiplyMpIntWithInt,
               testMultiplyMpIntWithFloat, testMultiplyMpIntWithMpInt,
               testMultiplyMpIntWithMpFloat);
PICOTEST_CASE(testMultiplyMpIntWithInt, colibriFixture) {
    checkMultiplyNumbers(MPINT(2), INT(3), INT(6));
    checkMultiplyNumbers(MPINT(0x4000000000000000), INT(2),
                         MPINT(0x8000000000000000));
}
PICOTEST_CASE(testMultiplyMpIntWithFloat, colibriFixture) {
    checkMultiplyNumbers(MPINT(2), FLOAT(3), FLOAT(6));
    checkMultiplyNumbers(MPINT(0x10000000000001), FLOAT(3),
                         MPFLOAT(0x30000000000003));
}
PICOTEST_CASE(testMultiplyMpIntWithMpInt, colibriFixture) {
    checkMultiplyNumbers(MPINT(2), MPINT(3), INT(6));
    checkMultiplyNumbers(MPINT(0x4000000000000000), MPINT(2),
                         MPINT(0x8000000000000000));
}
PICOTEST_CASE(testMultiplyMpIntWithMpFloat, colibriFixture) {
    checkMultiplyNumbers(MPINT(2), MPFLOAT(3), FLOAT(6));
    checkMultiplyNumbers(MPINT(0x10000000000001), MPFLOAT(3),
                         MPFLOAT(0x30000000000003));
}

PICOTEST_SUITE(testMultiplyMpFloat, testMultiplyMpFloatWithInt,
               testMultiplyMpFloatWithFloat, testMultiplyMpFloatWithMpInt,
               testMultiplyMpFloatWithMpFloat);
PICOTEST_CASE(testMultiplyMpFloatWithInt, colibriFixture) {
    checkMultiplyNumbers(MPFLOAT(2), INT(3), FLOAT(6));
    checkMultiplyNumbers(MPFLOAT(0x10000000000001), INT(3),
                         MPFLOAT(0x30000000000003));
}
PICOTEST_CASE(testMultiplyMpFloatWithFloat, colibriFixture) {
    checkMultiplyNumbers(MPFLOAT(2), FLOAT(3), FLOAT(6));
    checkMultiplyNumbers(MPFLOAT(0x10000000000001), FLOAT(3),
                         MPFLOAT(0x30000000000003));
}
PICOTEST_CASE(testMultiplyMpFloatWithMpInt, colibriFixture) {
    checkMultiplyNumbers(MPFLOAT(2), MPINT(3), FLOAT(6));
    checkMultiplyNumbers(MPFLOAT(0x10000000000001), MPINT(3),
                         MPFLOAT(0x30000000000003));
}
PICOTEST_CASE(testMultiplyMpFloatWithMpFloat, colibriFixture) {
    checkMultiplyNumbers(MPFLOAT(2), MPFLOAT(3), FLOAT(6));
    checkMultiplyNumbers(MPFLOAT(0x10000000000001), MPFLOAT(3),
                         MPFLOAT(0x30000000000003));
}

PICOTEST_SUITE(testDivideNumbers, testDivideInt, testDivideFloat,
               testDivideMpInt, testDivideMpFloat);

static void checkDivideNumbers(Col_Word number1, Col_Word number2,
                               Col_Word result) {
    PICOTEST_VERIFY(Coatl_CompareNumbers(Coatl_DivideNumbers(number1, number2),
                                         result) == 0);
}

PICOTEST_SUITE(testDivideInt, testDivideIntWithInt, testDivideIntWithFloat,
               testDivideIntWithMpInt, testDivideIntWithMpFloat);
PICOTEST_CASE(testDivideIntWithInt, colibriFixture) {
    checkDivideNumbers(INT(6), INT(3), FLOAT(2));
    checkDivideNumbers(INT(0x4000000000000002), INT(2),
                       MPFLOAT(0x2000000000000001));
}
PICOTEST_CASE(testDivideIntWithFloat, colibriFixture) {
    checkDivideNumbers(INT(6), FLOAT(3), FLOAT(2));
    checkDivideNumbers(INT(0x4000000000000002), FLOAT(2),
                       MPFLOAT(0x2000000000000001));
}
PICOTEST_CASE(testDivideIntWithMpInt, colibriFixture) {
    checkDivideNumbers(INT(6), MPINT(3), FLOAT(2));
    checkDivideNumbers(INT(0x4000000000000002), MPINT(2),
                       MPFLOAT(0x2000000000000001));
}
PICOTEST_CASE(testDivideIntWithMpFloat, colibriFixture) {
    checkDivideNumbers(INT(6), MPFLOAT(3), FLOAT(2));
    checkDivideNumbers(INT(0x4000000000000002), MPFLOAT(2),
                       MPFLOAT(0x2000000000000001));
}

PICOTEST_SUITE(testDivideFloat, testDivideFloatWithInt,
               testDivideFloatWithFloat, testDivideFloatWithMpInt,
               testDivideFloatWithMpFloat);
PICOTEST_CASE(testDivideFloatWithInt, colibriFixture) {
    checkDivideNumbers(FLOAT(6), INT(3), FLOAT(2));
}
PICOTEST_CASE(testDivideFloatWithFloat, colibriFixture) {
    checkDivideNumbers(FLOAT(6), FLOAT(3), FLOAT(2));
}
PICOTEST_CASE(testDivideFloatWithMpInt, colibriFixture) {
    checkDivideNumbers(FLOAT(6), MPINT(3), FLOAT(2));
}
PICOTEST_CASE(testDivideFloatWithMpFloat, colibriFixture) {
    checkDivideNumbers(FLOAT(6), MPFLOAT(3), FLOAT(2));
}

PICOTEST_SUITE(testDivideMpInt, testDivideMpIntWithInt,
               testDivideMpIntWithFloat, testDivideMpIntWithMpInt,
               testDivideMpIntWithMpFloat);
PICOTEST_CASE(testDivideMpIntWithInt, colibriFixture) {
    checkDivideNumbers(MPINT(6), INT(3), FLOAT(2));
    checkDivideNumbers(MPINT(0x4000000000000002), INT(2),
                       MPFLOAT(0x2000000000000001));
}
PICOTEST_CASE(testDivideMpIntWithFloat, colibriFixture) {
    checkDivideNumbers(MPINT(6), FLOAT(3), FLOAT(2));
    checkDivideNumbers(MPINT(0x4000000000000002), FLOAT(2),
                       MPFLOAT(0x2000000000000001));
}
PICOTEST_CASE(testDivideMpIntWithMpInt, colibriFixture) {
    checkDivideNumbers(MPINT(6), MPINT(3), FLOAT(2));
    checkDivideNumbers(MPINT(0x4000000000000002), MPINT(2),
                       MPFLOAT(0x2000000000000001));
}
PICOTEST_CASE(testDivideMpIntWithMpFloat, colibriFixture) {
    checkDivideNumbers(MPINT(6), MPFLOAT(3), FLOAT(2));
    checkDivideNumbers(MPINT(0x4000000000000002), MPFLOAT(2),
                       MPFLOAT(0x2000000000000001));
}

PICOTEST_SUITE(testDivideMpFloat, testDivideMpFloatWithInt,
               testDivideMpFloatWithFloat, testDivideMpFloatWithMpInt,
               testDivideMpFloatWithMpFloat);
PICOTEST_CASE(testDivideMpFloatWithInt, colibriFixture) {
    checkDivideNumbers(MPFLOAT(6), INT(3), FLOAT(2));
    checkDivideNumbers(MPFLOAT(0x4000000000000002), INT(2),
                       MPFLOAT(0x2000000000000001));
}
PICOTEST_CASE(testDivideMpFloatWithFloat, colibriFixture) {
    checkDivideNumbers(MPFLOAT(6), FLOAT(3), FLOAT(2));
    checkDivideNumbers(MPFLOAT(0x4000000000000002), FLOAT(2),
                       MPFLOAT(0x2000000000000001));
}
PICOTEST_CASE(testDivideMpFloatWithMpInt, colibriFixture) {
    checkDivideNumbers(MPFLOAT(6), MPINT(3), FLOAT(2));
    checkDivideNumbers(MPFLOAT(0x4000000000000002), MPINT(2),
                       MPFLOAT(0x2000000000000001));
}
PICOTEST_CASE(testDivideMpFloatWithMpFloat, colibriFixture) {
    checkDivideNumbers(MPFLOAT(6), MPFLOAT(3), FLOAT(2));
    checkDivideNumbers(MPFLOAT(0x4000000000000002), MPFLOAT(2),
                       MPFLOAT(0x2000000000000001));
}
