/*
 * Internal Header: coatlNumberInt.h
 *
 *	This header file defines the number handling internals of CoATL.
 *
 * See also:
 *	<coatlNumber.c>, <coatlNumber.h>
 */

#ifndef _COATL_NUMBER_INT
#define _COATL_NUMBER_INT


/*
================================================================================
Internal Section: Number Parsing
================================================================================
*/

int			ParseInt(Col_RopeIterator begin, Col_RopeIterator end,
			    size_t min, size_t max, unsigned int base, 
			    Col_Char *ignore);
int			ScanInt(Col_RopeIterator begin, Col_RopeIterator end,
			    unsigned int base, Col_Char *ignore, 
			    uintmax_t *valuePtr);
Col_Word		ScanIntWord(Col_RopeIterator begin, 
			    Col_RopeIterator end, unsigned int base, 
			    Col_Char *ignore);
Col_Word		ScanFloatWord(Col_RopeIterator begin, 
			    Col_RopeIterator end, unsigned int base, 
			    Col_Char *ignore);

#endif /* _COATL_NUMBER_INT */
