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
#include "coatlInternal.h"

#include "re/regex.h"

/*
 * Prototypes for functions used only in this file.
 */

static Col_CustomWordSizeProc RegexpSizeProc;
static Col_CustomWordFreeProc RegexpFreeProc;


/*
================================================================================
Section: Regular Expressions
================================================================================
*/

/*---------------------------------------------------------------------------
 * Internal Variable: regexpWordType
 *
 *	Custom word type holding a regex_t structure.
 *---------------------------------------------------------------------------*/

static Col_CustomWordType regexpWordType = {
    COL_CUSTOM,
    "regexp",
    RegexpSizeProc,
    RegexpFreeProc,
    NULL /* childrenProc */
};

/*---------------------------------------------------------------------------
 * Internal Function: RegexpSizeProc
 *
 *	Regexp word type size proc. Follows <Col_CustomWordSizeProc> signature.	
 *
 * Argument:
 *	word	- Custom word to get size for.
 *
 * Result:
 *	The custom word size in bytes.
 *
 * See also:
 *	<regexpWordType>
 *---------------------------------------------------------------------------*/

static size_t
RegexpSizeProc(
    Col_Word word)
{
    return sizeof(regex_t);
}

/*---------------------------------------------------------------------------
 * Internal Function: RegexpFreeProc
 *
 *	Regexp word type cleanup proc. Follows <Col_CustomWordFreeProc>
 *	signature.
 *
 * Argument:
 *	word	- Custom word to cleanup.
 *
 * Side effects:
 *	Calls regex_t cleanup procedure.
 *
 * See also: 
 *	<regexpWordType>
 *---------------------------------------------------------------------------*/

static void
RegexpFreeProc(
    Col_Word word)
{
    Col_WordData data;
    regex_t *re;

    Col_GetWordInfo(word, &data);
    ASSERT(data.custom.type == &regexpWordType);
    re = (regex_t *) data.custom.data;

    CoatlReFree(re);
}

/*---------------------------------------------------------------------------
 * Function: Coatl_RegexpCompile
 *
 *	Compile a regular expression for later execution.
 *
 * Arguments:
 *	string	- Regular expression to compile.
 *	flags	- Compilation flags (see <Regular Expression Flags>).
 *
 * Result:
 *	An error code (see <Regular Expression Error Codes>). Additionally:
 *
 *	rePtr	- Regular expression word if compilation was successful (i.e.
 *		  result is <COATL_REGEXP_OKAY>).
 *
 * Side effects:
 *	May allocate memory cells.
 *
 * See also:
 *	<Coatl_RegexpExec>
 *---------------------------------------------------------------------------*/

int
Coatl_RegexpCompile(
    Col_Word string, 
    int flags,
    Col_Word *rePtr)
{
    Col_RopeIterator it;
    int result;
    regex_t re;
    void *data;

#if 1
    Col_RopeIterFirst(string, &it); 
    result = CoatlReCompile(&re, it, Col_RopeIterLength(&it), flags);
#else
    {
    Col_WordData sdata;
    const Col_Char4 *s;

    string = Col_NormalizeRope(string, COL_UCS4, 0, 1);
    Col_GetWordInfo(string, &sdata);
    result = CoatlReCompile(&re, (const Col_Char4 *) sdata.string.data, 
	    Col_RopeLength(string), flags);
    }
#endif
    if (result == REG_OKAY) {
	*rePtr = Col_NewCustomWord(&regexpWordType, sizeof(re), &data);
	*(regex_t *) data = re;
    } else {
	*rePtr = WORD_NIL;
    }
    return result;
}

/*---------------------------------------------------------------------------
 * Function: Coatl_RegexpExec
 *
 *	Execute a previously compiled regular expression.
 *
 * Arguments:
 *	re	- Compiled regular expression (result of <Coatl_RegexpCompile>).
 *	string	- String to match against regular expression.
 *	flags	- Execution flags (see <Regular Expression Flags>).
 *
 * Result:
 *	An error code (see <Regular Expression Error Codes>).
 *
 * See also:
 *	<Coatl_RegexpCompile>
 *---------------------------------------------------------------------------*/

int
Coatl_RegexpExec(
    Col_Word re,
    Col_Word string,
    int flags)
{
    Col_WordData data;
    regex_t *rePtr;
    Col_RopeIterator it;

    Col_GetWordInfo(re, &data);
    if (data.custom.type != &regexpWordType) {
	Col_Error(COL_ERROR, "%x is not a regexp", re);
	return 0;
    }

    rePtr = (regex_t *) data.custom.data;

    //TODO ranges
#if 1
    Col_RopeIterFirst(string, &it);
    return CoatlReExec(rePtr, it, Col_RopeIterLength(&it), NULL, 0, NULL, 
	    flags);
#else
    {
    Col_WordData sdata;
    const Col_Char4 *s;

    string = Col_NormalizeRope(string, COL_UCS4, 0, 1);
    Col_GetWordInfo(string, &sdata);
    return CoatlReExec(rePtr, (const Col_Char4 *) sdata.string.data, 
	    Col_RopeLength(string), NULL, 0, NULL, flags);
    }
#endif
}
