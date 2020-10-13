header
{/**
 * @file coatlUcd.h
 *
 * This file defines Unicode character property accessors.
 *
 * It is automatically generated from the Unicode Character Database (UCD) using
 * the file `coatlUcd.tcl`; Do not modify.
 */

#ifndef _COATL_UCD
#define _COATL_UCD
}

footer 
{
#endif /* _COATL_UCD */}

ucdPropertyAccessorsGroupBegin
{
/*
===========================================================================*//*!
\defgroup ucd Unicode Character Database
\ingroup unicode
\{*//*==========================================================================
*/

/***************************************************************************//*!
 * \name UCD Property Accessors 
 ***************************************************************************\{*/
}

propertyAccessor_boolean
{EXTERN int              Coatl_GetUcdProperty_${Property}(Col_Char c);}

propertyAccessor_enum
{EXTERN Coatl_Ucd_${Property}${padding} Coatl_GetUcdProperty_${Property}(Col_Char c);}

propertyAccessor_cp
{EXTERN Col_Char         Coatl_GetUcdProperty_${Property}(Col_Char c);}

propertyAccessor_numeric
{EXTERN const char *     Coatl_GetUcdProperty_${Property}(Col_Char c);}

propertyAccessor_string
{EXTERN const char *     Coatl_GetUcdProperty_${Property}(Col_Char c);}

propertyAccessor_mcp
{EXTERN const int *      Coatl_GetUcdProperty_${Property}(Col_Char c,
                            size_t *lengthPtr);}

propertyAccessor_enumList
{EXTERN const unsigned ${valueType} * Coatl_GetUcdProperty_${Property}(
                            Col_Char c,size_t *lengthPtr);}

propertyAccessorAlias
{
/**
 * Get value of UCD property '**${alias}**' for given codepoint.
 * Alias for property UCD property accessor '**${Property}**'
 *
 * @param c Codepoint to get UCD property value for.
 *
 * @return Value of UCD property '**${alias}**'.
 *
 * @see COATL_UCD_${PROPERTY}
 * @see Coatl_GetUcdProperty_${Property}
 * @see COATL_UCD_${ALIAS}
 */
#define Coatl_GetUcdProperty_${Alias}(c) \
    Coatl_GetUcdProperty_${Property}(c)}

propertyAccessorAliasList
{
/**
 * Get value of UCD property '**${alias}**' for given codepoint.
 * Alias for property UCD property accessor '**${Property}**'
 *
 * @param c Codepoint to get UCD property value for.
 *
 * @param[out] lengthPtr    Value list length.
 *
 * @return Beginning of value list for UCD property '**${property}**'. 
 *
 * Entries can be safely cast to <Coatl_Ucd_${ElementProperty}>.
 *
 * @see COATL_UCD_${PROPERTY}
 * @see Coatl_GetUcdProperty_${Property}
 * @see COATL_UCD_${ALIAS}
 */
#define Coatl_GetUcdProperty_${Alias}(c, lengthPtr) \
    Coatl_GetUcdProperty_${Property}((c), (lengthPtr))}

ucdPropertyAccessorsGroupEnd
{
/* End of UCD Property Accessors *//*!\}*/

/* End of Unicode Character Database *//*!\}*/}
