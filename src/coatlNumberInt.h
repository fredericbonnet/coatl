/**
 * @file coatlNumberInt.h
 *
 * This header file defines the number handling internals of CoATL.
 *
 * @see coatlNumber.c
 * @see coatlNumber.h
 *
 * @beginprivate @cond PRIVATE
 */

#ifndef _COATL_NUMBER_INT
#define _COATL_NUMBER_INT

#include <mpir.h>


/*
===========================================================================*//*!
\internal \addtogroup mp_int_words Multiple Precision Integer Words
\{*//*==========================================================================
*/

/***************************************************************************//*!
 * \name Multiple Precision Integer Word Creation
 ***************************************************************************\{*/

Col_Word                NewMpIntWord(mpz_t **valuePtr);

/* End of Multiple Precision Integer Word Creation *//*!\}*/

/* End of Multiple Precision Integer Words *//*!\}*/


/*
===========================================================================*//*!
\internal \addtogroup mp_float_words Multiple Precision Floating Point Words
\{*//*==========================================================================
*/

/***************************************************************************//*!
 * \name Multiple Precision Floating Point Word Creation
 ***************************************************************************\{*/

Col_Word                NewMpFloatWord(mpf_t **valuePtr);

/* End of Multiple Precision Floating Point Word Creation *//*!\}*/

/* End of Multiple Precision Floating Point Words *//*!\}*/


/*
===========================================================================*//*!
\internal \addtogroup number_io Number Input/Output
\{*//*==========================================================================
*/

int                     ParseUInt(Col_RopeIterator begin, Col_RopeIterator end,
                            size_t min, size_t max, unsigned int radix, 
                            const Col_Char *ignored);
int                     ReadUInt(Col_RopeIterator begin, Col_RopeIterator end,
                            unsigned int radix, const Col_Char *ignored, 
                            uintptr_t *valuePtr);
void                    WriteUInt(Col_Word strbuf, uintptr_t value,
                            unsigned int radix);

/* End of Number Input/Output *//*!\}*/

#endif /* _COATL_NUMBER_INT */
/*! @endcond @endprivate */
