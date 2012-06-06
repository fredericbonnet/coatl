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
Internal Section: Number Input
================================================================================
*/

int			ParseUInt(Col_RopeIterator begin, Col_RopeIterator end,
			    size_t min, size_t max, unsigned int base, 
			    Col_Char *ignore);
int			ReadUInt(Col_RopeIterator begin, Col_RopeIterator end,
			    unsigned int base, Col_Char *ignore, 
			    uintmax_t *valuePtr);
Col_Word		ReadIntWord(Col_RopeIterator begin, 
			    Col_RopeIterator end, unsigned int base, 
			    Col_Char *ignore);
Col_Word		ReadFloatWord(Col_RopeIterator begin, 
			    Col_RopeIterator end, unsigned int base, 
			    Col_Char *ignore);


/*
================================================================================
Internal Section: Number Output
================================================================================
*/

void			WriteUInt(Col_Word strbuf, uintmax_t value,
			    unsigned int base);
void			WriteIntWord(Col_Word strbuf, Col_Word value,
			    unsigned int base);
void			WriteFloatWord(Col_Word strbuf, Col_Word value,
			    unsigned int base);

#endif /* _COATL_NUMBER_INT */
