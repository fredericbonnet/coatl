/*
 * File: coatlRegexp.c
 *
 *      This file implements the regular expression facility of CoATL.
 *
 *      The code is based on Henry Spencer's regexp library found in Tcl.
 *
 * See also:
 *      <coatlRegexp.h>
 */

#include "../include/coatl.h"
#include "coatlInternal.h"

#include "re/regex.h"

/*
 * Prototypes for functions used only in this file.
 */

static Col_CustomWordSizeProc RegexpSizeProc;
static Col_CustomWordFreeProc RegexpFreeProc;


/*
================================================================================
Internal Section: Type Checking
================================================================================
*/

/*---------------------------------------------------------------------------
 * Internal Macro: TYPECHECK_REGEXP
 *
 *      Type checking macro for regular expressions.
 *
 * Argument:
 *      word    - Checked word.
 *
 * Result:
 *      rePtr   - Variable receiving address of regex_t structure.
 *
 * Side effects:
 *      Generate <COL_TYPECHECK> error when *word* is not a regexp word.
 *
 * See also:
 *      <Col_Error>
 *---------------------------------------------------------------------------*/

#ifdef _DEBUG
#   define TYPECHECK_REGEXP(word, rePtr) \
        COL_RUNTIMECHECK(((Col_WordType(word) & COL_CUSTOM) \
                && Col_CustomWordInfo((word), (void **) &(rePtr)) \
                == &regexpWordType), COL_TYPECHECK, CoatlDomain, \
                COATL_ERROR_REGEXP, (word))
#else
#   define TYPECHECK_REGEXP(word, rePtr) \
        Col_CustomWordInfo((word), (void **) &(rePtr)); if (0)
#endif

/*
================================================================================
Section: Regular Expressions
================================================================================
*/

/*---------------------------------------------------------------------------
 * Internal Variable: regexpWordType
 *
 *      Custom word type holding a regex_t structure.
 *
 * See also:
 *      <RegexpSizeProc>, <RegexpFreeProc>
 *---------------------------------------------------------------------------*/

static Col_CustomWordType regexpWordType = {
    0,
    "regexp",
    RegexpSizeProc,
    RegexpFreeProc,
    NULL /* childrenProc */
};

/*---------------------------------------------------------------------------
 * Internal Function: RegexpSizeProc
 *
 *      Regexp word type size proc. Follows <Col_CustomWordSizeProc> signature. 
 *
 * Argument:
 *      word    - Custom word to get size for.
 *
 * Result:
 *      The custom word size in bytes.
 *
 * See also:
 *      <regexpWordType>
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
 *      Regexp word type cleanup proc. Follows <Col_CustomWordFreeProc>
 *      signature.
 *
 * Argument:
 *      word    - Custom word to cleanup.
 *
 * Side effects:
 *      Calls regex_t cleanup procedure.
 *
 * See also: 
 *      <regexpWordType>
 *---------------------------------------------------------------------------*/

static void
RegexpFreeProc(
    Col_Word word)
{
    regex_t *re;

    REQUIRE(Col_CustomWordInfo(word, (void **) &re) == &regexpWordType);

    CoatlReFree(re);
}

/*---------------------------------------------------------------------------
 * Function: Coatl_RegexpCompile
 *
 *      Compile a regular expression for later execution.
 *
 * Arguments:
 *      string  - Regular expression to compile.
 *      flags   - Compilation flags (see <Regular Expression Compilation 
 *                Flags>).
 *
 * Results:
 *      An error code (see <Regular Expression Compilation Error Codes>). 
 *      Additionally:
 *
 *      rePtr   - Regular expression word if compilation was successful (i.e.
 *                result is <COATL_RECOMP_OKAY>).
 *
 * Side effects:
 *      May allocate memory cells.
 *
 * See also:
 *      <Coatl_RegexpExec>
 *---------------------------------------------------------------------------*/

int
Coatl_RegexpCompile(
    Col_Word string, 
    int flags,
    Col_Word *rePtr)
{
    int result;
    regex_t re, *data;
    Col_RopeIterator it = COL_ROPEITER_NULL;

    Col_RopeIterFirst(it, string); 
    result = CoatlReCompile(&re, it, Col_RopeIterLength(it), flags);
    if (result == REG_OKAY) {
        *rePtr = Col_NewCustomWord(&regexpWordType, sizeof(*data), (void **) &data);
        *data = re;
    } else {
        *rePtr = WORD_NIL;
    }
    return result;
}

/*---------------------------------------------------------------------------
 * Function: Coatl_RegexpNbSubexpressions
 *
 *      Return the number of subexpressions in a compiled regular expression.
 *      I.e. the number of capturing sets of parentheses.
 *
 * Argument:
 *      re      - Compiled regular expression (result of <Coatl_RegexpCompile>).
 *
 * Type checking:
 *      *re* must be a valid regular expression word.
 *
 * Result:
 *      The number of subexpressions.
 *
 * See also:
 *      <Coatl_RegexpCompile>
 *---------------------------------------------------------------------------*/

size_t
Coatl_RegexpNbSubexpressions(
    Col_Word re)
{
    regex_t *rePtr;

    /*
     * Check preconditions.
     */

    TYPECHECK_REGEXP(re, rePtr) return 0;

    return rePtr->re_nsub;
}

/*---------------------------------------------------------------------------
 * Function: Coatl_RegexpExec
 *
 *      Execute a previously compiled regular expression.
 *
 * Arguments:
 *      re              - Compiled regular expression (result of 
 *                        <Coatl_RegexpCompile>).
 *      string          - String to match against regular expression.
 *      flags           - Execution flags (see <Regular Expression Execution 
 *                        Flags>).
 *      nbMatches       - Number of matching ranges to return upon success,
 *                        including the global match.
 *      matches         - If nbMatches is > 0, array of matching ranges of 
 *                        characters upon success.
 *
 * Type checking:
 *      *re* must be a valid regular expression word.
 *
 * Results:
 *      An error code (see <Regular Expression Execution Error Codes>).
 *      Additionally:
 *
 *      matches - Upon success and if nbMatches is > 0, holds the matching 
 *                ranges of characters, in the form of string index pairs in 
 *                even/odd order (first/last inclusive character indices 
 *                respectively, suitable for e.g. <Col_Subrope>), the first 
 *                pair being for the global match and the subsequent pairs for 
 *                the respective subexpressions. If either index of a pair is
 *                SIZE_MAX (which is always out of range whatever the string),
 *                this means that the respective subexpression didn't match.
 *
 * See also:
 *      <Coatl_RegexpCompile>
 *---------------------------------------------------------------------------*/

int
Coatl_RegexpExec(
    Col_Word re,
    Col_Word string,
    int flags,
    size_t nbMatches,
    size_t *matches)
{
    regex_t *rePtr;
    int result;
    Col_RopeIterator it = COL_ROPEITER_NULL;

    /*
     * Check preconditions.
     */

    TYPECHECK_REGEXP(re, rePtr) return 0;

    /*
     * Hack: Assume that regmatch_t, which is a struct holding a pair of 
     * regoff_t (= intptr_t), can be safely cast to a pair of intptr_t.
     * Moreover, the regexp engine uses signed intptr_t and the value -1 for
     * unmatched subexpressions, and we use size_t and SIZE_MAX respectively.
     * As size_t and intptr_t has the same size and SIZE_MAX and -1 has the
     * same binary representation in 2's complement, also assume that they can 
     * be safely cast as well. Sign overflow would only occur with insanely
     * large strings that the regexp engine couldn't handle properly anyway.
     */

    ASSERT(sizeof(regmatch_t) == sizeof(intptr_t)*2);
    ASSERT(sizeof(intptr_t) == sizeof(size_t));
    ASSERT(SIZE_MAX == (size_t) ((intptr_t)-1));

    Col_RopeIterFirst(it, string);
    result = CoatlReExec(rePtr, it, Col_RopeIterLength(it), NULL, nbMatches, 
            (regmatch_t *) matches, flags);
    if (matches && result == REG_OKAY) {
        /*
         * Offset range end indices by -1.
         */

        size_t i;
        ASSERT(nbMatches > 0);
        for (i = 1; i < nbMatches*2; i+=2) {
            matches[i] = matches[i] == -1 ? -1 : matches[i]-1;
        }
    }

    return result;
}
