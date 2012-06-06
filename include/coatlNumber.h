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
#endif /* INTPTR_MAX != INTMAX_MAX */


/****************************************************************************
 * Group: Large Integer Word Predicates
 *
 * Declaration:
 *	<Coatl_WordIsLargeInt>
 ****************************************************************************/

#if INTPTR_MAX != INTMAX_MAX
EXTERN int		Coatl_WordIsLargeInt(Col_Word word);
#else
#   define Coatl_WordIsLargeInt	(Col_WordType(word) & COL_INT)
#endif /* INTPTR_MAX != INTMAX_MAX */


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
#endif /* INTPTR_MAX != INTMAX_MAX */

#endif /* _COATL_NUMBER */
