header
{/*
 * Header: coatlUcd.h
 *
 *	This file defines Unicode character property accessors.
 *
 *	It is automatically generated from the Unicode Character Database (UCD)
 *	using the file *coatlUcd.tcl*; Do not modify.
 */

#ifndef _COATL_UCD
#define _COATL_UCD
}

footer 
{
#endif /* _COATL_UCD */}

ucdPropertyAccessorsGroup 
{
/*
================================================================================
Section: UCD Property Accessors

Declarations: ${declarations}
================================================================================
*/
}

propertyAccessorDeclarationFirst
{
	<Coatl_GetUcdProperty_${Property}>}

propertyAccessorDeclarationNext
{, <Coatl_GetUcdProperty_${Property}>}

propertyAccessorDeclarationWrap
{,
	<Coatl_GetUcdProperty_${Property}>}

 propertyAccessor_boolean
{EXTERN int		Coatl_GetUcdProperty_${Property}(Col_Char c);}

propertyAccessor_enum
{EXTERN Coatl_Ucd_${Property}	Coatl_GetUcdProperty_${Property}(Col_Char c);}

propertyAccessor_cp
{EXTERN Col_Char		Coatl_GetUcdProperty_${Property}(Col_Char c);}

propertyAccessor_numeric
{EXTERN const char *	Coatl_GetUcdProperty_${Property}(Col_Char c);}

propertyAccessor_string
{EXTERN const char *	Coatl_GetUcdProperty_${Property}(Col_Char c);}

propertyAccessor_mcp
{EXTERN const int *	Coatl_GetUcdProperty_${Property}(Col_Char c,
			    size_t *lengthPtr);}

propertyAccessor_enumList
{EXTERN const unsigned ${valueType} * Coatl_GetUcdProperty_${Property}(
			    Col_Char c,size_t *lengthPtr);}

propertyAccessorAlias
{
/*---------------------------------------------------------------------------
 * Macro: Coatl_GetUcdProperty_${Alias}
 *
 *	Get value of UCD property '*${alias}*' for given codepoint.
 *	Alias for property UCD property accessor '*${Property}*'
 *
 * Argument:
 *	c	- Codepoint to get UCD property value for.
 *
 * Result:
 *	Value of UCD property '*${alias}*'.
 *
 * See also:
 *	<COATL_UCD_${PROPERTY}>, <Coatl_GetUcdProperty_${Property}>,
 *	<COATL_UCD_${ALIAS}>
 *---------------------------------------------------------------------------*/

 #define Coatl_GetUcdProperty_${Alias}(c) \
    Coatl_GetUcdProperty_${Property}(c)}

propertyAccessorAliasList
{
/*---------------------------------------------------------------------------
 * Macro: Coatl_GetUcdProperty_${Alias}
 *
 *	Get value of UCD property '*${alias}*' for given codepoint.
 *	Alias for property UCD property accessor '*${Property}*'
 *
 * Argument:
 *	c	- Codepoint to get UCD property value for.
 *
 * Results:
 *	Beginning of value list for UCD property '*${property}*'. Additionally:
 *
 *	lengthPtr	- (out) Value list length.
 *
 *	Entries can be safely cast to <Coatl_Ucd_${ElementProperty}>.
 *
 * See also:
 *	<COATL_UCD_${PROPERTY}>, <Coatl_GetUcdProperty_${Property}>,
 *	<COATL_UCD_${ALIAS}>
 *---------------------------------------------------------------------------*/

 #define Coatl_GetUcdProperty_${Alias}(c, lengthPtr) \
    Coatl_GetUcdProperty_${Property}((c), (lengthPtr))}
