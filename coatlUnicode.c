/*
 * File: coatlUnicode.c
 *
 *	This file implements the Unicode handling features of CoATL.
 *
 * See also:
 *	<coatlUnicode.h>
 */

#include "include/coatl.h"
#include "coatlInternal.h"

#include <limits.h>


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
    return (Coatl_GetUcdProperty_Cased(c) 
	    && Coatl_GetUcdProperty_Simple_Titlecase_Mapping(c) == c);
}

/*---------------------------------------------------------------------------
 * Internal Function: MapRope
 *
 *	Transform rope using a one-to-one character mapping function.
 *
 * Argument:
 *	r	- The rope to transform.
 *	mapProc	- The mapping function.
 *
 * Result:
 *	The transformed rope.
 *---------------------------------------------------------------------------*/

static Col_Word
MapRope(
    Col_Word r,
    Col_Char (*mapProc)(Col_Char))
{
    Col_RopeIterator it, firstUnchanged = COL_ROPEITER_NULL;
    Col_Word strbuf = Col_NewStringBuffer(0, COL_UCS);
    for (Col_RopeIterFirst(r, &it); !Col_RopeIterEnd(&it); 
	    Col_RopeIterNext(&it)) {
	Col_Char c = Col_RopeIterAt(&it);
	Col_Char mc = mapProc(c);
	if (mc == c) {
	    /*
	     * Identity, remember position.
	     */

	    if (Col_RopeIterNull(&firstUnchanged)) firstUnchanged = it;
	    continue;
	}
	if (!Col_RopeIterNull(&firstUnchanged)) {
	    /*
	     * Append unchanged character sequence.
	     */

	    Col_StringBufferAppendSequence(strbuf, &firstUnchanged, &it);
	    firstUnchanged = COL_ROPEITER_NULL;
	}

	/*
	 * Append mapped character.
	 */

	Col_StringBufferAppendChar(strbuf, mc);
    }
    if (!Col_RopeIterNull(&firstUnchanged)) {
	/*
	 * Append unchanged character sequence.
	 */

	ASSERT(Col_RopeIterEnd(&it));
	Col_StringBufferAppendSequence(strbuf, &firstUnchanged, &it);
    }
    return Col_StringBufferFreeze(strbuf);
}

/*---------------------------------------------------------------------------
 * Internal Function: TransformRope
 *
 *	Transform rope using a one-to-many character mapping function.
 *
 * Argument:
 *	r	- The rope to transform.
 *	mapProc	- The mapping function.
 *
 * Result:
 *	The transformed rope.
 *---------------------------------------------------------------------------*/

static Col_Word
TransformRope(
    Col_Word r,
    const int * (*mapProc)(Col_Char, size_t *))
{
    Col_RopeIterator it, firstUnchanged = COL_ROPEITER_NULL;
    Col_Word strbuf = Col_NewStringBuffer(0, COL_UCS);
    for (Col_RopeIterFirst(r, &it); !Col_RopeIterEnd(&it); 
	    Col_RopeIterNext(&it)) {
	Col_Char c = Col_RopeIterAt(&it);
	size_t length;
	const int *lc = mapProc(c, &length);
	if (length == 0 || (length == 1 && *lc == 0)) {
	    /*
	     * Identity, remember position.
	     */

	    if (Col_RopeIterNull(&firstUnchanged)) firstUnchanged = it;
	    continue;
	} 
	if (!Col_RopeIterNull(&firstUnchanged)) {
	    /*
	     * Append unchanged character sequence.
	     */

	    Col_StringBufferAppendSequence(strbuf, &firstUnchanged, &it);
	    firstUnchanged = COL_ROPEITER_NULL;
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
    if (!Col_RopeIterNull(&firstUnchanged)) {
	/*
	 * Append unchanged character sequence.
	 */

	ASSERT(Col_RopeIterEnd(&it));
	Col_StringBufferAppendSequence(strbuf, &firstUnchanged, &it);
    }
    return Col_StringBufferFreeze(strbuf);
}


Col_Word
Coatl_RopeToLowercase(
    Col_Word r,
    int full)
{
    return full ? TransformRope(r, Coatl_GetUcdProperty_Lc)
	    : MapRope(r, Coatl_GetUcdProperty_Slc);
}
Col_Word
Coatl_RopeToUppercase(
    Col_Word r,
    int full)
{
    return full ? TransformRope(r, Coatl_GetUcdProperty_Uc)
	    : MapRope(r, Coatl_GetUcdProperty_Suc);
}
Col_Word
Coatl_RopeToTitlecase(
    Col_Word r,
    int full)
{
    return full ? TransformRope(r, Coatl_GetUcdProperty_Tc)
	    : MapRope(r, Coatl_GetUcdProperty_Stc);
}
Col_Word
Coatl_RopeToCasefold(
    Col_Word r,
    int full)
{
    return full ? TransformRope(r, Coatl_GetUcdProperty_Cf)
	    : MapRope(r, Coatl_GetUcdProperty_Scf);
}

int
Coatl_RopeIsLowercase(
    Col_Word r)
{
    Col_RopeIterator it;
    for (Col_RopeIterFirst(r, &it); !Col_RopeIterEnd(&it); 
	    Col_RopeIterNext(&it)) {
	Col_Char c = Col_RopeIterAt(&it);
	if (Coatl_CharIsCased(c) && !Coatl_CharIsLowercase(c)) return 0;
    }
    return 1;
}
int
Coatl_RopeIsUppercase(
    Col_Word r)
{
    Col_RopeIterator it;
    for (Col_RopeIterFirst(r, &it); !Col_RopeIterEnd(&it); 
	    Col_RopeIterNext(&it)) {
	Col_Char c = Col_RopeIterAt(&it);
	if (Coatl_CharIsCased(c) && !Coatl_CharIsUppercase(c)) return 0;
    }
    return 1;
}
int
Coatl_RopeIsTitlecase(
    Col_Word r)
{
    Col_RopeIterator it;
    for (Col_RopeIterFirst(r, &it); !Col_RopeIterEnd(&it); 
	    Col_RopeIterNext(&it)) {
	Col_Char c = Col_RopeIterAt(&it);
	if (Coatl_CharIsCased(c) && !Coatl_CharIsTitlecase(c)) return 0;
    }
    return 1;
}
int
Coatl_RopeIsCasefolded(
    Col_Word r)
{
    Col_RopeIterator it;
    for (Col_RopeIterFirst(r, &it); !Col_RopeIterEnd(&it); 
	    Col_RopeIterNext(&it)) {
	Col_Char c = Col_RopeIterAt(&it);
//TODO	if (Coatl_CharIsCased(c) && !Coatl_CharIsCasefolded(c)) return 0;
    }
    return 1;
}
int
Coatl_RopeIsCased(
    Col_Word r)
{
    Col_RopeIterator it;
    for (Col_RopeIterFirst(r, &it); !Col_RopeIterEnd(&it); 
	    Col_RopeIterNext(&it)) {
	Col_Char c = Col_RopeIterAt(&it);
	if (Coatl_CharIsCased(c)) return 1;
    }
    return 0;
}
