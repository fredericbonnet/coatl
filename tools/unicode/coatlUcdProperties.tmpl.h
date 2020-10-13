header 
{/**
 * @file coatlUcdProperties.h
 *
 * This header file describes Unicode character properties and values.
 *
 * It is automatically generated from the Unicode Character Database (UCD) using
 * the file `coatlUcd.tcl`; Do not modify.
 */

#ifndef _COATL_UCDPROPERTIES
#define _COATL_UCDPROPERTIES
}

footer 
{#endif /* _COATL_UCDPROPERTIES */}

ucdPropertiesGroupBegin 
{
/*
===========================================================================*//*!
\weakgroup ucd Unicode Character Database
\{*//*==========================================================================
*/

/***************************************************************************//*!
 * \name UCD Properties
 *
 * Unicode Character Database (UCD) property types & values.
 ***************************************************************************\{*/
}

propertiesEnum 
{/**
 * @enum Coatl_UcdProperty
 *      Unicode character properties.
 *
 *      Names are automatically generated from the UCD file
 *      `PropertyAliases.txt`.
 *${comments} 
 */
 
typedef enum Coatl_UcdProperty {
${values}
} Coatl_UcdProperty;

/**
 * Number of Unicode character properties.
 *
 * @see Coatl_UcdProperty
 */
#define COATL_UCD_NBPROPERTIES  $number
}

propertyAlias
{'**${alias}**'} 

propertiesEnumValueComment 
{
 * @var COATL_UCD_${PROPERTY}
 *      ${aliases}}

propertiesEnumAliasComment 
{
 * @var COATL_UCD_${ALIAS}
 *      Alias for #COATL_UCD_${PROPERTY}}

propertiesEnumValue
{    COATL_UCD_${PROPERTY}=${number},
}

propertiesEnumAlias
{        COATL_UCD_${ALIAS}=COATL_UCD_${PROPERTY},
}

propertyEnum
{/**
 * @enum Coatl_Ucd_${Property}
 *      Values for Unicode character property '**${property}**'.
 *
 *      Names are automatically generated from the UCD file
 *      `PropertyValueAliases.txt`.
 *
 * @see COATL_UCD_${PROPERTY}
 *${comments}
 */
typedef enum Coatl_Ucd_${Property} {
${values}
} Coatl_Ucd_${Property};

/**
 * Number of values for Unicode character property '*${property}*'.
 *
 * @see Coatl_Ucd_${Property}
 */
#define COATL_UCD_${PROPERTY}_NBVALUES${padding} ${number}
}

propertyValueAlias
{'**${alias}**'} 

propertyEnumValueComment 
{
 * @var COATL_UCD_${PROPERTY}_${VALUE}
 *      ${aliases}}

propertyEnumAliasComment 
{
 * @var COATL_UCD_${PROPERTY}_${ALIAS}
 *      Alias for #COATL_UCD_${PROPERTY}_${VALUE}}

propertyEnumValue
{    COATL_UCD_${PROPERTY}_${VALUE}=${number},
}

propertyEnumAlias
{        COATL_UCD_${PROPERTY}_${ALIAS}=COATL_UCD_${PROPERTY}_${VALUE},
}

ucdPropertiesGroupEnd 
{/* End of UCD Properties *//*!\}*/

/* End of Unicode Character Database *//*!\}*/
}
