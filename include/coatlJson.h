/*
 * Header: coatlJson.h
 *
 *	This header file defines the JSON features of CoATL.
 */

#ifndef _COATL_JSON
#define _COATL_JSON

//TODO doc format


EXTERN int		Coatl_ParseJson(Col_RopeIterator begin, 
			    Col_RopeIterator end, Col_Word *dataPtr);

#endif /* _COATL_JSON */
