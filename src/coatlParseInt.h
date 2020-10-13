/*
 * Internal Header: coatlParseInt.h
 *
 *      TODO
 */

#ifndef _COATL_PARSE_INT
#define _COATL_PARSE_INT

/*---------------------------------------------------------------------------
 * Internal Macro: GET_CHAR
 *
 *      Get current rope character for iterator, unless said iterator is past
 *      the given end of sequence, in this case execute the code that directly
 *      follows the construct.
 *
 *      For example:
 *
 * (start code)
 *      GET_CHAR(c, it, end) return 0;
 * (end code)
 *
 *      The above code reads the current character at iterator *it* into the 
 *      variable *c*, unless *it* is past *end*, in this case it returns 0.
 *
 * Arguments:
 *      it      - Current iterator position.
 *      end     - End of sequence.
 *
 * Return value:
 *      c       - Variable receiving the current character upon success.
 *
 * Side effects:
 *      Variable *c* is modified if *it* is before *end*.
 *
 * See also:
 *      <Col_RopeIterAt>, <Col_RopeIterCompare>
 *---------------------------------------------------------------------------*/

#define GET_CHAR(c, it, end) \
    if (Col_RopeIterCompare((it), (end)) >= 0) \
        goto COL_CONCATENATE(GET_CHAR,__LINE__); \
    (c) = Col_RopeIterAt(it); \
    if (0) \
COL_CONCATENATE(GET_CHAR,__LINE__): 

/*---------------------------------------------------------------------------
 * Internal Macro: NEXT_CHAR
 *
 *      Get next rope character for iterator, unless said iterator is past
 *      the given end of sequence, in this case execute the code that directly
 *      follows the construct.
 *
 *      For example:
 *
 * (start code)
 *      NEXT_CHAR(c, it, end) return 0;
 * (end code)
 *
 *      The above code reads the next character at iterator *it* into the 
 *      variable *c*, incrementing *it* in the process, unless *it* is past 
 *      *end*, in this case it returns 0.
 *
 *      This is the same as incrementing *it* then calling GET_CHAR with the 
 *      same arguments.
 *
 * Arguments:
 *      it      - Current iterator position.
 *      end     - End of sequence.
 *
 * Return value:
 *      c       - Variable receiving the next character upon success.
 *
 * Side effects:
 *      Iterator *it* is incremented. Variable *c* is modified if *it* is before
 *      *end*.
 *
 * See also:
 *      <Col_RopeIterAt>, <Col_RopeIterCompare>, <GET_CHAR>
 *---------------------------------------------------------------------------*/

#define NEXT_CHAR(c, it, end) \
    Col_RopeIterNext(it); GET_CHAR((c), (it), (end))

/*---------------------------------------------------------------------------
 * Internal Macro: IF_CHAR_IN
 *
 *      If-block testing whether a character belongs to the given character
 *      group. Roughly equivalent to the C code *if (strchr(s, c))*.
 *
 * Arguments:
 *      s       - Array of characters terminated by COL_CHAR_INVALID, or NULL
 *                for empty.
 *      c       - Character to test.
 *---------------------------------------------------------------------------*/

#define IF_CHAR_IN(s, c) \
    { \
        const Col_Char *p; \
        for (p = (s); p && *p != COL_CHAR_INVALID; p++) { \
            if (*p == (c)) goto COL_CONCATENATE(FINDCHAR,__LINE__); \
        } \
    } \
    if (0) \
COL_CONCATENATE(FINDCHAR,__LINE__): 

/*---------------------------------------------------------------------------
 * Internal Macro: SKIP_CHARS
 *
 *      Get first character not belonging to the given character group, starting
 *      at the given iterator position, unless said iterator gets past the given 
 *      end of sequence, in this case execute the code that directly follows the 
 *      construct.
 *
 * Arguments:
 *      s       - Array of characters terminated by COL_CHAR_INVALID, or NULL
 *                for empty.
 *      c       - Current character.
 *      it      - Current iterator position.
 *      end     - End of sequence.
 *
 * Return value:
 *      c       - Variable receiving the first character not within *s*.
 *
 * Side effects:
 *      If *c* is not within *s*, nothing happens.
 *      Else, iterator *it* is incremented repeatedly until a suitable character
 *      is found, which is written into the variable *c*.
 *
 * See also:
 *      <NEXT_CHAR>, <IF_CHAR_IN>
 *---------------------------------------------------------------------------*/

#define SKIP_CHARS(s, c, it, end) \
    for (;;) { \
        IF_CHAR_IN((s), (c)) { \
            NEXT_CHAR((c), (it), (end)) \
                goto COL_CONCATENATE(SKIP_CHARS,__LINE__); \
        } else break; \
    } \
    if (0) \
COL_CONCATENATE(SKIP_CHARS,__LINE__): 

#endif /* _COATL_PARSE_INT */
