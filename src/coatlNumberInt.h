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
Internal Section: Number Input/Output

Declarations:
	<ParseUInt>, <ReadUInt>, <WriteUInt>
================================================================================
*/

int			ParseUInt(Col_RopeIterator begin, Col_RopeIterator end,
			    size_t min, size_t max, unsigned int radix, 
			    const Col_Char *ignored);
int			ReadUInt(Col_RopeIterator begin, Col_RopeIterator end,
			    unsigned int radix, const Col_Char *ignored, 
			    uintmax_t *valuePtr);
void			WriteUInt(Col_Word strbuf, uintmax_t value,
			    unsigned int radix);

#endif /* _COATL_NUMBER_INT */
