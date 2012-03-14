/*
 * Header: coatlUcdProperties.h
 *
 *	This header file describes Unicode character properties and values.
 *
 *	It is automatically generated from the Unicode Character Database (UCD)
 *	using the file *coatlUcdProperties.tcl*; Do not modify.
 */

#ifndef _COATL_UCDPROPERTIES
#define _COATL_UCDPROPERTIES


/****************************************************************************
 * Section: UCD Properties
 *
 *	Unicode Character Database (UCD) property types & values.
 ****************************************************************************/

/*---------------------------------------------------------------------------
 * Enum: Coatl_UcdProperty
 *
 *	Unicode character properties.
 *
 *	Names are automatically generated from the UCD file
 *	*PropertyAliases.txt*
 *
 *  COATL_UCD_AGE - '*age*', '*Age*'
 *  COATL_UCD_AHEX - '*AHex*', '*ASCII_Hex_Digit*'
 *  COATL_UCD_ASCII_HEX_DIGIT - Alias for <COATL_UCD_AHEX>
 *  COATL_UCD_ALPHA - '*Alpha*', '*Alphabetic*'
 *  COATL_UCD_ALPHABETIC - Alias for <COATL_UCD_ALPHA>
 *  COATL_UCD_BC - '*bc*', '*Bidi_Class*'
 *  COATL_UCD_BIDI_CLASS - Alias for <COATL_UCD_BC>
 *  COATL_UCD_BIDI_C - '*Bidi_C*', '*Bidi_Control*'
 *  COATL_UCD_BIDI_CONTROL - Alias for <COATL_UCD_BIDI_C>
 *  COATL_UCD_BIDI_M - '*Bidi_M*', '*Bidi_Mirrored*'
 *  COATL_UCD_BIDI_MIRRORED - Alias for <COATL_UCD_BIDI_M>
 *  COATL_UCD_BLK - '*blk*', '*Block*'
 *  COATL_UCD_BLOCK - Alias for <COATL_UCD_BLK>
 *  COATL_UCD_BMG - '*bmg*', '*Bidi_Mirroring_Glyph*'
 *  COATL_UCD_BIDI_MIRRORING_GLYPH - Alias for <COATL_UCD_BMG>
 *  COATL_UCD_CASED - '*Cased*', '*Cased*'
 *  COATL_UCD_CCC - '*ccc*', '*Canonical_Combining_Class*'
 *  COATL_UCD_CANONICAL_COMBINING_CLASS - Alias for <COATL_UCD_CCC>
 *  COATL_UCD_CE - '*CE*', '*Composition_Exclusion*'
 *  COATL_UCD_COMPOSITION_EXCLUSION - Alias for <COATL_UCD_CE>
 *  COATL_UCD_CF - '*cf*', '*Case_Folding*'
 *  COATL_UCD_CASE_FOLDING - Alias for <COATL_UCD_CF>
 *  COATL_UCD_CI - '*CI*', '*Case_Ignorable*'
 *  COATL_UCD_CASE_IGNORABLE - Alias for <COATL_UCD_CI>
 *  COATL_UCD_COMP_EX - '*Comp_Ex*', '*Full_Composition_Exclusion*'
 *  COATL_UCD_FULL_COMPOSITION_EXCLUSION - Alias for <COATL_UCD_COMP_EX>
 *  COATL_UCD_CWCF - '*CWCF*', '*Changes_When_Casefolded*'
 *  COATL_UCD_CHANGES_WHEN_CASEFOLDED - Alias for <COATL_UCD_CWCF>
 *  COATL_UCD_CWCM - '*CWCM*', '*Changes_When_Casemapped*'
 *  COATL_UCD_CHANGES_WHEN_CASEMAPPED - Alias for <COATL_UCD_CWCM>
 *  COATL_UCD_CWKCF - '*CWKCF*', '*Changes_When_NFKC_Casefolded*'
 *  COATL_UCD_CHANGES_WHEN_NFKC_CASEFOLDED - Alias for <COATL_UCD_CWKCF>
 *  COATL_UCD_CWL - '*CWL*', '*Changes_When_Lowercased*'
 *  COATL_UCD_CHANGES_WHEN_LOWERCASED - Alias for <COATL_UCD_CWL>
 *  COATL_UCD_CWT - '*CWT*', '*Changes_When_Titlecased*'
 *  COATL_UCD_CHANGES_WHEN_TITLECASED - Alias for <COATL_UCD_CWT>
 *  COATL_UCD_CWU - '*CWU*', '*Changes_When_Uppercased*'
 *  COATL_UCD_CHANGES_WHEN_UPPERCASED - Alias for <COATL_UCD_CWU>
 *  COATL_UCD_DASH - '*Dash*', '*Dash*'
 *  COATL_UCD_DEP - '*Dep*', '*Deprecated*'
 *  COATL_UCD_DEPRECATED - Alias for <COATL_UCD_DEP>
 *  COATL_UCD_DI - '*DI*', '*Default_Ignorable_Code_Point*'
 *  COATL_UCD_DEFAULT_IGNORABLE_CODE_POINT - Alias for <COATL_UCD_DI>
 *  COATL_UCD_DIA - '*Dia*', '*Diacritic*'
 *  COATL_UCD_DIACRITIC - Alias for <COATL_UCD_DIA>
 *  COATL_UCD_DM - '*dm*', '*Decomposition_Mapping*'
 *  COATL_UCD_DECOMPOSITION_MAPPING - Alias for <COATL_UCD_DM>
 *  COATL_UCD_DT - '*dt*', '*Decomposition_Type*'
 *  COATL_UCD_DECOMPOSITION_TYPE - Alias for <COATL_UCD_DT>
 *  COATL_UCD_EA - '*ea*', '*East_Asian_Width*'
 *  COATL_UCD_EAST_ASIAN_WIDTH - Alias for <COATL_UCD_EA>
 *  COATL_UCD_EXT - '*Ext*', '*Extender*'
 *  COATL_UCD_EXTENDER - Alias for <COATL_UCD_EXT>
 *  COATL_UCD_GC - '*gc*', '*General_Category*'
 *  COATL_UCD_GENERAL_CATEGORY - Alias for <COATL_UCD_GC>
 *  COATL_UCD_GCB - '*GCB*', '*Grapheme_Cluster_Break*'
 *  COATL_UCD_GRAPHEME_CLUSTER_BREAK - Alias for <COATL_UCD_GCB>
 *  COATL_UCD_GR_BASE - '*Gr_Base*', '*Grapheme_Base*'
 *  COATL_UCD_GRAPHEME_BASE - Alias for <COATL_UCD_GR_BASE>
 *  COATL_UCD_GR_EXT - '*Gr_Ext*', '*Grapheme_Extend*'
 *  COATL_UCD_GRAPHEME_EXTEND - Alias for <COATL_UCD_GR_EXT>
 *  COATL_UCD_HEX - '*Hex*', '*Hex_Digit*'
 *  COATL_UCD_HEX_DIGIT - Alias for <COATL_UCD_HEX>
 *  COATL_UCD_HST - '*hst*', '*Hangul_Syllable_Type*'
 *  COATL_UCD_HANGUL_SYLLABLE_TYPE - Alias for <COATL_UCD_HST>
 *  COATL_UCD_IDC - '*IDC*', '*ID_Continue*'
 *  COATL_UCD_ID_CONTINUE - Alias for <COATL_UCD_IDC>
 *  COATL_UCD_IDEO - '*Ideo*', '*Ideographic*'
 *  COATL_UCD_IDEOGRAPHIC - Alias for <COATL_UCD_IDEO>
 *  COATL_UCD_IDS - '*IDS*', '*ID_Start*'
 *  COATL_UCD_ID_START - Alias for <COATL_UCD_IDS>
 *  COATL_UCD_IDSB - '*IDSB*', '*IDS_Binary_Operator*'
 *  COATL_UCD_IDS_BINARY_OPERATOR - Alias for <COATL_UCD_IDSB>
 *  COATL_UCD_IDST - '*IDST*', '*IDS_Trinary_Operator*'
 *  COATL_UCD_IDS_TRINARY_OPERATOR - Alias for <COATL_UCD_IDST>
 *  COATL_UCD_INMC - '*InMC*', '*Indic_Matra_Category*'
 *  COATL_UCD_INDIC_MATRA_CATEGORY - Alias for <COATL_UCD_INMC>
 *  COATL_UCD_INSC - '*InSC*', '*Indic_Syllabic_Category*'
 *  COATL_UCD_INDIC_SYLLABIC_CATEGORY - Alias for <COATL_UCD_INSC>
 *  COATL_UCD_JG - '*jg*', '*Joining_Group*'
 *  COATL_UCD_JOINING_GROUP - Alias for <COATL_UCD_JG>
 *  COATL_UCD_JOIN_C - '*Join_C*', '*Join_Control*'
 *  COATL_UCD_JOIN_CONTROL - Alias for <COATL_UCD_JOIN_C>
 *  COATL_UCD_JSN - '*JSN*', '*Jamo_Short_Name*'
 *  COATL_UCD_JAMO_SHORT_NAME - Alias for <COATL_UCD_JSN>
 *  COATL_UCD_JT - '*jt*', '*Joining_Type*'
 *  COATL_UCD_JOINING_TYPE - Alias for <COATL_UCD_JT>
 *  COATL_UCD_LB - '*lb*', '*Line_Break*'
 *  COATL_UCD_LINE_BREAK - Alias for <COATL_UCD_LB>
 *  COATL_UCD_LC - '*lc*', '*Lowercase_Mapping*'
 *  COATL_UCD_LOWERCASE_MAPPING - Alias for <COATL_UCD_LC>
 *  COATL_UCD_LOE - '*LOE*', '*Logical_Order_Exception*'
 *  COATL_UCD_LOGICAL_ORDER_EXCEPTION - Alias for <COATL_UCD_LOE>
 *  COATL_UCD_LOWER - '*Lower*', '*Lowercase*'
 *  COATL_UCD_LOWERCASE - Alias for <COATL_UCD_LOWER>
 *  COATL_UCD_MATH - '*Math*', '*Math*'
 *  COATL_UCD_NA - '*na*', '*Name*'
 *  COATL_UCD_NAME - Alias for <COATL_UCD_NA>
 *  COATL_UCD_NA1 - '*na1*', '*Unicode_1_Name*'
 *  COATL_UCD_UNICODE_1_NAME - Alias for <COATL_UCD_NA1>
 *  COATL_UCD_NAME_ALIAS - '*Name_Alias*', '*Name_Alias*'
 *  COATL_UCD_NCHAR - '*NChar*', '*Noncharacter_Code_Point*'
 *  COATL_UCD_NONCHARACTER_CODE_POINT - Alias for <COATL_UCD_NCHAR>
 *  COATL_UCD_NFC_QC - '*NFC_QC*', '*NFC_Quick_Check*'
 *  COATL_UCD_NFC_QUICK_CHECK - Alias for <COATL_UCD_NFC_QC>
 *  COATL_UCD_NFD_QC - '*NFD_QC*', '*NFD_Quick_Check*'
 *  COATL_UCD_NFD_QUICK_CHECK - Alias for <COATL_UCD_NFD_QC>
 *  COATL_UCD_NFKC_CF - '*NFKC_CF*', '*NFKC_Casefold*'
 *  COATL_UCD_NFKC_CASEFOLD - Alias for <COATL_UCD_NFKC_CF>
 *  COATL_UCD_NFKC_QC - '*NFKC_QC*', '*NFKC_Quick_Check*'
 *  COATL_UCD_NFKC_QUICK_CHECK - Alias for <COATL_UCD_NFKC_QC>
 *  COATL_UCD_NFKD_QC - '*NFKD_QC*', '*NFKD_Quick_Check*'
 *  COATL_UCD_NFKD_QUICK_CHECK - Alias for <COATL_UCD_NFKD_QC>
 *  COATL_UCD_NT - '*nt*', '*Numeric_Type*'
 *  COATL_UCD_NUMERIC_TYPE - Alias for <COATL_UCD_NT>
 *  COATL_UCD_NV - '*nv*', '*Numeric_Value*'
 *  COATL_UCD_NUMERIC_VALUE - Alias for <COATL_UCD_NV>
 *  COATL_UCD_OALPHA - '*OAlpha*', '*Other_Alphabetic*'
 *  COATL_UCD_OTHER_ALPHABETIC - Alias for <COATL_UCD_OALPHA>
 *  COATL_UCD_ODI - '*ODI*', '*Other_Default_Ignorable_Code_Point*'
 *  COATL_UCD_OTHER_DEFAULT_IGNORABLE_CODE_POINT - Alias for <COATL_UCD_ODI>
 *  COATL_UCD_OGR_EXT - '*OGr_Ext*', '*Other_Grapheme_Extend*'
 *  COATL_UCD_OTHER_GRAPHEME_EXTEND - Alias for <COATL_UCD_OGR_EXT>
 *  COATL_UCD_OIDC - '*OIDC*', '*Other_ID_Continue*'
 *  COATL_UCD_OTHER_ID_CONTINUE - Alias for <COATL_UCD_OIDC>
 *  COATL_UCD_OIDS - '*OIDS*', '*Other_ID_Start*'
 *  COATL_UCD_OTHER_ID_START - Alias for <COATL_UCD_OIDS>
 *  COATL_UCD_OLOWER - '*OLower*', '*Other_Lowercase*'
 *  COATL_UCD_OTHER_LOWERCASE - Alias for <COATL_UCD_OLOWER>
 *  COATL_UCD_OMATH - '*OMath*', '*Other_Math*'
 *  COATL_UCD_OTHER_MATH - Alias for <COATL_UCD_OMATH>
 *  COATL_UCD_OUPPER - '*OUpper*', '*Other_Uppercase*'
 *  COATL_UCD_OTHER_UPPERCASE - Alias for <COATL_UCD_OUPPER>
 *  COATL_UCD_PAT_SYN - '*Pat_Syn*', '*Pattern_Syntax*'
 *  COATL_UCD_PATTERN_SYNTAX - Alias for <COATL_UCD_PAT_SYN>
 *  COATL_UCD_PAT_WS - '*Pat_WS*', '*Pattern_White_Space*'
 *  COATL_UCD_PATTERN_WHITE_SPACE - Alias for <COATL_UCD_PAT_WS>
 *  COATL_UCD_QMARK - '*QMark*', '*Quotation_Mark*'
 *  COATL_UCD_QUOTATION_MARK - Alias for <COATL_UCD_QMARK>
 *  COATL_UCD_RADICAL - '*Radical*', '*Radical*'
 *  COATL_UCD_SB - '*SB*', '*Sentence_Break*'
 *  COATL_UCD_SENTENCE_BREAK - Alias for <COATL_UCD_SB>
 *  COATL_UCD_SC - '*sc*', '*Script*'
 *  COATL_UCD_SCRIPT - Alias for <COATL_UCD_SC>
 *  COATL_UCD_SCF - '*scf*', '*Simple_Case_Folding*', '*sfc*'
 *  COATL_UCD_SIMPLE_CASE_FOLDING - Alias for <COATL_UCD_SCF>
 *  COATL_UCD_SFC - Alias for <COATL_UCD_SCF>
 *  COATL_UCD_SCX - '*scx*', '*Script_Extensions*'
 *  COATL_UCD_SCRIPT_EXTENSIONS - Alias for <COATL_UCD_SCX>
 *  COATL_UCD_SD - '*SD*', '*Soft_Dotted*'
 *  COATL_UCD_SOFT_DOTTED - Alias for <COATL_UCD_SD>
 *  COATL_UCD_SLC - '*slc*', '*Simple_Lowercase_Mapping*'
 *  COATL_UCD_SIMPLE_LOWERCASE_MAPPING - Alias for <COATL_UCD_SLC>
 *  COATL_UCD_STC - '*stc*', '*Simple_Titlecase_Mapping*'
 *  COATL_UCD_SIMPLE_TITLECASE_MAPPING - Alias for <COATL_UCD_STC>
 *  COATL_UCD_STERM - '*STerm*', '*STerm*'
 *  COATL_UCD_SUC - '*suc*', '*Simple_Uppercase_Mapping*'
 *  COATL_UCD_SIMPLE_UPPERCASE_MAPPING - Alias for <COATL_UCD_SUC>
 *  COATL_UCD_TC - '*tc*', '*Titlecase_Mapping*'
 *  COATL_UCD_TITLECASE_MAPPING - Alias for <COATL_UCD_TC>
 *  COATL_UCD_TERM - '*Term*', '*Terminal_Punctuation*'
 *  COATL_UCD_TERMINAL_PUNCTUATION - Alias for <COATL_UCD_TERM>
 *  COATL_UCD_UC - '*uc*', '*Uppercase_Mapping*'
 *  COATL_UCD_UPPERCASE_MAPPING - Alias for <COATL_UCD_UC>
 *  COATL_UCD_UIDEO - '*UIdeo*', '*Unified_Ideograph*'
 *  COATL_UCD_UNIFIED_IDEOGRAPH - Alias for <COATL_UCD_UIDEO>
 *  COATL_UCD_UPPER - '*Upper*', '*Uppercase*'
 *  COATL_UCD_UPPERCASE - Alias for <COATL_UCD_UPPER>
 *  COATL_UCD_VS - '*VS*', '*Variation_Selector*'
 *  COATL_UCD_VARIATION_SELECTOR - Alias for <COATL_UCD_VS>
 *  COATL_UCD_WB - '*WB*', '*Word_Break*'
 *  COATL_UCD_WORD_BREAK - Alias for <COATL_UCD_WB>
 *  COATL_UCD_WSPACE - '*WSpace*', '*White_Space*', '*space*'
 *  COATL_UCD_WHITE_SPACE - Alias for <COATL_UCD_WSPACE>
 *  COATL_UCD_SPACE - Alias for <COATL_UCD_WSPACE>
 *  COATL_UCD_XIDC - '*XIDC*', '*XID_Continue*'
 *  COATL_UCD_XID_CONTINUE - Alias for <COATL_UCD_XIDC>
 *  COATL_UCD_XIDS - '*XIDS*', '*XID_Start*'
 *  COATL_UCD_XID_START - Alias for <COATL_UCD_XIDS> 
 *---------------------------------------------------------------------------*/
 
typedef enum Coatl_UcdProperty {
    COATL_UCD_AGE=1,
    COATL_UCD_AHEX=2,
	COATL_UCD_ASCII_HEX_DIGIT=COATL_UCD_AHEX,
    COATL_UCD_ALPHA=3,
	COATL_UCD_ALPHABETIC=COATL_UCD_ALPHA,
    COATL_UCD_BC=4,
	COATL_UCD_BIDI_CLASS=COATL_UCD_BC,
    COATL_UCD_BIDI_C=5,
	COATL_UCD_BIDI_CONTROL=COATL_UCD_BIDI_C,
    COATL_UCD_BIDI_M=6,
	COATL_UCD_BIDI_MIRRORED=COATL_UCD_BIDI_M,
    COATL_UCD_BLK=7,
	COATL_UCD_BLOCK=COATL_UCD_BLK,
    COATL_UCD_BMG=8,
	COATL_UCD_BIDI_MIRRORING_GLYPH=COATL_UCD_BMG,
    COATL_UCD_CASED=9,
    COATL_UCD_CCC=10,
	COATL_UCD_CANONICAL_COMBINING_CLASS=COATL_UCD_CCC,
    COATL_UCD_CE=11,
	COATL_UCD_COMPOSITION_EXCLUSION=COATL_UCD_CE,
    COATL_UCD_CF=12,
	COATL_UCD_CASE_FOLDING=COATL_UCD_CF,
    COATL_UCD_CI=13,
	COATL_UCD_CASE_IGNORABLE=COATL_UCD_CI,
    COATL_UCD_COMP_EX=14,
	COATL_UCD_FULL_COMPOSITION_EXCLUSION=COATL_UCD_COMP_EX,
    COATL_UCD_CWCF=15,
	COATL_UCD_CHANGES_WHEN_CASEFOLDED=COATL_UCD_CWCF,
    COATL_UCD_CWCM=16,
	COATL_UCD_CHANGES_WHEN_CASEMAPPED=COATL_UCD_CWCM,
    COATL_UCD_CWKCF=17,
	COATL_UCD_CHANGES_WHEN_NFKC_CASEFOLDED=COATL_UCD_CWKCF,
    COATL_UCD_CWL=18,
	COATL_UCD_CHANGES_WHEN_LOWERCASED=COATL_UCD_CWL,
    COATL_UCD_CWT=19,
	COATL_UCD_CHANGES_WHEN_TITLECASED=COATL_UCD_CWT,
    COATL_UCD_CWU=20,
	COATL_UCD_CHANGES_WHEN_UPPERCASED=COATL_UCD_CWU,
    COATL_UCD_DASH=21,
    COATL_UCD_DEP=22,
	COATL_UCD_DEPRECATED=COATL_UCD_DEP,
    COATL_UCD_DI=23,
	COATL_UCD_DEFAULT_IGNORABLE_CODE_POINT=COATL_UCD_DI,
    COATL_UCD_DIA=24,
	COATL_UCD_DIACRITIC=COATL_UCD_DIA,
    COATL_UCD_DM=25,
	COATL_UCD_DECOMPOSITION_MAPPING=COATL_UCD_DM,
    COATL_UCD_DT=26,
	COATL_UCD_DECOMPOSITION_TYPE=COATL_UCD_DT,
    COATL_UCD_EA=27,
	COATL_UCD_EAST_ASIAN_WIDTH=COATL_UCD_EA,
    COATL_UCD_EXT=28,
	COATL_UCD_EXTENDER=COATL_UCD_EXT,
    COATL_UCD_GC=29,
	COATL_UCD_GENERAL_CATEGORY=COATL_UCD_GC,
    COATL_UCD_GCB=30,
	COATL_UCD_GRAPHEME_CLUSTER_BREAK=COATL_UCD_GCB,
    COATL_UCD_GR_BASE=31,
	COATL_UCD_GRAPHEME_BASE=COATL_UCD_GR_BASE,
    COATL_UCD_GR_EXT=32,
	COATL_UCD_GRAPHEME_EXTEND=COATL_UCD_GR_EXT,
    COATL_UCD_HEX=33,
	COATL_UCD_HEX_DIGIT=COATL_UCD_HEX,
    COATL_UCD_HST=34,
	COATL_UCD_HANGUL_SYLLABLE_TYPE=COATL_UCD_HST,
    COATL_UCD_IDC=35,
	COATL_UCD_ID_CONTINUE=COATL_UCD_IDC,
    COATL_UCD_IDEO=36,
	COATL_UCD_IDEOGRAPHIC=COATL_UCD_IDEO,
    COATL_UCD_IDS=37,
	COATL_UCD_ID_START=COATL_UCD_IDS,
    COATL_UCD_IDSB=38,
	COATL_UCD_IDS_BINARY_OPERATOR=COATL_UCD_IDSB,
    COATL_UCD_IDST=39,
	COATL_UCD_IDS_TRINARY_OPERATOR=COATL_UCD_IDST,
    COATL_UCD_INMC=40,
	COATL_UCD_INDIC_MATRA_CATEGORY=COATL_UCD_INMC,
    COATL_UCD_INSC=41,
	COATL_UCD_INDIC_SYLLABIC_CATEGORY=COATL_UCD_INSC,
    COATL_UCD_JG=42,
	COATL_UCD_JOINING_GROUP=COATL_UCD_JG,
    COATL_UCD_JOIN_C=43,
	COATL_UCD_JOIN_CONTROL=COATL_UCD_JOIN_C,
    COATL_UCD_JSN=44,
	COATL_UCD_JAMO_SHORT_NAME=COATL_UCD_JSN,
    COATL_UCD_JT=45,
	COATL_UCD_JOINING_TYPE=COATL_UCD_JT,
    COATL_UCD_LB=46,
	COATL_UCD_LINE_BREAK=COATL_UCD_LB,
    COATL_UCD_LC=47,
	COATL_UCD_LOWERCASE_MAPPING=COATL_UCD_LC,
    COATL_UCD_LOE=48,
	COATL_UCD_LOGICAL_ORDER_EXCEPTION=COATL_UCD_LOE,
    COATL_UCD_LOWER=49,
	COATL_UCD_LOWERCASE=COATL_UCD_LOWER,
    COATL_UCD_MATH=50,
    COATL_UCD_NA=51,
	COATL_UCD_NAME=COATL_UCD_NA,
    COATL_UCD_NA1=52,
	COATL_UCD_UNICODE_1_NAME=COATL_UCD_NA1,
    COATL_UCD_NAME_ALIAS=53,
    COATL_UCD_NCHAR=54,
	COATL_UCD_NONCHARACTER_CODE_POINT=COATL_UCD_NCHAR,
    COATL_UCD_NFC_QC=55,
	COATL_UCD_NFC_QUICK_CHECK=COATL_UCD_NFC_QC,
    COATL_UCD_NFD_QC=56,
	COATL_UCD_NFD_QUICK_CHECK=COATL_UCD_NFD_QC,
    COATL_UCD_NFKC_CF=57,
	COATL_UCD_NFKC_CASEFOLD=COATL_UCD_NFKC_CF,
    COATL_UCD_NFKC_QC=58,
	COATL_UCD_NFKC_QUICK_CHECK=COATL_UCD_NFKC_QC,
    COATL_UCD_NFKD_QC=59,
	COATL_UCD_NFKD_QUICK_CHECK=COATL_UCD_NFKD_QC,
    COATL_UCD_NT=60,
	COATL_UCD_NUMERIC_TYPE=COATL_UCD_NT,
    COATL_UCD_NV=61,
	COATL_UCD_NUMERIC_VALUE=COATL_UCD_NV,
    COATL_UCD_OALPHA=62,
	COATL_UCD_OTHER_ALPHABETIC=COATL_UCD_OALPHA,
    COATL_UCD_ODI=63,
	COATL_UCD_OTHER_DEFAULT_IGNORABLE_CODE_POINT=COATL_UCD_ODI,
    COATL_UCD_OGR_EXT=64,
	COATL_UCD_OTHER_GRAPHEME_EXTEND=COATL_UCD_OGR_EXT,
    COATL_UCD_OIDC=65,
	COATL_UCD_OTHER_ID_CONTINUE=COATL_UCD_OIDC,
    COATL_UCD_OIDS=66,
	COATL_UCD_OTHER_ID_START=COATL_UCD_OIDS,
    COATL_UCD_OLOWER=67,
	COATL_UCD_OTHER_LOWERCASE=COATL_UCD_OLOWER,
    COATL_UCD_OMATH=68,
	COATL_UCD_OTHER_MATH=COATL_UCD_OMATH,
    COATL_UCD_OUPPER=69,
	COATL_UCD_OTHER_UPPERCASE=COATL_UCD_OUPPER,
    COATL_UCD_PAT_SYN=70,
	COATL_UCD_PATTERN_SYNTAX=COATL_UCD_PAT_SYN,
    COATL_UCD_PAT_WS=71,
	COATL_UCD_PATTERN_WHITE_SPACE=COATL_UCD_PAT_WS,
    COATL_UCD_QMARK=72,
	COATL_UCD_QUOTATION_MARK=COATL_UCD_QMARK,
    COATL_UCD_RADICAL=73,
    COATL_UCD_SB=74,
	COATL_UCD_SENTENCE_BREAK=COATL_UCD_SB,
    COATL_UCD_SC=75,
	COATL_UCD_SCRIPT=COATL_UCD_SC,
    COATL_UCD_SCF=76,
	COATL_UCD_SIMPLE_CASE_FOLDING=COATL_UCD_SCF,
	COATL_UCD_SFC=COATL_UCD_SCF,
    COATL_UCD_SCX=77,
	COATL_UCD_SCRIPT_EXTENSIONS=COATL_UCD_SCX,
    COATL_UCD_SD=78,
	COATL_UCD_SOFT_DOTTED=COATL_UCD_SD,
    COATL_UCD_SLC=79,
	COATL_UCD_SIMPLE_LOWERCASE_MAPPING=COATL_UCD_SLC,
    COATL_UCD_STC=80,
	COATL_UCD_SIMPLE_TITLECASE_MAPPING=COATL_UCD_STC,
    COATL_UCD_STERM=81,
    COATL_UCD_SUC=82,
	COATL_UCD_SIMPLE_UPPERCASE_MAPPING=COATL_UCD_SUC,
    COATL_UCD_TC=83,
	COATL_UCD_TITLECASE_MAPPING=COATL_UCD_TC,
    COATL_UCD_TERM=84,
	COATL_UCD_TERMINAL_PUNCTUATION=COATL_UCD_TERM,
    COATL_UCD_UC=85,
	COATL_UCD_UPPERCASE_MAPPING=COATL_UCD_UC,
    COATL_UCD_UIDEO=86,
	COATL_UCD_UNIFIED_IDEOGRAPH=COATL_UCD_UIDEO,
    COATL_UCD_UPPER=87,
	COATL_UCD_UPPERCASE=COATL_UCD_UPPER,
    COATL_UCD_VS=88,
	COATL_UCD_VARIATION_SELECTOR=COATL_UCD_VS,
    COATL_UCD_WB=89,
	COATL_UCD_WORD_BREAK=COATL_UCD_WB,
    COATL_UCD_WSPACE=90,
	COATL_UCD_WHITE_SPACE=COATL_UCD_WSPACE,
	COATL_UCD_SPACE=COATL_UCD_WSPACE,
    COATL_UCD_XIDC=91,
	COATL_UCD_XID_CONTINUE=COATL_UCD_XIDC,
    COATL_UCD_XIDS=92,
	COATL_UCD_XID_START=COATL_UCD_XIDS,

} Coatl_UcdProperty;

/*---------------------------------------------------------------------------
 * Constant: COATL_UCD_NBPROPERTIES
 *
 *	Number of Unicode character properties.
 *
 * See also:
 *	<Coatl_UcdProperty>
 *---------------------------------------------------------------------------*/

#define COATL_UCD_NBPROPERTIES	92

/*---------------------------------------------------------------------------
 * Enum: Coatl_Ucd_Age
 *
 *	Values for Unicode character property '*age*'.
 *
 *	Names are automatically generated from the UCD file
 *	*PropertyValueAliases.txt*
 *
 *  COATL_UCD_AGE_1_1 - '*1.1*', '*V1_1*'
 *  COATL_UCD_AGE_V1_1 - Alias for <COATL_UCD_AGE_1_1>
 *  COATL_UCD_AGE_2_0 - '*2.0*', '*V2_0*'
 *  COATL_UCD_AGE_V2_0 - Alias for <COATL_UCD_AGE_2_0>
 *  COATL_UCD_AGE_2_1 - '*2.1*', '*V2_1*'
 *  COATL_UCD_AGE_V2_1 - Alias for <COATL_UCD_AGE_2_1>
 *  COATL_UCD_AGE_3_0 - '*3.0*', '*V3_0*'
 *  COATL_UCD_AGE_V3_0 - Alias for <COATL_UCD_AGE_3_0>
 *  COATL_UCD_AGE_3_1 - '*3.1*', '*V3_1*'
 *  COATL_UCD_AGE_V3_1 - Alias for <COATL_UCD_AGE_3_1>
 *  COATL_UCD_AGE_3_2 - '*3.2*', '*V3_2*'
 *  COATL_UCD_AGE_V3_2 - Alias for <COATL_UCD_AGE_3_2>
 *  COATL_UCD_AGE_4_0 - '*4.0*', '*V4_0*'
 *  COATL_UCD_AGE_V4_0 - Alias for <COATL_UCD_AGE_4_0>
 *  COATL_UCD_AGE_4_1 - '*4.1*', '*V4_1*'
 *  COATL_UCD_AGE_V4_1 - Alias for <COATL_UCD_AGE_4_1>
 *  COATL_UCD_AGE_5_0 - '*5.0*', '*V5_0*'
 *  COATL_UCD_AGE_V5_0 - Alias for <COATL_UCD_AGE_5_0>
 *  COATL_UCD_AGE_5_1 - '*5.1*', '*V5_1*'
 *  COATL_UCD_AGE_V5_1 - Alias for <COATL_UCD_AGE_5_1>
 *  COATL_UCD_AGE_5_2 - '*5.2*', '*V5_2*'
 *  COATL_UCD_AGE_V5_2 - Alias for <COATL_UCD_AGE_5_2>
 *  COATL_UCD_AGE_6_0 - '*6.0*', '*V6_0*'
 *  COATL_UCD_AGE_V6_0 - Alias for <COATL_UCD_AGE_6_0>
 *  COATL_UCD_AGE_6_1 - '*6.1*', '*V6_1*'
 *  COATL_UCD_AGE_V6_1 - Alias for <COATL_UCD_AGE_6_1>
 *  COATL_UCD_AGE_NA - '*NA*', '*Unassigned*'
 *  COATL_UCD_AGE_UNASSIGNED - Alias for <COATL_UCD_AGE_NA>
 *
 * See also:
 *	<COATL_UCD_AGE>
 *---------------------------------------------------------------------------*/

typedef enum Coatl_Ucd_Age {
    COATL_UCD_AGE_1_1=1,
	COATL_UCD_AGE_V1_1=COATL_UCD_AGE_1_1,
    COATL_UCD_AGE_2_0=2,
	COATL_UCD_AGE_V2_0=COATL_UCD_AGE_2_0,
    COATL_UCD_AGE_2_1=3,
	COATL_UCD_AGE_V2_1=COATL_UCD_AGE_2_1,
    COATL_UCD_AGE_3_0=4,
	COATL_UCD_AGE_V3_0=COATL_UCD_AGE_3_0,
    COATL_UCD_AGE_3_1=5,
	COATL_UCD_AGE_V3_1=COATL_UCD_AGE_3_1,
    COATL_UCD_AGE_3_2=6,
	COATL_UCD_AGE_V3_2=COATL_UCD_AGE_3_2,
    COATL_UCD_AGE_4_0=7,
	COATL_UCD_AGE_V4_0=COATL_UCD_AGE_4_0,
    COATL_UCD_AGE_4_1=8,
	COATL_UCD_AGE_V4_1=COATL_UCD_AGE_4_1,
    COATL_UCD_AGE_5_0=9,
	COATL_UCD_AGE_V5_0=COATL_UCD_AGE_5_0,
    COATL_UCD_AGE_5_1=10,
	COATL_UCD_AGE_V5_1=COATL_UCD_AGE_5_1,
    COATL_UCD_AGE_5_2=11,
	COATL_UCD_AGE_V5_2=COATL_UCD_AGE_5_2,
    COATL_UCD_AGE_6_0=12,
	COATL_UCD_AGE_V6_0=COATL_UCD_AGE_6_0,
    COATL_UCD_AGE_6_1=13,
	COATL_UCD_AGE_V6_1=COATL_UCD_AGE_6_1,
    COATL_UCD_AGE_NA=14,
	COATL_UCD_AGE_UNASSIGNED=COATL_UCD_AGE_NA,

} Coatl_Ucd_Age;

/*---------------------------------------------------------------------------
 * Constant: COATL_UCD_AGE_NBVALUES
 *
 *	Number of values for Unicode character property '*age*'.
 *
 * See also:
 *	<Coatl_Ucd_Age>
 *---------------------------------------------------------------------------*/

#define COATL_UCD_AGE_NBVALUES	14

/*---------------------------------------------------------------------------
 * Enum: Coatl_Ucd_Bc
 *
 *	Values for Unicode character property '*bc*'.
 *
 *	Names are automatically generated from the UCD file
 *	*PropertyValueAliases.txt*
 *
 *  COATL_UCD_BC_AL - '*AL*', '*Arabic_Letter*'
 *  COATL_UCD_BC_ARABIC_LETTER - Alias for <COATL_UCD_BC_AL>
 *  COATL_UCD_BC_AN - '*AN*', '*Arabic_Number*'
 *  COATL_UCD_BC_ARABIC_NUMBER - Alias for <COATL_UCD_BC_AN>
 *  COATL_UCD_BC_B - '*B*', '*Paragraph_Separator*'
 *  COATL_UCD_BC_PARAGRAPH_SEPARATOR - Alias for <COATL_UCD_BC_B>
 *  COATL_UCD_BC_BN - '*BN*', '*Boundary_Neutral*'
 *  COATL_UCD_BC_BOUNDARY_NEUTRAL - Alias for <COATL_UCD_BC_BN>
 *  COATL_UCD_BC_CS - '*CS*', '*Common_Separator*'
 *  COATL_UCD_BC_COMMON_SEPARATOR - Alias for <COATL_UCD_BC_CS>
 *  COATL_UCD_BC_EN - '*EN*', '*European_Number*'
 *  COATL_UCD_BC_EUROPEAN_NUMBER - Alias for <COATL_UCD_BC_EN>
 *  COATL_UCD_BC_ES - '*ES*', '*European_Separator*'
 *  COATL_UCD_BC_EUROPEAN_SEPARATOR - Alias for <COATL_UCD_BC_ES>
 *  COATL_UCD_BC_ET - '*ET*', '*European_Terminator*'
 *  COATL_UCD_BC_EUROPEAN_TERMINATOR - Alias for <COATL_UCD_BC_ET>
 *  COATL_UCD_BC_L - '*L*', '*Left_To_Right*'
 *  COATL_UCD_BC_LEFT_TO_RIGHT - Alias for <COATL_UCD_BC_L>
 *  COATL_UCD_BC_LRE - '*LRE*', '*Left_To_Right_Embedding*'
 *  COATL_UCD_BC_LEFT_TO_RIGHT_EMBEDDING - Alias for <COATL_UCD_BC_LRE>
 *  COATL_UCD_BC_LRO - '*LRO*', '*Left_To_Right_Override*'
 *  COATL_UCD_BC_LEFT_TO_RIGHT_OVERRIDE - Alias for <COATL_UCD_BC_LRO>
 *  COATL_UCD_BC_NSM - '*NSM*', '*Nonspacing_Mark*'
 *  COATL_UCD_BC_NONSPACING_MARK - Alias for <COATL_UCD_BC_NSM>
 *  COATL_UCD_BC_ON - '*ON*', '*Other_Neutral*'
 *  COATL_UCD_BC_OTHER_NEUTRAL - Alias for <COATL_UCD_BC_ON>
 *  COATL_UCD_BC_PDF - '*PDF*', '*Pop_Directional_Format*'
 *  COATL_UCD_BC_POP_DIRECTIONAL_FORMAT - Alias for <COATL_UCD_BC_PDF>
 *  COATL_UCD_BC_R - '*R*', '*Right_To_Left*'
 *  COATL_UCD_BC_RIGHT_TO_LEFT - Alias for <COATL_UCD_BC_R>
 *  COATL_UCD_BC_RLE - '*RLE*', '*Right_To_Left_Embedding*'
 *  COATL_UCD_BC_RIGHT_TO_LEFT_EMBEDDING - Alias for <COATL_UCD_BC_RLE>
 *  COATL_UCD_BC_RLO - '*RLO*', '*Right_To_Left_Override*'
 *  COATL_UCD_BC_RIGHT_TO_LEFT_OVERRIDE - Alias for <COATL_UCD_BC_RLO>
 *  COATL_UCD_BC_S - '*S*', '*Segment_Separator*'
 *  COATL_UCD_BC_SEGMENT_SEPARATOR - Alias for <COATL_UCD_BC_S>
 *  COATL_UCD_BC_WS - '*WS*', '*White_Space*'
 *  COATL_UCD_BC_WHITE_SPACE - Alias for <COATL_UCD_BC_WS>
 *
 * See also:
 *	<COATL_UCD_BC>
 *---------------------------------------------------------------------------*/

typedef enum Coatl_Ucd_Bc {
    COATL_UCD_BC_AL=1,
	COATL_UCD_BC_ARABIC_LETTER=COATL_UCD_BC_AL,
    COATL_UCD_BC_AN=2,
	COATL_UCD_BC_ARABIC_NUMBER=COATL_UCD_BC_AN,
    COATL_UCD_BC_B=3,
	COATL_UCD_BC_PARAGRAPH_SEPARATOR=COATL_UCD_BC_B,
    COATL_UCD_BC_BN=4,
	COATL_UCD_BC_BOUNDARY_NEUTRAL=COATL_UCD_BC_BN,
    COATL_UCD_BC_CS=5,
	COATL_UCD_BC_COMMON_SEPARATOR=COATL_UCD_BC_CS,
    COATL_UCD_BC_EN=6,
	COATL_UCD_BC_EUROPEAN_NUMBER=COATL_UCD_BC_EN,
    COATL_UCD_BC_ES=7,
	COATL_UCD_BC_EUROPEAN_SEPARATOR=COATL_UCD_BC_ES,
    COATL_UCD_BC_ET=8,
	COATL_UCD_BC_EUROPEAN_TERMINATOR=COATL_UCD_BC_ET,
    COATL_UCD_BC_L=9,
	COATL_UCD_BC_LEFT_TO_RIGHT=COATL_UCD_BC_L,
    COATL_UCD_BC_LRE=10,
	COATL_UCD_BC_LEFT_TO_RIGHT_EMBEDDING=COATL_UCD_BC_LRE,
    COATL_UCD_BC_LRO=11,
	COATL_UCD_BC_LEFT_TO_RIGHT_OVERRIDE=COATL_UCD_BC_LRO,
    COATL_UCD_BC_NSM=12,
	COATL_UCD_BC_NONSPACING_MARK=COATL_UCD_BC_NSM,
    COATL_UCD_BC_ON=13,
	COATL_UCD_BC_OTHER_NEUTRAL=COATL_UCD_BC_ON,
    COATL_UCD_BC_PDF=14,
	COATL_UCD_BC_POP_DIRECTIONAL_FORMAT=COATL_UCD_BC_PDF,
    COATL_UCD_BC_R=15,
	COATL_UCD_BC_RIGHT_TO_LEFT=COATL_UCD_BC_R,
    COATL_UCD_BC_RLE=16,
	COATL_UCD_BC_RIGHT_TO_LEFT_EMBEDDING=COATL_UCD_BC_RLE,
    COATL_UCD_BC_RLO=17,
	COATL_UCD_BC_RIGHT_TO_LEFT_OVERRIDE=COATL_UCD_BC_RLO,
    COATL_UCD_BC_S=18,
	COATL_UCD_BC_SEGMENT_SEPARATOR=COATL_UCD_BC_S,
    COATL_UCD_BC_WS=19,
	COATL_UCD_BC_WHITE_SPACE=COATL_UCD_BC_WS,

} Coatl_Ucd_Bc;

/*---------------------------------------------------------------------------
 * Constant: COATL_UCD_BC_NBVALUES
 *
 *	Number of values for Unicode character property '*bc*'.
 *
 * See also:
 *	<Coatl_Ucd_Bc>
 *---------------------------------------------------------------------------*/

#define COATL_UCD_BC_NBVALUES	19

/*---------------------------------------------------------------------------
 * Enum: Coatl_Ucd_Blk
 *
 *	Values for Unicode character property '*blk*'.
 *
 *	Names are automatically generated from the UCD file
 *	*PropertyValueAliases.txt*
 *
 *  COATL_UCD_BLK_AEGEAN_NUMBERS - '*Aegean_Numbers*'
 *  COATL_UCD_BLK_ALCHEMICAL - '*Alchemical*', '*Alchemical_Symbols*'
 *  COATL_UCD_BLK_ALCHEMICAL_SYMBOLS - Alias for <COATL_UCD_BLK_ALCHEMICAL>
 *  COATL_UCD_BLK_ALPHABETIC_PF - '*Alphabetic_PF*', '*Alphabetic_Presentation_Forms*'
 *  COATL_UCD_BLK_ALPHABETIC_PRESENTATION_FORMS - Alias for <COATL_UCD_BLK_ALPHABETIC_PF>
 *  COATL_UCD_BLK_ANCIENT_GREEK_MUSIC - '*Ancient_Greek_Music*', '*Ancient_Greek_Musical_Notation*'
 *  COATL_UCD_BLK_ANCIENT_GREEK_MUSICAL_NOTATION - Alias for <COATL_UCD_BLK_ANCIENT_GREEK_MUSIC>
 *  COATL_UCD_BLK_ANCIENT_GREEK_NUMBERS - '*Ancient_Greek_Numbers*'
 *  COATL_UCD_BLK_ANCIENT_SYMBOLS - '*Ancient_Symbols*'
 *  COATL_UCD_BLK_ARABIC - '*Arabic*'
 *  COATL_UCD_BLK_ARABIC_EXT_A - '*Arabic_Ext_A*', '*Arabic_Extended_A*'
 *  COATL_UCD_BLK_ARABIC_EXTENDED_A - Alias for <COATL_UCD_BLK_ARABIC_EXT_A>
 *  COATL_UCD_BLK_ARABIC_MATH - '*Arabic_Math*', '*Arabic_Mathematical_Alphabetic_Symbols*'
 *  COATL_UCD_BLK_ARABIC_MATHEMATICAL_ALPHABETIC_SYMBOLS - Alias for <COATL_UCD_BLK_ARABIC_MATH>
 *  COATL_UCD_BLK_ARABIC_PF_A - '*Arabic_PF_A*', '*Arabic_Presentation_Forms_A*', '*Arabic_Presentation_Forms-A*'
 *  COATL_UCD_BLK_ARABIC_PRESENTATION_FORMS_A - Alias for <COATL_UCD_BLK_ARABIC_PF_A>
 *  COATL_UCD_BLK_ARABIC_PF_B - '*Arabic_PF_B*', '*Arabic_Presentation_Forms_B*'
 *  COATL_UCD_BLK_ARABIC_PRESENTATION_FORMS_B - Alias for <COATL_UCD_BLK_ARABIC_PF_B>
 *  COATL_UCD_BLK_ARABIC_SUP - '*Arabic_Sup*', '*Arabic_Supplement*'
 *  COATL_UCD_BLK_ARABIC_SUPPLEMENT - Alias for <COATL_UCD_BLK_ARABIC_SUP>
 *  COATL_UCD_BLK_ARMENIAN - '*Armenian*'
 *  COATL_UCD_BLK_ARROWS - '*Arrows*'
 *  COATL_UCD_BLK_ASCII - '*ASCII*', '*Basic_Latin*'
 *  COATL_UCD_BLK_BASIC_LATIN - Alias for <COATL_UCD_BLK_ASCII>
 *  COATL_UCD_BLK_AVESTAN - '*Avestan*'
 *  COATL_UCD_BLK_BALINESE - '*Balinese*'
 *  COATL_UCD_BLK_BAMUM - '*Bamum*'
 *  COATL_UCD_BLK_BAMUM_SUP - '*Bamum_Sup*', '*Bamum_Supplement*'
 *  COATL_UCD_BLK_BAMUM_SUPPLEMENT - Alias for <COATL_UCD_BLK_BAMUM_SUP>
 *  COATL_UCD_BLK_BATAK - '*Batak*'
 *  COATL_UCD_BLK_BENGALI - '*Bengali*'
 *  COATL_UCD_BLK_BLOCK_ELEMENTS - '*Block_Elements*'
 *  COATL_UCD_BLK_BOPOMOFO - '*Bopomofo*'
 *  COATL_UCD_BLK_BOPOMOFO_EXT - '*Bopomofo_Ext*', '*Bopomofo_Extended*'
 *  COATL_UCD_BLK_BOPOMOFO_EXTENDED - Alias for <COATL_UCD_BLK_BOPOMOFO_EXT>
 *  COATL_UCD_BLK_BOX_DRAWING - '*Box_Drawing*'
 *  COATL_UCD_BLK_BRAHMI - '*Brahmi*'
 *  COATL_UCD_BLK_BRAILLE - '*Braille*', '*Braille_Patterns*'
 *  COATL_UCD_BLK_BRAILLE_PATTERNS - Alias for <COATL_UCD_BLK_BRAILLE>
 *  COATL_UCD_BLK_BUGINESE - '*Buginese*'
 *  COATL_UCD_BLK_BUHID - '*Buhid*'
 *  COATL_UCD_BLK_BYZANTINE_MUSIC - '*Byzantine_Music*', '*Byzantine_Musical_Symbols*'
 *  COATL_UCD_BLK_BYZANTINE_MUSICAL_SYMBOLS - Alias for <COATL_UCD_BLK_BYZANTINE_MUSIC>
 *  COATL_UCD_BLK_CARIAN - '*Carian*'
 *  COATL_UCD_BLK_CHAKMA - '*Chakma*'
 *  COATL_UCD_BLK_CHAM - '*Cham*'
 *  COATL_UCD_BLK_CHEROKEE - '*Cherokee*'
 *  COATL_UCD_BLK_CJK - '*CJK*', '*CJK_Unified_Ideographs*'
 *  COATL_UCD_BLK_CJK_UNIFIED_IDEOGRAPHS - Alias for <COATL_UCD_BLK_CJK>
 *  COATL_UCD_BLK_CJK_COMPAT - '*CJK_Compat*', '*CJK_Compatibility*'
 *  COATL_UCD_BLK_CJK_COMPATIBILITY - Alias for <COATL_UCD_BLK_CJK_COMPAT>
 *  COATL_UCD_BLK_CJK_COMPAT_FORMS - '*CJK_Compat_Forms*', '*CJK_Compatibility_Forms*'
 *  COATL_UCD_BLK_CJK_COMPATIBILITY_FORMS - Alias for <COATL_UCD_BLK_CJK_COMPAT_FORMS>
 *  COATL_UCD_BLK_CJK_COMPAT_IDEOGRAPHS - '*CJK_Compat_Ideographs*', '*CJK_Compatibility_Ideographs*'
 *  COATL_UCD_BLK_CJK_COMPATIBILITY_IDEOGRAPHS - Alias for <COATL_UCD_BLK_CJK_COMPAT_IDEOGRAPHS>
 *  COATL_UCD_BLK_CJK_COMPAT_IDEOGRAPHS_SUP - '*CJK_Compat_Ideographs_Sup*', '*CJK_Compatibility_Ideographs_Supplement*'
 *  COATL_UCD_BLK_CJK_COMPATIBILITY_IDEOGRAPHS_SUPPLEMENT - Alias for <COATL_UCD_BLK_CJK_COMPAT_IDEOGRAPHS_SUP>
 *  COATL_UCD_BLK_CJK_EXT_A - '*CJK_Ext_A*', '*CJK_Unified_Ideographs_Extension_A*'
 *  COATL_UCD_BLK_CJK_UNIFIED_IDEOGRAPHS_EXTENSION_A - Alias for <COATL_UCD_BLK_CJK_EXT_A>
 *  COATL_UCD_BLK_CJK_EXT_B - '*CJK_Ext_B*', '*CJK_Unified_Ideographs_Extension_B*'
 *  COATL_UCD_BLK_CJK_UNIFIED_IDEOGRAPHS_EXTENSION_B - Alias for <COATL_UCD_BLK_CJK_EXT_B>
 *  COATL_UCD_BLK_CJK_EXT_C - '*CJK_Ext_C*', '*CJK_Unified_Ideographs_Extension_C*'
 *  COATL_UCD_BLK_CJK_UNIFIED_IDEOGRAPHS_EXTENSION_C - Alias for <COATL_UCD_BLK_CJK_EXT_C>
 *  COATL_UCD_BLK_CJK_EXT_D - '*CJK_Ext_D*', '*CJK_Unified_Ideographs_Extension_D*'
 *  COATL_UCD_BLK_CJK_UNIFIED_IDEOGRAPHS_EXTENSION_D - Alias for <COATL_UCD_BLK_CJK_EXT_D>
 *  COATL_UCD_BLK_CJK_RADICALS_SUP - '*CJK_Radicals_Sup*', '*CJK_Radicals_Supplement*'
 *  COATL_UCD_BLK_CJK_RADICALS_SUPPLEMENT - Alias for <COATL_UCD_BLK_CJK_RADICALS_SUP>
 *  COATL_UCD_BLK_CJK_STROKES - '*CJK_Strokes*'
 *  COATL_UCD_BLK_CJK_SYMBOLS - '*CJK_Symbols*', '*CJK_Symbols_And_Punctuation*'
 *  COATL_UCD_BLK_CJK_SYMBOLS_AND_PUNCTUATION - Alias for <COATL_UCD_BLK_CJK_SYMBOLS>
 *  COATL_UCD_BLK_COMPAT_JAMO - '*Compat_Jamo*', '*Hangul_Compatibility_Jamo*'
 *  COATL_UCD_BLK_HANGUL_COMPATIBILITY_JAMO - Alias for <COATL_UCD_BLK_COMPAT_JAMO>
 *  COATL_UCD_BLK_CONTROL_PICTURES - '*Control_Pictures*'
 *  COATL_UCD_BLK_COPTIC - '*Coptic*'
 *  COATL_UCD_BLK_COUNTING_ROD - '*Counting_Rod*', '*Counting_Rod_Numerals*'
 *  COATL_UCD_BLK_COUNTING_ROD_NUMERALS - Alias for <COATL_UCD_BLK_COUNTING_ROD>
 *  COATL_UCD_BLK_CUNEIFORM - '*Cuneiform*'
 *  COATL_UCD_BLK_CUNEIFORM_NUMBERS - '*Cuneiform_Numbers*', '*Cuneiform_Numbers_And_Punctuation*'
 *  COATL_UCD_BLK_CUNEIFORM_NUMBERS_AND_PUNCTUATION - Alias for <COATL_UCD_BLK_CUNEIFORM_NUMBERS>
 *  COATL_UCD_BLK_CURRENCY_SYMBOLS - '*Currency_Symbols*'
 *  COATL_UCD_BLK_CYPRIOT_SYLLABARY - '*Cypriot_Syllabary*'
 *  COATL_UCD_BLK_CYRILLIC - '*Cyrillic*'
 *  COATL_UCD_BLK_CYRILLIC_EXT_A - '*Cyrillic_Ext_A*', '*Cyrillic_Extended_A*'
 *  COATL_UCD_BLK_CYRILLIC_EXTENDED_A - Alias for <COATL_UCD_BLK_CYRILLIC_EXT_A>
 *  COATL_UCD_BLK_CYRILLIC_EXT_B - '*Cyrillic_Ext_B*', '*Cyrillic_Extended_B*'
 *  COATL_UCD_BLK_CYRILLIC_EXTENDED_B - Alias for <COATL_UCD_BLK_CYRILLIC_EXT_B>
 *  COATL_UCD_BLK_CYRILLIC_SUP - '*Cyrillic_Sup*', '*Cyrillic_Supplement*', '*Cyrillic_Supplementary*'
 *  COATL_UCD_BLK_CYRILLIC_SUPPLEMENT - Alias for <COATL_UCD_BLK_CYRILLIC_SUP>
 *  COATL_UCD_BLK_CYRILLIC_SUPPLEMENTARY - Alias for <COATL_UCD_BLK_CYRILLIC_SUP>
 *  COATL_UCD_BLK_DESERET - '*Deseret*'
 *  COATL_UCD_BLK_DEVANAGARI - '*Devanagari*'
 *  COATL_UCD_BLK_DEVANAGARI_EXT - '*Devanagari_Ext*', '*Devanagari_Extended*'
 *  COATL_UCD_BLK_DEVANAGARI_EXTENDED - Alias for <COATL_UCD_BLK_DEVANAGARI_EXT>
 *  COATL_UCD_BLK_DIACRITICALS - '*Diacriticals*', '*Combining_Diacritical_Marks*'
 *  COATL_UCD_BLK_COMBINING_DIACRITICAL_MARKS - Alias for <COATL_UCD_BLK_DIACRITICALS>
 *  COATL_UCD_BLK_DIACRITICALS_FOR_SYMBOLS - '*Diacriticals_For_Symbols*', '*Combining_Diacritical_Marks_For_Symbols*', '*Combining_Marks_For_Symbols*'
 *  COATL_UCD_BLK_COMBINING_DIACRITICAL_MARKS_FOR_SYMBOLS - Alias for <COATL_UCD_BLK_DIACRITICALS_FOR_SYMBOLS>
 *  COATL_UCD_BLK_COMBINING_MARKS_FOR_SYMBOLS - Alias for <COATL_UCD_BLK_DIACRITICALS_FOR_SYMBOLS>
 *  COATL_UCD_BLK_DIACRITICALS_SUP - '*Diacriticals_Sup*', '*Combining_Diacritical_Marks_Supplement*'
 *  COATL_UCD_BLK_COMBINING_DIACRITICAL_MARKS_SUPPLEMENT - Alias for <COATL_UCD_BLK_DIACRITICALS_SUP>
 *  COATL_UCD_BLK_DINGBATS - '*Dingbats*'
 *  COATL_UCD_BLK_DOMINO - '*Domino*', '*Domino_Tiles*'
 *  COATL_UCD_BLK_DOMINO_TILES - Alias for <COATL_UCD_BLK_DOMINO>
 *  COATL_UCD_BLK_EGYPTIAN_HIEROGLYPHS - '*Egyptian_Hieroglyphs*'
 *  COATL_UCD_BLK_EMOTICONS - '*Emoticons*'
 *  COATL_UCD_BLK_ENCLOSED_ALPHANUM - '*Enclosed_Alphanum*', '*Enclosed_Alphanumerics*'
 *  COATL_UCD_BLK_ENCLOSED_ALPHANUMERICS - Alias for <COATL_UCD_BLK_ENCLOSED_ALPHANUM>
 *  COATL_UCD_BLK_ENCLOSED_ALPHANUM_SUP - '*Enclosed_Alphanum_Sup*', '*Enclosed_Alphanumeric_Supplement*'
 *  COATL_UCD_BLK_ENCLOSED_ALPHANUMERIC_SUPPLEMENT - Alias for <COATL_UCD_BLK_ENCLOSED_ALPHANUM_SUP>
 *  COATL_UCD_BLK_ENCLOSED_CJK - '*Enclosed_CJK*', '*Enclosed_CJK_Letters_And_Months*'
 *  COATL_UCD_BLK_ENCLOSED_CJK_LETTERS_AND_MONTHS - Alias for <COATL_UCD_BLK_ENCLOSED_CJK>
 *  COATL_UCD_BLK_ENCLOSED_IDEOGRAPHIC_SUP - '*Enclosed_Ideographic_Sup*', '*Enclosed_Ideographic_Supplement*'
 *  COATL_UCD_BLK_ENCLOSED_IDEOGRAPHIC_SUPPLEMENT - Alias for <COATL_UCD_BLK_ENCLOSED_IDEOGRAPHIC_SUP>
 *  COATL_UCD_BLK_ETHIOPIC - '*Ethiopic*'
 *  COATL_UCD_BLK_ETHIOPIC_EXT - '*Ethiopic_Ext*', '*Ethiopic_Extended*'
 *  COATL_UCD_BLK_ETHIOPIC_EXTENDED - Alias for <COATL_UCD_BLK_ETHIOPIC_EXT>
 *  COATL_UCD_BLK_ETHIOPIC_EXT_A - '*Ethiopic_Ext_A*', '*Ethiopic_Extended_A*'
 *  COATL_UCD_BLK_ETHIOPIC_EXTENDED_A - Alias for <COATL_UCD_BLK_ETHIOPIC_EXT_A>
 *  COATL_UCD_BLK_ETHIOPIC_SUP - '*Ethiopic_Sup*', '*Ethiopic_Supplement*'
 *  COATL_UCD_BLK_ETHIOPIC_SUPPLEMENT - Alias for <COATL_UCD_BLK_ETHIOPIC_SUP>
 *  COATL_UCD_BLK_GEOMETRIC_SHAPES - '*Geometric_Shapes*'
 *  COATL_UCD_BLK_GEORGIAN - '*Georgian*'
 *  COATL_UCD_BLK_GEORGIAN_SUP - '*Georgian_Sup*', '*Georgian_Supplement*'
 *  COATL_UCD_BLK_GEORGIAN_SUPPLEMENT - Alias for <COATL_UCD_BLK_GEORGIAN_SUP>
 *  COATL_UCD_BLK_GLAGOLITIC - '*Glagolitic*'
 *  COATL_UCD_BLK_GOTHIC - '*Gothic*'
 *  COATL_UCD_BLK_GREEK - '*Greek*', '*Greek_And_Coptic*'
 *  COATL_UCD_BLK_GREEK_AND_COPTIC - Alias for <COATL_UCD_BLK_GREEK>
 *  COATL_UCD_BLK_GREEK_EXT - '*Greek_Ext*', '*Greek_Extended*'
 *  COATL_UCD_BLK_GREEK_EXTENDED - Alias for <COATL_UCD_BLK_GREEK_EXT>
 *  COATL_UCD_BLK_GUJARATI - '*Gujarati*'
 *  COATL_UCD_BLK_GURMUKHI - '*Gurmukhi*'
 *  COATL_UCD_BLK_HALF_AND_FULL_FORMS - '*Half_And_Full_Forms*', '*Halfwidth_And_Fullwidth_Forms*'
 *  COATL_UCD_BLK_HALFWIDTH_AND_FULLWIDTH_FORMS - Alias for <COATL_UCD_BLK_HALF_AND_FULL_FORMS>
 *  COATL_UCD_BLK_HALF_MARKS - '*Half_Marks*', '*Combining_Half_Marks*'
 *  COATL_UCD_BLK_COMBINING_HALF_MARKS - Alias for <COATL_UCD_BLK_HALF_MARKS>
 *  COATL_UCD_BLK_HANGUL - '*Hangul*', '*Hangul_Syllables*'
 *  COATL_UCD_BLK_HANGUL_SYLLABLES - Alias for <COATL_UCD_BLK_HANGUL>
 *  COATL_UCD_BLK_HANUNOO - '*Hanunoo*'
 *  COATL_UCD_BLK_HEBREW - '*Hebrew*'
 *  COATL_UCD_BLK_HIGH_PU_SURROGATES - '*High_PU_Surrogates*', '*High_Private_Use_Surrogates*'
 *  COATL_UCD_BLK_HIGH_PRIVATE_USE_SURROGATES - Alias for <COATL_UCD_BLK_HIGH_PU_SURROGATES>
 *  COATL_UCD_BLK_HIGH_SURROGATES - '*High_Surrogates*'
 *  COATL_UCD_BLK_HIRAGANA - '*Hiragana*'
 *  COATL_UCD_BLK_IDC - '*IDC*', '*Ideographic_Description_Characters*'
 *  COATL_UCD_BLK_IDEOGRAPHIC_DESCRIPTION_CHARACTERS - Alias for <COATL_UCD_BLK_IDC>
 *  COATL_UCD_BLK_IMPERIAL_ARAMAIC - '*Imperial_Aramaic*'
 *  COATL_UCD_BLK_INDIC_NUMBER_FORMS - '*Indic_Number_Forms*', '*Common_Indic_Number_Forms*'
 *  COATL_UCD_BLK_COMMON_INDIC_NUMBER_FORMS - Alias for <COATL_UCD_BLK_INDIC_NUMBER_FORMS>
 *  COATL_UCD_BLK_INSCRIPTIONAL_PAHLAVI - '*Inscriptional_Pahlavi*'
 *  COATL_UCD_BLK_INSCRIPTIONAL_PARTHIAN - '*Inscriptional_Parthian*'
 *  COATL_UCD_BLK_IPA_EXT - '*IPA_Ext*', '*IPA_Extensions*'
 *  COATL_UCD_BLK_IPA_EXTENSIONS - Alias for <COATL_UCD_BLK_IPA_EXT>
 *  COATL_UCD_BLK_JAMO - '*Jamo*', '*Hangul_Jamo*'
 *  COATL_UCD_BLK_HANGUL_JAMO - Alias for <COATL_UCD_BLK_JAMO>
 *  COATL_UCD_BLK_JAMO_EXT_A - '*Jamo_Ext_A*', '*Hangul_Jamo_Extended_A*'
 *  COATL_UCD_BLK_HANGUL_JAMO_EXTENDED_A - Alias for <COATL_UCD_BLK_JAMO_EXT_A>
 *  COATL_UCD_BLK_JAMO_EXT_B - '*Jamo_Ext_B*', '*Hangul_Jamo_Extended_B*'
 *  COATL_UCD_BLK_HANGUL_JAMO_EXTENDED_B - Alias for <COATL_UCD_BLK_JAMO_EXT_B>
 *  COATL_UCD_BLK_JAVANESE - '*Javanese*'
 *  COATL_UCD_BLK_KAITHI - '*Kaithi*'
 *  COATL_UCD_BLK_KANA_SUP - '*Kana_Sup*', '*Kana_Supplement*'
 *  COATL_UCD_BLK_KANA_SUPPLEMENT - Alias for <COATL_UCD_BLK_KANA_SUP>
 *  COATL_UCD_BLK_KANBUN - '*Kanbun*'
 *  COATL_UCD_BLK_KANGXI - '*Kangxi*', '*Kangxi_Radicals*'
 *  COATL_UCD_BLK_KANGXI_RADICALS - Alias for <COATL_UCD_BLK_KANGXI>
 *  COATL_UCD_BLK_KANNADA - '*Kannada*'
 *  COATL_UCD_BLK_KATAKANA - '*Katakana*'
 *  COATL_UCD_BLK_KATAKANA_EXT - '*Katakana_Ext*', '*Katakana_Phonetic_Extensions*'
 *  COATL_UCD_BLK_KATAKANA_PHONETIC_EXTENSIONS - Alias for <COATL_UCD_BLK_KATAKANA_EXT>
 *  COATL_UCD_BLK_KAYAH_LI - '*Kayah_Li*'
 *  COATL_UCD_BLK_KHAROSHTHI - '*Kharoshthi*'
 *  COATL_UCD_BLK_KHMER - '*Khmer*'
 *  COATL_UCD_BLK_KHMER_SYMBOLS - '*Khmer_Symbols*'
 *  COATL_UCD_BLK_LAO - '*Lao*'
 *  COATL_UCD_BLK_LATIN_1_SUP - '*Latin_1_Sup*', '*Latin_1_Supplement*', '*Latin_1*'
 *  COATL_UCD_BLK_LATIN_1_SUPPLEMENT - Alias for <COATL_UCD_BLK_LATIN_1_SUP>
 *  COATL_UCD_BLK_LATIN_1 - Alias for <COATL_UCD_BLK_LATIN_1_SUP>
 *  COATL_UCD_BLK_LATIN_EXT_A - '*Latin_Ext_A*', '*Latin_Extended_A*'
 *  COATL_UCD_BLK_LATIN_EXTENDED_A - Alias for <COATL_UCD_BLK_LATIN_EXT_A>
 *  COATL_UCD_BLK_LATIN_EXT_ADDITIONAL - '*Latin_Ext_Additional*', '*Latin_Extended_Additional*'
 *  COATL_UCD_BLK_LATIN_EXTENDED_ADDITIONAL - Alias for <COATL_UCD_BLK_LATIN_EXT_ADDITIONAL>
 *  COATL_UCD_BLK_LATIN_EXT_B - '*Latin_Ext_B*', '*Latin_Extended_B*'
 *  COATL_UCD_BLK_LATIN_EXTENDED_B - Alias for <COATL_UCD_BLK_LATIN_EXT_B>
 *  COATL_UCD_BLK_LATIN_EXT_C - '*Latin_Ext_C*', '*Latin_Extended_C*'
 *  COATL_UCD_BLK_LATIN_EXTENDED_C - Alias for <COATL_UCD_BLK_LATIN_EXT_C>
 *  COATL_UCD_BLK_LATIN_EXT_D - '*Latin_Ext_D*', '*Latin_Extended_D*'
 *  COATL_UCD_BLK_LATIN_EXTENDED_D - Alias for <COATL_UCD_BLK_LATIN_EXT_D>
 *  COATL_UCD_BLK_LEPCHA - '*Lepcha*'
 *  COATL_UCD_BLK_LETTERLIKE_SYMBOLS - '*Letterlike_Symbols*'
 *  COATL_UCD_BLK_LIMBU - '*Limbu*'
 *  COATL_UCD_BLK_LINEAR_B_IDEOGRAMS - '*Linear_B_Ideograms*'
 *  COATL_UCD_BLK_LINEAR_B_SYLLABARY - '*Linear_B_Syllabary*'
 *  COATL_UCD_BLK_LISU - '*Lisu*'
 *  COATL_UCD_BLK_LOW_SURROGATES - '*Low_Surrogates*'
 *  COATL_UCD_BLK_LYCIAN - '*Lycian*'
 *  COATL_UCD_BLK_LYDIAN - '*Lydian*'
 *  COATL_UCD_BLK_MAHJONG - '*Mahjong*', '*Mahjong_Tiles*'
 *  COATL_UCD_BLK_MAHJONG_TILES - Alias for <COATL_UCD_BLK_MAHJONG>
 *  COATL_UCD_BLK_MALAYALAM - '*Malayalam*'
 *  COATL_UCD_BLK_MANDAIC - '*Mandaic*'
 *  COATL_UCD_BLK_MATH_ALPHANUM - '*Math_Alphanum*', '*Mathematical_Alphanumeric_Symbols*'
 *  COATL_UCD_BLK_MATHEMATICAL_ALPHANUMERIC_SYMBOLS - Alias for <COATL_UCD_BLK_MATH_ALPHANUM>
 *  COATL_UCD_BLK_MATH_OPERATORS - '*Math_Operators*', '*Mathematical_Operators*'
 *  COATL_UCD_BLK_MATHEMATICAL_OPERATORS - Alias for <COATL_UCD_BLK_MATH_OPERATORS>
 *  COATL_UCD_BLK_MEETEI_MAYEK - '*Meetei_Mayek*'
 *  COATL_UCD_BLK_MEETEI_MAYEK_EXT - '*Meetei_Mayek_Ext*', '*Meetei_Mayek_Extensions*'
 *  COATL_UCD_BLK_MEETEI_MAYEK_EXTENSIONS - Alias for <COATL_UCD_BLK_MEETEI_MAYEK_EXT>
 *  COATL_UCD_BLK_MEROITIC_CURSIVE - '*Meroitic_Cursive*'
 *  COATL_UCD_BLK_MEROITIC_HIEROGLYPHS - '*Meroitic_Hieroglyphs*'
 *  COATL_UCD_BLK_MIAO - '*Miao*'
 *  COATL_UCD_BLK_MISC_ARROWS - '*Misc_Arrows*', '*Miscellaneous_Symbols_And_Arrows*'
 *  COATL_UCD_BLK_MISCELLANEOUS_SYMBOLS_AND_ARROWS - Alias for <COATL_UCD_BLK_MISC_ARROWS>
 *  COATL_UCD_BLK_MISC_MATH_SYMBOLS_A - '*Misc_Math_Symbols_A*', '*Miscellaneous_Mathematical_Symbols_A*'
 *  COATL_UCD_BLK_MISCELLANEOUS_MATHEMATICAL_SYMBOLS_A - Alias for <COATL_UCD_BLK_MISC_MATH_SYMBOLS_A>
 *  COATL_UCD_BLK_MISC_MATH_SYMBOLS_B - '*Misc_Math_Symbols_B*', '*Miscellaneous_Mathematical_Symbols_B*'
 *  COATL_UCD_BLK_MISCELLANEOUS_MATHEMATICAL_SYMBOLS_B - Alias for <COATL_UCD_BLK_MISC_MATH_SYMBOLS_B>
 *  COATL_UCD_BLK_MISC_PICTOGRAPHS - '*Misc_Pictographs*', '*Miscellaneous_Symbols_And_Pictographs*'
 *  COATL_UCD_BLK_MISCELLANEOUS_SYMBOLS_AND_PICTOGRAPHS - Alias for <COATL_UCD_BLK_MISC_PICTOGRAPHS>
 *  COATL_UCD_BLK_MISC_SYMBOLS - '*Misc_Symbols*', '*Miscellaneous_Symbols*'
 *  COATL_UCD_BLK_MISCELLANEOUS_SYMBOLS - Alias for <COATL_UCD_BLK_MISC_SYMBOLS>
 *  COATL_UCD_BLK_MISC_TECHNICAL - '*Misc_Technical*', '*Miscellaneous_Technical*'
 *  COATL_UCD_BLK_MISCELLANEOUS_TECHNICAL - Alias for <COATL_UCD_BLK_MISC_TECHNICAL>
 *  COATL_UCD_BLK_MODIFIER_LETTERS - '*Modifier_Letters*', '*Spacing_Modifier_Letters*'
 *  COATL_UCD_BLK_SPACING_MODIFIER_LETTERS - Alias for <COATL_UCD_BLK_MODIFIER_LETTERS>
 *  COATL_UCD_BLK_MODIFIER_TONE_LETTERS - '*Modifier_Tone_Letters*'
 *  COATL_UCD_BLK_MONGOLIAN - '*Mongolian*'
 *  COATL_UCD_BLK_MUSIC - '*Music*', '*Musical_Symbols*'
 *  COATL_UCD_BLK_MUSICAL_SYMBOLS - Alias for <COATL_UCD_BLK_MUSIC>
 *  COATL_UCD_BLK_MYANMAR - '*Myanmar*'
 *  COATL_UCD_BLK_MYANMAR_EXT_A - '*Myanmar_Ext_A*', '*Myanmar_Extended_A*'
 *  COATL_UCD_BLK_MYANMAR_EXTENDED_A - Alias for <COATL_UCD_BLK_MYANMAR_EXT_A>
 *  COATL_UCD_BLK_NB - '*NB*', '*No_Block*'
 *  COATL_UCD_BLK_NO_BLOCK - Alias for <COATL_UCD_BLK_NB>
 *  COATL_UCD_BLK_NEW_TAI_LUE - '*New_Tai_Lue*'
 *  COATL_UCD_BLK_NKO - '*NKo*'
 *  COATL_UCD_BLK_NUMBER_FORMS - '*Number_Forms*'
 *  COATL_UCD_BLK_OCR - '*OCR*', '*Optical_Character_Recognition*'
 *  COATL_UCD_BLK_OPTICAL_CHARACTER_RECOGNITION - Alias for <COATL_UCD_BLK_OCR>
 *  COATL_UCD_BLK_OGHAM - '*Ogham*'
 *  COATL_UCD_BLK_OL_CHIKI - '*Ol_Chiki*'
 *  COATL_UCD_BLK_OLD_ITALIC - '*Old_Italic*'
 *  COATL_UCD_BLK_OLD_PERSIAN - '*Old_Persian*'
 *  COATL_UCD_BLK_OLD_SOUTH_ARABIAN - '*Old_South_Arabian*'
 *  COATL_UCD_BLK_OLD_TURKIC - '*Old_Turkic*'
 *  COATL_UCD_BLK_ORIYA - '*Oriya*'
 *  COATL_UCD_BLK_OSMANYA - '*Osmanya*'
 *  COATL_UCD_BLK_PHAGS_PA - '*Phags_Pa*'
 *  COATL_UCD_BLK_PHAISTOS - '*Phaistos*', '*Phaistos_Disc*'
 *  COATL_UCD_BLK_PHAISTOS_DISC - Alias for <COATL_UCD_BLK_PHAISTOS>
 *  COATL_UCD_BLK_PHOENICIAN - '*Phoenician*'
 *  COATL_UCD_BLK_PHONETIC_EXT - '*Phonetic_Ext*', '*Phonetic_Extensions*'
 *  COATL_UCD_BLK_PHONETIC_EXTENSIONS - Alias for <COATL_UCD_BLK_PHONETIC_EXT>
 *  COATL_UCD_BLK_PHONETIC_EXT_SUP - '*Phonetic_Ext_Sup*', '*Phonetic_Extensions_Supplement*'
 *  COATL_UCD_BLK_PHONETIC_EXTENSIONS_SUPPLEMENT - Alias for <COATL_UCD_BLK_PHONETIC_EXT_SUP>
 *  COATL_UCD_BLK_PLAYING_CARDS - '*Playing_Cards*'
 *  COATL_UCD_BLK_PUA - '*PUA*', '*Private_Use_Area*', '*Private_Use*'
 *  COATL_UCD_BLK_PRIVATE_USE_AREA - Alias for <COATL_UCD_BLK_PUA>
 *  COATL_UCD_BLK_PRIVATE_USE - Alias for <COATL_UCD_BLK_PUA>
 *  COATL_UCD_BLK_PUNCTUATION - '*Punctuation*', '*General_Punctuation*'
 *  COATL_UCD_BLK_GENERAL_PUNCTUATION - Alias for <COATL_UCD_BLK_PUNCTUATION>
 *  COATL_UCD_BLK_REJANG - '*Rejang*'
 *  COATL_UCD_BLK_RUMI - '*Rumi*', '*Rumi_Numeral_Symbols*'
 *  COATL_UCD_BLK_RUMI_NUMERAL_SYMBOLS - Alias for <COATL_UCD_BLK_RUMI>
 *  COATL_UCD_BLK_RUNIC - '*Runic*'
 *  COATL_UCD_BLK_SAMARITAN - '*Samaritan*'
 *  COATL_UCD_BLK_SAURASHTRA - '*Saurashtra*'
 *  COATL_UCD_BLK_SHARADA - '*Sharada*'
 *  COATL_UCD_BLK_SHAVIAN - '*Shavian*'
 *  COATL_UCD_BLK_SINHALA - '*Sinhala*'
 *  COATL_UCD_BLK_SMALL_FORMS - '*Small_Forms*', '*Small_Form_Variants*'
 *  COATL_UCD_BLK_SMALL_FORM_VARIANTS - Alias for <COATL_UCD_BLK_SMALL_FORMS>
 *  COATL_UCD_BLK_SORA_SOMPENG - '*Sora_Sompeng*'
 *  COATL_UCD_BLK_SPECIALS - '*Specials*'
 *  COATL_UCD_BLK_SUNDANESE - '*Sundanese*'
 *  COATL_UCD_BLK_SUNDANESE_SUP - '*Sundanese_Sup*', '*Sundanese_Supplement*'
 *  COATL_UCD_BLK_SUNDANESE_SUPPLEMENT - Alias for <COATL_UCD_BLK_SUNDANESE_SUP>
 *  COATL_UCD_BLK_SUP_ARROWS_A - '*Sup_Arrows_A*', '*Supplemental_Arrows_A*'
 *  COATL_UCD_BLK_SUPPLEMENTAL_ARROWS_A - Alias for <COATL_UCD_BLK_SUP_ARROWS_A>
 *  COATL_UCD_BLK_SUP_ARROWS_B - '*Sup_Arrows_B*', '*Supplemental_Arrows_B*'
 *  COATL_UCD_BLK_SUPPLEMENTAL_ARROWS_B - Alias for <COATL_UCD_BLK_SUP_ARROWS_B>
 *  COATL_UCD_BLK_SUP_MATH_OPERATORS - '*Sup_Math_Operators*', '*Supplemental_Mathematical_Operators*'
 *  COATL_UCD_BLK_SUPPLEMENTAL_MATHEMATICAL_OPERATORS - Alias for <COATL_UCD_BLK_SUP_MATH_OPERATORS>
 *  COATL_UCD_BLK_SUP_PUA_A - '*Sup_PUA_A*', '*Supplementary_Private_Use_Area_A*'
 *  COATL_UCD_BLK_SUPPLEMENTARY_PRIVATE_USE_AREA_A - Alias for <COATL_UCD_BLK_SUP_PUA_A>
 *  COATL_UCD_BLK_SUP_PUA_B - '*Sup_PUA_B*', '*Supplementary_Private_Use_Area_B*'
 *  COATL_UCD_BLK_SUPPLEMENTARY_PRIVATE_USE_AREA_B - Alias for <COATL_UCD_BLK_SUP_PUA_B>
 *  COATL_UCD_BLK_SUP_PUNCTUATION - '*Sup_Punctuation*', '*Supplemental_Punctuation*'
 *  COATL_UCD_BLK_SUPPLEMENTAL_PUNCTUATION - Alias for <COATL_UCD_BLK_SUP_PUNCTUATION>
 *  COATL_UCD_BLK_SUPER_AND_SUB - '*Super_And_Sub*', '*Superscripts_And_Subscripts*'
 *  COATL_UCD_BLK_SUPERSCRIPTS_AND_SUBSCRIPTS - Alias for <COATL_UCD_BLK_SUPER_AND_SUB>
 *  COATL_UCD_BLK_SYLOTI_NAGRI - '*Syloti_Nagri*'
 *  COATL_UCD_BLK_SYRIAC - '*Syriac*'
 *  COATL_UCD_BLK_TAGALOG - '*Tagalog*'
 *  COATL_UCD_BLK_TAGBANWA - '*Tagbanwa*'
 *  COATL_UCD_BLK_TAGS - '*Tags*'
 *  COATL_UCD_BLK_TAI_LE - '*Tai_Le*'
 *  COATL_UCD_BLK_TAI_THAM - '*Tai_Tham*'
 *  COATL_UCD_BLK_TAI_VIET - '*Tai_Viet*'
 *  COATL_UCD_BLK_TAI_XUAN_JING - '*Tai_Xuan_Jing*', '*Tai_Xuan_Jing_Symbols*'
 *  COATL_UCD_BLK_TAI_XUAN_JING_SYMBOLS - Alias for <COATL_UCD_BLK_TAI_XUAN_JING>
 *  COATL_UCD_BLK_TAKRI - '*Takri*'
 *  COATL_UCD_BLK_TAMIL - '*Tamil*'
 *  COATL_UCD_BLK_TELUGU - '*Telugu*'
 *  COATL_UCD_BLK_THAANA - '*Thaana*'
 *  COATL_UCD_BLK_THAI - '*Thai*'
 *  COATL_UCD_BLK_TIBETAN - '*Tibetan*'
 *  COATL_UCD_BLK_TIFINAGH - '*Tifinagh*'
 *  COATL_UCD_BLK_TRANSPORT_AND_MAP - '*Transport_And_Map*', '*Transport_And_Map_Symbols*'
 *  COATL_UCD_BLK_TRANSPORT_AND_MAP_SYMBOLS - Alias for <COATL_UCD_BLK_TRANSPORT_AND_MAP>
 *  COATL_UCD_BLK_UCAS - '*UCAS*', '*Unified_Canadian_Aboriginal_Syllabics*', '*Canadian_Syllabics*'
 *  COATL_UCD_BLK_UNIFIED_CANADIAN_ABORIGINAL_SYLLABICS - Alias for <COATL_UCD_BLK_UCAS>
 *  COATL_UCD_BLK_CANADIAN_SYLLABICS - Alias for <COATL_UCD_BLK_UCAS>
 *  COATL_UCD_BLK_UCAS_EXT - '*UCAS_Ext*', '*Unified_Canadian_Aboriginal_Syllabics_Extended*'
 *  COATL_UCD_BLK_UNIFIED_CANADIAN_ABORIGINAL_SYLLABICS_EXTENDED - Alias for <COATL_UCD_BLK_UCAS_EXT>
 *  COATL_UCD_BLK_UGARITIC - '*Ugaritic*'
 *  COATL_UCD_BLK_VAI - '*Vai*'
 *  COATL_UCD_BLK_VEDIC_EXT - '*Vedic_Ext*', '*Vedic_Extensions*'
 *  COATL_UCD_BLK_VEDIC_EXTENSIONS - Alias for <COATL_UCD_BLK_VEDIC_EXT>
 *  COATL_UCD_BLK_VERTICAL_FORMS - '*Vertical_Forms*'
 *  COATL_UCD_BLK_VS - '*VS*', '*Variation_Selectors*'
 *  COATL_UCD_BLK_VARIATION_SELECTORS - Alias for <COATL_UCD_BLK_VS>
 *  COATL_UCD_BLK_VS_SUP - '*VS_Sup*', '*Variation_Selectors_Supplement*'
 *  COATL_UCD_BLK_VARIATION_SELECTORS_SUPPLEMENT - Alias for <COATL_UCD_BLK_VS_SUP>
 *  COATL_UCD_BLK_YI_RADICALS - '*Yi_Radicals*'
 *  COATL_UCD_BLK_YI_SYLLABLES - '*Yi_Syllables*'
 *  COATL_UCD_BLK_YIJING - '*Yijing*', '*Yijing_Hexagram_Symbols*'
 *  COATL_UCD_BLK_YIJING_HEXAGRAM_SYMBOLS - Alias for <COATL_UCD_BLK_YIJING>
 *
 * See also:
 *	<COATL_UCD_BLK>
 *---------------------------------------------------------------------------*/

typedef enum Coatl_Ucd_Blk {
    COATL_UCD_BLK_AEGEAN_NUMBERS=1,
    COATL_UCD_BLK_ALCHEMICAL=2,
	COATL_UCD_BLK_ALCHEMICAL_SYMBOLS=COATL_UCD_BLK_ALCHEMICAL,
    COATL_UCD_BLK_ALPHABETIC_PF=3,
	COATL_UCD_BLK_ALPHABETIC_PRESENTATION_FORMS=COATL_UCD_BLK_ALPHABETIC_PF,
    COATL_UCD_BLK_ANCIENT_GREEK_MUSIC=4,
	COATL_UCD_BLK_ANCIENT_GREEK_MUSICAL_NOTATION=COATL_UCD_BLK_ANCIENT_GREEK_MUSIC,
    COATL_UCD_BLK_ANCIENT_GREEK_NUMBERS=5,
    COATL_UCD_BLK_ANCIENT_SYMBOLS=6,
    COATL_UCD_BLK_ARABIC=7,
    COATL_UCD_BLK_ARABIC_EXT_A=8,
	COATL_UCD_BLK_ARABIC_EXTENDED_A=COATL_UCD_BLK_ARABIC_EXT_A,
    COATL_UCD_BLK_ARABIC_MATH=9,
	COATL_UCD_BLK_ARABIC_MATHEMATICAL_ALPHABETIC_SYMBOLS=COATL_UCD_BLK_ARABIC_MATH,
    COATL_UCD_BLK_ARABIC_PF_A=10,
	COATL_UCD_BLK_ARABIC_PRESENTATION_FORMS_A=COATL_UCD_BLK_ARABIC_PF_A,
    COATL_UCD_BLK_ARABIC_PF_B=11,
	COATL_UCD_BLK_ARABIC_PRESENTATION_FORMS_B=COATL_UCD_BLK_ARABIC_PF_B,
    COATL_UCD_BLK_ARABIC_SUP=12,
	COATL_UCD_BLK_ARABIC_SUPPLEMENT=COATL_UCD_BLK_ARABIC_SUP,
    COATL_UCD_BLK_ARMENIAN=13,
    COATL_UCD_BLK_ARROWS=14,
    COATL_UCD_BLK_ASCII=15,
	COATL_UCD_BLK_BASIC_LATIN=COATL_UCD_BLK_ASCII,
    COATL_UCD_BLK_AVESTAN=16,
    COATL_UCD_BLK_BALINESE=17,
    COATL_UCD_BLK_BAMUM=18,
    COATL_UCD_BLK_BAMUM_SUP=19,
	COATL_UCD_BLK_BAMUM_SUPPLEMENT=COATL_UCD_BLK_BAMUM_SUP,
    COATL_UCD_BLK_BATAK=20,
    COATL_UCD_BLK_BENGALI=21,
    COATL_UCD_BLK_BLOCK_ELEMENTS=22,
    COATL_UCD_BLK_BOPOMOFO=23,
    COATL_UCD_BLK_BOPOMOFO_EXT=24,
	COATL_UCD_BLK_BOPOMOFO_EXTENDED=COATL_UCD_BLK_BOPOMOFO_EXT,
    COATL_UCD_BLK_BOX_DRAWING=25,
    COATL_UCD_BLK_BRAHMI=26,
    COATL_UCD_BLK_BRAILLE=27,
	COATL_UCD_BLK_BRAILLE_PATTERNS=COATL_UCD_BLK_BRAILLE,
    COATL_UCD_BLK_BUGINESE=28,
    COATL_UCD_BLK_BUHID=29,
    COATL_UCD_BLK_BYZANTINE_MUSIC=30,
	COATL_UCD_BLK_BYZANTINE_MUSICAL_SYMBOLS=COATL_UCD_BLK_BYZANTINE_MUSIC,
    COATL_UCD_BLK_CARIAN=31,
    COATL_UCD_BLK_CHAKMA=32,
    COATL_UCD_BLK_CHAM=33,
    COATL_UCD_BLK_CHEROKEE=34,
    COATL_UCD_BLK_CJK=35,
	COATL_UCD_BLK_CJK_UNIFIED_IDEOGRAPHS=COATL_UCD_BLK_CJK,
    COATL_UCD_BLK_CJK_COMPAT=36,
	COATL_UCD_BLK_CJK_COMPATIBILITY=COATL_UCD_BLK_CJK_COMPAT,
    COATL_UCD_BLK_CJK_COMPAT_FORMS=37,
	COATL_UCD_BLK_CJK_COMPATIBILITY_FORMS=COATL_UCD_BLK_CJK_COMPAT_FORMS,
    COATL_UCD_BLK_CJK_COMPAT_IDEOGRAPHS=38,
	COATL_UCD_BLK_CJK_COMPATIBILITY_IDEOGRAPHS=COATL_UCD_BLK_CJK_COMPAT_IDEOGRAPHS,
    COATL_UCD_BLK_CJK_COMPAT_IDEOGRAPHS_SUP=39,
	COATL_UCD_BLK_CJK_COMPATIBILITY_IDEOGRAPHS_SUPPLEMENT=COATL_UCD_BLK_CJK_COMPAT_IDEOGRAPHS_SUP,
    COATL_UCD_BLK_CJK_EXT_A=40,
	COATL_UCD_BLK_CJK_UNIFIED_IDEOGRAPHS_EXTENSION_A=COATL_UCD_BLK_CJK_EXT_A,
    COATL_UCD_BLK_CJK_EXT_B=41,
	COATL_UCD_BLK_CJK_UNIFIED_IDEOGRAPHS_EXTENSION_B=COATL_UCD_BLK_CJK_EXT_B,
    COATL_UCD_BLK_CJK_EXT_C=42,
	COATL_UCD_BLK_CJK_UNIFIED_IDEOGRAPHS_EXTENSION_C=COATL_UCD_BLK_CJK_EXT_C,
    COATL_UCD_BLK_CJK_EXT_D=43,
	COATL_UCD_BLK_CJK_UNIFIED_IDEOGRAPHS_EXTENSION_D=COATL_UCD_BLK_CJK_EXT_D,
    COATL_UCD_BLK_CJK_RADICALS_SUP=44,
	COATL_UCD_BLK_CJK_RADICALS_SUPPLEMENT=COATL_UCD_BLK_CJK_RADICALS_SUP,
    COATL_UCD_BLK_CJK_STROKES=45,
    COATL_UCD_BLK_CJK_SYMBOLS=46,
	COATL_UCD_BLK_CJK_SYMBOLS_AND_PUNCTUATION=COATL_UCD_BLK_CJK_SYMBOLS,
    COATL_UCD_BLK_COMPAT_JAMO=47,
	COATL_UCD_BLK_HANGUL_COMPATIBILITY_JAMO=COATL_UCD_BLK_COMPAT_JAMO,
    COATL_UCD_BLK_CONTROL_PICTURES=48,
    COATL_UCD_BLK_COPTIC=49,
    COATL_UCD_BLK_COUNTING_ROD=50,
	COATL_UCD_BLK_COUNTING_ROD_NUMERALS=COATL_UCD_BLK_COUNTING_ROD,
    COATL_UCD_BLK_CUNEIFORM=51,
    COATL_UCD_BLK_CUNEIFORM_NUMBERS=52,
	COATL_UCD_BLK_CUNEIFORM_NUMBERS_AND_PUNCTUATION=COATL_UCD_BLK_CUNEIFORM_NUMBERS,
    COATL_UCD_BLK_CURRENCY_SYMBOLS=53,
    COATL_UCD_BLK_CYPRIOT_SYLLABARY=54,
    COATL_UCD_BLK_CYRILLIC=55,
    COATL_UCD_BLK_CYRILLIC_EXT_A=56,
	COATL_UCD_BLK_CYRILLIC_EXTENDED_A=COATL_UCD_BLK_CYRILLIC_EXT_A,
    COATL_UCD_BLK_CYRILLIC_EXT_B=57,
	COATL_UCD_BLK_CYRILLIC_EXTENDED_B=COATL_UCD_BLK_CYRILLIC_EXT_B,
    COATL_UCD_BLK_CYRILLIC_SUP=58,
	COATL_UCD_BLK_CYRILLIC_SUPPLEMENT=COATL_UCD_BLK_CYRILLIC_SUP,
	COATL_UCD_BLK_CYRILLIC_SUPPLEMENTARY=COATL_UCD_BLK_CYRILLIC_SUP,
    COATL_UCD_BLK_DESERET=59,
    COATL_UCD_BLK_DEVANAGARI=60,
    COATL_UCD_BLK_DEVANAGARI_EXT=61,
	COATL_UCD_BLK_DEVANAGARI_EXTENDED=COATL_UCD_BLK_DEVANAGARI_EXT,
    COATL_UCD_BLK_DIACRITICALS=62,
	COATL_UCD_BLK_COMBINING_DIACRITICAL_MARKS=COATL_UCD_BLK_DIACRITICALS,
    COATL_UCD_BLK_DIACRITICALS_FOR_SYMBOLS=63,
	COATL_UCD_BLK_COMBINING_DIACRITICAL_MARKS_FOR_SYMBOLS=COATL_UCD_BLK_DIACRITICALS_FOR_SYMBOLS,
	COATL_UCD_BLK_COMBINING_MARKS_FOR_SYMBOLS=COATL_UCD_BLK_DIACRITICALS_FOR_SYMBOLS,
    COATL_UCD_BLK_DIACRITICALS_SUP=64,
	COATL_UCD_BLK_COMBINING_DIACRITICAL_MARKS_SUPPLEMENT=COATL_UCD_BLK_DIACRITICALS_SUP,
    COATL_UCD_BLK_DINGBATS=65,
    COATL_UCD_BLK_DOMINO=66,
	COATL_UCD_BLK_DOMINO_TILES=COATL_UCD_BLK_DOMINO,
    COATL_UCD_BLK_EGYPTIAN_HIEROGLYPHS=67,
    COATL_UCD_BLK_EMOTICONS=68,
    COATL_UCD_BLK_ENCLOSED_ALPHANUM=69,
	COATL_UCD_BLK_ENCLOSED_ALPHANUMERICS=COATL_UCD_BLK_ENCLOSED_ALPHANUM,
    COATL_UCD_BLK_ENCLOSED_ALPHANUM_SUP=70,
	COATL_UCD_BLK_ENCLOSED_ALPHANUMERIC_SUPPLEMENT=COATL_UCD_BLK_ENCLOSED_ALPHANUM_SUP,
    COATL_UCD_BLK_ENCLOSED_CJK=71,
	COATL_UCD_BLK_ENCLOSED_CJK_LETTERS_AND_MONTHS=COATL_UCD_BLK_ENCLOSED_CJK,
    COATL_UCD_BLK_ENCLOSED_IDEOGRAPHIC_SUP=72,
	COATL_UCD_BLK_ENCLOSED_IDEOGRAPHIC_SUPPLEMENT=COATL_UCD_BLK_ENCLOSED_IDEOGRAPHIC_SUP,
    COATL_UCD_BLK_ETHIOPIC=73,
    COATL_UCD_BLK_ETHIOPIC_EXT=74,
	COATL_UCD_BLK_ETHIOPIC_EXTENDED=COATL_UCD_BLK_ETHIOPIC_EXT,
    COATL_UCD_BLK_ETHIOPIC_EXT_A=75,
	COATL_UCD_BLK_ETHIOPIC_EXTENDED_A=COATL_UCD_BLK_ETHIOPIC_EXT_A,
    COATL_UCD_BLK_ETHIOPIC_SUP=76,
	COATL_UCD_BLK_ETHIOPIC_SUPPLEMENT=COATL_UCD_BLK_ETHIOPIC_SUP,
    COATL_UCD_BLK_GEOMETRIC_SHAPES=77,
    COATL_UCD_BLK_GEORGIAN=78,
    COATL_UCD_BLK_GEORGIAN_SUP=79,
	COATL_UCD_BLK_GEORGIAN_SUPPLEMENT=COATL_UCD_BLK_GEORGIAN_SUP,
    COATL_UCD_BLK_GLAGOLITIC=80,
    COATL_UCD_BLK_GOTHIC=81,
    COATL_UCD_BLK_GREEK=82,
	COATL_UCD_BLK_GREEK_AND_COPTIC=COATL_UCD_BLK_GREEK,
    COATL_UCD_BLK_GREEK_EXT=83,
	COATL_UCD_BLK_GREEK_EXTENDED=COATL_UCD_BLK_GREEK_EXT,
    COATL_UCD_BLK_GUJARATI=84,
    COATL_UCD_BLK_GURMUKHI=85,
    COATL_UCD_BLK_HALF_AND_FULL_FORMS=86,
	COATL_UCD_BLK_HALFWIDTH_AND_FULLWIDTH_FORMS=COATL_UCD_BLK_HALF_AND_FULL_FORMS,
    COATL_UCD_BLK_HALF_MARKS=87,
	COATL_UCD_BLK_COMBINING_HALF_MARKS=COATL_UCD_BLK_HALF_MARKS,
    COATL_UCD_BLK_HANGUL=88,
	COATL_UCD_BLK_HANGUL_SYLLABLES=COATL_UCD_BLK_HANGUL,
    COATL_UCD_BLK_HANUNOO=89,
    COATL_UCD_BLK_HEBREW=90,
    COATL_UCD_BLK_HIGH_PU_SURROGATES=91,
	COATL_UCD_BLK_HIGH_PRIVATE_USE_SURROGATES=COATL_UCD_BLK_HIGH_PU_SURROGATES,
    COATL_UCD_BLK_HIGH_SURROGATES=92,
    COATL_UCD_BLK_HIRAGANA=93,
    COATL_UCD_BLK_IDC=94,
	COATL_UCD_BLK_IDEOGRAPHIC_DESCRIPTION_CHARACTERS=COATL_UCD_BLK_IDC,
    COATL_UCD_BLK_IMPERIAL_ARAMAIC=95,
    COATL_UCD_BLK_INDIC_NUMBER_FORMS=96,
	COATL_UCD_BLK_COMMON_INDIC_NUMBER_FORMS=COATL_UCD_BLK_INDIC_NUMBER_FORMS,
    COATL_UCD_BLK_INSCRIPTIONAL_PAHLAVI=97,
    COATL_UCD_BLK_INSCRIPTIONAL_PARTHIAN=98,
    COATL_UCD_BLK_IPA_EXT=99,
	COATL_UCD_BLK_IPA_EXTENSIONS=COATL_UCD_BLK_IPA_EXT,
    COATL_UCD_BLK_JAMO=100,
	COATL_UCD_BLK_HANGUL_JAMO=COATL_UCD_BLK_JAMO,
    COATL_UCD_BLK_JAMO_EXT_A=101,
	COATL_UCD_BLK_HANGUL_JAMO_EXTENDED_A=COATL_UCD_BLK_JAMO_EXT_A,
    COATL_UCD_BLK_JAMO_EXT_B=102,
	COATL_UCD_BLK_HANGUL_JAMO_EXTENDED_B=COATL_UCD_BLK_JAMO_EXT_B,
    COATL_UCD_BLK_JAVANESE=103,
    COATL_UCD_BLK_KAITHI=104,
    COATL_UCD_BLK_KANA_SUP=105,
	COATL_UCD_BLK_KANA_SUPPLEMENT=COATL_UCD_BLK_KANA_SUP,
    COATL_UCD_BLK_KANBUN=106,
    COATL_UCD_BLK_KANGXI=107,
	COATL_UCD_BLK_KANGXI_RADICALS=COATL_UCD_BLK_KANGXI,
    COATL_UCD_BLK_KANNADA=108,
    COATL_UCD_BLK_KATAKANA=109,
    COATL_UCD_BLK_KATAKANA_EXT=110,
	COATL_UCD_BLK_KATAKANA_PHONETIC_EXTENSIONS=COATL_UCD_BLK_KATAKANA_EXT,
    COATL_UCD_BLK_KAYAH_LI=111,
    COATL_UCD_BLK_KHAROSHTHI=112,
    COATL_UCD_BLK_KHMER=113,
    COATL_UCD_BLK_KHMER_SYMBOLS=114,
    COATL_UCD_BLK_LAO=115,
    COATL_UCD_BLK_LATIN_1_SUP=116,
	COATL_UCD_BLK_LATIN_1_SUPPLEMENT=COATL_UCD_BLK_LATIN_1_SUP,
	COATL_UCD_BLK_LATIN_1=COATL_UCD_BLK_LATIN_1_SUP,
    COATL_UCD_BLK_LATIN_EXT_A=117,
	COATL_UCD_BLK_LATIN_EXTENDED_A=COATL_UCD_BLK_LATIN_EXT_A,
    COATL_UCD_BLK_LATIN_EXT_ADDITIONAL=118,
	COATL_UCD_BLK_LATIN_EXTENDED_ADDITIONAL=COATL_UCD_BLK_LATIN_EXT_ADDITIONAL,
    COATL_UCD_BLK_LATIN_EXT_B=119,
	COATL_UCD_BLK_LATIN_EXTENDED_B=COATL_UCD_BLK_LATIN_EXT_B,
    COATL_UCD_BLK_LATIN_EXT_C=120,
	COATL_UCD_BLK_LATIN_EXTENDED_C=COATL_UCD_BLK_LATIN_EXT_C,
    COATL_UCD_BLK_LATIN_EXT_D=121,
	COATL_UCD_BLK_LATIN_EXTENDED_D=COATL_UCD_BLK_LATIN_EXT_D,
    COATL_UCD_BLK_LEPCHA=122,
    COATL_UCD_BLK_LETTERLIKE_SYMBOLS=123,
    COATL_UCD_BLK_LIMBU=124,
    COATL_UCD_BLK_LINEAR_B_IDEOGRAMS=125,
    COATL_UCD_BLK_LINEAR_B_SYLLABARY=126,
    COATL_UCD_BLK_LISU=127,
    COATL_UCD_BLK_LOW_SURROGATES=128,
    COATL_UCD_BLK_LYCIAN=129,
    COATL_UCD_BLK_LYDIAN=130,
    COATL_UCD_BLK_MAHJONG=131,
	COATL_UCD_BLK_MAHJONG_TILES=COATL_UCD_BLK_MAHJONG,
    COATL_UCD_BLK_MALAYALAM=132,
    COATL_UCD_BLK_MANDAIC=133,
    COATL_UCD_BLK_MATH_ALPHANUM=134,
	COATL_UCD_BLK_MATHEMATICAL_ALPHANUMERIC_SYMBOLS=COATL_UCD_BLK_MATH_ALPHANUM,
    COATL_UCD_BLK_MATH_OPERATORS=135,
	COATL_UCD_BLK_MATHEMATICAL_OPERATORS=COATL_UCD_BLK_MATH_OPERATORS,
    COATL_UCD_BLK_MEETEI_MAYEK=136,
    COATL_UCD_BLK_MEETEI_MAYEK_EXT=137,
	COATL_UCD_BLK_MEETEI_MAYEK_EXTENSIONS=COATL_UCD_BLK_MEETEI_MAYEK_EXT,
    COATL_UCD_BLK_MEROITIC_CURSIVE=138,
    COATL_UCD_BLK_MEROITIC_HIEROGLYPHS=139,
    COATL_UCD_BLK_MIAO=140,
    COATL_UCD_BLK_MISC_ARROWS=141,
	COATL_UCD_BLK_MISCELLANEOUS_SYMBOLS_AND_ARROWS=COATL_UCD_BLK_MISC_ARROWS,
    COATL_UCD_BLK_MISC_MATH_SYMBOLS_A=142,
	COATL_UCD_BLK_MISCELLANEOUS_MATHEMATICAL_SYMBOLS_A=COATL_UCD_BLK_MISC_MATH_SYMBOLS_A,
    COATL_UCD_BLK_MISC_MATH_SYMBOLS_B=143,
	COATL_UCD_BLK_MISCELLANEOUS_MATHEMATICAL_SYMBOLS_B=COATL_UCD_BLK_MISC_MATH_SYMBOLS_B,
    COATL_UCD_BLK_MISC_PICTOGRAPHS=144,
	COATL_UCD_BLK_MISCELLANEOUS_SYMBOLS_AND_PICTOGRAPHS=COATL_UCD_BLK_MISC_PICTOGRAPHS,
    COATL_UCD_BLK_MISC_SYMBOLS=145,
	COATL_UCD_BLK_MISCELLANEOUS_SYMBOLS=COATL_UCD_BLK_MISC_SYMBOLS,
    COATL_UCD_BLK_MISC_TECHNICAL=146,
	COATL_UCD_BLK_MISCELLANEOUS_TECHNICAL=COATL_UCD_BLK_MISC_TECHNICAL,
    COATL_UCD_BLK_MODIFIER_LETTERS=147,
	COATL_UCD_BLK_SPACING_MODIFIER_LETTERS=COATL_UCD_BLK_MODIFIER_LETTERS,
    COATL_UCD_BLK_MODIFIER_TONE_LETTERS=148,
    COATL_UCD_BLK_MONGOLIAN=149,
    COATL_UCD_BLK_MUSIC=150,
	COATL_UCD_BLK_MUSICAL_SYMBOLS=COATL_UCD_BLK_MUSIC,
    COATL_UCD_BLK_MYANMAR=151,
    COATL_UCD_BLK_MYANMAR_EXT_A=152,
	COATL_UCD_BLK_MYANMAR_EXTENDED_A=COATL_UCD_BLK_MYANMAR_EXT_A,
    COATL_UCD_BLK_NB=153,
	COATL_UCD_BLK_NO_BLOCK=COATL_UCD_BLK_NB,
    COATL_UCD_BLK_NEW_TAI_LUE=154,
    COATL_UCD_BLK_NKO=155,
    COATL_UCD_BLK_NUMBER_FORMS=156,
    COATL_UCD_BLK_OCR=157,
	COATL_UCD_BLK_OPTICAL_CHARACTER_RECOGNITION=COATL_UCD_BLK_OCR,
    COATL_UCD_BLK_OGHAM=158,
    COATL_UCD_BLK_OL_CHIKI=159,
    COATL_UCD_BLK_OLD_ITALIC=160,
    COATL_UCD_BLK_OLD_PERSIAN=161,
    COATL_UCD_BLK_OLD_SOUTH_ARABIAN=162,
    COATL_UCD_BLK_OLD_TURKIC=163,
    COATL_UCD_BLK_ORIYA=164,
    COATL_UCD_BLK_OSMANYA=165,
    COATL_UCD_BLK_PHAGS_PA=166,
    COATL_UCD_BLK_PHAISTOS=167,
	COATL_UCD_BLK_PHAISTOS_DISC=COATL_UCD_BLK_PHAISTOS,
    COATL_UCD_BLK_PHOENICIAN=168,
    COATL_UCD_BLK_PHONETIC_EXT=169,
	COATL_UCD_BLK_PHONETIC_EXTENSIONS=COATL_UCD_BLK_PHONETIC_EXT,
    COATL_UCD_BLK_PHONETIC_EXT_SUP=170,
	COATL_UCD_BLK_PHONETIC_EXTENSIONS_SUPPLEMENT=COATL_UCD_BLK_PHONETIC_EXT_SUP,
    COATL_UCD_BLK_PLAYING_CARDS=171,
    COATL_UCD_BLK_PUA=172,
	COATL_UCD_BLK_PRIVATE_USE_AREA=COATL_UCD_BLK_PUA,
	COATL_UCD_BLK_PRIVATE_USE=COATL_UCD_BLK_PUA,
    COATL_UCD_BLK_PUNCTUATION=173,
	COATL_UCD_BLK_GENERAL_PUNCTUATION=COATL_UCD_BLK_PUNCTUATION,
    COATL_UCD_BLK_REJANG=174,
    COATL_UCD_BLK_RUMI=175,
	COATL_UCD_BLK_RUMI_NUMERAL_SYMBOLS=COATL_UCD_BLK_RUMI,
    COATL_UCD_BLK_RUNIC=176,
    COATL_UCD_BLK_SAMARITAN=177,
    COATL_UCD_BLK_SAURASHTRA=178,
    COATL_UCD_BLK_SHARADA=179,
    COATL_UCD_BLK_SHAVIAN=180,
    COATL_UCD_BLK_SINHALA=181,
    COATL_UCD_BLK_SMALL_FORMS=182,
	COATL_UCD_BLK_SMALL_FORM_VARIANTS=COATL_UCD_BLK_SMALL_FORMS,
    COATL_UCD_BLK_SORA_SOMPENG=183,
    COATL_UCD_BLK_SPECIALS=184,
    COATL_UCD_BLK_SUNDANESE=185,
    COATL_UCD_BLK_SUNDANESE_SUP=186,
	COATL_UCD_BLK_SUNDANESE_SUPPLEMENT=COATL_UCD_BLK_SUNDANESE_SUP,
    COATL_UCD_BLK_SUP_ARROWS_A=187,
	COATL_UCD_BLK_SUPPLEMENTAL_ARROWS_A=COATL_UCD_BLK_SUP_ARROWS_A,
    COATL_UCD_BLK_SUP_ARROWS_B=188,
	COATL_UCD_BLK_SUPPLEMENTAL_ARROWS_B=COATL_UCD_BLK_SUP_ARROWS_B,
    COATL_UCD_BLK_SUP_MATH_OPERATORS=189,
	COATL_UCD_BLK_SUPPLEMENTAL_MATHEMATICAL_OPERATORS=COATL_UCD_BLK_SUP_MATH_OPERATORS,
    COATL_UCD_BLK_SUP_PUA_A=190,
	COATL_UCD_BLK_SUPPLEMENTARY_PRIVATE_USE_AREA_A=COATL_UCD_BLK_SUP_PUA_A,
    COATL_UCD_BLK_SUP_PUA_B=191,
	COATL_UCD_BLK_SUPPLEMENTARY_PRIVATE_USE_AREA_B=COATL_UCD_BLK_SUP_PUA_B,
    COATL_UCD_BLK_SUP_PUNCTUATION=192,
	COATL_UCD_BLK_SUPPLEMENTAL_PUNCTUATION=COATL_UCD_BLK_SUP_PUNCTUATION,
    COATL_UCD_BLK_SUPER_AND_SUB=193,
	COATL_UCD_BLK_SUPERSCRIPTS_AND_SUBSCRIPTS=COATL_UCD_BLK_SUPER_AND_SUB,
    COATL_UCD_BLK_SYLOTI_NAGRI=194,
    COATL_UCD_BLK_SYRIAC=195,
    COATL_UCD_BLK_TAGALOG=196,
    COATL_UCD_BLK_TAGBANWA=197,
    COATL_UCD_BLK_TAGS=198,
    COATL_UCD_BLK_TAI_LE=199,
    COATL_UCD_BLK_TAI_THAM=200,
    COATL_UCD_BLK_TAI_VIET=201,
    COATL_UCD_BLK_TAI_XUAN_JING=202,
	COATL_UCD_BLK_TAI_XUAN_JING_SYMBOLS=COATL_UCD_BLK_TAI_XUAN_JING,
    COATL_UCD_BLK_TAKRI=203,
    COATL_UCD_BLK_TAMIL=204,
    COATL_UCD_BLK_TELUGU=205,
    COATL_UCD_BLK_THAANA=206,
    COATL_UCD_BLK_THAI=207,
    COATL_UCD_BLK_TIBETAN=208,
    COATL_UCD_BLK_TIFINAGH=209,
    COATL_UCD_BLK_TRANSPORT_AND_MAP=210,
	COATL_UCD_BLK_TRANSPORT_AND_MAP_SYMBOLS=COATL_UCD_BLK_TRANSPORT_AND_MAP,
    COATL_UCD_BLK_UCAS=211,
	COATL_UCD_BLK_UNIFIED_CANADIAN_ABORIGINAL_SYLLABICS=COATL_UCD_BLK_UCAS,
	COATL_UCD_BLK_CANADIAN_SYLLABICS=COATL_UCD_BLK_UCAS,
    COATL_UCD_BLK_UCAS_EXT=212,
	COATL_UCD_BLK_UNIFIED_CANADIAN_ABORIGINAL_SYLLABICS_EXTENDED=COATL_UCD_BLK_UCAS_EXT,
    COATL_UCD_BLK_UGARITIC=213,
    COATL_UCD_BLK_VAI=214,
    COATL_UCD_BLK_VEDIC_EXT=215,
	COATL_UCD_BLK_VEDIC_EXTENSIONS=COATL_UCD_BLK_VEDIC_EXT,
    COATL_UCD_BLK_VERTICAL_FORMS=216,
    COATL_UCD_BLK_VS=217,
	COATL_UCD_BLK_VARIATION_SELECTORS=COATL_UCD_BLK_VS,
    COATL_UCD_BLK_VS_SUP=218,
	COATL_UCD_BLK_VARIATION_SELECTORS_SUPPLEMENT=COATL_UCD_BLK_VS_SUP,
    COATL_UCD_BLK_YI_RADICALS=219,
    COATL_UCD_BLK_YI_SYLLABLES=220,
    COATL_UCD_BLK_YIJING=221,
	COATL_UCD_BLK_YIJING_HEXAGRAM_SYMBOLS=COATL_UCD_BLK_YIJING,

} Coatl_Ucd_Blk;

/*---------------------------------------------------------------------------
 * Constant: COATL_UCD_BLK_NBVALUES
 *
 *	Number of values for Unicode character property '*blk*'.
 *
 * See also:
 *	<Coatl_Ucd_Blk>
 *---------------------------------------------------------------------------*/

#define COATL_UCD_BLK_NBVALUES	221

/*---------------------------------------------------------------------------
 * Enum: Coatl_Ucd_Ccc
 *
 *	Values for Unicode character property '*ccc*'.
 *
 *	Names are automatically generated from the UCD file
 *	*PropertyValueAliases.txt*
 *
 *  COATL_UCD_CCC_0 - '*0*', '*NR*', '*Not_Reordered*'
 *  COATL_UCD_CCC_NR - Alias for <COATL_UCD_CCC_0>
 *  COATL_UCD_CCC_NOT_REORDERED - Alias for <COATL_UCD_CCC_0>
 *  COATL_UCD_CCC_1 - '*1*', '*OV*', '*Overlay*'
 *  COATL_UCD_CCC_OV - Alias for <COATL_UCD_CCC_1>
 *  COATL_UCD_CCC_OVERLAY - Alias for <COATL_UCD_CCC_1>
 *  COATL_UCD_CCC_7 - '*7*', '*NK*', '*Nukta*'
 *  COATL_UCD_CCC_NK - Alias for <COATL_UCD_CCC_7>
 *  COATL_UCD_CCC_NUKTA - Alias for <COATL_UCD_CCC_7>
 *  COATL_UCD_CCC_8 - '*8*', '*KV*', '*Kana_Voicing*'
 *  COATL_UCD_CCC_KV - Alias for <COATL_UCD_CCC_8>
 *  COATL_UCD_CCC_KANA_VOICING - Alias for <COATL_UCD_CCC_8>
 *  COATL_UCD_CCC_9 - '*9*', '*VR*', '*Virama*'
 *  COATL_UCD_CCC_VR - Alias for <COATL_UCD_CCC_9>
 *  COATL_UCD_CCC_VIRAMA - Alias for <COATL_UCD_CCC_9>
 *  COATL_UCD_CCC_10 - '*10*', '*CCC10*'
 *  COATL_UCD_CCC_CCC10 - Alias for <COATL_UCD_CCC_10>
 *  COATL_UCD_CCC_11 - '*11*', '*CCC11*'
 *  COATL_UCD_CCC_CCC11 - Alias for <COATL_UCD_CCC_11>
 *  COATL_UCD_CCC_12 - '*12*', '*CCC12*'
 *  COATL_UCD_CCC_CCC12 - Alias for <COATL_UCD_CCC_12>
 *  COATL_UCD_CCC_13 - '*13*', '*CCC13*'
 *  COATL_UCD_CCC_CCC13 - Alias for <COATL_UCD_CCC_13>
 *  COATL_UCD_CCC_14 - '*14*', '*CCC14*'
 *  COATL_UCD_CCC_CCC14 - Alias for <COATL_UCD_CCC_14>
 *  COATL_UCD_CCC_15 - '*15*', '*CCC15*'
 *  COATL_UCD_CCC_CCC15 - Alias for <COATL_UCD_CCC_15>
 *  COATL_UCD_CCC_16 - '*16*', '*CCC16*'
 *  COATL_UCD_CCC_CCC16 - Alias for <COATL_UCD_CCC_16>
 *  COATL_UCD_CCC_17 - '*17*', '*CCC17*'
 *  COATL_UCD_CCC_CCC17 - Alias for <COATL_UCD_CCC_17>
 *  COATL_UCD_CCC_18 - '*18*', '*CCC18*'
 *  COATL_UCD_CCC_CCC18 - Alias for <COATL_UCD_CCC_18>
 *  COATL_UCD_CCC_19 - '*19*', '*CCC19*'
 *  COATL_UCD_CCC_CCC19 - Alias for <COATL_UCD_CCC_19>
 *  COATL_UCD_CCC_20 - '*20*', '*CCC20*'
 *  COATL_UCD_CCC_CCC20 - Alias for <COATL_UCD_CCC_20>
 *  COATL_UCD_CCC_21 - '*21*', '*CCC21*'
 *  COATL_UCD_CCC_CCC21 - Alias for <COATL_UCD_CCC_21>
 *  COATL_UCD_CCC_22 - '*22*', '*CCC22*'
 *  COATL_UCD_CCC_CCC22 - Alias for <COATL_UCD_CCC_22>
 *  COATL_UCD_CCC_23 - '*23*', '*CCC23*'
 *  COATL_UCD_CCC_CCC23 - Alias for <COATL_UCD_CCC_23>
 *  COATL_UCD_CCC_24 - '*24*', '*CCC24*'
 *  COATL_UCD_CCC_CCC24 - Alias for <COATL_UCD_CCC_24>
 *  COATL_UCD_CCC_25 - '*25*', '*CCC25*'
 *  COATL_UCD_CCC_CCC25 - Alias for <COATL_UCD_CCC_25>
 *  COATL_UCD_CCC_26 - '*26*', '*CCC26*'
 *  COATL_UCD_CCC_CCC26 - Alias for <COATL_UCD_CCC_26>
 *  COATL_UCD_CCC_27 - '*27*', '*CCC27*'
 *  COATL_UCD_CCC_CCC27 - Alias for <COATL_UCD_CCC_27>
 *  COATL_UCD_CCC_28 - '*28*', '*CCC28*'
 *  COATL_UCD_CCC_CCC28 - Alias for <COATL_UCD_CCC_28>
 *  COATL_UCD_CCC_29 - '*29*', '*CCC29*'
 *  COATL_UCD_CCC_CCC29 - Alias for <COATL_UCD_CCC_29>
 *  COATL_UCD_CCC_30 - '*30*', '*CCC30*'
 *  COATL_UCD_CCC_CCC30 - Alias for <COATL_UCD_CCC_30>
 *  COATL_UCD_CCC_31 - '*31*', '*CCC31*'
 *  COATL_UCD_CCC_CCC31 - Alias for <COATL_UCD_CCC_31>
 *  COATL_UCD_CCC_32 - '*32*', '*CCC32*'
 *  COATL_UCD_CCC_CCC32 - Alias for <COATL_UCD_CCC_32>
 *  COATL_UCD_CCC_33 - '*33*', '*CCC33*'
 *  COATL_UCD_CCC_CCC33 - Alias for <COATL_UCD_CCC_33>
 *  COATL_UCD_CCC_34 - '*34*', '*CCC34*'
 *  COATL_UCD_CCC_CCC34 - Alias for <COATL_UCD_CCC_34>
 *  COATL_UCD_CCC_35 - '*35*', '*CCC35*'
 *  COATL_UCD_CCC_CCC35 - Alias for <COATL_UCD_CCC_35>
 *  COATL_UCD_CCC_36 - '*36*', '*CCC36*'
 *  COATL_UCD_CCC_CCC36 - Alias for <COATL_UCD_CCC_36>
 *  COATL_UCD_CCC_84 - '*84*', '*CCC84*'
 *  COATL_UCD_CCC_CCC84 - Alias for <COATL_UCD_CCC_84>
 *  COATL_UCD_CCC_91 - '*91*', '*CCC91*'
 *  COATL_UCD_CCC_CCC91 - Alias for <COATL_UCD_CCC_91>
 *  COATL_UCD_CCC_103 - '*103*', '*CCC103*'
 *  COATL_UCD_CCC_CCC103 - Alias for <COATL_UCD_CCC_103>
 *  COATL_UCD_CCC_107 - '*107*', '*CCC107*'
 *  COATL_UCD_CCC_CCC107 - Alias for <COATL_UCD_CCC_107>
 *  COATL_UCD_CCC_118 - '*118*', '*CCC118*'
 *  COATL_UCD_CCC_CCC118 - Alias for <COATL_UCD_CCC_118>
 *  COATL_UCD_CCC_122 - '*122*', '*CCC122*'
 *  COATL_UCD_CCC_CCC122 - Alias for <COATL_UCD_CCC_122>
 *  COATL_UCD_CCC_129 - '*129*', '*CCC129*'
 *  COATL_UCD_CCC_CCC129 - Alias for <COATL_UCD_CCC_129>
 *  COATL_UCD_CCC_130 - '*130*', '*CCC130*'
 *  COATL_UCD_CCC_CCC130 - Alias for <COATL_UCD_CCC_130>
 *  COATL_UCD_CCC_132 - '*132*', '*CCC133*'
 *  COATL_UCD_CCC_CCC133 - Alias for <COATL_UCD_CCC_132>
 *  COATL_UCD_CCC_200 - '*200*', '*ATBL*', '*Attached_Below_Left*'
 *  COATL_UCD_CCC_ATBL - Alias for <COATL_UCD_CCC_200>
 *  COATL_UCD_CCC_ATTACHED_BELOW_LEFT - Alias for <COATL_UCD_CCC_200>
 *  COATL_UCD_CCC_202 - '*202*', '*ATB*', '*Attached_Below*'
 *  COATL_UCD_CCC_ATB - Alias for <COATL_UCD_CCC_202>
 *  COATL_UCD_CCC_ATTACHED_BELOW - Alias for <COATL_UCD_CCC_202>
 *  COATL_UCD_CCC_214 - '*214*', '*ATA*', '*Attached_Above*'
 *  COATL_UCD_CCC_ATA - Alias for <COATL_UCD_CCC_214>
 *  COATL_UCD_CCC_ATTACHED_ABOVE - Alias for <COATL_UCD_CCC_214>
 *  COATL_UCD_CCC_216 - '*216*', '*ATAR*', '*Attached_Above_Right*'
 *  COATL_UCD_CCC_ATAR - Alias for <COATL_UCD_CCC_216>
 *  COATL_UCD_CCC_ATTACHED_ABOVE_RIGHT - Alias for <COATL_UCD_CCC_216>
 *  COATL_UCD_CCC_218 - '*218*', '*BL*', '*Below_Left*'
 *  COATL_UCD_CCC_BL - Alias for <COATL_UCD_CCC_218>
 *  COATL_UCD_CCC_BELOW_LEFT - Alias for <COATL_UCD_CCC_218>
 *  COATL_UCD_CCC_220 - '*220*', '*B*', '*Below*'
 *  COATL_UCD_CCC_B - Alias for <COATL_UCD_CCC_220>
 *  COATL_UCD_CCC_BELOW - Alias for <COATL_UCD_CCC_220>
 *  COATL_UCD_CCC_222 - '*222*', '*BR*', '*Below_Right*'
 *  COATL_UCD_CCC_BR - Alias for <COATL_UCD_CCC_222>
 *  COATL_UCD_CCC_BELOW_RIGHT - Alias for <COATL_UCD_CCC_222>
 *  COATL_UCD_CCC_224 - '*224*', '*L*', '*Left*'
 *  COATL_UCD_CCC_L - Alias for <COATL_UCD_CCC_224>
 *  COATL_UCD_CCC_LEFT - Alias for <COATL_UCD_CCC_224>
 *  COATL_UCD_CCC_226 - '*226*', '*R*', '*Right*'
 *  COATL_UCD_CCC_R - Alias for <COATL_UCD_CCC_226>
 *  COATL_UCD_CCC_RIGHT - Alias for <COATL_UCD_CCC_226>
 *  COATL_UCD_CCC_228 - '*228*', '*AL*', '*Above_Left*'
 *  COATL_UCD_CCC_AL - Alias for <COATL_UCD_CCC_228>
 *  COATL_UCD_CCC_ABOVE_LEFT - Alias for <COATL_UCD_CCC_228>
 *  COATL_UCD_CCC_230 - '*230*', '*A*', '*Above*'
 *  COATL_UCD_CCC_A - Alias for <COATL_UCD_CCC_230>
 *  COATL_UCD_CCC_ABOVE - Alias for <COATL_UCD_CCC_230>
 *  COATL_UCD_CCC_232 - '*232*', '*AR*', '*Above_Right*'
 *  COATL_UCD_CCC_AR - Alias for <COATL_UCD_CCC_232>
 *  COATL_UCD_CCC_ABOVE_RIGHT - Alias for <COATL_UCD_CCC_232>
 *  COATL_UCD_CCC_233 - '*233*', '*DB*', '*Double_Below*'
 *  COATL_UCD_CCC_DB - Alias for <COATL_UCD_CCC_233>
 *  COATL_UCD_CCC_DOUBLE_BELOW - Alias for <COATL_UCD_CCC_233>
 *  COATL_UCD_CCC_234 - '*234*', '*DA*', '*Double_Above*'
 *  COATL_UCD_CCC_DA - Alias for <COATL_UCD_CCC_234>
 *  COATL_UCD_CCC_DOUBLE_ABOVE - Alias for <COATL_UCD_CCC_234>
 *  COATL_UCD_CCC_240 - '*240*', '*IS*', '*Iota_Subscript*'
 *  COATL_UCD_CCC_IS - Alias for <COATL_UCD_CCC_240>
 *  COATL_UCD_CCC_IOTA_SUBSCRIPT - Alias for <COATL_UCD_CCC_240>
 *
 * See also:
 *	<COATL_UCD_CCC>
 *---------------------------------------------------------------------------*/

typedef enum Coatl_Ucd_Ccc {
    COATL_UCD_CCC_0=1,
	COATL_UCD_CCC_NR=COATL_UCD_CCC_0,
	COATL_UCD_CCC_NOT_REORDERED=COATL_UCD_CCC_0,
    COATL_UCD_CCC_1=2,
	COATL_UCD_CCC_OV=COATL_UCD_CCC_1,
	COATL_UCD_CCC_OVERLAY=COATL_UCD_CCC_1,
    COATL_UCD_CCC_7=3,
	COATL_UCD_CCC_NK=COATL_UCD_CCC_7,
	COATL_UCD_CCC_NUKTA=COATL_UCD_CCC_7,
    COATL_UCD_CCC_8=4,
	COATL_UCD_CCC_KV=COATL_UCD_CCC_8,
	COATL_UCD_CCC_KANA_VOICING=COATL_UCD_CCC_8,
    COATL_UCD_CCC_9=5,
	COATL_UCD_CCC_VR=COATL_UCD_CCC_9,
	COATL_UCD_CCC_VIRAMA=COATL_UCD_CCC_9,
    COATL_UCD_CCC_10=6,
	COATL_UCD_CCC_CCC10=COATL_UCD_CCC_10,
    COATL_UCD_CCC_11=7,
	COATL_UCD_CCC_CCC11=COATL_UCD_CCC_11,
    COATL_UCD_CCC_12=8,
	COATL_UCD_CCC_CCC12=COATL_UCD_CCC_12,
    COATL_UCD_CCC_13=9,
	COATL_UCD_CCC_CCC13=COATL_UCD_CCC_13,
    COATL_UCD_CCC_14=10,
	COATL_UCD_CCC_CCC14=COATL_UCD_CCC_14,
    COATL_UCD_CCC_15=11,
	COATL_UCD_CCC_CCC15=COATL_UCD_CCC_15,
    COATL_UCD_CCC_16=12,
	COATL_UCD_CCC_CCC16=COATL_UCD_CCC_16,
    COATL_UCD_CCC_17=13,
	COATL_UCD_CCC_CCC17=COATL_UCD_CCC_17,
    COATL_UCD_CCC_18=14,
	COATL_UCD_CCC_CCC18=COATL_UCD_CCC_18,
    COATL_UCD_CCC_19=15,
	COATL_UCD_CCC_CCC19=COATL_UCD_CCC_19,
    COATL_UCD_CCC_20=16,
	COATL_UCD_CCC_CCC20=COATL_UCD_CCC_20,
    COATL_UCD_CCC_21=17,
	COATL_UCD_CCC_CCC21=COATL_UCD_CCC_21,
    COATL_UCD_CCC_22=18,
	COATL_UCD_CCC_CCC22=COATL_UCD_CCC_22,
    COATL_UCD_CCC_23=19,
	COATL_UCD_CCC_CCC23=COATL_UCD_CCC_23,
    COATL_UCD_CCC_24=20,
	COATL_UCD_CCC_CCC24=COATL_UCD_CCC_24,
    COATL_UCD_CCC_25=21,
	COATL_UCD_CCC_CCC25=COATL_UCD_CCC_25,
    COATL_UCD_CCC_26=22,
	COATL_UCD_CCC_CCC26=COATL_UCD_CCC_26,
    COATL_UCD_CCC_27=23,
	COATL_UCD_CCC_CCC27=COATL_UCD_CCC_27,
    COATL_UCD_CCC_28=24,
	COATL_UCD_CCC_CCC28=COATL_UCD_CCC_28,
    COATL_UCD_CCC_29=25,
	COATL_UCD_CCC_CCC29=COATL_UCD_CCC_29,
    COATL_UCD_CCC_30=26,
	COATL_UCD_CCC_CCC30=COATL_UCD_CCC_30,
    COATL_UCD_CCC_31=27,
	COATL_UCD_CCC_CCC31=COATL_UCD_CCC_31,
    COATL_UCD_CCC_32=28,
	COATL_UCD_CCC_CCC32=COATL_UCD_CCC_32,
    COATL_UCD_CCC_33=29,
	COATL_UCD_CCC_CCC33=COATL_UCD_CCC_33,
    COATL_UCD_CCC_34=30,
	COATL_UCD_CCC_CCC34=COATL_UCD_CCC_34,
    COATL_UCD_CCC_35=31,
	COATL_UCD_CCC_CCC35=COATL_UCD_CCC_35,
    COATL_UCD_CCC_36=32,
	COATL_UCD_CCC_CCC36=COATL_UCD_CCC_36,
    COATL_UCD_CCC_84=33,
	COATL_UCD_CCC_CCC84=COATL_UCD_CCC_84,
    COATL_UCD_CCC_91=34,
	COATL_UCD_CCC_CCC91=COATL_UCD_CCC_91,
    COATL_UCD_CCC_103=35,
	COATL_UCD_CCC_CCC103=COATL_UCD_CCC_103,
    COATL_UCD_CCC_107=36,
	COATL_UCD_CCC_CCC107=COATL_UCD_CCC_107,
    COATL_UCD_CCC_118=37,
	COATL_UCD_CCC_CCC118=COATL_UCD_CCC_118,
    COATL_UCD_CCC_122=38,
	COATL_UCD_CCC_CCC122=COATL_UCD_CCC_122,
    COATL_UCD_CCC_129=39,
	COATL_UCD_CCC_CCC129=COATL_UCD_CCC_129,
    COATL_UCD_CCC_130=40,
	COATL_UCD_CCC_CCC130=COATL_UCD_CCC_130,
    COATL_UCD_CCC_132=41,
	COATL_UCD_CCC_CCC133=COATL_UCD_CCC_132,
    COATL_UCD_CCC_200=42,
	COATL_UCD_CCC_ATBL=COATL_UCD_CCC_200,
	COATL_UCD_CCC_ATTACHED_BELOW_LEFT=COATL_UCD_CCC_200,
    COATL_UCD_CCC_202=43,
	COATL_UCD_CCC_ATB=COATL_UCD_CCC_202,
	COATL_UCD_CCC_ATTACHED_BELOW=COATL_UCD_CCC_202,
    COATL_UCD_CCC_214=44,
	COATL_UCD_CCC_ATA=COATL_UCD_CCC_214,
	COATL_UCD_CCC_ATTACHED_ABOVE=COATL_UCD_CCC_214,
    COATL_UCD_CCC_216=45,
	COATL_UCD_CCC_ATAR=COATL_UCD_CCC_216,
	COATL_UCD_CCC_ATTACHED_ABOVE_RIGHT=COATL_UCD_CCC_216,
    COATL_UCD_CCC_218=46,
	COATL_UCD_CCC_BL=COATL_UCD_CCC_218,
	COATL_UCD_CCC_BELOW_LEFT=COATL_UCD_CCC_218,
    COATL_UCD_CCC_220=47,
	COATL_UCD_CCC_B=COATL_UCD_CCC_220,
	COATL_UCD_CCC_BELOW=COATL_UCD_CCC_220,
    COATL_UCD_CCC_222=48,
	COATL_UCD_CCC_BR=COATL_UCD_CCC_222,
	COATL_UCD_CCC_BELOW_RIGHT=COATL_UCD_CCC_222,
    COATL_UCD_CCC_224=49,
	COATL_UCD_CCC_L=COATL_UCD_CCC_224,
	COATL_UCD_CCC_LEFT=COATL_UCD_CCC_224,
    COATL_UCD_CCC_226=50,
	COATL_UCD_CCC_R=COATL_UCD_CCC_226,
	COATL_UCD_CCC_RIGHT=COATL_UCD_CCC_226,
    COATL_UCD_CCC_228=51,
	COATL_UCD_CCC_AL=COATL_UCD_CCC_228,
	COATL_UCD_CCC_ABOVE_LEFT=COATL_UCD_CCC_228,
    COATL_UCD_CCC_230=52,
	COATL_UCD_CCC_A=COATL_UCD_CCC_230,
	COATL_UCD_CCC_ABOVE=COATL_UCD_CCC_230,
    COATL_UCD_CCC_232=53,
	COATL_UCD_CCC_AR=COATL_UCD_CCC_232,
	COATL_UCD_CCC_ABOVE_RIGHT=COATL_UCD_CCC_232,
    COATL_UCD_CCC_233=54,
	COATL_UCD_CCC_DB=COATL_UCD_CCC_233,
	COATL_UCD_CCC_DOUBLE_BELOW=COATL_UCD_CCC_233,
    COATL_UCD_CCC_234=55,
	COATL_UCD_CCC_DA=COATL_UCD_CCC_234,
	COATL_UCD_CCC_DOUBLE_ABOVE=COATL_UCD_CCC_234,
    COATL_UCD_CCC_240=56,
	COATL_UCD_CCC_IS=COATL_UCD_CCC_240,
	COATL_UCD_CCC_IOTA_SUBSCRIPT=COATL_UCD_CCC_240,

} Coatl_Ucd_Ccc;

/*---------------------------------------------------------------------------
 * Constant: COATL_UCD_CCC_NBVALUES
 *
 *	Number of values for Unicode character property '*ccc*'.
 *
 * See also:
 *	<Coatl_Ucd_Ccc>
 *---------------------------------------------------------------------------*/

#define COATL_UCD_CCC_NBVALUES	56

/*---------------------------------------------------------------------------
 * Enum: Coatl_Ucd_Dt
 *
 *	Values for Unicode character property '*dt*'.
 *
 *	Names are automatically generated from the UCD file
 *	*PropertyValueAliases.txt*
 *
 *  COATL_UCD_DT_CAN - '*Can*', '*Canonical*', '*can*'
 *  COATL_UCD_DT_CANONICAL - Alias for <COATL_UCD_DT_CAN>
 *  COATL_UCD_DT_COM - '*Com*', '*Compat*', '*com*'
 *  COATL_UCD_DT_COMPAT - Alias for <COATL_UCD_DT_COM>
 *  COATL_UCD_DT_ENC - '*Enc*', '*Circle*', '*enc*'
 *  COATL_UCD_DT_CIRCLE - Alias for <COATL_UCD_DT_ENC>
 *  COATL_UCD_DT_FIN - '*Fin*', '*Final*', '*fin*'
 *  COATL_UCD_DT_FINAL - Alias for <COATL_UCD_DT_FIN>
 *  COATL_UCD_DT_FONT - '*Font*', '*font*'
 *  COATL_UCD_DT_FRA - '*Fra*', '*Fraction*', '*fra*'
 *  COATL_UCD_DT_FRACTION - Alias for <COATL_UCD_DT_FRA>
 *  COATL_UCD_DT_INIT - '*Init*', '*Initial*', '*init*'
 *  COATL_UCD_DT_INITIAL - Alias for <COATL_UCD_DT_INIT>
 *  COATL_UCD_DT_ISO - '*Iso*', '*Isolated*', '*iso*'
 *  COATL_UCD_DT_ISOLATED - Alias for <COATL_UCD_DT_ISO>
 *  COATL_UCD_DT_MED - '*Med*', '*Medial*', '*med*'
 *  COATL_UCD_DT_MEDIAL - Alias for <COATL_UCD_DT_MED>
 *  COATL_UCD_DT_NAR - '*Nar*', '*Narrow*', '*nar*'
 *  COATL_UCD_DT_NARROW - Alias for <COATL_UCD_DT_NAR>
 *  COATL_UCD_DT_NB - '*Nb*', '*Nobreak*', '*nb*'
 *  COATL_UCD_DT_NOBREAK - Alias for <COATL_UCD_DT_NB>
 *  COATL_UCD_DT_NONE - '*None*', '*none*'
 *  COATL_UCD_DT_SML - '*Sml*', '*Small*', '*sml*'
 *  COATL_UCD_DT_SMALL - Alias for <COATL_UCD_DT_SML>
 *  COATL_UCD_DT_SQR - '*Sqr*', '*Square*', '*sqr*'
 *  COATL_UCD_DT_SQUARE - Alias for <COATL_UCD_DT_SQR>
 *  COATL_UCD_DT_SUB - '*Sub*', '*sub*'
 *  COATL_UCD_DT_SUP - '*Sup*', '*Super*', '*sup*'
 *  COATL_UCD_DT_SUPER - Alias for <COATL_UCD_DT_SUP>
 *  COATL_UCD_DT_VERT - '*Vert*', '*Vertical*', '*vert*'
 *  COATL_UCD_DT_VERTICAL - Alias for <COATL_UCD_DT_VERT>
 *  COATL_UCD_DT_WIDE - '*Wide*', '*wide*'
 *
 * See also:
 *	<COATL_UCD_DT>
 *---------------------------------------------------------------------------*/

typedef enum Coatl_Ucd_Dt {
    COATL_UCD_DT_CAN=1,
	COATL_UCD_DT_CANONICAL=COATL_UCD_DT_CAN,
    COATL_UCD_DT_COM=2,
	COATL_UCD_DT_COMPAT=COATL_UCD_DT_COM,
    COATL_UCD_DT_ENC=3,
	COATL_UCD_DT_CIRCLE=COATL_UCD_DT_ENC,
    COATL_UCD_DT_FIN=4,
	COATL_UCD_DT_FINAL=COATL_UCD_DT_FIN,
    COATL_UCD_DT_FONT=5,
    COATL_UCD_DT_FRA=6,
	COATL_UCD_DT_FRACTION=COATL_UCD_DT_FRA,
    COATL_UCD_DT_INIT=7,
	COATL_UCD_DT_INITIAL=COATL_UCD_DT_INIT,
    COATL_UCD_DT_ISO=8,
	COATL_UCD_DT_ISOLATED=COATL_UCD_DT_ISO,
    COATL_UCD_DT_MED=9,
	COATL_UCD_DT_MEDIAL=COATL_UCD_DT_MED,
    COATL_UCD_DT_NAR=10,
	COATL_UCD_DT_NARROW=COATL_UCD_DT_NAR,
    COATL_UCD_DT_NB=11,
	COATL_UCD_DT_NOBREAK=COATL_UCD_DT_NB,
    COATL_UCD_DT_NONE=12,
    COATL_UCD_DT_SML=13,
	COATL_UCD_DT_SMALL=COATL_UCD_DT_SML,
    COATL_UCD_DT_SQR=14,
	COATL_UCD_DT_SQUARE=COATL_UCD_DT_SQR,
    COATL_UCD_DT_SUB=15,
    COATL_UCD_DT_SUP=16,
	COATL_UCD_DT_SUPER=COATL_UCD_DT_SUP,
    COATL_UCD_DT_VERT=17,
	COATL_UCD_DT_VERTICAL=COATL_UCD_DT_VERT,
    COATL_UCD_DT_WIDE=18,

} Coatl_Ucd_Dt;

/*---------------------------------------------------------------------------
 * Constant: COATL_UCD_DT_NBVALUES
 *
 *	Number of values for Unicode character property '*dt*'.
 *
 * See also:
 *	<Coatl_Ucd_Dt>
 *---------------------------------------------------------------------------*/

#define COATL_UCD_DT_NBVALUES	18

/*---------------------------------------------------------------------------
 * Enum: Coatl_Ucd_Ea
 *
 *	Values for Unicode character property '*ea*'.
 *
 *	Names are automatically generated from the UCD file
 *	*PropertyValueAliases.txt*
 *
 *  COATL_UCD_EA_A - '*A*', '*Ambiguous*'
 *  COATL_UCD_EA_AMBIGUOUS - Alias for <COATL_UCD_EA_A>
 *  COATL_UCD_EA_F - '*F*', '*Fullwidth*'
 *  COATL_UCD_EA_FULLWIDTH - Alias for <COATL_UCD_EA_F>
 *  COATL_UCD_EA_H - '*H*', '*Halfwidth*'
 *  COATL_UCD_EA_HALFWIDTH - Alias for <COATL_UCD_EA_H>
 *  COATL_UCD_EA_N - '*N*', '*Neutral*'
 *  COATL_UCD_EA_NEUTRAL - Alias for <COATL_UCD_EA_N>
 *  COATL_UCD_EA_NA - '*Na*', '*Narrow*'
 *  COATL_UCD_EA_NARROW - Alias for <COATL_UCD_EA_NA>
 *  COATL_UCD_EA_W - '*W*', '*Wide*'
 *  COATL_UCD_EA_WIDE - Alias for <COATL_UCD_EA_W>
 *
 * See also:
 *	<COATL_UCD_EA>
 *---------------------------------------------------------------------------*/

typedef enum Coatl_Ucd_Ea {
    COATL_UCD_EA_A=1,
	COATL_UCD_EA_AMBIGUOUS=COATL_UCD_EA_A,
    COATL_UCD_EA_F=2,
	COATL_UCD_EA_FULLWIDTH=COATL_UCD_EA_F,
    COATL_UCD_EA_H=3,
	COATL_UCD_EA_HALFWIDTH=COATL_UCD_EA_H,
    COATL_UCD_EA_N=4,
	COATL_UCD_EA_NEUTRAL=COATL_UCD_EA_N,
    COATL_UCD_EA_NA=5,
	COATL_UCD_EA_NARROW=COATL_UCD_EA_NA,
    COATL_UCD_EA_W=6,
	COATL_UCD_EA_WIDE=COATL_UCD_EA_W,

} Coatl_Ucd_Ea;

/*---------------------------------------------------------------------------
 * Constant: COATL_UCD_EA_NBVALUES
 *
 *	Number of values for Unicode character property '*ea*'.
 *
 * See also:
 *	<Coatl_Ucd_Ea>
 *---------------------------------------------------------------------------*/

#define COATL_UCD_EA_NBVALUES	6

/*---------------------------------------------------------------------------
 * Enum: Coatl_Ucd_Gc
 *
 *	Values for Unicode character property '*gc*'.
 *
 *	Names are automatically generated from the UCD file
 *	*PropertyValueAliases.txt*
 *
 *  COATL_UCD_GC_CC - '*Cc*', '*Control*', '*cntrl*'
 *  COATL_UCD_GC_CONTROL - Alias for <COATL_UCD_GC_CC>
 *  COATL_UCD_GC_CNTRL - Alias for <COATL_UCD_GC_CC>
 *  COATL_UCD_GC_CF - '*Cf*', '*Format*'
 *  COATL_UCD_GC_FORMAT - Alias for <COATL_UCD_GC_CF>
 *  COATL_UCD_GC_CN - '*Cn*', '*Unassigned*'
 *  COATL_UCD_GC_UNASSIGNED - Alias for <COATL_UCD_GC_CN>
 *  COATL_UCD_GC_CO - '*Co*', '*Private_Use*'
 *  COATL_UCD_GC_PRIVATE_USE - Alias for <COATL_UCD_GC_CO>
 *  COATL_UCD_GC_CS - '*Cs*', '*Surrogate*'
 *  COATL_UCD_GC_SURROGATE - Alias for <COATL_UCD_GC_CS>
 *  COATL_UCD_GC_LL - '*Ll*', '*Lowercase_Letter*'
 *  COATL_UCD_GC_LOWERCASE_LETTER - Alias for <COATL_UCD_GC_LL>
 *  COATL_UCD_GC_LM - '*Lm*', '*Modifier_Letter*'
 *  COATL_UCD_GC_MODIFIER_LETTER - Alias for <COATL_UCD_GC_LM>
 *  COATL_UCD_GC_LO - '*Lo*', '*Other_Letter*'
 *  COATL_UCD_GC_OTHER_LETTER - Alias for <COATL_UCD_GC_LO>
 *  COATL_UCD_GC_LT - '*Lt*', '*Titlecase_Letter*'
 *  COATL_UCD_GC_TITLECASE_LETTER - Alias for <COATL_UCD_GC_LT>
 *  COATL_UCD_GC_LU - '*Lu*', '*Uppercase_Letter*'
 *  COATL_UCD_GC_UPPERCASE_LETTER - Alias for <COATL_UCD_GC_LU>
 *  COATL_UCD_GC_MC - '*Mc*', '*Spacing_Mark*'
 *  COATL_UCD_GC_SPACING_MARK - Alias for <COATL_UCD_GC_MC>
 *  COATL_UCD_GC_ME - '*Me*', '*Enclosing_Mark*'
 *  COATL_UCD_GC_ENCLOSING_MARK - Alias for <COATL_UCD_GC_ME>
 *  COATL_UCD_GC_MN - '*Mn*', '*Nonspacing_Mark*'
 *  COATL_UCD_GC_NONSPACING_MARK - Alias for <COATL_UCD_GC_MN>
 *  COATL_UCD_GC_ND - '*Nd*', '*Decimal_Number*', '*digit*'
 *  COATL_UCD_GC_DECIMAL_NUMBER - Alias for <COATL_UCD_GC_ND>
 *  COATL_UCD_GC_DIGIT - Alias for <COATL_UCD_GC_ND>
 *  COATL_UCD_GC_NL - '*Nl*', '*Letter_Number*'
 *  COATL_UCD_GC_LETTER_NUMBER - Alias for <COATL_UCD_GC_NL>
 *  COATL_UCD_GC_NO - '*No*', '*Other_Number*'
 *  COATL_UCD_GC_OTHER_NUMBER - Alias for <COATL_UCD_GC_NO>
 *  COATL_UCD_GC_PC - '*Pc*', '*Connector_Punctuation*'
 *  COATL_UCD_GC_CONNECTOR_PUNCTUATION - Alias for <COATL_UCD_GC_PC>
 *  COATL_UCD_GC_PD - '*Pd*', '*Dash_Punctuation*'
 *  COATL_UCD_GC_DASH_PUNCTUATION - Alias for <COATL_UCD_GC_PD>
 *  COATL_UCD_GC_PE - '*Pe*', '*Close_Punctuation*'
 *  COATL_UCD_GC_CLOSE_PUNCTUATION - Alias for <COATL_UCD_GC_PE>
 *  COATL_UCD_GC_PF - '*Pf*', '*Final_Punctuation*'
 *  COATL_UCD_GC_FINAL_PUNCTUATION - Alias for <COATL_UCD_GC_PF>
 *  COATL_UCD_GC_PI - '*Pi*', '*Initial_Punctuation*'
 *  COATL_UCD_GC_INITIAL_PUNCTUATION - Alias for <COATL_UCD_GC_PI>
 *  COATL_UCD_GC_PO - '*Po*', '*Other_Punctuation*'
 *  COATL_UCD_GC_OTHER_PUNCTUATION - Alias for <COATL_UCD_GC_PO>
 *  COATL_UCD_GC_PS - '*Ps*', '*Open_Punctuation*'
 *  COATL_UCD_GC_OPEN_PUNCTUATION - Alias for <COATL_UCD_GC_PS>
 *  COATL_UCD_GC_SC - '*Sc*', '*Currency_Symbol*'
 *  COATL_UCD_GC_CURRENCY_SYMBOL - Alias for <COATL_UCD_GC_SC>
 *  COATL_UCD_GC_SK - '*Sk*', '*Modifier_Symbol*'
 *  COATL_UCD_GC_MODIFIER_SYMBOL - Alias for <COATL_UCD_GC_SK>
 *  COATL_UCD_GC_SM - '*Sm*', '*Math_Symbol*'
 *  COATL_UCD_GC_MATH_SYMBOL - Alias for <COATL_UCD_GC_SM>
 *  COATL_UCD_GC_SO - '*So*', '*Other_Symbol*'
 *  COATL_UCD_GC_OTHER_SYMBOL - Alias for <COATL_UCD_GC_SO>
 *  COATL_UCD_GC_ZL - '*Zl*', '*Line_Separator*'
 *  COATL_UCD_GC_LINE_SEPARATOR - Alias for <COATL_UCD_GC_ZL>
 *  COATL_UCD_GC_ZP - '*Zp*', '*Paragraph_Separator*'
 *  COATL_UCD_GC_PARAGRAPH_SEPARATOR - Alias for <COATL_UCD_GC_ZP>
 *  COATL_UCD_GC_ZS - '*Zs*', '*Space_Separator*'
 *  COATL_UCD_GC_SPACE_SEPARATOR - Alias for <COATL_UCD_GC_ZS>
 *
 * See also:
 *	<COATL_UCD_GC>
 *---------------------------------------------------------------------------*/

typedef enum Coatl_Ucd_Gc {
    COATL_UCD_GC_CC=1,
	COATL_UCD_GC_CONTROL=COATL_UCD_GC_CC,
	COATL_UCD_GC_CNTRL=COATL_UCD_GC_CC,
    COATL_UCD_GC_CF=2,
	COATL_UCD_GC_FORMAT=COATL_UCD_GC_CF,
    COATL_UCD_GC_CN=3,
	COATL_UCD_GC_UNASSIGNED=COATL_UCD_GC_CN,
    COATL_UCD_GC_CO=4,
	COATL_UCD_GC_PRIVATE_USE=COATL_UCD_GC_CO,
    COATL_UCD_GC_CS=5,
	COATL_UCD_GC_SURROGATE=COATL_UCD_GC_CS,
    COATL_UCD_GC_LL=6,
	COATL_UCD_GC_LOWERCASE_LETTER=COATL_UCD_GC_LL,
    COATL_UCD_GC_LM=7,
	COATL_UCD_GC_MODIFIER_LETTER=COATL_UCD_GC_LM,
    COATL_UCD_GC_LO=8,
	COATL_UCD_GC_OTHER_LETTER=COATL_UCD_GC_LO,
    COATL_UCD_GC_LT=9,
	COATL_UCD_GC_TITLECASE_LETTER=COATL_UCD_GC_LT,
    COATL_UCD_GC_LU=10,
	COATL_UCD_GC_UPPERCASE_LETTER=COATL_UCD_GC_LU,
    COATL_UCD_GC_MC=11,
	COATL_UCD_GC_SPACING_MARK=COATL_UCD_GC_MC,
    COATL_UCD_GC_ME=12,
	COATL_UCD_GC_ENCLOSING_MARK=COATL_UCD_GC_ME,
    COATL_UCD_GC_MN=13,
	COATL_UCD_GC_NONSPACING_MARK=COATL_UCD_GC_MN,
    COATL_UCD_GC_ND=14,
	COATL_UCD_GC_DECIMAL_NUMBER=COATL_UCD_GC_ND,
	COATL_UCD_GC_DIGIT=COATL_UCD_GC_ND,
    COATL_UCD_GC_NL=15,
	COATL_UCD_GC_LETTER_NUMBER=COATL_UCD_GC_NL,
    COATL_UCD_GC_NO=16,
	COATL_UCD_GC_OTHER_NUMBER=COATL_UCD_GC_NO,
    COATL_UCD_GC_PC=17,
	COATL_UCD_GC_CONNECTOR_PUNCTUATION=COATL_UCD_GC_PC,
    COATL_UCD_GC_PD=18,
	COATL_UCD_GC_DASH_PUNCTUATION=COATL_UCD_GC_PD,
    COATL_UCD_GC_PE=19,
	COATL_UCD_GC_CLOSE_PUNCTUATION=COATL_UCD_GC_PE,
    COATL_UCD_GC_PF=20,
	COATL_UCD_GC_FINAL_PUNCTUATION=COATL_UCD_GC_PF,
    COATL_UCD_GC_PI=21,
	COATL_UCD_GC_INITIAL_PUNCTUATION=COATL_UCD_GC_PI,
    COATL_UCD_GC_PO=22,
	COATL_UCD_GC_OTHER_PUNCTUATION=COATL_UCD_GC_PO,
    COATL_UCD_GC_PS=23,
	COATL_UCD_GC_OPEN_PUNCTUATION=COATL_UCD_GC_PS,
    COATL_UCD_GC_SC=24,
	COATL_UCD_GC_CURRENCY_SYMBOL=COATL_UCD_GC_SC,
    COATL_UCD_GC_SK=25,
	COATL_UCD_GC_MODIFIER_SYMBOL=COATL_UCD_GC_SK,
    COATL_UCD_GC_SM=26,
	COATL_UCD_GC_MATH_SYMBOL=COATL_UCD_GC_SM,
    COATL_UCD_GC_SO=27,
	COATL_UCD_GC_OTHER_SYMBOL=COATL_UCD_GC_SO,
    COATL_UCD_GC_ZL=28,
	COATL_UCD_GC_LINE_SEPARATOR=COATL_UCD_GC_ZL,
    COATL_UCD_GC_ZP=29,
	COATL_UCD_GC_PARAGRAPH_SEPARATOR=COATL_UCD_GC_ZP,
    COATL_UCD_GC_ZS=30,
	COATL_UCD_GC_SPACE_SEPARATOR=COATL_UCD_GC_ZS,

} Coatl_Ucd_Gc;

/*---------------------------------------------------------------------------
 * Constant: COATL_UCD_GC_NBVALUES
 *
 *	Number of values for Unicode character property '*gc*'.
 *
 * See also:
 *	<Coatl_Ucd_Gc>
 *---------------------------------------------------------------------------*/

#define COATL_UCD_GC_NBVALUES	30

/*---------------------------------------------------------------------------
 * Enum: Coatl_Ucd_GCB
 *
 *	Values for Unicode character property '*GCB*'.
 *
 *	Names are automatically generated from the UCD file
 *	*PropertyValueAliases.txt*
 *
 *  COATL_UCD_GCB_CN - '*CN*', '*Control*'
 *  COATL_UCD_GCB_CONTROL - Alias for <COATL_UCD_GCB_CN>
 *  COATL_UCD_GCB_CR - '*CR*'
 *  COATL_UCD_GCB_EX - '*EX*', '*Extend*'
 *  COATL_UCD_GCB_EXTEND - Alias for <COATL_UCD_GCB_EX>
 *  COATL_UCD_GCB_L - '*L*'
 *  COATL_UCD_GCB_LF - '*LF*'
 *  COATL_UCD_GCB_LV - '*LV*'
 *  COATL_UCD_GCB_LVT - '*LVT*'
 *  COATL_UCD_GCB_PP - '*PP*', '*Prepend*'
 *  COATL_UCD_GCB_PREPEND - Alias for <COATL_UCD_GCB_PP>
 *  COATL_UCD_GCB_SM - '*SM*', '*SpacingMark*'
 *  COATL_UCD_GCB_SPACINGMARK - Alias for <COATL_UCD_GCB_SM>
 *  COATL_UCD_GCB_T - '*T*'
 *  COATL_UCD_GCB_V - '*V*'
 *  COATL_UCD_GCB_XX - '*XX*', '*Other*'
 *  COATL_UCD_GCB_OTHER - Alias for <COATL_UCD_GCB_XX>
 *
 * See also:
 *	<COATL_UCD_GCB>
 *---------------------------------------------------------------------------*/

typedef enum Coatl_Ucd_GCB {
    COATL_UCD_GCB_CN=1,
	COATL_UCD_GCB_CONTROL=COATL_UCD_GCB_CN,
    COATL_UCD_GCB_CR=2,
    COATL_UCD_GCB_EX=3,
	COATL_UCD_GCB_EXTEND=COATL_UCD_GCB_EX,
    COATL_UCD_GCB_L=4,
    COATL_UCD_GCB_LF=5,
    COATL_UCD_GCB_LV=6,
    COATL_UCD_GCB_LVT=7,
    COATL_UCD_GCB_PP=8,
	COATL_UCD_GCB_PREPEND=COATL_UCD_GCB_PP,
    COATL_UCD_GCB_SM=9,
	COATL_UCD_GCB_SPACINGMARK=COATL_UCD_GCB_SM,
    COATL_UCD_GCB_T=10,
    COATL_UCD_GCB_V=11,
    COATL_UCD_GCB_XX=12,
	COATL_UCD_GCB_OTHER=COATL_UCD_GCB_XX,

} Coatl_Ucd_GCB;

/*---------------------------------------------------------------------------
 * Constant: COATL_UCD_GCB_NBVALUES
 *
 *	Number of values for Unicode character property '*GCB*'.
 *
 * See also:
 *	<Coatl_Ucd_GCB>
 *---------------------------------------------------------------------------*/

#define COATL_UCD_GCB_NBVALUES	12

/*---------------------------------------------------------------------------
 * Enum: Coatl_Ucd_Hst
 *
 *	Values for Unicode character property '*hst*'.
 *
 *	Names are automatically generated from the UCD file
 *	*PropertyValueAliases.txt*
 *
 *  COATL_UCD_HST_L - '*L*', '*Leading_Jamo*'
 *  COATL_UCD_HST_LEADING_JAMO - Alias for <COATL_UCD_HST_L>
 *  COATL_UCD_HST_LV - '*LV*', '*LV_Syllable*'
 *  COATL_UCD_HST_LV_SYLLABLE - Alias for <COATL_UCD_HST_LV>
 *  COATL_UCD_HST_LVT - '*LVT*', '*LVT_Syllable*'
 *  COATL_UCD_HST_LVT_SYLLABLE - Alias for <COATL_UCD_HST_LVT>
 *  COATL_UCD_HST_NA - '*NA*', '*Not_Applicable*'
 *  COATL_UCD_HST_NOT_APPLICABLE - Alias for <COATL_UCD_HST_NA>
 *  COATL_UCD_HST_T - '*T*', '*Trailing_Jamo*'
 *  COATL_UCD_HST_TRAILING_JAMO - Alias for <COATL_UCD_HST_T>
 *  COATL_UCD_HST_V - '*V*', '*Vowel_Jamo*'
 *  COATL_UCD_HST_VOWEL_JAMO - Alias for <COATL_UCD_HST_V>
 *
 * See also:
 *	<COATL_UCD_HST>
 *---------------------------------------------------------------------------*/

typedef enum Coatl_Ucd_Hst {
    COATL_UCD_HST_L=1,
	COATL_UCD_HST_LEADING_JAMO=COATL_UCD_HST_L,
    COATL_UCD_HST_LV=2,
	COATL_UCD_HST_LV_SYLLABLE=COATL_UCD_HST_LV,
    COATL_UCD_HST_LVT=3,
	COATL_UCD_HST_LVT_SYLLABLE=COATL_UCD_HST_LVT,
    COATL_UCD_HST_NA=4,
	COATL_UCD_HST_NOT_APPLICABLE=COATL_UCD_HST_NA,
    COATL_UCD_HST_T=5,
	COATL_UCD_HST_TRAILING_JAMO=COATL_UCD_HST_T,
    COATL_UCD_HST_V=6,
	COATL_UCD_HST_VOWEL_JAMO=COATL_UCD_HST_V,

} Coatl_Ucd_Hst;

/*---------------------------------------------------------------------------
 * Constant: COATL_UCD_HST_NBVALUES
 *
 *	Number of values for Unicode character property '*hst*'.
 *
 * See also:
 *	<Coatl_Ucd_Hst>
 *---------------------------------------------------------------------------*/

#define COATL_UCD_HST_NBVALUES	6

/*---------------------------------------------------------------------------
 * Enum: Coatl_Ucd_InMC
 *
 *	Values for Unicode character property '*InMC*'.
 *
 *	Names are automatically generated from the UCD file
 *	*PropertyValueAliases.txt*
 *
 *  COATL_UCD_INMC_BOTTOM - '*Bottom*'
 *  COATL_UCD_INMC_BOTTOM_AND_RIGHT - '*Bottom_And_Right*'
 *  COATL_UCD_INMC_INVISIBLE - '*Invisible*'
 *  COATL_UCD_INMC_LEFT - '*Left*'
 *  COATL_UCD_INMC_LEFT_AND_RIGHT - '*Left_And_Right*'
 *  COATL_UCD_INMC_NA - '*NA*'
 *  COATL_UCD_INMC_OVERSTRUCK - '*Overstruck*'
 *  COATL_UCD_INMC_RIGHT - '*Right*'
 *  COATL_UCD_INMC_TOP - '*Top*'
 *  COATL_UCD_INMC_TOP_AND_BOTTOM - '*Top_And_Bottom*'
 *  COATL_UCD_INMC_TOP_AND_BOTTOM_AND_RIGHT - '*Top_And_Bottom_And_Right*'
 *  COATL_UCD_INMC_TOP_AND_LEFT - '*Top_And_Left*'
 *  COATL_UCD_INMC_TOP_AND_LEFT_AND_RIGHT - '*Top_And_Left_And_Right*'
 *  COATL_UCD_INMC_TOP_AND_RIGHT - '*Top_And_Right*'
 *  COATL_UCD_INMC_VISUAL_ORDER_LEFT - '*Visual_Order_Left*'
 *
 * See also:
 *	<COATL_UCD_INMC>
 *---------------------------------------------------------------------------*/

typedef enum Coatl_Ucd_InMC {
    COATL_UCD_INMC_BOTTOM=1,
    COATL_UCD_INMC_BOTTOM_AND_RIGHT=2,
    COATL_UCD_INMC_INVISIBLE=3,
    COATL_UCD_INMC_LEFT=4,
    COATL_UCD_INMC_LEFT_AND_RIGHT=5,
    COATL_UCD_INMC_NA=6,
    COATL_UCD_INMC_OVERSTRUCK=7,
    COATL_UCD_INMC_RIGHT=8,
    COATL_UCD_INMC_TOP=9,
    COATL_UCD_INMC_TOP_AND_BOTTOM=10,
    COATL_UCD_INMC_TOP_AND_BOTTOM_AND_RIGHT=11,
    COATL_UCD_INMC_TOP_AND_LEFT=12,
    COATL_UCD_INMC_TOP_AND_LEFT_AND_RIGHT=13,
    COATL_UCD_INMC_TOP_AND_RIGHT=14,
    COATL_UCD_INMC_VISUAL_ORDER_LEFT=15,

} Coatl_Ucd_InMC;

/*---------------------------------------------------------------------------
 * Constant: COATL_UCD_INMC_NBVALUES
 *
 *	Number of values for Unicode character property '*InMC*'.
 *
 * See also:
 *	<Coatl_Ucd_InMC>
 *---------------------------------------------------------------------------*/

#define COATL_UCD_INMC_NBVALUES	15

/*---------------------------------------------------------------------------
 * Enum: Coatl_Ucd_InSC
 *
 *	Values for Unicode character property '*InSC*'.
 *
 *	Names are automatically generated from the UCD file
 *	*PropertyValueAliases.txt*
 *
 *  COATL_UCD_INSC_AVAGRAHA - '*Avagraha*'
 *  COATL_UCD_INSC_BINDU - '*Bindu*'
 *  COATL_UCD_INSC_CONSONANT - '*Consonant*'
 *  COATL_UCD_INSC_CONSONANT_DEAD - '*Consonant_Dead*'
 *  COATL_UCD_INSC_CONSONANT_FINAL - '*Consonant_Final*'
 *  COATL_UCD_INSC_CONSONANT_HEAD_LETTER - '*Consonant_Head_Letter*'
 *  COATL_UCD_INSC_CONSONANT_MEDIAL - '*Consonant_Medial*'
 *  COATL_UCD_INSC_CONSONANT_PLACEHOLDER - '*Consonant_Placeholder*'
 *  COATL_UCD_INSC_CONSONANT_REPHA - '*Consonant_Repha*'
 *  COATL_UCD_INSC_CONSONANT_SUBJOINED - '*Consonant_Subjoined*'
 *  COATL_UCD_INSC_MODIFYING_LETTER - '*Modifying_Letter*'
 *  COATL_UCD_INSC_NUKTA - '*Nukta*'
 *  COATL_UCD_INSC_OTHER - '*Other*'
 *  COATL_UCD_INSC_REGISTER_SHIFTER - '*Register_Shifter*'
 *  COATL_UCD_INSC_TONE_LETTER - '*Tone_Letter*'
 *  COATL_UCD_INSC_TONE_MARK - '*Tone_Mark*'
 *  COATL_UCD_INSC_VIRAMA - '*Virama*'
 *  COATL_UCD_INSC_VISARGA - '*Visarga*'
 *  COATL_UCD_INSC_VOWEL - '*Vowel*'
 *  COATL_UCD_INSC_VOWEL_DEPENDENT - '*Vowel_Dependent*'
 *  COATL_UCD_INSC_VOWEL_INDEPENDENT - '*Vowel_Independent*'
 *
 * See also:
 *	<COATL_UCD_INSC>
 *---------------------------------------------------------------------------*/

typedef enum Coatl_Ucd_InSC {
    COATL_UCD_INSC_AVAGRAHA=1,
    COATL_UCD_INSC_BINDU=2,
    COATL_UCD_INSC_CONSONANT=3,
    COATL_UCD_INSC_CONSONANT_DEAD=4,
    COATL_UCD_INSC_CONSONANT_FINAL=5,
    COATL_UCD_INSC_CONSONANT_HEAD_LETTER=6,
    COATL_UCD_INSC_CONSONANT_MEDIAL=7,
    COATL_UCD_INSC_CONSONANT_PLACEHOLDER=8,
    COATL_UCD_INSC_CONSONANT_REPHA=9,
    COATL_UCD_INSC_CONSONANT_SUBJOINED=10,
    COATL_UCD_INSC_MODIFYING_LETTER=11,
    COATL_UCD_INSC_NUKTA=12,
    COATL_UCD_INSC_OTHER=13,
    COATL_UCD_INSC_REGISTER_SHIFTER=14,
    COATL_UCD_INSC_TONE_LETTER=15,
    COATL_UCD_INSC_TONE_MARK=16,
    COATL_UCD_INSC_VIRAMA=17,
    COATL_UCD_INSC_VISARGA=18,
    COATL_UCD_INSC_VOWEL=19,
    COATL_UCD_INSC_VOWEL_DEPENDENT=20,
    COATL_UCD_INSC_VOWEL_INDEPENDENT=21,

} Coatl_Ucd_InSC;

/*---------------------------------------------------------------------------
 * Constant: COATL_UCD_INSC_NBVALUES
 *
 *	Number of values for Unicode character property '*InSC*'.
 *
 * See also:
 *	<Coatl_Ucd_InSC>
 *---------------------------------------------------------------------------*/

#define COATL_UCD_INSC_NBVALUES	21

/*---------------------------------------------------------------------------
 * Enum: Coatl_Ucd_Jg
 *
 *	Values for Unicode character property '*jg*'.
 *
 *	Names are automatically generated from the UCD file
 *	*PropertyValueAliases.txt*
 *
 *  COATL_UCD_JG_AIN - '*Ain*'
 *  COATL_UCD_JG_ALAPH - '*Alaph*'
 *  COATL_UCD_JG_ALEF - '*Alef*'
 *  COATL_UCD_JG_BEH - '*Beh*'
 *  COATL_UCD_JG_BETH - '*Beth*'
 *  COATL_UCD_JG_BURUSHASKI_YEH_BARREE - '*Burushaski_Yeh_Barree*'
 *  COATL_UCD_JG_DAL - '*Dal*'
 *  COATL_UCD_JG_DALATH_RISH - '*Dalath_Rish*'
 *  COATL_UCD_JG_E - '*E*'
 *  COATL_UCD_JG_FARSI_YEH - '*Farsi_Yeh*'
 *  COATL_UCD_JG_FE - '*Fe*'
 *  COATL_UCD_JG_FEH - '*Feh*'
 *  COATL_UCD_JG_FINAL_SEMKATH - '*Final_Semkath*'
 *  COATL_UCD_JG_GAF - '*Gaf*'
 *  COATL_UCD_JG_GAMAL - '*Gamal*'
 *  COATL_UCD_JG_HAH - '*Hah*'
 *  COATL_UCD_JG_HE - '*He*'
 *  COATL_UCD_JG_HEH - '*Heh*'
 *  COATL_UCD_JG_HEH_GOAL - '*Heh_Goal*'
 *  COATL_UCD_JG_HETH - '*Heth*'
 *  COATL_UCD_JG_KAF - '*Kaf*'
 *  COATL_UCD_JG_KAPH - '*Kaph*'
 *  COATL_UCD_JG_KHAPH - '*Khaph*'
 *  COATL_UCD_JG_KNOTTED_HEH - '*Knotted_Heh*'
 *  COATL_UCD_JG_LAM - '*Lam*'
 *  COATL_UCD_JG_LAMADH - '*Lamadh*'
 *  COATL_UCD_JG_MEEM - '*Meem*'
 *  COATL_UCD_JG_MIM - '*Mim*'
 *  COATL_UCD_JG_NO_JOINING_GROUP - '*No_Joining_Group*'
 *  COATL_UCD_JG_NOON - '*Noon*'
 *  COATL_UCD_JG_NUN - '*Nun*'
 *  COATL_UCD_JG_NYA - '*Nya*'
 *  COATL_UCD_JG_PE - '*Pe*'
 *  COATL_UCD_JG_QAF - '*Qaf*'
 *  COATL_UCD_JG_QAPH - '*Qaph*'
 *  COATL_UCD_JG_REH - '*Reh*'
 *  COATL_UCD_JG_REVERSED_PE - '*Reversed_Pe*'
 *  COATL_UCD_JG_ROHINGYA_YEH - '*Rohingya_Yeh*'
 *  COATL_UCD_JG_SAD - '*Sad*'
 *  COATL_UCD_JG_SADHE - '*Sadhe*'
 *  COATL_UCD_JG_SEEN - '*Seen*'
 *  COATL_UCD_JG_SEMKATH - '*Semkath*'
 *  COATL_UCD_JG_SHIN - '*Shin*'
 *  COATL_UCD_JG_SWASH_KAF - '*Swash_Kaf*'
 *  COATL_UCD_JG_SYRIAC_WAW - '*Syriac_Waw*'
 *  COATL_UCD_JG_TAH - '*Tah*'
 *  COATL_UCD_JG_TAW - '*Taw*'
 *  COATL_UCD_JG_TEH_MARBUTA - '*Teh_Marbuta*'
 *  COATL_UCD_JG_TEH_MARBUTA_GOAL - '*Teh_Marbuta_Goal*', '*Hamza_On_Heh_Goal*'
 *  COATL_UCD_JG_HAMZA_ON_HEH_GOAL - Alias for <COATL_UCD_JG_TEH_MARBUTA_GOAL>
 *  COATL_UCD_JG_TETH - '*Teth*'
 *  COATL_UCD_JG_WAW - '*Waw*'
 *  COATL_UCD_JG_YEH - '*Yeh*'
 *  COATL_UCD_JG_YEH_BARREE - '*Yeh_Barree*'
 *  COATL_UCD_JG_YEH_WITH_TAIL - '*Yeh_With_Tail*'
 *  COATL_UCD_JG_YUDH - '*Yudh*'
 *  COATL_UCD_JG_YUDH_HE - '*Yudh_He*'
 *  COATL_UCD_JG_ZAIN - '*Zain*'
 *  COATL_UCD_JG_ZHAIN - '*Zhain*'
 *
 * See also:
 *	<COATL_UCD_JG>
 *---------------------------------------------------------------------------*/

typedef enum Coatl_Ucd_Jg {
    COATL_UCD_JG_AIN=1,
    COATL_UCD_JG_ALAPH=2,
    COATL_UCD_JG_ALEF=3,
    COATL_UCD_JG_BEH=4,
    COATL_UCD_JG_BETH=5,
    COATL_UCD_JG_BURUSHASKI_YEH_BARREE=6,
    COATL_UCD_JG_DAL=7,
    COATL_UCD_JG_DALATH_RISH=8,
    COATL_UCD_JG_E=9,
    COATL_UCD_JG_FARSI_YEH=10,
    COATL_UCD_JG_FE=11,
    COATL_UCD_JG_FEH=12,
    COATL_UCD_JG_FINAL_SEMKATH=13,
    COATL_UCD_JG_GAF=14,
    COATL_UCD_JG_GAMAL=15,
    COATL_UCD_JG_HAH=16,
    COATL_UCD_JG_HE=17,
    COATL_UCD_JG_HEH=18,
    COATL_UCD_JG_HEH_GOAL=19,
    COATL_UCD_JG_HETH=20,
    COATL_UCD_JG_KAF=21,
    COATL_UCD_JG_KAPH=22,
    COATL_UCD_JG_KHAPH=23,
    COATL_UCD_JG_KNOTTED_HEH=24,
    COATL_UCD_JG_LAM=25,
    COATL_UCD_JG_LAMADH=26,
    COATL_UCD_JG_MEEM=27,
    COATL_UCD_JG_MIM=28,
    COATL_UCD_JG_NO_JOINING_GROUP=29,
    COATL_UCD_JG_NOON=30,
    COATL_UCD_JG_NUN=31,
    COATL_UCD_JG_NYA=32,
    COATL_UCD_JG_PE=33,
    COATL_UCD_JG_QAF=34,
    COATL_UCD_JG_QAPH=35,
    COATL_UCD_JG_REH=36,
    COATL_UCD_JG_REVERSED_PE=37,
    COATL_UCD_JG_ROHINGYA_YEH=38,
    COATL_UCD_JG_SAD=39,
    COATL_UCD_JG_SADHE=40,
    COATL_UCD_JG_SEEN=41,
    COATL_UCD_JG_SEMKATH=42,
    COATL_UCD_JG_SHIN=43,
    COATL_UCD_JG_SWASH_KAF=44,
    COATL_UCD_JG_SYRIAC_WAW=45,
    COATL_UCD_JG_TAH=46,
    COATL_UCD_JG_TAW=47,
    COATL_UCD_JG_TEH_MARBUTA=48,
    COATL_UCD_JG_TEH_MARBUTA_GOAL=49,
	COATL_UCD_JG_HAMZA_ON_HEH_GOAL=COATL_UCD_JG_TEH_MARBUTA_GOAL,
    COATL_UCD_JG_TETH=50,
    COATL_UCD_JG_WAW=51,
    COATL_UCD_JG_YEH=52,
    COATL_UCD_JG_YEH_BARREE=53,
    COATL_UCD_JG_YEH_WITH_TAIL=54,
    COATL_UCD_JG_YUDH=55,
    COATL_UCD_JG_YUDH_HE=56,
    COATL_UCD_JG_ZAIN=57,
    COATL_UCD_JG_ZHAIN=58,

} Coatl_Ucd_Jg;

/*---------------------------------------------------------------------------
 * Constant: COATL_UCD_JG_NBVALUES
 *
 *	Number of values for Unicode character property '*jg*'.
 *
 * See also:
 *	<Coatl_Ucd_Jg>
 *---------------------------------------------------------------------------*/

#define COATL_UCD_JG_NBVALUES	58

/*---------------------------------------------------------------------------
 * Enum: Coatl_Ucd_Jt
 *
 *	Values for Unicode character property '*jt*'.
 *
 *	Names are automatically generated from the UCD file
 *	*PropertyValueAliases.txt*
 *
 *  COATL_UCD_JT_C - '*C*', '*Join_Causing*'
 *  COATL_UCD_JT_JOIN_CAUSING - Alias for <COATL_UCD_JT_C>
 *  COATL_UCD_JT_D - '*D*', '*Dual_Joining*'
 *  COATL_UCD_JT_DUAL_JOINING - Alias for <COATL_UCD_JT_D>
 *  COATL_UCD_JT_L - '*L*', '*Left_Joining*'
 *  COATL_UCD_JT_LEFT_JOINING - Alias for <COATL_UCD_JT_L>
 *  COATL_UCD_JT_R - '*R*', '*Right_Joining*'
 *  COATL_UCD_JT_RIGHT_JOINING - Alias for <COATL_UCD_JT_R>
 *  COATL_UCD_JT_T - '*T*', '*Transparent*'
 *  COATL_UCD_JT_TRANSPARENT - Alias for <COATL_UCD_JT_T>
 *  COATL_UCD_JT_U - '*U*', '*Non_Joining*'
 *  COATL_UCD_JT_NON_JOINING - Alias for <COATL_UCD_JT_U>
 *
 * See also:
 *	<COATL_UCD_JT>
 *---------------------------------------------------------------------------*/

typedef enum Coatl_Ucd_Jt {
    COATL_UCD_JT_C=1,
	COATL_UCD_JT_JOIN_CAUSING=COATL_UCD_JT_C,
    COATL_UCD_JT_D=2,
	COATL_UCD_JT_DUAL_JOINING=COATL_UCD_JT_D,
    COATL_UCD_JT_L=3,
	COATL_UCD_JT_LEFT_JOINING=COATL_UCD_JT_L,
    COATL_UCD_JT_R=4,
	COATL_UCD_JT_RIGHT_JOINING=COATL_UCD_JT_R,
    COATL_UCD_JT_T=5,
	COATL_UCD_JT_TRANSPARENT=COATL_UCD_JT_T,
    COATL_UCD_JT_U=6,
	COATL_UCD_JT_NON_JOINING=COATL_UCD_JT_U,

} Coatl_Ucd_Jt;

/*---------------------------------------------------------------------------
 * Constant: COATL_UCD_JT_NBVALUES
 *
 *	Number of values for Unicode character property '*jt*'.
 *
 * See also:
 *	<Coatl_Ucd_Jt>
 *---------------------------------------------------------------------------*/

#define COATL_UCD_JT_NBVALUES	6

/*---------------------------------------------------------------------------
 * Enum: Coatl_Ucd_Lb
 *
 *	Values for Unicode character property '*lb*'.
 *
 *	Names are automatically generated from the UCD file
 *	*PropertyValueAliases.txt*
 *
 *  COATL_UCD_LB_AI - '*AI*', '*Ambiguous*'
 *  COATL_UCD_LB_AMBIGUOUS - Alias for <COATL_UCD_LB_AI>
 *  COATL_UCD_LB_AL - '*AL*', '*Alphabetic*'
 *  COATL_UCD_LB_ALPHABETIC - Alias for <COATL_UCD_LB_AL>
 *  COATL_UCD_LB_B2 - '*B2*', '*Break_Both*'
 *  COATL_UCD_LB_BREAK_BOTH - Alias for <COATL_UCD_LB_B2>
 *  COATL_UCD_LB_BA - '*BA*', '*Break_After*'
 *  COATL_UCD_LB_BREAK_AFTER - Alias for <COATL_UCD_LB_BA>
 *  COATL_UCD_LB_BB - '*BB*', '*Break_Before*'
 *  COATL_UCD_LB_BREAK_BEFORE - Alias for <COATL_UCD_LB_BB>
 *  COATL_UCD_LB_BK - '*BK*', '*Mandatory_Break*'
 *  COATL_UCD_LB_MANDATORY_BREAK - Alias for <COATL_UCD_LB_BK>
 *  COATL_UCD_LB_CB - '*CB*', '*Contingent_Break*'
 *  COATL_UCD_LB_CONTINGENT_BREAK - Alias for <COATL_UCD_LB_CB>
 *  COATL_UCD_LB_CJ - '*CJ*', '*Conditional_Japanese_Starter*'
 *  COATL_UCD_LB_CONDITIONAL_JAPANESE_STARTER - Alias for <COATL_UCD_LB_CJ>
 *  COATL_UCD_LB_CL - '*CL*', '*Close_Punctuation*'
 *  COATL_UCD_LB_CLOSE_PUNCTUATION - Alias for <COATL_UCD_LB_CL>
 *  COATL_UCD_LB_CM - '*CM*', '*Combining_Mark*'
 *  COATL_UCD_LB_COMBINING_MARK - Alias for <COATL_UCD_LB_CM>
 *  COATL_UCD_LB_CP - '*CP*', '*Close_Parenthesis*'
 *  COATL_UCD_LB_CLOSE_PARENTHESIS - Alias for <COATL_UCD_LB_CP>
 *  COATL_UCD_LB_CR - '*CR*', '*Carriage_Return*'
 *  COATL_UCD_LB_CARRIAGE_RETURN - Alias for <COATL_UCD_LB_CR>
 *  COATL_UCD_LB_EX - '*EX*', '*Exclamation*'
 *  COATL_UCD_LB_EXCLAMATION - Alias for <COATL_UCD_LB_EX>
 *  COATL_UCD_LB_GL - '*GL*', '*Glue*'
 *  COATL_UCD_LB_GLUE - Alias for <COATL_UCD_LB_GL>
 *  COATL_UCD_LB_H2 - '*H2*'
 *  COATL_UCD_LB_H3 - '*H3*'
 *  COATL_UCD_LB_HL - '*HL*', '*Hebrew_Letter*'
 *  COATL_UCD_LB_HEBREW_LETTER - Alias for <COATL_UCD_LB_HL>
 *  COATL_UCD_LB_HY - '*HY*', '*Hyphen*'
 *  COATL_UCD_LB_HYPHEN - Alias for <COATL_UCD_LB_HY>
 *  COATL_UCD_LB_ID - '*ID*', '*Ideographic*'
 *  COATL_UCD_LB_IDEOGRAPHIC - Alias for <COATL_UCD_LB_ID>
 *  COATL_UCD_LB_IN - '*IN*', '*Inseparable*', '*Inseperable*'
 *  COATL_UCD_LB_INSEPARABLE - Alias for <COATL_UCD_LB_IN>
 *  COATL_UCD_LB_INSEPERABLE - Alias for <COATL_UCD_LB_IN>
 *  COATL_UCD_LB_IS - '*IS*', '*Infix_Numeric*'
 *  COATL_UCD_LB_INFIX_NUMERIC - Alias for <COATL_UCD_LB_IS>
 *  COATL_UCD_LB_JL - '*JL*'
 *  COATL_UCD_LB_JT - '*JT*'
 *  COATL_UCD_LB_JV - '*JV*'
 *  COATL_UCD_LB_LF - '*LF*', '*Line_Feed*'
 *  COATL_UCD_LB_LINE_FEED - Alias for <COATL_UCD_LB_LF>
 *  COATL_UCD_LB_NL - '*NL*', '*Next_Line*'
 *  COATL_UCD_LB_NEXT_LINE - Alias for <COATL_UCD_LB_NL>
 *  COATL_UCD_LB_NS - '*NS*', '*Nonstarter*'
 *  COATL_UCD_LB_NONSTARTER - Alias for <COATL_UCD_LB_NS>
 *  COATL_UCD_LB_NU - '*NU*', '*Numeric*'
 *  COATL_UCD_LB_NUMERIC - Alias for <COATL_UCD_LB_NU>
 *  COATL_UCD_LB_OP - '*OP*', '*Open_Punctuation*'
 *  COATL_UCD_LB_OPEN_PUNCTUATION - Alias for <COATL_UCD_LB_OP>
 *  COATL_UCD_LB_PO - '*PO*', '*Postfix_Numeric*'
 *  COATL_UCD_LB_POSTFIX_NUMERIC - Alias for <COATL_UCD_LB_PO>
 *  COATL_UCD_LB_PR - '*PR*', '*Prefix_Numeric*'
 *  COATL_UCD_LB_PREFIX_NUMERIC - Alias for <COATL_UCD_LB_PR>
 *  COATL_UCD_LB_QU - '*QU*', '*Quotation*'
 *  COATL_UCD_LB_QUOTATION - Alias for <COATL_UCD_LB_QU>
 *  COATL_UCD_LB_SA - '*SA*', '*Complex_Context*'
 *  COATL_UCD_LB_COMPLEX_CONTEXT - Alias for <COATL_UCD_LB_SA>
 *  COATL_UCD_LB_SG - '*SG*', '*Surrogate*'
 *  COATL_UCD_LB_SURROGATE - Alias for <COATL_UCD_LB_SG>
 *  COATL_UCD_LB_SP - '*SP*', '*Space*'
 *  COATL_UCD_LB_SPACE - Alias for <COATL_UCD_LB_SP>
 *  COATL_UCD_LB_SY - '*SY*', '*Break_Symbols*'
 *  COATL_UCD_LB_BREAK_SYMBOLS - Alias for <COATL_UCD_LB_SY>
 *  COATL_UCD_LB_WJ - '*WJ*', '*Word_Joiner*'
 *  COATL_UCD_LB_WORD_JOINER - Alias for <COATL_UCD_LB_WJ>
 *  COATL_UCD_LB_XX - '*XX*', '*Unknown*'
 *  COATL_UCD_LB_UNKNOWN - Alias for <COATL_UCD_LB_XX>
 *  COATL_UCD_LB_ZW - '*ZW*', '*ZWSpace*'
 *  COATL_UCD_LB_ZWSPACE - Alias for <COATL_UCD_LB_ZW>
 *
 * See also:
 *	<COATL_UCD_LB>
 *---------------------------------------------------------------------------*/

typedef enum Coatl_Ucd_Lb {
    COATL_UCD_LB_AI=1,
	COATL_UCD_LB_AMBIGUOUS=COATL_UCD_LB_AI,
    COATL_UCD_LB_AL=2,
	COATL_UCD_LB_ALPHABETIC=COATL_UCD_LB_AL,
    COATL_UCD_LB_B2=3,
	COATL_UCD_LB_BREAK_BOTH=COATL_UCD_LB_B2,
    COATL_UCD_LB_BA=4,
	COATL_UCD_LB_BREAK_AFTER=COATL_UCD_LB_BA,
    COATL_UCD_LB_BB=5,
	COATL_UCD_LB_BREAK_BEFORE=COATL_UCD_LB_BB,
    COATL_UCD_LB_BK=6,
	COATL_UCD_LB_MANDATORY_BREAK=COATL_UCD_LB_BK,
    COATL_UCD_LB_CB=7,
	COATL_UCD_LB_CONTINGENT_BREAK=COATL_UCD_LB_CB,
    COATL_UCD_LB_CJ=8,
	COATL_UCD_LB_CONDITIONAL_JAPANESE_STARTER=COATL_UCD_LB_CJ,
    COATL_UCD_LB_CL=9,
	COATL_UCD_LB_CLOSE_PUNCTUATION=COATL_UCD_LB_CL,
    COATL_UCD_LB_CM=10,
	COATL_UCD_LB_COMBINING_MARK=COATL_UCD_LB_CM,
    COATL_UCD_LB_CP=11,
	COATL_UCD_LB_CLOSE_PARENTHESIS=COATL_UCD_LB_CP,
    COATL_UCD_LB_CR=12,
	COATL_UCD_LB_CARRIAGE_RETURN=COATL_UCD_LB_CR,
    COATL_UCD_LB_EX=13,
	COATL_UCD_LB_EXCLAMATION=COATL_UCD_LB_EX,
    COATL_UCD_LB_GL=14,
	COATL_UCD_LB_GLUE=COATL_UCD_LB_GL,
    COATL_UCD_LB_H2=15,
    COATL_UCD_LB_H3=16,
    COATL_UCD_LB_HL=17,
	COATL_UCD_LB_HEBREW_LETTER=COATL_UCD_LB_HL,
    COATL_UCD_LB_HY=18,
	COATL_UCD_LB_HYPHEN=COATL_UCD_LB_HY,
    COATL_UCD_LB_ID=19,
	COATL_UCD_LB_IDEOGRAPHIC=COATL_UCD_LB_ID,
    COATL_UCD_LB_IN=20,
	COATL_UCD_LB_INSEPARABLE=COATL_UCD_LB_IN,
	COATL_UCD_LB_INSEPERABLE=COATL_UCD_LB_IN,
    COATL_UCD_LB_IS=21,
	COATL_UCD_LB_INFIX_NUMERIC=COATL_UCD_LB_IS,
    COATL_UCD_LB_JL=22,
    COATL_UCD_LB_JT=23,
    COATL_UCD_LB_JV=24,
    COATL_UCD_LB_LF=25,
	COATL_UCD_LB_LINE_FEED=COATL_UCD_LB_LF,
    COATL_UCD_LB_NL=26,
	COATL_UCD_LB_NEXT_LINE=COATL_UCD_LB_NL,
    COATL_UCD_LB_NS=27,
	COATL_UCD_LB_NONSTARTER=COATL_UCD_LB_NS,
    COATL_UCD_LB_NU=28,
	COATL_UCD_LB_NUMERIC=COATL_UCD_LB_NU,
    COATL_UCD_LB_OP=29,
	COATL_UCD_LB_OPEN_PUNCTUATION=COATL_UCD_LB_OP,
    COATL_UCD_LB_PO=30,
	COATL_UCD_LB_POSTFIX_NUMERIC=COATL_UCD_LB_PO,
    COATL_UCD_LB_PR=31,
	COATL_UCD_LB_PREFIX_NUMERIC=COATL_UCD_LB_PR,
    COATL_UCD_LB_QU=32,
	COATL_UCD_LB_QUOTATION=COATL_UCD_LB_QU,
    COATL_UCD_LB_SA=33,
	COATL_UCD_LB_COMPLEX_CONTEXT=COATL_UCD_LB_SA,
    COATL_UCD_LB_SG=34,
	COATL_UCD_LB_SURROGATE=COATL_UCD_LB_SG,
    COATL_UCD_LB_SP=35,
	COATL_UCD_LB_SPACE=COATL_UCD_LB_SP,
    COATL_UCD_LB_SY=36,
	COATL_UCD_LB_BREAK_SYMBOLS=COATL_UCD_LB_SY,
    COATL_UCD_LB_WJ=37,
	COATL_UCD_LB_WORD_JOINER=COATL_UCD_LB_WJ,
    COATL_UCD_LB_XX=38,
	COATL_UCD_LB_UNKNOWN=COATL_UCD_LB_XX,
    COATL_UCD_LB_ZW=39,
	COATL_UCD_LB_ZWSPACE=COATL_UCD_LB_ZW,

} Coatl_Ucd_Lb;

/*---------------------------------------------------------------------------
 * Constant: COATL_UCD_LB_NBVALUES
 *
 *	Number of values for Unicode character property '*lb*'.
 *
 * See also:
 *	<Coatl_Ucd_Lb>
 *---------------------------------------------------------------------------*/

#define COATL_UCD_LB_NBVALUES	39

/*---------------------------------------------------------------------------
 * Enum: Coatl_Ucd_NFC_QC
 *
 *	Values for Unicode character property '*NFC_QC*'.
 *
 *	Names are automatically generated from the UCD file
 *	*PropertyValueAliases.txt*
 *
 *  COATL_UCD_NFC_QC_M - '*M*', '*Maybe*'
 *  COATL_UCD_NFC_QC_MAYBE - Alias for <COATL_UCD_NFC_QC_M>
 *  COATL_UCD_NFC_QC_N - '*N*', '*No*'
 *  COATL_UCD_NFC_QC_NO - Alias for <COATL_UCD_NFC_QC_N>
 *  COATL_UCD_NFC_QC_Y - '*Y*', '*Yes*'
 *  COATL_UCD_NFC_QC_YES - Alias for <COATL_UCD_NFC_QC_Y>
 *
 * See also:
 *	<COATL_UCD_NFC_QC>
 *---------------------------------------------------------------------------*/

typedef enum Coatl_Ucd_NFC_QC {
    COATL_UCD_NFC_QC_M=1,
	COATL_UCD_NFC_QC_MAYBE=COATL_UCD_NFC_QC_M,
    COATL_UCD_NFC_QC_N=2,
	COATL_UCD_NFC_QC_NO=COATL_UCD_NFC_QC_N,
    COATL_UCD_NFC_QC_Y=3,
	COATL_UCD_NFC_QC_YES=COATL_UCD_NFC_QC_Y,

} Coatl_Ucd_NFC_QC;

/*---------------------------------------------------------------------------
 * Constant: COATL_UCD_NFC_QC_NBVALUES
 *
 *	Number of values for Unicode character property '*NFC_QC*'.
 *
 * See also:
 *	<Coatl_Ucd_NFC_QC>
 *---------------------------------------------------------------------------*/

#define COATL_UCD_NFC_QC_NBVALUES	3

/*---------------------------------------------------------------------------
 * Enum: Coatl_Ucd_NFKC_QC
 *
 *	Values for Unicode character property '*NFKC_QC*'.
 *
 *	Names are automatically generated from the UCD file
 *	*PropertyValueAliases.txt*
 *
 *  COATL_UCD_NFKC_QC_M - '*M*', '*Maybe*'
 *  COATL_UCD_NFKC_QC_MAYBE - Alias for <COATL_UCD_NFKC_QC_M>
 *  COATL_UCD_NFKC_QC_N - '*N*', '*No*'
 *  COATL_UCD_NFKC_QC_NO - Alias for <COATL_UCD_NFKC_QC_N>
 *  COATL_UCD_NFKC_QC_Y - '*Y*', '*Yes*'
 *  COATL_UCD_NFKC_QC_YES - Alias for <COATL_UCD_NFKC_QC_Y>
 *
 * See also:
 *	<COATL_UCD_NFKC_QC>
 *---------------------------------------------------------------------------*/

typedef enum Coatl_Ucd_NFKC_QC {
    COATL_UCD_NFKC_QC_M=1,
	COATL_UCD_NFKC_QC_MAYBE=COATL_UCD_NFKC_QC_M,
    COATL_UCD_NFKC_QC_N=2,
	COATL_UCD_NFKC_QC_NO=COATL_UCD_NFKC_QC_N,
    COATL_UCD_NFKC_QC_Y=3,
	COATL_UCD_NFKC_QC_YES=COATL_UCD_NFKC_QC_Y,

} Coatl_Ucd_NFKC_QC;

/*---------------------------------------------------------------------------
 * Constant: COATL_UCD_NFKC_QC_NBVALUES
 *
 *	Number of values for Unicode character property '*NFKC_QC*'.
 *
 * See also:
 *	<Coatl_Ucd_NFKC_QC>
 *---------------------------------------------------------------------------*/

#define COATL_UCD_NFKC_QC_NBVALUES	3

/*---------------------------------------------------------------------------
 * Enum: Coatl_Ucd_Nt
 *
 *	Values for Unicode character property '*nt*'.
 *
 *	Names are automatically generated from the UCD file
 *	*PropertyValueAliases.txt*
 *
 *  COATL_UCD_NT_DE - '*De*', '*Decimal*'
 *  COATL_UCD_NT_DECIMAL - Alias for <COATL_UCD_NT_DE>
 *  COATL_UCD_NT_DI - '*Di*', '*Digit*'
 *  COATL_UCD_NT_DIGIT - Alias for <COATL_UCD_NT_DI>
 *  COATL_UCD_NT_NONE - '*None*'
 *  COATL_UCD_NT_NU - '*Nu*', '*Numeric*'
 *  COATL_UCD_NT_NUMERIC - Alias for <COATL_UCD_NT_NU>
 *
 * See also:
 *	<COATL_UCD_NT>
 *---------------------------------------------------------------------------*/

typedef enum Coatl_Ucd_Nt {
    COATL_UCD_NT_DE=1,
	COATL_UCD_NT_DECIMAL=COATL_UCD_NT_DE,
    COATL_UCD_NT_DI=2,
	COATL_UCD_NT_DIGIT=COATL_UCD_NT_DI,
    COATL_UCD_NT_NONE=3,
    COATL_UCD_NT_NU=4,
	COATL_UCD_NT_NUMERIC=COATL_UCD_NT_NU,

} Coatl_Ucd_Nt;

/*---------------------------------------------------------------------------
 * Constant: COATL_UCD_NT_NBVALUES
 *
 *	Number of values for Unicode character property '*nt*'.
 *
 * See also:
 *	<Coatl_Ucd_Nt>
 *---------------------------------------------------------------------------*/

#define COATL_UCD_NT_NBVALUES	4

/*---------------------------------------------------------------------------
 * Enum: Coatl_Ucd_SB
 *
 *	Values for Unicode character property '*SB*'.
 *
 *	Names are automatically generated from the UCD file
 *	*PropertyValueAliases.txt*
 *
 *  COATL_UCD_SB_AT - '*AT*', '*ATerm*'
 *  COATL_UCD_SB_ATERM - Alias for <COATL_UCD_SB_AT>
 *  COATL_UCD_SB_CL - '*CL*', '*Close*'
 *  COATL_UCD_SB_CLOSE - Alias for <COATL_UCD_SB_CL>
 *  COATL_UCD_SB_CR - '*CR*'
 *  COATL_UCD_SB_EX - '*EX*', '*Extend*'
 *  COATL_UCD_SB_EXTEND - Alias for <COATL_UCD_SB_EX>
 *  COATL_UCD_SB_FO - '*FO*', '*Format*'
 *  COATL_UCD_SB_FORMAT - Alias for <COATL_UCD_SB_FO>
 *  COATL_UCD_SB_LE - '*LE*', '*OLetter*'
 *  COATL_UCD_SB_OLETTER - Alias for <COATL_UCD_SB_LE>
 *  COATL_UCD_SB_LF - '*LF*'
 *  COATL_UCD_SB_LO - '*LO*', '*Lower*'
 *  COATL_UCD_SB_LOWER - Alias for <COATL_UCD_SB_LO>
 *  COATL_UCD_SB_NU - '*NU*', '*Numeric*'
 *  COATL_UCD_SB_NUMERIC - Alias for <COATL_UCD_SB_NU>
 *  COATL_UCD_SB_SC - '*SC*', '*SContinue*'
 *  COATL_UCD_SB_SCONTINUE - Alias for <COATL_UCD_SB_SC>
 *  COATL_UCD_SB_SE - '*SE*', '*Sep*'
 *  COATL_UCD_SB_SEP - Alias for <COATL_UCD_SB_SE>
 *  COATL_UCD_SB_SP - '*SP*', '*Sp*'
 *  COATL_UCD_SB_ST - '*ST*', '*STerm*'
 *  COATL_UCD_SB_STERM - Alias for <COATL_UCD_SB_ST>
 *  COATL_UCD_SB_UP - '*UP*', '*Upper*'
 *  COATL_UCD_SB_UPPER - Alias for <COATL_UCD_SB_UP>
 *  COATL_UCD_SB_XX - '*XX*', '*Other*'
 *  COATL_UCD_SB_OTHER - Alias for <COATL_UCD_SB_XX>
 *
 * See also:
 *	<COATL_UCD_SB>
 *---------------------------------------------------------------------------*/

typedef enum Coatl_Ucd_SB {
    COATL_UCD_SB_AT=1,
	COATL_UCD_SB_ATERM=COATL_UCD_SB_AT,
    COATL_UCD_SB_CL=2,
	COATL_UCD_SB_CLOSE=COATL_UCD_SB_CL,
    COATL_UCD_SB_CR=3,
    COATL_UCD_SB_EX=4,
	COATL_UCD_SB_EXTEND=COATL_UCD_SB_EX,
    COATL_UCD_SB_FO=5,
	COATL_UCD_SB_FORMAT=COATL_UCD_SB_FO,
    COATL_UCD_SB_LE=6,
	COATL_UCD_SB_OLETTER=COATL_UCD_SB_LE,
    COATL_UCD_SB_LF=7,
    COATL_UCD_SB_LO=8,
	COATL_UCD_SB_LOWER=COATL_UCD_SB_LO,
    COATL_UCD_SB_NU=9,
	COATL_UCD_SB_NUMERIC=COATL_UCD_SB_NU,
    COATL_UCD_SB_SC=10,
	COATL_UCD_SB_SCONTINUE=COATL_UCD_SB_SC,
    COATL_UCD_SB_SE=11,
	COATL_UCD_SB_SEP=COATL_UCD_SB_SE,
    COATL_UCD_SB_SP=12,
    COATL_UCD_SB_ST=13,
	COATL_UCD_SB_STERM=COATL_UCD_SB_ST,
    COATL_UCD_SB_UP=14,
	COATL_UCD_SB_UPPER=COATL_UCD_SB_UP,
    COATL_UCD_SB_XX=15,
	COATL_UCD_SB_OTHER=COATL_UCD_SB_XX,

} Coatl_Ucd_SB;

/*---------------------------------------------------------------------------
 * Constant: COATL_UCD_SB_NBVALUES
 *
 *	Number of values for Unicode character property '*SB*'.
 *
 * See also:
 *	<Coatl_Ucd_SB>
 *---------------------------------------------------------------------------*/

#define COATL_UCD_SB_NBVALUES	15

/*---------------------------------------------------------------------------
 * Enum: Coatl_Ucd_Sc
 *
 *	Values for Unicode character property '*sc*'.
 *
 *	Names are automatically generated from the UCD file
 *	*PropertyValueAliases.txt*
 *
 *  COATL_UCD_SC_ARAB - '*Arab*', '*Arabic*'
 *  COATL_UCD_SC_ARABIC - Alias for <COATL_UCD_SC_ARAB>
 *  COATL_UCD_SC_ARMI - '*Armi*', '*Imperial_Aramaic*'
 *  COATL_UCD_SC_IMPERIAL_ARAMAIC - Alias for <COATL_UCD_SC_ARMI>
 *  COATL_UCD_SC_ARMN - '*Armn*', '*Armenian*'
 *  COATL_UCD_SC_ARMENIAN - Alias for <COATL_UCD_SC_ARMN>
 *  COATL_UCD_SC_AVST - '*Avst*', '*Avestan*'
 *  COATL_UCD_SC_AVESTAN - Alias for <COATL_UCD_SC_AVST>
 *  COATL_UCD_SC_BALI - '*Bali*', '*Balinese*'
 *  COATL_UCD_SC_BALINESE - Alias for <COATL_UCD_SC_BALI>
 *  COATL_UCD_SC_BAMU - '*Bamu*', '*Bamum*'
 *  COATL_UCD_SC_BAMUM - Alias for <COATL_UCD_SC_BAMU>
 *  COATL_UCD_SC_BATK - '*Batk*', '*Batak*'
 *  COATL_UCD_SC_BATAK - Alias for <COATL_UCD_SC_BATK>
 *  COATL_UCD_SC_BENG - '*Beng*', '*Bengali*'
 *  COATL_UCD_SC_BENGALI - Alias for <COATL_UCD_SC_BENG>
 *  COATL_UCD_SC_BOPO - '*Bopo*', '*Bopomofo*'
 *  COATL_UCD_SC_BOPOMOFO - Alias for <COATL_UCD_SC_BOPO>
 *  COATL_UCD_SC_BRAH - '*Brah*', '*Brahmi*'
 *  COATL_UCD_SC_BRAHMI - Alias for <COATL_UCD_SC_BRAH>
 *  COATL_UCD_SC_BRAI - '*Brai*', '*Braille*'
 *  COATL_UCD_SC_BRAILLE - Alias for <COATL_UCD_SC_BRAI>
 *  COATL_UCD_SC_BUGI - '*Bugi*', '*Buginese*'
 *  COATL_UCD_SC_BUGINESE - Alias for <COATL_UCD_SC_BUGI>
 *  COATL_UCD_SC_BUHD - '*Buhd*', '*Buhid*'
 *  COATL_UCD_SC_BUHID - Alias for <COATL_UCD_SC_BUHD>
 *  COATL_UCD_SC_CAKM - '*Cakm*', '*Chakma*'
 *  COATL_UCD_SC_CHAKMA - Alias for <COATL_UCD_SC_CAKM>
 *  COATL_UCD_SC_CANS - '*Cans*', '*Canadian_Aboriginal*'
 *  COATL_UCD_SC_CANADIAN_ABORIGINAL - Alias for <COATL_UCD_SC_CANS>
 *  COATL_UCD_SC_CARI - '*Cari*', '*Carian*'
 *  COATL_UCD_SC_CARIAN - Alias for <COATL_UCD_SC_CARI>
 *  COATL_UCD_SC_CHAM - '*Cham*'
 *  COATL_UCD_SC_CHER - '*Cher*', '*Cherokee*'
 *  COATL_UCD_SC_CHEROKEE - Alias for <COATL_UCD_SC_CHER>
 *  COATL_UCD_SC_COPT - '*Copt*', '*Coptic*', '*Qaac*'
 *  COATL_UCD_SC_COPTIC - Alias for <COATL_UCD_SC_COPT>
 *  COATL_UCD_SC_QAAC - Alias for <COATL_UCD_SC_COPT>
 *  COATL_UCD_SC_CPRT - '*Cprt*', '*Cypriot*'
 *  COATL_UCD_SC_CYPRIOT - Alias for <COATL_UCD_SC_CPRT>
 *  COATL_UCD_SC_CYRL - '*Cyrl*', '*Cyrillic*'
 *  COATL_UCD_SC_CYRILLIC - Alias for <COATL_UCD_SC_CYRL>
 *  COATL_UCD_SC_DEVA - '*Deva*', '*Devanagari*'
 *  COATL_UCD_SC_DEVANAGARI - Alias for <COATL_UCD_SC_DEVA>
 *  COATL_UCD_SC_DSRT - '*Dsrt*', '*Deseret*'
 *  COATL_UCD_SC_DESERET - Alias for <COATL_UCD_SC_DSRT>
 *  COATL_UCD_SC_EGYP - '*Egyp*', '*Egyptian_Hieroglyphs*'
 *  COATL_UCD_SC_EGYPTIAN_HIEROGLYPHS - Alias for <COATL_UCD_SC_EGYP>
 *  COATL_UCD_SC_ETHI - '*Ethi*', '*Ethiopic*'
 *  COATL_UCD_SC_ETHIOPIC - Alias for <COATL_UCD_SC_ETHI>
 *  COATL_UCD_SC_GEOR - '*Geor*', '*Georgian*'
 *  COATL_UCD_SC_GEORGIAN - Alias for <COATL_UCD_SC_GEOR>
 *  COATL_UCD_SC_GLAG - '*Glag*', '*Glagolitic*'
 *  COATL_UCD_SC_GLAGOLITIC - Alias for <COATL_UCD_SC_GLAG>
 *  COATL_UCD_SC_GOTH - '*Goth*', '*Gothic*'
 *  COATL_UCD_SC_GOTHIC - Alias for <COATL_UCD_SC_GOTH>
 *  COATL_UCD_SC_GREK - '*Grek*', '*Greek*'
 *  COATL_UCD_SC_GREEK - Alias for <COATL_UCD_SC_GREK>
 *  COATL_UCD_SC_GUJR - '*Gujr*', '*Gujarati*'
 *  COATL_UCD_SC_GUJARATI - Alias for <COATL_UCD_SC_GUJR>
 *  COATL_UCD_SC_GURU - '*Guru*', '*Gurmukhi*'
 *  COATL_UCD_SC_GURMUKHI - Alias for <COATL_UCD_SC_GURU>
 *  COATL_UCD_SC_HANG - '*Hang*', '*Hangul*'
 *  COATL_UCD_SC_HANGUL - Alias for <COATL_UCD_SC_HANG>
 *  COATL_UCD_SC_HANI - '*Hani*', '*Han*'
 *  COATL_UCD_SC_HAN - Alias for <COATL_UCD_SC_HANI>
 *  COATL_UCD_SC_HANO - '*Hano*', '*Hanunoo*'
 *  COATL_UCD_SC_HANUNOO - Alias for <COATL_UCD_SC_HANO>
 *  COATL_UCD_SC_HEBR - '*Hebr*', '*Hebrew*'
 *  COATL_UCD_SC_HEBREW - Alias for <COATL_UCD_SC_HEBR>
 *  COATL_UCD_SC_HIRA - '*Hira*', '*Hiragana*'
 *  COATL_UCD_SC_HIRAGANA - Alias for <COATL_UCD_SC_HIRA>
 *  COATL_UCD_SC_HRKT - '*Hrkt*', '*Katakana_Or_Hiragana*'
 *  COATL_UCD_SC_KATAKANA_OR_HIRAGANA - Alias for <COATL_UCD_SC_HRKT>
 *  COATL_UCD_SC_ITAL - '*Ital*', '*Old_Italic*'
 *  COATL_UCD_SC_OLD_ITALIC - Alias for <COATL_UCD_SC_ITAL>
 *  COATL_UCD_SC_JAVA - '*Java*', '*Javanese*'
 *  COATL_UCD_SC_JAVANESE - Alias for <COATL_UCD_SC_JAVA>
 *  COATL_UCD_SC_KALI - '*Kali*', '*Kayah_Li*'
 *  COATL_UCD_SC_KAYAH_LI - Alias for <COATL_UCD_SC_KALI>
 *  COATL_UCD_SC_KANA - '*Kana*', '*Katakana*'
 *  COATL_UCD_SC_KATAKANA - Alias for <COATL_UCD_SC_KANA>
 *  COATL_UCD_SC_KHAR - '*Khar*', '*Kharoshthi*'
 *  COATL_UCD_SC_KHAROSHTHI - Alias for <COATL_UCD_SC_KHAR>
 *  COATL_UCD_SC_KHMR - '*Khmr*', '*Khmer*'
 *  COATL_UCD_SC_KHMER - Alias for <COATL_UCD_SC_KHMR>
 *  COATL_UCD_SC_KNDA - '*Knda*', '*Kannada*'
 *  COATL_UCD_SC_KANNADA - Alias for <COATL_UCD_SC_KNDA>
 *  COATL_UCD_SC_KTHI - '*Kthi*', '*Kaithi*'
 *  COATL_UCD_SC_KAITHI - Alias for <COATL_UCD_SC_KTHI>
 *  COATL_UCD_SC_LANA - '*Lana*', '*Tai_Tham*'
 *  COATL_UCD_SC_TAI_THAM - Alias for <COATL_UCD_SC_LANA>
 *  COATL_UCD_SC_LAOO - '*Laoo*', '*Lao*'
 *  COATL_UCD_SC_LAO - Alias for <COATL_UCD_SC_LAOO>
 *  COATL_UCD_SC_LATN - '*Latn*', '*Latin*'
 *  COATL_UCD_SC_LATIN - Alias for <COATL_UCD_SC_LATN>
 *  COATL_UCD_SC_LEPC - '*Lepc*', '*Lepcha*'
 *  COATL_UCD_SC_LEPCHA - Alias for <COATL_UCD_SC_LEPC>
 *  COATL_UCD_SC_LIMB - '*Limb*', '*Limbu*'
 *  COATL_UCD_SC_LIMBU - Alias for <COATL_UCD_SC_LIMB>
 *  COATL_UCD_SC_LINB - '*Linb*', '*Linear_B*'
 *  COATL_UCD_SC_LINEAR_B - Alias for <COATL_UCD_SC_LINB>
 *  COATL_UCD_SC_LISU - '*Lisu*'
 *  COATL_UCD_SC_LYCI - '*Lyci*', '*Lycian*'
 *  COATL_UCD_SC_LYCIAN - Alias for <COATL_UCD_SC_LYCI>
 *  COATL_UCD_SC_LYDI - '*Lydi*', '*Lydian*'
 *  COATL_UCD_SC_LYDIAN - Alias for <COATL_UCD_SC_LYDI>
 *  COATL_UCD_SC_MAND - '*Mand*', '*Mandaic*'
 *  COATL_UCD_SC_MANDAIC - Alias for <COATL_UCD_SC_MAND>
 *  COATL_UCD_SC_MERC - '*Merc*', '*Meroitic_Cursive*'
 *  COATL_UCD_SC_MEROITIC_CURSIVE - Alias for <COATL_UCD_SC_MERC>
 *  COATL_UCD_SC_MERO - '*Mero*', '*Meroitic_Hieroglyphs*'
 *  COATL_UCD_SC_MEROITIC_HIEROGLYPHS - Alias for <COATL_UCD_SC_MERO>
 *  COATL_UCD_SC_MLYM - '*Mlym*', '*Malayalam*'
 *  COATL_UCD_SC_MALAYALAM - Alias for <COATL_UCD_SC_MLYM>
 *  COATL_UCD_SC_MONG - '*Mong*', '*Mongolian*'
 *  COATL_UCD_SC_MONGOLIAN - Alias for <COATL_UCD_SC_MONG>
 *  COATL_UCD_SC_MTEI - '*Mtei*', '*Meetei_Mayek*'
 *  COATL_UCD_SC_MEETEI_MAYEK - Alias for <COATL_UCD_SC_MTEI>
 *  COATL_UCD_SC_MYMR - '*Mymr*', '*Myanmar*'
 *  COATL_UCD_SC_MYANMAR - Alias for <COATL_UCD_SC_MYMR>
 *  COATL_UCD_SC_NKOO - '*Nkoo*', '*Nko*'
 *  COATL_UCD_SC_NKO - Alias for <COATL_UCD_SC_NKOO>
 *  COATL_UCD_SC_OGAM - '*Ogam*', '*Ogham*'
 *  COATL_UCD_SC_OGHAM - Alias for <COATL_UCD_SC_OGAM>
 *  COATL_UCD_SC_OLCK - '*Olck*', '*Ol_Chiki*'
 *  COATL_UCD_SC_OL_CHIKI - Alias for <COATL_UCD_SC_OLCK>
 *  COATL_UCD_SC_ORKH - '*Orkh*', '*Old_Turkic*'
 *  COATL_UCD_SC_OLD_TURKIC - Alias for <COATL_UCD_SC_ORKH>
 *  COATL_UCD_SC_ORYA - '*Orya*', '*Oriya*'
 *  COATL_UCD_SC_ORIYA - Alias for <COATL_UCD_SC_ORYA>
 *  COATL_UCD_SC_OSMA - '*Osma*', '*Osmanya*'
 *  COATL_UCD_SC_OSMANYA - Alias for <COATL_UCD_SC_OSMA>
 *  COATL_UCD_SC_PHAG - '*Phag*', '*Phags_Pa*'
 *  COATL_UCD_SC_PHAGS_PA - Alias for <COATL_UCD_SC_PHAG>
 *  COATL_UCD_SC_PHLI - '*Phli*', '*Inscriptional_Pahlavi*'
 *  COATL_UCD_SC_INSCRIPTIONAL_PAHLAVI - Alias for <COATL_UCD_SC_PHLI>
 *  COATL_UCD_SC_PHNX - '*Phnx*', '*Phoenician*'
 *  COATL_UCD_SC_PHOENICIAN - Alias for <COATL_UCD_SC_PHNX>
 *  COATL_UCD_SC_PLRD - '*Plrd*', '*Miao*'
 *  COATL_UCD_SC_MIAO - Alias for <COATL_UCD_SC_PLRD>
 *  COATL_UCD_SC_PRTI - '*Prti*', '*Inscriptional_Parthian*'
 *  COATL_UCD_SC_INSCRIPTIONAL_PARTHIAN - Alias for <COATL_UCD_SC_PRTI>
 *  COATL_UCD_SC_RJNG - '*Rjng*', '*Rejang*'
 *  COATL_UCD_SC_REJANG - Alias for <COATL_UCD_SC_RJNG>
 *  COATL_UCD_SC_RUNR - '*Runr*', '*Runic*'
 *  COATL_UCD_SC_RUNIC - Alias for <COATL_UCD_SC_RUNR>
 *  COATL_UCD_SC_SAMR - '*Samr*', '*Samaritan*'
 *  COATL_UCD_SC_SAMARITAN - Alias for <COATL_UCD_SC_SAMR>
 *  COATL_UCD_SC_SARB - '*Sarb*', '*Old_South_Arabian*'
 *  COATL_UCD_SC_OLD_SOUTH_ARABIAN - Alias for <COATL_UCD_SC_SARB>
 *  COATL_UCD_SC_SAUR - '*Saur*', '*Saurashtra*'
 *  COATL_UCD_SC_SAURASHTRA - Alias for <COATL_UCD_SC_SAUR>
 *  COATL_UCD_SC_SHAW - '*Shaw*', '*Shavian*'
 *  COATL_UCD_SC_SHAVIAN - Alias for <COATL_UCD_SC_SHAW>
 *  COATL_UCD_SC_SHRD - '*Shrd*', '*Sharada*'
 *  COATL_UCD_SC_SHARADA - Alias for <COATL_UCD_SC_SHRD>
 *  COATL_UCD_SC_SINH - '*Sinh*', '*Sinhala*'
 *  COATL_UCD_SC_SINHALA - Alias for <COATL_UCD_SC_SINH>
 *  COATL_UCD_SC_SORA - '*Sora*', '*Sora_Sompeng*'
 *  COATL_UCD_SC_SORA_SOMPENG - Alias for <COATL_UCD_SC_SORA>
 *  COATL_UCD_SC_SUND - '*Sund*', '*Sundanese*'
 *  COATL_UCD_SC_SUNDANESE - Alias for <COATL_UCD_SC_SUND>
 *  COATL_UCD_SC_SYLO - '*Sylo*', '*Syloti_Nagri*'
 *  COATL_UCD_SC_SYLOTI_NAGRI - Alias for <COATL_UCD_SC_SYLO>
 *  COATL_UCD_SC_SYRC - '*Syrc*', '*Syriac*'
 *  COATL_UCD_SC_SYRIAC - Alias for <COATL_UCD_SC_SYRC>
 *  COATL_UCD_SC_TAGB - '*Tagb*', '*Tagbanwa*'
 *  COATL_UCD_SC_TAGBANWA - Alias for <COATL_UCD_SC_TAGB>
 *  COATL_UCD_SC_TAKR - '*Takr*', '*Takri*'
 *  COATL_UCD_SC_TAKRI - Alias for <COATL_UCD_SC_TAKR>
 *  COATL_UCD_SC_TALE - '*Tale*', '*Tai_Le*'
 *  COATL_UCD_SC_TAI_LE - Alias for <COATL_UCD_SC_TALE>
 *  COATL_UCD_SC_TALU - '*Talu*', '*New_Tai_Lue*'
 *  COATL_UCD_SC_NEW_TAI_LUE - Alias for <COATL_UCD_SC_TALU>
 *  COATL_UCD_SC_TAML - '*Taml*', '*Tamil*'
 *  COATL_UCD_SC_TAMIL - Alias for <COATL_UCD_SC_TAML>
 *  COATL_UCD_SC_TAVT - '*Tavt*', '*Tai_Viet*'
 *  COATL_UCD_SC_TAI_VIET - Alias for <COATL_UCD_SC_TAVT>
 *  COATL_UCD_SC_TELU - '*Telu*', '*Telugu*'
 *  COATL_UCD_SC_TELUGU - Alias for <COATL_UCD_SC_TELU>
 *  COATL_UCD_SC_TFNG - '*Tfng*', '*Tifinagh*'
 *  COATL_UCD_SC_TIFINAGH - Alias for <COATL_UCD_SC_TFNG>
 *  COATL_UCD_SC_TGLG - '*Tglg*', '*Tagalog*'
 *  COATL_UCD_SC_TAGALOG - Alias for <COATL_UCD_SC_TGLG>
 *  COATL_UCD_SC_THAA - '*Thaa*', '*Thaana*'
 *  COATL_UCD_SC_THAANA - Alias for <COATL_UCD_SC_THAA>
 *  COATL_UCD_SC_THAI - '*Thai*'
 *  COATL_UCD_SC_TIBT - '*Tibt*', '*Tibetan*'
 *  COATL_UCD_SC_TIBETAN - Alias for <COATL_UCD_SC_TIBT>
 *  COATL_UCD_SC_UGAR - '*Ugar*', '*Ugaritic*'
 *  COATL_UCD_SC_UGARITIC - Alias for <COATL_UCD_SC_UGAR>
 *  COATL_UCD_SC_VAII - '*Vaii*', '*Vai*'
 *  COATL_UCD_SC_VAI - Alias for <COATL_UCD_SC_VAII>
 *  COATL_UCD_SC_XPEO - '*Xpeo*', '*Old_Persian*'
 *  COATL_UCD_SC_OLD_PERSIAN - Alias for <COATL_UCD_SC_XPEO>
 *  COATL_UCD_SC_XSUX - '*Xsux*', '*Cuneiform*'
 *  COATL_UCD_SC_CUNEIFORM - Alias for <COATL_UCD_SC_XSUX>
 *  COATL_UCD_SC_YIII - '*Yiii*', '*Yi*'
 *  COATL_UCD_SC_YI - Alias for <COATL_UCD_SC_YIII>
 *  COATL_UCD_SC_ZINH - '*Zinh*', '*Inherited*', '*Qaai*'
 *  COATL_UCD_SC_INHERITED - Alias for <COATL_UCD_SC_ZINH>
 *  COATL_UCD_SC_QAAI - Alias for <COATL_UCD_SC_ZINH>
 *  COATL_UCD_SC_ZYYY - '*Zyyy*', '*Common*'
 *  COATL_UCD_SC_COMMON - Alias for <COATL_UCD_SC_ZYYY>
 *  COATL_UCD_SC_ZZZZ - '*Zzzz*', '*Unknown*'
 *  COATL_UCD_SC_UNKNOWN - Alias for <COATL_UCD_SC_ZZZZ>
 *
 * See also:
 *	<COATL_UCD_SC>
 *---------------------------------------------------------------------------*/

typedef enum Coatl_Ucd_Sc {
    COATL_UCD_SC_ARAB=1,
	COATL_UCD_SC_ARABIC=COATL_UCD_SC_ARAB,
    COATL_UCD_SC_ARMI=2,
	COATL_UCD_SC_IMPERIAL_ARAMAIC=COATL_UCD_SC_ARMI,
    COATL_UCD_SC_ARMN=3,
	COATL_UCD_SC_ARMENIAN=COATL_UCD_SC_ARMN,
    COATL_UCD_SC_AVST=4,
	COATL_UCD_SC_AVESTAN=COATL_UCD_SC_AVST,
    COATL_UCD_SC_BALI=5,
	COATL_UCD_SC_BALINESE=COATL_UCD_SC_BALI,
    COATL_UCD_SC_BAMU=6,
	COATL_UCD_SC_BAMUM=COATL_UCD_SC_BAMU,
    COATL_UCD_SC_BATK=7,
	COATL_UCD_SC_BATAK=COATL_UCD_SC_BATK,
    COATL_UCD_SC_BENG=8,
	COATL_UCD_SC_BENGALI=COATL_UCD_SC_BENG,
    COATL_UCD_SC_BOPO=9,
	COATL_UCD_SC_BOPOMOFO=COATL_UCD_SC_BOPO,
    COATL_UCD_SC_BRAH=10,
	COATL_UCD_SC_BRAHMI=COATL_UCD_SC_BRAH,
    COATL_UCD_SC_BRAI=11,
	COATL_UCD_SC_BRAILLE=COATL_UCD_SC_BRAI,
    COATL_UCD_SC_BUGI=12,
	COATL_UCD_SC_BUGINESE=COATL_UCD_SC_BUGI,
    COATL_UCD_SC_BUHD=13,
	COATL_UCD_SC_BUHID=COATL_UCD_SC_BUHD,
    COATL_UCD_SC_CAKM=14,
	COATL_UCD_SC_CHAKMA=COATL_UCD_SC_CAKM,
    COATL_UCD_SC_CANS=15,
	COATL_UCD_SC_CANADIAN_ABORIGINAL=COATL_UCD_SC_CANS,
    COATL_UCD_SC_CARI=16,
	COATL_UCD_SC_CARIAN=COATL_UCD_SC_CARI,
    COATL_UCD_SC_CHAM=17,
    COATL_UCD_SC_CHER=18,
	COATL_UCD_SC_CHEROKEE=COATL_UCD_SC_CHER,
    COATL_UCD_SC_COPT=19,
	COATL_UCD_SC_COPTIC=COATL_UCD_SC_COPT,
	COATL_UCD_SC_QAAC=COATL_UCD_SC_COPT,
    COATL_UCD_SC_CPRT=20,
	COATL_UCD_SC_CYPRIOT=COATL_UCD_SC_CPRT,
    COATL_UCD_SC_CYRL=21,
	COATL_UCD_SC_CYRILLIC=COATL_UCD_SC_CYRL,
    COATL_UCD_SC_DEVA=22,
	COATL_UCD_SC_DEVANAGARI=COATL_UCD_SC_DEVA,
    COATL_UCD_SC_DSRT=23,
	COATL_UCD_SC_DESERET=COATL_UCD_SC_DSRT,
    COATL_UCD_SC_EGYP=24,
	COATL_UCD_SC_EGYPTIAN_HIEROGLYPHS=COATL_UCD_SC_EGYP,
    COATL_UCD_SC_ETHI=25,
	COATL_UCD_SC_ETHIOPIC=COATL_UCD_SC_ETHI,
    COATL_UCD_SC_GEOR=26,
	COATL_UCD_SC_GEORGIAN=COATL_UCD_SC_GEOR,
    COATL_UCD_SC_GLAG=27,
	COATL_UCD_SC_GLAGOLITIC=COATL_UCD_SC_GLAG,
    COATL_UCD_SC_GOTH=28,
	COATL_UCD_SC_GOTHIC=COATL_UCD_SC_GOTH,
    COATL_UCD_SC_GREK=29,
	COATL_UCD_SC_GREEK=COATL_UCD_SC_GREK,
    COATL_UCD_SC_GUJR=30,
	COATL_UCD_SC_GUJARATI=COATL_UCD_SC_GUJR,
    COATL_UCD_SC_GURU=31,
	COATL_UCD_SC_GURMUKHI=COATL_UCD_SC_GURU,
    COATL_UCD_SC_HANG=32,
	COATL_UCD_SC_HANGUL=COATL_UCD_SC_HANG,
    COATL_UCD_SC_HANI=33,
	COATL_UCD_SC_HAN=COATL_UCD_SC_HANI,
    COATL_UCD_SC_HANO=34,
	COATL_UCD_SC_HANUNOO=COATL_UCD_SC_HANO,
    COATL_UCD_SC_HEBR=35,
	COATL_UCD_SC_HEBREW=COATL_UCD_SC_HEBR,
    COATL_UCD_SC_HIRA=36,
	COATL_UCD_SC_HIRAGANA=COATL_UCD_SC_HIRA,
    COATL_UCD_SC_HRKT=37,
	COATL_UCD_SC_KATAKANA_OR_HIRAGANA=COATL_UCD_SC_HRKT,
    COATL_UCD_SC_ITAL=38,
	COATL_UCD_SC_OLD_ITALIC=COATL_UCD_SC_ITAL,
    COATL_UCD_SC_JAVA=39,
	COATL_UCD_SC_JAVANESE=COATL_UCD_SC_JAVA,
    COATL_UCD_SC_KALI=40,
	COATL_UCD_SC_KAYAH_LI=COATL_UCD_SC_KALI,
    COATL_UCD_SC_KANA=41,
	COATL_UCD_SC_KATAKANA=COATL_UCD_SC_KANA,
    COATL_UCD_SC_KHAR=42,
	COATL_UCD_SC_KHAROSHTHI=COATL_UCD_SC_KHAR,
    COATL_UCD_SC_KHMR=43,
	COATL_UCD_SC_KHMER=COATL_UCD_SC_KHMR,
    COATL_UCD_SC_KNDA=44,
	COATL_UCD_SC_KANNADA=COATL_UCD_SC_KNDA,
    COATL_UCD_SC_KTHI=45,
	COATL_UCD_SC_KAITHI=COATL_UCD_SC_KTHI,
    COATL_UCD_SC_LANA=46,
	COATL_UCD_SC_TAI_THAM=COATL_UCD_SC_LANA,
    COATL_UCD_SC_LAOO=47,
	COATL_UCD_SC_LAO=COATL_UCD_SC_LAOO,
    COATL_UCD_SC_LATN=48,
	COATL_UCD_SC_LATIN=COATL_UCD_SC_LATN,
    COATL_UCD_SC_LEPC=49,
	COATL_UCD_SC_LEPCHA=COATL_UCD_SC_LEPC,
    COATL_UCD_SC_LIMB=50,
	COATL_UCD_SC_LIMBU=COATL_UCD_SC_LIMB,
    COATL_UCD_SC_LINB=51,
	COATL_UCD_SC_LINEAR_B=COATL_UCD_SC_LINB,
    COATL_UCD_SC_LISU=52,
    COATL_UCD_SC_LYCI=53,
	COATL_UCD_SC_LYCIAN=COATL_UCD_SC_LYCI,
    COATL_UCD_SC_LYDI=54,
	COATL_UCD_SC_LYDIAN=COATL_UCD_SC_LYDI,
    COATL_UCD_SC_MAND=55,
	COATL_UCD_SC_MANDAIC=COATL_UCD_SC_MAND,
    COATL_UCD_SC_MERC=56,
	COATL_UCD_SC_MEROITIC_CURSIVE=COATL_UCD_SC_MERC,
    COATL_UCD_SC_MERO=57,
	COATL_UCD_SC_MEROITIC_HIEROGLYPHS=COATL_UCD_SC_MERO,
    COATL_UCD_SC_MLYM=58,
	COATL_UCD_SC_MALAYALAM=COATL_UCD_SC_MLYM,
    COATL_UCD_SC_MONG=59,
	COATL_UCD_SC_MONGOLIAN=COATL_UCD_SC_MONG,
    COATL_UCD_SC_MTEI=60,
	COATL_UCD_SC_MEETEI_MAYEK=COATL_UCD_SC_MTEI,
    COATL_UCD_SC_MYMR=61,
	COATL_UCD_SC_MYANMAR=COATL_UCD_SC_MYMR,
    COATL_UCD_SC_NKOO=62,
	COATL_UCD_SC_NKO=COATL_UCD_SC_NKOO,
    COATL_UCD_SC_OGAM=63,
	COATL_UCD_SC_OGHAM=COATL_UCD_SC_OGAM,
    COATL_UCD_SC_OLCK=64,
	COATL_UCD_SC_OL_CHIKI=COATL_UCD_SC_OLCK,
    COATL_UCD_SC_ORKH=65,
	COATL_UCD_SC_OLD_TURKIC=COATL_UCD_SC_ORKH,
    COATL_UCD_SC_ORYA=66,
	COATL_UCD_SC_ORIYA=COATL_UCD_SC_ORYA,
    COATL_UCD_SC_OSMA=67,
	COATL_UCD_SC_OSMANYA=COATL_UCD_SC_OSMA,
    COATL_UCD_SC_PHAG=68,
	COATL_UCD_SC_PHAGS_PA=COATL_UCD_SC_PHAG,
    COATL_UCD_SC_PHLI=69,
	COATL_UCD_SC_INSCRIPTIONAL_PAHLAVI=COATL_UCD_SC_PHLI,
    COATL_UCD_SC_PHNX=70,
	COATL_UCD_SC_PHOENICIAN=COATL_UCD_SC_PHNX,
    COATL_UCD_SC_PLRD=71,
	COATL_UCD_SC_MIAO=COATL_UCD_SC_PLRD,
    COATL_UCD_SC_PRTI=72,
	COATL_UCD_SC_INSCRIPTIONAL_PARTHIAN=COATL_UCD_SC_PRTI,
    COATL_UCD_SC_RJNG=73,
	COATL_UCD_SC_REJANG=COATL_UCD_SC_RJNG,
    COATL_UCD_SC_RUNR=74,
	COATL_UCD_SC_RUNIC=COATL_UCD_SC_RUNR,
    COATL_UCD_SC_SAMR=75,
	COATL_UCD_SC_SAMARITAN=COATL_UCD_SC_SAMR,
    COATL_UCD_SC_SARB=76,
	COATL_UCD_SC_OLD_SOUTH_ARABIAN=COATL_UCD_SC_SARB,
    COATL_UCD_SC_SAUR=77,
	COATL_UCD_SC_SAURASHTRA=COATL_UCD_SC_SAUR,
    COATL_UCD_SC_SHAW=78,
	COATL_UCD_SC_SHAVIAN=COATL_UCD_SC_SHAW,
    COATL_UCD_SC_SHRD=79,
	COATL_UCD_SC_SHARADA=COATL_UCD_SC_SHRD,
    COATL_UCD_SC_SINH=80,
	COATL_UCD_SC_SINHALA=COATL_UCD_SC_SINH,
    COATL_UCD_SC_SORA=81,
	COATL_UCD_SC_SORA_SOMPENG=COATL_UCD_SC_SORA,
    COATL_UCD_SC_SUND=82,
	COATL_UCD_SC_SUNDANESE=COATL_UCD_SC_SUND,
    COATL_UCD_SC_SYLO=83,
	COATL_UCD_SC_SYLOTI_NAGRI=COATL_UCD_SC_SYLO,
    COATL_UCD_SC_SYRC=84,
	COATL_UCD_SC_SYRIAC=COATL_UCD_SC_SYRC,
    COATL_UCD_SC_TAGB=85,
	COATL_UCD_SC_TAGBANWA=COATL_UCD_SC_TAGB,
    COATL_UCD_SC_TAKR=86,
	COATL_UCD_SC_TAKRI=COATL_UCD_SC_TAKR,
    COATL_UCD_SC_TALE=87,
	COATL_UCD_SC_TAI_LE=COATL_UCD_SC_TALE,
    COATL_UCD_SC_TALU=88,
	COATL_UCD_SC_NEW_TAI_LUE=COATL_UCD_SC_TALU,
    COATL_UCD_SC_TAML=89,
	COATL_UCD_SC_TAMIL=COATL_UCD_SC_TAML,
    COATL_UCD_SC_TAVT=90,
	COATL_UCD_SC_TAI_VIET=COATL_UCD_SC_TAVT,
    COATL_UCD_SC_TELU=91,
	COATL_UCD_SC_TELUGU=COATL_UCD_SC_TELU,
    COATL_UCD_SC_TFNG=92,
	COATL_UCD_SC_TIFINAGH=COATL_UCD_SC_TFNG,
    COATL_UCD_SC_TGLG=93,
	COATL_UCD_SC_TAGALOG=COATL_UCD_SC_TGLG,
    COATL_UCD_SC_THAA=94,
	COATL_UCD_SC_THAANA=COATL_UCD_SC_THAA,
    COATL_UCD_SC_THAI=95,
    COATL_UCD_SC_TIBT=96,
	COATL_UCD_SC_TIBETAN=COATL_UCD_SC_TIBT,
    COATL_UCD_SC_UGAR=97,
	COATL_UCD_SC_UGARITIC=COATL_UCD_SC_UGAR,
    COATL_UCD_SC_VAII=98,
	COATL_UCD_SC_VAI=COATL_UCD_SC_VAII,
    COATL_UCD_SC_XPEO=99,
	COATL_UCD_SC_OLD_PERSIAN=COATL_UCD_SC_XPEO,
    COATL_UCD_SC_XSUX=100,
	COATL_UCD_SC_CUNEIFORM=COATL_UCD_SC_XSUX,
    COATL_UCD_SC_YIII=101,
	COATL_UCD_SC_YI=COATL_UCD_SC_YIII,
    COATL_UCD_SC_ZINH=102,
	COATL_UCD_SC_INHERITED=COATL_UCD_SC_ZINH,
	COATL_UCD_SC_QAAI=COATL_UCD_SC_ZINH,
    COATL_UCD_SC_ZYYY=103,
	COATL_UCD_SC_COMMON=COATL_UCD_SC_ZYYY,
    COATL_UCD_SC_ZZZZ=104,
	COATL_UCD_SC_UNKNOWN=COATL_UCD_SC_ZZZZ,

} Coatl_Ucd_Sc;

/*---------------------------------------------------------------------------
 * Constant: COATL_UCD_SC_NBVALUES
 *
 *	Number of values for Unicode character property '*sc*'.
 *
 * See also:
 *	<Coatl_Ucd_Sc>
 *---------------------------------------------------------------------------*/

#define COATL_UCD_SC_NBVALUES	104

/*---------------------------------------------------------------------------
 * Enum: Coatl_Ucd_WB
 *
 *	Values for Unicode character property '*WB*'.
 *
 *	Names are automatically generated from the UCD file
 *	*PropertyValueAliases.txt*
 *
 *  COATL_UCD_WB_CR - '*CR*'
 *  COATL_UCD_WB_EX - '*EX*', '*ExtendNumLet*'
 *  COATL_UCD_WB_EXTENDNUMLET - Alias for <COATL_UCD_WB_EX>
 *  COATL_UCD_WB_EXTEND - '*Extend*'
 *  COATL_UCD_WB_FO - '*FO*', '*Format*'
 *  COATL_UCD_WB_FORMAT - Alias for <COATL_UCD_WB_FO>
 *  COATL_UCD_WB_KA - '*KA*', '*Katakana*'
 *  COATL_UCD_WB_KATAKANA - Alias for <COATL_UCD_WB_KA>
 *  COATL_UCD_WB_LE - '*LE*', '*ALetter*'
 *  COATL_UCD_WB_ALETTER - Alias for <COATL_UCD_WB_LE>
 *  COATL_UCD_WB_LF - '*LF*'
 *  COATL_UCD_WB_MB - '*MB*', '*MidNumLet*'
 *  COATL_UCD_WB_MIDNUMLET - Alias for <COATL_UCD_WB_MB>
 *  COATL_UCD_WB_ML - '*ML*', '*MidLetter*'
 *  COATL_UCD_WB_MIDLETTER - Alias for <COATL_UCD_WB_ML>
 *  COATL_UCD_WB_MN - '*MN*', '*MidNum*'
 *  COATL_UCD_WB_MIDNUM - Alias for <COATL_UCD_WB_MN>
 *  COATL_UCD_WB_NL - '*NL*', '*Newline*'
 *  COATL_UCD_WB_NEWLINE - Alias for <COATL_UCD_WB_NL>
 *  COATL_UCD_WB_NU - '*NU*', '*Numeric*'
 *  COATL_UCD_WB_NUMERIC - Alias for <COATL_UCD_WB_NU>
 *  COATL_UCD_WB_XX - '*XX*', '*Other*'
 *  COATL_UCD_WB_OTHER - Alias for <COATL_UCD_WB_XX>
 *
 * See also:
 *	<COATL_UCD_WB>
 *---------------------------------------------------------------------------*/

typedef enum Coatl_Ucd_WB {
    COATL_UCD_WB_CR=1,
    COATL_UCD_WB_EX=2,
	COATL_UCD_WB_EXTENDNUMLET=COATL_UCD_WB_EX,
    COATL_UCD_WB_EXTEND=3,
    COATL_UCD_WB_FO=4,
	COATL_UCD_WB_FORMAT=COATL_UCD_WB_FO,
    COATL_UCD_WB_KA=5,
	COATL_UCD_WB_KATAKANA=COATL_UCD_WB_KA,
    COATL_UCD_WB_LE=6,
	COATL_UCD_WB_ALETTER=COATL_UCD_WB_LE,
    COATL_UCD_WB_LF=7,
    COATL_UCD_WB_MB=8,
	COATL_UCD_WB_MIDNUMLET=COATL_UCD_WB_MB,
    COATL_UCD_WB_ML=9,
	COATL_UCD_WB_MIDLETTER=COATL_UCD_WB_ML,
    COATL_UCD_WB_MN=10,
	COATL_UCD_WB_MIDNUM=COATL_UCD_WB_MN,
    COATL_UCD_WB_NL=11,
	COATL_UCD_WB_NEWLINE=COATL_UCD_WB_NL,
    COATL_UCD_WB_NU=12,
	COATL_UCD_WB_NUMERIC=COATL_UCD_WB_NU,
    COATL_UCD_WB_XX=13,
	COATL_UCD_WB_OTHER=COATL_UCD_WB_XX,

} Coatl_Ucd_WB;

/*---------------------------------------------------------------------------
 * Constant: COATL_UCD_WB_NBVALUES
 *
 *	Number of values for Unicode character property '*WB*'.
 *
 * See also:
 *	<Coatl_Ucd_WB>
 *---------------------------------------------------------------------------*/

#define COATL_UCD_WB_NBVALUES	13


#endif /* _COATL_UCDPROPERTIES */
