header 
{/*
 * Header: coatlUcdProperties.h
 *
 *	This header file describes Unicode character properties and values.
 *
 *	It is automatically generated from the Unicode Character Database (UCD)
 *	using the file *coatlUcdProperties.tcl*; Do not modify.
 */

#ifndef _COATL_UCDPROPERTIES
#define _COATL_UCDPROPERTIES
}

footer 
{
#endif /* _COATL_UCDPROPERTIES */}

ucdPropertiesGroup 
{
/****************************************************************************
 * Section: UCD Properties
 *
 *	Unicode Character Database (UCD) property types & values.
 ****************************************************************************/
}

propertiesEnum 
{/*---------------------------------------------------------------------------
 * Enum: Coatl_UcdProperty
 *
 *	Unicode character properties.
 *
 *	Names are automatically generated from the UCD file
 *	*PropertyAliases.txt*
 *${comments} 
 *---------------------------------------------------------------------------*/
 
typedef enum Coatl_UcdProperty {
${values}
} Coatl_UcdProperty;

/*---------------------------------------------------------------------------
 * Constant: COATL_UCD_NBPROPERTIES
 *
 *	Number of Unicode character properties.
 *
 * See also:
 *	<Coatl_UcdProperty>
 *---------------------------------------------------------------------------*/

#define COATL_UCD_NBPROPERTIES	$number
}

propertyAlias
{'*${alias}*'} 

propertiesEnumValueComment 
{
 *  COATL_UCD_${PROPERTY} - ${aliases}}

propertiesEnumAliasComment 
{
 *  COATL_UCD_${ALIAS} - Alias for <COATL_UCD_${PROPERTY}>}

propertiesEnumValue
{    COATL_UCD_${PROPERTY}=${number},
}

propertiesEnumAlias
{	COATL_UCD_${ALIAS}=COATL_UCD_${PROPERTY},
}

propertyEnum
{/*---------------------------------------------------------------------------
 * Enum: Coatl_Ucd_${Property}
 *
 *	Values for Unicode character property '*${property}*'.
 *
 *	Names are automatically generated from the UCD file
 *	*PropertyValueAliases.txt*
 *${comments}
 *
 * See also:
 *	<COATL_UCD_${PROPERTY}>
 *---------------------------------------------------------------------------*/

typedef enum Coatl_Ucd_${Property} {
${values}
} Coatl_Ucd_${Property};

/*---------------------------------------------------------------------------
 * Constant: COATL_UCD_${PROPERTY}_NBVALUES
 *
 *	Number of values for Unicode character property '*${property}*'.
 *
 * See also:
 *	<Coatl_Ucd_${Property}>
 *---------------------------------------------------------------------------*/

#define COATL_UCD_${PROPERTY}_NBVALUES	${number}
}

propertyValueAlias
{'*${alias}*'} 

propertyEnumValueComment 
{
 *  COATL_UCD_${PROPERTY}_${VALUE} - ${aliases}}

propertyEnumAliasComment 
{
 *  COATL_UCD_${PROPERTY}_${ALIAS} - Alias for <COATL_UCD_${PROPERTY}_${VALUE}>}

propertyEnumValue
{    COATL_UCD_${PROPERTY}_${VALUE}=${number},
}

propertyEnumAlias
{	COATL_UCD_${PROPERTY}_${ALIAS}=COATL_UCD_${PROPERTY}_${VALUE},
}

