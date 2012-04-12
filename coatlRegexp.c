/*
 * File: coatlRegexp.c
 *
 *	This file implements the regular expression facility of CoATL.
 *
 *	The code is based on Henry Spencer's regexp library found in Tcl.
 *
 * See also:
 *	<coatlRegex.h>
 */

#include "include/coatl.h"

#include "re/regex.h"

int 
Coatl_TestRegexp(
    Col_Word re, 
    Col_Word s)
{
    regex_t r;
    regmatch_t match[1];
    int result;

#if 1
    Col_RopeIterator it;

    Col_RopeIterFirst(re, &it); 
    CoatlReCompile(&r, it, Col_RopeLength(re), REG_ADVANCED);

    Col_RopeIterFirst(s, &it); 
    result = CoatlReExec(&r, it, Col_RopeLength(s), NULL, sizeof(match)/sizeof(*match), match, 0);
#else
    Col_WordData redata, sdata;
    const Col_Char4 *rec, *sc;

    re = Col_NormalizeRope(re, COL_UCS4, 0, 1);
    Col_GetWordInfo(re, &redata);
    rec = (const Col_Char4 *) redata.string.data;
    s = Col_NormalizeRope(s, COL_UCS4, 0, 1);
    Col_GetWordInfo(s, &sdata);
    sc = (const Col_Char4 *) sdata.string.data;

    CoatlReCompile(&r, rec, Col_RopeLength(re), REG_ADVANCED);

    result = CoatlReExec(&r, sc, Col_RopeLength(s), NULL, sizeof(match)/sizeof(*match), match, 0);
#endif

    CoatlReFree(&r);

    return (result == REG_OKAY);
}
