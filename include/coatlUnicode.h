/**
 * @file coatlUnicode.h
 *
 * This header file defines the Unicode handling features of CoATL.
 */

#ifndef _COATL_UNICODE
#define _COATL_UNICODE

#include "coatlUcdProperties.h"
#include "coatlUcd.h"

/*
===========================================================================*//*!
\defgroup unicode Unicode
\{*//*==========================================================================
*/

/*
===========================================================================*//*!
\defgroup unicode_case Case Mapping and Folding

Per-character and rope case mapping and folding following the Unicode standard.

Per-character conversion routines use simple case mapping and folding, i.e. they
only return single characters.

Rope conversion routines can use either simple (single character) or full
(multiple character) mapping and folding. In the latter case the output string
may be larger than the input.

Some routines are direct mapping to Unicode Character Database (UCD) property
accessors.
\{*//*==========================================================================
*/

/***************************************************************************//*!
 * \name Unicode Case Predicates
 ***************************************************************************\{*/

/**
 * Check whether the character is lowercase.
 *
 * Uses the Unicode Character Database (UCD).
 *
 * @param c The character to check.
 *
 * @return Whether the character is lowercase.
 *
 * @see Coatl_CharIsUppercase
 * @see Coatl_CharIsTitlecase
 * @see Coatl_CharIsCased
 * @see Coatl_CharToLowercase
 * @see Coatl_GetUcdProperty_Lowercase
 */
#define Coatl_CharIsLowercase(c) \
    Coatl_GetUcdProperty_Lowercase(c)

/**
 * Check whether the character is uppercase.
 *
 * Uses the Unicode Character Database (UCD).
 *
 * @param c The character to check.
 *
 * @return Whether the character is uppercase.
 *
 * @see Coatl_CharIsLowercase
 * @see Coatl_CharIsTitlecase
 * @see Coatl_CharIsCased
 * @see Coatl_CharToUppercase
 * @see Coatl_GetUcdProperty_Uppercase
 */
#define Coatl_CharIsUppercase(c) \
    Coatl_GetUcdProperty_Uppercase(c)

/**
 * Check whether the character is cased.
 *
 * Uses the Unicode Character Database (UCD).
 *
 * @param c The character to check.
 *
 * @return Whether the character is cased.
 *
 * @see Coatl_CharIsLowercase
 * @see Coatl_CharIsUppercase
 * @see Coatl_CharIsTitlecase
 * @see Coatl_GetUcdProperty_Cased
 */
#define Coatl_CharIsCased(c) \
    Coatl_GetUcdProperty_Cased(c)

/*
 * Remaining declarations.
 */

EXTERN int              Coatl_CharIsTitlecase(Col_Char c);
EXTERN int              Coatl_RopeIsLowercase(Col_Word r);
EXTERN int              Coatl_RopeIsUppercase(Col_Word r);
EXTERN int              Coatl_RopeIsTitlecase(Col_Word r);
// TODO EXTERN int              Coatl_RopeIsCasefolded(Col_Word r);
EXTERN int              Coatl_RopeIsCased(Col_Word r);

/* End of Unicode Case Predicates *//*!\}*/


/***************************************************************************//*!
 * \name Unicode Case Transform
 ***************************************************************************\{*/

/**
 * Return the simple lowercase mapping of the given character.
 *
 * Uses the Unicode Character Database (UCD).
 *
 * @param c The character to map.
 *
 * @return The mapped character.
 *
 * @see Coatl_CharToUppercase
 * @see Coatl_CharToTitlecase
 * @see Coatl_CharIsLowercase
 * @see Coatl_GetUcdProperty_Simple_Lowercase_Mapping
 */
#define Coatl_CharToLowercase(c) \
    Coatl_GetUcdProperty_Simple_Lowercase_Mapping(c)

/**
 * Return the simple uppercase mapping of the given character.
 *
 * Uses the Unicode Character Database (UCD).
 *
 * @param c The character to map.
 *
 * @return The mapped character.
 * 
 * @see Coatl_CharToLowercase
 * @see Coatl_CharToTitlecase
 * @see Coatl_CharIsUppercase
 * @see Coatl_GetUcdProperty_Simple_Uppercase_Mapping
 */
#define Coatl_CharToUppercase(c) \
    Coatl_GetUcdProperty_Simple_Uppercase_Mapping(c)

/**
 * Return the simple titlecase mapping of the given character.
 *
 * Uses the Unicode Character Database (UCD).
 *
 * @param c The character to map.
 *
 * @return The mapped character.
 *
 * @see Coatl_CharToLowercase
 * @see Coatl_CharToUppercase
 * @see Coatl_CharIsTitlecase
 * @see Coatl_GetUcdProperty_Simple_Titlecase_Mapping
 */
#define Coatl_CharToTitlecase(c) \
    Coatl_GetUcdProperty_Simple_Titlecase_Mapping(c)

/**
 * Return the simple case folding of the given character.
 *
 * Uses the Unicode Character Database (UCD).
 *
 * @param c The character to map.
 *
 * @return The mapped character.
 *
 * @see Coatl_GetUcdProperty_Simple_Case_Folding
 */
#define Coatl_CharToCaseFolded(c) \
    Coatl_GetUcdProperty_Simple_Case_Folding(c)

/*
 * Remaining declarations.
 */

EXTERN Col_Word         Coatl_RopeToLowercase(Col_Word r, int full);
EXTERN Col_Word         Coatl_RopeToUppercase(Col_Word r, int full);
EXTERN Col_Word         Coatl_RopeToTitlecase(Col_Word r, int full);
EXTERN Col_Word         Coatl_RopeToCaseFolded(Col_Word r, int full);

/* End of Unicode Case Transform *//*!\}*/

/* End of Case Mapping and Folding *//*!\}*/

/* End of Unicode *//*!\}*/

#endif /* _COATL_UNICODE */
