/**
 * @file coatlMath.h
 *
 * This header file defines the mathematical functions of CoATL.
 */

#ifndef _COATL_MATH
#define _COATL_MATH

/*
===========================================================================*//*!
\defgroup math Mathematical Operations
\{*//*==========================================================================
*/

EXTERN int              Coatl_CompareNumbers(Col_Word number1, 
                            Col_Word number2);
EXTERN Col_Word         Coatl_AddNumbers(Col_Word number1, Col_Word number2);
EXTERN Col_Word         Coatl_SubtractNumbers(Col_Word number1, 
                            Col_Word number2);
EXTERN Col_Word         Coatl_MultiplyNumbers(Col_Word number1, 
                            Col_Word number2);
EXTERN Col_Word         Coatl_DivideNumbers(Col_Word number1, 
                            Col_Word number2);

/* End of Mathematical Operations *//*!\}*/

#endif /* _COATL_MATH */
