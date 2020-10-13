/**
 * @file coatlUnicode.c
 *
 * This file implements the Unicode handling features of CoATL.
 *
 * @see coatlUnicode.h
 */

#include "../include/coatl.h"
#include "coatlInternal.h"

#include <limits.h>


/*
===========================================================================*//*!
\weakgroup unicode_case Case Mapping and Folding
\{*//*==========================================================================
*/

/*******************************************************************************
 * Unicode Case Predicates
 ******************************************************************************/

/**
 * Check whether the character is titlecase.
 *
 * Uses the Unicode Character Database (UCD).
 *
 * @return Whether the character is titlecase.
 *
 * @see Coatl_CharIsLowercase
 * @see Coatl_CharIsUppercase
 * @see Coatl_CharIsCased
 * @see Coatl_CharToTitlecase
 * @see Coatl_GetUcdProperty_Simple_Titlecase_Mapping
 */
int
Coatl_CharIsTitlecase(
    Col_Char c) /*!< The character to check. */
{
    return (Coatl_GetUcdProperty_Cased(c) 
            && Coatl_GetUcdProperty_Simple_Titlecase_Mapping(c) == c);
}

/**
 * Check whether the rope is lowercase.
 *
 * Uses the Unicode Character Database (UCD).
 *
 * @return Whether the rope is lowercase.
 *
 * @see Coatl_CharIsLowercase
 * @see Coatl_CharIsCased
 * @see Coatl_CharToLowercase
 */
int
Coatl_RopeIsLowercase(
    Col_Word r) /*!< The rope to check. */
{
    Col_RopeIterator it;
    for (Col_RopeIterFirst(it, r); !Col_RopeIterEnd(it); 
            Col_RopeIterNext(it)) {
        Col_Char c = Col_RopeIterAt(it);
        if (Coatl_CharIsCased(c) && !Coatl_CharIsLowercase(c)) return 0;
    }
    return 1;
}

/**
 * Check whether the rope is uppercase.
 *
 * Uses the Unicode Character Database (UCD).
 *
 * @return Whether the rope is uppercase.
 *
 * @see Coatl_CharIsUppercase
 * @see Coatl_CharIsCased
 * @see Coatl_CharToUppercase
 */
int
Coatl_RopeIsUppercase(
    Col_Word r) /*!< The rope to check. */
{
    Col_RopeIterator it;
    for (Col_RopeIterFirst(it, r); !Col_RopeIterEnd(it); 
            Col_RopeIterNext(it)) {
        Col_Char c = Col_RopeIterAt(it);
        if (Coatl_CharIsCased(c) && !Coatl_CharIsUppercase(c)) return 0;
    }
    return 1;
}

/**
 * Check whether the rope is titlecase.
 *
 * Uses the Unicode Character Database (UCD).
 *
 * @return Whether the rope is titlecase.
 *
 * @see Coatl_CharIsTitlecase
 * @see Coatl_CharIsCased
 * @see Coatl_CharToTitlecase
 */
int
Coatl_RopeIsTitlecase(
    Col_Word r) /*!< The rope to check. */
{
    Col_RopeIterator it;
    for (Col_RopeIterFirst(it, r); !Col_RopeIterEnd(it); 
            Col_RopeIterNext(it)) {
        Col_Char c = Col_RopeIterAt(it);
        if (Coatl_CharIsCased(c) && !Coatl_CharIsTitlecase(c)) return 0;
    }
    return 1;
}

/* TODO
int
Coatl_RopeIsCasefolded(
    Col_Word r)
{
    Col_RopeIterator it;
    for (Col_RopeIterFirst(it, r); !Col_RopeIterEnd(it); 
            Col_RopeIterNext(it)) {
        Col_Char c = Col_RopeIterAt(it);
//TODO  if (Coatl_CharIsCased(c) && !Coatl_CharIsCasefolded(c)) return 0;
    }
    return 1;
}
*/

/**
 * Check whether the rope is cased.
 *
 * Uses the Unicode Character Database (UCD).
 *
 * @return Whether the rope is cased.
 *
 * @see Coatl_CharIsCased
 */
int
Coatl_RopeIsCased(
    Col_Word r) /*!< The rope to check. */
{
    Col_RopeIterator it;
    for (Col_RopeIterFirst(it, r); !Col_RopeIterEnd(it); 
            Col_RopeIterNext(it)) {
        Col_Char c = Col_RopeIterAt(it);
        if (Coatl_CharIsCased(c)) return 1;
    }
    return 0;
}

/* End of Unicode Case Predicates */


/*******************************************************************************
 * Unicode Case Transform
 ******************************************************************************/

/** @beginprivate @cond PRIVATE */

/**
 * Transform rope using a one-to-one character mapping function.
 *
 * @return The transformed rope.
 */
static Col_Word
MapRope(
    Col_Word r,                     /*!< The rope to transform. */
    Col_Char (*mapProc)(Col_Char))  /*!< The mapping function. */
{
    Col_RopeIterator it, firstUnchanged = COL_ROPEITER_NULL;
    Col_Word strbuf = Col_NewStringBuffer(0, COL_UCS);//TODO optimize buffer length?
    for (Col_RopeIterFirst(it, r); !Col_RopeIterEnd(it); 
            Col_RopeIterNext(it)) {
        Col_Char c = Col_RopeIterAt(it);
        Col_Char mc = mapProc(c);
        if (mc == c) {
            /*
             * Identity, remember position.
             */

            if (Col_RopeIterNull(firstUnchanged)) {
                Col_RopeIterSet(firstUnchanged, it);
            }
            continue;
        }
        if (!Col_RopeIterNull(firstUnchanged)) {
            /*
             * Append unchanged character sequence.
             */

            Col_StringBufferAppendSequence(strbuf, firstUnchanged, it);
            Col_RopeIterSetNull(firstUnchanged);
        }

        /*
         * Append mapped character.
         */

        Col_StringBufferAppendChar(strbuf, mc);
    }
    if (!Col_RopeIterNull(firstUnchanged)) {
        /*
         * Append unchanged character sequence.
         */

        ASSERT(Col_RopeIterEnd(it));
        Col_StringBufferAppendSequence(strbuf, firstUnchanged, it);
    }
    return Col_StringBufferFreeze(strbuf);
}

/**
 * Transform rope using a one-to-many character mapping function.
 *
 * @return The transformed rope.
 */
static Col_Word
TransformRope(
    Col_Word r,                                 /*!< The rope to transform. */
    const int * (*mapProc)(Col_Char, size_t *)) /*!< The mapping function. */
{
    Col_RopeIterator it, firstUnchanged = COL_ROPEITER_NULL;
    Col_Word strbuf = Col_NewStringBuffer(0, COL_UCS);//TODO optimize buffer length?
    for (Col_RopeIterFirst(it, r); !Col_RopeIterEnd(it); 
            Col_RopeIterNext(it)) {
        Col_Char c = Col_RopeIterAt(it);
        size_t length;
        const int *lc = mapProc(c, &length);
        if (length == 0 || (length == 1 && *lc == 0)) {
            /*
             * Identity, remember position.
             */

            if (Col_RopeIterNull(firstUnchanged)) {
                Col_RopeIterSet(firstUnchanged, it);
            }
            continue;
        } 
        if (!Col_RopeIterNull(firstUnchanged)) {
            /*
             * Append unchanged character sequence.
             */

            Col_StringBufferAppendSequence(strbuf, firstUnchanged, it);
            Col_RopeIterSetNull(firstUnchanged);
        }
        if (length == 1) {
            /*
             * Offset, append mapped character.
             */

            ASSERT(*lc != 0);
            Col_StringBufferAppendChar(strbuf, c + *lc);
        } else {
            /*
             * Sequence, append mapped characters.
             */

            while (length--) Col_StringBufferAppendChar(strbuf, 
                    (Col_Char) *lc++);
        }
    }
    if (!Col_RopeIterNull(firstUnchanged)) {
        /*
         * Append unchanged character sequence.
         */

        ASSERT(Col_RopeIterEnd(it));
        Col_StringBufferAppendSequence(strbuf, firstUnchanged, it);
    }
    return Col_StringBufferFreeze(strbuf);
}

/** @endcond @endprivate */

/**
 * Transform the rope to lowercase.
 *
 * Uses the Unicode Character Database (UCD).
 *
 * Two modes are available:
 * - full mode: cased characters are transformed into character sequences, 
 *   depending on the UCD property '**Lowercase_Mapping**'
 * - simple mode: cased characters are mapped individually, depending on the
 *   UCD property '**Simple_Lowercase_Mapping**'
 *
 * @return The transformed rope.
 *
 * @see Coatl_GetUcdProperty_Lc
 * @see Coatl_GetUcdProperty_Slc
 */
Col_Word
Coatl_RopeToLowercase(
    Col_Word r, /*!< The rope to transform. */
    int full)   /*!< Whether to use full or simple mode. */
{
    return full ? TransformRope(r, Coatl_GetUcdProperty_Lc)
            : MapRope(r, Coatl_GetUcdProperty_Slc);
}

/**
 * Transform the rope to uppercase.
 *
 * Uses the Unicode Character Database (UCD).
 *
 * Two modes are available:
 * - full mode: cased characters are transformed into character sequences, 
 *   depending on the UCD property '**Uppercase_Mapping**'
 * - simple mode: cased characters are mapped individually, depending on the
 *   UCD property '**Simple_Uppercase_Mapping**'
 *
 * @return The transformed rope.
 *
 * @see Coatl_GetUcdProperty_Uc
 * @see Coatl_GetUcdProperty_Suc
 */
Col_Word
Coatl_RopeToUppercase(
    Col_Word r, /*!< The rope to transform. */
    int full)   /*!< Whether to use full or simple mode. */
{
    return full ? TransformRope(r, Coatl_GetUcdProperty_Uc)
            : MapRope(r, Coatl_GetUcdProperty_Suc);
}

/**
 * Transform the rope to titlecase.
 *
 * Uses the Unicode Character Database (UCD).
 *
 * Two modes are available:
 * - full mode: cased characters are transformed into character sequences, 
 *   depending on the UCD property '**Titlecase_Mapping**'
 * - simple mode: cased characters are mapped individually, depending on the
 *   UCD property '**Simple_Titlecase_Mapping**'
 *
 * @return The transformed rope.
 *
 * @see Coatl_GetUcdProperty_Tc
 * @see Coatl_GetUcdProperty_Stc
 */
Col_Word
Coatl_RopeToTitlecase(
    Col_Word r, /*!< The rope to transform. */
    int full)   /*!< Whether to use full or simple mode. */
{
    return full ? TransformRope(r, Coatl_GetUcdProperty_Tc)
            : MapRope(r, Coatl_GetUcdProperty_Stc);
}

/**
 * Transform the rope to case folded.
 *
 * Uses the Unicode Character Database (UCD).
 *
 * Two modes are available:
 * - full mode: cased characters are transformed into character sequences, 
 *   depending on the UCD property '**Case_Folding**'
 * - simple mode: cased characters are mapped individually, depending on the
 *   UCD property '**Simple_Case_Folding**'
 *
 * @return The transformed rope.
 *
 * @see Coatl_GetUcdProperty_Cf
 * @see Coatl_GetUcdProperty_Scf
 */
Col_Word
Coatl_RopeToCaseFolded(
    Col_Word r, /*!< The rope to transform. */
    int full)   /*!< Whether to use full or simple mode. */
{
    return full ? TransformRope(r, Coatl_GetUcdProperty_Cf)
            : MapRope(r, Coatl_GetUcdProperty_Scf);
}

/* End of Unicode Case Transform */

/* End of Case Mapping and Folding *//*!\}*/
