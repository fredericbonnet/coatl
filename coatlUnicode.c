/*
 * File: coatlUnicode.c
 *
 *	This file implements the Unicode handling features of CoATL.
 *
 * See also:
 *	<coatlUnicode.h>
 */

#include "coatl.h"


/****************************************************************************
 * Section: Case Mapping and Folding
 ****************************************************************************/

/*---------------------------------------------------------------------------
 * Function: Coatl_CharIsTitlecase
 *
 *	Check whether the character is titlecase.
 *
 *	Uses the Unicode Character Database (UCD).
 *
 * Argument:
 *	c	- The character to check.
 *
 * Result:
 *	Whether the character is titlecase.
 *
 * See also:
 *	<Coatl_CharIsLowercase>, <Coatl_CharIsUppercase>, <Coatl_CharIsCased>,
 *	<Coatl_CharToTitlecase>, <Coatl_GetUcdProperty_Simple_Titlecase_Mapping>
 *---------------------------------------------------------------------------*/

int
Coatl_CharIsTitlecase(
    Col_Char c)
{
    return (Coatl_GetUcdProperty_Simple_Titlecase_Mapping(c) != c);
}


Col_Word
Coatl_RopeToLowercase(
    Col_Word r,
    int full)
{
}
Col_Word
Coatl_RopeToUppercase(
    Col_Word r,
    int full)
{
}
Col_Word
Coatl_RopeToTitlecase(
    Col_Word r,
    int full)
{
}
Col_Word
Coatl_RopeToCasefold(
    Col_Word r,
    int full)
{
}
int
Coatl_RopeIsLowercase(
    Col_Word r)
{
}
int
Coatl_RopeIsUppercase(
    Col_Word r)
{
}
int
Coatl_RopeIsTitlecase(
    Col_Word r)
{
}
int
Coatl_RopeIsCasefolded(
    Col_Word r)
{
}
int
Coatl_RopeIsCased(
    Col_Word r)
{
}
