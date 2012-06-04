/*
 * Internal Header: coatlParseInt.h
 *
 *	TODO
 */

#ifndef _COATL_PARSE_INT
#define _COATL_PARSE_INT


#define GETCHAR(c, begin, end, r) \
    { \
	if (Col_RopeIterCompare((begin), (end)) >= 0) {r;} \
	(c) = Col_RopeIterAt(begin); \
    }

#define NEXTCHAR(c, begin, end, r) \
    { \
	Col_RopeIterNext(begin); \
	GETCHAR((c), (begin), (end), r); \
    }


#endif /* _COATL_PARSE_INT */
