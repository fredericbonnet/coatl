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
    Col_WordData redata, sdata;
    const Col_Char *rec, *sc;
    regmatch_t match[1];
    int result;

    re = Col_NormalizeRope(re, COL_UCS4, 0, 1);
    Col_GetWordInfo(re, &redata);
    rec = (const Col_Char *) redata.string.data;
    s = Col_NormalizeRope(s, COL_UCS4, 0, 1);
    Col_GetWordInfo(s, &sdata);
    sc = (const Col_Char *) sdata.string.data;

    CoatlReCompile(&r, rec, Col_RopeLength(re), REG_ADVANCED);

    result = CoatlReExec(&r, sc, Col_RopeLength(s), NULL, sizeof(match)/sizeof(*match), match, 0);

    CoatlReFree(&r);

    return (result == REG_OKAY);
}
