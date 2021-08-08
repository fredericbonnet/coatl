/**
 * @file coatlMath.c
 *
 * This file implements the mathematical functions of CoATL.
 *
 * @see coatlMath.h
 */

#include "../include/coatl.h"
#include "coatlInternal.h"

#include "coatlMathInt.h"
#include "coatlNumberInt.h"

#include <mpir.h>

/*
 * Prototypes for functions used only in this file.
 */

/*! \cond IGNORE */
static Col_Word         NewIntWord(mpz_t value);
static Col_Word         NewFloatWord(mpf_t value);
typedef void (IntOp2)(mpz_t rop, mpz_t op1, mpz_t op2);
typedef void (FloatOp2)(mpf_t rop, mpf_t op1, mpf_t op2);
static Col_Word         NumberOp(IntOp2 *intOp, FloatOp2 *floatOp,
                            Col_Word number1, Col_Word number2);
static Col_Word         FloatOp(FloatOp2 *floatOp, Col_Word number1, 
                            Col_Word number2);
/*! \endcond *//* IGNORE */

/*
===========================================================================*//*!
\weakgroup math Mathematical Operations
\{*//*==========================================================================
*/

/**
 * Compare two numbers.
 *
 * @retval 0    if both numbers are identical.
 * @retval <0   if first number is less than second number.
 * @retval >0   if first number is greater than second number.
 */
int
Coatl_CompareNumbers(
    Col_Word number1,   /*!< First operand. */
    Col_Word number2)   /*!< Second operand. */
{
    int result = 0;

    /*
     * Check preconditions.
     */

    /*! @typecheck{COATL_ERROR_NUMBER,number1} */
    TYPECHECK_NUMBER(number1) return 1;

    /*! @typecheck{COATL_ERROR_NUMBER,number2} */
    TYPECHECK_NUMBER(number2) return -1;

    if (number1 == number2) return 0;

    if (Col_WordType(number1) == COL_INT) {
        intptr_t op1 = Col_IntWordValue(number1);
        if (Col_WordType(number2) == COL_INT) {
            intptr_t op2 = Col_IntWordValue(number2);
            result =      op1 == op2 ? 0
                        : op1 < op2 ? -1
                        : 1;
        } else if (Col_WordType(number2) == COL_FLOAT) {
            double op2 = Col_FloatWordValue(number2);
            result =      op1 == op2 ? 0
                        : op1 < op2 ? -1
                        : 1;
        } else if (Coatl_WordIsMpInt(number2)) {
            mpz_t *pop2;
            Col_CustomWordInfo(number2, (void *)&pop2);
            result = -mpz_cmp_si(*pop2, op1);
        } else if (Coatl_WordIsMpFloat(number2)) {
            mpf_t *pop2;
            Col_CustomWordInfo(number2, (void *)&pop2);
            result = -mpf_cmp_si(*pop2, op1);
        }
    } else if (Col_WordType(number1) == COL_FLOAT) {
        double op1 = Col_FloatWordValue(number1);
        if (Col_WordType(number2) == COL_INT) {
            intptr_t op2 = Col_IntWordValue(number2);
            result =      op1 == op2 ? 0
                        : op1 < op2 ? -1
                        : 1;
        } else if (Col_WordType(number2) == COL_FLOAT) {
            double op2 = Col_FloatWordValue(number2);
            result =      op1 == op2 ? 0
                        : op1 < op2 ? -1
                        : 1;
        } else if (Coatl_WordIsMpInt(number2)) {
            mpz_t *pop2;
            Col_CustomWordInfo(number2, (void *)&pop2);
            result = -mpz_cmp_d(*pop2, op1);
        } else if (Coatl_WordIsMpFloat(number2)) {
            mpf_t *pop2;
            Col_CustomWordInfo(number2, (void *)&pop2);
            result = -mpf_cmp_d(*pop2, op1);
        }
    } else if (Coatl_WordIsMpInt(number1)) {
        mpz_t *pop1;
        Col_CustomWordInfo(number1, (void *)&pop1);
        if (Col_WordType(number2) == COL_INT) {
            intptr_t op2 = Col_IntWordValue(number2);
            result = mpz_cmp_si(*pop1, op2);
        } else if (Col_WordType(number2) == COL_FLOAT) {
            double op2 = Col_FloatWordValue(number2);
            result = mpz_cmp_d(*pop1, op2);
        } else if (Coatl_WordIsMpInt(number2)) {
            mpz_t *pop2;
            Col_CustomWordInfo(number2, (void *)&pop2);
            result = mpz_cmp(*pop1, *pop2);
        } else if (Coatl_WordIsMpFloat(number2)) {
            mpf_t op1, *pop2;
            mpf_init(op1);
            mpf_set_z(op1, *pop1);
            Col_CustomWordInfo(number2, (void *)&pop2);
            result = -mpf_cmp(*pop2, op1);
            mpf_clear(op1);
        }
    } else if (Coatl_WordIsMpFloat(number1)) {
        mpf_t *pop1;
        Col_CustomWordInfo(number1, (void *)&pop1);
        if (Col_WordType(number2) == COL_INT) {
            intptr_t op2 = Col_IntWordValue(number2);
            result = mpf_cmp_si(*pop1, op2);
        } else if (Col_WordType(number2) == COL_FLOAT) {
            double op2 = Col_FloatWordValue(number2);
            result = mpf_cmp_d(*pop1, op2);
        } else if (Coatl_WordIsMpInt(number2)) {
            mpz_t *pop2;
            mpf_t op2;
            Col_CustomWordInfo(number2, (void *)&pop2);
            mpf_init(op2);
            mpf_set_z(op2, *pop2);
            result = mpf_cmp(*pop1, op2);
            mpf_clear(op2);
        } else if (Coatl_WordIsMpFloat(number2)) {
            mpf_t *pop2;
            Col_CustomWordInfo(number2, (void *)&pop2);
            result = mpf_cmp(*pop1, *pop2);
        }
    }
    
    return result;
}

/** @beginprivate @cond PRIVATE */

/**
 * Create a new integer word fitting the given value.
 *
 * @return A new number word holding the given value. May be a Colibri integer
 * word, or a CoATL multiple precision integer word.
 *
 * @return The new integer word.
 * 
 * @see Col_NewIntWord
 * @see NewMpIntWord
 */
static Col_Word
NewIntWord(
    mpz_t value)    /*!< Integer value of the word to create. */
{
    Col_Word result;
    if (mpz_fits_slong_p(value)) {
        result = Col_NewIntWord(mpz_get_si(value));
    } else {
        mpz_t *data;
        result = NewMpIntWord(&data);
        mpz_init_set(*data, value);
    }
    return result;
}

/**
 * Create a new floating point word fitting the given value.
 *
 * @return A new number word holding the given value. May be a Colibri floating
 * point word, or a CoATL multiple precision floating point word.
 *
 * @return The new floating point word.
 * 
 * @see Col_NewFloatWord
 * @see NewMpFloatWord
 */
static Col_Word
NewFloatWord(
    mpf_t value)
{
    Col_Word result;
    double d = mpf_get_d(value);
    if (mpf_cmp_d(value, d) == 0) {
        result = Col_NewFloatWord(d);
    } else {
        mpf_t *data;
        result = NewMpFloatWord(&data);
        mpf_init_set(*data, value);
    }
    return result;
}

/**
 * Execute an operation on two numbers.
 *
 * @return A new number word holding the result of the operation. May be a 
 *      Colibri integer or floating point word, or a CoATL multiple precision 
 *      integer or float word.
 */
static Col_Word
NumberOp(
    IntOp2 *intOp,              /*!< Integer operation. */
    FloatOp2 *floatOp,          /*!< Floating point operation. */
    Col_Word number1,           /*!< First operand. */
    Col_Word number2)           /*!< Second operand. */
{
    Col_Word result = WORD_NIL;
    if (Col_WordType(number1) == COL_INT) {
        if (Col_WordType(number2) == COL_INT) {
            mpz_t op1, op2;
            mpz_init_set_si(op1, Col_IntWordValue(number1));
            mpz_init_set_si(op2, Col_IntWordValue(number2));
            intOp(op1, op1, op2);
            result = NewIntWord(op1);
            mpz_clear(op1);
            mpz_clear(op2);
        } else if (Col_WordType(number2) == COL_FLOAT) {
            mpf_t op1, op2;
            mpf_init_set_si(op1, Col_IntWordValue(number1));
            mpf_init_set_d(op2, Col_FloatWordValue(number2));
            floatOp(op1, op1, op2);
            result = NewFloatWord(op1);
            mpf_clear(op1);
            mpf_clear(op2);
        } else if (Coatl_WordIsMpInt(number2)) {
            mpz_t op1, *pop2;
            mpz_init_set_si(op1, Col_IntWordValue(number1));
            Col_CustomWordInfo(number2, (void *)&pop2);
            intOp(op1, op1, *pop2);
            result = NewIntWord(op1);
            mpz_clear(op1);
        } else if (Coatl_WordIsMpFloat(number2)) {
            mpf_t op1, *pop2;
            mpf_init_set_si(op1, Col_IntWordValue(number1));
            Col_CustomWordInfo(number2, (void *)&pop2);
            floatOp(op1, op1, *pop2);
            result = NewFloatWord(op1);
            mpf_clear(op1);
        }
    } else if (Col_WordType(number1) == COL_FLOAT) {
        if (Col_WordType(number2) == COL_INT) {
            mpf_t op1, op2;
            mpf_init_set_d(op1, Col_FloatWordValue(number1));
            mpf_init_set_si(op2, Col_IntWordValue(number2));
            floatOp(op1, op1, op2);
            result = NewFloatWord(op1);
            mpf_clear(op1);
            mpf_clear(op2);
        } else if (Col_WordType(number2) == COL_FLOAT) {
            mpf_t op1, op2;
            mpf_init_set_d(op1, Col_FloatWordValue(number1));
            mpf_init_set_d(op2, Col_FloatWordValue(number2));
            floatOp(op1, op1, op2);
            result = NewFloatWord(op1);
            mpf_clear(op1);
            mpf_clear(op2);
        } else if (Coatl_WordIsMpInt(number2)) {
            mpz_t *pop2;
            mpf_t op1, op2;
            mpf_init_set_d(op1, Col_FloatWordValue(number1));
            Col_CustomWordInfo(number2, (void *)&pop2);
            mpf_init(op2);
            mpf_set_z(op2, *pop2);
            floatOp(op1, op1, op2);
            result = NewFloatWord(op1);
            mpf_clear(op1);
            mpf_clear(op2);
        } else if (Coatl_WordIsMpFloat(number2)) {
            mpf_t op1, *pop2;
            mpf_init_set_d(op1, Col_FloatWordValue(number1));
            Col_CustomWordInfo(number2, (void *)&pop2);
            floatOp(op1, op1, *pop2);
            result = NewFloatWord(op1);
            mpf_clear(op1);
        }
    } else if (Coatl_WordIsMpInt(number1)) {
        if (Col_WordType(number2) == COL_INT) {
            mpz_t *pop1, op2, rop;
            Col_CustomWordInfo(number1, (void *)&pop1);
            mpz_init_set_si(op2, Col_IntWordValue(number2));
            mpz_init(rop);
            intOp(rop, *pop1, op2);
            result = NewIntWord(rop);
            mpz_clear(op2);
            mpz_clear(rop);
        } else if (Col_WordType(number2) == COL_FLOAT) {
            mpz_t *pop1;
            mpf_t op1, op2;
            Col_CustomWordInfo(number1, (void *)&pop1);
            mpf_init(op1);
            mpf_set_z(op1, *pop1);
            mpf_init_set_d(op2, Col_FloatWordValue(number2));
            floatOp(op1, op1, op2);
            result = NewFloatWord(op1);
            mpf_clear(op1);
            mpf_clear(op2);
        } else if (Coatl_WordIsMpInt(number2)) {
            mpz_t *pop1, *pop2, rop;
            Col_CustomWordInfo(number1, (void *)&pop1);
            Col_CustomWordInfo(number2, (void *)&pop2);
            mpz_init(rop);
            intOp(rop, *pop1, *pop2);
            result = NewIntWord(rop);
            mpz_clear(rop);
        } else if (Coatl_WordIsMpFloat(number2)) {
            mpz_t *pop1;
            mpf_t op1, *pop2;
            Col_CustomWordInfo(number1, (void *)&pop1);
            mpf_init(op1);
            mpf_set_z(op1, *pop1);
            Col_CustomWordInfo(number2, (void *)&pop2);
            floatOp(op1, op1, *pop2);
            result = NewFloatWord(op1);
            mpf_clear(op1);
        }
    } else if (Coatl_WordIsMpFloat(number1)) {
        if (Col_WordType(number2) == COL_INT) {
            mpf_t *pop1, op2, rop;
            Col_CustomWordInfo(number1, (void *)&pop1);
            mpf_init_set_si(op2, Col_IntWordValue(number2));
            mpf_init(rop);
            floatOp(rop, *pop1, op2);
            result = NewFloatWord(rop);
            mpf_clear(op2);
            mpf_clear(rop);
        } else if (Col_WordType(number2) == COL_FLOAT) {
            mpf_t *pop1, op2, rop;
            Col_CustomWordInfo(number1, (void *)&pop1);
            mpf_init_set_d(op2, Col_FloatWordValue(number2));
            mpf_init(rop);
            floatOp(rop, *pop1, op2);
            result = NewFloatWord(rop);
            mpf_clear(op2);
            mpf_clear(rop);
        } else if (Coatl_WordIsMpInt(number2)) {
            mpz_t *pop2;
            mpf_t *pop1, op2, rop;
            Col_CustomWordInfo(number1, (void *)&pop1);
            Col_CustomWordInfo(number2, (void *)&pop2);
            mpf_init(op2);
            mpf_set_z(op2, *pop2);
            mpf_init(rop);
            floatOp(rop, *pop1, op2);
            result = NewFloatWord(rop);
            mpf_clear(op2);
            mpf_clear(rop);
        } else if (Coatl_WordIsMpFloat(number2)) {
            mpf_t *pop1, *pop2, rop;
            Col_CustomWordInfo(number1, (void *)&pop1);
            Col_CustomWordInfo(number2, (void *)&pop2);
            mpf_init(rop);
            floatOp(rop, *pop1, *pop2);
            result = NewFloatWord(rop);
            mpf_clear(rop);
        }
    }

    return result;
}

/**
 * Execute a floating point operation on two numbers.
 *
 * @return A new number word holding the result of the operation. May be a
 *      Colibri floating point word, or a CoATL multiple precision floating
 *      point word.
 */
static Col_Word
FloatOp(
    FloatOp2 *floatOp,          /*!< Floating point operation. */
    Col_Word number1,           /*!< First operand. */
    Col_Word number2)           /*!< Second operand. */
{
    Col_Word result = WORD_NIL;
    if (Col_WordType(number1) == COL_INT) {
        mpf_t op1;
        mpf_init_set_si(op1, Col_IntWordValue(number1));
        if (Col_WordType(number2) == COL_INT) {
            mpf_t op2;
            mpf_init_set_si(op2, Col_IntWordValue(number2));
            floatOp(op1, op1, op2);
            result = NewFloatWord(op1);
            mpf_clear(op2);
        } else if (Col_WordType(number2) == COL_FLOAT) {
            mpf_t op2;
            mpf_init_set_d(op2, Col_FloatWordValue(number2));
            floatOp(op1, op1, op2);
            result = NewFloatWord(op1);
            mpf_clear(op2);
        } else if (Coatl_WordIsMpInt(number2)) {
            mpz_t *pop2;
            mpf_t op2;
            Col_CustomWordInfo(number2, (void *)&pop2);
            mpf_init(op2);
            mpf_set_z(op2, *pop2);
            floatOp(op1, op1, op2);
            result = NewFloatWord(op1);
            mpf_clear(op2);
        } else if (Coatl_WordIsMpFloat(number2)) {
            mpf_t *pop2;
            Col_CustomWordInfo(number2, (void *)&pop2);
            floatOp(op1, op1, *pop2);
            result = NewFloatWord(op1);
        }
        mpf_clear(op1);
    } else if (Col_WordType(number1) == COL_FLOAT) {
        mpf_t op1;
        mpf_init_set_d(op1, Col_FloatWordValue(number1));
        if (Col_WordType(number2) == COL_INT) {
            mpf_t op2;
            mpf_init_set_si(op2, Col_IntWordValue(number2));
            floatOp(op1, op1, op2);
            result = NewFloatWord(op1);
            mpf_clear(op2);
        } else if (Col_WordType(number2) == COL_FLOAT) {
            mpf_t op2;
            mpf_init_set_d(op2, Col_FloatWordValue(number2));
            floatOp(op1, op1, op2);
            result = NewFloatWord(op1);
            mpf_clear(op2);
        } else if (Coatl_WordIsMpInt(number2)) {
            mpz_t *pop2;
            mpf_t op2;
            Col_CustomWordInfo(number2, (void *)&pop2);
            mpf_init(op2);
            mpf_set_z(op2, *pop2);
            floatOp(op1, op1, op2);
            result = NewFloatWord(op1);
            mpf_clear(op2);
        } else if (Coatl_WordIsMpFloat(number2)) {
            mpf_t *pop2;
            Col_CustomWordInfo(number2, (void *)&pop2);
            floatOp(op1, op1, *pop2);
            result = NewFloatWord(op1);
        }
        mpf_clear(op1);
    } else if (Coatl_WordIsMpInt(number1)) {
        mpz_t *pop1;
        mpf_t op1;
        Col_CustomWordInfo(number1, (void *)&pop1);
        mpf_init(op1);
        mpf_set_z(op1, *pop1);
        if (Col_WordType(number2) == COL_INT) {
            mpf_t op2;
            mpf_init_set_si(op2, Col_IntWordValue(number2));
            floatOp(op1, op1, op2);
            result = NewFloatWord(op1);
            mpf_clear(op2);
        } else if (Col_WordType(number2) == COL_FLOAT) {
            mpf_t op2;
            mpf_init_set_d(op2, Col_FloatWordValue(number2));
            floatOp(op1, op1, op2);
            result = NewFloatWord(op1);
            mpf_clear(op2);
        } else if (Coatl_WordIsMpInt(number2)) {
            mpz_t *pop2;
            mpf_t op2;
            Col_CustomWordInfo(number2, (void *)&pop2);
            mpf_init(op2);
            mpf_set_z(op2, *pop2);
            floatOp(op1, op1, op2);
            result = NewFloatWord(op1);
            mpf_clear(op2);
        } else if (Coatl_WordIsMpFloat(number2)) {
            mpf_t *pop2;
            Col_CustomWordInfo(number2, (void *)&pop2);
            floatOp(op1, op1, *pop2);
            result = NewFloatWord(op1);
        }
        mpf_clear(op1);
    } else if (Coatl_WordIsMpFloat(number1)) {
        mpf_t *pop1, rop;
        Col_CustomWordInfo(number1, (void *)&pop1);
        mpf_init(rop);
        if (Col_WordType(number2) == COL_INT) {
            mpf_t op2;
            mpf_init_set_si(op2, Col_IntWordValue(number2));
            floatOp(rop, *pop1, op2);
            result = NewFloatWord(rop);
            mpf_clear(op2);
        } else if (Col_WordType(number2) == COL_FLOAT) {
            mpf_t op2;
            mpf_init_set_d(op2, Col_FloatWordValue(number2));
            floatOp(rop, *pop1, op2);
            result = NewFloatWord(rop);
            mpf_clear(op2);
        } else if (Coatl_WordIsMpInt(number2)) {
            mpz_t *pop2;
            mpf_t op2;
            Col_CustomWordInfo(number2, (void *)&pop2);
            mpf_init(op2);
            mpf_set_z(op2, *pop2);
            floatOp(rop, *pop1, op2);
            result = NewFloatWord(rop);
            mpf_clear(op2);
        } else if (Coatl_WordIsMpFloat(number2)) {
            mpf_t *pop2;
            Col_CustomWordInfo(number2, (void *)&pop2);
            floatOp(rop, *pop1, *pop2);
            result = NewFloatWord(rop);
        }
        mpf_clear(rop);
    }

    return result;
}

/** @endcond @endprivate */

/**
 * Add two numbers.
 *
 * @return A new number word holding the result of the operation. May be a 
 *      Colibri integer or floating point word, or a CoATL multiple precision 
 *      integer or float word.
 */
Col_Word
Coatl_AddNumbers(
    Col_Word number1,   /*!< First operand. */
    Col_Word number2)   /*!< Second operand. */
{
    Col_Word result = WORD_NIL;

    /*
     * Check preconditions.
     */

    /*! @typecheck{COATL_ERROR_NUMBER,number1} */
    TYPECHECK_NUMBER(number1) return WORD_NIL;

    /*! @typecheck{COATL_ERROR_NUMBER,number2} */
    TYPECHECK_NUMBER(number2) return WORD_NIL;

    return NumberOp(mpz_add, mpf_add, number1, number2);
}

/**
 * Subtract two numbers.
 *
 * @return A new number word holding the result of the operation. May be a 
 *      Colibri integer or floating point word, or a CoATL multiple precision 
 *      integer or float word.
 */
Col_Word
Coatl_SubtractNumbers(
    Col_Word number1,   /*!< First operand. */
    Col_Word number2)   /*!< Second operand. */
{
    Col_Word result = WORD_NIL;

    /*
     * Check preconditions.
     */

    /*! @typecheck{COATL_ERROR_NUMBER,number1} */
    TYPECHECK_NUMBER(number1) return WORD_NIL;

    /*! @typecheck{COATL_ERROR_NUMBER,number2} */
    TYPECHECK_NUMBER(number2) return WORD_NIL;

    return NumberOp(mpz_sub, mpf_sub, number1, number2);
}

/**
 * Multiply two numbers.
 *
 * @return A new number word holding the result of the operation. May be a 
 *      Colibri integer or floating point word, or a CoATL multiple precision 
 *      integer or float word.
 */
Col_Word
Coatl_MultiplyNumbers(
    Col_Word number1,   /*!< First operand. */
    Col_Word number2)   /*!< Second operand. */
{
    Col_Word result = WORD_NIL;

    /*
     * Check preconditions.
     */

    /*! @typecheck{COATL_ERROR_NUMBER,number1} */
    TYPECHECK_NUMBER(number1) return WORD_NIL;

    /*! @typecheck{COATL_ERROR_NUMBER,number2} */
    TYPECHECK_NUMBER(number2) return WORD_NIL;

    return NumberOp(mpz_mul, mpf_mul, number1, number2);
}

/**
 * Divide two numbers.
 *
 * @return A new number word holding the result of the operation. May be a 
 *      Colibri integer or floating point word, or a CoATL multiple precision 
 *      integer or float word.
 */
Col_Word
Coatl_DivideNumbers(
    Col_Word number1,   /*!< First operand. */
    Col_Word number2)   /*!< Second operand. */
{
    Col_Word result = WORD_NIL;

    /*
     * Check preconditions.
     */

    /*! @typecheck{COATL_ERROR_NUMBER,number1} */
    TYPECHECK_NUMBER(number1) return WORD_NIL;

    /*! @typecheck{COATL_ERROR_NUMBER,number2} */
    TYPECHECK_NUMBER(number2) return WORD_NIL;

    return FloatOp(mpf_div, number1, number2);
}

/* End of Mathematical Operations *//*!\}*/
