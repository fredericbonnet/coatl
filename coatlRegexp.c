/*
 * File: coatlRegexp.c
 *
 *	This file implements the regular expression facility of CoATL.
 *
 *	The code is based on Henry Spencer's regexp library found in Tcl.
 *
 * See also:
 *	<coatlRegexp.h>
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
 *	flags	- Compilation flags (see <Regular Expression Compilation 
 *		  Flags>).
 *
 * Result:
 *	An error code (see <Regular Expression Compilation Error Codes>). 
 *	Additionally:
 *
 *	rePtr	- Regular expression word if compilation was successful (i.e.
 *		  result is <COATL_RECOMP_OKAY>).
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
    int result;
    regex_t re;
    void *data;

#ifdef REGEXP_USE_ITERATORS
    {
    Col_RopeIterator it;
    Col_RopeIterFirst(string, &it); 
    result = CoatlReCompile(&re, it, Col_RopeIterLength(&it), flags);
    }
#else
    {
    Col_WordData sdata;

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
 * Function: Coatl_RegexpNbSubexpressions
 *
 *	Return the number of subexpressions in a compiled regular expression.
 *	I.e. the number of capturing sets of parentheses.
 *
 * Argument:
 *	re	- Compiled regular expression (result of <Coatl_RegexpCompile>).
 *
 * Result:
 *	The number of subexpressions.
 *
 * See also:
 *	<Coatl_RegexpCompile>
 *---------------------------------------------------------------------------*/

size_t
Coatl_RegexpNbSubexpressions(
    Col_Word re)
{
    Col_WordData data;
    regex_t *rePtr;

    Col_GetWordInfo(re, &data);
    if (data.custom.type != &regexpWordType) {
	Col_Error(COL_ERROR, "%x is not a regexp", re);
	return 0;
    }

    rePtr = (regex_t *) data.custom.data;

    return rePtr->re_nsub;
}

/*---------------------------------------------------------------------------
 * Function: Coatl_RegexpExec
 *
 *	Execute a previously compiled regular expression.
 *
 * Arguments:
 *	re		- Compiled regular expression (result of 
 *			  <Coatl_RegexpCompile>).
 *	string		- String to match against regular expression.
 *	flags		- Execution flags (see <Regular Expression Execution 
 *			  Flags>).
 *	matchesPtr	- If non-NULL, points to a word that will hold the 
 *			  matching ranges of characters upon success. If this
 *			  word is nil at call time, will allocates a new mutable
 *			  vector sized to fit the total number of ranges.
 *			  subexpressions. Else, must be a mutable vector whose
 *			  size gives the maximum number of returned ranges.
 *
 * Result:
 *	An error code (see <Regular Expression Execution Error Codes>).
 *	Additionally:
 *
 *	matchesPtr	- Upon success and if non-NULL, a mutable vector holding
 *			  the matching ranges of characters, in the form of 
 *			  integer word pairs in even/odd order (first/last 
 *			  inclusive character indices respectively), the first 
 *			  pair being for the global match and the subsequent 
 *			  pairs for the respective subexpressions. If either 
 *			  index of a pair is -1, this means that the respective 
 *			  subexpression didn't match.
 *
 * See also:
 *	<Coatl_RegexpCompile>
 *---------------------------------------------------------------------------*/

int
Coatl_RegexpExec(
    Col_Word re,
    Col_Word string,
    int flags,
    Col_Word *resultsPtr)
{
    Col_WordData data;
    regex_t *rePtr;
    size_t nbMatches = 0;
    regmatch_t *matches = NULL;
    int result;

    Col_GetWordInfo(re, &data);
    if (data.custom.type != &regexpWordType) {
	Col_Error(COL_ERROR, "%x is not a regexp", re);
	return 0;
    }

    rePtr = (regex_t *) data.custom.data;

    if (resultsPtr != NULL) {
	/*
	 * Mutable vector holding results.
	 */

	if (!*resultsPtr) {
	    /*
	     * Allocate adequately sized mutable vector.
	     */

	    *resultsPtr = Col_NewMVector(0, (rePtr->re_nsub+1)*2, NULL);
	}
	if (Col_GetWordInfo(*resultsPtr, &data) != COL_MVECTOR) {
	    Col_Error(COL_ERROR, "result vector %x is not a mutable vector", 
		    *resultsPtr);
	    return 0;
	}

	/*
	 * Hack: cast the Col_Word-pair array to a regmatch_t array and convert
	 * data later. This should work bar exotic alignment problems.
	 */

	ASSERT(sizeof(regmatch_t) == sizeof(Col_Word)*2);
	nbMatches = data.mvector.length/2;
	matches = (regmatch_t *) data.mvector.elements;
    }

#ifdef REGEXP_USE_ITERATORS
    {
    Col_RopeIterator it;
    Col_RopeIterFirst(string, &it);
    result = CoatlReExec(rePtr, it, Col_RopeIterLength(&it), NULL, nbMatches, 
	    matches, flags);
    }
#else
    {
    Col_WordData sdata;

    string = Col_NormalizeRope(string, COL_UCS4, 0, 1);
    Col_GetWordInfo(string, &sdata);
    result = CoatlReExec(rePtr, (const Col_Char4 *) sdata.string.data, 
	    Col_RopeLength(string), NULL, nbMatches, matches, flags);
    }
#endif

    if (matches && result == REG_OKAY) {
	/*
	 * Hack: convert regmatch_t/regoff_t to integer words.
	 */

	size_t i;
	ASSERT(nbMatches > 0);
	for (i = 0; i < nbMatches; i++) {
	    matches[i].rm_so = (regoff_t) Col_NewIntWord(matches[i].rm_so);
	    matches[i].rm_eo = (regoff_t) Col_NewIntWord(
		    matches[i].rm_eo == -1 ? -1 : matches[i].rm_eo-1);
	}
    }

    return result;
}
