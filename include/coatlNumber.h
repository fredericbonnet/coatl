/*
 * Header: coatlNumber.h
 *
 *	This header file defines the number handling facility of CoATL.
 */

#ifndef _COATL_NUMBER
#define _COATL_NUMBER

#include <limits.h>


/*
================================================================================
Section: Large Integer Words
================================================================================
*/

/****************************************************************************
 * Group: Large Integer Word Creation
 *
 * Declaration:
 *	<Coatl_NewLargeIntWord>
 ****************************************************************************/

#if INTPTR_MAX != INTMAX_MAX
EXTERN Col_Word		Coatl_NewLargeIntWord(intmax_t value);
#else
#   define Coatl_NewLargeIntWord	Col_NewIntWord
#endif

/****************************************************************************
 * Group: Large Integer Word Accessors
 *
 * Declaration:
 *	<Coatl_LargeIntWordValue>
 ****************************************************************************/

#if INTPTR_MAX != INTMAX_MAX
EXTERN intmax_t		Coatl_LargeIntWordValue(Col_Word word);
#else
#   define Coatl_LargeIntWordValue	Col_IntWordValue
#endif

#endif /* _COATL_NUMBER */
