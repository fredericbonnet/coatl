/*
 * Header: coatlUcd.h
 *
 *	This file defines Unicode character property accessors.
 *
 *	It is automatically generated from the Unicode Character Database (UCD)
 *	using the file *coatlUcd.tcl*; Do not modify.
 */

#ifndef _COATL_UCD
#define _COATL_UCD


/*
================================================================================
Section: UCD Property Accessors

Declarations: 
	<Coatl_GetUcdProperty_Age>, <Coatl_GetUcdProperty_AHex>,
	<Coatl_GetUcdProperty_Alpha>, <Coatl_GetUcdProperty_Bc>,
	<Coatl_GetUcdProperty_Bidi_C>, <Coatl_GetUcdProperty_Bidi_M>,
	<Coatl_GetUcdProperty_Blk>, <Coatl_GetUcdProperty_Bmg>,
	<Coatl_GetUcdProperty_Cased>, <Coatl_GetUcdProperty_Ccc>,
	<Coatl_GetUcdProperty_CE>, <Coatl_GetUcdProperty_Cf>,
	<Coatl_GetUcdProperty_CI>, <Coatl_GetUcdProperty_Comp_Ex>,
	<Coatl_GetUcdProperty_CWCF>, <Coatl_GetUcdProperty_CWCM>,
	<Coatl_GetUcdProperty_CWKCF>, <Coatl_GetUcdProperty_CWL>,
	<Coatl_GetUcdProperty_CWT>, <Coatl_GetUcdProperty_CWU>,
	<Coatl_GetUcdProperty_Dash>, <Coatl_GetUcdProperty_Dep>,
	<Coatl_GetUcdProperty_DI>, <Coatl_GetUcdProperty_Dia>,
	<Coatl_GetUcdProperty_Dm>, <Coatl_GetUcdProperty_Dt>,
	<Coatl_GetUcdProperty_Ea>, <Coatl_GetUcdProperty_Ext>,
	<Coatl_GetUcdProperty_Gc>, <Coatl_GetUcdProperty_GCB>,
	<Coatl_GetUcdProperty_Gr_Base>, <Coatl_GetUcdProperty_Gr_Ext>,
	<Coatl_GetUcdProperty_Hex>, <Coatl_GetUcdProperty_Hst>,
	<Coatl_GetUcdProperty_IDC>, <Coatl_GetUcdProperty_Ideo>,
	<Coatl_GetUcdProperty_IDS>, <Coatl_GetUcdProperty_IDSB>,
	<Coatl_GetUcdProperty_IDST>, <Coatl_GetUcdProperty_InMC>,
	<Coatl_GetUcdProperty_InSC>, <Coatl_GetUcdProperty_Jg>,
	<Coatl_GetUcdProperty_Join_C>, <Coatl_GetUcdProperty_Jt>,
	<Coatl_GetUcdProperty_Lb>, <Coatl_GetUcdProperty_Lc>,
	<Coatl_GetUcdProperty_LOE>, <Coatl_GetUcdProperty_Lower>,
	<Coatl_GetUcdProperty_Math>, <Coatl_GetUcdProperty_NChar>,
	<Coatl_GetUcdProperty_NFC_QC>, <Coatl_GetUcdProperty_NFD_QC>,
	<Coatl_GetUcdProperty_NFKC_CF>, <Coatl_GetUcdProperty_NFKC_QC>,
	<Coatl_GetUcdProperty_NFKD_QC>, <Coatl_GetUcdProperty_Nt>,
	<Coatl_GetUcdProperty_Nv>, <Coatl_GetUcdProperty_OAlpha>,
	<Coatl_GetUcdProperty_ODI>, <Coatl_GetUcdProperty_OGr_Ext>,
	<Coatl_GetUcdProperty_OIDC>, <Coatl_GetUcdProperty_OIDS>,
	<Coatl_GetUcdProperty_OLower>, <Coatl_GetUcdProperty_OMath>,
	<Coatl_GetUcdProperty_OUpper>, <Coatl_GetUcdProperty_Pat_Syn>,
	<Coatl_GetUcdProperty_Pat_WS>, <Coatl_GetUcdProperty_QMark>,
	<Coatl_GetUcdProperty_Radical>, <Coatl_GetUcdProperty_SB>,
	<Coatl_GetUcdProperty_Sc>, <Coatl_GetUcdProperty_Scf>,
	<Coatl_GetUcdProperty_Scx>, <Coatl_GetUcdProperty_SD>,
	<Coatl_GetUcdProperty_Slc>, <Coatl_GetUcdProperty_Stc>,
	<Coatl_GetUcdProperty_STerm>, <Coatl_GetUcdProperty_Suc>,
	<Coatl_GetUcdProperty_Tc>, <Coatl_GetUcdProperty_Term>,
	<Coatl_GetUcdProperty_Uc>, <Coatl_GetUcdProperty_UIdeo>,
	<Coatl_GetUcdProperty_Upper>, <Coatl_GetUcdProperty_VS>,
	<Coatl_GetUcdProperty_WB>, <Coatl_GetUcdProperty_WSpace>,
	<Coatl_GetUcdProperty_XIDC>, <Coatl_GetUcdProperty_XIDS>
================================================================================
*/

EXTERN Coatl_Ucd_Age	Coatl_GetUcdProperty_Age(Col_Char c);
EXTERN int		Coatl_GetUcdProperty_AHex(Col_Char c);
EXTERN int		Coatl_GetUcdProperty_Alpha(Col_Char c);
EXTERN Coatl_Ucd_Bc	Coatl_GetUcdProperty_Bc(Col_Char c);
EXTERN int		Coatl_GetUcdProperty_Bidi_C(Col_Char c);
EXTERN int		Coatl_GetUcdProperty_Bidi_M(Col_Char c);
EXTERN Coatl_Ucd_Blk	Coatl_GetUcdProperty_Blk(Col_Char c);
EXTERN Col_Char		Coatl_GetUcdProperty_Bmg(Col_Char c);
EXTERN int		Coatl_GetUcdProperty_Cased(Col_Char c);
EXTERN Coatl_Ucd_Ccc	Coatl_GetUcdProperty_Ccc(Col_Char c);
EXTERN int		Coatl_GetUcdProperty_CE(Col_Char c);
EXTERN const int *	Coatl_GetUcdProperty_Cf(Col_Char c,
			    size_t *lengthPtr);
EXTERN int		Coatl_GetUcdProperty_CI(Col_Char c);
EXTERN int		Coatl_GetUcdProperty_Comp_Ex(Col_Char c);
EXTERN int		Coatl_GetUcdProperty_CWCF(Col_Char c);
EXTERN int		Coatl_GetUcdProperty_CWCM(Col_Char c);
EXTERN int		Coatl_GetUcdProperty_CWKCF(Col_Char c);
EXTERN int		Coatl_GetUcdProperty_CWL(Col_Char c);
EXTERN int		Coatl_GetUcdProperty_CWT(Col_Char c);
EXTERN int		Coatl_GetUcdProperty_CWU(Col_Char c);
EXTERN int		Coatl_GetUcdProperty_Dash(Col_Char c);
EXTERN int		Coatl_GetUcdProperty_Dep(Col_Char c);
EXTERN int		Coatl_GetUcdProperty_DI(Col_Char c);
EXTERN int		Coatl_GetUcdProperty_Dia(Col_Char c);
EXTERN const int *	Coatl_GetUcdProperty_Dm(Col_Char c,
			    size_t *lengthPtr);
EXTERN Coatl_Ucd_Dt	Coatl_GetUcdProperty_Dt(Col_Char c);
EXTERN Coatl_Ucd_Ea	Coatl_GetUcdProperty_Ea(Col_Char c);
EXTERN int		Coatl_GetUcdProperty_Ext(Col_Char c);
EXTERN Coatl_Ucd_Gc	Coatl_GetUcdProperty_Gc(Col_Char c);
EXTERN Coatl_Ucd_GCB	Coatl_GetUcdProperty_GCB(Col_Char c);
EXTERN int		Coatl_GetUcdProperty_Gr_Base(Col_Char c);
EXTERN int		Coatl_GetUcdProperty_Gr_Ext(Col_Char c);
EXTERN int		Coatl_GetUcdProperty_Hex(Col_Char c);
EXTERN Coatl_Ucd_Hst	Coatl_GetUcdProperty_Hst(Col_Char c);
EXTERN int		Coatl_GetUcdProperty_IDC(Col_Char c);
EXTERN int		Coatl_GetUcdProperty_Ideo(Col_Char c);
EXTERN int		Coatl_GetUcdProperty_IDS(Col_Char c);
EXTERN int		Coatl_GetUcdProperty_IDSB(Col_Char c);
EXTERN int		Coatl_GetUcdProperty_IDST(Col_Char c);
EXTERN Coatl_Ucd_InMC	Coatl_GetUcdProperty_InMC(Col_Char c);
EXTERN Coatl_Ucd_InSC	Coatl_GetUcdProperty_InSC(Col_Char c);
EXTERN Coatl_Ucd_Jg	Coatl_GetUcdProperty_Jg(Col_Char c);
EXTERN int		Coatl_GetUcdProperty_Join_C(Col_Char c);
EXTERN Coatl_Ucd_Jt	Coatl_GetUcdProperty_Jt(Col_Char c);
EXTERN Coatl_Ucd_Lb	Coatl_GetUcdProperty_Lb(Col_Char c);
EXTERN const int *	Coatl_GetUcdProperty_Lc(Col_Char c,
			    size_t *lengthPtr);
EXTERN int		Coatl_GetUcdProperty_LOE(Col_Char c);
EXTERN int		Coatl_GetUcdProperty_Lower(Col_Char c);
EXTERN int		Coatl_GetUcdProperty_Math(Col_Char c);
EXTERN int		Coatl_GetUcdProperty_NChar(Col_Char c);
EXTERN Coatl_Ucd_NFC_QC	Coatl_GetUcdProperty_NFC_QC(Col_Char c);
EXTERN int		Coatl_GetUcdProperty_NFD_QC(Col_Char c);
EXTERN const int *	Coatl_GetUcdProperty_NFKC_CF(Col_Char c,
			    size_t *lengthPtr);
EXTERN Coatl_Ucd_NFKC_QC	Coatl_GetUcdProperty_NFKC_QC(Col_Char c);
EXTERN int		Coatl_GetUcdProperty_NFKD_QC(Col_Char c);
EXTERN Coatl_Ucd_Nt	Coatl_GetUcdProperty_Nt(Col_Char c);
EXTERN const char *	Coatl_GetUcdProperty_Nv(Col_Char c);
EXTERN int		Coatl_GetUcdProperty_OAlpha(Col_Char c);
EXTERN int		Coatl_GetUcdProperty_ODI(Col_Char c);
EXTERN int		Coatl_GetUcdProperty_OGr_Ext(Col_Char c);
EXTERN int		Coatl_GetUcdProperty_OIDC(Col_Char c);
EXTERN int		Coatl_GetUcdProperty_OIDS(Col_Char c);
EXTERN int		Coatl_GetUcdProperty_OLower(Col_Char c);
EXTERN int		Coatl_GetUcdProperty_OMath(Col_Char c);
EXTERN int		Coatl_GetUcdProperty_OUpper(Col_Char c);
EXTERN int		Coatl_GetUcdProperty_Pat_Syn(Col_Char c);
EXTERN int		Coatl_GetUcdProperty_Pat_WS(Col_Char c);
EXTERN int		Coatl_GetUcdProperty_QMark(Col_Char c);
EXTERN int		Coatl_GetUcdProperty_Radical(Col_Char c);
EXTERN Coatl_Ucd_SB	Coatl_GetUcdProperty_SB(Col_Char c);
EXTERN Coatl_Ucd_Sc	Coatl_GetUcdProperty_Sc(Col_Char c);
EXTERN Col_Char		Coatl_GetUcdProperty_Scf(Col_Char c);
EXTERN const unsigned char * Coatl_GetUcdProperty_Scx(
			    Col_Char c,size_t *lengthPtr);
EXTERN int		Coatl_GetUcdProperty_SD(Col_Char c);
EXTERN Col_Char		Coatl_GetUcdProperty_Slc(Col_Char c);
EXTERN Col_Char		Coatl_GetUcdProperty_Stc(Col_Char c);
EXTERN int		Coatl_GetUcdProperty_STerm(Col_Char c);
EXTERN Col_Char		Coatl_GetUcdProperty_Suc(Col_Char c);
EXTERN const int *	Coatl_GetUcdProperty_Tc(Col_Char c,
			    size_t *lengthPtr);
EXTERN int		Coatl_GetUcdProperty_Term(Col_Char c);
EXTERN const int *	Coatl_GetUcdProperty_Uc(Col_Char c,
			    size_t *lengthPtr);
EXTERN int		Coatl_GetUcdProperty_UIdeo(Col_Char c);
EXTERN int		Coatl_GetUcdProperty_Upper(Col_Char c);
EXTERN int		Coatl_GetUcdProperty_VS(Col_Char c);
EXTERN Coatl_Ucd_WB	Coatl_GetUcdProperty_WB(Col_Char c);
EXTERN int		Coatl_GetUcdProperty_WSpace(Col_Char c);
EXTERN int		Coatl_GetUcdProperty_XIDC(Col_Char c);
EXTERN int		Coatl_GetUcdProperty_XIDS(Col_Char c);

/*---------------------------------------------------------------------------
 * Macro: Coatl_GetUcdProperty_ASCII_Hex_Digit
 *
 *	Get value of UCD property '*ASCII_Hex_Digit*' for given codepoint.
 *	Alias for property UCD property accessor '*AHex*'
 *
 * Argument:
 *	c	- Codepoint to get UCD property value for.
 *
 * Result:
 *	Value of UCD property '*ASCII_Hex_Digit*'.
 *
 * See also:
 *	<COATL_UCD_AHEX>, <Coatl_GetUcdProperty_AHex>,
 *	<COATL_UCD_ASCII_HEX_DIGIT>
 *---------------------------------------------------------------------------*/

 #define Coatl_GetUcdProperty_ASCII_Hex_Digit(c) \
    Coatl_GetUcdProperty_AHex(c)

/*---------------------------------------------------------------------------
 * Macro: Coatl_GetUcdProperty_Alphabetic
 *
 *	Get value of UCD property '*Alphabetic*' for given codepoint.
 *	Alias for property UCD property accessor '*Alpha*'
 *
 * Argument:
 *	c	- Codepoint to get UCD property value for.
 *
 * Result:
 *	Value of UCD property '*Alphabetic*'.
 *
 * See also:
 *	<COATL_UCD_ALPHA>, <Coatl_GetUcdProperty_Alpha>,
 *	<COATL_UCD_ALPHABETIC>
 *---------------------------------------------------------------------------*/

 #define Coatl_GetUcdProperty_Alphabetic(c) \
    Coatl_GetUcdProperty_Alpha(c)

/*---------------------------------------------------------------------------
 * Macro: Coatl_GetUcdProperty_Bidi_Class
 *
 *	Get value of UCD property '*Bidi_Class*' for given codepoint.
 *	Alias for property UCD property accessor '*Bc*'
 *
 * Argument:
 *	c	- Codepoint to get UCD property value for.
 *
 * Result:
 *	Value of UCD property '*Bidi_Class*'.
 *
 * See also:
 *	<COATL_UCD_BC>, <Coatl_GetUcdProperty_Bc>,
 *	<COATL_UCD_BIDI_CLASS>
 *---------------------------------------------------------------------------*/

 #define Coatl_GetUcdProperty_Bidi_Class(c) \
    Coatl_GetUcdProperty_Bc(c)

/*---------------------------------------------------------------------------
 * Macro: Coatl_GetUcdProperty_Bidi_Control
 *
 *	Get value of UCD property '*Bidi_Control*' for given codepoint.
 *	Alias for property UCD property accessor '*Bidi_C*'
 *
 * Argument:
 *	c	- Codepoint to get UCD property value for.
 *
 * Result:
 *	Value of UCD property '*Bidi_Control*'.
 *
 * See also:
 *	<COATL_UCD_BIDI_C>, <Coatl_GetUcdProperty_Bidi_C>,
 *	<COATL_UCD_BIDI_CONTROL>
 *---------------------------------------------------------------------------*/

 #define Coatl_GetUcdProperty_Bidi_Control(c) \
    Coatl_GetUcdProperty_Bidi_C(c)

/*---------------------------------------------------------------------------
 * Macro: Coatl_GetUcdProperty_Bidi_Mirrored
 *
 *	Get value of UCD property '*Bidi_Mirrored*' for given codepoint.
 *	Alias for property UCD property accessor '*Bidi_M*'
 *
 * Argument:
 *	c	- Codepoint to get UCD property value for.
 *
 * Result:
 *	Value of UCD property '*Bidi_Mirrored*'.
 *
 * See also:
 *	<COATL_UCD_BIDI_M>, <Coatl_GetUcdProperty_Bidi_M>,
 *	<COATL_UCD_BIDI_MIRRORED>
 *---------------------------------------------------------------------------*/

 #define Coatl_GetUcdProperty_Bidi_Mirrored(c) \
    Coatl_GetUcdProperty_Bidi_M(c)

/*---------------------------------------------------------------------------
 * Macro: Coatl_GetUcdProperty_Block
 *
 *	Get value of UCD property '*Block*' for given codepoint.
 *	Alias for property UCD property accessor '*Blk*'
 *
 * Argument:
 *	c	- Codepoint to get UCD property value for.
 *
 * Result:
 *	Value of UCD property '*Block*'.
 *
 * See also:
 *	<COATL_UCD_BLK>, <Coatl_GetUcdProperty_Blk>,
 *	<COATL_UCD_BLOCK>
 *---------------------------------------------------------------------------*/

 #define Coatl_GetUcdProperty_Block(c) \
    Coatl_GetUcdProperty_Blk(c)

/*---------------------------------------------------------------------------
 * Macro: Coatl_GetUcdProperty_Bidi_Mirroring_Glyph
 *
 *	Get value of UCD property '*Bidi_Mirroring_Glyph*' for given codepoint.
 *	Alias for property UCD property accessor '*Bmg*'
 *
 * Argument:
 *	c	- Codepoint to get UCD property value for.
 *
 * Result:
 *	Value of UCD property '*Bidi_Mirroring_Glyph*'.
 *
 * See also:
 *	<COATL_UCD_BMG>, <Coatl_GetUcdProperty_Bmg>,
 *	<COATL_UCD_BIDI_MIRRORING_GLYPH>
 *---------------------------------------------------------------------------*/

 #define Coatl_GetUcdProperty_Bidi_Mirroring_Glyph(c) \
    Coatl_GetUcdProperty_Bmg(c)

/*---------------------------------------------------------------------------
 * Macro: Coatl_GetUcdProperty_Canonical_Combining_Class
 *
 *	Get value of UCD property '*Canonical_Combining_Class*' for given codepoint.
 *	Alias for property UCD property accessor '*Ccc*'
 *
 * Argument:
 *	c	- Codepoint to get UCD property value for.
 *
 * Result:
 *	Value of UCD property '*Canonical_Combining_Class*'.
 *
 * See also:
 *	<COATL_UCD_CCC>, <Coatl_GetUcdProperty_Ccc>,
 *	<COATL_UCD_CANONICAL_COMBINING_CLASS>
 *---------------------------------------------------------------------------*/

 #define Coatl_GetUcdProperty_Canonical_Combining_Class(c) \
    Coatl_GetUcdProperty_Ccc(c)

/*---------------------------------------------------------------------------
 * Macro: Coatl_GetUcdProperty_Composition_Exclusion
 *
 *	Get value of UCD property '*Composition_Exclusion*' for given codepoint.
 *	Alias for property UCD property accessor '*CE*'
 *
 * Argument:
 *	c	- Codepoint to get UCD property value for.
 *
 * Result:
 *	Value of UCD property '*Composition_Exclusion*'.
 *
 * See also:
 *	<COATL_UCD_CE>, <Coatl_GetUcdProperty_CE>,
 *	<COATL_UCD_COMPOSITION_EXCLUSION>
 *---------------------------------------------------------------------------*/

 #define Coatl_GetUcdProperty_Composition_Exclusion(c) \
    Coatl_GetUcdProperty_CE(c)

/*---------------------------------------------------------------------------
 * Macro: Coatl_GetUcdProperty_Case_Folding
 *
 *	Get value of UCD property '*Case_Folding*' for given codepoint.
 *	Alias for property UCD property accessor '*Cf*'
 *
 * Argument:
 *	c	- Codepoint to get UCD property value for.
 *
 * Result:
 *	Value of UCD property '*Case_Folding*'.
 *
 * See also:
 *	<COATL_UCD_CF>, <Coatl_GetUcdProperty_Cf>,
 *	<COATL_UCD_CASE_FOLDING>
 *---------------------------------------------------------------------------*/

 #define Coatl_GetUcdProperty_Case_Folding(c) \
    Coatl_GetUcdProperty_Cf(c)

/*---------------------------------------------------------------------------
 * Macro: Coatl_GetUcdProperty_Case_Ignorable
 *
 *	Get value of UCD property '*Case_Ignorable*' for given codepoint.
 *	Alias for property UCD property accessor '*CI*'
 *
 * Argument:
 *	c	- Codepoint to get UCD property value for.
 *
 * Result:
 *	Value of UCD property '*Case_Ignorable*'.
 *
 * See also:
 *	<COATL_UCD_CI>, <Coatl_GetUcdProperty_CI>,
 *	<COATL_UCD_CASE_IGNORABLE>
 *---------------------------------------------------------------------------*/

 #define Coatl_GetUcdProperty_Case_Ignorable(c) \
    Coatl_GetUcdProperty_CI(c)

/*---------------------------------------------------------------------------
 * Macro: Coatl_GetUcdProperty_Full_Composition_Exclusion
 *
 *	Get value of UCD property '*Full_Composition_Exclusion*' for given codepoint.
 *	Alias for property UCD property accessor '*Comp_Ex*'
 *
 * Argument:
 *	c	- Codepoint to get UCD property value for.
 *
 * Result:
 *	Value of UCD property '*Full_Composition_Exclusion*'.
 *
 * See also:
 *	<COATL_UCD_COMP_EX>, <Coatl_GetUcdProperty_Comp_Ex>,
 *	<COATL_UCD_FULL_COMPOSITION_EXCLUSION>
 *---------------------------------------------------------------------------*/

 #define Coatl_GetUcdProperty_Full_Composition_Exclusion(c) \
    Coatl_GetUcdProperty_Comp_Ex(c)

/*---------------------------------------------------------------------------
 * Macro: Coatl_GetUcdProperty_Changes_When_Casefolded
 *
 *	Get value of UCD property '*Changes_When_Casefolded*' for given codepoint.
 *	Alias for property UCD property accessor '*CWCF*'
 *
 * Argument:
 *	c	- Codepoint to get UCD property value for.
 *
 * Result:
 *	Value of UCD property '*Changes_When_Casefolded*'.
 *
 * See also:
 *	<COATL_UCD_CWCF>, <Coatl_GetUcdProperty_CWCF>,
 *	<COATL_UCD_CHANGES_WHEN_CASEFOLDED>
 *---------------------------------------------------------------------------*/

 #define Coatl_GetUcdProperty_Changes_When_Casefolded(c) \
    Coatl_GetUcdProperty_CWCF(c)

/*---------------------------------------------------------------------------
 * Macro: Coatl_GetUcdProperty_Changes_When_Casemapped
 *
 *	Get value of UCD property '*Changes_When_Casemapped*' for given codepoint.
 *	Alias for property UCD property accessor '*CWCM*'
 *
 * Argument:
 *	c	- Codepoint to get UCD property value for.
 *
 * Result:
 *	Value of UCD property '*Changes_When_Casemapped*'.
 *
 * See also:
 *	<COATL_UCD_CWCM>, <Coatl_GetUcdProperty_CWCM>,
 *	<COATL_UCD_CHANGES_WHEN_CASEMAPPED>
 *---------------------------------------------------------------------------*/

 #define Coatl_GetUcdProperty_Changes_When_Casemapped(c) \
    Coatl_GetUcdProperty_CWCM(c)

/*---------------------------------------------------------------------------
 * Macro: Coatl_GetUcdProperty_Changes_When_NFKC_Casefolded
 *
 *	Get value of UCD property '*Changes_When_NFKC_Casefolded*' for given codepoint.
 *	Alias for property UCD property accessor '*CWKCF*'
 *
 * Argument:
 *	c	- Codepoint to get UCD property value for.
 *
 * Result:
 *	Value of UCD property '*Changes_When_NFKC_Casefolded*'.
 *
 * See also:
 *	<COATL_UCD_CWKCF>, <Coatl_GetUcdProperty_CWKCF>,
 *	<COATL_UCD_CHANGES_WHEN_NFKC_CASEFOLDED>
 *---------------------------------------------------------------------------*/

 #define Coatl_GetUcdProperty_Changes_When_NFKC_Casefolded(c) \
    Coatl_GetUcdProperty_CWKCF(c)

/*---------------------------------------------------------------------------
 * Macro: Coatl_GetUcdProperty_Changes_When_Lowercased
 *
 *	Get value of UCD property '*Changes_When_Lowercased*' for given codepoint.
 *	Alias for property UCD property accessor '*CWL*'
 *
 * Argument:
 *	c	- Codepoint to get UCD property value for.
 *
 * Result:
 *	Value of UCD property '*Changes_When_Lowercased*'.
 *
 * See also:
 *	<COATL_UCD_CWL>, <Coatl_GetUcdProperty_CWL>,
 *	<COATL_UCD_CHANGES_WHEN_LOWERCASED>
 *---------------------------------------------------------------------------*/

 #define Coatl_GetUcdProperty_Changes_When_Lowercased(c) \
    Coatl_GetUcdProperty_CWL(c)

/*---------------------------------------------------------------------------
 * Macro: Coatl_GetUcdProperty_Changes_When_Titlecased
 *
 *	Get value of UCD property '*Changes_When_Titlecased*' for given codepoint.
 *	Alias for property UCD property accessor '*CWT*'
 *
 * Argument:
 *	c	- Codepoint to get UCD property value for.
 *
 * Result:
 *	Value of UCD property '*Changes_When_Titlecased*'.
 *
 * See also:
 *	<COATL_UCD_CWT>, <Coatl_GetUcdProperty_CWT>,
 *	<COATL_UCD_CHANGES_WHEN_TITLECASED>
 *---------------------------------------------------------------------------*/

 #define Coatl_GetUcdProperty_Changes_When_Titlecased(c) \
    Coatl_GetUcdProperty_CWT(c)

/*---------------------------------------------------------------------------
 * Macro: Coatl_GetUcdProperty_Changes_When_Uppercased
 *
 *	Get value of UCD property '*Changes_When_Uppercased*' for given codepoint.
 *	Alias for property UCD property accessor '*CWU*'
 *
 * Argument:
 *	c	- Codepoint to get UCD property value for.
 *
 * Result:
 *	Value of UCD property '*Changes_When_Uppercased*'.
 *
 * See also:
 *	<COATL_UCD_CWU>, <Coatl_GetUcdProperty_CWU>,
 *	<COATL_UCD_CHANGES_WHEN_UPPERCASED>
 *---------------------------------------------------------------------------*/

 #define Coatl_GetUcdProperty_Changes_When_Uppercased(c) \
    Coatl_GetUcdProperty_CWU(c)

/*---------------------------------------------------------------------------
 * Macro: Coatl_GetUcdProperty_Deprecated
 *
 *	Get value of UCD property '*Deprecated*' for given codepoint.
 *	Alias for property UCD property accessor '*Dep*'
 *
 * Argument:
 *	c	- Codepoint to get UCD property value for.
 *
 * Result:
 *	Value of UCD property '*Deprecated*'.
 *
 * See also:
 *	<COATL_UCD_DEP>, <Coatl_GetUcdProperty_Dep>,
 *	<COATL_UCD_DEPRECATED>
 *---------------------------------------------------------------------------*/

 #define Coatl_GetUcdProperty_Deprecated(c) \
    Coatl_GetUcdProperty_Dep(c)

/*---------------------------------------------------------------------------
 * Macro: Coatl_GetUcdProperty_Default_Ignorable_Code_Point
 *
 *	Get value of UCD property '*Default_Ignorable_Code_Point*' for given codepoint.
 *	Alias for property UCD property accessor '*DI*'
 *
 * Argument:
 *	c	- Codepoint to get UCD property value for.
 *
 * Result:
 *	Value of UCD property '*Default_Ignorable_Code_Point*'.
 *
 * See also:
 *	<COATL_UCD_DI>, <Coatl_GetUcdProperty_DI>,
 *	<COATL_UCD_DEFAULT_IGNORABLE_CODE_POINT>
 *---------------------------------------------------------------------------*/

 #define Coatl_GetUcdProperty_Default_Ignorable_Code_Point(c) \
    Coatl_GetUcdProperty_DI(c)

/*---------------------------------------------------------------------------
 * Macro: Coatl_GetUcdProperty_Diacritic
 *
 *	Get value of UCD property '*Diacritic*' for given codepoint.
 *	Alias for property UCD property accessor '*Dia*'
 *
 * Argument:
 *	c	- Codepoint to get UCD property value for.
 *
 * Result:
 *	Value of UCD property '*Diacritic*'.
 *
 * See also:
 *	<COATL_UCD_DIA>, <Coatl_GetUcdProperty_Dia>,
 *	<COATL_UCD_DIACRITIC>
 *---------------------------------------------------------------------------*/

 #define Coatl_GetUcdProperty_Diacritic(c) \
    Coatl_GetUcdProperty_Dia(c)

/*---------------------------------------------------------------------------
 * Macro: Coatl_GetUcdProperty_Decomposition_Mapping
 *
 *	Get value of UCD property '*Decomposition_Mapping*' for given codepoint.
 *	Alias for property UCD property accessor '*Dm*'
 *
 * Argument:
 *	c	- Codepoint to get UCD property value for.
 *
 * Result:
 *	Value of UCD property '*Decomposition_Mapping*'.
 *
 * See also:
 *	<COATL_UCD_DM>, <Coatl_GetUcdProperty_Dm>,
 *	<COATL_UCD_DECOMPOSITION_MAPPING>
 *---------------------------------------------------------------------------*/

 #define Coatl_GetUcdProperty_Decomposition_Mapping(c) \
    Coatl_GetUcdProperty_Dm(c)

/*---------------------------------------------------------------------------
 * Macro: Coatl_GetUcdProperty_Decomposition_Type
 *
 *	Get value of UCD property '*Decomposition_Type*' for given codepoint.
 *	Alias for property UCD property accessor '*Dt*'
 *
 * Argument:
 *	c	- Codepoint to get UCD property value for.
 *
 * Result:
 *	Value of UCD property '*Decomposition_Type*'.
 *
 * See also:
 *	<COATL_UCD_DT>, <Coatl_GetUcdProperty_Dt>,
 *	<COATL_UCD_DECOMPOSITION_TYPE>
 *---------------------------------------------------------------------------*/

 #define Coatl_GetUcdProperty_Decomposition_Type(c) \
    Coatl_GetUcdProperty_Dt(c)

/*---------------------------------------------------------------------------
 * Macro: Coatl_GetUcdProperty_East_Asian_Width
 *
 *	Get value of UCD property '*East_Asian_Width*' for given codepoint.
 *	Alias for property UCD property accessor '*Ea*'
 *
 * Argument:
 *	c	- Codepoint to get UCD property value for.
 *
 * Result:
 *	Value of UCD property '*East_Asian_Width*'.
 *
 * See also:
 *	<COATL_UCD_EA>, <Coatl_GetUcdProperty_Ea>,
 *	<COATL_UCD_EAST_ASIAN_WIDTH>
 *---------------------------------------------------------------------------*/

 #define Coatl_GetUcdProperty_East_Asian_Width(c) \
    Coatl_GetUcdProperty_Ea(c)

/*---------------------------------------------------------------------------
 * Macro: Coatl_GetUcdProperty_Extender
 *
 *	Get value of UCD property '*Extender*' for given codepoint.
 *	Alias for property UCD property accessor '*Ext*'
 *
 * Argument:
 *	c	- Codepoint to get UCD property value for.
 *
 * Result:
 *	Value of UCD property '*Extender*'.
 *
 * See also:
 *	<COATL_UCD_EXT>, <Coatl_GetUcdProperty_Ext>,
 *	<COATL_UCD_EXTENDER>
 *---------------------------------------------------------------------------*/

 #define Coatl_GetUcdProperty_Extender(c) \
    Coatl_GetUcdProperty_Ext(c)

/*---------------------------------------------------------------------------
 * Macro: Coatl_GetUcdProperty_General_Category
 *
 *	Get value of UCD property '*General_Category*' for given codepoint.
 *	Alias for property UCD property accessor '*Gc*'
 *
 * Argument:
 *	c	- Codepoint to get UCD property value for.
 *
 * Result:
 *	Value of UCD property '*General_Category*'.
 *
 * See also:
 *	<COATL_UCD_GC>, <Coatl_GetUcdProperty_Gc>,
 *	<COATL_UCD_GENERAL_CATEGORY>
 *---------------------------------------------------------------------------*/

 #define Coatl_GetUcdProperty_General_Category(c) \
    Coatl_GetUcdProperty_Gc(c)

/*---------------------------------------------------------------------------
 * Macro: Coatl_GetUcdProperty_Grapheme_Cluster_Break
 *
 *	Get value of UCD property '*Grapheme_Cluster_Break*' for given codepoint.
 *	Alias for property UCD property accessor '*GCB*'
 *
 * Argument:
 *	c	- Codepoint to get UCD property value for.
 *
 * Result:
 *	Value of UCD property '*Grapheme_Cluster_Break*'.
 *
 * See also:
 *	<COATL_UCD_GCB>, <Coatl_GetUcdProperty_GCB>,
 *	<COATL_UCD_GRAPHEME_CLUSTER_BREAK>
 *---------------------------------------------------------------------------*/

 #define Coatl_GetUcdProperty_Grapheme_Cluster_Break(c) \
    Coatl_GetUcdProperty_GCB(c)

/*---------------------------------------------------------------------------
 * Macro: Coatl_GetUcdProperty_Grapheme_Base
 *
 *	Get value of UCD property '*Grapheme_Base*' for given codepoint.
 *	Alias for property UCD property accessor '*Gr_Base*'
 *
 * Argument:
 *	c	- Codepoint to get UCD property value for.
 *
 * Result:
 *	Value of UCD property '*Grapheme_Base*'.
 *
 * See also:
 *	<COATL_UCD_GR_BASE>, <Coatl_GetUcdProperty_Gr_Base>,
 *	<COATL_UCD_GRAPHEME_BASE>
 *---------------------------------------------------------------------------*/

 #define Coatl_GetUcdProperty_Grapheme_Base(c) \
    Coatl_GetUcdProperty_Gr_Base(c)

/*---------------------------------------------------------------------------
 * Macro: Coatl_GetUcdProperty_Grapheme_Extend
 *
 *	Get value of UCD property '*Grapheme_Extend*' for given codepoint.
 *	Alias for property UCD property accessor '*Gr_Ext*'
 *
 * Argument:
 *	c	- Codepoint to get UCD property value for.
 *
 * Result:
 *	Value of UCD property '*Grapheme_Extend*'.
 *
 * See also:
 *	<COATL_UCD_GR_EXT>, <Coatl_GetUcdProperty_Gr_Ext>,
 *	<COATL_UCD_GRAPHEME_EXTEND>
 *---------------------------------------------------------------------------*/

 #define Coatl_GetUcdProperty_Grapheme_Extend(c) \
    Coatl_GetUcdProperty_Gr_Ext(c)

/*---------------------------------------------------------------------------
 * Macro: Coatl_GetUcdProperty_Hex_Digit
 *
 *	Get value of UCD property '*Hex_Digit*' for given codepoint.
 *	Alias for property UCD property accessor '*Hex*'
 *
 * Argument:
 *	c	- Codepoint to get UCD property value for.
 *
 * Result:
 *	Value of UCD property '*Hex_Digit*'.
 *
 * See also:
 *	<COATL_UCD_HEX>, <Coatl_GetUcdProperty_Hex>,
 *	<COATL_UCD_HEX_DIGIT>
 *---------------------------------------------------------------------------*/

 #define Coatl_GetUcdProperty_Hex_Digit(c) \
    Coatl_GetUcdProperty_Hex(c)

/*---------------------------------------------------------------------------
 * Macro: Coatl_GetUcdProperty_Hangul_Syllable_Type
 *
 *	Get value of UCD property '*Hangul_Syllable_Type*' for given codepoint.
 *	Alias for property UCD property accessor '*Hst*'
 *
 * Argument:
 *	c	- Codepoint to get UCD property value for.
 *
 * Result:
 *	Value of UCD property '*Hangul_Syllable_Type*'.
 *
 * See also:
 *	<COATL_UCD_HST>, <Coatl_GetUcdProperty_Hst>,
 *	<COATL_UCD_HANGUL_SYLLABLE_TYPE>
 *---------------------------------------------------------------------------*/

 #define Coatl_GetUcdProperty_Hangul_Syllable_Type(c) \
    Coatl_GetUcdProperty_Hst(c)

/*---------------------------------------------------------------------------
 * Macro: Coatl_GetUcdProperty_ID_Continue
 *
 *	Get value of UCD property '*ID_Continue*' for given codepoint.
 *	Alias for property UCD property accessor '*IDC*'
 *
 * Argument:
 *	c	- Codepoint to get UCD property value for.
 *
 * Result:
 *	Value of UCD property '*ID_Continue*'.
 *
 * See also:
 *	<COATL_UCD_IDC>, <Coatl_GetUcdProperty_IDC>,
 *	<COATL_UCD_ID_CONTINUE>
 *---------------------------------------------------------------------------*/

 #define Coatl_GetUcdProperty_ID_Continue(c) \
    Coatl_GetUcdProperty_IDC(c)

/*---------------------------------------------------------------------------
 * Macro: Coatl_GetUcdProperty_Ideographic
 *
 *	Get value of UCD property '*Ideographic*' for given codepoint.
 *	Alias for property UCD property accessor '*Ideo*'
 *
 * Argument:
 *	c	- Codepoint to get UCD property value for.
 *
 * Result:
 *	Value of UCD property '*Ideographic*'.
 *
 * See also:
 *	<COATL_UCD_IDEO>, <Coatl_GetUcdProperty_Ideo>,
 *	<COATL_UCD_IDEOGRAPHIC>
 *---------------------------------------------------------------------------*/

 #define Coatl_GetUcdProperty_Ideographic(c) \
    Coatl_GetUcdProperty_Ideo(c)

/*---------------------------------------------------------------------------
 * Macro: Coatl_GetUcdProperty_ID_Start
 *
 *	Get value of UCD property '*ID_Start*' for given codepoint.
 *	Alias for property UCD property accessor '*IDS*'
 *
 * Argument:
 *	c	- Codepoint to get UCD property value for.
 *
 * Result:
 *	Value of UCD property '*ID_Start*'.
 *
 * See also:
 *	<COATL_UCD_IDS>, <Coatl_GetUcdProperty_IDS>,
 *	<COATL_UCD_ID_START>
 *---------------------------------------------------------------------------*/

 #define Coatl_GetUcdProperty_ID_Start(c) \
    Coatl_GetUcdProperty_IDS(c)

/*---------------------------------------------------------------------------
 * Macro: Coatl_GetUcdProperty_IDS_Binary_Operator
 *
 *	Get value of UCD property '*IDS_Binary_Operator*' for given codepoint.
 *	Alias for property UCD property accessor '*IDSB*'
 *
 * Argument:
 *	c	- Codepoint to get UCD property value for.
 *
 * Result:
 *	Value of UCD property '*IDS_Binary_Operator*'.
 *
 * See also:
 *	<COATL_UCD_IDSB>, <Coatl_GetUcdProperty_IDSB>,
 *	<COATL_UCD_IDS_BINARY_OPERATOR>
 *---------------------------------------------------------------------------*/

 #define Coatl_GetUcdProperty_IDS_Binary_Operator(c) \
    Coatl_GetUcdProperty_IDSB(c)

/*---------------------------------------------------------------------------
 * Macro: Coatl_GetUcdProperty_IDS_Trinary_Operator
 *
 *	Get value of UCD property '*IDS_Trinary_Operator*' for given codepoint.
 *	Alias for property UCD property accessor '*IDST*'
 *
 * Argument:
 *	c	- Codepoint to get UCD property value for.
 *
 * Result:
 *	Value of UCD property '*IDS_Trinary_Operator*'.
 *
 * See also:
 *	<COATL_UCD_IDST>, <Coatl_GetUcdProperty_IDST>,
 *	<COATL_UCD_IDS_TRINARY_OPERATOR>
 *---------------------------------------------------------------------------*/

 #define Coatl_GetUcdProperty_IDS_Trinary_Operator(c) \
    Coatl_GetUcdProperty_IDST(c)

/*---------------------------------------------------------------------------
 * Macro: Coatl_GetUcdProperty_Indic_Matra_Category
 *
 *	Get value of UCD property '*Indic_Matra_Category*' for given codepoint.
 *	Alias for property UCD property accessor '*InMC*'
 *
 * Argument:
 *	c	- Codepoint to get UCD property value for.
 *
 * Result:
 *	Value of UCD property '*Indic_Matra_Category*'.
 *
 * See also:
 *	<COATL_UCD_INMC>, <Coatl_GetUcdProperty_InMC>,
 *	<COATL_UCD_INDIC_MATRA_CATEGORY>
 *---------------------------------------------------------------------------*/

 #define Coatl_GetUcdProperty_Indic_Matra_Category(c) \
    Coatl_GetUcdProperty_InMC(c)

/*---------------------------------------------------------------------------
 * Macro: Coatl_GetUcdProperty_Indic_Syllabic_Category
 *
 *	Get value of UCD property '*Indic_Syllabic_Category*' for given codepoint.
 *	Alias for property UCD property accessor '*InSC*'
 *
 * Argument:
 *	c	- Codepoint to get UCD property value for.
 *
 * Result:
 *	Value of UCD property '*Indic_Syllabic_Category*'.
 *
 * See also:
 *	<COATL_UCD_INSC>, <Coatl_GetUcdProperty_InSC>,
 *	<COATL_UCD_INDIC_SYLLABIC_CATEGORY>
 *---------------------------------------------------------------------------*/

 #define Coatl_GetUcdProperty_Indic_Syllabic_Category(c) \
    Coatl_GetUcdProperty_InSC(c)

/*---------------------------------------------------------------------------
 * Macro: Coatl_GetUcdProperty_Joining_Group
 *
 *	Get value of UCD property '*Joining_Group*' for given codepoint.
 *	Alias for property UCD property accessor '*Jg*'
 *
 * Argument:
 *	c	- Codepoint to get UCD property value for.
 *
 * Result:
 *	Value of UCD property '*Joining_Group*'.
 *
 * See also:
 *	<COATL_UCD_JG>, <Coatl_GetUcdProperty_Jg>,
 *	<COATL_UCD_JOINING_GROUP>
 *---------------------------------------------------------------------------*/

 #define Coatl_GetUcdProperty_Joining_Group(c) \
    Coatl_GetUcdProperty_Jg(c)

/*---------------------------------------------------------------------------
 * Macro: Coatl_GetUcdProperty_Join_Control
 *
 *	Get value of UCD property '*Join_Control*' for given codepoint.
 *	Alias for property UCD property accessor '*Join_C*'
 *
 * Argument:
 *	c	- Codepoint to get UCD property value for.
 *
 * Result:
 *	Value of UCD property '*Join_Control*'.
 *
 * See also:
 *	<COATL_UCD_JOIN_C>, <Coatl_GetUcdProperty_Join_C>,
 *	<COATL_UCD_JOIN_CONTROL>
 *---------------------------------------------------------------------------*/

 #define Coatl_GetUcdProperty_Join_Control(c) \
    Coatl_GetUcdProperty_Join_C(c)

/*---------------------------------------------------------------------------
 * Macro: Coatl_GetUcdProperty_Joining_Type
 *
 *	Get value of UCD property '*Joining_Type*' for given codepoint.
 *	Alias for property UCD property accessor '*Jt*'
 *
 * Argument:
 *	c	- Codepoint to get UCD property value for.
 *
 * Result:
 *	Value of UCD property '*Joining_Type*'.
 *
 * See also:
 *	<COATL_UCD_JT>, <Coatl_GetUcdProperty_Jt>,
 *	<COATL_UCD_JOINING_TYPE>
 *---------------------------------------------------------------------------*/

 #define Coatl_GetUcdProperty_Joining_Type(c) \
    Coatl_GetUcdProperty_Jt(c)

/*---------------------------------------------------------------------------
 * Macro: Coatl_GetUcdProperty_Line_Break
 *
 *	Get value of UCD property '*Line_Break*' for given codepoint.
 *	Alias for property UCD property accessor '*Lb*'
 *
 * Argument:
 *	c	- Codepoint to get UCD property value for.
 *
 * Result:
 *	Value of UCD property '*Line_Break*'.
 *
 * See also:
 *	<COATL_UCD_LB>, <Coatl_GetUcdProperty_Lb>,
 *	<COATL_UCD_LINE_BREAK>
 *---------------------------------------------------------------------------*/

 #define Coatl_GetUcdProperty_Line_Break(c) \
    Coatl_GetUcdProperty_Lb(c)

/*---------------------------------------------------------------------------
 * Macro: Coatl_GetUcdProperty_Lowercase_Mapping
 *
 *	Get value of UCD property '*Lowercase_Mapping*' for given codepoint.
 *	Alias for property UCD property accessor '*Lc*'
 *
 * Argument:
 *	c	- Codepoint to get UCD property value for.
 *
 * Result:
 *	Value of UCD property '*Lowercase_Mapping*'.
 *
 * See also:
 *	<COATL_UCD_LC>, <Coatl_GetUcdProperty_Lc>,
 *	<COATL_UCD_LOWERCASE_MAPPING>
 *---------------------------------------------------------------------------*/

 #define Coatl_GetUcdProperty_Lowercase_Mapping(c) \
    Coatl_GetUcdProperty_Lc(c)

/*---------------------------------------------------------------------------
 * Macro: Coatl_GetUcdProperty_Logical_Order_Exception
 *
 *	Get value of UCD property '*Logical_Order_Exception*' for given codepoint.
 *	Alias for property UCD property accessor '*LOE*'
 *
 * Argument:
 *	c	- Codepoint to get UCD property value for.
 *
 * Result:
 *	Value of UCD property '*Logical_Order_Exception*'.
 *
 * See also:
 *	<COATL_UCD_LOE>, <Coatl_GetUcdProperty_LOE>,
 *	<COATL_UCD_LOGICAL_ORDER_EXCEPTION>
 *---------------------------------------------------------------------------*/

 #define Coatl_GetUcdProperty_Logical_Order_Exception(c) \
    Coatl_GetUcdProperty_LOE(c)

/*---------------------------------------------------------------------------
 * Macro: Coatl_GetUcdProperty_Lowercase
 *
 *	Get value of UCD property '*Lowercase*' for given codepoint.
 *	Alias for property UCD property accessor '*Lower*'
 *
 * Argument:
 *	c	- Codepoint to get UCD property value for.
 *
 * Result:
 *	Value of UCD property '*Lowercase*'.
 *
 * See also:
 *	<COATL_UCD_LOWER>, <Coatl_GetUcdProperty_Lower>,
 *	<COATL_UCD_LOWERCASE>
 *---------------------------------------------------------------------------*/

 #define Coatl_GetUcdProperty_Lowercase(c) \
    Coatl_GetUcdProperty_Lower(c)

/*---------------------------------------------------------------------------
 * Macro: Coatl_GetUcdProperty_Noncharacter_Code_Point
 *
 *	Get value of UCD property '*Noncharacter_Code_Point*' for given codepoint.
 *	Alias for property UCD property accessor '*NChar*'
 *
 * Argument:
 *	c	- Codepoint to get UCD property value for.
 *
 * Result:
 *	Value of UCD property '*Noncharacter_Code_Point*'.
 *
 * See also:
 *	<COATL_UCD_NCHAR>, <Coatl_GetUcdProperty_NChar>,
 *	<COATL_UCD_NONCHARACTER_CODE_POINT>
 *---------------------------------------------------------------------------*/

 #define Coatl_GetUcdProperty_Noncharacter_Code_Point(c) \
    Coatl_GetUcdProperty_NChar(c)

/*---------------------------------------------------------------------------
 * Macro: Coatl_GetUcdProperty_NFC_Quick_Check
 *
 *	Get value of UCD property '*NFC_Quick_Check*' for given codepoint.
 *	Alias for property UCD property accessor '*NFC_QC*'
 *
 * Argument:
 *	c	- Codepoint to get UCD property value for.
 *
 * Result:
 *	Value of UCD property '*NFC_Quick_Check*'.
 *
 * See also:
 *	<COATL_UCD_NFC_QC>, <Coatl_GetUcdProperty_NFC_QC>,
 *	<COATL_UCD_NFC_QUICK_CHECK>
 *---------------------------------------------------------------------------*/

 #define Coatl_GetUcdProperty_NFC_Quick_Check(c) \
    Coatl_GetUcdProperty_NFC_QC(c)

/*---------------------------------------------------------------------------
 * Macro: Coatl_GetUcdProperty_NFD_Quick_Check
 *
 *	Get value of UCD property '*NFD_Quick_Check*' for given codepoint.
 *	Alias for property UCD property accessor '*NFD_QC*'
 *
 * Argument:
 *	c	- Codepoint to get UCD property value for.
 *
 * Result:
 *	Value of UCD property '*NFD_Quick_Check*'.
 *
 * See also:
 *	<COATL_UCD_NFD_QC>, <Coatl_GetUcdProperty_NFD_QC>,
 *	<COATL_UCD_NFD_QUICK_CHECK>
 *---------------------------------------------------------------------------*/

 #define Coatl_GetUcdProperty_NFD_Quick_Check(c) \
    Coatl_GetUcdProperty_NFD_QC(c)

/*---------------------------------------------------------------------------
 * Macro: Coatl_GetUcdProperty_NFKC_Casefold
 *
 *	Get value of UCD property '*NFKC_Casefold*' for given codepoint.
 *	Alias for property UCD property accessor '*NFKC_CF*'
 *
 * Argument:
 *	c	- Codepoint to get UCD property value for.
 *
 * Result:
 *	Value of UCD property '*NFKC_Casefold*'.
 *
 * See also:
 *	<COATL_UCD_NFKC_CF>, <Coatl_GetUcdProperty_NFKC_CF>,
 *	<COATL_UCD_NFKC_CASEFOLD>
 *---------------------------------------------------------------------------*/

 #define Coatl_GetUcdProperty_NFKC_Casefold(c) \
    Coatl_GetUcdProperty_NFKC_CF(c)

/*---------------------------------------------------------------------------
 * Macro: Coatl_GetUcdProperty_NFKC_Quick_Check
 *
 *	Get value of UCD property '*NFKC_Quick_Check*' for given codepoint.
 *	Alias for property UCD property accessor '*NFKC_QC*'
 *
 * Argument:
 *	c	- Codepoint to get UCD property value for.
 *
 * Result:
 *	Value of UCD property '*NFKC_Quick_Check*'.
 *
 * See also:
 *	<COATL_UCD_NFKC_QC>, <Coatl_GetUcdProperty_NFKC_QC>,
 *	<COATL_UCD_NFKC_QUICK_CHECK>
 *---------------------------------------------------------------------------*/

 #define Coatl_GetUcdProperty_NFKC_Quick_Check(c) \
    Coatl_GetUcdProperty_NFKC_QC(c)

/*---------------------------------------------------------------------------
 * Macro: Coatl_GetUcdProperty_NFKD_Quick_Check
 *
 *	Get value of UCD property '*NFKD_Quick_Check*' for given codepoint.
 *	Alias for property UCD property accessor '*NFKD_QC*'
 *
 * Argument:
 *	c	- Codepoint to get UCD property value for.
 *
 * Result:
 *	Value of UCD property '*NFKD_Quick_Check*'.
 *
 * See also:
 *	<COATL_UCD_NFKD_QC>, <Coatl_GetUcdProperty_NFKD_QC>,
 *	<COATL_UCD_NFKD_QUICK_CHECK>
 *---------------------------------------------------------------------------*/

 #define Coatl_GetUcdProperty_NFKD_Quick_Check(c) \
    Coatl_GetUcdProperty_NFKD_QC(c)

/*---------------------------------------------------------------------------
 * Macro: Coatl_GetUcdProperty_Numeric_Type
 *
 *	Get value of UCD property '*Numeric_Type*' for given codepoint.
 *	Alias for property UCD property accessor '*Nt*'
 *
 * Argument:
 *	c	- Codepoint to get UCD property value for.
 *
 * Result:
 *	Value of UCD property '*Numeric_Type*'.
 *
 * See also:
 *	<COATL_UCD_NT>, <Coatl_GetUcdProperty_Nt>,
 *	<COATL_UCD_NUMERIC_TYPE>
 *---------------------------------------------------------------------------*/

 #define Coatl_GetUcdProperty_Numeric_Type(c) \
    Coatl_GetUcdProperty_Nt(c)

/*---------------------------------------------------------------------------
 * Macro: Coatl_GetUcdProperty_Numeric_Value
 *
 *	Get value of UCD property '*Numeric_Value*' for given codepoint.
 *	Alias for property UCD property accessor '*Nv*'
 *
 * Argument:
 *	c	- Codepoint to get UCD property value for.
 *
 * Result:
 *	Value of UCD property '*Numeric_Value*'.
 *
 * See also:
 *	<COATL_UCD_NV>, <Coatl_GetUcdProperty_Nv>,
 *	<COATL_UCD_NUMERIC_VALUE>
 *---------------------------------------------------------------------------*/

 #define Coatl_GetUcdProperty_Numeric_Value(c) \
    Coatl_GetUcdProperty_Nv(c)

/*---------------------------------------------------------------------------
 * Macro: Coatl_GetUcdProperty_Other_Alphabetic
 *
 *	Get value of UCD property '*Other_Alphabetic*' for given codepoint.
 *	Alias for property UCD property accessor '*OAlpha*'
 *
 * Argument:
 *	c	- Codepoint to get UCD property value for.
 *
 * Result:
 *	Value of UCD property '*Other_Alphabetic*'.
 *
 * See also:
 *	<COATL_UCD_OALPHA>, <Coatl_GetUcdProperty_OAlpha>,
 *	<COATL_UCD_OTHER_ALPHABETIC>
 *---------------------------------------------------------------------------*/

 #define Coatl_GetUcdProperty_Other_Alphabetic(c) \
    Coatl_GetUcdProperty_OAlpha(c)

/*---------------------------------------------------------------------------
 * Macro: Coatl_GetUcdProperty_Other_Default_Ignorable_Code_Point
 *
 *	Get value of UCD property '*Other_Default_Ignorable_Code_Point*' for given codepoint.
 *	Alias for property UCD property accessor '*ODI*'
 *
 * Argument:
 *	c	- Codepoint to get UCD property value for.
 *
 * Result:
 *	Value of UCD property '*Other_Default_Ignorable_Code_Point*'.
 *
 * See also:
 *	<COATL_UCD_ODI>, <Coatl_GetUcdProperty_ODI>,
 *	<COATL_UCD_OTHER_DEFAULT_IGNORABLE_CODE_POINT>
 *---------------------------------------------------------------------------*/

 #define Coatl_GetUcdProperty_Other_Default_Ignorable_Code_Point(c) \
    Coatl_GetUcdProperty_ODI(c)

/*---------------------------------------------------------------------------
 * Macro: Coatl_GetUcdProperty_Other_Grapheme_Extend
 *
 *	Get value of UCD property '*Other_Grapheme_Extend*' for given codepoint.
 *	Alias for property UCD property accessor '*OGr_Ext*'
 *
 * Argument:
 *	c	- Codepoint to get UCD property value for.
 *
 * Result:
 *	Value of UCD property '*Other_Grapheme_Extend*'.
 *
 * See also:
 *	<COATL_UCD_OGR_EXT>, <Coatl_GetUcdProperty_OGr_Ext>,
 *	<COATL_UCD_OTHER_GRAPHEME_EXTEND>
 *---------------------------------------------------------------------------*/

 #define Coatl_GetUcdProperty_Other_Grapheme_Extend(c) \
    Coatl_GetUcdProperty_OGr_Ext(c)

/*---------------------------------------------------------------------------
 * Macro: Coatl_GetUcdProperty_Other_ID_Continue
 *
 *	Get value of UCD property '*Other_ID_Continue*' for given codepoint.
 *	Alias for property UCD property accessor '*OIDC*'
 *
 * Argument:
 *	c	- Codepoint to get UCD property value for.
 *
 * Result:
 *	Value of UCD property '*Other_ID_Continue*'.
 *
 * See also:
 *	<COATL_UCD_OIDC>, <Coatl_GetUcdProperty_OIDC>,
 *	<COATL_UCD_OTHER_ID_CONTINUE>
 *---------------------------------------------------------------------------*/

 #define Coatl_GetUcdProperty_Other_ID_Continue(c) \
    Coatl_GetUcdProperty_OIDC(c)

/*---------------------------------------------------------------------------
 * Macro: Coatl_GetUcdProperty_Other_ID_Start
 *
 *	Get value of UCD property '*Other_ID_Start*' for given codepoint.
 *	Alias for property UCD property accessor '*OIDS*'
 *
 * Argument:
 *	c	- Codepoint to get UCD property value for.
 *
 * Result:
 *	Value of UCD property '*Other_ID_Start*'.
 *
 * See also:
 *	<COATL_UCD_OIDS>, <Coatl_GetUcdProperty_OIDS>,
 *	<COATL_UCD_OTHER_ID_START>
 *---------------------------------------------------------------------------*/

 #define Coatl_GetUcdProperty_Other_ID_Start(c) \
    Coatl_GetUcdProperty_OIDS(c)

/*---------------------------------------------------------------------------
 * Macro: Coatl_GetUcdProperty_Other_Lowercase
 *
 *	Get value of UCD property '*Other_Lowercase*' for given codepoint.
 *	Alias for property UCD property accessor '*OLower*'
 *
 * Argument:
 *	c	- Codepoint to get UCD property value for.
 *
 * Result:
 *	Value of UCD property '*Other_Lowercase*'.
 *
 * See also:
 *	<COATL_UCD_OLOWER>, <Coatl_GetUcdProperty_OLower>,
 *	<COATL_UCD_OTHER_LOWERCASE>
 *---------------------------------------------------------------------------*/

 #define Coatl_GetUcdProperty_Other_Lowercase(c) \
    Coatl_GetUcdProperty_OLower(c)

/*---------------------------------------------------------------------------
 * Macro: Coatl_GetUcdProperty_Other_Math
 *
 *	Get value of UCD property '*Other_Math*' for given codepoint.
 *	Alias for property UCD property accessor '*OMath*'
 *
 * Argument:
 *	c	- Codepoint to get UCD property value for.
 *
 * Result:
 *	Value of UCD property '*Other_Math*'.
 *
 * See also:
 *	<COATL_UCD_OMATH>, <Coatl_GetUcdProperty_OMath>,
 *	<COATL_UCD_OTHER_MATH>
 *---------------------------------------------------------------------------*/

 #define Coatl_GetUcdProperty_Other_Math(c) \
    Coatl_GetUcdProperty_OMath(c)

/*---------------------------------------------------------------------------
 * Macro: Coatl_GetUcdProperty_Other_Uppercase
 *
 *	Get value of UCD property '*Other_Uppercase*' for given codepoint.
 *	Alias for property UCD property accessor '*OUpper*'
 *
 * Argument:
 *	c	- Codepoint to get UCD property value for.
 *
 * Result:
 *	Value of UCD property '*Other_Uppercase*'.
 *
 * See also:
 *	<COATL_UCD_OUPPER>, <Coatl_GetUcdProperty_OUpper>,
 *	<COATL_UCD_OTHER_UPPERCASE>
 *---------------------------------------------------------------------------*/

 #define Coatl_GetUcdProperty_Other_Uppercase(c) \
    Coatl_GetUcdProperty_OUpper(c)

/*---------------------------------------------------------------------------
 * Macro: Coatl_GetUcdProperty_Pattern_Syntax
 *
 *	Get value of UCD property '*Pattern_Syntax*' for given codepoint.
 *	Alias for property UCD property accessor '*Pat_Syn*'
 *
 * Argument:
 *	c	- Codepoint to get UCD property value for.
 *
 * Result:
 *	Value of UCD property '*Pattern_Syntax*'.
 *
 * See also:
 *	<COATL_UCD_PAT_SYN>, <Coatl_GetUcdProperty_Pat_Syn>,
 *	<COATL_UCD_PATTERN_SYNTAX>
 *---------------------------------------------------------------------------*/

 #define Coatl_GetUcdProperty_Pattern_Syntax(c) \
    Coatl_GetUcdProperty_Pat_Syn(c)

/*---------------------------------------------------------------------------
 * Macro: Coatl_GetUcdProperty_Pattern_White_Space
 *
 *	Get value of UCD property '*Pattern_White_Space*' for given codepoint.
 *	Alias for property UCD property accessor '*Pat_WS*'
 *
 * Argument:
 *	c	- Codepoint to get UCD property value for.
 *
 * Result:
 *	Value of UCD property '*Pattern_White_Space*'.
 *
 * See also:
 *	<COATL_UCD_PAT_WS>, <Coatl_GetUcdProperty_Pat_WS>,
 *	<COATL_UCD_PATTERN_WHITE_SPACE>
 *---------------------------------------------------------------------------*/

 #define Coatl_GetUcdProperty_Pattern_White_Space(c) \
    Coatl_GetUcdProperty_Pat_WS(c)

/*---------------------------------------------------------------------------
 * Macro: Coatl_GetUcdProperty_Quotation_Mark
 *
 *	Get value of UCD property '*Quotation_Mark*' for given codepoint.
 *	Alias for property UCD property accessor '*QMark*'
 *
 * Argument:
 *	c	- Codepoint to get UCD property value for.
 *
 * Result:
 *	Value of UCD property '*Quotation_Mark*'.
 *
 * See also:
 *	<COATL_UCD_QMARK>, <Coatl_GetUcdProperty_QMark>,
 *	<COATL_UCD_QUOTATION_MARK>
 *---------------------------------------------------------------------------*/

 #define Coatl_GetUcdProperty_Quotation_Mark(c) \
    Coatl_GetUcdProperty_QMark(c)

/*---------------------------------------------------------------------------
 * Macro: Coatl_GetUcdProperty_Sentence_Break
 *
 *	Get value of UCD property '*Sentence_Break*' for given codepoint.
 *	Alias for property UCD property accessor '*SB*'
 *
 * Argument:
 *	c	- Codepoint to get UCD property value for.
 *
 * Result:
 *	Value of UCD property '*Sentence_Break*'.
 *
 * See also:
 *	<COATL_UCD_SB>, <Coatl_GetUcdProperty_SB>,
 *	<COATL_UCD_SENTENCE_BREAK>
 *---------------------------------------------------------------------------*/

 #define Coatl_GetUcdProperty_Sentence_Break(c) \
    Coatl_GetUcdProperty_SB(c)

/*---------------------------------------------------------------------------
 * Macro: Coatl_GetUcdProperty_Script
 *
 *	Get value of UCD property '*Script*' for given codepoint.
 *	Alias for property UCD property accessor '*Sc*'
 *
 * Argument:
 *	c	- Codepoint to get UCD property value for.
 *
 * Result:
 *	Value of UCD property '*Script*'.
 *
 * See also:
 *	<COATL_UCD_SC>, <Coatl_GetUcdProperty_Sc>,
 *	<COATL_UCD_SCRIPT>
 *---------------------------------------------------------------------------*/

 #define Coatl_GetUcdProperty_Script(c) \
    Coatl_GetUcdProperty_Sc(c)

/*---------------------------------------------------------------------------
 * Macro: Coatl_GetUcdProperty_Simple_Case_Folding
 *
 *	Get value of UCD property '*Simple_Case_Folding*' for given codepoint.
 *	Alias for property UCD property accessor '*Scf*'
 *
 * Argument:
 *	c	- Codepoint to get UCD property value for.
 *
 * Result:
 *	Value of UCD property '*Simple_Case_Folding*'.
 *
 * See also:
 *	<COATL_UCD_SCF>, <Coatl_GetUcdProperty_Scf>,
 *	<COATL_UCD_SIMPLE_CASE_FOLDING>
 *---------------------------------------------------------------------------*/

 #define Coatl_GetUcdProperty_Simple_Case_Folding(c) \
    Coatl_GetUcdProperty_Scf(c)

/*---------------------------------------------------------------------------
 * Macro: Coatl_GetUcdProperty_Sfc
 *
 *	Get value of UCD property '*sfc*' for given codepoint.
 *	Alias for property UCD property accessor '*Scf*'
 *
 * Argument:
 *	c	- Codepoint to get UCD property value for.
 *
 * Result:
 *	Value of UCD property '*sfc*'.
 *
 * See also:
 *	<COATL_UCD_SCF>, <Coatl_GetUcdProperty_Scf>,
 *	<COATL_UCD_SFC>
 *---------------------------------------------------------------------------*/

 #define Coatl_GetUcdProperty_Sfc(c) \
    Coatl_GetUcdProperty_Scf(c)

/*---------------------------------------------------------------------------
 * Macro: Coatl_GetUcdProperty_Script_Extensions
 *
 *	Get value of UCD property '*Script_Extensions*' for given codepoint.
 *	Alias for property UCD property accessor '*Scx*'
 *
 * Argument:
 *	c	- Codepoint to get UCD property value for.
 *
 * Result:
 *	Value of UCD property '*Script_Extensions*'.
 *
 * See also:
 *	<COATL_UCD_SCX>, <Coatl_GetUcdProperty_Scx>,
 *	<COATL_UCD_SCRIPT_EXTENSIONS>
 *---------------------------------------------------------------------------*/

 #define Coatl_GetUcdProperty_Script_Extensions(c) \
    Coatl_GetUcdProperty_Scx(c)

/*---------------------------------------------------------------------------
 * Macro: Coatl_GetUcdProperty_Soft_Dotted
 *
 *	Get value of UCD property '*Soft_Dotted*' for given codepoint.
 *	Alias for property UCD property accessor '*SD*'
 *
 * Argument:
 *	c	- Codepoint to get UCD property value for.
 *
 * Result:
 *	Value of UCD property '*Soft_Dotted*'.
 *
 * See also:
 *	<COATL_UCD_SD>, <Coatl_GetUcdProperty_SD>,
 *	<COATL_UCD_SOFT_DOTTED>
 *---------------------------------------------------------------------------*/

 #define Coatl_GetUcdProperty_Soft_Dotted(c) \
    Coatl_GetUcdProperty_SD(c)

/*---------------------------------------------------------------------------
 * Macro: Coatl_GetUcdProperty_Simple_Lowercase_Mapping
 *
 *	Get value of UCD property '*Simple_Lowercase_Mapping*' for given codepoint.
 *	Alias for property UCD property accessor '*Slc*'
 *
 * Argument:
 *	c	- Codepoint to get UCD property value for.
 *
 * Result:
 *	Value of UCD property '*Simple_Lowercase_Mapping*'.
 *
 * See also:
 *	<COATL_UCD_SLC>, <Coatl_GetUcdProperty_Slc>,
 *	<COATL_UCD_SIMPLE_LOWERCASE_MAPPING>
 *---------------------------------------------------------------------------*/

 #define Coatl_GetUcdProperty_Simple_Lowercase_Mapping(c) \
    Coatl_GetUcdProperty_Slc(c)

/*---------------------------------------------------------------------------
 * Macro: Coatl_GetUcdProperty_Simple_Titlecase_Mapping
 *
 *	Get value of UCD property '*Simple_Titlecase_Mapping*' for given codepoint.
 *	Alias for property UCD property accessor '*Stc*'
 *
 * Argument:
 *	c	- Codepoint to get UCD property value for.
 *
 * Result:
 *	Value of UCD property '*Simple_Titlecase_Mapping*'.
 *
 * See also:
 *	<COATL_UCD_STC>, <Coatl_GetUcdProperty_Stc>,
 *	<COATL_UCD_SIMPLE_TITLECASE_MAPPING>
 *---------------------------------------------------------------------------*/

 #define Coatl_GetUcdProperty_Simple_Titlecase_Mapping(c) \
    Coatl_GetUcdProperty_Stc(c)

/*---------------------------------------------------------------------------
 * Macro: Coatl_GetUcdProperty_Simple_Uppercase_Mapping
 *
 *	Get value of UCD property '*Simple_Uppercase_Mapping*' for given codepoint.
 *	Alias for property UCD property accessor '*Suc*'
 *
 * Argument:
 *	c	- Codepoint to get UCD property value for.
 *
 * Result:
 *	Value of UCD property '*Simple_Uppercase_Mapping*'.
 *
 * See also:
 *	<COATL_UCD_SUC>, <Coatl_GetUcdProperty_Suc>,
 *	<COATL_UCD_SIMPLE_UPPERCASE_MAPPING>
 *---------------------------------------------------------------------------*/

 #define Coatl_GetUcdProperty_Simple_Uppercase_Mapping(c) \
    Coatl_GetUcdProperty_Suc(c)

/*---------------------------------------------------------------------------
 * Macro: Coatl_GetUcdProperty_Titlecase_Mapping
 *
 *	Get value of UCD property '*Titlecase_Mapping*' for given codepoint.
 *	Alias for property UCD property accessor '*Tc*'
 *
 * Argument:
 *	c	- Codepoint to get UCD property value for.
 *
 * Result:
 *	Value of UCD property '*Titlecase_Mapping*'.
 *
 * See also:
 *	<COATL_UCD_TC>, <Coatl_GetUcdProperty_Tc>,
 *	<COATL_UCD_TITLECASE_MAPPING>
 *---------------------------------------------------------------------------*/

 #define Coatl_GetUcdProperty_Titlecase_Mapping(c) \
    Coatl_GetUcdProperty_Tc(c)

/*---------------------------------------------------------------------------
 * Macro: Coatl_GetUcdProperty_Terminal_Punctuation
 *
 *	Get value of UCD property '*Terminal_Punctuation*' for given codepoint.
 *	Alias for property UCD property accessor '*Term*'
 *
 * Argument:
 *	c	- Codepoint to get UCD property value for.
 *
 * Result:
 *	Value of UCD property '*Terminal_Punctuation*'.
 *
 * See also:
 *	<COATL_UCD_TERM>, <Coatl_GetUcdProperty_Term>,
 *	<COATL_UCD_TERMINAL_PUNCTUATION>
 *---------------------------------------------------------------------------*/

 #define Coatl_GetUcdProperty_Terminal_Punctuation(c) \
    Coatl_GetUcdProperty_Term(c)

/*---------------------------------------------------------------------------
 * Macro: Coatl_GetUcdProperty_Uppercase_Mapping
 *
 *	Get value of UCD property '*Uppercase_Mapping*' for given codepoint.
 *	Alias for property UCD property accessor '*Uc*'
 *
 * Argument:
 *	c	- Codepoint to get UCD property value for.
 *
 * Result:
 *	Value of UCD property '*Uppercase_Mapping*'.
 *
 * See also:
 *	<COATL_UCD_UC>, <Coatl_GetUcdProperty_Uc>,
 *	<COATL_UCD_UPPERCASE_MAPPING>
 *---------------------------------------------------------------------------*/

 #define Coatl_GetUcdProperty_Uppercase_Mapping(c) \
    Coatl_GetUcdProperty_Uc(c)

/*---------------------------------------------------------------------------
 * Macro: Coatl_GetUcdProperty_Unified_Ideograph
 *
 *	Get value of UCD property '*Unified_Ideograph*' for given codepoint.
 *	Alias for property UCD property accessor '*UIdeo*'
 *
 * Argument:
 *	c	- Codepoint to get UCD property value for.
 *
 * Result:
 *	Value of UCD property '*Unified_Ideograph*'.
 *
 * See also:
 *	<COATL_UCD_UIDEO>, <Coatl_GetUcdProperty_UIdeo>,
 *	<COATL_UCD_UNIFIED_IDEOGRAPH>
 *---------------------------------------------------------------------------*/

 #define Coatl_GetUcdProperty_Unified_Ideograph(c) \
    Coatl_GetUcdProperty_UIdeo(c)

/*---------------------------------------------------------------------------
 * Macro: Coatl_GetUcdProperty_Uppercase
 *
 *	Get value of UCD property '*Uppercase*' for given codepoint.
 *	Alias for property UCD property accessor '*Upper*'
 *
 * Argument:
 *	c	- Codepoint to get UCD property value for.
 *
 * Result:
 *	Value of UCD property '*Uppercase*'.
 *
 * See also:
 *	<COATL_UCD_UPPER>, <Coatl_GetUcdProperty_Upper>,
 *	<COATL_UCD_UPPERCASE>
 *---------------------------------------------------------------------------*/

 #define Coatl_GetUcdProperty_Uppercase(c) \
    Coatl_GetUcdProperty_Upper(c)

/*---------------------------------------------------------------------------
 * Macro: Coatl_GetUcdProperty_Variation_Selector
 *
 *	Get value of UCD property '*Variation_Selector*' for given codepoint.
 *	Alias for property UCD property accessor '*VS*'
 *
 * Argument:
 *	c	- Codepoint to get UCD property value for.
 *
 * Result:
 *	Value of UCD property '*Variation_Selector*'.
 *
 * See also:
 *	<COATL_UCD_VS>, <Coatl_GetUcdProperty_VS>,
 *	<COATL_UCD_VARIATION_SELECTOR>
 *---------------------------------------------------------------------------*/

 #define Coatl_GetUcdProperty_Variation_Selector(c) \
    Coatl_GetUcdProperty_VS(c)

/*---------------------------------------------------------------------------
 * Macro: Coatl_GetUcdProperty_Word_Break
 *
 *	Get value of UCD property '*Word_Break*' for given codepoint.
 *	Alias for property UCD property accessor '*WB*'
 *
 * Argument:
 *	c	- Codepoint to get UCD property value for.
 *
 * Result:
 *	Value of UCD property '*Word_Break*'.
 *
 * See also:
 *	<COATL_UCD_WB>, <Coatl_GetUcdProperty_WB>,
 *	<COATL_UCD_WORD_BREAK>
 *---------------------------------------------------------------------------*/

 #define Coatl_GetUcdProperty_Word_Break(c) \
    Coatl_GetUcdProperty_WB(c)

/*---------------------------------------------------------------------------
 * Macro: Coatl_GetUcdProperty_White_Space
 *
 *	Get value of UCD property '*White_Space*' for given codepoint.
 *	Alias for property UCD property accessor '*WSpace*'
 *
 * Argument:
 *	c	- Codepoint to get UCD property value for.
 *
 * Result:
 *	Value of UCD property '*White_Space*'.
 *
 * See also:
 *	<COATL_UCD_WSPACE>, <Coatl_GetUcdProperty_WSpace>,
 *	<COATL_UCD_WHITE_SPACE>
 *---------------------------------------------------------------------------*/

 #define Coatl_GetUcdProperty_White_Space(c) \
    Coatl_GetUcdProperty_WSpace(c)

/*---------------------------------------------------------------------------
 * Macro: Coatl_GetUcdProperty_Space
 *
 *	Get value of UCD property '*space*' for given codepoint.
 *	Alias for property UCD property accessor '*WSpace*'
 *
 * Argument:
 *	c	- Codepoint to get UCD property value for.
 *
 * Result:
 *	Value of UCD property '*space*'.
 *
 * See also:
 *	<COATL_UCD_WSPACE>, <Coatl_GetUcdProperty_WSpace>,
 *	<COATL_UCD_SPACE>
 *---------------------------------------------------------------------------*/

 #define Coatl_GetUcdProperty_Space(c) \
    Coatl_GetUcdProperty_WSpace(c)

/*---------------------------------------------------------------------------
 * Macro: Coatl_GetUcdProperty_XID_Continue
 *
 *	Get value of UCD property '*XID_Continue*' for given codepoint.
 *	Alias for property UCD property accessor '*XIDC*'
 *
 * Argument:
 *	c	- Codepoint to get UCD property value for.
 *
 * Result:
 *	Value of UCD property '*XID_Continue*'.
 *
 * See also:
 *	<COATL_UCD_XIDC>, <Coatl_GetUcdProperty_XIDC>,
 *	<COATL_UCD_XID_CONTINUE>
 *---------------------------------------------------------------------------*/

 #define Coatl_GetUcdProperty_XID_Continue(c) \
    Coatl_GetUcdProperty_XIDC(c)

/*---------------------------------------------------------------------------
 * Macro: Coatl_GetUcdProperty_XID_Start
 *
 *	Get value of UCD property '*XID_Start*' for given codepoint.
 *	Alias for property UCD property accessor '*XIDS*'
 *
 * Argument:
 *	c	- Codepoint to get UCD property value for.
 *
 * Result:
 *	Value of UCD property '*XID_Start*'.
 *
 * See also:
 *	<COATL_UCD_XIDS>, <Coatl_GetUcdProperty_XIDS>,
 *	<COATL_UCD_XID_START>
 *---------------------------------------------------------------------------*/

 #define Coatl_GetUcdProperty_XID_Start(c) \
    Coatl_GetUcdProperty_XIDS(c)

#endif /* _COATL_UCD */
