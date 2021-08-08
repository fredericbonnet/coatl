/**
 * @file coatl.c
 *
 * This file implements the error handling functions of CoATL.
 *
 * @see coatl.h
 */

#include "../include/coatl.h"


/*
===========================================================================*//*!
\weakgroup error Error Handling & Debugging
\{*//*==========================================================================
*/

/** @beginprivate @cond PRIVATE */

/**
 * Domain for CoATL error codes. Defines a message string for each code.
 *
 * @see **Col_ErrorCode**
 */
const char * const CoatlDomain[] = {
    "%s(%d) : assertion failed! (%s)",          // COATL_ERROR_ASSERTION (file, line, expression)
    "%x is not a regexp",                       // COATL_ERROR_REGEXP (word)
    "%x is not a number",                       // COATL_ERROR_NUMBER (word)
};

/** @endcond @endprivate */

/**
 * Get the domain for CoATL error codes.
 *
 * @return The domain.
 *
 * @see **Col_Error**
 */
Col_ErrorDomain
Coatl_GetErrorDomain()
{
    return CoatlDomain;
}

/* End of Error Handling & Debugging *//*!\}*/
