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
