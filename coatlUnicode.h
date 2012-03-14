/*
 * Header: coatlUnicode.h
 *
 *	This header file defines the Unicode handling features of CoATL.
 */

#ifndef _COATL_UNICODE
#define _COATL_UNICODE

#include "coatlUcdProperties.h"
#include "coatlUcd.h"


/****************************************************************************
 * Section: Case Mapping and Folding
 *
 *	Per-character and rope case mapping and folding following the Unicode
 *	standard. 
 *
 *	Per-character conversion routines use simple case mapping and folding,
 *	i.e. they only return single characters. 
 *
 *	Rope conversion routines can use either simple (single character) or 
 *	full (multiple character) mapping and folding. In the latter case the
 *	output string may be larger than the input.
 *
 *	Some routines are direct mapping to Unicode Character Database (UCD)
 *	property accessors.
 *
 * Declarations:
 *	<Coatl_CharIsTitlecase>, <Coatl_RopeToLowercase>,
 *	<Coatl_RopeToUppercase>, <Coatl_RopeToTitlecase>,
 *	<Coatl_RopeToCasefold>, <Coatl_RopeIsLowercase>,
 *	<Coatl_RopeIsUppercase>, <Coatl_RopeIsTitlecase>,
 *	<Coatl_RopeIsCasefolded>, <Coatl_RopeIsCased>,
 ****************************************************************************/

EXTERN int		Coatl_CharIsTitlecase(Col_Char c);

EXTERN Col_Word		Coatl_RopeToLowercase(Col_Word r, int full);
EXTERN Col_Word		Coatl_RopeToUppercase(Col_Word r, int full);
EXTERN Col_Word		Coatl_RopeToTitlecase(Col_Word r, int full);
EXTERN Col_Word		Coatl_RopeToCasefold(Col_Word r, int full);
EXTERN int		Coatl_RopeIsLowercase(Col_Word r);
EXTERN int		Coatl_RopeIsUppercase(Col_Word r);
EXTERN int		Coatl_RopeIsTitlecase(Col_Word r);
EXTERN int		Coatl_RopeIsCasefolded(Col_Word r);
EXTERN int		Coatl_RopeIsCased(Col_Word r);

/*---------------------------------------------------------------------------
 * Macro: Coatl_CharToLowercase
 *
 *	Return the simple lowercase mapping of the given character.
 *
 *	Uses the Unicode Character Database (UCD).
 *
 * Argument:
 *	c	- The character to map.
 *
 * Result:
 *	The mapped character.
 *
 * See also:
 *	<Coatl_CharToUppercase>, <Coatl_CharToTitlecase>, 
 *	<Coatl_CharIsLowercase>, <Coatl_GetUcdProperty_Simple_Lowercase_Mapping>
 *---------------------------------------------------------------------------*/

#define Coatl_CharToLowercase(c) \
    Coatl_GetUcdProperty_Simple_Lowercase_Mapping(c)

/*---------------------------------------------------------------------------
 * Macro: Coatl_CharToUppercase
 *
 *	Return the simple uppercase mapping of the given character.
 *
 *	Uses the Unicode Character Database (UCD).
 *
 * Argument:
 *	c	- The character to map.
 *
 * Result:
 *	The mapped character.
 *
 * See also:
 *	<Coatl_CharToLowercase>, <Coatl_CharToTitlecase>, 
 *	<Coatl_CharIsUppercase>, <Coatl_GetUcdProperty_Simple_Uppercase_Mapping>
 *---------------------------------------------------------------------------*/

#define Coatl_CharToUppercase(c) \
    Coatl_GetUcdProperty_Simple_Uppercase_Mapping(c)

/*---------------------------------------------------------------------------
 * Macro: Coatl_CharToTitlecase
 *
 *	Return the simple titlecase mapping of the given character.
 *
 *	Uses the Unicode Character Database (UCD).
 *
 * Argument:
 *	c	- The character to map.
 *
 * Result:
 *	The mapped character.
 *
 * See also:
 *	<Coatl_CharToLowercase>, <Coatl_CharToUppercase>, 
 *	<Coatl_CharIsTitlecase>, <Coatl_GetUcdProperty_Simple_Titlecase_Mapping>
 *---------------------------------------------------------------------------*/

#define Coatl_CharToTitlecase(c) \
    Coatl_GetUcdProperty_Simple_Titlecase_Mapping(c)

/*---------------------------------------------------------------------------
 * Macro: Coatl_CharIsLowercase
 *
 *	Check whether the character is lowercase.
 *
 *	Uses the Unicode Character Database (UCD).
 *
 * Argument:
 *	c	- The character to check.
 *
 * Result:
 *	Whether the character is lowercase.
 *
 * See also:
 *	<Coatl_CharIsUppercase>, <Coatl_CharIsTitlecase>, <Coatl_CharIsCased>,
 *	<Coatl_CharToLowercase>, <Coatl_GetUcdProperty_Lowercase>
 *---------------------------------------------------------------------------*/

#define Coatl_CharIsLowercase(c) \
    Coatl_GetUcdProperty_Lowercase(c)

/*---------------------------------------------------------------------------
 * Macro: Coatl_CharIsUppercase
 *
 *	Check whether the character is uppercase.
 *
 *	Uses the Unicode Character Database (UCD).
 *
 * Argument:
 *	c	- The character to check.
 *
 * Result:
 *	Whether the character is uppercase.
 *
 * See also:
 *	<Coatl_CharIsLowercase>, <Coatl_CharIsTitlecase>, <Coatl_CharIsCased>,
 *	<Coatl_CharToUppercase>, <Coatl_GetUcdProperty_Uppercase>
 *---------------------------------------------------------------------------*/

#define Coatl_CharIsUppercase(c) \
    Coatl_GetUcdProperty_Uppercase(c)

/*---------------------------------------------------------------------------
 * Macro: Coatl_CharIsCased
 *
 *	Check whether the character is cased.
 *
 *	Uses the Unicode Character Database (UCD).
 *
 * Argument:
 *	c	- The character to check.
 *
 * Result:
 *	Whether the character is cased.
 *
 * See also:
 *	<Coatl_CharIsLowercase>, <Coatl_CharIsUppercase>, 
 *	<Coatl_CharIsTitlecase>, <Coatl_GetUcdProperty_Cased>
 *---------------------------------------------------------------------------*/

#define Coatl_CharIsCased(c) \
    Coatl_GetUcdProperty_Cased(c)


#endif /* _COATL_UNICODE */
