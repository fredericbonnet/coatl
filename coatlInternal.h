/*
 * Internal Header: coatlInternal.h
 *
 *	This header file defines internal structures and macros.
 */

#ifndef _COATL_INTERNAL
#define _COATL_INTERNAL

#ifdef _DEBUG
#   define DO_TRACE
#   define REQUIRE(x) {if (!(x)) Col_Error(COL_FATAL, CoatlDomain, COATL_ERROR_ASSERTION, __FILE__, __LINE__, #x);}
#   define ASSERT(x) REQUIRE(x)
#else
#   define REQUIRE(x) (x)
#   define ASSERT(x)
#endif

/*---------------------------------------------------------------------------
 * Internal Constant: REGEXP_USE_ITERATORS
 *
 *	When defined, the regexp package uses iterators instead of character 
 *	arrays.
 *---------------------------------------------------------------------------*/

#define REGEXP_USE_ITERATORS

/*
 * Remaining definitions.
 */

extern const char * const CoatlDomain[];

#endif /* _COATL_INTERNAL */
