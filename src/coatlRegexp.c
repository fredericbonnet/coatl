/**
 * @file coatlRegexp.c
 *
 * This file implements the regular expression facility of CoATL.
 *
 * The code is based on Henry Spencer's regexp library found in Tcl.
 *
 * @see coatlRegexp.h
 */

#include "../include/coatl.h"
#include "coatlInternal.h"

#include "re/regex.h"

/*
 * Prototypes for functions used only in this file.
 */

/*! \cond IGNORE */
static Col_CustomWordSizeProc RegexpSizeProc;
static Col_CustomWordFreeProc RegexpFreeProc;
/*! \endcond *//* IGNORE */


/*
===========================================================================*//*!
\internal \defgroup regexp_words Regular Expression Words
\ingroup regexp
\{*//*==========================================================================
*/

/** @beginprivate @cond PRIVATE */

/***************************************************************************//*!
 * \name Regular Expression Word Type
 *
 * Regular expressions are custom Colibri word types.
 ***************************************************************************\{*/

/**
 * Custom word type holding a **regex_t** structure.
 *
 * @see RegexpSizeProc
 * @see RegexpFreeProc
 */
static Col_CustomWordType regexpWordType = {
    0,
    "regexp",
    RegexpSizeProc,
    RegexpFreeProc,
    NULL /* childrenProc */
};

/**
 * Regexp word type size proc. Follows **Col_CustomWordSizeProc()** signature. 
 *
 * @return The custom word size in bytes.
 *
 * @see regexpWordType
 */
static size_t
RegexpSizeProc(
    Col_Word word)  /*!< Custom word to get size for. */
{
    return sizeof(regex_t);
}

/**
 * Regexp word type cleanup proc. Follows **Col_CustomWordFreeProc()** 
 * signature.
 *
 * @sideeffect
 *      Calls **regex_t** cleanup procedure.
 *
 * @see regexpWordType
 */
static void
RegexpFreeProc(
    Col_Word word)  /*!< Custom word to cleanup. */
{
    regex_t *re;

    REQUIRE(Col_CustomWordInfo(word, (void **) &re) == &regexpWordType);

    CoatlReFree(re);
}

/* End of Regular Expression Word Type *//*!\}*/


/***************************************************************************//*!
 * \name Regular Expression Word Type Checking
 ***************************************************************************\{*/

/**
 * Type checking macro for regular expressions.
 *
 * @param word  Checked word.
 *
 * @param[out] rePtr    Variable receiving address of **regex_t** structure.
 *
 * @typecheck{COATL_ERROR_REGEXP,word}
 *
 * @see **COL_RUNTIMECHECK**
 * @hideinitializer
 **/
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

/* End of Regular Expression Word Type Checking *//*!\}*/

/** @endcond @endprivate */

/* End of Regular Expression Words *//*!\}*/


/*
===========================================================================*//*!
\weakgroup regexp Regular Expressions
\{*//*==========================================================================
*/

/**
 * Compile a regular expression for later execution.
 *
 * @return A @ref regexp_compile_errors "compilation error code". 
 *
 * @sideeffect
 *      May allocate memory cells.
 *
 * @see Coatl_RegexpExec
 */
int
Coatl_RegexpCompile(
    Col_Word string,    /*!< Regular expression to compile. */
    int flags,          /*!< @ref regexp_compile_flags "Compilation flags". */

    /*! [out] Regular expression word if compilation was successful (i.e. result
        is #COATL_RECOMP_OKAY). */
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

/**
 * Return the number of subexpressions in a compiled regular expression, i\.e\. 
 * the number of capturing sets of parentheses.
 *
 * @return The number of subexpressions.
 *
 * @see Coatl_RegexpCompile
 */
size_t
Coatl_RegexpNbSubexpressions(
    Col_Word re)    /*!< Compiled regular expression (result of 
                         Coatl_RegexpCompile()). */
{
    regex_t *rePtr;

    /*
     * Check preconditions.
     */

    /*! @typecheck{COATL_ERROR_REGEXP,re} */
    TYPECHECK_REGEXP(re, rePtr) return 0;

    return rePtr->re_nsub;
}

/**
 * Execute a previously compiled regular expression.
 *
 * @return A @ref regexp_exec_errors "execution error code".
 *
 * @see Coatl_RegexpCompile
 */
int
Coatl_RegexpExec(
    Col_Word re,        /*!< Compiled regular expression (result of 
                             Coatl_RegexpCompile()). */
    Col_Word string,    /*!< String to match against regular expression. */
    int flags,          /*!< @ref regexp_exec_flags "Execution flags". */
    size_t nbMatches,   /*!< Number of matching ranges to return upon success,
                             including the global match. */

    /*! [out] Upon success and if **nbMatches** is > 0, holds the matching
        ranges of characters, in the form of string index pairs in even/odd
        order (first/last inclusive character indices respectively, suitable for
        e.g. **Col_Subrope()**), the first pair being for the global match and
        the subsequent pairs for the respective subexpressions. If either index
        of a pair is SIZE_MAX (which is always out of range whatever the
        string), this means that the respective subexpression didn't match. */
    size_t *matches)
{
    regex_t *rePtr;
    int result;
    Col_RopeIterator it = COL_ROPEITER_NULL;

    /*
     * Check preconditions.
     */

    /*! @typecheck{COATL_ERROR_REGEXP,re} */
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

/* End of Regular Expressions *//*!\}*/
