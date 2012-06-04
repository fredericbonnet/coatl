/*
 * File: coatl.c
 *
 *	TODO
 */

#include "include/coatl.h"

/*
================================================================================
Internal Section: Error Handling
================================================================================
*/

/*---------------------------------------------------------------------------
 * Internal Variable: CoatlDomain
 *
 *	Domain for CoATL error codes. Defines a message string for each code.
 *
 * See also:
 *	<Coatl_ErrorCode>
 *---------------------------------------------------------------------------*/

const char * const CoatlDomain[] = {
    "%s(%d) : assertion failed! (%s)",		// COATL_ERROR_ASSERTION (file, line, expression)
    "%x is not a large integer",		// COATL_ERROR_LARGEINT (word)
    "%x is not a regexp",			// COATL_ERROR_REGEXP (word)
};

/*---------------------------------------------------------------------------
 * Function: Coatl_GetErrorDomain
 *
 *	Get the domain for CoATL error codes.
 *
 * Result:
 *	The domain.
 *
 * See also: 
 *	<Col_Error>
 *---------------------------------------------------------------------------*/

Col_ErrorDomain
Coatl_GetErrorDomain()
{
    return CoatlDomain;
}
