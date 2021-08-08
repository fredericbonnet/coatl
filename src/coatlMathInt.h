/**
 * @file coatlMathInt.h
 *
 * This header file defines the mathematical operation internals of CoATL.
 *
 * @see coatlMath.c
 * @see coatlMath.h
 *
 * @beginprivate @cond PRIVATE
 */

#ifndef _COATL_MATH_INT
#define _COATL_MATH_INT


/*
===========================================================================*//*!
\internal \addtogroup math Mathematical Operations
\{*//*==========================================================================
*/

/***************************************************************************//*!
 * \name Mathematical Exceptions
 ***************************************************************************\{*/

/**
 * Type checking macro for numbers.
 *
 * @param word  Checked word.
 *
 * @typecheck{COATL_ERROR_NUMBER,word}
 * @hideinitializer
 */
#define TYPECHECK_NUMBER(word) \
    COL_DEBUGCHECK( \
               Col_WordType(word) == COL_INT \
            || Col_WordType(word) == COL_FLOAT \
            || Coatl_WordIsMpInt(word) \
            || Coatl_WordIsMpFloat(word), \
            COL_TYPECHECK, CoatlDomain, COATL_ERROR_NUMBER, (word))

/* End of Mathematical Exceptions *//*!\}*/

/* End of Mathematical Operations *//*!\}*/

#endif /* _COATL_MATH_INT */
/*! @endcond @endprivate */