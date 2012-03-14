header
{/*
 * File: coatlUcd.c
 *
 *	This file implements Unicode character property data and accessors.
 *
 *	It is automatically generated from the Unicode Character Database (UCD)
 *	using the file *coatlUcd.tcl*; Do not modify.
 */

#include "coatl.h"

#include <limits.h>

/*
 * Prototypes for functions used only in this file.
 */

static size_t		GetRange(Col_Char c, const Col_Char *ranges, 
			    size_t nbRanges);
}

ucdCompiledDataGroup 
{
/****************************************************************************
 * Internal Section: Compiled UCD Data
 *
 *	Statically compiled Unicode Character Database (UCD).
 *
 * Description:
 *	The Unicode Character Database (UCD) defines a set of properties for
 *	every known codepoint in the standard. This represents a huge quantity
 *	of raw data for over one million codepoints. Storing this data as flat
 *	C arrays of high level structures is not realistic, as it would inflate
 *	the size of the compiled binary by tens of megabytes and would 
 *	overburden the client processes' memory.
 *
 *	To solve this problem we compile the UCD in the most compact way 
 *	possible using a combination of techniques:
 *
 *	- Don't store flat arrays of values, but contiguous ranges of values 
 *	that are binary-searched during lookup; as neighboring codepoints in the
 *	UCD often share the same properties, this technique is very efficient.
 *	- Use enums for all enumerated properties to minimize storage (values
 *	fit a single byte in most cases).
 *	- Boolean properties need only the first value since consecutive ranges 
 *	have alternate values.
 *	- Use atom tables for strings and complex datatypes to reuse storage. 
 * 
 *	That way, all but the name properties are statically defined in the
 *	library without too much overhead. By comparison the uncompressed 
 *	textual version of the UCD weighs around 15MB, and the grouped XML 
 *	version around 40MB.
 ****************************************************************************/
}

rangeVar
{/*---------------------------------------------------------------------------
 * Internal Variable: ucdRanges_${property}
 *
 *	Codepoint ranges of values for UCD property '*${property}*'.
 *
 *	Automatically generated from the UCD.
 *
 * See also:
 *	<ucdValues_${property}>, <COATL_UCD_${PROPERTY}>
 *---------------------------------------------------------------------------*/

static const Col_Char ucdRanges_${property}[] = {${ranges}};
}

rangeBooleanVar
{/*---------------------------------------------------------------------------
 * Internal Variable: ucdRanges_${property}
 *
 *	Codepoint ranges of values for UCD property '*${property}*'.
 *
 *	Automatically generated from the UCD.
 *
 * See also:
 *	<UCD_VALUE_0_${PROPERTY}>, <COATL_UCD_${PROPERTY}>
 *---------------------------------------------------------------------------*/

static const Col_Char ucdRanges_${property}[] = {${ranges}};
}

nbRangeConstant
{/*---------------------------------------------------------------------------
 * Internal Constant: UCD_NBRANGES_${PROPERTY}
 *
 *	Number of ranges of values for UCD property '*${property}*'.
 *
 *	Automatically generated from the UCD.
 *
 * See also:
 *	<ucdRanges_${property}>, <COATL_UCD_${PROPERTY}>
 *---------------------------------------------------------------------------*/

#define UCD_NBRANGES_${PROPERTY}	${nbRanges}
}

valueBooleanVar
{/*---------------------------------------------------------------------------
 * Internal Constant: UCD_VALUE_0_${PROPERTY}
 *
 *	Value of first range for UCD property '*${property}*'. 
 *
 *	This property is boolean, so storing the first value is sufficient as
 *	consecutive ranges have alternating values.
 *
 *	Automatically generated from the UCD.
 *
 * See also:
 *	<ucdRanges_${property}>, <COATL_UCD_${PROPERTY}>
 *---------------------------------------------------------------------------*/

#define UCD_VALUE_0_${PROPERTY}	${value0}
}

valueCpVar
{/*---------------------------------------------------------------------------
 * Internal Variable: ucdValues_${property}
 *
 *	Per-range values for UCD property '*${property}*'.
 *
 *	This property is single-codepoint, stored as offsets from the codepoint
 *	value so as to build large ranges of identical values.
 *
 *	Automatically generated from the UCD.
 *
 * See also:
 *	<ucdRanges_${property}>, <COATL_UCD_${PROPERTY}>
 *---------------------------------------------------------------------------*/

static const Col_Char ucdValues_${property}[] = {${values}};
}

valueEnumVar
{/*---------------------------------------------------------------------------
 * Internal Variable: ucdValues_${property}
 *
 *	Per-range values for UCD property '*${property}*'.
 *
 *	Automatically generated from the UCD.
 *
 * See also:
 *	<ucdRanges_${property}>, <COATL_UCD_${PROPERTY}>, <Coatl_Ucd_${Property}>
 *---------------------------------------------------------------------------*/

static const Coatl_Ucd_${Property} ucdValues_${property}[] = {${values}};
}

enumValue
{COATL_UCD_${PROPERTY}_${VALUE}}

valueAtomVar
{/*---------------------------------------------------------------------------
 * Internal Variable: ucdValues_${property}
 *
 *	Per-range atom indices for UCD property '*${property}*'.
 *
 *	This array stores the index of the value in the atom array for each 
 *	range. Atoms are stored in the separate array <ucdAtoms_${property}>. 
 *
 *	Automatically generated from the UCD.
 *
 * See also:
 *	<ucdRanges_${property}>, <ucdAtoms_${property}>, <COATL_UCD_${PROPERTY}>
 *---------------------------------------------------------------------------*/

static const unsigned ${valueType} ucdValues_${property}[] = {${values}};
}

atomVar
{/*---------------------------------------------------------------------------
 * Internal Variable: ucdAtoms_${property}
 *
 *	Atoms for UCD property '*${property}*'.
 *
 *	Automatically generated from the UCD.
 *
 * See also:
 *	<ucdValues_${property}>, <COATL_UCD_${PROPERTY}>
 *---------------------------------------------------------------------------*/

static const ${atomType} ucdAtoms_${property}[] = {${atoms}};
}

atomEnumVar
{/*---------------------------------------------------------------------------
 * Internal Variable: ucdAtoms_${property}
 *
 *	Atoms for UCD property '*${property}*'.
 *
 *	Automatically generated from the UCD.
 *
 * See also:
 *	<ucdValues_${property}>, <COATL_UCD_${PROPERTY}>, <Coatl_Ucd_${ElementProperty}>
 *---------------------------------------------------------------------------*/

static const unsigned ${valueType} ucdAtoms_${property}[] = {${atoms}};
}

atomEnumValue 
{COATL_UCD_${ELEMENT_PROPERTY}_${ENUM_VALUE}}


ucdPropertyAccessorsGroup 
{
/****************************************************************************
 * Section: UCD Property Accessors
 ****************************************************************************/

/*---------------------------------------------------------------------------
 * Internal Function: GetRange
 *
 *	Get the range index containing the given codepoint.
 *
 * Arguments:
 *	c		- Codepoint to lookup.
 *	ranges		- Array of ranges boundaries. First one is omitted 
 *			  (first codepoint is always zero).
 *	nbRanges	- Number of ranges.
 *
 * Result:
 *	Range index.
 *---------------------------------------------------------------------------*/

static size_t 
GetRange(
    Col_Char c, 
    const Col_Char *ranges, 
    size_t nbRanges) 
{
    int min, max;
    if (c < ranges[0] || nbRanges < 2) return 0;
    if (c >= ranges[nbRanges-2]) return nbRanges-1;
    for (min=1, max=nbRanges-1; max-min > 1;) {
	int mid = min+((max-min)>>1);
	if (c < ranges[mid-1]) max = mid;
	else min = mid;
    }
    return min;
}
}

propertyAccessor_boolean
{/*---------------------------------------------------------------------------
 * Function: Coatl_GetUcdProperty_${Property}
 *
 *	Get value of UCD property '*${property}*' for given codepoint.
 *
 * Argument:
 *	c	- Codepoint to get UCD property value for.
 *
 * Result:
 *	Value of UCD property '*${property}*'.
 *
 * See also:
 *	<COATL_UCD_${PROPERTY}>
 *---------------------------------------------------------------------------*/

int
Coatl_GetUcdProperty_${Property}(
    Col_Char c)
{
    return (GetRange(c, ucdRanges_${property}, UCD_NBRANGES_${PROPERTY})%2)
	? !UCD_VALUE_0_${PROPERTY}
	: UCD_VALUE_0_${PROPERTY};
}
}

propertyAccessor_enum
{/*---------------------------------------------------------------------------
 * Function: Coatl_GetUcdProperty_${Property}
 *
 *	Get value of UCD property '*${property}*' for given codepoint.
 *
 * Argument:
 *	c	- Codepoint to get UCD property value for.
 *
 * Results:
 *	Value of UCD property '*${property}*'.
 *
 * See also:
 *	<COATL_UCD_${PROPERTY}>, <Coatl_Ucd_${Property}>
 *---------------------------------------------------------------------------*/

Coatl_Ucd_${Property}
Coatl_GetUcdProperty_${Property}(
    Col_Char c)
{
    return ucdValues_${property}[GetRange(c, ucdRanges_${property}, UCD_NBRANGES_${PROPERTY})];
}
}

propertyAccessor_cp
{/*---------------------------------------------------------------------------
 * Function: Coatl_GetUcdProperty_${Property}
 *
 *	Get value of UCD property '*${property}*' for given codepoint.
 *
 * Argument:
 *	c	- Codepoint to get UCD property value for.
 *
 * Result:
 *	Value of UCD property '*${property}*'.
 *
 * See also:
 *	<COATL_UCD_${PROPERTY}>
 *---------------------------------------------------------------------------*/

Col_Char
Coatl_GetUcdProperty_${Property}(
    Col_Char c)
{
    return c+ucdValues_${property}[GetRange(c, ucdRanges_${property}, UCD_NBRANGES_${PROPERTY})];
}
}

propertyAccessor_numeric
{/*---------------------------------------------------------------------------
 * Function: Coatl_GetUcdProperty_${Property}
 *
 *	Get value of UCD property '*${property}*' for given codepoint.
 *
 * Argument:
 *	c	- Codepoint to get UCD property value for.
 *
 * Result:
 *	Value of UCD property '*${property}*'.
 *
 * See also:
 *	<COATL_UCD_${PROPERTY}>
 *---------------------------------------------------------------------------*/

const char *
Coatl_GetUcdProperty_${Property}(
    Col_Char c)
{
    return ucdAtoms_${property}[ucdValues_${property}[GetRange(c, ucdRanges_${property}, UCD_NBRANGES_${PROPERTY})]];
}
}

propertyAccessor_string
{/*---------------------------------------------------------------------------
 * Function: Coatl_GetUcdProperty_${Property}
 *
 *	Get value of UCD property '*${property}*' for given codepoint.
 *
 * Argument:
 *	c	- Codepoint to get UCD property value for.
 *
 * Result:
 *	Value of UCD property '*${property}*'.
 *
 * See also:
 *	<COATL_UCD_${PROPERTY}>
 *---------------------------------------------------------------------------*/

const char *
Coatl_GetUcdProperty_${Property}(
    Col_Char c)
{
    return ucdAtoms_${property}[ucdValues_${property}[GetRange(c, ucdRanges_${property}, UCD_NBRANGES_${PROPERTY})]];
}
}

propertyAccessor_mcp
{/*---------------------------------------------------------------------------
 * Function: Coatl_GetUcdProperty_${Property}
 *
 *	Get value of UCD property '*${property}*' for given codepoint.
 *
 * Argument:
 *	c	- Codepoint to get UCD property value for.
 *
 * Results:
 *	Beginning of value list for UCD property '*${property}*'. Additionally:
 *
 *	lengthPtr	- (out) Value list length. 
 *
 *	If list length is 1, the first entry gives the offset from the input 
 *	codepoint to get the actual single-value codepoint. Else, list entries
 *	give codepoint values that can be safely cast to Col_Char.
 *
 * See also:
 *	<COATL_UCD_${PROPERTY}>
 *---------------------------------------------------------------------------*/

const int *
Coatl_GetUcdProperty_${Property}(
    Col_Char c,
    size_t *lengthPtr)
{
    const int *first = ucdAtoms_${property} + ucdValues_${property}[GetRange(c, ucdRanges_${property}, UCD_NBRANGES_${PROPERTY})], 
	*last = first;
    while (*last != 0) last++;
    *lengthPtr = last-first;
    return first;
}
}

propertyAccessor_enumList
{/*---------------------------------------------------------------------------
 * Function: Coatl_GetUcdProperty_${Property}
 *
 *	Get value of UCD property '*${property}*' for given codepoint.
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
 *	<COATL_UCD_${PROPERTY}>, <Coatl_Ucd_${ElementProperty}>
 *---------------------------------------------------------------------------*/

const unsigned ${valueType} *
Coatl_GetUcdProperty_${Property}(
    Col_Char c,
    size_t *lengthPtr)
{
    const unsigned ${valueType}
	*first = ucdAtoms_${property} + ucdValues_${property}[GetRange(c, ucdRanges_${property}, UCD_NBRANGES_${PROPERTY})], 
	*last = first;
    while (*last != 0) last++;
    *lengthPtr = last-first;
    return first;
}
}
