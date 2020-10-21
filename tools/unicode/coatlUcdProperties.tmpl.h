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
 * Unicode character properties.
 *
 * Names are automatically generated from the UCD file `PropertyAliases.txt`.
 */
typedef enum Coatl_UcdProperty {${values}} Coatl_UcdProperty;

/**
 * Number of Unicode character properties.
 *
 * @see Coatl_UcdProperty
 */
#define COATL_UCD_NBPROPERTIES  $number
}

propertyAlias
{'**${alias}**'} 

propertiesEnumValue
{
    /** ${aliases} */
    COATL_UCD_${PROPERTY}=${number},
}

propertiesEnumAlias
{        /** Alias for #COATL_UCD_${PROPERTY} */
        COATL_UCD_${ALIAS}=COATL_UCD_${PROPERTY},
}

propertyEnum
{/**
 * Values for Unicode character property '**${property}**'.
 *
 * Names are automatically generated from the UCD file 
 * `PropertyValueAliases.txt`.
 *
 * @see COATL_UCD_${PROPERTY}
 */
typedef enum Coatl_Ucd_${Property} {${values}} Coatl_Ucd_${Property};

/**
 * Number of values for Unicode character property '*${property}*'.
 *
 * @see Coatl_Ucd_${Property}
 */
#define COATL_UCD_${PROPERTY}_NBVALUES${padding} ${number}
}

propertyValueAlias
{'**${alias}**'} 

propertyEnumValue
{
    /** ${aliases} */ 
    COATL_UCD_${PROPERTY}_${VALUE}=${number},
}

propertyEnumAlias
{        /** Alias for #COATL_UCD_${PROPERTY}_${VALUE} */
        COATL_UCD_${PROPERTY}_${ALIAS}=COATL_UCD_${PROPERTY}_${VALUE},
}

ucdPropertiesGroupEnd 
{/* End of UCD Properties *//*!\}*/

/* End of Unicode Character Database *//*!\}*/
}
