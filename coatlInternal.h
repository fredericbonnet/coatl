/*
 * Internal Header: coatlInternal.h
 *
 *	This header file defines internal structures and macros.
 */

#ifndef _COATL_INTERNAL
#define _COATL_INTERNAL

#ifdef _DEBUG
#   define DO_TRACE
#   define ASSERT(x) {if (!(x)) Col_Error(COL_FATAL, "%s(%d) : assertion failed! (%s)", __FILE__, __LINE__, #x);}
#else
#   define ASSERT(x)
#endif

#endif /* _COATL_INTERNAL */
