/**
 * @file coatlUcd.h
 *
 * This file defines Unicode character property accessors.
 *
 * It is automatically generated from the Unicode Character Database (UCD) using
 * the file `coatlUcd.tcl`; Do not modify.
 */

#ifndef _COATL_UCD
#define _COATL_UCD


/*
===========================================================================*//*!
\defgroup ucd Unicode Character Database
\ingroup unicode
\{*//*==========================================================================
*/

/***************************************************************************//*!
 * \name UCD Property Accessors 
 ***************************************************************************\{*/

EXTERN Coatl_Ucd_Age    Coatl_GetUcdProperty_Age(Col_Char c);
EXTERN int              Coatl_GetUcdProperty_AHex(Col_Char c);
EXTERN int              Coatl_GetUcdProperty_Alpha(Col_Char c);
EXTERN Coatl_Ucd_Bc     Coatl_GetUcdProperty_Bc(Col_Char c);
EXTERN int              Coatl_GetUcdProperty_Bidi_C(Col_Char c);
EXTERN int              Coatl_GetUcdProperty_Bidi_M(Col_Char c);
EXTERN Coatl_Ucd_Blk    Coatl_GetUcdProperty_Blk(Col_Char c);
EXTERN Col_Char         Coatl_GetUcdProperty_Bmg(Col_Char c);
EXTERN int              Coatl_GetUcdProperty_Cased(Col_Char c);
EXTERN Coatl_Ucd_Ccc    Coatl_GetUcdProperty_Ccc(Col_Char c);
EXTERN int              Coatl_GetUcdProperty_CE(Col_Char c);
EXTERN const int *      Coatl_GetUcdProperty_Cf(Col_Char c,
                            size_t *lengthPtr);
EXTERN int              Coatl_GetUcdProperty_CI(Col_Char c);
EXTERN int              Coatl_GetUcdProperty_Comp_Ex(Col_Char c);
EXTERN int              Coatl_GetUcdProperty_CWCF(Col_Char c);
EXTERN int              Coatl_GetUcdProperty_CWCM(Col_Char c);
EXTERN int              Coatl_GetUcdProperty_CWKCF(Col_Char c);
EXTERN int              Coatl_GetUcdProperty_CWL(Col_Char c);
EXTERN int              Coatl_GetUcdProperty_CWT(Col_Char c);
EXTERN int              Coatl_GetUcdProperty_CWU(Col_Char c);
EXTERN int              Coatl_GetUcdProperty_Dash(Col_Char c);
EXTERN int              Coatl_GetUcdProperty_Dep(Col_Char c);
EXTERN int              Coatl_GetUcdProperty_DI(Col_Char c);
EXTERN int              Coatl_GetUcdProperty_Dia(Col_Char c);
EXTERN const int *      Coatl_GetUcdProperty_Dm(Col_Char c,
                            size_t *lengthPtr);
EXTERN Coatl_Ucd_Dt     Coatl_GetUcdProperty_Dt(Col_Char c);
EXTERN Coatl_Ucd_Ea     Coatl_GetUcdProperty_Ea(Col_Char c);
EXTERN int              Coatl_GetUcdProperty_Ext(Col_Char c);
EXTERN Coatl_Ucd_Gc     Coatl_GetUcdProperty_Gc(Col_Char c);
EXTERN Coatl_Ucd_GCB    Coatl_GetUcdProperty_GCB(Col_Char c);
EXTERN int              Coatl_GetUcdProperty_Gr_Base(Col_Char c);
EXTERN int              Coatl_GetUcdProperty_Gr_Ext(Col_Char c);
EXTERN int              Coatl_GetUcdProperty_Hex(Col_Char c);
EXTERN Coatl_Ucd_Hst    Coatl_GetUcdProperty_Hst(Col_Char c);
EXTERN int              Coatl_GetUcdProperty_IDC(Col_Char c);
EXTERN int              Coatl_GetUcdProperty_Ideo(Col_Char c);
EXTERN int              Coatl_GetUcdProperty_IDS(Col_Char c);
EXTERN int              Coatl_GetUcdProperty_IDSB(Col_Char c);
EXTERN int              Coatl_GetUcdProperty_IDST(Col_Char c);
EXTERN Coatl_Ucd_InPC   Coatl_GetUcdProperty_InPC(Col_Char c);
EXTERN Coatl_Ucd_InSC   Coatl_GetUcdProperty_InSC(Col_Char c);
EXTERN Coatl_Ucd_Jg     Coatl_GetUcdProperty_Jg(Col_Char c);
EXTERN int              Coatl_GetUcdProperty_Join_C(Col_Char c);
EXTERN Coatl_Ucd_Jt     Coatl_GetUcdProperty_Jt(Col_Char c);
EXTERN Coatl_Ucd_Lb     Coatl_GetUcdProperty_Lb(Col_Char c);
EXTERN const int *      Coatl_GetUcdProperty_Lc(Col_Char c,
                            size_t *lengthPtr);
EXTERN int              Coatl_GetUcdProperty_LOE(Col_Char c);
EXTERN int              Coatl_GetUcdProperty_Lower(Col_Char c);
EXTERN int              Coatl_GetUcdProperty_Math(Col_Char c);
EXTERN int              Coatl_GetUcdProperty_NChar(Col_Char c);
EXTERN Coatl_Ucd_NFC_QC Coatl_GetUcdProperty_NFC_QC(Col_Char c);
EXTERN int              Coatl_GetUcdProperty_NFD_QC(Col_Char c);
EXTERN const int *      Coatl_GetUcdProperty_NFKC_CF(Col_Char c,
                            size_t *lengthPtr);
EXTERN Coatl_Ucd_NFKC_QC Coatl_GetUcdProperty_NFKC_QC(Col_Char c);
EXTERN int              Coatl_GetUcdProperty_NFKD_QC(Col_Char c);
EXTERN Coatl_Ucd_Nt     Coatl_GetUcdProperty_Nt(Col_Char c);
EXTERN const char *     Coatl_GetUcdProperty_Nv(Col_Char c);
EXTERN int              Coatl_GetUcdProperty_OAlpha(Col_Char c);
EXTERN int              Coatl_GetUcdProperty_ODI(Col_Char c);
EXTERN int              Coatl_GetUcdProperty_OGr_Ext(Col_Char c);
EXTERN int              Coatl_GetUcdProperty_OIDC(Col_Char c);
EXTERN int              Coatl_GetUcdProperty_OIDS(Col_Char c);
EXTERN int              Coatl_GetUcdProperty_OLower(Col_Char c);
EXTERN int              Coatl_GetUcdProperty_OMath(Col_Char c);
EXTERN int              Coatl_GetUcdProperty_OUpper(Col_Char c);
EXTERN int              Coatl_GetUcdProperty_Pat_Syn(Col_Char c);
EXTERN int              Coatl_GetUcdProperty_Pat_WS(Col_Char c);
EXTERN int              Coatl_GetUcdProperty_QMark(Col_Char c);
EXTERN int              Coatl_GetUcdProperty_Radical(Col_Char c);
EXTERN Coatl_Ucd_SB     Coatl_GetUcdProperty_SB(Col_Char c);
EXTERN Coatl_Ucd_Sc     Coatl_GetUcdProperty_Sc(Col_Char c);
EXTERN Col_Char         Coatl_GetUcdProperty_Scf(Col_Char c);
EXTERN const unsigned char * Coatl_GetUcdProperty_Scx(
                            Col_Char c,size_t *lengthPtr);
EXTERN int              Coatl_GetUcdProperty_SD(Col_Char c);
EXTERN Col_Char         Coatl_GetUcdProperty_Slc(Col_Char c);
EXTERN Col_Char         Coatl_GetUcdProperty_Stc(Col_Char c);
EXTERN int              Coatl_GetUcdProperty_STerm(Col_Char c);
EXTERN Col_Char         Coatl_GetUcdProperty_Suc(Col_Char c);
EXTERN const int *      Coatl_GetUcdProperty_Tc(Col_Char c,
                            size_t *lengthPtr);
EXTERN int              Coatl_GetUcdProperty_Term(Col_Char c);
EXTERN const int *      Coatl_GetUcdProperty_Uc(Col_Char c,
                            size_t *lengthPtr);
EXTERN int              Coatl_GetUcdProperty_UIdeo(Col_Char c);
EXTERN int              Coatl_GetUcdProperty_Upper(Col_Char c);
EXTERN int              Coatl_GetUcdProperty_VS(Col_Char c);
EXTERN Coatl_Ucd_WB     Coatl_GetUcdProperty_WB(Col_Char c);
EXTERN int              Coatl_GetUcdProperty_WSpace(Col_Char c);
EXTERN int              Coatl_GetUcdProperty_XIDC(Col_Char c);
EXTERN int              Coatl_GetUcdProperty_XIDS(Col_Char c);
EXTERN Col_Char         Coatl_GetUcdProperty_Bpb(Col_Char c);
EXTERN Coatl_Ucd_Bpt    Coatl_GetUcdProperty_Bpt(Col_Char c);
EXTERN int              Coatl_GetUcdProperty_PCM(Col_Char c);

/**
 * Get value of UCD property '**ASCII_Hex_Digit**' for given codepoint.
 * Alias for property UCD property accessor '**AHex**'
 *
 * @param c Codepoint to get UCD property value for.
 *
 * @return Value of UCD property '**ASCII_Hex_Digit**'.
 *
 * @see COATL_UCD_AHEX
 * @see Coatl_GetUcdProperty_AHex
 * @see COATL_UCD_ASCII_HEX_DIGIT
 */
#define Coatl_GetUcdProperty_ASCII_Hex_Digit(c) \
    Coatl_GetUcdProperty_AHex(c)

/**
 * Get value of UCD property '**Alphabetic**' for given codepoint.
 * Alias for property UCD property accessor '**Alpha**'
 *
 * @param c Codepoint to get UCD property value for.
 *
 * @return Value of UCD property '**Alphabetic**'.
 *
 * @see COATL_UCD_ALPHA
 * @see Coatl_GetUcdProperty_Alpha
 * @see COATL_UCD_ALPHABETIC
 */
#define Coatl_GetUcdProperty_Alphabetic(c) \
    Coatl_GetUcdProperty_Alpha(c)

/**
 * Get value of UCD property '**Bidi_Class**' for given codepoint.
 * Alias for property UCD property accessor '**Bc**'
 *
 * @param c Codepoint to get UCD property value for.
 *
 * @return Value of UCD property '**Bidi_Class**'.
 *
 * @see COATL_UCD_BC
 * @see Coatl_GetUcdProperty_Bc
 * @see COATL_UCD_BIDI_CLASS
 */
#define Coatl_GetUcdProperty_Bidi_Class(c) \
    Coatl_GetUcdProperty_Bc(c)

/**
 * Get value of UCD property '**Bidi_Control**' for given codepoint.
 * Alias for property UCD property accessor '**Bidi_C**'
 *
 * @param c Codepoint to get UCD property value for.
 *
 * @return Value of UCD property '**Bidi_Control**'.
 *
 * @see COATL_UCD_BIDI_C
 * @see Coatl_GetUcdProperty_Bidi_C
 * @see COATL_UCD_BIDI_CONTROL
 */
#define Coatl_GetUcdProperty_Bidi_Control(c) \
    Coatl_GetUcdProperty_Bidi_C(c)

/**
 * Get value of UCD property '**Bidi_Mirrored**' for given codepoint.
 * Alias for property UCD property accessor '**Bidi_M**'
 *
 * @param c Codepoint to get UCD property value for.
 *
 * @return Value of UCD property '**Bidi_Mirrored**'.
 *
 * @see COATL_UCD_BIDI_M
 * @see Coatl_GetUcdProperty_Bidi_M
 * @see COATL_UCD_BIDI_MIRRORED
 */
#define Coatl_GetUcdProperty_Bidi_Mirrored(c) \
    Coatl_GetUcdProperty_Bidi_M(c)

/**
 * Get value of UCD property '**Block**' for given codepoint.
 * Alias for property UCD property accessor '**Blk**'
 *
 * @param c Codepoint to get UCD property value for.
 *
 * @return Value of UCD property '**Block**'.
 *
 * @see COATL_UCD_BLK
 * @see Coatl_GetUcdProperty_Blk
 * @see COATL_UCD_BLOCK
 */
#define Coatl_GetUcdProperty_Block(c) \
    Coatl_GetUcdProperty_Blk(c)

/**
 * Get value of UCD property '**Bidi_Mirroring_Glyph**' for given codepoint.
 * Alias for property UCD property accessor '**Bmg**'
 *
 * @param c Codepoint to get UCD property value for.
 *
 * @return Value of UCD property '**Bidi_Mirroring_Glyph**'.
 *
 * @see COATL_UCD_BMG
 * @see Coatl_GetUcdProperty_Bmg
 * @see COATL_UCD_BIDI_MIRRORING_GLYPH
 */
#define Coatl_GetUcdProperty_Bidi_Mirroring_Glyph(c) \
    Coatl_GetUcdProperty_Bmg(c)

/**
 * Get value of UCD property '**Canonical_Combining_Class**' for given codepoint.
 * Alias for property UCD property accessor '**Ccc**'
 *
 * @param c Codepoint to get UCD property value for.
 *
 * @return Value of UCD property '**Canonical_Combining_Class**'.
 *
 * @see COATL_UCD_CCC
 * @see Coatl_GetUcdProperty_Ccc
 * @see COATL_UCD_CANONICAL_COMBINING_CLASS
 */
#define Coatl_GetUcdProperty_Canonical_Combining_Class(c) \
    Coatl_GetUcdProperty_Ccc(c)

/**
 * Get value of UCD property '**Composition_Exclusion**' for given codepoint.
 * Alias for property UCD property accessor '**CE**'
 *
 * @param c Codepoint to get UCD property value for.
 *
 * @return Value of UCD property '**Composition_Exclusion**'.
 *
 * @see COATL_UCD_CE
 * @see Coatl_GetUcdProperty_CE
 * @see COATL_UCD_COMPOSITION_EXCLUSION
 */
#define Coatl_GetUcdProperty_Composition_Exclusion(c) \
    Coatl_GetUcdProperty_CE(c)

/**
 * Get value of UCD property '**Case_Folding**' for given codepoint.
 * Alias for property UCD property accessor '**Cf**'
 *
 * @param c Codepoint to get UCD property value for.
 *
 * @return Value of UCD property '**Case_Folding**'.
 *
 * @see COATL_UCD_CF
 * @see Coatl_GetUcdProperty_Cf
 * @see COATL_UCD_CASE_FOLDING
 */
#define Coatl_GetUcdProperty_Case_Folding(c) \
    Coatl_GetUcdProperty_Cf(c)

/**
 * Get value of UCD property '**Case_Ignorable**' for given codepoint.
 * Alias for property UCD property accessor '**CI**'
 *
 * @param c Codepoint to get UCD property value for.
 *
 * @return Value of UCD property '**Case_Ignorable**'.
 *
 * @see COATL_UCD_CI
 * @see Coatl_GetUcdProperty_CI
 * @see COATL_UCD_CASE_IGNORABLE
 */
#define Coatl_GetUcdProperty_Case_Ignorable(c) \
    Coatl_GetUcdProperty_CI(c)

/**
 * Get value of UCD property '**Full_Composition_Exclusion**' for given codepoint.
 * Alias for property UCD property accessor '**Comp_Ex**'
 *
 * @param c Codepoint to get UCD property value for.
 *
 * @return Value of UCD property '**Full_Composition_Exclusion**'.
 *
 * @see COATL_UCD_COMP_EX
 * @see Coatl_GetUcdProperty_Comp_Ex
 * @see COATL_UCD_FULL_COMPOSITION_EXCLUSION
 */
#define Coatl_GetUcdProperty_Full_Composition_Exclusion(c) \
    Coatl_GetUcdProperty_Comp_Ex(c)

/**
 * Get value of UCD property '**Changes_When_Casefolded**' for given codepoint.
 * Alias for property UCD property accessor '**CWCF**'
 *
 * @param c Codepoint to get UCD property value for.
 *
 * @return Value of UCD property '**Changes_When_Casefolded**'.
 *
 * @see COATL_UCD_CWCF
 * @see Coatl_GetUcdProperty_CWCF
 * @see COATL_UCD_CHANGES_WHEN_CASEFOLDED
 */
#define Coatl_GetUcdProperty_Changes_When_Casefolded(c) \
    Coatl_GetUcdProperty_CWCF(c)

/**
 * Get value of UCD property '**Changes_When_Casemapped**' for given codepoint.
 * Alias for property UCD property accessor '**CWCM**'
 *
 * @param c Codepoint to get UCD property value for.
 *
 * @return Value of UCD property '**Changes_When_Casemapped**'.
 *
 * @see COATL_UCD_CWCM
 * @see Coatl_GetUcdProperty_CWCM
 * @see COATL_UCD_CHANGES_WHEN_CASEMAPPED
 */
#define Coatl_GetUcdProperty_Changes_When_Casemapped(c) \
    Coatl_GetUcdProperty_CWCM(c)

/**
 * Get value of UCD property '**Changes_When_NFKC_Casefolded**' for given codepoint.
 * Alias for property UCD property accessor '**CWKCF**'
 *
 * @param c Codepoint to get UCD property value for.
 *
 * @return Value of UCD property '**Changes_When_NFKC_Casefolded**'.
 *
 * @see COATL_UCD_CWKCF
 * @see Coatl_GetUcdProperty_CWKCF
 * @see COATL_UCD_CHANGES_WHEN_NFKC_CASEFOLDED
 */
#define Coatl_GetUcdProperty_Changes_When_NFKC_Casefolded(c) \
    Coatl_GetUcdProperty_CWKCF(c)

/**
 * Get value of UCD property '**Changes_When_Lowercased**' for given codepoint.
 * Alias for property UCD property accessor '**CWL**'
 *
 * @param c Codepoint to get UCD property value for.
 *
 * @return Value of UCD property '**Changes_When_Lowercased**'.
 *
 * @see COATL_UCD_CWL
 * @see Coatl_GetUcdProperty_CWL
 * @see COATL_UCD_CHANGES_WHEN_LOWERCASED
 */
#define Coatl_GetUcdProperty_Changes_When_Lowercased(c) \
    Coatl_GetUcdProperty_CWL(c)

/**
 * Get value of UCD property '**Changes_When_Titlecased**' for given codepoint.
 * Alias for property UCD property accessor '**CWT**'
 *
 * @param c Codepoint to get UCD property value for.
 *
 * @return Value of UCD property '**Changes_When_Titlecased**'.
 *
 * @see COATL_UCD_CWT
 * @see Coatl_GetUcdProperty_CWT
 * @see COATL_UCD_CHANGES_WHEN_TITLECASED
 */
#define Coatl_GetUcdProperty_Changes_When_Titlecased(c) \
    Coatl_GetUcdProperty_CWT(c)

/**
 * Get value of UCD property '**Changes_When_Uppercased**' for given codepoint.
 * Alias for property UCD property accessor '**CWU**'
 *
 * @param c Codepoint to get UCD property value for.
 *
 * @return Value of UCD property '**Changes_When_Uppercased**'.
 *
 * @see COATL_UCD_CWU
 * @see Coatl_GetUcdProperty_CWU
 * @see COATL_UCD_CHANGES_WHEN_UPPERCASED
 */
#define Coatl_GetUcdProperty_Changes_When_Uppercased(c) \
    Coatl_GetUcdProperty_CWU(c)

/**
 * Get value of UCD property '**Deprecated**' for given codepoint.
 * Alias for property UCD property accessor '**Dep**'
 *
 * @param c Codepoint to get UCD property value for.
 *
 * @return Value of UCD property '**Deprecated**'.
 *
 * @see COATL_UCD_DEP
 * @see Coatl_GetUcdProperty_Dep
 * @see COATL_UCD_DEPRECATED
 */
#define Coatl_GetUcdProperty_Deprecated(c) \
    Coatl_GetUcdProperty_Dep(c)

/**
 * Get value of UCD property '**Default_Ignorable_Code_Point**' for given codepoint.
 * Alias for property UCD property accessor '**DI**'
 *
 * @param c Codepoint to get UCD property value for.
 *
 * @return Value of UCD property '**Default_Ignorable_Code_Point**'.
 *
 * @see COATL_UCD_DI
 * @see Coatl_GetUcdProperty_DI
 * @see COATL_UCD_DEFAULT_IGNORABLE_CODE_POINT
 */
#define Coatl_GetUcdProperty_Default_Ignorable_Code_Point(c) \
    Coatl_GetUcdProperty_DI(c)

/**
 * Get value of UCD property '**Diacritic**' for given codepoint.
 * Alias for property UCD property accessor '**Dia**'
 *
 * @param c Codepoint to get UCD property value for.
 *
 * @return Value of UCD property '**Diacritic**'.
 *
 * @see COATL_UCD_DIA
 * @see Coatl_GetUcdProperty_Dia
 * @see COATL_UCD_DIACRITIC
 */
#define Coatl_GetUcdProperty_Diacritic(c) \
    Coatl_GetUcdProperty_Dia(c)

/**
 * Get value of UCD property '**Decomposition_Mapping**' for given codepoint.
 * Alias for property UCD property accessor '**Dm**'
 *
 * @param c Codepoint to get UCD property value for.
 *
 * @return Value of UCD property '**Decomposition_Mapping**'.
 *
 * @see COATL_UCD_DM
 * @see Coatl_GetUcdProperty_Dm
 * @see COATL_UCD_DECOMPOSITION_MAPPING
 */
#define Coatl_GetUcdProperty_Decomposition_Mapping(c) \
    Coatl_GetUcdProperty_Dm(c)

/**
 * Get value of UCD property '**Decomposition_Type**' for given codepoint.
 * Alias for property UCD property accessor '**Dt**'
 *
 * @param c Codepoint to get UCD property value for.
 *
 * @return Value of UCD property '**Decomposition_Type**'.
 *
 * @see COATL_UCD_DT
 * @see Coatl_GetUcdProperty_Dt
 * @see COATL_UCD_DECOMPOSITION_TYPE
 */
#define Coatl_GetUcdProperty_Decomposition_Type(c) \
    Coatl_GetUcdProperty_Dt(c)

/**
 * Get value of UCD property '**East_Asian_Width**' for given codepoint.
 * Alias for property UCD property accessor '**Ea**'
 *
 * @param c Codepoint to get UCD property value for.
 *
 * @return Value of UCD property '**East_Asian_Width**'.
 *
 * @see COATL_UCD_EA
 * @see Coatl_GetUcdProperty_Ea
 * @see COATL_UCD_EAST_ASIAN_WIDTH
 */
#define Coatl_GetUcdProperty_East_Asian_Width(c) \
    Coatl_GetUcdProperty_Ea(c)

/**
 * Get value of UCD property '**Extender**' for given codepoint.
 * Alias for property UCD property accessor '**Ext**'
 *
 * @param c Codepoint to get UCD property value for.
 *
 * @return Value of UCD property '**Extender**'.
 *
 * @see COATL_UCD_EXT
 * @see Coatl_GetUcdProperty_Ext
 * @see COATL_UCD_EXTENDER
 */
#define Coatl_GetUcdProperty_Extender(c) \
    Coatl_GetUcdProperty_Ext(c)

/**
 * Get value of UCD property '**General_Category**' for given codepoint.
 * Alias for property UCD property accessor '**Gc**'
 *
 * @param c Codepoint to get UCD property value for.
 *
 * @return Value of UCD property '**General_Category**'.
 *
 * @see COATL_UCD_GC
 * @see Coatl_GetUcdProperty_Gc
 * @see COATL_UCD_GENERAL_CATEGORY
 */
#define Coatl_GetUcdProperty_General_Category(c) \
    Coatl_GetUcdProperty_Gc(c)

/**
 * Get value of UCD property '**Grapheme_Cluster_Break**' for given codepoint.
 * Alias for property UCD property accessor '**GCB**'
 *
 * @param c Codepoint to get UCD property value for.
 *
 * @return Value of UCD property '**Grapheme_Cluster_Break**'.
 *
 * @see COATL_UCD_GCB
 * @see Coatl_GetUcdProperty_GCB
 * @see COATL_UCD_GRAPHEME_CLUSTER_BREAK
 */
#define Coatl_GetUcdProperty_Grapheme_Cluster_Break(c) \
    Coatl_GetUcdProperty_GCB(c)

/**
 * Get value of UCD property '**Grapheme_Base**' for given codepoint.
 * Alias for property UCD property accessor '**Gr_Base**'
 *
 * @param c Codepoint to get UCD property value for.
 *
 * @return Value of UCD property '**Grapheme_Base**'.
 *
 * @see COATL_UCD_GR_BASE
 * @see Coatl_GetUcdProperty_Gr_Base
 * @see COATL_UCD_GRAPHEME_BASE
 */
#define Coatl_GetUcdProperty_Grapheme_Base(c) \
    Coatl_GetUcdProperty_Gr_Base(c)

/**
 * Get value of UCD property '**Grapheme_Extend**' for given codepoint.
 * Alias for property UCD property accessor '**Gr_Ext**'
 *
 * @param c Codepoint to get UCD property value for.
 *
 * @return Value of UCD property '**Grapheme_Extend**'.
 *
 * @see COATL_UCD_GR_EXT
 * @see Coatl_GetUcdProperty_Gr_Ext
 * @see COATL_UCD_GRAPHEME_EXTEND
 */
#define Coatl_GetUcdProperty_Grapheme_Extend(c) \
    Coatl_GetUcdProperty_Gr_Ext(c)

/**
 * Get value of UCD property '**Hex_Digit**' for given codepoint.
 * Alias for property UCD property accessor '**Hex**'
 *
 * @param c Codepoint to get UCD property value for.
 *
 * @return Value of UCD property '**Hex_Digit**'.
 *
 * @see COATL_UCD_HEX
 * @see Coatl_GetUcdProperty_Hex
 * @see COATL_UCD_HEX_DIGIT
 */
#define Coatl_GetUcdProperty_Hex_Digit(c) \
    Coatl_GetUcdProperty_Hex(c)

/**
 * Get value of UCD property '**Hangul_Syllable_Type**' for given codepoint.
 * Alias for property UCD property accessor '**Hst**'
 *
 * @param c Codepoint to get UCD property value for.
 *
 * @return Value of UCD property '**Hangul_Syllable_Type**'.
 *
 * @see COATL_UCD_HST
 * @see Coatl_GetUcdProperty_Hst
 * @see COATL_UCD_HANGUL_SYLLABLE_TYPE
 */
#define Coatl_GetUcdProperty_Hangul_Syllable_Type(c) \
    Coatl_GetUcdProperty_Hst(c)

/**
 * Get value of UCD property '**ID_Continue**' for given codepoint.
 * Alias for property UCD property accessor '**IDC**'
 *
 * @param c Codepoint to get UCD property value for.
 *
 * @return Value of UCD property '**ID_Continue**'.
 *
 * @see COATL_UCD_IDC
 * @see Coatl_GetUcdProperty_IDC
 * @see COATL_UCD_ID_CONTINUE
 */
#define Coatl_GetUcdProperty_ID_Continue(c) \
    Coatl_GetUcdProperty_IDC(c)

/**
 * Get value of UCD property '**Ideographic**' for given codepoint.
 * Alias for property UCD property accessor '**Ideo**'
 *
 * @param c Codepoint to get UCD property value for.
 *
 * @return Value of UCD property '**Ideographic**'.
 *
 * @see COATL_UCD_IDEO
 * @see Coatl_GetUcdProperty_Ideo
 * @see COATL_UCD_IDEOGRAPHIC
 */
#define Coatl_GetUcdProperty_Ideographic(c) \
    Coatl_GetUcdProperty_Ideo(c)

/**
 * Get value of UCD property '**ID_Start**' for given codepoint.
 * Alias for property UCD property accessor '**IDS**'
 *
 * @param c Codepoint to get UCD property value for.
 *
 * @return Value of UCD property '**ID_Start**'.
 *
 * @see COATL_UCD_IDS
 * @see Coatl_GetUcdProperty_IDS
 * @see COATL_UCD_ID_START
 */
#define Coatl_GetUcdProperty_ID_Start(c) \
    Coatl_GetUcdProperty_IDS(c)

/**
 * Get value of UCD property '**IDS_Binary_Operator**' for given codepoint.
 * Alias for property UCD property accessor '**IDSB**'
 *
 * @param c Codepoint to get UCD property value for.
 *
 * @return Value of UCD property '**IDS_Binary_Operator**'.
 *
 * @see COATL_UCD_IDSB
 * @see Coatl_GetUcdProperty_IDSB
 * @see COATL_UCD_IDS_BINARY_OPERATOR
 */
#define Coatl_GetUcdProperty_IDS_Binary_Operator(c) \
    Coatl_GetUcdProperty_IDSB(c)

/**
 * Get value of UCD property '**IDS_Trinary_Operator**' for given codepoint.
 * Alias for property UCD property accessor '**IDST**'
 *
 * @param c Codepoint to get UCD property value for.
 *
 * @return Value of UCD property '**IDS_Trinary_Operator**'.
 *
 * @see COATL_UCD_IDST
 * @see Coatl_GetUcdProperty_IDST
 * @see COATL_UCD_IDS_TRINARY_OPERATOR
 */
#define Coatl_GetUcdProperty_IDS_Trinary_Operator(c) \
    Coatl_GetUcdProperty_IDST(c)

/**
 * Get value of UCD property '**Indic_Positional_Category**' for given codepoint.
 * Alias for property UCD property accessor '**InPC**'
 *
 * @param c Codepoint to get UCD property value for.
 *
 * @return Value of UCD property '**Indic_Positional_Category**'.
 *
 * @see COATL_UCD_INPC
 * @see Coatl_GetUcdProperty_InPC
 * @see COATL_UCD_INDIC_POSITIONAL_CATEGORY
 */
#define Coatl_GetUcdProperty_Indic_Positional_Category(c) \
    Coatl_GetUcdProperty_InPC(c)

/**
 * Get value of UCD property '**Indic_Syllabic_Category**' for given codepoint.
 * Alias for property UCD property accessor '**InSC**'
 *
 * @param c Codepoint to get UCD property value for.
 *
 * @return Value of UCD property '**Indic_Syllabic_Category**'.
 *
 * @see COATL_UCD_INSC
 * @see Coatl_GetUcdProperty_InSC
 * @see COATL_UCD_INDIC_SYLLABIC_CATEGORY
 */
#define Coatl_GetUcdProperty_Indic_Syllabic_Category(c) \
    Coatl_GetUcdProperty_InSC(c)

/**
 * Get value of UCD property '**Joining_Group**' for given codepoint.
 * Alias for property UCD property accessor '**Jg**'
 *
 * @param c Codepoint to get UCD property value for.
 *
 * @return Value of UCD property '**Joining_Group**'.
 *
 * @see COATL_UCD_JG
 * @see Coatl_GetUcdProperty_Jg
 * @see COATL_UCD_JOINING_GROUP
 */
#define Coatl_GetUcdProperty_Joining_Group(c) \
    Coatl_GetUcdProperty_Jg(c)

/**
 * Get value of UCD property '**Join_Control**' for given codepoint.
 * Alias for property UCD property accessor '**Join_C**'
 *
 * @param c Codepoint to get UCD property value for.
 *
 * @return Value of UCD property '**Join_Control**'.
 *
 * @see COATL_UCD_JOIN_C
 * @see Coatl_GetUcdProperty_Join_C
 * @see COATL_UCD_JOIN_CONTROL
 */
#define Coatl_GetUcdProperty_Join_Control(c) \
    Coatl_GetUcdProperty_Join_C(c)

/**
 * Get value of UCD property '**Joining_Type**' for given codepoint.
 * Alias for property UCD property accessor '**Jt**'
 *
 * @param c Codepoint to get UCD property value for.
 *
 * @return Value of UCD property '**Joining_Type**'.
 *
 * @see COATL_UCD_JT
 * @see Coatl_GetUcdProperty_Jt
 * @see COATL_UCD_JOINING_TYPE
 */
#define Coatl_GetUcdProperty_Joining_Type(c) \
    Coatl_GetUcdProperty_Jt(c)

/**
 * Get value of UCD property '**Line_Break**' for given codepoint.
 * Alias for property UCD property accessor '**Lb**'
 *
 * @param c Codepoint to get UCD property value for.
 *
 * @return Value of UCD property '**Line_Break**'.
 *
 * @see COATL_UCD_LB
 * @see Coatl_GetUcdProperty_Lb
 * @see COATL_UCD_LINE_BREAK
 */
#define Coatl_GetUcdProperty_Line_Break(c) \
    Coatl_GetUcdProperty_Lb(c)

/**
 * Get value of UCD property '**Lowercase_Mapping**' for given codepoint.
 * Alias for property UCD property accessor '**Lc**'
 *
 * @param c Codepoint to get UCD property value for.
 *
 * @return Value of UCD property '**Lowercase_Mapping**'.
 *
 * @see COATL_UCD_LC
 * @see Coatl_GetUcdProperty_Lc
 * @see COATL_UCD_LOWERCASE_MAPPING
 */
#define Coatl_GetUcdProperty_Lowercase_Mapping(c) \
    Coatl_GetUcdProperty_Lc(c)

/**
 * Get value of UCD property '**Logical_Order_Exception**' for given codepoint.
 * Alias for property UCD property accessor '**LOE**'
 *
 * @param c Codepoint to get UCD property value for.
 *
 * @return Value of UCD property '**Logical_Order_Exception**'.
 *
 * @see COATL_UCD_LOE
 * @see Coatl_GetUcdProperty_LOE
 * @see COATL_UCD_LOGICAL_ORDER_EXCEPTION
 */
#define Coatl_GetUcdProperty_Logical_Order_Exception(c) \
    Coatl_GetUcdProperty_LOE(c)

/**
 * Get value of UCD property '**Lowercase**' for given codepoint.
 * Alias for property UCD property accessor '**Lower**'
 *
 * @param c Codepoint to get UCD property value for.
 *
 * @return Value of UCD property '**Lowercase**'.
 *
 * @see COATL_UCD_LOWER
 * @see Coatl_GetUcdProperty_Lower
 * @see COATL_UCD_LOWERCASE
 */
#define Coatl_GetUcdProperty_Lowercase(c) \
    Coatl_GetUcdProperty_Lower(c)

/**
 * Get value of UCD property '**Noncharacter_Code_Point**' for given codepoint.
 * Alias for property UCD property accessor '**NChar**'
 *
 * @param c Codepoint to get UCD property value for.
 *
 * @return Value of UCD property '**Noncharacter_Code_Point**'.
 *
 * @see COATL_UCD_NCHAR
 * @see Coatl_GetUcdProperty_NChar
 * @see COATL_UCD_NONCHARACTER_CODE_POINT
 */
#define Coatl_GetUcdProperty_Noncharacter_Code_Point(c) \
    Coatl_GetUcdProperty_NChar(c)

/**
 * Get value of UCD property '**NFC_Quick_Check**' for given codepoint.
 * Alias for property UCD property accessor '**NFC_QC**'
 *
 * @param c Codepoint to get UCD property value for.
 *
 * @return Value of UCD property '**NFC_Quick_Check**'.
 *
 * @see COATL_UCD_NFC_QC
 * @see Coatl_GetUcdProperty_NFC_QC
 * @see COATL_UCD_NFC_QUICK_CHECK
 */
#define Coatl_GetUcdProperty_NFC_Quick_Check(c) \
    Coatl_GetUcdProperty_NFC_QC(c)

/**
 * Get value of UCD property '**NFD_Quick_Check**' for given codepoint.
 * Alias for property UCD property accessor '**NFD_QC**'
 *
 * @param c Codepoint to get UCD property value for.
 *
 * @return Value of UCD property '**NFD_Quick_Check**'.
 *
 * @see COATL_UCD_NFD_QC
 * @see Coatl_GetUcdProperty_NFD_QC
 * @see COATL_UCD_NFD_QUICK_CHECK
 */
#define Coatl_GetUcdProperty_NFD_Quick_Check(c) \
    Coatl_GetUcdProperty_NFD_QC(c)

/**
 * Get value of UCD property '**NFKC_Casefold**' for given codepoint.
 * Alias for property UCD property accessor '**NFKC_CF**'
 *
 * @param c Codepoint to get UCD property value for.
 *
 * @return Value of UCD property '**NFKC_Casefold**'.
 *
 * @see COATL_UCD_NFKC_CF
 * @see Coatl_GetUcdProperty_NFKC_CF
 * @see COATL_UCD_NFKC_CASEFOLD
 */
#define Coatl_GetUcdProperty_NFKC_Casefold(c) \
    Coatl_GetUcdProperty_NFKC_CF(c)

/**
 * Get value of UCD property '**NFKC_Quick_Check**' for given codepoint.
 * Alias for property UCD property accessor '**NFKC_QC**'
 *
 * @param c Codepoint to get UCD property value for.
 *
 * @return Value of UCD property '**NFKC_Quick_Check**'.
 *
 * @see COATL_UCD_NFKC_QC
 * @see Coatl_GetUcdProperty_NFKC_QC
 * @see COATL_UCD_NFKC_QUICK_CHECK
 */
#define Coatl_GetUcdProperty_NFKC_Quick_Check(c) \
    Coatl_GetUcdProperty_NFKC_QC(c)

/**
 * Get value of UCD property '**NFKD_Quick_Check**' for given codepoint.
 * Alias for property UCD property accessor '**NFKD_QC**'
 *
 * @param c Codepoint to get UCD property value for.
 *
 * @return Value of UCD property '**NFKD_Quick_Check**'.
 *
 * @see COATL_UCD_NFKD_QC
 * @see Coatl_GetUcdProperty_NFKD_QC
 * @see COATL_UCD_NFKD_QUICK_CHECK
 */
#define Coatl_GetUcdProperty_NFKD_Quick_Check(c) \
    Coatl_GetUcdProperty_NFKD_QC(c)

/**
 * Get value of UCD property '**Numeric_Type**' for given codepoint.
 * Alias for property UCD property accessor '**Nt**'
 *
 * @param c Codepoint to get UCD property value for.
 *
 * @return Value of UCD property '**Numeric_Type**'.
 *
 * @see COATL_UCD_NT
 * @see Coatl_GetUcdProperty_Nt
 * @see COATL_UCD_NUMERIC_TYPE
 */
#define Coatl_GetUcdProperty_Numeric_Type(c) \
    Coatl_GetUcdProperty_Nt(c)

/**
 * Get value of UCD property '**Numeric_Value**' for given codepoint.
 * Alias for property UCD property accessor '**Nv**'
 *
 * @param c Codepoint to get UCD property value for.
 *
 * @return Value of UCD property '**Numeric_Value**'.
 *
 * @see COATL_UCD_NV
 * @see Coatl_GetUcdProperty_Nv
 * @see COATL_UCD_NUMERIC_VALUE
 */
#define Coatl_GetUcdProperty_Numeric_Value(c) \
    Coatl_GetUcdProperty_Nv(c)

/**
 * Get value of UCD property '**Other_Alphabetic**' for given codepoint.
 * Alias for property UCD property accessor '**OAlpha**'
 *
 * @param c Codepoint to get UCD property value for.
 *
 * @return Value of UCD property '**Other_Alphabetic**'.
 *
 * @see COATL_UCD_OALPHA
 * @see Coatl_GetUcdProperty_OAlpha
 * @see COATL_UCD_OTHER_ALPHABETIC
 */
#define Coatl_GetUcdProperty_Other_Alphabetic(c) \
    Coatl_GetUcdProperty_OAlpha(c)

/**
 * Get value of UCD property '**Other_Default_Ignorable_Code_Point**' for given codepoint.
 * Alias for property UCD property accessor '**ODI**'
 *
 * @param c Codepoint to get UCD property value for.
 *
 * @return Value of UCD property '**Other_Default_Ignorable_Code_Point**'.
 *
 * @see COATL_UCD_ODI
 * @see Coatl_GetUcdProperty_ODI
 * @see COATL_UCD_OTHER_DEFAULT_IGNORABLE_CODE_POINT
 */
#define Coatl_GetUcdProperty_Other_Default_Ignorable_Code_Point(c) \
    Coatl_GetUcdProperty_ODI(c)

/**
 * Get value of UCD property '**Other_Grapheme_Extend**' for given codepoint.
 * Alias for property UCD property accessor '**OGr_Ext**'
 *
 * @param c Codepoint to get UCD property value for.
 *
 * @return Value of UCD property '**Other_Grapheme_Extend**'.
 *
 * @see COATL_UCD_OGR_EXT
 * @see Coatl_GetUcdProperty_OGr_Ext
 * @see COATL_UCD_OTHER_GRAPHEME_EXTEND
 */
#define Coatl_GetUcdProperty_Other_Grapheme_Extend(c) \
    Coatl_GetUcdProperty_OGr_Ext(c)

/**
 * Get value of UCD property '**Other_ID_Continue**' for given codepoint.
 * Alias for property UCD property accessor '**OIDC**'
 *
 * @param c Codepoint to get UCD property value for.
 *
 * @return Value of UCD property '**Other_ID_Continue**'.
 *
 * @see COATL_UCD_OIDC
 * @see Coatl_GetUcdProperty_OIDC
 * @see COATL_UCD_OTHER_ID_CONTINUE
 */
#define Coatl_GetUcdProperty_Other_ID_Continue(c) \
    Coatl_GetUcdProperty_OIDC(c)

/**
 * Get value of UCD property '**Other_ID_Start**' for given codepoint.
 * Alias for property UCD property accessor '**OIDS**'
 *
 * @param c Codepoint to get UCD property value for.
 *
 * @return Value of UCD property '**Other_ID_Start**'.
 *
 * @see COATL_UCD_OIDS
 * @see Coatl_GetUcdProperty_OIDS
 * @see COATL_UCD_OTHER_ID_START
 */
#define Coatl_GetUcdProperty_Other_ID_Start(c) \
    Coatl_GetUcdProperty_OIDS(c)

/**
 * Get value of UCD property '**Other_Lowercase**' for given codepoint.
 * Alias for property UCD property accessor '**OLower**'
 *
 * @param c Codepoint to get UCD property value for.
 *
 * @return Value of UCD property '**Other_Lowercase**'.
 *
 * @see COATL_UCD_OLOWER
 * @see Coatl_GetUcdProperty_OLower
 * @see COATL_UCD_OTHER_LOWERCASE
 */
#define Coatl_GetUcdProperty_Other_Lowercase(c) \
    Coatl_GetUcdProperty_OLower(c)

/**
 * Get value of UCD property '**Other_Math**' for given codepoint.
 * Alias for property UCD property accessor '**OMath**'
 *
 * @param c Codepoint to get UCD property value for.
 *
 * @return Value of UCD property '**Other_Math**'.
 *
 * @see COATL_UCD_OMATH
 * @see Coatl_GetUcdProperty_OMath
 * @see COATL_UCD_OTHER_MATH
 */
#define Coatl_GetUcdProperty_Other_Math(c) \
    Coatl_GetUcdProperty_OMath(c)

/**
 * Get value of UCD property '**Other_Uppercase**' for given codepoint.
 * Alias for property UCD property accessor '**OUpper**'
 *
 * @param c Codepoint to get UCD property value for.
 *
 * @return Value of UCD property '**Other_Uppercase**'.
 *
 * @see COATL_UCD_OUPPER
 * @see Coatl_GetUcdProperty_OUpper
 * @see COATL_UCD_OTHER_UPPERCASE
 */
#define Coatl_GetUcdProperty_Other_Uppercase(c) \
    Coatl_GetUcdProperty_OUpper(c)

/**
 * Get value of UCD property '**Pattern_Syntax**' for given codepoint.
 * Alias for property UCD property accessor '**Pat_Syn**'
 *
 * @param c Codepoint to get UCD property value for.
 *
 * @return Value of UCD property '**Pattern_Syntax**'.
 *
 * @see COATL_UCD_PAT_SYN
 * @see Coatl_GetUcdProperty_Pat_Syn
 * @see COATL_UCD_PATTERN_SYNTAX
 */
#define Coatl_GetUcdProperty_Pattern_Syntax(c) \
    Coatl_GetUcdProperty_Pat_Syn(c)

/**
 * Get value of UCD property '**Pattern_White_Space**' for given codepoint.
 * Alias for property UCD property accessor '**Pat_WS**'
 *
 * @param c Codepoint to get UCD property value for.
 *
 * @return Value of UCD property '**Pattern_White_Space**'.
 *
 * @see COATL_UCD_PAT_WS
 * @see Coatl_GetUcdProperty_Pat_WS
 * @see COATL_UCD_PATTERN_WHITE_SPACE
 */
#define Coatl_GetUcdProperty_Pattern_White_Space(c) \
    Coatl_GetUcdProperty_Pat_WS(c)

/**
 * Get value of UCD property '**Quotation_Mark**' for given codepoint.
 * Alias for property UCD property accessor '**QMark**'
 *
 * @param c Codepoint to get UCD property value for.
 *
 * @return Value of UCD property '**Quotation_Mark**'.
 *
 * @see COATL_UCD_QMARK
 * @see Coatl_GetUcdProperty_QMark
 * @see COATL_UCD_QUOTATION_MARK
 */
#define Coatl_GetUcdProperty_Quotation_Mark(c) \
    Coatl_GetUcdProperty_QMark(c)

/**
 * Get value of UCD property '**Sentence_Break**' for given codepoint.
 * Alias for property UCD property accessor '**SB**'
 *
 * @param c Codepoint to get UCD property value for.
 *
 * @return Value of UCD property '**Sentence_Break**'.
 *
 * @see COATL_UCD_SB
 * @see Coatl_GetUcdProperty_SB
 * @see COATL_UCD_SENTENCE_BREAK
 */
#define Coatl_GetUcdProperty_Sentence_Break(c) \
    Coatl_GetUcdProperty_SB(c)

/**
 * Get value of UCD property '**Script**' for given codepoint.
 * Alias for property UCD property accessor '**Sc**'
 *
 * @param c Codepoint to get UCD property value for.
 *
 * @return Value of UCD property '**Script**'.
 *
 * @see COATL_UCD_SC
 * @see Coatl_GetUcdProperty_Sc
 * @see COATL_UCD_SCRIPT
 */
#define Coatl_GetUcdProperty_Script(c) \
    Coatl_GetUcdProperty_Sc(c)

/**
 * Get value of UCD property '**Simple_Case_Folding**' for given codepoint.
 * Alias for property UCD property accessor '**Scf**'
 *
 * @param c Codepoint to get UCD property value for.
 *
 * @return Value of UCD property '**Simple_Case_Folding**'.
 *
 * @see COATL_UCD_SCF
 * @see Coatl_GetUcdProperty_Scf
 * @see COATL_UCD_SIMPLE_CASE_FOLDING
 */
#define Coatl_GetUcdProperty_Simple_Case_Folding(c) \
    Coatl_GetUcdProperty_Scf(c)

/**
 * Get value of UCD property '**sfc**' for given codepoint.
 * Alias for property UCD property accessor '**Scf**'
 *
 * @param c Codepoint to get UCD property value for.
 *
 * @return Value of UCD property '**sfc**'.
 *
 * @see COATL_UCD_SCF
 * @see Coatl_GetUcdProperty_Scf
 * @see COATL_UCD_SFC
 */
#define Coatl_GetUcdProperty_Sfc(c) \
    Coatl_GetUcdProperty_Scf(c)

/**
 * Get value of UCD property '**Script_Extensions**' for given codepoint.
 * Alias for property UCD property accessor '**Scx**'
 *
 * @param c Codepoint to get UCD property value for.
 *
 * @return Value of UCD property '**Script_Extensions**'.
 *
 * @see COATL_UCD_SCX
 * @see Coatl_GetUcdProperty_Scx
 * @see COATL_UCD_SCRIPT_EXTENSIONS
 */
#define Coatl_GetUcdProperty_Script_Extensions(c) \
    Coatl_GetUcdProperty_Scx(c)

/**
 * Get value of UCD property '**Soft_Dotted**' for given codepoint.
 * Alias for property UCD property accessor '**SD**'
 *
 * @param c Codepoint to get UCD property value for.
 *
 * @return Value of UCD property '**Soft_Dotted**'.
 *
 * @see COATL_UCD_SD
 * @see Coatl_GetUcdProperty_SD
 * @see COATL_UCD_SOFT_DOTTED
 */
#define Coatl_GetUcdProperty_Soft_Dotted(c) \
    Coatl_GetUcdProperty_SD(c)

/**
 * Get value of UCD property '**Simple_Lowercase_Mapping**' for given codepoint.
 * Alias for property UCD property accessor '**Slc**'
 *
 * @param c Codepoint to get UCD property value for.
 *
 * @return Value of UCD property '**Simple_Lowercase_Mapping**'.
 *
 * @see COATL_UCD_SLC
 * @see Coatl_GetUcdProperty_Slc
 * @see COATL_UCD_SIMPLE_LOWERCASE_MAPPING
 */
#define Coatl_GetUcdProperty_Simple_Lowercase_Mapping(c) \
    Coatl_GetUcdProperty_Slc(c)

/**
 * Get value of UCD property '**Simple_Titlecase_Mapping**' for given codepoint.
 * Alias for property UCD property accessor '**Stc**'
 *
 * @param c Codepoint to get UCD property value for.
 *
 * @return Value of UCD property '**Simple_Titlecase_Mapping**'.
 *
 * @see COATL_UCD_STC
 * @see Coatl_GetUcdProperty_Stc
 * @see COATL_UCD_SIMPLE_TITLECASE_MAPPING
 */
#define Coatl_GetUcdProperty_Simple_Titlecase_Mapping(c) \
    Coatl_GetUcdProperty_Stc(c)

/**
 * Get value of UCD property '**Sentence_Terminal**' for given codepoint.
 * Alias for property UCD property accessor '**STerm**'
 *
 * @param c Codepoint to get UCD property value for.
 *
 * @return Value of UCD property '**Sentence_Terminal**'.
 *
 * @see COATL_UCD_STERM
 * @see Coatl_GetUcdProperty_STerm
 * @see COATL_UCD_SENTENCE_TERMINAL
 */
#define Coatl_GetUcdProperty_Sentence_Terminal(c) \
    Coatl_GetUcdProperty_STerm(c)

/**
 * Get value of UCD property '**Simple_Uppercase_Mapping**' for given codepoint.
 * Alias for property UCD property accessor '**Suc**'
 *
 * @param c Codepoint to get UCD property value for.
 *
 * @return Value of UCD property '**Simple_Uppercase_Mapping**'.
 *
 * @see COATL_UCD_SUC
 * @see Coatl_GetUcdProperty_Suc
 * @see COATL_UCD_SIMPLE_UPPERCASE_MAPPING
 */
#define Coatl_GetUcdProperty_Simple_Uppercase_Mapping(c) \
    Coatl_GetUcdProperty_Suc(c)

/**
 * Get value of UCD property '**Titlecase_Mapping**' for given codepoint.
 * Alias for property UCD property accessor '**Tc**'
 *
 * @param c Codepoint to get UCD property value for.
 *
 * @return Value of UCD property '**Titlecase_Mapping**'.
 *
 * @see COATL_UCD_TC
 * @see Coatl_GetUcdProperty_Tc
 * @see COATL_UCD_TITLECASE_MAPPING
 */
#define Coatl_GetUcdProperty_Titlecase_Mapping(c) \
    Coatl_GetUcdProperty_Tc(c)

/**
 * Get value of UCD property '**Terminal_Punctuation**' for given codepoint.
 * Alias for property UCD property accessor '**Term**'
 *
 * @param c Codepoint to get UCD property value for.
 *
 * @return Value of UCD property '**Terminal_Punctuation**'.
 *
 * @see COATL_UCD_TERM
 * @see Coatl_GetUcdProperty_Term
 * @see COATL_UCD_TERMINAL_PUNCTUATION
 */
#define Coatl_GetUcdProperty_Terminal_Punctuation(c) \
    Coatl_GetUcdProperty_Term(c)

/**
 * Get value of UCD property '**Uppercase_Mapping**' for given codepoint.
 * Alias for property UCD property accessor '**Uc**'
 *
 * @param c Codepoint to get UCD property value for.
 *
 * @return Value of UCD property '**Uppercase_Mapping**'.
 *
 * @see COATL_UCD_UC
 * @see Coatl_GetUcdProperty_Uc
 * @see COATL_UCD_UPPERCASE_MAPPING
 */
#define Coatl_GetUcdProperty_Uppercase_Mapping(c) \
    Coatl_GetUcdProperty_Uc(c)

/**
 * Get value of UCD property '**Unified_Ideograph**' for given codepoint.
 * Alias for property UCD property accessor '**UIdeo**'
 *
 * @param c Codepoint to get UCD property value for.
 *
 * @return Value of UCD property '**Unified_Ideograph**'.
 *
 * @see COATL_UCD_UIDEO
 * @see Coatl_GetUcdProperty_UIdeo
 * @see COATL_UCD_UNIFIED_IDEOGRAPH
 */
#define Coatl_GetUcdProperty_Unified_Ideograph(c) \
    Coatl_GetUcdProperty_UIdeo(c)

/**
 * Get value of UCD property '**Uppercase**' for given codepoint.
 * Alias for property UCD property accessor '**Upper**'
 *
 * @param c Codepoint to get UCD property value for.
 *
 * @return Value of UCD property '**Uppercase**'.
 *
 * @see COATL_UCD_UPPER
 * @see Coatl_GetUcdProperty_Upper
 * @see COATL_UCD_UPPERCASE
 */
#define Coatl_GetUcdProperty_Uppercase(c) \
    Coatl_GetUcdProperty_Upper(c)

/**
 * Get value of UCD property '**Variation_Selector**' for given codepoint.
 * Alias for property UCD property accessor '**VS**'
 *
 * @param c Codepoint to get UCD property value for.
 *
 * @return Value of UCD property '**Variation_Selector**'.
 *
 * @see COATL_UCD_VS
 * @see Coatl_GetUcdProperty_VS
 * @see COATL_UCD_VARIATION_SELECTOR
 */
#define Coatl_GetUcdProperty_Variation_Selector(c) \
    Coatl_GetUcdProperty_VS(c)

/**
 * Get value of UCD property '**Word_Break**' for given codepoint.
 * Alias for property UCD property accessor '**WB**'
 *
 * @param c Codepoint to get UCD property value for.
 *
 * @return Value of UCD property '**Word_Break**'.
 *
 * @see COATL_UCD_WB
 * @see Coatl_GetUcdProperty_WB
 * @see COATL_UCD_WORD_BREAK
 */
#define Coatl_GetUcdProperty_Word_Break(c) \
    Coatl_GetUcdProperty_WB(c)

/**
 * Get value of UCD property '**White_Space**' for given codepoint.
 * Alias for property UCD property accessor '**WSpace**'
 *
 * @param c Codepoint to get UCD property value for.
 *
 * @return Value of UCD property '**White_Space**'.
 *
 * @see COATL_UCD_WSPACE
 * @see Coatl_GetUcdProperty_WSpace
 * @see COATL_UCD_WHITE_SPACE
 */
#define Coatl_GetUcdProperty_White_Space(c) \
    Coatl_GetUcdProperty_WSpace(c)

/**
 * Get value of UCD property '**space**' for given codepoint.
 * Alias for property UCD property accessor '**WSpace**'
 *
 * @param c Codepoint to get UCD property value for.
 *
 * @return Value of UCD property '**space**'.
 *
 * @see COATL_UCD_WSPACE
 * @see Coatl_GetUcdProperty_WSpace
 * @see COATL_UCD_SPACE
 */
#define Coatl_GetUcdProperty_Space(c) \
    Coatl_GetUcdProperty_WSpace(c)

/**
 * Get value of UCD property '**XID_Continue**' for given codepoint.
 * Alias for property UCD property accessor '**XIDC**'
 *
 * @param c Codepoint to get UCD property value for.
 *
 * @return Value of UCD property '**XID_Continue**'.
 *
 * @see COATL_UCD_XIDC
 * @see Coatl_GetUcdProperty_XIDC
 * @see COATL_UCD_XID_CONTINUE
 */
#define Coatl_GetUcdProperty_XID_Continue(c) \
    Coatl_GetUcdProperty_XIDC(c)

/**
 * Get value of UCD property '**XID_Start**' for given codepoint.
 * Alias for property UCD property accessor '**XIDS**'
 *
 * @param c Codepoint to get UCD property value for.
 *
 * @return Value of UCD property '**XID_Start**'.
 *
 * @see COATL_UCD_XIDS
 * @see Coatl_GetUcdProperty_XIDS
 * @see COATL_UCD_XID_START
 */
#define Coatl_GetUcdProperty_XID_Start(c) \
    Coatl_GetUcdProperty_XIDS(c)

/**
 * Get value of UCD property '**Bidi_Paired_Bracket**' for given codepoint.
 * Alias for property UCD property accessor '**Bpb**'
 *
 * @param c Codepoint to get UCD property value for.
 *
 * @return Value of UCD property '**Bidi_Paired_Bracket**'.
 *
 * @see COATL_UCD_BPB
 * @see Coatl_GetUcdProperty_Bpb
 * @see COATL_UCD_BIDI_PAIRED_BRACKET
 */
#define Coatl_GetUcdProperty_Bidi_Paired_Bracket(c) \
    Coatl_GetUcdProperty_Bpb(c)

/**
 * Get value of UCD property '**Bidi_Paired_Bracket_Type**' for given codepoint.
 * Alias for property UCD property accessor '**Bpt**'
 *
 * @param c Codepoint to get UCD property value for.
 *
 * @return Value of UCD property '**Bidi_Paired_Bracket_Type**'.
 *
 * @see COATL_UCD_BPT
 * @see Coatl_GetUcdProperty_Bpt
 * @see COATL_UCD_BIDI_PAIRED_BRACKET_TYPE
 */
#define Coatl_GetUcdProperty_Bidi_Paired_Bracket_Type(c) \
    Coatl_GetUcdProperty_Bpt(c)

/**
 * Get value of UCD property '**Prepended_Concatenation_Mark**' for given codepoint.
 * Alias for property UCD property accessor '**PCM**'
 *
 * @param c Codepoint to get UCD property value for.
 *
 * @return Value of UCD property '**Prepended_Concatenation_Mark**'.
 *
 * @see COATL_UCD_PCM
 * @see Coatl_GetUcdProperty_PCM
 * @see COATL_UCD_PREPENDED_CONCATENATION_MARK
 */
#define Coatl_GetUcdProperty_Prepended_Concatenation_Mark(c) \
    Coatl_GetUcdProperty_PCM(c)

/* End of UCD Property Accessors *//*!\}*/

/* End of Unicode Character Database *//*!\}*/

#endif /* _COATL_UCD */
