/**
 * @file coatlParseInt.h
 *
 * This header file defines parsing utilities.
 *
 * @see coatlJson.h
 *
 * @beginprivate @cond PRIVATE
 */

#ifndef _COATL_PARSE_INT
#define _COATL_PARSE_INT

/*
===========================================================================*//*!
\internal \defgroup parsing Parsing Utilities
\{*//*==========================================================================
*/

/**
 * Get current rope character for iterator, unless said iterator is past the
 * given end of sequence, in which case execute the code that directly follows
 * the construct.
 *
 * For example:
 *
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * GET_CHAR(c, it, end) return 0;
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 *
 * The above code reads the current character at iterator **it** into the 
 * variable **c**, unless **it** is past **end**, in which case it returns 0.
 *
 * @param it    Current iterator position.
 * @param end   End of sequence.
 *
 * @param[out] c    Variable receiving the current character upon success.
 *
 * @sideeffect
 *      Variable **c** is modified if **it** is before **end**.
 *
 * @see **Col_RopeIterAt**
 * @see **Col_RopeIterCompare**
 */
#define GET_CHAR(c, it, end) \
    if (Col_RopeIterCompare((it), (end)) >= 0) \
        goto COL_CONCATENATE(GET_CHAR,__LINE__); \
    (c) = Col_RopeIterAt(it); \
    if (0) \
COL_CONCATENATE(GET_CHAR,__LINE__): 

/**
 * Get next rope character for iterator, unless said iterator is past the given
 * end of sequence, in which case execute the code that directly follows the
 * construct.
 *
 * For example:
 *
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * NEXT_CHAR(c, it, end) return 0;
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 *
 * The above code reads the next character at iterator **it** into the variable
 * **c**, incrementing **it** in the process, unless **it** is past **end**, in
 * which case it returns 0.
 *
 * This is the same as incrementing **it** then calling GET_CHAR() with the same
 * arguments.
 *
 * @param it    Current iterator position.
 * @param end   End of sequence.
 *
 * @param[out] c    Variable receiving the next character upon success.
 *
 * @sideeffect
 *      Iterator **it** is incremented. Variable **c** is modified if **it** is
 *      before **end**.
 *
 * @see **Col_RopeIterAt**
 * @see **Col_RopeIterCompare**
 * @see GET_CHAR
 */
#define NEXT_CHAR(c, it, end) \
    Col_RopeIterNext(it); GET_CHAR((c), (it), (end))

/**
 * If-block testing whether a character belongs to the given character group.
 * Roughly equivalent to the C code `if (strchr(s, c))`.
 *
 * @param s Array of characters terminated by **COL_CHAR_INVALID**, or NULL for 
            empty.
 * @param c Character to test.
 */
#define IF_CHAR_IN(s, c) \
    { \
        const Col_Char *p; \
        for (p = (s); p && *p != COL_CHAR_INVALID; p++) { \
            if (*p == (c)) goto COL_CONCATENATE(FINDCHAR,__LINE__); \
        } \
    } \
    if (0) \
COL_CONCATENATE(FINDCHAR,__LINE__): 

/**
 * Get first character not belonging to the given character group, starting at
 * the given iterator position, unless said iterator gets past the given end of
 * sequence, in which case execute the code that directly follows the construct.
 *
 * @param s         Array of characters terminated by **COL_CHAR_INVALID**, or 
 *                  NULL for empty.
 * @param[in,out] c Current character on input, will receive the first character
 *                  not within **s** on output.
 * @param it        Current iterator position.
 * @param end       End of sequence.
 *
 * @sideeffect
 *      If **c** is not within **s**, nothing happens.
 *      Else, iterator **it** is incremented repeatedly until a suitable 
 *      character is found, which is written into the variable **c**.
 *
 * @see NEXT_CHAR
 * @see IF_CHAR_IN
 */
#define SKIP_CHARS(s, c, it, end) \
    for (;;) { \
        IF_CHAR_IN((s), (c)) { \
            NEXT_CHAR((c), (it), (end)) \
                goto COL_CONCATENATE(SKIP_CHARS,__LINE__); \
        } else break; \
    } \
    if (0) \
COL_CONCATENATE(SKIP_CHARS,__LINE__): 

/* End of Parsing Utilities *//*!\}*/

#endif /* _COATL_PARSE_INT */
/*! @endcond @endprivate */
