/**
 * @file coatlUcdProperties.h
 *
 * This header file describes Unicode character properties and values.
 *
 * It is automatically generated from the Unicode Character Database (UCD) using
 * the file `coatlUcd.tcl`; Do not modify.
 */

#ifndef _COATL_UCDPROPERTIES
#define _COATL_UCDPROPERTIES


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

/**
 * @enum Coatl_UcdProperty
 *      Unicode character properties.
 *
 *      Names are automatically generated from the UCD file
 *      `PropertyAliases.txt`.
 *
 * @var COATL_UCD_AGE
 *      '**age**', '**Age**'
 * @var COATL_UCD_AHEX
 *      '**AHex**', '**ASCII_Hex_Digit**'
 * @var COATL_UCD_ASCII_HEX_DIGIT
 *      Alias for #COATL_UCD_AHEX
 * @var COATL_UCD_ALPHA
 *      '**Alpha**', '**Alphabetic**'
 * @var COATL_UCD_ALPHABETIC
 *      Alias for #COATL_UCD_ALPHA
 * @var COATL_UCD_BC
 *      '**bc**', '**Bidi_Class**'
 * @var COATL_UCD_BIDI_CLASS
 *      Alias for #COATL_UCD_BC
 * @var COATL_UCD_BIDI_C
 *      '**Bidi_C**', '**Bidi_Control**'
 * @var COATL_UCD_BIDI_CONTROL
 *      Alias for #COATL_UCD_BIDI_C
 * @var COATL_UCD_BIDI_M
 *      '**Bidi_M**', '**Bidi_Mirrored**'
 * @var COATL_UCD_BIDI_MIRRORED
 *      Alias for #COATL_UCD_BIDI_M
 * @var COATL_UCD_BLK
 *      '**blk**', '**Block**'
 * @var COATL_UCD_BLOCK
 *      Alias for #COATL_UCD_BLK
 * @var COATL_UCD_BMG
 *      '**bmg**', '**Bidi_Mirroring_Glyph**'
 * @var COATL_UCD_BIDI_MIRRORING_GLYPH
 *      Alias for #COATL_UCD_BMG
 * @var COATL_UCD_CASED
 *      '**Cased**', '**Cased**'
 * @var COATL_UCD_CCC
 *      '**ccc**', '**Canonical_Combining_Class**'
 * @var COATL_UCD_CANONICAL_COMBINING_CLASS
 *      Alias for #COATL_UCD_CCC
 * @var COATL_UCD_CE
 *      '**CE**', '**Composition_Exclusion**'
 * @var COATL_UCD_COMPOSITION_EXCLUSION
 *      Alias for #COATL_UCD_CE
 * @var COATL_UCD_CF
 *      '**cf**', '**Case_Folding**'
 * @var COATL_UCD_CASE_FOLDING
 *      Alias for #COATL_UCD_CF
 * @var COATL_UCD_CI
 *      '**CI**', '**Case_Ignorable**'
 * @var COATL_UCD_CASE_IGNORABLE
 *      Alias for #COATL_UCD_CI
 * @var COATL_UCD_COMP_EX
 *      '**Comp_Ex**', '**Full_Composition_Exclusion**'
 * @var COATL_UCD_FULL_COMPOSITION_EXCLUSION
 *      Alias for #COATL_UCD_COMP_EX
 * @var COATL_UCD_CWCF
 *      '**CWCF**', '**Changes_When_Casefolded**'
 * @var COATL_UCD_CHANGES_WHEN_CASEFOLDED
 *      Alias for #COATL_UCD_CWCF
 * @var COATL_UCD_CWCM
 *      '**CWCM**', '**Changes_When_Casemapped**'
 * @var COATL_UCD_CHANGES_WHEN_CASEMAPPED
 *      Alias for #COATL_UCD_CWCM
 * @var COATL_UCD_CWKCF
 *      '**CWKCF**', '**Changes_When_NFKC_Casefolded**'
 * @var COATL_UCD_CHANGES_WHEN_NFKC_CASEFOLDED
 *      Alias for #COATL_UCD_CWKCF
 * @var COATL_UCD_CWL
 *      '**CWL**', '**Changes_When_Lowercased**'
 * @var COATL_UCD_CHANGES_WHEN_LOWERCASED
 *      Alias for #COATL_UCD_CWL
 * @var COATL_UCD_CWT
 *      '**CWT**', '**Changes_When_Titlecased**'
 * @var COATL_UCD_CHANGES_WHEN_TITLECASED
 *      Alias for #COATL_UCD_CWT
 * @var COATL_UCD_CWU
 *      '**CWU**', '**Changes_When_Uppercased**'
 * @var COATL_UCD_CHANGES_WHEN_UPPERCASED
 *      Alias for #COATL_UCD_CWU
 * @var COATL_UCD_DASH
 *      '**Dash**', '**Dash**'
 * @var COATL_UCD_DEP
 *      '**Dep**', '**Deprecated**'
 * @var COATL_UCD_DEPRECATED
 *      Alias for #COATL_UCD_DEP
 * @var COATL_UCD_DI
 *      '**DI**', '**Default_Ignorable_Code_Point**'
 * @var COATL_UCD_DEFAULT_IGNORABLE_CODE_POINT
 *      Alias for #COATL_UCD_DI
 * @var COATL_UCD_DIA
 *      '**Dia**', '**Diacritic**'
 * @var COATL_UCD_DIACRITIC
 *      Alias for #COATL_UCD_DIA
 * @var COATL_UCD_DM
 *      '**dm**', '**Decomposition_Mapping**'
 * @var COATL_UCD_DECOMPOSITION_MAPPING
 *      Alias for #COATL_UCD_DM
 * @var COATL_UCD_DT
 *      '**dt**', '**Decomposition_Type**'
 * @var COATL_UCD_DECOMPOSITION_TYPE
 *      Alias for #COATL_UCD_DT
 * @var COATL_UCD_EA
 *      '**ea**', '**East_Asian_Width**'
 * @var COATL_UCD_EAST_ASIAN_WIDTH
 *      Alias for #COATL_UCD_EA
 * @var COATL_UCD_EXT
 *      '**Ext**', '**Extender**'
 * @var COATL_UCD_EXTENDER
 *      Alias for #COATL_UCD_EXT
 * @var COATL_UCD_GC
 *      '**gc**', '**General_Category**'
 * @var COATL_UCD_GENERAL_CATEGORY
 *      Alias for #COATL_UCD_GC
 * @var COATL_UCD_GCB
 *      '**GCB**', '**Grapheme_Cluster_Break**'
 * @var COATL_UCD_GRAPHEME_CLUSTER_BREAK
 *      Alias for #COATL_UCD_GCB
 * @var COATL_UCD_GR_BASE
 *      '**Gr_Base**', '**Grapheme_Base**'
 * @var COATL_UCD_GRAPHEME_BASE
 *      Alias for #COATL_UCD_GR_BASE
 * @var COATL_UCD_GR_EXT
 *      '**Gr_Ext**', '**Grapheme_Extend**'
 * @var COATL_UCD_GRAPHEME_EXTEND
 *      Alias for #COATL_UCD_GR_EXT
 * @var COATL_UCD_HEX
 *      '**Hex**', '**Hex_Digit**'
 * @var COATL_UCD_HEX_DIGIT
 *      Alias for #COATL_UCD_HEX
 * @var COATL_UCD_HST
 *      '**hst**', '**Hangul_Syllable_Type**'
 * @var COATL_UCD_HANGUL_SYLLABLE_TYPE
 *      Alias for #COATL_UCD_HST
 * @var COATL_UCD_IDC
 *      '**IDC**', '**ID_Continue**'
 * @var COATL_UCD_ID_CONTINUE
 *      Alias for #COATL_UCD_IDC
 * @var COATL_UCD_IDEO
 *      '**Ideo**', '**Ideographic**'
 * @var COATL_UCD_IDEOGRAPHIC
 *      Alias for #COATL_UCD_IDEO
 * @var COATL_UCD_IDS
 *      '**IDS**', '**ID_Start**'
 * @var COATL_UCD_ID_START
 *      Alias for #COATL_UCD_IDS
 * @var COATL_UCD_IDSB
 *      '**IDSB**', '**IDS_Binary_Operator**'
 * @var COATL_UCD_IDS_BINARY_OPERATOR
 *      Alias for #COATL_UCD_IDSB
 * @var COATL_UCD_IDST
 *      '**IDST**', '**IDS_Trinary_Operator**'
 * @var COATL_UCD_IDS_TRINARY_OPERATOR
 *      Alias for #COATL_UCD_IDST
 * @var COATL_UCD_INPC
 *      '**InPC**', '**Indic_Positional_Category**'
 * @var COATL_UCD_INDIC_POSITIONAL_CATEGORY
 *      Alias for #COATL_UCD_INPC
 * @var COATL_UCD_INSC
 *      '**InSC**', '**Indic_Syllabic_Category**'
 * @var COATL_UCD_INDIC_SYLLABIC_CATEGORY
 *      Alias for #COATL_UCD_INSC
 * @var COATL_UCD_JG
 *      '**jg**', '**Joining_Group**'
 * @var COATL_UCD_JOINING_GROUP
 *      Alias for #COATL_UCD_JG
 * @var COATL_UCD_JOIN_C
 *      '**Join_C**', '**Join_Control**'
 * @var COATL_UCD_JOIN_CONTROL
 *      Alias for #COATL_UCD_JOIN_C
 * @var COATL_UCD_JSN
 *      '**JSN**', '**Jamo_Short_Name**'
 * @var COATL_UCD_JAMO_SHORT_NAME
 *      Alias for #COATL_UCD_JSN
 * @var COATL_UCD_JT
 *      '**jt**', '**Joining_Type**'
 * @var COATL_UCD_JOINING_TYPE
 *      Alias for #COATL_UCD_JT
 * @var COATL_UCD_LB
 *      '**lb**', '**Line_Break**'
 * @var COATL_UCD_LINE_BREAK
 *      Alias for #COATL_UCD_LB
 * @var COATL_UCD_LC
 *      '**lc**', '**Lowercase_Mapping**'
 * @var COATL_UCD_LOWERCASE_MAPPING
 *      Alias for #COATL_UCD_LC
 * @var COATL_UCD_LOE
 *      '**LOE**', '**Logical_Order_Exception**'
 * @var COATL_UCD_LOGICAL_ORDER_EXCEPTION
 *      Alias for #COATL_UCD_LOE
 * @var COATL_UCD_LOWER
 *      '**Lower**', '**Lowercase**'
 * @var COATL_UCD_LOWERCASE
 *      Alias for #COATL_UCD_LOWER
 * @var COATL_UCD_MATH
 *      '**Math**', '**Math**'
 * @var COATL_UCD_NA
 *      '**na**', '**Name**'
 * @var COATL_UCD_NAME
 *      Alias for #COATL_UCD_NA
 * @var COATL_UCD_NA1
 *      '**na1**', '**Unicode_1_Name**'
 * @var COATL_UCD_UNICODE_1_NAME
 *      Alias for #COATL_UCD_NA1
 * @var COATL_UCD_NAME_ALIAS
 *      '**Name_Alias**', '**Name_Alias**'
 * @var COATL_UCD_NCHAR
 *      '**NChar**', '**Noncharacter_Code_Point**'
 * @var COATL_UCD_NONCHARACTER_CODE_POINT
 *      Alias for #COATL_UCD_NCHAR
 * @var COATL_UCD_NFC_QC
 *      '**NFC_QC**', '**NFC_Quick_Check**'
 * @var COATL_UCD_NFC_QUICK_CHECK
 *      Alias for #COATL_UCD_NFC_QC
 * @var COATL_UCD_NFD_QC
 *      '**NFD_QC**', '**NFD_Quick_Check**'
 * @var COATL_UCD_NFD_QUICK_CHECK
 *      Alias for #COATL_UCD_NFD_QC
 * @var COATL_UCD_NFKC_CF
 *      '**NFKC_CF**', '**NFKC_Casefold**'
 * @var COATL_UCD_NFKC_CASEFOLD
 *      Alias for #COATL_UCD_NFKC_CF
 * @var COATL_UCD_NFKC_QC
 *      '**NFKC_QC**', '**NFKC_Quick_Check**'
 * @var COATL_UCD_NFKC_QUICK_CHECK
 *      Alias for #COATL_UCD_NFKC_QC
 * @var COATL_UCD_NFKD_QC
 *      '**NFKD_QC**', '**NFKD_Quick_Check**'
 * @var COATL_UCD_NFKD_QUICK_CHECK
 *      Alias for #COATL_UCD_NFKD_QC
 * @var COATL_UCD_NT
 *      '**nt**', '**Numeric_Type**'
 * @var COATL_UCD_NUMERIC_TYPE
 *      Alias for #COATL_UCD_NT
 * @var COATL_UCD_NV
 *      '**nv**', '**Numeric_Value**'
 * @var COATL_UCD_NUMERIC_VALUE
 *      Alias for #COATL_UCD_NV
 * @var COATL_UCD_OALPHA
 *      '**OAlpha**', '**Other_Alphabetic**'
 * @var COATL_UCD_OTHER_ALPHABETIC
 *      Alias for #COATL_UCD_OALPHA
 * @var COATL_UCD_ODI
 *      '**ODI**', '**Other_Default_Ignorable_Code_Point**'
 * @var COATL_UCD_OTHER_DEFAULT_IGNORABLE_CODE_POINT
 *      Alias for #COATL_UCD_ODI
 * @var COATL_UCD_OGR_EXT
 *      '**OGr_Ext**', '**Other_Grapheme_Extend**'
 * @var COATL_UCD_OTHER_GRAPHEME_EXTEND
 *      Alias for #COATL_UCD_OGR_EXT
 * @var COATL_UCD_OIDC
 *      '**OIDC**', '**Other_ID_Continue**'
 * @var COATL_UCD_OTHER_ID_CONTINUE
 *      Alias for #COATL_UCD_OIDC
 * @var COATL_UCD_OIDS
 *      '**OIDS**', '**Other_ID_Start**'
 * @var COATL_UCD_OTHER_ID_START
 *      Alias for #COATL_UCD_OIDS
 * @var COATL_UCD_OLOWER
 *      '**OLower**', '**Other_Lowercase**'
 * @var COATL_UCD_OTHER_LOWERCASE
 *      Alias for #COATL_UCD_OLOWER
 * @var COATL_UCD_OMATH
 *      '**OMath**', '**Other_Math**'
 * @var COATL_UCD_OTHER_MATH
 *      Alias for #COATL_UCD_OMATH
 * @var COATL_UCD_OUPPER
 *      '**OUpper**', '**Other_Uppercase**'
 * @var COATL_UCD_OTHER_UPPERCASE
 *      Alias for #COATL_UCD_OUPPER
 * @var COATL_UCD_PAT_SYN
 *      '**Pat_Syn**', '**Pattern_Syntax**'
 * @var COATL_UCD_PATTERN_SYNTAX
 *      Alias for #COATL_UCD_PAT_SYN
 * @var COATL_UCD_PAT_WS
 *      '**Pat_WS**', '**Pattern_White_Space**'
 * @var COATL_UCD_PATTERN_WHITE_SPACE
 *      Alias for #COATL_UCD_PAT_WS
 * @var COATL_UCD_QMARK
 *      '**QMark**', '**Quotation_Mark**'
 * @var COATL_UCD_QUOTATION_MARK
 *      Alias for #COATL_UCD_QMARK
 * @var COATL_UCD_RADICAL
 *      '**Radical**', '**Radical**'
 * @var COATL_UCD_SB
 *      '**SB**', '**Sentence_Break**'
 * @var COATL_UCD_SENTENCE_BREAK
 *      Alias for #COATL_UCD_SB
 * @var COATL_UCD_SC
 *      '**sc**', '**Script**'
 * @var COATL_UCD_SCRIPT
 *      Alias for #COATL_UCD_SC
 * @var COATL_UCD_SCF
 *      '**scf**', '**Simple_Case_Folding**', '**sfc**'
 * @var COATL_UCD_SIMPLE_CASE_FOLDING
 *      Alias for #COATL_UCD_SCF
 * @var COATL_UCD_SFC
 *      Alias for #COATL_UCD_SCF
 * @var COATL_UCD_SCX
 *      '**scx**', '**Script_Extensions**'
 * @var COATL_UCD_SCRIPT_EXTENSIONS
 *      Alias for #COATL_UCD_SCX
 * @var COATL_UCD_SD
 *      '**SD**', '**Soft_Dotted**'
 * @var COATL_UCD_SOFT_DOTTED
 *      Alias for #COATL_UCD_SD
 * @var COATL_UCD_SLC
 *      '**slc**', '**Simple_Lowercase_Mapping**'
 * @var COATL_UCD_SIMPLE_LOWERCASE_MAPPING
 *      Alias for #COATL_UCD_SLC
 * @var COATL_UCD_STC
 *      '**stc**', '**Simple_Titlecase_Mapping**'
 * @var COATL_UCD_SIMPLE_TITLECASE_MAPPING
 *      Alias for #COATL_UCD_STC
 * @var COATL_UCD_STERM
 *      '**STerm**', '**Sentence_Terminal**'
 * @var COATL_UCD_SENTENCE_TERMINAL
 *      Alias for #COATL_UCD_STERM
 * @var COATL_UCD_SUC
 *      '**suc**', '**Simple_Uppercase_Mapping**'
 * @var COATL_UCD_SIMPLE_UPPERCASE_MAPPING
 *      Alias for #COATL_UCD_SUC
 * @var COATL_UCD_TC
 *      '**tc**', '**Titlecase_Mapping**'
 * @var COATL_UCD_TITLECASE_MAPPING
 *      Alias for #COATL_UCD_TC
 * @var COATL_UCD_TERM
 *      '**Term**', '**Terminal_Punctuation**'
 * @var COATL_UCD_TERMINAL_PUNCTUATION
 *      Alias for #COATL_UCD_TERM
 * @var COATL_UCD_UC
 *      '**uc**', '**Uppercase_Mapping**'
 * @var COATL_UCD_UPPERCASE_MAPPING
 *      Alias for #COATL_UCD_UC
 * @var COATL_UCD_UIDEO
 *      '**UIdeo**', '**Unified_Ideograph**'
 * @var COATL_UCD_UNIFIED_IDEOGRAPH
 *      Alias for #COATL_UCD_UIDEO
 * @var COATL_UCD_UPPER
 *      '**Upper**', '**Uppercase**'
 * @var COATL_UCD_UPPERCASE
 *      Alias for #COATL_UCD_UPPER
 * @var COATL_UCD_VS
 *      '**VS**', '**Variation_Selector**'
 * @var COATL_UCD_VARIATION_SELECTOR
 *      Alias for #COATL_UCD_VS
 * @var COATL_UCD_WB
 *      '**WB**', '**Word_Break**'
 * @var COATL_UCD_WORD_BREAK
 *      Alias for #COATL_UCD_WB
 * @var COATL_UCD_WSPACE
 *      '**WSpace**', '**White_Space**', '**space**'
 * @var COATL_UCD_WHITE_SPACE
 *      Alias for #COATL_UCD_WSPACE
 * @var COATL_UCD_SPACE
 *      Alias for #COATL_UCD_WSPACE
 * @var COATL_UCD_XIDC
 *      '**XIDC**', '**XID_Continue**'
 * @var COATL_UCD_XID_CONTINUE
 *      Alias for #COATL_UCD_XIDC
 * @var COATL_UCD_XIDS
 *      '**XIDS**', '**XID_Start**'
 * @var COATL_UCD_XID_START
 *      Alias for #COATL_UCD_XIDS
 * @var COATL_UCD_BPB
 *      '**bpb**', '**Bidi_Paired_Bracket**'
 * @var COATL_UCD_BIDI_PAIRED_BRACKET
 *      Alias for #COATL_UCD_BPB
 * @var COATL_UCD_BPT
 *      '**bpt**', '**Bidi_Paired_Bracket_Type**'
 * @var COATL_UCD_BIDI_PAIRED_BRACKET_TYPE
 *      Alias for #COATL_UCD_BPT
 * @var COATL_UCD_PCM
 *      '**PCM**', '**Prepended_Concatenation_Mark**'
 * @var COATL_UCD_PREPENDED_CONCATENATION_MARK
 *      Alias for #COATL_UCD_PCM 
 */
 
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
    COATL_UCD_INPC=40,
        COATL_UCD_INDIC_POSITIONAL_CATEGORY=COATL_UCD_INPC,
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
        COATL_UCD_SENTENCE_TERMINAL=COATL_UCD_STERM,
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
    COATL_UCD_BPB=93,
        COATL_UCD_BIDI_PAIRED_BRACKET=COATL_UCD_BPB,
    COATL_UCD_BPT=94,
        COATL_UCD_BIDI_PAIRED_BRACKET_TYPE=COATL_UCD_BPT,
    COATL_UCD_PCM=95,
        COATL_UCD_PREPENDED_CONCATENATION_MARK=COATL_UCD_PCM,

} Coatl_UcdProperty;

/**
 * Number of Unicode character properties.
 *
 * @see Coatl_UcdProperty
 */
#define COATL_UCD_NBPROPERTIES  95

/**
 * @enum Coatl_Ucd_Age
 *      Values for Unicode character property '**age**'.
 *
 *      Names are automatically generated from the UCD file
 *      `PropertyValueAliases.txt`.
 *
 * @see COATL_UCD_AGE
 *
 * @var COATL_UCD_AGE_1_1
 *      '**1.1**', '**V1_1**'
 * @var COATL_UCD_AGE_V1_1
 *      Alias for #COATL_UCD_AGE_1_1
 * @var COATL_UCD_AGE_2_0
 *      '**2.0**', '**V2_0**'
 * @var COATL_UCD_AGE_V2_0
 *      Alias for #COATL_UCD_AGE_2_0
 * @var COATL_UCD_AGE_2_1
 *      '**2.1**', '**V2_1**'
 * @var COATL_UCD_AGE_V2_1
 *      Alias for #COATL_UCD_AGE_2_1
 * @var COATL_UCD_AGE_3_0
 *      '**3.0**', '**V3_0**'
 * @var COATL_UCD_AGE_V3_0
 *      Alias for #COATL_UCD_AGE_3_0
 * @var COATL_UCD_AGE_3_1
 *      '**3.1**', '**V3_1**'
 * @var COATL_UCD_AGE_V3_1
 *      Alias for #COATL_UCD_AGE_3_1
 * @var COATL_UCD_AGE_3_2
 *      '**3.2**', '**V3_2**'
 * @var COATL_UCD_AGE_V3_2
 *      Alias for #COATL_UCD_AGE_3_2
 * @var COATL_UCD_AGE_4_0
 *      '**4.0**', '**V4_0**'
 * @var COATL_UCD_AGE_V4_0
 *      Alias for #COATL_UCD_AGE_4_0
 * @var COATL_UCD_AGE_4_1
 *      '**4.1**', '**V4_1**'
 * @var COATL_UCD_AGE_V4_1
 *      Alias for #COATL_UCD_AGE_4_1
 * @var COATL_UCD_AGE_5_0
 *      '**5.0**', '**V5_0**'
 * @var COATL_UCD_AGE_V5_0
 *      Alias for #COATL_UCD_AGE_5_0
 * @var COATL_UCD_AGE_5_1
 *      '**5.1**', '**V5_1**'
 * @var COATL_UCD_AGE_V5_1
 *      Alias for #COATL_UCD_AGE_5_1
 * @var COATL_UCD_AGE_5_2
 *      '**5.2**', '**V5_2**'
 * @var COATL_UCD_AGE_V5_2
 *      Alias for #COATL_UCD_AGE_5_2
 * @var COATL_UCD_AGE_6_0
 *      '**6.0**', '**V6_0**'
 * @var COATL_UCD_AGE_V6_0
 *      Alias for #COATL_UCD_AGE_6_0
 * @var COATL_UCD_AGE_6_1
 *      '**6.1**', '**V6_1**'
 * @var COATL_UCD_AGE_V6_1
 *      Alias for #COATL_UCD_AGE_6_1
 * @var COATL_UCD_AGE_6_2
 *      '**6.2**', '**V6_2**'
 * @var COATL_UCD_AGE_V6_2
 *      Alias for #COATL_UCD_AGE_6_2
 * @var COATL_UCD_AGE_6_3
 *      '**6.3**', '**V6_3**'
 * @var COATL_UCD_AGE_V6_3
 *      Alias for #COATL_UCD_AGE_6_3
 * @var COATL_UCD_AGE_7_0
 *      '**7.0**', '**V7_0**'
 * @var COATL_UCD_AGE_V7_0
 *      Alias for #COATL_UCD_AGE_7_0
 * @var COATL_UCD_AGE_8_0
 *      '**8.0**', '**V8_0**'
 * @var COATL_UCD_AGE_V8_0
 *      Alias for #COATL_UCD_AGE_8_0
 * @var COATL_UCD_AGE_9_0
 *      '**9.0**', '**V9_0**'
 * @var COATL_UCD_AGE_V9_0
 *      Alias for #COATL_UCD_AGE_9_0
 * @var COATL_UCD_AGE_NA
 *      '**NA**', '**Unassigned**'
 * @var COATL_UCD_AGE_UNASSIGNED
 *      Alias for #COATL_UCD_AGE_NA
 */
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
    COATL_UCD_AGE_6_2=14,
        COATL_UCD_AGE_V6_2=COATL_UCD_AGE_6_2,
    COATL_UCD_AGE_6_3=15,
        COATL_UCD_AGE_V6_3=COATL_UCD_AGE_6_3,
    COATL_UCD_AGE_7_0=16,
        COATL_UCD_AGE_V7_0=COATL_UCD_AGE_7_0,
    COATL_UCD_AGE_8_0=17,
        COATL_UCD_AGE_V8_0=COATL_UCD_AGE_8_0,
    COATL_UCD_AGE_9_0=18,
        COATL_UCD_AGE_V9_0=COATL_UCD_AGE_9_0,
    COATL_UCD_AGE_NA=19,
        COATL_UCD_AGE_UNASSIGNED=COATL_UCD_AGE_NA,

} Coatl_Ucd_Age;

/**
 * Number of values for Unicode character property '*age*'.
 *
 * @see Coatl_Ucd_Age
 */
#define COATL_UCD_AGE_NBVALUES       19

/**
 * @enum Coatl_Ucd_Bc
 *      Values for Unicode character property '**bc**'.
 *
 *      Names are automatically generated from the UCD file
 *      `PropertyValueAliases.txt`.
 *
 * @see COATL_UCD_BC
 *
 * @var COATL_UCD_BC_AL
 *      '**AL**', '**Arabic_Letter**'
 * @var COATL_UCD_BC_ARABIC_LETTER
 *      Alias for #COATL_UCD_BC_AL
 * @var COATL_UCD_BC_AN
 *      '**AN**', '**Arabic_Number**'
 * @var COATL_UCD_BC_ARABIC_NUMBER
 *      Alias for #COATL_UCD_BC_AN
 * @var COATL_UCD_BC_B
 *      '**B**', '**Paragraph_Separator**'
 * @var COATL_UCD_BC_PARAGRAPH_SEPARATOR
 *      Alias for #COATL_UCD_BC_B
 * @var COATL_UCD_BC_BN
 *      '**BN**', '**Boundary_Neutral**'
 * @var COATL_UCD_BC_BOUNDARY_NEUTRAL
 *      Alias for #COATL_UCD_BC_BN
 * @var COATL_UCD_BC_CS
 *      '**CS**', '**Common_Separator**'
 * @var COATL_UCD_BC_COMMON_SEPARATOR
 *      Alias for #COATL_UCD_BC_CS
 * @var COATL_UCD_BC_EN
 *      '**EN**', '**European_Number**'
 * @var COATL_UCD_BC_EUROPEAN_NUMBER
 *      Alias for #COATL_UCD_BC_EN
 * @var COATL_UCD_BC_ES
 *      '**ES**', '**European_Separator**'
 * @var COATL_UCD_BC_EUROPEAN_SEPARATOR
 *      Alias for #COATL_UCD_BC_ES
 * @var COATL_UCD_BC_ET
 *      '**ET**', '**European_Terminator**'
 * @var COATL_UCD_BC_EUROPEAN_TERMINATOR
 *      Alias for #COATL_UCD_BC_ET
 * @var COATL_UCD_BC_FSI
 *      '**FSI**', '**First_Strong_Isolate**'
 * @var COATL_UCD_BC_FIRST_STRONG_ISOLATE
 *      Alias for #COATL_UCD_BC_FSI
 * @var COATL_UCD_BC_L
 *      '**L**', '**Left_To_Right**'
 * @var COATL_UCD_BC_LEFT_TO_RIGHT
 *      Alias for #COATL_UCD_BC_L
 * @var COATL_UCD_BC_LRE
 *      '**LRE**', '**Left_To_Right_Embedding**'
 * @var COATL_UCD_BC_LEFT_TO_RIGHT_EMBEDDING
 *      Alias for #COATL_UCD_BC_LRE
 * @var COATL_UCD_BC_LRI
 *      '**LRI**', '**Left_To_Right_Isolate**'
 * @var COATL_UCD_BC_LEFT_TO_RIGHT_ISOLATE
 *      Alias for #COATL_UCD_BC_LRI
 * @var COATL_UCD_BC_LRO
 *      '**LRO**', '**Left_To_Right_Override**'
 * @var COATL_UCD_BC_LEFT_TO_RIGHT_OVERRIDE
 *      Alias for #COATL_UCD_BC_LRO
 * @var COATL_UCD_BC_NSM
 *      '**NSM**', '**Nonspacing_Mark**'
 * @var COATL_UCD_BC_NONSPACING_MARK
 *      Alias for #COATL_UCD_BC_NSM
 * @var COATL_UCD_BC_ON
 *      '**ON**', '**Other_Neutral**'
 * @var COATL_UCD_BC_OTHER_NEUTRAL
 *      Alias for #COATL_UCD_BC_ON
 * @var COATL_UCD_BC_PDF
 *      '**PDF**', '**Pop_Directional_Format**'
 * @var COATL_UCD_BC_POP_DIRECTIONAL_FORMAT
 *      Alias for #COATL_UCD_BC_PDF
 * @var COATL_UCD_BC_PDI
 *      '**PDI**', '**Pop_Directional_Isolate**'
 * @var COATL_UCD_BC_POP_DIRECTIONAL_ISOLATE
 *      Alias for #COATL_UCD_BC_PDI
 * @var COATL_UCD_BC_R
 *      '**R**', '**Right_To_Left**'
 * @var COATL_UCD_BC_RIGHT_TO_LEFT
 *      Alias for #COATL_UCD_BC_R
 * @var COATL_UCD_BC_RLE
 *      '**RLE**', '**Right_To_Left_Embedding**'
 * @var COATL_UCD_BC_RIGHT_TO_LEFT_EMBEDDING
 *      Alias for #COATL_UCD_BC_RLE
 * @var COATL_UCD_BC_RLI
 *      '**RLI**', '**Right_To_Left_Isolate**'
 * @var COATL_UCD_BC_RIGHT_TO_LEFT_ISOLATE
 *      Alias for #COATL_UCD_BC_RLI
 * @var COATL_UCD_BC_RLO
 *      '**RLO**', '**Right_To_Left_Override**'
 * @var COATL_UCD_BC_RIGHT_TO_LEFT_OVERRIDE
 *      Alias for #COATL_UCD_BC_RLO
 * @var COATL_UCD_BC_S
 *      '**S**', '**Segment_Separator**'
 * @var COATL_UCD_BC_SEGMENT_SEPARATOR
 *      Alias for #COATL_UCD_BC_S
 * @var COATL_UCD_BC_WS
 *      '**WS**', '**White_Space**'
 * @var COATL_UCD_BC_WHITE_SPACE
 *      Alias for #COATL_UCD_BC_WS
 */
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
    COATL_UCD_BC_FSI=9,
        COATL_UCD_BC_FIRST_STRONG_ISOLATE=COATL_UCD_BC_FSI,
    COATL_UCD_BC_L=10,
        COATL_UCD_BC_LEFT_TO_RIGHT=COATL_UCD_BC_L,
    COATL_UCD_BC_LRE=11,
        COATL_UCD_BC_LEFT_TO_RIGHT_EMBEDDING=COATL_UCD_BC_LRE,
    COATL_UCD_BC_LRI=12,
        COATL_UCD_BC_LEFT_TO_RIGHT_ISOLATE=COATL_UCD_BC_LRI,
    COATL_UCD_BC_LRO=13,
        COATL_UCD_BC_LEFT_TO_RIGHT_OVERRIDE=COATL_UCD_BC_LRO,
    COATL_UCD_BC_NSM=14,
        COATL_UCD_BC_NONSPACING_MARK=COATL_UCD_BC_NSM,
    COATL_UCD_BC_ON=15,
        COATL_UCD_BC_OTHER_NEUTRAL=COATL_UCD_BC_ON,
    COATL_UCD_BC_PDF=16,
        COATL_UCD_BC_POP_DIRECTIONAL_FORMAT=COATL_UCD_BC_PDF,
    COATL_UCD_BC_PDI=17,
        COATL_UCD_BC_POP_DIRECTIONAL_ISOLATE=COATL_UCD_BC_PDI,
    COATL_UCD_BC_R=18,
        COATL_UCD_BC_RIGHT_TO_LEFT=COATL_UCD_BC_R,
    COATL_UCD_BC_RLE=19,
        COATL_UCD_BC_RIGHT_TO_LEFT_EMBEDDING=COATL_UCD_BC_RLE,
    COATL_UCD_BC_RLI=20,
        COATL_UCD_BC_RIGHT_TO_LEFT_ISOLATE=COATL_UCD_BC_RLI,
    COATL_UCD_BC_RLO=21,
        COATL_UCD_BC_RIGHT_TO_LEFT_OVERRIDE=COATL_UCD_BC_RLO,
    COATL_UCD_BC_S=22,
        COATL_UCD_BC_SEGMENT_SEPARATOR=COATL_UCD_BC_S,
    COATL_UCD_BC_WS=23,
        COATL_UCD_BC_WHITE_SPACE=COATL_UCD_BC_WS,

} Coatl_Ucd_Bc;

/**
 * Number of values for Unicode character property '*bc*'.
 *
 * @see Coatl_Ucd_Bc
 */
#define COATL_UCD_BC_NBVALUES        23

/**
 * @enum Coatl_Ucd_Blk
 *      Values for Unicode character property '**blk**'.
 *
 *      Names are automatically generated from the UCD file
 *      `PropertyValueAliases.txt`.
 *
 * @see COATL_UCD_BLK
 *
 * @var COATL_UCD_BLK_ADLAM
 *      '**Adlam**'
 * @var COATL_UCD_BLK_AEGEAN_NUMBERS
 *      '**Aegean_Numbers**'
 * @var COATL_UCD_BLK_AHOM
 *      '**Ahom**'
 * @var COATL_UCD_BLK_ALCHEMICAL
 *      '**Alchemical**', '**Alchemical_Symbols**'
 * @var COATL_UCD_BLK_ALCHEMICAL_SYMBOLS
 *      Alias for #COATL_UCD_BLK_ALCHEMICAL
 * @var COATL_UCD_BLK_ALPHABETIC_PF
 *      '**Alphabetic_PF**', '**Alphabetic_Presentation_Forms**'
 * @var COATL_UCD_BLK_ALPHABETIC_PRESENTATION_FORMS
 *      Alias for #COATL_UCD_BLK_ALPHABETIC_PF
 * @var COATL_UCD_BLK_ANATOLIAN_HIEROGLYPHS
 *      '**Anatolian_Hieroglyphs**'
 * @var COATL_UCD_BLK_ANCIENT_GREEK_MUSIC
 *      '**Ancient_Greek_Music**', '**Ancient_Greek_Musical_Notation**'
 * @var COATL_UCD_BLK_ANCIENT_GREEK_MUSICAL_NOTATION
 *      Alias for #COATL_UCD_BLK_ANCIENT_GREEK_MUSIC
 * @var COATL_UCD_BLK_ANCIENT_GREEK_NUMBERS
 *      '**Ancient_Greek_Numbers**'
 * @var COATL_UCD_BLK_ANCIENT_SYMBOLS
 *      '**Ancient_Symbols**'
 * @var COATL_UCD_BLK_ARABIC
 *      '**Arabic**'
 * @var COATL_UCD_BLK_ARABIC_EXT_A
 *      '**Arabic_Ext_A**', '**Arabic_Extended_A**'
 * @var COATL_UCD_BLK_ARABIC_EXTENDED_A
 *      Alias for #COATL_UCD_BLK_ARABIC_EXT_A
 * @var COATL_UCD_BLK_ARABIC_MATH
 *      '**Arabic_Math**', '**Arabic_Mathematical_Alphabetic_Symbols**'
 * @var COATL_UCD_BLK_ARABIC_MATHEMATICAL_ALPHABETIC_SYMBOLS
 *      Alias for #COATL_UCD_BLK_ARABIC_MATH
 * @var COATL_UCD_BLK_ARABIC_PF_A
 *      '**Arabic_PF_A**', '**Arabic_Presentation_Forms_A**', '**Arabic_Presentation_Forms-A**'
 * @var COATL_UCD_BLK_ARABIC_PRESENTATION_FORMS_A
 *      Alias for #COATL_UCD_BLK_ARABIC_PF_A
 * @var COATL_UCD_BLK_ARABIC_PF_B
 *      '**Arabic_PF_B**', '**Arabic_Presentation_Forms_B**'
 * @var COATL_UCD_BLK_ARABIC_PRESENTATION_FORMS_B
 *      Alias for #COATL_UCD_BLK_ARABIC_PF_B
 * @var COATL_UCD_BLK_ARABIC_SUP
 *      '**Arabic_Sup**', '**Arabic_Supplement**'
 * @var COATL_UCD_BLK_ARABIC_SUPPLEMENT
 *      Alias for #COATL_UCD_BLK_ARABIC_SUP
 * @var COATL_UCD_BLK_ARMENIAN
 *      '**Armenian**'
 * @var COATL_UCD_BLK_ARROWS
 *      '**Arrows**'
 * @var COATL_UCD_BLK_ASCII
 *      '**ASCII**', '**Basic_Latin**'
 * @var COATL_UCD_BLK_BASIC_LATIN
 *      Alias for #COATL_UCD_BLK_ASCII
 * @var COATL_UCD_BLK_AVESTAN
 *      '**Avestan**'
 * @var COATL_UCD_BLK_BALINESE
 *      '**Balinese**'
 * @var COATL_UCD_BLK_BAMUM
 *      '**Bamum**'
 * @var COATL_UCD_BLK_BAMUM_SUP
 *      '**Bamum_Sup**', '**Bamum_Supplement**'
 * @var COATL_UCD_BLK_BAMUM_SUPPLEMENT
 *      Alias for #COATL_UCD_BLK_BAMUM_SUP
 * @var COATL_UCD_BLK_BASSA_VAH
 *      '**Bassa_Vah**'
 * @var COATL_UCD_BLK_BATAK
 *      '**Batak**'
 * @var COATL_UCD_BLK_BENGALI
 *      '**Bengali**'
 * @var COATL_UCD_BLK_BHAIKSUKI
 *      '**Bhaiksuki**'
 * @var COATL_UCD_BLK_BLOCK_ELEMENTS
 *      '**Block_Elements**'
 * @var COATL_UCD_BLK_BOPOMOFO
 *      '**Bopomofo**'
 * @var COATL_UCD_BLK_BOPOMOFO_EXT
 *      '**Bopomofo_Ext**', '**Bopomofo_Extended**'
 * @var COATL_UCD_BLK_BOPOMOFO_EXTENDED
 *      Alias for #COATL_UCD_BLK_BOPOMOFO_EXT
 * @var COATL_UCD_BLK_BOX_DRAWING
 *      '**Box_Drawing**'
 * @var COATL_UCD_BLK_BRAHMI
 *      '**Brahmi**'
 * @var COATL_UCD_BLK_BRAILLE
 *      '**Braille**', '**Braille_Patterns**'
 * @var COATL_UCD_BLK_BRAILLE_PATTERNS
 *      Alias for #COATL_UCD_BLK_BRAILLE
 * @var COATL_UCD_BLK_BUGINESE
 *      '**Buginese**'
 * @var COATL_UCD_BLK_BUHID
 *      '**Buhid**'
 * @var COATL_UCD_BLK_BYZANTINE_MUSIC
 *      '**Byzantine_Music**', '**Byzantine_Musical_Symbols**'
 * @var COATL_UCD_BLK_BYZANTINE_MUSICAL_SYMBOLS
 *      Alias for #COATL_UCD_BLK_BYZANTINE_MUSIC
 * @var COATL_UCD_BLK_CARIAN
 *      '**Carian**'
 * @var COATL_UCD_BLK_CAUCASIAN_ALBANIAN
 *      '**Caucasian_Albanian**'
 * @var COATL_UCD_BLK_CHAKMA
 *      '**Chakma**'
 * @var COATL_UCD_BLK_CHAM
 *      '**Cham**'
 * @var COATL_UCD_BLK_CHEROKEE
 *      '**Cherokee**'
 * @var COATL_UCD_BLK_CHEROKEE_SUP
 *      '**Cherokee_Sup**', '**Cherokee_Supplement**'
 * @var COATL_UCD_BLK_CHEROKEE_SUPPLEMENT
 *      Alias for #COATL_UCD_BLK_CHEROKEE_SUP
 * @var COATL_UCD_BLK_CJK
 *      '**CJK**', '**CJK_Unified_Ideographs**'
 * @var COATL_UCD_BLK_CJK_UNIFIED_IDEOGRAPHS
 *      Alias for #COATL_UCD_BLK_CJK
 * @var COATL_UCD_BLK_CJK_COMPAT
 *      '**CJK_Compat**', '**CJK_Compatibility**'
 * @var COATL_UCD_BLK_CJK_COMPATIBILITY
 *      Alias for #COATL_UCD_BLK_CJK_COMPAT
 * @var COATL_UCD_BLK_CJK_COMPAT_FORMS
 *      '**CJK_Compat_Forms**', '**CJK_Compatibility_Forms**'
 * @var COATL_UCD_BLK_CJK_COMPATIBILITY_FORMS
 *      Alias for #COATL_UCD_BLK_CJK_COMPAT_FORMS
 * @var COATL_UCD_BLK_CJK_COMPAT_IDEOGRAPHS
 *      '**CJK_Compat_Ideographs**', '**CJK_Compatibility_Ideographs**'
 * @var COATL_UCD_BLK_CJK_COMPATIBILITY_IDEOGRAPHS
 *      Alias for #COATL_UCD_BLK_CJK_COMPAT_IDEOGRAPHS
 * @var COATL_UCD_BLK_CJK_COMPAT_IDEOGRAPHS_SUP
 *      '**CJK_Compat_Ideographs_Sup**', '**CJK_Compatibility_Ideographs_Supplement**'
 * @var COATL_UCD_BLK_CJK_COMPATIBILITY_IDEOGRAPHS_SUPPLEMENT
 *      Alias for #COATL_UCD_BLK_CJK_COMPAT_IDEOGRAPHS_SUP
 * @var COATL_UCD_BLK_CJK_EXT_A
 *      '**CJK_Ext_A**', '**CJK_Unified_Ideographs_Extension_A**'
 * @var COATL_UCD_BLK_CJK_UNIFIED_IDEOGRAPHS_EXTENSION_A
 *      Alias for #COATL_UCD_BLK_CJK_EXT_A
 * @var COATL_UCD_BLK_CJK_EXT_B
 *      '**CJK_Ext_B**', '**CJK_Unified_Ideographs_Extension_B**'
 * @var COATL_UCD_BLK_CJK_UNIFIED_IDEOGRAPHS_EXTENSION_B
 *      Alias for #COATL_UCD_BLK_CJK_EXT_B
 * @var COATL_UCD_BLK_CJK_EXT_C
 *      '**CJK_Ext_C**', '**CJK_Unified_Ideographs_Extension_C**'
 * @var COATL_UCD_BLK_CJK_UNIFIED_IDEOGRAPHS_EXTENSION_C
 *      Alias for #COATL_UCD_BLK_CJK_EXT_C
 * @var COATL_UCD_BLK_CJK_EXT_D
 *      '**CJK_Ext_D**', '**CJK_Unified_Ideographs_Extension_D**'
 * @var COATL_UCD_BLK_CJK_UNIFIED_IDEOGRAPHS_EXTENSION_D
 *      Alias for #COATL_UCD_BLK_CJK_EXT_D
 * @var COATL_UCD_BLK_CJK_EXT_E
 *      '**CJK_Ext_E**', '**CJK_Unified_Ideographs_Extension_E**'
 * @var COATL_UCD_BLK_CJK_UNIFIED_IDEOGRAPHS_EXTENSION_E
 *      Alias for #COATL_UCD_BLK_CJK_EXT_E
 * @var COATL_UCD_BLK_CJK_RADICALS_SUP
 *      '**CJK_Radicals_Sup**', '**CJK_Radicals_Supplement**'
 * @var COATL_UCD_BLK_CJK_RADICALS_SUPPLEMENT
 *      Alias for #COATL_UCD_BLK_CJK_RADICALS_SUP
 * @var COATL_UCD_BLK_CJK_STROKES
 *      '**CJK_Strokes**'
 * @var COATL_UCD_BLK_CJK_SYMBOLS
 *      '**CJK_Symbols**', '**CJK_Symbols_And_Punctuation**'
 * @var COATL_UCD_BLK_CJK_SYMBOLS_AND_PUNCTUATION
 *      Alias for #COATL_UCD_BLK_CJK_SYMBOLS
 * @var COATL_UCD_BLK_COMPAT_JAMO
 *      '**Compat_Jamo**', '**Hangul_Compatibility_Jamo**'
 * @var COATL_UCD_BLK_HANGUL_COMPATIBILITY_JAMO
 *      Alias for #COATL_UCD_BLK_COMPAT_JAMO
 * @var COATL_UCD_BLK_CONTROL_PICTURES
 *      '**Control_Pictures**'
 * @var COATL_UCD_BLK_COPTIC
 *      '**Coptic**'
 * @var COATL_UCD_BLK_COPTIC_EPACT_NUMBERS
 *      '**Coptic_Epact_Numbers**'
 * @var COATL_UCD_BLK_COUNTING_ROD
 *      '**Counting_Rod**', '**Counting_Rod_Numerals**'
 * @var COATL_UCD_BLK_COUNTING_ROD_NUMERALS
 *      Alias for #COATL_UCD_BLK_COUNTING_ROD
 * @var COATL_UCD_BLK_CUNEIFORM
 *      '**Cuneiform**'
 * @var COATL_UCD_BLK_CUNEIFORM_NUMBERS
 *      '**Cuneiform_Numbers**', '**Cuneiform_Numbers_And_Punctuation**'
 * @var COATL_UCD_BLK_CUNEIFORM_NUMBERS_AND_PUNCTUATION
 *      Alias for #COATL_UCD_BLK_CUNEIFORM_NUMBERS
 * @var COATL_UCD_BLK_CURRENCY_SYMBOLS
 *      '**Currency_Symbols**'
 * @var COATL_UCD_BLK_CYPRIOT_SYLLABARY
 *      '**Cypriot_Syllabary**'
 * @var COATL_UCD_BLK_CYRILLIC
 *      '**Cyrillic**'
 * @var COATL_UCD_BLK_CYRILLIC_EXT_A
 *      '**Cyrillic_Ext_A**', '**Cyrillic_Extended_A**'
 * @var COATL_UCD_BLK_CYRILLIC_EXTENDED_A
 *      Alias for #COATL_UCD_BLK_CYRILLIC_EXT_A
 * @var COATL_UCD_BLK_CYRILLIC_EXT_B
 *      '**Cyrillic_Ext_B**', '**Cyrillic_Extended_B**'
 * @var COATL_UCD_BLK_CYRILLIC_EXTENDED_B
 *      Alias for #COATL_UCD_BLK_CYRILLIC_EXT_B
 * @var COATL_UCD_BLK_CYRILLIC_EXT_C
 *      '**Cyrillic_Ext_C**', '**Cyrillic_Extended_C**'
 * @var COATL_UCD_BLK_CYRILLIC_EXTENDED_C
 *      Alias for #COATL_UCD_BLK_CYRILLIC_EXT_C
 * @var COATL_UCD_BLK_CYRILLIC_SUP
 *      '**Cyrillic_Sup**', '**Cyrillic_Supplement**', '**Cyrillic_Supplementary**'
 * @var COATL_UCD_BLK_CYRILLIC_SUPPLEMENT
 *      Alias for #COATL_UCD_BLK_CYRILLIC_SUP
 * @var COATL_UCD_BLK_CYRILLIC_SUPPLEMENTARY
 *      Alias for #COATL_UCD_BLK_CYRILLIC_SUP
 * @var COATL_UCD_BLK_DESERET
 *      '**Deseret**'
 * @var COATL_UCD_BLK_DEVANAGARI
 *      '**Devanagari**'
 * @var COATL_UCD_BLK_DEVANAGARI_EXT
 *      '**Devanagari_Ext**', '**Devanagari_Extended**'
 * @var COATL_UCD_BLK_DEVANAGARI_EXTENDED
 *      Alias for #COATL_UCD_BLK_DEVANAGARI_EXT
 * @var COATL_UCD_BLK_DIACRITICALS
 *      '**Diacriticals**', '**Combining_Diacritical_Marks**'
 * @var COATL_UCD_BLK_COMBINING_DIACRITICAL_MARKS
 *      Alias for #COATL_UCD_BLK_DIACRITICALS
 * @var COATL_UCD_BLK_DIACRITICALS_EXT
 *      '**Diacriticals_Ext**', '**Combining_Diacritical_Marks_Extended**'
 * @var COATL_UCD_BLK_COMBINING_DIACRITICAL_MARKS_EXTENDED
 *      Alias for #COATL_UCD_BLK_DIACRITICALS_EXT
 * @var COATL_UCD_BLK_DIACRITICALS_FOR_SYMBOLS
 *      '**Diacriticals_For_Symbols**', '**Combining_Diacritical_Marks_For_Symbols**', '**Combining_Marks_For_Symbols**'
 * @var COATL_UCD_BLK_COMBINING_DIACRITICAL_MARKS_FOR_SYMBOLS
 *      Alias for #COATL_UCD_BLK_DIACRITICALS_FOR_SYMBOLS
 * @var COATL_UCD_BLK_COMBINING_MARKS_FOR_SYMBOLS
 *      Alias for #COATL_UCD_BLK_DIACRITICALS_FOR_SYMBOLS
 * @var COATL_UCD_BLK_DIACRITICALS_SUP
 *      '**Diacriticals_Sup**', '**Combining_Diacritical_Marks_Supplement**'
 * @var COATL_UCD_BLK_COMBINING_DIACRITICAL_MARKS_SUPPLEMENT
 *      Alias for #COATL_UCD_BLK_DIACRITICALS_SUP
 * @var COATL_UCD_BLK_DINGBATS
 *      '**Dingbats**'
 * @var COATL_UCD_BLK_DOMINO
 *      '**Domino**', '**Domino_Tiles**'
 * @var COATL_UCD_BLK_DOMINO_TILES
 *      Alias for #COATL_UCD_BLK_DOMINO
 * @var COATL_UCD_BLK_DUPLOYAN
 *      '**Duployan**'
 * @var COATL_UCD_BLK_EARLY_DYNASTIC_CUNEIFORM
 *      '**Early_Dynastic_Cuneiform**'
 * @var COATL_UCD_BLK_EGYPTIAN_HIEROGLYPHS
 *      '**Egyptian_Hieroglyphs**'
 * @var COATL_UCD_BLK_ELBASAN
 *      '**Elbasan**'
 * @var COATL_UCD_BLK_EMOTICONS
 *      '**Emoticons**'
 * @var COATL_UCD_BLK_ENCLOSED_ALPHANUM
 *      '**Enclosed_Alphanum**', '**Enclosed_Alphanumerics**'
 * @var COATL_UCD_BLK_ENCLOSED_ALPHANUMERICS
 *      Alias for #COATL_UCD_BLK_ENCLOSED_ALPHANUM
 * @var COATL_UCD_BLK_ENCLOSED_ALPHANUM_SUP
 *      '**Enclosed_Alphanum_Sup**', '**Enclosed_Alphanumeric_Supplement**'
 * @var COATL_UCD_BLK_ENCLOSED_ALPHANUMERIC_SUPPLEMENT
 *      Alias for #COATL_UCD_BLK_ENCLOSED_ALPHANUM_SUP
 * @var COATL_UCD_BLK_ENCLOSED_CJK
 *      '**Enclosed_CJK**', '**Enclosed_CJK_Letters_And_Months**'
 * @var COATL_UCD_BLK_ENCLOSED_CJK_LETTERS_AND_MONTHS
 *      Alias for #COATL_UCD_BLK_ENCLOSED_CJK
 * @var COATL_UCD_BLK_ENCLOSED_IDEOGRAPHIC_SUP
 *      '**Enclosed_Ideographic_Sup**', '**Enclosed_Ideographic_Supplement**'
 * @var COATL_UCD_BLK_ENCLOSED_IDEOGRAPHIC_SUPPLEMENT
 *      Alias for #COATL_UCD_BLK_ENCLOSED_IDEOGRAPHIC_SUP
 * @var COATL_UCD_BLK_ETHIOPIC
 *      '**Ethiopic**'
 * @var COATL_UCD_BLK_ETHIOPIC_EXT
 *      '**Ethiopic_Ext**', '**Ethiopic_Extended**'
 * @var COATL_UCD_BLK_ETHIOPIC_EXTENDED
 *      Alias for #COATL_UCD_BLK_ETHIOPIC_EXT
 * @var COATL_UCD_BLK_ETHIOPIC_EXT_A
 *      '**Ethiopic_Ext_A**', '**Ethiopic_Extended_A**'
 * @var COATL_UCD_BLK_ETHIOPIC_EXTENDED_A
 *      Alias for #COATL_UCD_BLK_ETHIOPIC_EXT_A
 * @var COATL_UCD_BLK_ETHIOPIC_SUP
 *      '**Ethiopic_Sup**', '**Ethiopic_Supplement**'
 * @var COATL_UCD_BLK_ETHIOPIC_SUPPLEMENT
 *      Alias for #COATL_UCD_BLK_ETHIOPIC_SUP
 * @var COATL_UCD_BLK_GEOMETRIC_SHAPES
 *      '**Geometric_Shapes**'
 * @var COATL_UCD_BLK_GEOMETRIC_SHAPES_EXT
 *      '**Geometric_Shapes_Ext**', '**Geometric_Shapes_Extended**'
 * @var COATL_UCD_BLK_GEOMETRIC_SHAPES_EXTENDED
 *      Alias for #COATL_UCD_BLK_GEOMETRIC_SHAPES_EXT
 * @var COATL_UCD_BLK_GEORGIAN
 *      '**Georgian**'
 * @var COATL_UCD_BLK_GEORGIAN_SUP
 *      '**Georgian_Sup**', '**Georgian_Supplement**'
 * @var COATL_UCD_BLK_GEORGIAN_SUPPLEMENT
 *      Alias for #COATL_UCD_BLK_GEORGIAN_SUP
 * @var COATL_UCD_BLK_GLAGOLITIC
 *      '**Glagolitic**'
 * @var COATL_UCD_BLK_GLAGOLITIC_SUP
 *      '**Glagolitic_Sup**', '**Glagolitic_Supplement**'
 * @var COATL_UCD_BLK_GLAGOLITIC_SUPPLEMENT
 *      Alias for #COATL_UCD_BLK_GLAGOLITIC_SUP
 * @var COATL_UCD_BLK_GOTHIC
 *      '**Gothic**'
 * @var COATL_UCD_BLK_GRANTHA
 *      '**Grantha**'
 * @var COATL_UCD_BLK_GREEK
 *      '**Greek**', '**Greek_And_Coptic**'
 * @var COATL_UCD_BLK_GREEK_AND_COPTIC
 *      Alias for #COATL_UCD_BLK_GREEK
 * @var COATL_UCD_BLK_GREEK_EXT
 *      '**Greek_Ext**', '**Greek_Extended**'
 * @var COATL_UCD_BLK_GREEK_EXTENDED
 *      Alias for #COATL_UCD_BLK_GREEK_EXT
 * @var COATL_UCD_BLK_GUJARATI
 *      '**Gujarati**'
 * @var COATL_UCD_BLK_GURMUKHI
 *      '**Gurmukhi**'
 * @var COATL_UCD_BLK_HALF_AND_FULL_FORMS
 *      '**Half_And_Full_Forms**', '**Halfwidth_And_Fullwidth_Forms**'
 * @var COATL_UCD_BLK_HALFWIDTH_AND_FULLWIDTH_FORMS
 *      Alias for #COATL_UCD_BLK_HALF_AND_FULL_FORMS
 * @var COATL_UCD_BLK_HALF_MARKS
 *      '**Half_Marks**', '**Combining_Half_Marks**'
 * @var COATL_UCD_BLK_COMBINING_HALF_MARKS
 *      Alias for #COATL_UCD_BLK_HALF_MARKS
 * @var COATL_UCD_BLK_HANGUL
 *      '**Hangul**', '**Hangul_Syllables**'
 * @var COATL_UCD_BLK_HANGUL_SYLLABLES
 *      Alias for #COATL_UCD_BLK_HANGUL
 * @var COATL_UCD_BLK_HANUNOO
 *      '**Hanunoo**'
 * @var COATL_UCD_BLK_HATRAN
 *      '**Hatran**'
 * @var COATL_UCD_BLK_HEBREW
 *      '**Hebrew**'
 * @var COATL_UCD_BLK_HIGH_PU_SURROGATES
 *      '**High_PU_Surrogates**', '**High_Private_Use_Surrogates**'
 * @var COATL_UCD_BLK_HIGH_PRIVATE_USE_SURROGATES
 *      Alias for #COATL_UCD_BLK_HIGH_PU_SURROGATES
 * @var COATL_UCD_BLK_HIGH_SURROGATES
 *      '**High_Surrogates**'
 * @var COATL_UCD_BLK_HIRAGANA
 *      '**Hiragana**'
 * @var COATL_UCD_BLK_IDC
 *      '**IDC**', '**Ideographic_Description_Characters**'
 * @var COATL_UCD_BLK_IDEOGRAPHIC_DESCRIPTION_CHARACTERS
 *      Alias for #COATL_UCD_BLK_IDC
 * @var COATL_UCD_BLK_IDEOGRAPHIC_SYMBOLS
 *      '**Ideographic_Symbols**', '**Ideographic_Symbols_And_Punctuation**'
 * @var COATL_UCD_BLK_IDEOGRAPHIC_SYMBOLS_AND_PUNCTUATION
 *      Alias for #COATL_UCD_BLK_IDEOGRAPHIC_SYMBOLS
 * @var COATL_UCD_BLK_IMPERIAL_ARAMAIC
 *      '**Imperial_Aramaic**'
 * @var COATL_UCD_BLK_INDIC_NUMBER_FORMS
 *      '**Indic_Number_Forms**', '**Common_Indic_Number_Forms**'
 * @var COATL_UCD_BLK_COMMON_INDIC_NUMBER_FORMS
 *      Alias for #COATL_UCD_BLK_INDIC_NUMBER_FORMS
 * @var COATL_UCD_BLK_INSCRIPTIONAL_PAHLAVI
 *      '**Inscriptional_Pahlavi**'
 * @var COATL_UCD_BLK_INSCRIPTIONAL_PARTHIAN
 *      '**Inscriptional_Parthian**'
 * @var COATL_UCD_BLK_IPA_EXT
 *      '**IPA_Ext**', '**IPA_Extensions**'
 * @var COATL_UCD_BLK_IPA_EXTENSIONS
 *      Alias for #COATL_UCD_BLK_IPA_EXT
 * @var COATL_UCD_BLK_JAMO
 *      '**Jamo**', '**Hangul_Jamo**'
 * @var COATL_UCD_BLK_HANGUL_JAMO
 *      Alias for #COATL_UCD_BLK_JAMO
 * @var COATL_UCD_BLK_JAMO_EXT_A
 *      '**Jamo_Ext_A**', '**Hangul_Jamo_Extended_A**'
 * @var COATL_UCD_BLK_HANGUL_JAMO_EXTENDED_A
 *      Alias for #COATL_UCD_BLK_JAMO_EXT_A
 * @var COATL_UCD_BLK_JAMO_EXT_B
 *      '**Jamo_Ext_B**', '**Hangul_Jamo_Extended_B**'
 * @var COATL_UCD_BLK_HANGUL_JAMO_EXTENDED_B
 *      Alias for #COATL_UCD_BLK_JAMO_EXT_B
 * @var COATL_UCD_BLK_JAVANESE
 *      '**Javanese**'
 * @var COATL_UCD_BLK_KAITHI
 *      '**Kaithi**'
 * @var COATL_UCD_BLK_KANA_SUP
 *      '**Kana_Sup**', '**Kana_Supplement**'
 * @var COATL_UCD_BLK_KANA_SUPPLEMENT
 *      Alias for #COATL_UCD_BLK_KANA_SUP
 * @var COATL_UCD_BLK_KANBUN
 *      '**Kanbun**'
 * @var COATL_UCD_BLK_KANGXI
 *      '**Kangxi**', '**Kangxi_Radicals**'
 * @var COATL_UCD_BLK_KANGXI_RADICALS
 *      Alias for #COATL_UCD_BLK_KANGXI
 * @var COATL_UCD_BLK_KANNADA
 *      '**Kannada**'
 * @var COATL_UCD_BLK_KATAKANA
 *      '**Katakana**'
 * @var COATL_UCD_BLK_KATAKANA_EXT
 *      '**Katakana_Ext**', '**Katakana_Phonetic_Extensions**'
 * @var COATL_UCD_BLK_KATAKANA_PHONETIC_EXTENSIONS
 *      Alias for #COATL_UCD_BLK_KATAKANA_EXT
 * @var COATL_UCD_BLK_KAYAH_LI
 *      '**Kayah_Li**'
 * @var COATL_UCD_BLK_KHAROSHTHI
 *      '**Kharoshthi**'
 * @var COATL_UCD_BLK_KHMER
 *      '**Khmer**'
 * @var COATL_UCD_BLK_KHMER_SYMBOLS
 *      '**Khmer_Symbols**'
 * @var COATL_UCD_BLK_KHOJKI
 *      '**Khojki**'
 * @var COATL_UCD_BLK_KHUDAWADI
 *      '**Khudawadi**'
 * @var COATL_UCD_BLK_LAO
 *      '**Lao**'
 * @var COATL_UCD_BLK_LATIN_1_SUP
 *      '**Latin_1_Sup**', '**Latin_1_Supplement**', '**Latin_1**'
 * @var COATL_UCD_BLK_LATIN_1_SUPPLEMENT
 *      Alias for #COATL_UCD_BLK_LATIN_1_SUP
 * @var COATL_UCD_BLK_LATIN_1
 *      Alias for #COATL_UCD_BLK_LATIN_1_SUP
 * @var COATL_UCD_BLK_LATIN_EXT_A
 *      '**Latin_Ext_A**', '**Latin_Extended_A**'
 * @var COATL_UCD_BLK_LATIN_EXTENDED_A
 *      Alias for #COATL_UCD_BLK_LATIN_EXT_A
 * @var COATL_UCD_BLK_LATIN_EXT_ADDITIONAL
 *      '**Latin_Ext_Additional**', '**Latin_Extended_Additional**'
 * @var COATL_UCD_BLK_LATIN_EXTENDED_ADDITIONAL
 *      Alias for #COATL_UCD_BLK_LATIN_EXT_ADDITIONAL
 * @var COATL_UCD_BLK_LATIN_EXT_B
 *      '**Latin_Ext_B**', '**Latin_Extended_B**'
 * @var COATL_UCD_BLK_LATIN_EXTENDED_B
 *      Alias for #COATL_UCD_BLK_LATIN_EXT_B
 * @var COATL_UCD_BLK_LATIN_EXT_C
 *      '**Latin_Ext_C**', '**Latin_Extended_C**'
 * @var COATL_UCD_BLK_LATIN_EXTENDED_C
 *      Alias for #COATL_UCD_BLK_LATIN_EXT_C
 * @var COATL_UCD_BLK_LATIN_EXT_D
 *      '**Latin_Ext_D**', '**Latin_Extended_D**'
 * @var COATL_UCD_BLK_LATIN_EXTENDED_D
 *      Alias for #COATL_UCD_BLK_LATIN_EXT_D
 * @var COATL_UCD_BLK_LATIN_EXT_E
 *      '**Latin_Ext_E**', '**Latin_Extended_E**'
 * @var COATL_UCD_BLK_LATIN_EXTENDED_E
 *      Alias for #COATL_UCD_BLK_LATIN_EXT_E
 * @var COATL_UCD_BLK_LEPCHA
 *      '**Lepcha**'
 * @var COATL_UCD_BLK_LETTERLIKE_SYMBOLS
 *      '**Letterlike_Symbols**'
 * @var COATL_UCD_BLK_LIMBU
 *      '**Limbu**'
 * @var COATL_UCD_BLK_LINEAR_A
 *      '**Linear_A**'
 * @var COATL_UCD_BLK_LINEAR_B_IDEOGRAMS
 *      '**Linear_B_Ideograms**'
 * @var COATL_UCD_BLK_LINEAR_B_SYLLABARY
 *      '**Linear_B_Syllabary**'
 * @var COATL_UCD_BLK_LISU
 *      '**Lisu**'
 * @var COATL_UCD_BLK_LOW_SURROGATES
 *      '**Low_Surrogates**'
 * @var COATL_UCD_BLK_LYCIAN
 *      '**Lycian**'
 * @var COATL_UCD_BLK_LYDIAN
 *      '**Lydian**'
 * @var COATL_UCD_BLK_MAHAJANI
 *      '**Mahajani**'
 * @var COATL_UCD_BLK_MAHJONG
 *      '**Mahjong**', '**Mahjong_Tiles**'
 * @var COATL_UCD_BLK_MAHJONG_TILES
 *      Alias for #COATL_UCD_BLK_MAHJONG
 * @var COATL_UCD_BLK_MALAYALAM
 *      '**Malayalam**'
 * @var COATL_UCD_BLK_MANDAIC
 *      '**Mandaic**'
 * @var COATL_UCD_BLK_MANICHAEAN
 *      '**Manichaean**'
 * @var COATL_UCD_BLK_MARCHEN
 *      '**Marchen**'
 * @var COATL_UCD_BLK_MATH_ALPHANUM
 *      '**Math_Alphanum**', '**Mathematical_Alphanumeric_Symbols**'
 * @var COATL_UCD_BLK_MATHEMATICAL_ALPHANUMERIC_SYMBOLS
 *      Alias for #COATL_UCD_BLK_MATH_ALPHANUM
 * @var COATL_UCD_BLK_MATH_OPERATORS
 *      '**Math_Operators**', '**Mathematical_Operators**'
 * @var COATL_UCD_BLK_MATHEMATICAL_OPERATORS
 *      Alias for #COATL_UCD_BLK_MATH_OPERATORS
 * @var COATL_UCD_BLK_MEETEI_MAYEK
 *      '**Meetei_Mayek**'
 * @var COATL_UCD_BLK_MEETEI_MAYEK_EXT
 *      '**Meetei_Mayek_Ext**', '**Meetei_Mayek_Extensions**'
 * @var COATL_UCD_BLK_MEETEI_MAYEK_EXTENSIONS
 *      Alias for #COATL_UCD_BLK_MEETEI_MAYEK_EXT
 * @var COATL_UCD_BLK_MENDE_KIKAKUI
 *      '**Mende_Kikakui**'
 * @var COATL_UCD_BLK_MEROITIC_CURSIVE
 *      '**Meroitic_Cursive**'
 * @var COATL_UCD_BLK_MEROITIC_HIEROGLYPHS
 *      '**Meroitic_Hieroglyphs**'
 * @var COATL_UCD_BLK_MIAO
 *      '**Miao**'
 * @var COATL_UCD_BLK_MISC_ARROWS
 *      '**Misc_Arrows**', '**Miscellaneous_Symbols_And_Arrows**'
 * @var COATL_UCD_BLK_MISCELLANEOUS_SYMBOLS_AND_ARROWS
 *      Alias for #COATL_UCD_BLK_MISC_ARROWS
 * @var COATL_UCD_BLK_MISC_MATH_SYMBOLS_A
 *      '**Misc_Math_Symbols_A**', '**Miscellaneous_Mathematical_Symbols_A**'
 * @var COATL_UCD_BLK_MISCELLANEOUS_MATHEMATICAL_SYMBOLS_A
 *      Alias for #COATL_UCD_BLK_MISC_MATH_SYMBOLS_A
 * @var COATL_UCD_BLK_MISC_MATH_SYMBOLS_B
 *      '**Misc_Math_Symbols_B**', '**Miscellaneous_Mathematical_Symbols_B**'
 * @var COATL_UCD_BLK_MISCELLANEOUS_MATHEMATICAL_SYMBOLS_B
 *      Alias for #COATL_UCD_BLK_MISC_MATH_SYMBOLS_B
 * @var COATL_UCD_BLK_MISC_PICTOGRAPHS
 *      '**Misc_Pictographs**', '**Miscellaneous_Symbols_And_Pictographs**'
 * @var COATL_UCD_BLK_MISCELLANEOUS_SYMBOLS_AND_PICTOGRAPHS
 *      Alias for #COATL_UCD_BLK_MISC_PICTOGRAPHS
 * @var COATL_UCD_BLK_MISC_SYMBOLS
 *      '**Misc_Symbols**', '**Miscellaneous_Symbols**'
 * @var COATL_UCD_BLK_MISCELLANEOUS_SYMBOLS
 *      Alias for #COATL_UCD_BLK_MISC_SYMBOLS
 * @var COATL_UCD_BLK_MISC_TECHNICAL
 *      '**Misc_Technical**', '**Miscellaneous_Technical**'
 * @var COATL_UCD_BLK_MISCELLANEOUS_TECHNICAL
 *      Alias for #COATL_UCD_BLK_MISC_TECHNICAL
 * @var COATL_UCD_BLK_MODI
 *      '**Modi**'
 * @var COATL_UCD_BLK_MODIFIER_LETTERS
 *      '**Modifier_Letters**', '**Spacing_Modifier_Letters**'
 * @var COATL_UCD_BLK_SPACING_MODIFIER_LETTERS
 *      Alias for #COATL_UCD_BLK_MODIFIER_LETTERS
 * @var COATL_UCD_BLK_MODIFIER_TONE_LETTERS
 *      '**Modifier_Tone_Letters**'
 * @var COATL_UCD_BLK_MONGOLIAN
 *      '**Mongolian**'
 * @var COATL_UCD_BLK_MONGOLIAN_SUP
 *      '**Mongolian_Sup**', '**Mongolian_Supplement**'
 * @var COATL_UCD_BLK_MONGOLIAN_SUPPLEMENT
 *      Alias for #COATL_UCD_BLK_MONGOLIAN_SUP
 * @var COATL_UCD_BLK_MRO
 *      '**Mro**'
 * @var COATL_UCD_BLK_MULTANI
 *      '**Multani**'
 * @var COATL_UCD_BLK_MUSIC
 *      '**Music**', '**Musical_Symbols**'
 * @var COATL_UCD_BLK_MUSICAL_SYMBOLS
 *      Alias for #COATL_UCD_BLK_MUSIC
 * @var COATL_UCD_BLK_MYANMAR
 *      '**Myanmar**'
 * @var COATL_UCD_BLK_MYANMAR_EXT_A
 *      '**Myanmar_Ext_A**', '**Myanmar_Extended_A**'
 * @var COATL_UCD_BLK_MYANMAR_EXTENDED_A
 *      Alias for #COATL_UCD_BLK_MYANMAR_EXT_A
 * @var COATL_UCD_BLK_MYANMAR_EXT_B
 *      '**Myanmar_Ext_B**', '**Myanmar_Extended_B**'
 * @var COATL_UCD_BLK_MYANMAR_EXTENDED_B
 *      Alias for #COATL_UCD_BLK_MYANMAR_EXT_B
 * @var COATL_UCD_BLK_NABATAEAN
 *      '**Nabataean**'
 * @var COATL_UCD_BLK_NB
 *      '**NB**', '**No_Block**'
 * @var COATL_UCD_BLK_NO_BLOCK
 *      Alias for #COATL_UCD_BLK_NB
 * @var COATL_UCD_BLK_NEW_TAI_LUE
 *      '**New_Tai_Lue**'
 * @var COATL_UCD_BLK_NEWA
 *      '**Newa**'
 * @var COATL_UCD_BLK_NKO
 *      '**NKo**'
 * @var COATL_UCD_BLK_NUMBER_FORMS
 *      '**Number_Forms**'
 * @var COATL_UCD_BLK_OCR
 *      '**OCR**', '**Optical_Character_Recognition**'
 * @var COATL_UCD_BLK_OPTICAL_CHARACTER_RECOGNITION
 *      Alias for #COATL_UCD_BLK_OCR
 * @var COATL_UCD_BLK_OGHAM
 *      '**Ogham**'
 * @var COATL_UCD_BLK_OL_CHIKI
 *      '**Ol_Chiki**'
 * @var COATL_UCD_BLK_OLD_HUNGARIAN
 *      '**Old_Hungarian**'
 * @var COATL_UCD_BLK_OLD_ITALIC
 *      '**Old_Italic**'
 * @var COATL_UCD_BLK_OLD_NORTH_ARABIAN
 *      '**Old_North_Arabian**'
 * @var COATL_UCD_BLK_OLD_PERMIC
 *      '**Old_Permic**'
 * @var COATL_UCD_BLK_OLD_PERSIAN
 *      '**Old_Persian**'
 * @var COATL_UCD_BLK_OLD_SOUTH_ARABIAN
 *      '**Old_South_Arabian**'
 * @var COATL_UCD_BLK_OLD_TURKIC
 *      '**Old_Turkic**'
 * @var COATL_UCD_BLK_ORIYA
 *      '**Oriya**'
 * @var COATL_UCD_BLK_ORNAMENTAL_DINGBATS
 *      '**Ornamental_Dingbats**'
 * @var COATL_UCD_BLK_OSAGE
 *      '**Osage**'
 * @var COATL_UCD_BLK_OSMANYA
 *      '**Osmanya**'
 * @var COATL_UCD_BLK_PAHAWH_HMONG
 *      '**Pahawh_Hmong**'
 * @var COATL_UCD_BLK_PALMYRENE
 *      '**Palmyrene**'
 * @var COATL_UCD_BLK_PAU_CIN_HAU
 *      '**Pau_Cin_Hau**'
 * @var COATL_UCD_BLK_PHAGS_PA
 *      '**Phags_Pa**'
 * @var COATL_UCD_BLK_PHAISTOS
 *      '**Phaistos**', '**Phaistos_Disc**'
 * @var COATL_UCD_BLK_PHAISTOS_DISC
 *      Alias for #COATL_UCD_BLK_PHAISTOS
 * @var COATL_UCD_BLK_PHOENICIAN
 *      '**Phoenician**'
 * @var COATL_UCD_BLK_PHONETIC_EXT
 *      '**Phonetic_Ext**', '**Phonetic_Extensions**'
 * @var COATL_UCD_BLK_PHONETIC_EXTENSIONS
 *      Alias for #COATL_UCD_BLK_PHONETIC_EXT
 * @var COATL_UCD_BLK_PHONETIC_EXT_SUP
 *      '**Phonetic_Ext_Sup**', '**Phonetic_Extensions_Supplement**'
 * @var COATL_UCD_BLK_PHONETIC_EXTENSIONS_SUPPLEMENT
 *      Alias for #COATL_UCD_BLK_PHONETIC_EXT_SUP
 * @var COATL_UCD_BLK_PLAYING_CARDS
 *      '**Playing_Cards**'
 * @var COATL_UCD_BLK_PSALTER_PAHLAVI
 *      '**Psalter_Pahlavi**'
 * @var COATL_UCD_BLK_PUA
 *      '**PUA**', '**Private_Use_Area**', '**Private_Use**'
 * @var COATL_UCD_BLK_PRIVATE_USE_AREA
 *      Alias for #COATL_UCD_BLK_PUA
 * @var COATL_UCD_BLK_PRIVATE_USE
 *      Alias for #COATL_UCD_BLK_PUA
 * @var COATL_UCD_BLK_PUNCTUATION
 *      '**Punctuation**', '**General_Punctuation**'
 * @var COATL_UCD_BLK_GENERAL_PUNCTUATION
 *      Alias for #COATL_UCD_BLK_PUNCTUATION
 * @var COATL_UCD_BLK_REJANG
 *      '**Rejang**'
 * @var COATL_UCD_BLK_RUMI
 *      '**Rumi**', '**Rumi_Numeral_Symbols**'
 * @var COATL_UCD_BLK_RUMI_NUMERAL_SYMBOLS
 *      Alias for #COATL_UCD_BLK_RUMI
 * @var COATL_UCD_BLK_RUNIC
 *      '**Runic**'
 * @var COATL_UCD_BLK_SAMARITAN
 *      '**Samaritan**'
 * @var COATL_UCD_BLK_SAURASHTRA
 *      '**Saurashtra**'
 * @var COATL_UCD_BLK_SHARADA
 *      '**Sharada**'
 * @var COATL_UCD_BLK_SHAVIAN
 *      '**Shavian**'
 * @var COATL_UCD_BLK_SHORTHAND_FORMAT_CONTROLS
 *      '**Shorthand_Format_Controls**'
 * @var COATL_UCD_BLK_SIDDHAM
 *      '**Siddham**'
 * @var COATL_UCD_BLK_SINHALA
 *      '**Sinhala**'
 * @var COATL_UCD_BLK_SINHALA_ARCHAIC_NUMBERS
 *      '**Sinhala_Archaic_Numbers**'
 * @var COATL_UCD_BLK_SMALL_FORMS
 *      '**Small_Forms**', '**Small_Form_Variants**'
 * @var COATL_UCD_BLK_SMALL_FORM_VARIANTS
 *      Alias for #COATL_UCD_BLK_SMALL_FORMS
 * @var COATL_UCD_BLK_SORA_SOMPENG
 *      '**Sora_Sompeng**'
 * @var COATL_UCD_BLK_SPECIALS
 *      '**Specials**'
 * @var COATL_UCD_BLK_SUNDANESE
 *      '**Sundanese**'
 * @var COATL_UCD_BLK_SUNDANESE_SUP
 *      '**Sundanese_Sup**', '**Sundanese_Supplement**'
 * @var COATL_UCD_BLK_SUNDANESE_SUPPLEMENT
 *      Alias for #COATL_UCD_BLK_SUNDANESE_SUP
 * @var COATL_UCD_BLK_SUP_ARROWS_A
 *      '**Sup_Arrows_A**', '**Supplemental_Arrows_A**'
 * @var COATL_UCD_BLK_SUPPLEMENTAL_ARROWS_A
 *      Alias for #COATL_UCD_BLK_SUP_ARROWS_A
 * @var COATL_UCD_BLK_SUP_ARROWS_B
 *      '**Sup_Arrows_B**', '**Supplemental_Arrows_B**'
 * @var COATL_UCD_BLK_SUPPLEMENTAL_ARROWS_B
 *      Alias for #COATL_UCD_BLK_SUP_ARROWS_B
 * @var COATL_UCD_BLK_SUP_ARROWS_C
 *      '**Sup_Arrows_C**', '**Supplemental_Arrows_C**'
 * @var COATL_UCD_BLK_SUPPLEMENTAL_ARROWS_C
 *      Alias for #COATL_UCD_BLK_SUP_ARROWS_C
 * @var COATL_UCD_BLK_SUP_MATH_OPERATORS
 *      '**Sup_Math_Operators**', '**Supplemental_Mathematical_Operators**'
 * @var COATL_UCD_BLK_SUPPLEMENTAL_MATHEMATICAL_OPERATORS
 *      Alias for #COATL_UCD_BLK_SUP_MATH_OPERATORS
 * @var COATL_UCD_BLK_SUP_PUA_A
 *      '**Sup_PUA_A**', '**Supplementary_Private_Use_Area_A**'
 * @var COATL_UCD_BLK_SUPPLEMENTARY_PRIVATE_USE_AREA_A
 *      Alias for #COATL_UCD_BLK_SUP_PUA_A
 * @var COATL_UCD_BLK_SUP_PUA_B
 *      '**Sup_PUA_B**', '**Supplementary_Private_Use_Area_B**'
 * @var COATL_UCD_BLK_SUPPLEMENTARY_PRIVATE_USE_AREA_B
 *      Alias for #COATL_UCD_BLK_SUP_PUA_B
 * @var COATL_UCD_BLK_SUP_PUNCTUATION
 *      '**Sup_Punctuation**', '**Supplemental_Punctuation**'
 * @var COATL_UCD_BLK_SUPPLEMENTAL_PUNCTUATION
 *      Alias for #COATL_UCD_BLK_SUP_PUNCTUATION
 * @var COATL_UCD_BLK_SUP_SYMBOLS_AND_PICTOGRAPHS
 *      '**Sup_Symbols_And_Pictographs**', '**Supplemental_Symbols_And_Pictographs**'
 * @var COATL_UCD_BLK_SUPPLEMENTAL_SYMBOLS_AND_PICTOGRAPHS
 *      Alias for #COATL_UCD_BLK_SUP_SYMBOLS_AND_PICTOGRAPHS
 * @var COATL_UCD_BLK_SUPER_AND_SUB
 *      '**Super_And_Sub**', '**Superscripts_And_Subscripts**'
 * @var COATL_UCD_BLK_SUPERSCRIPTS_AND_SUBSCRIPTS
 *      Alias for #COATL_UCD_BLK_SUPER_AND_SUB
 * @var COATL_UCD_BLK_SUTTON_SIGNWRITING
 *      '**Sutton_SignWriting**'
 * @var COATL_UCD_BLK_SYLOTI_NAGRI
 *      '**Syloti_Nagri**'
 * @var COATL_UCD_BLK_SYRIAC
 *      '**Syriac**'
 * @var COATL_UCD_BLK_TAGALOG
 *      '**Tagalog**'
 * @var COATL_UCD_BLK_TAGBANWA
 *      '**Tagbanwa**'
 * @var COATL_UCD_BLK_TAGS
 *      '**Tags**'
 * @var COATL_UCD_BLK_TAI_LE
 *      '**Tai_Le**'
 * @var COATL_UCD_BLK_TAI_THAM
 *      '**Tai_Tham**'
 * @var COATL_UCD_BLK_TAI_VIET
 *      '**Tai_Viet**'
 * @var COATL_UCD_BLK_TAI_XUAN_JING
 *      '**Tai_Xuan_Jing**', '**Tai_Xuan_Jing_Symbols**'
 * @var COATL_UCD_BLK_TAI_XUAN_JING_SYMBOLS
 *      Alias for #COATL_UCD_BLK_TAI_XUAN_JING
 * @var COATL_UCD_BLK_TAKRI
 *      '**Takri**'
 * @var COATL_UCD_BLK_TAMIL
 *      '**Tamil**'
 * @var COATL_UCD_BLK_TANGUT
 *      '**Tangut**'
 * @var COATL_UCD_BLK_TANGUT_COMPONENTS
 *      '**Tangut_Components**'
 * @var COATL_UCD_BLK_TELUGU
 *      '**Telugu**'
 * @var COATL_UCD_BLK_THAANA
 *      '**Thaana**'
 * @var COATL_UCD_BLK_THAI
 *      '**Thai**'
 * @var COATL_UCD_BLK_TIBETAN
 *      '**Tibetan**'
 * @var COATL_UCD_BLK_TIFINAGH
 *      '**Tifinagh**'
 * @var COATL_UCD_BLK_TIRHUTA
 *      '**Tirhuta**'
 * @var COATL_UCD_BLK_TRANSPORT_AND_MAP
 *      '**Transport_And_Map**', '**Transport_And_Map_Symbols**'
 * @var COATL_UCD_BLK_TRANSPORT_AND_MAP_SYMBOLS
 *      Alias for #COATL_UCD_BLK_TRANSPORT_AND_MAP
 * @var COATL_UCD_BLK_UCAS
 *      '**UCAS**', '**Unified_Canadian_Aboriginal_Syllabics**', '**Canadian_Syllabics**'
 * @var COATL_UCD_BLK_UNIFIED_CANADIAN_ABORIGINAL_SYLLABICS
 *      Alias for #COATL_UCD_BLK_UCAS
 * @var COATL_UCD_BLK_CANADIAN_SYLLABICS
 *      Alias for #COATL_UCD_BLK_UCAS
 * @var COATL_UCD_BLK_UCAS_EXT
 *      '**UCAS_Ext**', '**Unified_Canadian_Aboriginal_Syllabics_Extended**'
 * @var COATL_UCD_BLK_UNIFIED_CANADIAN_ABORIGINAL_SYLLABICS_EXTENDED
 *      Alias for #COATL_UCD_BLK_UCAS_EXT
 * @var COATL_UCD_BLK_UGARITIC
 *      '**Ugaritic**'
 * @var COATL_UCD_BLK_VAI
 *      '**Vai**'
 * @var COATL_UCD_BLK_VEDIC_EXT
 *      '**Vedic_Ext**', '**Vedic_Extensions**'
 * @var COATL_UCD_BLK_VEDIC_EXTENSIONS
 *      Alias for #COATL_UCD_BLK_VEDIC_EXT
 * @var COATL_UCD_BLK_VERTICAL_FORMS
 *      '**Vertical_Forms**'
 * @var COATL_UCD_BLK_VS
 *      '**VS**', '**Variation_Selectors**'
 * @var COATL_UCD_BLK_VARIATION_SELECTORS
 *      Alias for #COATL_UCD_BLK_VS
 * @var COATL_UCD_BLK_VS_SUP
 *      '**VS_Sup**', '**Variation_Selectors_Supplement**'
 * @var COATL_UCD_BLK_VARIATION_SELECTORS_SUPPLEMENT
 *      Alias for #COATL_UCD_BLK_VS_SUP
 * @var COATL_UCD_BLK_WARANG_CITI
 *      '**Warang_Citi**'
 * @var COATL_UCD_BLK_YI_RADICALS
 *      '**Yi_Radicals**'
 * @var COATL_UCD_BLK_YI_SYLLABLES
 *      '**Yi_Syllables**'
 * @var COATL_UCD_BLK_YIJING
 *      '**Yijing**', '**Yijing_Hexagram_Symbols**'
 * @var COATL_UCD_BLK_YIJING_HEXAGRAM_SYMBOLS
 *      Alias for #COATL_UCD_BLK_YIJING
 */
typedef enum Coatl_Ucd_Blk {
    COATL_UCD_BLK_ADLAM=1,
    COATL_UCD_BLK_AEGEAN_NUMBERS=2,
    COATL_UCD_BLK_AHOM=3,
    COATL_UCD_BLK_ALCHEMICAL=4,
        COATL_UCD_BLK_ALCHEMICAL_SYMBOLS=COATL_UCD_BLK_ALCHEMICAL,
    COATL_UCD_BLK_ALPHABETIC_PF=5,
        COATL_UCD_BLK_ALPHABETIC_PRESENTATION_FORMS=COATL_UCD_BLK_ALPHABETIC_PF,
    COATL_UCD_BLK_ANATOLIAN_HIEROGLYPHS=6,
    COATL_UCD_BLK_ANCIENT_GREEK_MUSIC=7,
        COATL_UCD_BLK_ANCIENT_GREEK_MUSICAL_NOTATION=COATL_UCD_BLK_ANCIENT_GREEK_MUSIC,
    COATL_UCD_BLK_ANCIENT_GREEK_NUMBERS=8,
    COATL_UCD_BLK_ANCIENT_SYMBOLS=9,
    COATL_UCD_BLK_ARABIC=10,
    COATL_UCD_BLK_ARABIC_EXT_A=11,
        COATL_UCD_BLK_ARABIC_EXTENDED_A=COATL_UCD_BLK_ARABIC_EXT_A,
    COATL_UCD_BLK_ARABIC_MATH=12,
        COATL_UCD_BLK_ARABIC_MATHEMATICAL_ALPHABETIC_SYMBOLS=COATL_UCD_BLK_ARABIC_MATH,
    COATL_UCD_BLK_ARABIC_PF_A=13,
        COATL_UCD_BLK_ARABIC_PRESENTATION_FORMS_A=COATL_UCD_BLK_ARABIC_PF_A,
    COATL_UCD_BLK_ARABIC_PF_B=14,
        COATL_UCD_BLK_ARABIC_PRESENTATION_FORMS_B=COATL_UCD_BLK_ARABIC_PF_B,
    COATL_UCD_BLK_ARABIC_SUP=15,
        COATL_UCD_BLK_ARABIC_SUPPLEMENT=COATL_UCD_BLK_ARABIC_SUP,
    COATL_UCD_BLK_ARMENIAN=16,
    COATL_UCD_BLK_ARROWS=17,
    COATL_UCD_BLK_ASCII=18,
        COATL_UCD_BLK_BASIC_LATIN=COATL_UCD_BLK_ASCII,
    COATL_UCD_BLK_AVESTAN=19,
    COATL_UCD_BLK_BALINESE=20,
    COATL_UCD_BLK_BAMUM=21,
    COATL_UCD_BLK_BAMUM_SUP=22,
        COATL_UCD_BLK_BAMUM_SUPPLEMENT=COATL_UCD_BLK_BAMUM_SUP,
    COATL_UCD_BLK_BASSA_VAH=23,
    COATL_UCD_BLK_BATAK=24,
    COATL_UCD_BLK_BENGALI=25,
    COATL_UCD_BLK_BHAIKSUKI=26,
    COATL_UCD_BLK_BLOCK_ELEMENTS=27,
    COATL_UCD_BLK_BOPOMOFO=28,
    COATL_UCD_BLK_BOPOMOFO_EXT=29,
        COATL_UCD_BLK_BOPOMOFO_EXTENDED=COATL_UCD_BLK_BOPOMOFO_EXT,
    COATL_UCD_BLK_BOX_DRAWING=30,
    COATL_UCD_BLK_BRAHMI=31,
    COATL_UCD_BLK_BRAILLE=32,
        COATL_UCD_BLK_BRAILLE_PATTERNS=COATL_UCD_BLK_BRAILLE,
    COATL_UCD_BLK_BUGINESE=33,
    COATL_UCD_BLK_BUHID=34,
    COATL_UCD_BLK_BYZANTINE_MUSIC=35,
        COATL_UCD_BLK_BYZANTINE_MUSICAL_SYMBOLS=COATL_UCD_BLK_BYZANTINE_MUSIC,
    COATL_UCD_BLK_CARIAN=36,
    COATL_UCD_BLK_CAUCASIAN_ALBANIAN=37,
    COATL_UCD_BLK_CHAKMA=38,
    COATL_UCD_BLK_CHAM=39,
    COATL_UCD_BLK_CHEROKEE=40,
    COATL_UCD_BLK_CHEROKEE_SUP=41,
        COATL_UCD_BLK_CHEROKEE_SUPPLEMENT=COATL_UCD_BLK_CHEROKEE_SUP,
    COATL_UCD_BLK_CJK=42,
        COATL_UCD_BLK_CJK_UNIFIED_IDEOGRAPHS=COATL_UCD_BLK_CJK,
    COATL_UCD_BLK_CJK_COMPAT=43,
        COATL_UCD_BLK_CJK_COMPATIBILITY=COATL_UCD_BLK_CJK_COMPAT,
    COATL_UCD_BLK_CJK_COMPAT_FORMS=44,
        COATL_UCD_BLK_CJK_COMPATIBILITY_FORMS=COATL_UCD_BLK_CJK_COMPAT_FORMS,
    COATL_UCD_BLK_CJK_COMPAT_IDEOGRAPHS=45,
        COATL_UCD_BLK_CJK_COMPATIBILITY_IDEOGRAPHS=COATL_UCD_BLK_CJK_COMPAT_IDEOGRAPHS,
    COATL_UCD_BLK_CJK_COMPAT_IDEOGRAPHS_SUP=46,
        COATL_UCD_BLK_CJK_COMPATIBILITY_IDEOGRAPHS_SUPPLEMENT=COATL_UCD_BLK_CJK_COMPAT_IDEOGRAPHS_SUP,
    COATL_UCD_BLK_CJK_EXT_A=47,
        COATL_UCD_BLK_CJK_UNIFIED_IDEOGRAPHS_EXTENSION_A=COATL_UCD_BLK_CJK_EXT_A,
    COATL_UCD_BLK_CJK_EXT_B=48,
        COATL_UCD_BLK_CJK_UNIFIED_IDEOGRAPHS_EXTENSION_B=COATL_UCD_BLK_CJK_EXT_B,
    COATL_UCD_BLK_CJK_EXT_C=49,
        COATL_UCD_BLK_CJK_UNIFIED_IDEOGRAPHS_EXTENSION_C=COATL_UCD_BLK_CJK_EXT_C,
    COATL_UCD_BLK_CJK_EXT_D=50,
        COATL_UCD_BLK_CJK_UNIFIED_IDEOGRAPHS_EXTENSION_D=COATL_UCD_BLK_CJK_EXT_D,
    COATL_UCD_BLK_CJK_EXT_E=51,
        COATL_UCD_BLK_CJK_UNIFIED_IDEOGRAPHS_EXTENSION_E=COATL_UCD_BLK_CJK_EXT_E,
    COATL_UCD_BLK_CJK_RADICALS_SUP=52,
        COATL_UCD_BLK_CJK_RADICALS_SUPPLEMENT=COATL_UCD_BLK_CJK_RADICALS_SUP,
    COATL_UCD_BLK_CJK_STROKES=53,
    COATL_UCD_BLK_CJK_SYMBOLS=54,
        COATL_UCD_BLK_CJK_SYMBOLS_AND_PUNCTUATION=COATL_UCD_BLK_CJK_SYMBOLS,
    COATL_UCD_BLK_COMPAT_JAMO=55,
        COATL_UCD_BLK_HANGUL_COMPATIBILITY_JAMO=COATL_UCD_BLK_COMPAT_JAMO,
    COATL_UCD_BLK_CONTROL_PICTURES=56,
    COATL_UCD_BLK_COPTIC=57,
    COATL_UCD_BLK_COPTIC_EPACT_NUMBERS=58,
    COATL_UCD_BLK_COUNTING_ROD=59,
        COATL_UCD_BLK_COUNTING_ROD_NUMERALS=COATL_UCD_BLK_COUNTING_ROD,
    COATL_UCD_BLK_CUNEIFORM=60,
    COATL_UCD_BLK_CUNEIFORM_NUMBERS=61,
        COATL_UCD_BLK_CUNEIFORM_NUMBERS_AND_PUNCTUATION=COATL_UCD_BLK_CUNEIFORM_NUMBERS,
    COATL_UCD_BLK_CURRENCY_SYMBOLS=62,
    COATL_UCD_BLK_CYPRIOT_SYLLABARY=63,
    COATL_UCD_BLK_CYRILLIC=64,
    COATL_UCD_BLK_CYRILLIC_EXT_A=65,
        COATL_UCD_BLK_CYRILLIC_EXTENDED_A=COATL_UCD_BLK_CYRILLIC_EXT_A,
    COATL_UCD_BLK_CYRILLIC_EXT_B=66,
        COATL_UCD_BLK_CYRILLIC_EXTENDED_B=COATL_UCD_BLK_CYRILLIC_EXT_B,
    COATL_UCD_BLK_CYRILLIC_EXT_C=67,
        COATL_UCD_BLK_CYRILLIC_EXTENDED_C=COATL_UCD_BLK_CYRILLIC_EXT_C,
    COATL_UCD_BLK_CYRILLIC_SUP=68,
        COATL_UCD_BLK_CYRILLIC_SUPPLEMENT=COATL_UCD_BLK_CYRILLIC_SUP,
        COATL_UCD_BLK_CYRILLIC_SUPPLEMENTARY=COATL_UCD_BLK_CYRILLIC_SUP,
    COATL_UCD_BLK_DESERET=69,
    COATL_UCD_BLK_DEVANAGARI=70,
    COATL_UCD_BLK_DEVANAGARI_EXT=71,
        COATL_UCD_BLK_DEVANAGARI_EXTENDED=COATL_UCD_BLK_DEVANAGARI_EXT,
    COATL_UCD_BLK_DIACRITICALS=72,
        COATL_UCD_BLK_COMBINING_DIACRITICAL_MARKS=COATL_UCD_BLK_DIACRITICALS,
    COATL_UCD_BLK_DIACRITICALS_EXT=73,
        COATL_UCD_BLK_COMBINING_DIACRITICAL_MARKS_EXTENDED=COATL_UCD_BLK_DIACRITICALS_EXT,
    COATL_UCD_BLK_DIACRITICALS_FOR_SYMBOLS=74,
        COATL_UCD_BLK_COMBINING_DIACRITICAL_MARKS_FOR_SYMBOLS=COATL_UCD_BLK_DIACRITICALS_FOR_SYMBOLS,
        COATL_UCD_BLK_COMBINING_MARKS_FOR_SYMBOLS=COATL_UCD_BLK_DIACRITICALS_FOR_SYMBOLS,
    COATL_UCD_BLK_DIACRITICALS_SUP=75,
        COATL_UCD_BLK_COMBINING_DIACRITICAL_MARKS_SUPPLEMENT=COATL_UCD_BLK_DIACRITICALS_SUP,
    COATL_UCD_BLK_DINGBATS=76,
    COATL_UCD_BLK_DOMINO=77,
        COATL_UCD_BLK_DOMINO_TILES=COATL_UCD_BLK_DOMINO,
    COATL_UCD_BLK_DUPLOYAN=78,
    COATL_UCD_BLK_EARLY_DYNASTIC_CUNEIFORM=79,
    COATL_UCD_BLK_EGYPTIAN_HIEROGLYPHS=80,
    COATL_UCD_BLK_ELBASAN=81,
    COATL_UCD_BLK_EMOTICONS=82,
    COATL_UCD_BLK_ENCLOSED_ALPHANUM=83,
        COATL_UCD_BLK_ENCLOSED_ALPHANUMERICS=COATL_UCD_BLK_ENCLOSED_ALPHANUM,
    COATL_UCD_BLK_ENCLOSED_ALPHANUM_SUP=84,
        COATL_UCD_BLK_ENCLOSED_ALPHANUMERIC_SUPPLEMENT=COATL_UCD_BLK_ENCLOSED_ALPHANUM_SUP,
    COATL_UCD_BLK_ENCLOSED_CJK=85,
        COATL_UCD_BLK_ENCLOSED_CJK_LETTERS_AND_MONTHS=COATL_UCD_BLK_ENCLOSED_CJK,
    COATL_UCD_BLK_ENCLOSED_IDEOGRAPHIC_SUP=86,
        COATL_UCD_BLK_ENCLOSED_IDEOGRAPHIC_SUPPLEMENT=COATL_UCD_BLK_ENCLOSED_IDEOGRAPHIC_SUP,
    COATL_UCD_BLK_ETHIOPIC=87,
    COATL_UCD_BLK_ETHIOPIC_EXT=88,
        COATL_UCD_BLK_ETHIOPIC_EXTENDED=COATL_UCD_BLK_ETHIOPIC_EXT,
    COATL_UCD_BLK_ETHIOPIC_EXT_A=89,
        COATL_UCD_BLK_ETHIOPIC_EXTENDED_A=COATL_UCD_BLK_ETHIOPIC_EXT_A,
    COATL_UCD_BLK_ETHIOPIC_SUP=90,
        COATL_UCD_BLK_ETHIOPIC_SUPPLEMENT=COATL_UCD_BLK_ETHIOPIC_SUP,
    COATL_UCD_BLK_GEOMETRIC_SHAPES=91,
    COATL_UCD_BLK_GEOMETRIC_SHAPES_EXT=92,
        COATL_UCD_BLK_GEOMETRIC_SHAPES_EXTENDED=COATL_UCD_BLK_GEOMETRIC_SHAPES_EXT,
    COATL_UCD_BLK_GEORGIAN=93,
    COATL_UCD_BLK_GEORGIAN_SUP=94,
        COATL_UCD_BLK_GEORGIAN_SUPPLEMENT=COATL_UCD_BLK_GEORGIAN_SUP,
    COATL_UCD_BLK_GLAGOLITIC=95,
    COATL_UCD_BLK_GLAGOLITIC_SUP=96,
        COATL_UCD_BLK_GLAGOLITIC_SUPPLEMENT=COATL_UCD_BLK_GLAGOLITIC_SUP,
    COATL_UCD_BLK_GOTHIC=97,
    COATL_UCD_BLK_GRANTHA=98,
    COATL_UCD_BLK_GREEK=99,
        COATL_UCD_BLK_GREEK_AND_COPTIC=COATL_UCD_BLK_GREEK,
    COATL_UCD_BLK_GREEK_EXT=100,
        COATL_UCD_BLK_GREEK_EXTENDED=COATL_UCD_BLK_GREEK_EXT,
    COATL_UCD_BLK_GUJARATI=101,
    COATL_UCD_BLK_GURMUKHI=102,
    COATL_UCD_BLK_HALF_AND_FULL_FORMS=103,
        COATL_UCD_BLK_HALFWIDTH_AND_FULLWIDTH_FORMS=COATL_UCD_BLK_HALF_AND_FULL_FORMS,
    COATL_UCD_BLK_HALF_MARKS=104,
        COATL_UCD_BLK_COMBINING_HALF_MARKS=COATL_UCD_BLK_HALF_MARKS,
    COATL_UCD_BLK_HANGUL=105,
        COATL_UCD_BLK_HANGUL_SYLLABLES=COATL_UCD_BLK_HANGUL,
    COATL_UCD_BLK_HANUNOO=106,
    COATL_UCD_BLK_HATRAN=107,
    COATL_UCD_BLK_HEBREW=108,
    COATL_UCD_BLK_HIGH_PU_SURROGATES=109,
        COATL_UCD_BLK_HIGH_PRIVATE_USE_SURROGATES=COATL_UCD_BLK_HIGH_PU_SURROGATES,
    COATL_UCD_BLK_HIGH_SURROGATES=110,
    COATL_UCD_BLK_HIRAGANA=111,
    COATL_UCD_BLK_IDC=112,
        COATL_UCD_BLK_IDEOGRAPHIC_DESCRIPTION_CHARACTERS=COATL_UCD_BLK_IDC,
    COATL_UCD_BLK_IDEOGRAPHIC_SYMBOLS=113,
        COATL_UCD_BLK_IDEOGRAPHIC_SYMBOLS_AND_PUNCTUATION=COATL_UCD_BLK_IDEOGRAPHIC_SYMBOLS,
    COATL_UCD_BLK_IMPERIAL_ARAMAIC=114,
    COATL_UCD_BLK_INDIC_NUMBER_FORMS=115,
        COATL_UCD_BLK_COMMON_INDIC_NUMBER_FORMS=COATL_UCD_BLK_INDIC_NUMBER_FORMS,
    COATL_UCD_BLK_INSCRIPTIONAL_PAHLAVI=116,
    COATL_UCD_BLK_INSCRIPTIONAL_PARTHIAN=117,
    COATL_UCD_BLK_IPA_EXT=118,
        COATL_UCD_BLK_IPA_EXTENSIONS=COATL_UCD_BLK_IPA_EXT,
    COATL_UCD_BLK_JAMO=119,
        COATL_UCD_BLK_HANGUL_JAMO=COATL_UCD_BLK_JAMO,
    COATL_UCD_BLK_JAMO_EXT_A=120,
        COATL_UCD_BLK_HANGUL_JAMO_EXTENDED_A=COATL_UCD_BLK_JAMO_EXT_A,
    COATL_UCD_BLK_JAMO_EXT_B=121,
        COATL_UCD_BLK_HANGUL_JAMO_EXTENDED_B=COATL_UCD_BLK_JAMO_EXT_B,
    COATL_UCD_BLK_JAVANESE=122,
    COATL_UCD_BLK_KAITHI=123,
    COATL_UCD_BLK_KANA_SUP=124,
        COATL_UCD_BLK_KANA_SUPPLEMENT=COATL_UCD_BLK_KANA_SUP,
    COATL_UCD_BLK_KANBUN=125,
    COATL_UCD_BLK_KANGXI=126,
        COATL_UCD_BLK_KANGXI_RADICALS=COATL_UCD_BLK_KANGXI,
    COATL_UCD_BLK_KANNADA=127,
    COATL_UCD_BLK_KATAKANA=128,
    COATL_UCD_BLK_KATAKANA_EXT=129,
        COATL_UCD_BLK_KATAKANA_PHONETIC_EXTENSIONS=COATL_UCD_BLK_KATAKANA_EXT,
    COATL_UCD_BLK_KAYAH_LI=130,
    COATL_UCD_BLK_KHAROSHTHI=131,
    COATL_UCD_BLK_KHMER=132,
    COATL_UCD_BLK_KHMER_SYMBOLS=133,
    COATL_UCD_BLK_KHOJKI=134,
    COATL_UCD_BLK_KHUDAWADI=135,
    COATL_UCD_BLK_LAO=136,
    COATL_UCD_BLK_LATIN_1_SUP=137,
        COATL_UCD_BLK_LATIN_1_SUPPLEMENT=COATL_UCD_BLK_LATIN_1_SUP,
        COATL_UCD_BLK_LATIN_1=COATL_UCD_BLK_LATIN_1_SUP,
    COATL_UCD_BLK_LATIN_EXT_A=138,
        COATL_UCD_BLK_LATIN_EXTENDED_A=COATL_UCD_BLK_LATIN_EXT_A,
    COATL_UCD_BLK_LATIN_EXT_ADDITIONAL=139,
        COATL_UCD_BLK_LATIN_EXTENDED_ADDITIONAL=COATL_UCD_BLK_LATIN_EXT_ADDITIONAL,
    COATL_UCD_BLK_LATIN_EXT_B=140,
        COATL_UCD_BLK_LATIN_EXTENDED_B=COATL_UCD_BLK_LATIN_EXT_B,
    COATL_UCD_BLK_LATIN_EXT_C=141,
        COATL_UCD_BLK_LATIN_EXTENDED_C=COATL_UCD_BLK_LATIN_EXT_C,
    COATL_UCD_BLK_LATIN_EXT_D=142,
        COATL_UCD_BLK_LATIN_EXTENDED_D=COATL_UCD_BLK_LATIN_EXT_D,
    COATL_UCD_BLK_LATIN_EXT_E=143,
        COATL_UCD_BLK_LATIN_EXTENDED_E=COATL_UCD_BLK_LATIN_EXT_E,
    COATL_UCD_BLK_LEPCHA=144,
    COATL_UCD_BLK_LETTERLIKE_SYMBOLS=145,
    COATL_UCD_BLK_LIMBU=146,
    COATL_UCD_BLK_LINEAR_A=147,
    COATL_UCD_BLK_LINEAR_B_IDEOGRAMS=148,
    COATL_UCD_BLK_LINEAR_B_SYLLABARY=149,
    COATL_UCD_BLK_LISU=150,
    COATL_UCD_BLK_LOW_SURROGATES=151,
    COATL_UCD_BLK_LYCIAN=152,
    COATL_UCD_BLK_LYDIAN=153,
    COATL_UCD_BLK_MAHAJANI=154,
    COATL_UCD_BLK_MAHJONG=155,
        COATL_UCD_BLK_MAHJONG_TILES=COATL_UCD_BLK_MAHJONG,
    COATL_UCD_BLK_MALAYALAM=156,
    COATL_UCD_BLK_MANDAIC=157,
    COATL_UCD_BLK_MANICHAEAN=158,
    COATL_UCD_BLK_MARCHEN=159,
    COATL_UCD_BLK_MATH_ALPHANUM=160,
        COATL_UCD_BLK_MATHEMATICAL_ALPHANUMERIC_SYMBOLS=COATL_UCD_BLK_MATH_ALPHANUM,
    COATL_UCD_BLK_MATH_OPERATORS=161,
        COATL_UCD_BLK_MATHEMATICAL_OPERATORS=COATL_UCD_BLK_MATH_OPERATORS,
    COATL_UCD_BLK_MEETEI_MAYEK=162,
    COATL_UCD_BLK_MEETEI_MAYEK_EXT=163,
        COATL_UCD_BLK_MEETEI_MAYEK_EXTENSIONS=COATL_UCD_BLK_MEETEI_MAYEK_EXT,
    COATL_UCD_BLK_MENDE_KIKAKUI=164,
    COATL_UCD_BLK_MEROITIC_CURSIVE=165,
    COATL_UCD_BLK_MEROITIC_HIEROGLYPHS=166,
    COATL_UCD_BLK_MIAO=167,
    COATL_UCD_BLK_MISC_ARROWS=168,
        COATL_UCD_BLK_MISCELLANEOUS_SYMBOLS_AND_ARROWS=COATL_UCD_BLK_MISC_ARROWS,
    COATL_UCD_BLK_MISC_MATH_SYMBOLS_A=169,
        COATL_UCD_BLK_MISCELLANEOUS_MATHEMATICAL_SYMBOLS_A=COATL_UCD_BLK_MISC_MATH_SYMBOLS_A,
    COATL_UCD_BLK_MISC_MATH_SYMBOLS_B=170,
        COATL_UCD_BLK_MISCELLANEOUS_MATHEMATICAL_SYMBOLS_B=COATL_UCD_BLK_MISC_MATH_SYMBOLS_B,
    COATL_UCD_BLK_MISC_PICTOGRAPHS=171,
        COATL_UCD_BLK_MISCELLANEOUS_SYMBOLS_AND_PICTOGRAPHS=COATL_UCD_BLK_MISC_PICTOGRAPHS,
    COATL_UCD_BLK_MISC_SYMBOLS=172,
        COATL_UCD_BLK_MISCELLANEOUS_SYMBOLS=COATL_UCD_BLK_MISC_SYMBOLS,
    COATL_UCD_BLK_MISC_TECHNICAL=173,
        COATL_UCD_BLK_MISCELLANEOUS_TECHNICAL=COATL_UCD_BLK_MISC_TECHNICAL,
    COATL_UCD_BLK_MODI=174,
    COATL_UCD_BLK_MODIFIER_LETTERS=175,
        COATL_UCD_BLK_SPACING_MODIFIER_LETTERS=COATL_UCD_BLK_MODIFIER_LETTERS,
    COATL_UCD_BLK_MODIFIER_TONE_LETTERS=176,
    COATL_UCD_BLK_MONGOLIAN=177,
    COATL_UCD_BLK_MONGOLIAN_SUP=178,
        COATL_UCD_BLK_MONGOLIAN_SUPPLEMENT=COATL_UCD_BLK_MONGOLIAN_SUP,
    COATL_UCD_BLK_MRO=179,
    COATL_UCD_BLK_MULTANI=180,
    COATL_UCD_BLK_MUSIC=181,
        COATL_UCD_BLK_MUSICAL_SYMBOLS=COATL_UCD_BLK_MUSIC,
    COATL_UCD_BLK_MYANMAR=182,
    COATL_UCD_BLK_MYANMAR_EXT_A=183,
        COATL_UCD_BLK_MYANMAR_EXTENDED_A=COATL_UCD_BLK_MYANMAR_EXT_A,
    COATL_UCD_BLK_MYANMAR_EXT_B=184,
        COATL_UCD_BLK_MYANMAR_EXTENDED_B=COATL_UCD_BLK_MYANMAR_EXT_B,
    COATL_UCD_BLK_NABATAEAN=185,
    COATL_UCD_BLK_NB=186,
        COATL_UCD_BLK_NO_BLOCK=COATL_UCD_BLK_NB,
    COATL_UCD_BLK_NEW_TAI_LUE=187,
    COATL_UCD_BLK_NEWA=188,
    COATL_UCD_BLK_NKO=189,
    COATL_UCD_BLK_NUMBER_FORMS=190,
    COATL_UCD_BLK_OCR=191,
        COATL_UCD_BLK_OPTICAL_CHARACTER_RECOGNITION=COATL_UCD_BLK_OCR,
    COATL_UCD_BLK_OGHAM=192,
    COATL_UCD_BLK_OL_CHIKI=193,
    COATL_UCD_BLK_OLD_HUNGARIAN=194,
    COATL_UCD_BLK_OLD_ITALIC=195,
    COATL_UCD_BLK_OLD_NORTH_ARABIAN=196,
    COATL_UCD_BLK_OLD_PERMIC=197,
    COATL_UCD_BLK_OLD_PERSIAN=198,
    COATL_UCD_BLK_OLD_SOUTH_ARABIAN=199,
    COATL_UCD_BLK_OLD_TURKIC=200,
    COATL_UCD_BLK_ORIYA=201,
    COATL_UCD_BLK_ORNAMENTAL_DINGBATS=202,
    COATL_UCD_BLK_OSAGE=203,
    COATL_UCD_BLK_OSMANYA=204,
    COATL_UCD_BLK_PAHAWH_HMONG=205,
    COATL_UCD_BLK_PALMYRENE=206,
    COATL_UCD_BLK_PAU_CIN_HAU=207,
    COATL_UCD_BLK_PHAGS_PA=208,
    COATL_UCD_BLK_PHAISTOS=209,
        COATL_UCD_BLK_PHAISTOS_DISC=COATL_UCD_BLK_PHAISTOS,
    COATL_UCD_BLK_PHOENICIAN=210,
    COATL_UCD_BLK_PHONETIC_EXT=211,
        COATL_UCD_BLK_PHONETIC_EXTENSIONS=COATL_UCD_BLK_PHONETIC_EXT,
    COATL_UCD_BLK_PHONETIC_EXT_SUP=212,
        COATL_UCD_BLK_PHONETIC_EXTENSIONS_SUPPLEMENT=COATL_UCD_BLK_PHONETIC_EXT_SUP,
    COATL_UCD_BLK_PLAYING_CARDS=213,
    COATL_UCD_BLK_PSALTER_PAHLAVI=214,
    COATL_UCD_BLK_PUA=215,
        COATL_UCD_BLK_PRIVATE_USE_AREA=COATL_UCD_BLK_PUA,
        COATL_UCD_BLK_PRIVATE_USE=COATL_UCD_BLK_PUA,
    COATL_UCD_BLK_PUNCTUATION=216,
        COATL_UCD_BLK_GENERAL_PUNCTUATION=COATL_UCD_BLK_PUNCTUATION,
    COATL_UCD_BLK_REJANG=217,
    COATL_UCD_BLK_RUMI=218,
        COATL_UCD_BLK_RUMI_NUMERAL_SYMBOLS=COATL_UCD_BLK_RUMI,
    COATL_UCD_BLK_RUNIC=219,
    COATL_UCD_BLK_SAMARITAN=220,
    COATL_UCD_BLK_SAURASHTRA=221,
    COATL_UCD_BLK_SHARADA=222,
    COATL_UCD_BLK_SHAVIAN=223,
    COATL_UCD_BLK_SHORTHAND_FORMAT_CONTROLS=224,
    COATL_UCD_BLK_SIDDHAM=225,
    COATL_UCD_BLK_SINHALA=226,
    COATL_UCD_BLK_SINHALA_ARCHAIC_NUMBERS=227,
    COATL_UCD_BLK_SMALL_FORMS=228,
        COATL_UCD_BLK_SMALL_FORM_VARIANTS=COATL_UCD_BLK_SMALL_FORMS,
    COATL_UCD_BLK_SORA_SOMPENG=229,
    COATL_UCD_BLK_SPECIALS=230,
    COATL_UCD_BLK_SUNDANESE=231,
    COATL_UCD_BLK_SUNDANESE_SUP=232,
        COATL_UCD_BLK_SUNDANESE_SUPPLEMENT=COATL_UCD_BLK_SUNDANESE_SUP,
    COATL_UCD_BLK_SUP_ARROWS_A=233,
        COATL_UCD_BLK_SUPPLEMENTAL_ARROWS_A=COATL_UCD_BLK_SUP_ARROWS_A,
    COATL_UCD_BLK_SUP_ARROWS_B=234,
        COATL_UCD_BLK_SUPPLEMENTAL_ARROWS_B=COATL_UCD_BLK_SUP_ARROWS_B,
    COATL_UCD_BLK_SUP_ARROWS_C=235,
        COATL_UCD_BLK_SUPPLEMENTAL_ARROWS_C=COATL_UCD_BLK_SUP_ARROWS_C,
    COATL_UCD_BLK_SUP_MATH_OPERATORS=236,
        COATL_UCD_BLK_SUPPLEMENTAL_MATHEMATICAL_OPERATORS=COATL_UCD_BLK_SUP_MATH_OPERATORS,
    COATL_UCD_BLK_SUP_PUA_A=237,
        COATL_UCD_BLK_SUPPLEMENTARY_PRIVATE_USE_AREA_A=COATL_UCD_BLK_SUP_PUA_A,
    COATL_UCD_BLK_SUP_PUA_B=238,
        COATL_UCD_BLK_SUPPLEMENTARY_PRIVATE_USE_AREA_B=COATL_UCD_BLK_SUP_PUA_B,
    COATL_UCD_BLK_SUP_PUNCTUATION=239,
        COATL_UCD_BLK_SUPPLEMENTAL_PUNCTUATION=COATL_UCD_BLK_SUP_PUNCTUATION,
    COATL_UCD_BLK_SUP_SYMBOLS_AND_PICTOGRAPHS=240,
        COATL_UCD_BLK_SUPPLEMENTAL_SYMBOLS_AND_PICTOGRAPHS=COATL_UCD_BLK_SUP_SYMBOLS_AND_PICTOGRAPHS,
    COATL_UCD_BLK_SUPER_AND_SUB=241,
        COATL_UCD_BLK_SUPERSCRIPTS_AND_SUBSCRIPTS=COATL_UCD_BLK_SUPER_AND_SUB,
    COATL_UCD_BLK_SUTTON_SIGNWRITING=242,
    COATL_UCD_BLK_SYLOTI_NAGRI=243,
    COATL_UCD_BLK_SYRIAC=244,
    COATL_UCD_BLK_TAGALOG=245,
    COATL_UCD_BLK_TAGBANWA=246,
    COATL_UCD_BLK_TAGS=247,
    COATL_UCD_BLK_TAI_LE=248,
    COATL_UCD_BLK_TAI_THAM=249,
    COATL_UCD_BLK_TAI_VIET=250,
    COATL_UCD_BLK_TAI_XUAN_JING=251,
        COATL_UCD_BLK_TAI_XUAN_JING_SYMBOLS=COATL_UCD_BLK_TAI_XUAN_JING,
    COATL_UCD_BLK_TAKRI=252,
    COATL_UCD_BLK_TAMIL=253,
    COATL_UCD_BLK_TANGUT=254,
    COATL_UCD_BLK_TANGUT_COMPONENTS=255,
    COATL_UCD_BLK_TELUGU=256,
    COATL_UCD_BLK_THAANA=257,
    COATL_UCD_BLK_THAI=258,
    COATL_UCD_BLK_TIBETAN=259,
    COATL_UCD_BLK_TIFINAGH=260,
    COATL_UCD_BLK_TIRHUTA=261,
    COATL_UCD_BLK_TRANSPORT_AND_MAP=262,
        COATL_UCD_BLK_TRANSPORT_AND_MAP_SYMBOLS=COATL_UCD_BLK_TRANSPORT_AND_MAP,
    COATL_UCD_BLK_UCAS=263,
        COATL_UCD_BLK_UNIFIED_CANADIAN_ABORIGINAL_SYLLABICS=COATL_UCD_BLK_UCAS,
        COATL_UCD_BLK_CANADIAN_SYLLABICS=COATL_UCD_BLK_UCAS,
    COATL_UCD_BLK_UCAS_EXT=264,
        COATL_UCD_BLK_UNIFIED_CANADIAN_ABORIGINAL_SYLLABICS_EXTENDED=COATL_UCD_BLK_UCAS_EXT,
    COATL_UCD_BLK_UGARITIC=265,
    COATL_UCD_BLK_VAI=266,
    COATL_UCD_BLK_VEDIC_EXT=267,
        COATL_UCD_BLK_VEDIC_EXTENSIONS=COATL_UCD_BLK_VEDIC_EXT,
    COATL_UCD_BLK_VERTICAL_FORMS=268,
    COATL_UCD_BLK_VS=269,
        COATL_UCD_BLK_VARIATION_SELECTORS=COATL_UCD_BLK_VS,
    COATL_UCD_BLK_VS_SUP=270,
        COATL_UCD_BLK_VARIATION_SELECTORS_SUPPLEMENT=COATL_UCD_BLK_VS_SUP,
    COATL_UCD_BLK_WARANG_CITI=271,
    COATL_UCD_BLK_YI_RADICALS=272,
    COATL_UCD_BLK_YI_SYLLABLES=273,
    COATL_UCD_BLK_YIJING=274,
        COATL_UCD_BLK_YIJING_HEXAGRAM_SYMBOLS=COATL_UCD_BLK_YIJING,

} Coatl_Ucd_Blk;

/**
 * Number of values for Unicode character property '*blk*'.
 *
 * @see Coatl_Ucd_Blk
 */
#define COATL_UCD_BLK_NBVALUES       274

/**
 * @enum Coatl_Ucd_Ccc
 *      Values for Unicode character property '**ccc**'.
 *
 *      Names are automatically generated from the UCD file
 *      `PropertyValueAliases.txt`.
 *
 * @see COATL_UCD_CCC
 *
 * @var COATL_UCD_CCC_0
 *      '**0**', '**NR**', '**Not_Reordered**'
 * @var COATL_UCD_CCC_NR
 *      Alias for #COATL_UCD_CCC_0
 * @var COATL_UCD_CCC_NOT_REORDERED
 *      Alias for #COATL_UCD_CCC_0
 * @var COATL_UCD_CCC_1
 *      '**1**', '**OV**', '**Overlay**'
 * @var COATL_UCD_CCC_OV
 *      Alias for #COATL_UCD_CCC_1
 * @var COATL_UCD_CCC_OVERLAY
 *      Alias for #COATL_UCD_CCC_1
 * @var COATL_UCD_CCC_7
 *      '**7**', '**NK**', '**Nukta**'
 * @var COATL_UCD_CCC_NK
 *      Alias for #COATL_UCD_CCC_7
 * @var COATL_UCD_CCC_NUKTA
 *      Alias for #COATL_UCD_CCC_7
 * @var COATL_UCD_CCC_8
 *      '**8**', '**KV**', '**Kana_Voicing**'
 * @var COATL_UCD_CCC_KV
 *      Alias for #COATL_UCD_CCC_8
 * @var COATL_UCD_CCC_KANA_VOICING
 *      Alias for #COATL_UCD_CCC_8
 * @var COATL_UCD_CCC_9
 *      '**9**', '**VR**', '**Virama**'
 * @var COATL_UCD_CCC_VR
 *      Alias for #COATL_UCD_CCC_9
 * @var COATL_UCD_CCC_VIRAMA
 *      Alias for #COATL_UCD_CCC_9
 * @var COATL_UCD_CCC_10
 *      '**10**', '**CCC10**'
 * @var COATL_UCD_CCC_CCC10
 *      Alias for #COATL_UCD_CCC_10
 * @var COATL_UCD_CCC_11
 *      '**11**', '**CCC11**'
 * @var COATL_UCD_CCC_CCC11
 *      Alias for #COATL_UCD_CCC_11
 * @var COATL_UCD_CCC_12
 *      '**12**', '**CCC12**'
 * @var COATL_UCD_CCC_CCC12
 *      Alias for #COATL_UCD_CCC_12
 * @var COATL_UCD_CCC_13
 *      '**13**', '**CCC13**'
 * @var COATL_UCD_CCC_CCC13
 *      Alias for #COATL_UCD_CCC_13
 * @var COATL_UCD_CCC_14
 *      '**14**', '**CCC14**'
 * @var COATL_UCD_CCC_CCC14
 *      Alias for #COATL_UCD_CCC_14
 * @var COATL_UCD_CCC_15
 *      '**15**', '**CCC15**'
 * @var COATL_UCD_CCC_CCC15
 *      Alias for #COATL_UCD_CCC_15
 * @var COATL_UCD_CCC_16
 *      '**16**', '**CCC16**'
 * @var COATL_UCD_CCC_CCC16
 *      Alias for #COATL_UCD_CCC_16
 * @var COATL_UCD_CCC_17
 *      '**17**', '**CCC17**'
 * @var COATL_UCD_CCC_CCC17
 *      Alias for #COATL_UCD_CCC_17
 * @var COATL_UCD_CCC_18
 *      '**18**', '**CCC18**'
 * @var COATL_UCD_CCC_CCC18
 *      Alias for #COATL_UCD_CCC_18
 * @var COATL_UCD_CCC_19
 *      '**19**', '**CCC19**'
 * @var COATL_UCD_CCC_CCC19
 *      Alias for #COATL_UCD_CCC_19
 * @var COATL_UCD_CCC_20
 *      '**20**', '**CCC20**'
 * @var COATL_UCD_CCC_CCC20
 *      Alias for #COATL_UCD_CCC_20
 * @var COATL_UCD_CCC_21
 *      '**21**', '**CCC21**'
 * @var COATL_UCD_CCC_CCC21
 *      Alias for #COATL_UCD_CCC_21
 * @var COATL_UCD_CCC_22
 *      '**22**', '**CCC22**'
 * @var COATL_UCD_CCC_CCC22
 *      Alias for #COATL_UCD_CCC_22
 * @var COATL_UCD_CCC_23
 *      '**23**', '**CCC23**'
 * @var COATL_UCD_CCC_CCC23
 *      Alias for #COATL_UCD_CCC_23
 * @var COATL_UCD_CCC_24
 *      '**24**', '**CCC24**'
 * @var COATL_UCD_CCC_CCC24
 *      Alias for #COATL_UCD_CCC_24
 * @var COATL_UCD_CCC_25
 *      '**25**', '**CCC25**'
 * @var COATL_UCD_CCC_CCC25
 *      Alias for #COATL_UCD_CCC_25
 * @var COATL_UCD_CCC_26
 *      '**26**', '**CCC26**'
 * @var COATL_UCD_CCC_CCC26
 *      Alias for #COATL_UCD_CCC_26
 * @var COATL_UCD_CCC_27
 *      '**27**', '**CCC27**'
 * @var COATL_UCD_CCC_CCC27
 *      Alias for #COATL_UCD_CCC_27
 * @var COATL_UCD_CCC_28
 *      '**28**', '**CCC28**'
 * @var COATL_UCD_CCC_CCC28
 *      Alias for #COATL_UCD_CCC_28
 * @var COATL_UCD_CCC_29
 *      '**29**', '**CCC29**'
 * @var COATL_UCD_CCC_CCC29
 *      Alias for #COATL_UCD_CCC_29
 * @var COATL_UCD_CCC_30
 *      '**30**', '**CCC30**'
 * @var COATL_UCD_CCC_CCC30
 *      Alias for #COATL_UCD_CCC_30
 * @var COATL_UCD_CCC_31
 *      '**31**', '**CCC31**'
 * @var COATL_UCD_CCC_CCC31
 *      Alias for #COATL_UCD_CCC_31
 * @var COATL_UCD_CCC_32
 *      '**32**', '**CCC32**'
 * @var COATL_UCD_CCC_CCC32
 *      Alias for #COATL_UCD_CCC_32
 * @var COATL_UCD_CCC_33
 *      '**33**', '**CCC33**'
 * @var COATL_UCD_CCC_CCC33
 *      Alias for #COATL_UCD_CCC_33
 * @var COATL_UCD_CCC_34
 *      '**34**', '**CCC34**'
 * @var COATL_UCD_CCC_CCC34
 *      Alias for #COATL_UCD_CCC_34
 * @var COATL_UCD_CCC_35
 *      '**35**', '**CCC35**'
 * @var COATL_UCD_CCC_CCC35
 *      Alias for #COATL_UCD_CCC_35
 * @var COATL_UCD_CCC_36
 *      '**36**', '**CCC36**'
 * @var COATL_UCD_CCC_CCC36
 *      Alias for #COATL_UCD_CCC_36
 * @var COATL_UCD_CCC_84
 *      '**84**', '**CCC84**'
 * @var COATL_UCD_CCC_CCC84
 *      Alias for #COATL_UCD_CCC_84
 * @var COATL_UCD_CCC_91
 *      '**91**', '**CCC91**'
 * @var COATL_UCD_CCC_CCC91
 *      Alias for #COATL_UCD_CCC_91
 * @var COATL_UCD_CCC_103
 *      '**103**', '**CCC103**'
 * @var COATL_UCD_CCC_CCC103
 *      Alias for #COATL_UCD_CCC_103
 * @var COATL_UCD_CCC_107
 *      '**107**', '**CCC107**'
 * @var COATL_UCD_CCC_CCC107
 *      Alias for #COATL_UCD_CCC_107
 * @var COATL_UCD_CCC_118
 *      '**118**', '**CCC118**'
 * @var COATL_UCD_CCC_CCC118
 *      Alias for #COATL_UCD_CCC_118
 * @var COATL_UCD_CCC_122
 *      '**122**', '**CCC122**'
 * @var COATL_UCD_CCC_CCC122
 *      Alias for #COATL_UCD_CCC_122
 * @var COATL_UCD_CCC_129
 *      '**129**', '**CCC129**'
 * @var COATL_UCD_CCC_CCC129
 *      Alias for #COATL_UCD_CCC_129
 * @var COATL_UCD_CCC_130
 *      '**130**', '**CCC130**'
 * @var COATL_UCD_CCC_CCC130
 *      Alias for #COATL_UCD_CCC_130
 * @var COATL_UCD_CCC_132
 *      '**132**', '**CCC132**'
 * @var COATL_UCD_CCC_CCC132
 *      Alias for #COATL_UCD_CCC_132
 * @var COATL_UCD_CCC_133
 *      '**133**', '**CCC133**'
 * @var COATL_UCD_CCC_CCC133
 *      Alias for #COATL_UCD_CCC_133
 * @var COATL_UCD_CCC_200
 *      '**200**', '**ATBL**', '**Attached_Below_Left**'
 * @var COATL_UCD_CCC_ATBL
 *      Alias for #COATL_UCD_CCC_200
 * @var COATL_UCD_CCC_ATTACHED_BELOW_LEFT
 *      Alias for #COATL_UCD_CCC_200
 * @var COATL_UCD_CCC_202
 *      '**202**', '**ATB**', '**Attached_Below**'
 * @var COATL_UCD_CCC_ATB
 *      Alias for #COATL_UCD_CCC_202
 * @var COATL_UCD_CCC_ATTACHED_BELOW
 *      Alias for #COATL_UCD_CCC_202
 * @var COATL_UCD_CCC_214
 *      '**214**', '**ATA**', '**Attached_Above**'
 * @var COATL_UCD_CCC_ATA
 *      Alias for #COATL_UCD_CCC_214
 * @var COATL_UCD_CCC_ATTACHED_ABOVE
 *      Alias for #COATL_UCD_CCC_214
 * @var COATL_UCD_CCC_216
 *      '**216**', '**ATAR**', '**Attached_Above_Right**'
 * @var COATL_UCD_CCC_ATAR
 *      Alias for #COATL_UCD_CCC_216
 * @var COATL_UCD_CCC_ATTACHED_ABOVE_RIGHT
 *      Alias for #COATL_UCD_CCC_216
 * @var COATL_UCD_CCC_218
 *      '**218**', '**BL**', '**Below_Left**'
 * @var COATL_UCD_CCC_BL
 *      Alias for #COATL_UCD_CCC_218
 * @var COATL_UCD_CCC_BELOW_LEFT
 *      Alias for #COATL_UCD_CCC_218
 * @var COATL_UCD_CCC_220
 *      '**220**', '**B**', '**Below**'
 * @var COATL_UCD_CCC_B
 *      Alias for #COATL_UCD_CCC_220
 * @var COATL_UCD_CCC_BELOW
 *      Alias for #COATL_UCD_CCC_220
 * @var COATL_UCD_CCC_222
 *      '**222**', '**BR**', '**Below_Right**'
 * @var COATL_UCD_CCC_BR
 *      Alias for #COATL_UCD_CCC_222
 * @var COATL_UCD_CCC_BELOW_RIGHT
 *      Alias for #COATL_UCD_CCC_222
 * @var COATL_UCD_CCC_224
 *      '**224**', '**L**', '**Left**'
 * @var COATL_UCD_CCC_L
 *      Alias for #COATL_UCD_CCC_224
 * @var COATL_UCD_CCC_LEFT
 *      Alias for #COATL_UCD_CCC_224
 * @var COATL_UCD_CCC_226
 *      '**226**', '**R**', '**Right**'
 * @var COATL_UCD_CCC_R
 *      Alias for #COATL_UCD_CCC_226
 * @var COATL_UCD_CCC_RIGHT
 *      Alias for #COATL_UCD_CCC_226
 * @var COATL_UCD_CCC_228
 *      '**228**', '**AL**', '**Above_Left**'
 * @var COATL_UCD_CCC_AL
 *      Alias for #COATL_UCD_CCC_228
 * @var COATL_UCD_CCC_ABOVE_LEFT
 *      Alias for #COATL_UCD_CCC_228
 * @var COATL_UCD_CCC_230
 *      '**230**', '**A**', '**Above**'
 * @var COATL_UCD_CCC_A
 *      Alias for #COATL_UCD_CCC_230
 * @var COATL_UCD_CCC_ABOVE
 *      Alias for #COATL_UCD_CCC_230
 * @var COATL_UCD_CCC_232
 *      '**232**', '**AR**', '**Above_Right**'
 * @var COATL_UCD_CCC_AR
 *      Alias for #COATL_UCD_CCC_232
 * @var COATL_UCD_CCC_ABOVE_RIGHT
 *      Alias for #COATL_UCD_CCC_232
 * @var COATL_UCD_CCC_233
 *      '**233**', '**DB**', '**Double_Below**'
 * @var COATL_UCD_CCC_DB
 *      Alias for #COATL_UCD_CCC_233
 * @var COATL_UCD_CCC_DOUBLE_BELOW
 *      Alias for #COATL_UCD_CCC_233
 * @var COATL_UCD_CCC_234
 *      '**234**', '**DA**', '**Double_Above**'
 * @var COATL_UCD_CCC_DA
 *      Alias for #COATL_UCD_CCC_234
 * @var COATL_UCD_CCC_DOUBLE_ABOVE
 *      Alias for #COATL_UCD_CCC_234
 * @var COATL_UCD_CCC_240
 *      '**240**', '**IS**', '**Iota_Subscript**'
 * @var COATL_UCD_CCC_IS
 *      Alias for #COATL_UCD_CCC_240
 * @var COATL_UCD_CCC_IOTA_SUBSCRIPT
 *      Alias for #COATL_UCD_CCC_240
 */
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
        COATL_UCD_CCC_CCC132=COATL_UCD_CCC_132,
    COATL_UCD_CCC_133=42,
        COATL_UCD_CCC_CCC133=COATL_UCD_CCC_133,
    COATL_UCD_CCC_200=43,
        COATL_UCD_CCC_ATBL=COATL_UCD_CCC_200,
        COATL_UCD_CCC_ATTACHED_BELOW_LEFT=COATL_UCD_CCC_200,
    COATL_UCD_CCC_202=44,
        COATL_UCD_CCC_ATB=COATL_UCD_CCC_202,
        COATL_UCD_CCC_ATTACHED_BELOW=COATL_UCD_CCC_202,
    COATL_UCD_CCC_214=45,
        COATL_UCD_CCC_ATA=COATL_UCD_CCC_214,
        COATL_UCD_CCC_ATTACHED_ABOVE=COATL_UCD_CCC_214,
    COATL_UCD_CCC_216=46,
        COATL_UCD_CCC_ATAR=COATL_UCD_CCC_216,
        COATL_UCD_CCC_ATTACHED_ABOVE_RIGHT=COATL_UCD_CCC_216,
    COATL_UCD_CCC_218=47,
        COATL_UCD_CCC_BL=COATL_UCD_CCC_218,
        COATL_UCD_CCC_BELOW_LEFT=COATL_UCD_CCC_218,
    COATL_UCD_CCC_220=48,
        COATL_UCD_CCC_B=COATL_UCD_CCC_220,
        COATL_UCD_CCC_BELOW=COATL_UCD_CCC_220,
    COATL_UCD_CCC_222=49,
        COATL_UCD_CCC_BR=COATL_UCD_CCC_222,
        COATL_UCD_CCC_BELOW_RIGHT=COATL_UCD_CCC_222,
    COATL_UCD_CCC_224=50,
        COATL_UCD_CCC_L=COATL_UCD_CCC_224,
        COATL_UCD_CCC_LEFT=COATL_UCD_CCC_224,
    COATL_UCD_CCC_226=51,
        COATL_UCD_CCC_R=COATL_UCD_CCC_226,
        COATL_UCD_CCC_RIGHT=COATL_UCD_CCC_226,
    COATL_UCD_CCC_228=52,
        COATL_UCD_CCC_AL=COATL_UCD_CCC_228,
        COATL_UCD_CCC_ABOVE_LEFT=COATL_UCD_CCC_228,
    COATL_UCD_CCC_230=53,
        COATL_UCD_CCC_A=COATL_UCD_CCC_230,
        COATL_UCD_CCC_ABOVE=COATL_UCD_CCC_230,
    COATL_UCD_CCC_232=54,
        COATL_UCD_CCC_AR=COATL_UCD_CCC_232,
        COATL_UCD_CCC_ABOVE_RIGHT=COATL_UCD_CCC_232,
    COATL_UCD_CCC_233=55,
        COATL_UCD_CCC_DB=COATL_UCD_CCC_233,
        COATL_UCD_CCC_DOUBLE_BELOW=COATL_UCD_CCC_233,
    COATL_UCD_CCC_234=56,
        COATL_UCD_CCC_DA=COATL_UCD_CCC_234,
        COATL_UCD_CCC_DOUBLE_ABOVE=COATL_UCD_CCC_234,
    COATL_UCD_CCC_240=57,
        COATL_UCD_CCC_IS=COATL_UCD_CCC_240,
        COATL_UCD_CCC_IOTA_SUBSCRIPT=COATL_UCD_CCC_240,

} Coatl_Ucd_Ccc;

/**
 * Number of values for Unicode character property '*ccc*'.
 *
 * @see Coatl_Ucd_Ccc
 */
#define COATL_UCD_CCC_NBVALUES       57

/**
 * @enum Coatl_Ucd_Dt
 *      Values for Unicode character property '**dt**'.
 *
 *      Names are automatically generated from the UCD file
 *      `PropertyValueAliases.txt`.
 *
 * @see COATL_UCD_DT
 *
 * @var COATL_UCD_DT_CAN
 *      '**Can**', '**Canonical**', '**can**'
 * @var COATL_UCD_DT_CANONICAL
 *      Alias for #COATL_UCD_DT_CAN
 * @var COATL_UCD_DT_COM
 *      '**Com**', '**Compat**', '**com**'
 * @var COATL_UCD_DT_COMPAT
 *      Alias for #COATL_UCD_DT_COM
 * @var COATL_UCD_DT_ENC
 *      '**Enc**', '**Circle**', '**enc**'
 * @var COATL_UCD_DT_CIRCLE
 *      Alias for #COATL_UCD_DT_ENC
 * @var COATL_UCD_DT_FIN
 *      '**Fin**', '**Final**', '**fin**'
 * @var COATL_UCD_DT_FINAL
 *      Alias for #COATL_UCD_DT_FIN
 * @var COATL_UCD_DT_FONT
 *      '**Font**', '**font**'
 * @var COATL_UCD_DT_FRA
 *      '**Fra**', '**Fraction**', '**fra**'
 * @var COATL_UCD_DT_FRACTION
 *      Alias for #COATL_UCD_DT_FRA
 * @var COATL_UCD_DT_INIT
 *      '**Init**', '**Initial**', '**init**'
 * @var COATL_UCD_DT_INITIAL
 *      Alias for #COATL_UCD_DT_INIT
 * @var COATL_UCD_DT_ISO
 *      '**Iso**', '**Isolated**', '**iso**'
 * @var COATL_UCD_DT_ISOLATED
 *      Alias for #COATL_UCD_DT_ISO
 * @var COATL_UCD_DT_MED
 *      '**Med**', '**Medial**', '**med**'
 * @var COATL_UCD_DT_MEDIAL
 *      Alias for #COATL_UCD_DT_MED
 * @var COATL_UCD_DT_NAR
 *      '**Nar**', '**Narrow**', '**nar**'
 * @var COATL_UCD_DT_NARROW
 *      Alias for #COATL_UCD_DT_NAR
 * @var COATL_UCD_DT_NB
 *      '**Nb**', '**Nobreak**', '**nb**'
 * @var COATL_UCD_DT_NOBREAK
 *      Alias for #COATL_UCD_DT_NB
 * @var COATL_UCD_DT_NONE
 *      '**None**', '**none**'
 * @var COATL_UCD_DT_SML
 *      '**Sml**', '**Small**', '**sml**'
 * @var COATL_UCD_DT_SMALL
 *      Alias for #COATL_UCD_DT_SML
 * @var COATL_UCD_DT_SQR
 *      '**Sqr**', '**Square**', '**sqr**'
 * @var COATL_UCD_DT_SQUARE
 *      Alias for #COATL_UCD_DT_SQR
 * @var COATL_UCD_DT_SUB
 *      '**Sub**', '**sub**'
 * @var COATL_UCD_DT_SUP
 *      '**Sup**', '**Super**', '**sup**'
 * @var COATL_UCD_DT_SUPER
 *      Alias for #COATL_UCD_DT_SUP
 * @var COATL_UCD_DT_VERT
 *      '**Vert**', '**Vertical**', '**vert**'
 * @var COATL_UCD_DT_VERTICAL
 *      Alias for #COATL_UCD_DT_VERT
 * @var COATL_UCD_DT_WIDE
 *      '**Wide**', '**wide**'
 */
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

/**
 * Number of values for Unicode character property '*dt*'.
 *
 * @see Coatl_Ucd_Dt
 */
#define COATL_UCD_DT_NBVALUES        18

/**
 * @enum Coatl_Ucd_Ea
 *      Values for Unicode character property '**ea**'.
 *
 *      Names are automatically generated from the UCD file
 *      `PropertyValueAliases.txt`.
 *
 * @see COATL_UCD_EA
 *
 * @var COATL_UCD_EA_A
 *      '**A**', '**Ambiguous**'
 * @var COATL_UCD_EA_AMBIGUOUS
 *      Alias for #COATL_UCD_EA_A
 * @var COATL_UCD_EA_F
 *      '**F**', '**Fullwidth**'
 * @var COATL_UCD_EA_FULLWIDTH
 *      Alias for #COATL_UCD_EA_F
 * @var COATL_UCD_EA_H
 *      '**H**', '**Halfwidth**'
 * @var COATL_UCD_EA_HALFWIDTH
 *      Alias for #COATL_UCD_EA_H
 * @var COATL_UCD_EA_N
 *      '**N**', '**Neutral**'
 * @var COATL_UCD_EA_NEUTRAL
 *      Alias for #COATL_UCD_EA_N
 * @var COATL_UCD_EA_NA
 *      '**Na**', '**Narrow**'
 * @var COATL_UCD_EA_NARROW
 *      Alias for #COATL_UCD_EA_NA
 * @var COATL_UCD_EA_W
 *      '**W**', '**Wide**'
 * @var COATL_UCD_EA_WIDE
 *      Alias for #COATL_UCD_EA_W
 */
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

/**
 * Number of values for Unicode character property '*ea*'.
 *
 * @see Coatl_Ucd_Ea
 */
#define COATL_UCD_EA_NBVALUES        6

/**
 * @enum Coatl_Ucd_Gc
 *      Values for Unicode character property '**gc**'.
 *
 *      Names are automatically generated from the UCD file
 *      `PropertyValueAliases.txt`.
 *
 * @see COATL_UCD_GC
 *
 * @var COATL_UCD_GC_CC
 *      '**Cc**', '**Control**', '**cntrl**'
 * @var COATL_UCD_GC_CONTROL
 *      Alias for #COATL_UCD_GC_CC
 * @var COATL_UCD_GC_CNTRL
 *      Alias for #COATL_UCD_GC_CC
 * @var COATL_UCD_GC_CF
 *      '**Cf**', '**Format**'
 * @var COATL_UCD_GC_FORMAT
 *      Alias for #COATL_UCD_GC_CF
 * @var COATL_UCD_GC_CN
 *      '**Cn**', '**Unassigned**'
 * @var COATL_UCD_GC_UNASSIGNED
 *      Alias for #COATL_UCD_GC_CN
 * @var COATL_UCD_GC_CO
 *      '**Co**', '**Private_Use**'
 * @var COATL_UCD_GC_PRIVATE_USE
 *      Alias for #COATL_UCD_GC_CO
 * @var COATL_UCD_GC_CS
 *      '**Cs**', '**Surrogate**'
 * @var COATL_UCD_GC_SURROGATE
 *      Alias for #COATL_UCD_GC_CS
 * @var COATL_UCD_GC_LL
 *      '**Ll**', '**Lowercase_Letter**'
 * @var COATL_UCD_GC_LOWERCASE_LETTER
 *      Alias for #COATL_UCD_GC_LL
 * @var COATL_UCD_GC_LM
 *      '**Lm**', '**Modifier_Letter**'
 * @var COATL_UCD_GC_MODIFIER_LETTER
 *      Alias for #COATL_UCD_GC_LM
 * @var COATL_UCD_GC_LO
 *      '**Lo**', '**Other_Letter**'
 * @var COATL_UCD_GC_OTHER_LETTER
 *      Alias for #COATL_UCD_GC_LO
 * @var COATL_UCD_GC_LT
 *      '**Lt**', '**Titlecase_Letter**'
 * @var COATL_UCD_GC_TITLECASE_LETTER
 *      Alias for #COATL_UCD_GC_LT
 * @var COATL_UCD_GC_LU
 *      '**Lu**', '**Uppercase_Letter**'
 * @var COATL_UCD_GC_UPPERCASE_LETTER
 *      Alias for #COATL_UCD_GC_LU
 * @var COATL_UCD_GC_MC
 *      '**Mc**', '**Spacing_Mark**'
 * @var COATL_UCD_GC_SPACING_MARK
 *      Alias for #COATL_UCD_GC_MC
 * @var COATL_UCD_GC_ME
 *      '**Me**', '**Enclosing_Mark**'
 * @var COATL_UCD_GC_ENCLOSING_MARK
 *      Alias for #COATL_UCD_GC_ME
 * @var COATL_UCD_GC_MN
 *      '**Mn**', '**Nonspacing_Mark**'
 * @var COATL_UCD_GC_NONSPACING_MARK
 *      Alias for #COATL_UCD_GC_MN
 * @var COATL_UCD_GC_ND
 *      '**Nd**', '**Decimal_Number**', '**digit**'
 * @var COATL_UCD_GC_DECIMAL_NUMBER
 *      Alias for #COATL_UCD_GC_ND
 * @var COATL_UCD_GC_DIGIT
 *      Alias for #COATL_UCD_GC_ND
 * @var COATL_UCD_GC_NL
 *      '**Nl**', '**Letter_Number**'
 * @var COATL_UCD_GC_LETTER_NUMBER
 *      Alias for #COATL_UCD_GC_NL
 * @var COATL_UCD_GC_NO
 *      '**No**', '**Other_Number**'
 * @var COATL_UCD_GC_OTHER_NUMBER
 *      Alias for #COATL_UCD_GC_NO
 * @var COATL_UCD_GC_PC
 *      '**Pc**', '**Connector_Punctuation**'
 * @var COATL_UCD_GC_CONNECTOR_PUNCTUATION
 *      Alias for #COATL_UCD_GC_PC
 * @var COATL_UCD_GC_PD
 *      '**Pd**', '**Dash_Punctuation**'
 * @var COATL_UCD_GC_DASH_PUNCTUATION
 *      Alias for #COATL_UCD_GC_PD
 * @var COATL_UCD_GC_PE
 *      '**Pe**', '**Close_Punctuation**'
 * @var COATL_UCD_GC_CLOSE_PUNCTUATION
 *      Alias for #COATL_UCD_GC_PE
 * @var COATL_UCD_GC_PF
 *      '**Pf**', '**Final_Punctuation**'
 * @var COATL_UCD_GC_FINAL_PUNCTUATION
 *      Alias for #COATL_UCD_GC_PF
 * @var COATL_UCD_GC_PI
 *      '**Pi**', '**Initial_Punctuation**'
 * @var COATL_UCD_GC_INITIAL_PUNCTUATION
 *      Alias for #COATL_UCD_GC_PI
 * @var COATL_UCD_GC_PO
 *      '**Po**', '**Other_Punctuation**'
 * @var COATL_UCD_GC_OTHER_PUNCTUATION
 *      Alias for #COATL_UCD_GC_PO
 * @var COATL_UCD_GC_PS
 *      '**Ps**', '**Open_Punctuation**'
 * @var COATL_UCD_GC_OPEN_PUNCTUATION
 *      Alias for #COATL_UCD_GC_PS
 * @var COATL_UCD_GC_SC
 *      '**Sc**', '**Currency_Symbol**'
 * @var COATL_UCD_GC_CURRENCY_SYMBOL
 *      Alias for #COATL_UCD_GC_SC
 * @var COATL_UCD_GC_SK
 *      '**Sk**', '**Modifier_Symbol**'
 * @var COATL_UCD_GC_MODIFIER_SYMBOL
 *      Alias for #COATL_UCD_GC_SK
 * @var COATL_UCD_GC_SM
 *      '**Sm**', '**Math_Symbol**'
 * @var COATL_UCD_GC_MATH_SYMBOL
 *      Alias for #COATL_UCD_GC_SM
 * @var COATL_UCD_GC_SO
 *      '**So**', '**Other_Symbol**'
 * @var COATL_UCD_GC_OTHER_SYMBOL
 *      Alias for #COATL_UCD_GC_SO
 * @var COATL_UCD_GC_ZL
 *      '**Zl**', '**Line_Separator**'
 * @var COATL_UCD_GC_LINE_SEPARATOR
 *      Alias for #COATL_UCD_GC_ZL
 * @var COATL_UCD_GC_ZP
 *      '**Zp**', '**Paragraph_Separator**'
 * @var COATL_UCD_GC_PARAGRAPH_SEPARATOR
 *      Alias for #COATL_UCD_GC_ZP
 * @var COATL_UCD_GC_ZS
 *      '**Zs**', '**Space_Separator**'
 * @var COATL_UCD_GC_SPACE_SEPARATOR
 *      Alias for #COATL_UCD_GC_ZS
 */
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

/**
 * Number of values for Unicode character property '*gc*'.
 *
 * @see Coatl_Ucd_Gc
 */
#define COATL_UCD_GC_NBVALUES        30

/**
 * @enum Coatl_Ucd_GCB
 *      Values for Unicode character property '**GCB**'.
 *
 *      Names are automatically generated from the UCD file
 *      `PropertyValueAliases.txt`.
 *
 * @see COATL_UCD_GCB
 *
 * @var COATL_UCD_GCB_CN
 *      '**CN**', '**Control**'
 * @var COATL_UCD_GCB_CONTROL
 *      Alias for #COATL_UCD_GCB_CN
 * @var COATL_UCD_GCB_CR
 *      '**CR**'
 * @var COATL_UCD_GCB_EB
 *      '**EB**', '**E_Base**'
 * @var COATL_UCD_GCB_E_BASE
 *      Alias for #COATL_UCD_GCB_EB
 * @var COATL_UCD_GCB_EBG
 *      '**EBG**', '**E_Base_GAZ**'
 * @var COATL_UCD_GCB_E_BASE_GAZ
 *      Alias for #COATL_UCD_GCB_EBG
 * @var COATL_UCD_GCB_EM
 *      '**EM**', '**E_Modifier**'
 * @var COATL_UCD_GCB_E_MODIFIER
 *      Alias for #COATL_UCD_GCB_EM
 * @var COATL_UCD_GCB_EX
 *      '**EX**', '**Extend**'
 * @var COATL_UCD_GCB_EXTEND
 *      Alias for #COATL_UCD_GCB_EX
 * @var COATL_UCD_GCB_GAZ
 *      '**GAZ**', '**Glue_After_Zwj**'
 * @var COATL_UCD_GCB_GLUE_AFTER_ZWJ
 *      Alias for #COATL_UCD_GCB_GAZ
 * @var COATL_UCD_GCB_L
 *      '**L**'
 * @var COATL_UCD_GCB_LF
 *      '**LF**'
 * @var COATL_UCD_GCB_LV
 *      '**LV**'
 * @var COATL_UCD_GCB_LVT
 *      '**LVT**'
 * @var COATL_UCD_GCB_PP
 *      '**PP**', '**Prepend**'
 * @var COATL_UCD_GCB_PREPEND
 *      Alias for #COATL_UCD_GCB_PP
 * @var COATL_UCD_GCB_RI
 *      '**RI**', '**Regional_Indicator**'
 * @var COATL_UCD_GCB_REGIONAL_INDICATOR
 *      Alias for #COATL_UCD_GCB_RI
 * @var COATL_UCD_GCB_SM
 *      '**SM**', '**SpacingMark**'
 * @var COATL_UCD_GCB_SPACINGMARK
 *      Alias for #COATL_UCD_GCB_SM
 * @var COATL_UCD_GCB_T
 *      '**T**'
 * @var COATL_UCD_GCB_V
 *      '**V**'
 * @var COATL_UCD_GCB_XX
 *      '**XX**', '**Other**'
 * @var COATL_UCD_GCB_OTHER
 *      Alias for #COATL_UCD_GCB_XX
 * @var COATL_UCD_GCB_ZWJ
 *      '**ZWJ**'
 */
typedef enum Coatl_Ucd_GCB {
    COATL_UCD_GCB_CN=1,
        COATL_UCD_GCB_CONTROL=COATL_UCD_GCB_CN,
    COATL_UCD_GCB_CR=2,
    COATL_UCD_GCB_EB=3,
        COATL_UCD_GCB_E_BASE=COATL_UCD_GCB_EB,
    COATL_UCD_GCB_EBG=4,
        COATL_UCD_GCB_E_BASE_GAZ=COATL_UCD_GCB_EBG,
    COATL_UCD_GCB_EM=5,
        COATL_UCD_GCB_E_MODIFIER=COATL_UCD_GCB_EM,
    COATL_UCD_GCB_EX=6,
        COATL_UCD_GCB_EXTEND=COATL_UCD_GCB_EX,
    COATL_UCD_GCB_GAZ=7,
        COATL_UCD_GCB_GLUE_AFTER_ZWJ=COATL_UCD_GCB_GAZ,
    COATL_UCD_GCB_L=8,
    COATL_UCD_GCB_LF=9,
    COATL_UCD_GCB_LV=10,
    COATL_UCD_GCB_LVT=11,
    COATL_UCD_GCB_PP=12,
        COATL_UCD_GCB_PREPEND=COATL_UCD_GCB_PP,
    COATL_UCD_GCB_RI=13,
        COATL_UCD_GCB_REGIONAL_INDICATOR=COATL_UCD_GCB_RI,
    COATL_UCD_GCB_SM=14,
        COATL_UCD_GCB_SPACINGMARK=COATL_UCD_GCB_SM,
    COATL_UCD_GCB_T=15,
    COATL_UCD_GCB_V=16,
    COATL_UCD_GCB_XX=17,
        COATL_UCD_GCB_OTHER=COATL_UCD_GCB_XX,
    COATL_UCD_GCB_ZWJ=18,

} Coatl_Ucd_GCB;

/**
 * Number of values for Unicode character property '*GCB*'.
 *
 * @see Coatl_Ucd_GCB
 */
#define COATL_UCD_GCB_NBVALUES       18

/**
 * @enum Coatl_Ucd_Hst
 *      Values for Unicode character property '**hst**'.
 *
 *      Names are automatically generated from the UCD file
 *      `PropertyValueAliases.txt`.
 *
 * @see COATL_UCD_HST
 *
 * @var COATL_UCD_HST_L
 *      '**L**', '**Leading_Jamo**'
 * @var COATL_UCD_HST_LEADING_JAMO
 *      Alias for #COATL_UCD_HST_L
 * @var COATL_UCD_HST_LV
 *      '**LV**', '**LV_Syllable**'
 * @var COATL_UCD_HST_LV_SYLLABLE
 *      Alias for #COATL_UCD_HST_LV
 * @var COATL_UCD_HST_LVT
 *      '**LVT**', '**LVT_Syllable**'
 * @var COATL_UCD_HST_LVT_SYLLABLE
 *      Alias for #COATL_UCD_HST_LVT
 * @var COATL_UCD_HST_NA
 *      '**NA**', '**Not_Applicable**'
 * @var COATL_UCD_HST_NOT_APPLICABLE
 *      Alias for #COATL_UCD_HST_NA
 * @var COATL_UCD_HST_T
 *      '**T**', '**Trailing_Jamo**'
 * @var COATL_UCD_HST_TRAILING_JAMO
 *      Alias for #COATL_UCD_HST_T
 * @var COATL_UCD_HST_V
 *      '**V**', '**Vowel_Jamo**'
 * @var COATL_UCD_HST_VOWEL_JAMO
 *      Alias for #COATL_UCD_HST_V
 */
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

/**
 * Number of values for Unicode character property '*hst*'.
 *
 * @see Coatl_Ucd_Hst
 */
#define COATL_UCD_HST_NBVALUES       6

/**
 * @enum Coatl_Ucd_InPC
 *      Values for Unicode character property '**InPC**'.
 *
 *      Names are automatically generated from the UCD file
 *      `PropertyValueAliases.txt`.
 *
 * @see COATL_UCD_INPC
 *
 * @var COATL_UCD_INPC_BOTTOM
 *      '**Bottom**'
 * @var COATL_UCD_INPC_BOTTOM_AND_RIGHT
 *      '**Bottom_And_Right**'
 * @var COATL_UCD_INPC_LEFT
 *      '**Left**'
 * @var COATL_UCD_INPC_LEFT_AND_RIGHT
 *      '**Left_And_Right**'
 * @var COATL_UCD_INPC_NA
 *      '**NA**'
 * @var COATL_UCD_INPC_OVERSTRUCK
 *      '**Overstruck**'
 * @var COATL_UCD_INPC_RIGHT
 *      '**Right**'
 * @var COATL_UCD_INPC_TOP
 *      '**Top**'
 * @var COATL_UCD_INPC_TOP_AND_BOTTOM
 *      '**Top_And_Bottom**'
 * @var COATL_UCD_INPC_TOP_AND_BOTTOM_AND_RIGHT
 *      '**Top_And_Bottom_And_Right**'
 * @var COATL_UCD_INPC_TOP_AND_LEFT
 *      '**Top_And_Left**'
 * @var COATL_UCD_INPC_TOP_AND_LEFT_AND_RIGHT
 *      '**Top_And_Left_And_Right**'
 * @var COATL_UCD_INPC_TOP_AND_RIGHT
 *      '**Top_And_Right**'
 * @var COATL_UCD_INPC_VISUAL_ORDER_LEFT
 *      '**Visual_Order_Left**'
 */
typedef enum Coatl_Ucd_InPC {
    COATL_UCD_INPC_BOTTOM=1,
    COATL_UCD_INPC_BOTTOM_AND_RIGHT=2,
    COATL_UCD_INPC_LEFT=3,
    COATL_UCD_INPC_LEFT_AND_RIGHT=4,
    COATL_UCD_INPC_NA=5,
    COATL_UCD_INPC_OVERSTRUCK=6,
    COATL_UCD_INPC_RIGHT=7,
    COATL_UCD_INPC_TOP=8,
    COATL_UCD_INPC_TOP_AND_BOTTOM=9,
    COATL_UCD_INPC_TOP_AND_BOTTOM_AND_RIGHT=10,
    COATL_UCD_INPC_TOP_AND_LEFT=11,
    COATL_UCD_INPC_TOP_AND_LEFT_AND_RIGHT=12,
    COATL_UCD_INPC_TOP_AND_RIGHT=13,
    COATL_UCD_INPC_VISUAL_ORDER_LEFT=14,

} Coatl_Ucd_InPC;

/**
 * Number of values for Unicode character property '*InPC*'.
 *
 * @see Coatl_Ucd_InPC
 */
#define COATL_UCD_INPC_NBVALUES      14

/**
 * @enum Coatl_Ucd_InSC
 *      Values for Unicode character property '**InSC**'.
 *
 *      Names are automatically generated from the UCD file
 *      `PropertyValueAliases.txt`.
 *
 * @see COATL_UCD_INSC
 *
 * @var COATL_UCD_INSC_AVAGRAHA
 *      '**Avagraha**'
 * @var COATL_UCD_INSC_BINDU
 *      '**Bindu**'
 * @var COATL_UCD_INSC_BRAHMI_JOINING_NUMBER
 *      '**Brahmi_Joining_Number**'
 * @var COATL_UCD_INSC_CANTILLATION_MARK
 *      '**Cantillation_Mark**'
 * @var COATL_UCD_INSC_CONSONANT
 *      '**Consonant**'
 * @var COATL_UCD_INSC_CONSONANT_DEAD
 *      '**Consonant_Dead**'
 * @var COATL_UCD_INSC_CONSONANT_FINAL
 *      '**Consonant_Final**'
 * @var COATL_UCD_INSC_CONSONANT_HEAD_LETTER
 *      '**Consonant_Head_Letter**'
 * @var COATL_UCD_INSC_CONSONANT_KILLER
 *      '**Consonant_Killer**'
 * @var COATL_UCD_INSC_CONSONANT_MEDIAL
 *      '**Consonant_Medial**'
 * @var COATL_UCD_INSC_CONSONANT_PLACEHOLDER
 *      '**Consonant_Placeholder**'
 * @var COATL_UCD_INSC_CONSONANT_PRECEDING_REPHA
 *      '**Consonant_Preceding_Repha**'
 * @var COATL_UCD_INSC_CONSONANT_PREFIXED
 *      '**Consonant_Prefixed**'
 * @var COATL_UCD_INSC_CONSONANT_SUBJOINED
 *      '**Consonant_Subjoined**'
 * @var COATL_UCD_INSC_CONSONANT_SUCCEEDING_REPHA
 *      '**Consonant_Succeeding_Repha**'
 * @var COATL_UCD_INSC_CONSONANT_WITH_STACKER
 *      '**Consonant_With_Stacker**'
 * @var COATL_UCD_INSC_GEMINATION_MARK
 *      '**Gemination_Mark**'
 * @var COATL_UCD_INSC_INVISIBLE_STACKER
 *      '**Invisible_Stacker**'
 * @var COATL_UCD_INSC_JOINER
 *      '**Joiner**'
 * @var COATL_UCD_INSC_MODIFYING_LETTER
 *      '**Modifying_Letter**'
 * @var COATL_UCD_INSC_NON_JOINER
 *      '**Non_Joiner**'
 * @var COATL_UCD_INSC_NUKTA
 *      '**Nukta**'
 * @var COATL_UCD_INSC_NUMBER
 *      '**Number**'
 * @var COATL_UCD_INSC_NUMBER_JOINER
 *      '**Number_Joiner**'
 * @var COATL_UCD_INSC_OTHER
 *      '**Other**'
 * @var COATL_UCD_INSC_PURE_KILLER
 *      '**Pure_Killer**'
 * @var COATL_UCD_INSC_REGISTER_SHIFTER
 *      '**Register_Shifter**'
 * @var COATL_UCD_INSC_SYLLABLE_MODIFIER
 *      '**Syllable_Modifier**'
 * @var COATL_UCD_INSC_TONE_LETTER
 *      '**Tone_Letter**'
 * @var COATL_UCD_INSC_TONE_MARK
 *      '**Tone_Mark**'
 * @var COATL_UCD_INSC_VIRAMA
 *      '**Virama**'
 * @var COATL_UCD_INSC_VISARGA
 *      '**Visarga**'
 * @var COATL_UCD_INSC_VOWEL
 *      '**Vowel**'
 * @var COATL_UCD_INSC_VOWEL_DEPENDENT
 *      '**Vowel_Dependent**'
 * @var COATL_UCD_INSC_VOWEL_INDEPENDENT
 *      '**Vowel_Independent**'
 */
typedef enum Coatl_Ucd_InSC {
    COATL_UCD_INSC_AVAGRAHA=1,
    COATL_UCD_INSC_BINDU=2,
    COATL_UCD_INSC_BRAHMI_JOINING_NUMBER=3,
    COATL_UCD_INSC_CANTILLATION_MARK=4,
    COATL_UCD_INSC_CONSONANT=5,
    COATL_UCD_INSC_CONSONANT_DEAD=6,
    COATL_UCD_INSC_CONSONANT_FINAL=7,
    COATL_UCD_INSC_CONSONANT_HEAD_LETTER=8,
    COATL_UCD_INSC_CONSONANT_KILLER=9,
    COATL_UCD_INSC_CONSONANT_MEDIAL=10,
    COATL_UCD_INSC_CONSONANT_PLACEHOLDER=11,
    COATL_UCD_INSC_CONSONANT_PRECEDING_REPHA=12,
    COATL_UCD_INSC_CONSONANT_PREFIXED=13,
    COATL_UCD_INSC_CONSONANT_SUBJOINED=14,
    COATL_UCD_INSC_CONSONANT_SUCCEEDING_REPHA=15,
    COATL_UCD_INSC_CONSONANT_WITH_STACKER=16,
    COATL_UCD_INSC_GEMINATION_MARK=17,
    COATL_UCD_INSC_INVISIBLE_STACKER=18,
    COATL_UCD_INSC_JOINER=19,
    COATL_UCD_INSC_MODIFYING_LETTER=20,
    COATL_UCD_INSC_NON_JOINER=21,
    COATL_UCD_INSC_NUKTA=22,
    COATL_UCD_INSC_NUMBER=23,
    COATL_UCD_INSC_NUMBER_JOINER=24,
    COATL_UCD_INSC_OTHER=25,
    COATL_UCD_INSC_PURE_KILLER=26,
    COATL_UCD_INSC_REGISTER_SHIFTER=27,
    COATL_UCD_INSC_SYLLABLE_MODIFIER=28,
    COATL_UCD_INSC_TONE_LETTER=29,
    COATL_UCD_INSC_TONE_MARK=30,
    COATL_UCD_INSC_VIRAMA=31,
    COATL_UCD_INSC_VISARGA=32,
    COATL_UCD_INSC_VOWEL=33,
    COATL_UCD_INSC_VOWEL_DEPENDENT=34,
    COATL_UCD_INSC_VOWEL_INDEPENDENT=35,

} Coatl_Ucd_InSC;

/**
 * Number of values for Unicode character property '*InSC*'.
 *
 * @see Coatl_Ucd_InSC
 */
#define COATL_UCD_INSC_NBVALUES      35

/**
 * @enum Coatl_Ucd_Jg
 *      Values for Unicode character property '**jg**'.
 *
 *      Names are automatically generated from the UCD file
 *      `PropertyValueAliases.txt`.
 *
 * @see COATL_UCD_JG
 *
 * @var COATL_UCD_JG_AFRICAN_FEH
 *      '**African_Feh**'
 * @var COATL_UCD_JG_AFRICAN_NOON
 *      '**African_Noon**'
 * @var COATL_UCD_JG_AFRICAN_QAF
 *      '**African_Qaf**'
 * @var COATL_UCD_JG_AIN
 *      '**Ain**'
 * @var COATL_UCD_JG_ALAPH
 *      '**Alaph**'
 * @var COATL_UCD_JG_ALEF
 *      '**Alef**'
 * @var COATL_UCD_JG_BEH
 *      '**Beh**'
 * @var COATL_UCD_JG_BETH
 *      '**Beth**'
 * @var COATL_UCD_JG_BURUSHASKI_YEH_BARREE
 *      '**Burushaski_Yeh_Barree**'
 * @var COATL_UCD_JG_DAL
 *      '**Dal**'
 * @var COATL_UCD_JG_DALATH_RISH
 *      '**Dalath_Rish**'
 * @var COATL_UCD_JG_E
 *      '**E**'
 * @var COATL_UCD_JG_FARSI_YEH
 *      '**Farsi_Yeh**'
 * @var COATL_UCD_JG_FE
 *      '**Fe**'
 * @var COATL_UCD_JG_FEH
 *      '**Feh**'
 * @var COATL_UCD_JG_FINAL_SEMKATH
 *      '**Final_Semkath**'
 * @var COATL_UCD_JG_GAF
 *      '**Gaf**'
 * @var COATL_UCD_JG_GAMAL
 *      '**Gamal**'
 * @var COATL_UCD_JG_HAH
 *      '**Hah**'
 * @var COATL_UCD_JG_HE
 *      '**He**'
 * @var COATL_UCD_JG_HEH
 *      '**Heh**'
 * @var COATL_UCD_JG_HEH_GOAL
 *      '**Heh_Goal**'
 * @var COATL_UCD_JG_HETH
 *      '**Heth**'
 * @var COATL_UCD_JG_KAF
 *      '**Kaf**'
 * @var COATL_UCD_JG_KAPH
 *      '**Kaph**'
 * @var COATL_UCD_JG_KHAPH
 *      '**Khaph**'
 * @var COATL_UCD_JG_KNOTTED_HEH
 *      '**Knotted_Heh**'
 * @var COATL_UCD_JG_LAM
 *      '**Lam**'
 * @var COATL_UCD_JG_LAMADH
 *      '**Lamadh**'
 * @var COATL_UCD_JG_MANICHAEAN_ALEPH
 *      '**Manichaean_Aleph**'
 * @var COATL_UCD_JG_MANICHAEAN_AYIN
 *      '**Manichaean_Ayin**'
 * @var COATL_UCD_JG_MANICHAEAN_BETH
 *      '**Manichaean_Beth**'
 * @var COATL_UCD_JG_MANICHAEAN_DALETH
 *      '**Manichaean_Daleth**'
 * @var COATL_UCD_JG_MANICHAEAN_DHAMEDH
 *      '**Manichaean_Dhamedh**'
 * @var COATL_UCD_JG_MANICHAEAN_FIVE
 *      '**Manichaean_Five**'
 * @var COATL_UCD_JG_MANICHAEAN_GIMEL
 *      '**Manichaean_Gimel**'
 * @var COATL_UCD_JG_MANICHAEAN_HETH
 *      '**Manichaean_Heth**'
 * @var COATL_UCD_JG_MANICHAEAN_HUNDRED
 *      '**Manichaean_Hundred**'
 * @var COATL_UCD_JG_MANICHAEAN_KAPH
 *      '**Manichaean_Kaph**'
 * @var COATL_UCD_JG_MANICHAEAN_LAMEDH
 *      '**Manichaean_Lamedh**'
 * @var COATL_UCD_JG_MANICHAEAN_MEM
 *      '**Manichaean_Mem**'
 * @var COATL_UCD_JG_MANICHAEAN_NUN
 *      '**Manichaean_Nun**'
 * @var COATL_UCD_JG_MANICHAEAN_ONE
 *      '**Manichaean_One**'
 * @var COATL_UCD_JG_MANICHAEAN_PE
 *      '**Manichaean_Pe**'
 * @var COATL_UCD_JG_MANICHAEAN_QOPH
 *      '**Manichaean_Qoph**'
 * @var COATL_UCD_JG_MANICHAEAN_RESH
 *      '**Manichaean_Resh**'
 * @var COATL_UCD_JG_MANICHAEAN_SADHE
 *      '**Manichaean_Sadhe**'
 * @var COATL_UCD_JG_MANICHAEAN_SAMEKH
 *      '**Manichaean_Samekh**'
 * @var COATL_UCD_JG_MANICHAEAN_TAW
 *      '**Manichaean_Taw**'
 * @var COATL_UCD_JG_MANICHAEAN_TEN
 *      '**Manichaean_Ten**'
 * @var COATL_UCD_JG_MANICHAEAN_TETH
 *      '**Manichaean_Teth**'
 * @var COATL_UCD_JG_MANICHAEAN_THAMEDH
 *      '**Manichaean_Thamedh**'
 * @var COATL_UCD_JG_MANICHAEAN_TWENTY
 *      '**Manichaean_Twenty**'
 * @var COATL_UCD_JG_MANICHAEAN_WAW
 *      '**Manichaean_Waw**'
 * @var COATL_UCD_JG_MANICHAEAN_YODH
 *      '**Manichaean_Yodh**'
 * @var COATL_UCD_JG_MANICHAEAN_ZAYIN
 *      '**Manichaean_Zayin**'
 * @var COATL_UCD_JG_MEEM
 *      '**Meem**'
 * @var COATL_UCD_JG_MIM
 *      '**Mim**'
 * @var COATL_UCD_JG_NO_JOINING_GROUP
 *      '**No_Joining_Group**'
 * @var COATL_UCD_JG_NOON
 *      '**Noon**'
 * @var COATL_UCD_JG_NUN
 *      '**Nun**'
 * @var COATL_UCD_JG_NYA
 *      '**Nya**'
 * @var COATL_UCD_JG_PE
 *      '**Pe**'
 * @var COATL_UCD_JG_QAF
 *      '**Qaf**'
 * @var COATL_UCD_JG_QAPH
 *      '**Qaph**'
 * @var COATL_UCD_JG_REH
 *      '**Reh**'
 * @var COATL_UCD_JG_REVERSED_PE
 *      '**Reversed_Pe**'
 * @var COATL_UCD_JG_ROHINGYA_YEH
 *      '**Rohingya_Yeh**'
 * @var COATL_UCD_JG_SAD
 *      '**Sad**'
 * @var COATL_UCD_JG_SADHE
 *      '**Sadhe**'
 * @var COATL_UCD_JG_SEEN
 *      '**Seen**'
 * @var COATL_UCD_JG_SEMKATH
 *      '**Semkath**'
 * @var COATL_UCD_JG_SHIN
 *      '**Shin**'
 * @var COATL_UCD_JG_STRAIGHT_WAW
 *      '**Straight_Waw**'
 * @var COATL_UCD_JG_SWASH_KAF
 *      '**Swash_Kaf**'
 * @var COATL_UCD_JG_SYRIAC_WAW
 *      '**Syriac_Waw**'
 * @var COATL_UCD_JG_TAH
 *      '**Tah**'
 * @var COATL_UCD_JG_TAW
 *      '**Taw**'
 * @var COATL_UCD_JG_TEH_MARBUTA
 *      '**Teh_Marbuta**'
 * @var COATL_UCD_JG_TEH_MARBUTA_GOAL
 *      '**Teh_Marbuta_Goal**', '**Hamza_On_Heh_Goal**'
 * @var COATL_UCD_JG_HAMZA_ON_HEH_GOAL
 *      Alias for #COATL_UCD_JG_TEH_MARBUTA_GOAL
 * @var COATL_UCD_JG_TETH
 *      '**Teth**'
 * @var COATL_UCD_JG_WAW
 *      '**Waw**'
 * @var COATL_UCD_JG_YEH
 *      '**Yeh**'
 * @var COATL_UCD_JG_YEH_BARREE
 *      '**Yeh_Barree**'
 * @var COATL_UCD_JG_YEH_WITH_TAIL
 *      '**Yeh_With_Tail**'
 * @var COATL_UCD_JG_YUDH
 *      '**Yudh**'
 * @var COATL_UCD_JG_YUDH_HE
 *      '**Yudh_He**'
 * @var COATL_UCD_JG_ZAIN
 *      '**Zain**'
 * @var COATL_UCD_JG_ZHAIN
 *      '**Zhain**'
 */
typedef enum Coatl_Ucd_Jg {
    COATL_UCD_JG_AFRICAN_FEH=1,
    COATL_UCD_JG_AFRICAN_NOON=2,
    COATL_UCD_JG_AFRICAN_QAF=3,
    COATL_UCD_JG_AIN=4,
    COATL_UCD_JG_ALAPH=5,
    COATL_UCD_JG_ALEF=6,
    COATL_UCD_JG_BEH=7,
    COATL_UCD_JG_BETH=8,
    COATL_UCD_JG_BURUSHASKI_YEH_BARREE=9,
    COATL_UCD_JG_DAL=10,
    COATL_UCD_JG_DALATH_RISH=11,
    COATL_UCD_JG_E=12,
    COATL_UCD_JG_FARSI_YEH=13,
    COATL_UCD_JG_FE=14,
    COATL_UCD_JG_FEH=15,
    COATL_UCD_JG_FINAL_SEMKATH=16,
    COATL_UCD_JG_GAF=17,
    COATL_UCD_JG_GAMAL=18,
    COATL_UCD_JG_HAH=19,
    COATL_UCD_JG_HE=20,
    COATL_UCD_JG_HEH=21,
    COATL_UCD_JG_HEH_GOAL=22,
    COATL_UCD_JG_HETH=23,
    COATL_UCD_JG_KAF=24,
    COATL_UCD_JG_KAPH=25,
    COATL_UCD_JG_KHAPH=26,
    COATL_UCD_JG_KNOTTED_HEH=27,
    COATL_UCD_JG_LAM=28,
    COATL_UCD_JG_LAMADH=29,
    COATL_UCD_JG_MANICHAEAN_ALEPH=30,
    COATL_UCD_JG_MANICHAEAN_AYIN=31,
    COATL_UCD_JG_MANICHAEAN_BETH=32,
    COATL_UCD_JG_MANICHAEAN_DALETH=33,
    COATL_UCD_JG_MANICHAEAN_DHAMEDH=34,
    COATL_UCD_JG_MANICHAEAN_FIVE=35,
    COATL_UCD_JG_MANICHAEAN_GIMEL=36,
    COATL_UCD_JG_MANICHAEAN_HETH=37,
    COATL_UCD_JG_MANICHAEAN_HUNDRED=38,
    COATL_UCD_JG_MANICHAEAN_KAPH=39,
    COATL_UCD_JG_MANICHAEAN_LAMEDH=40,
    COATL_UCD_JG_MANICHAEAN_MEM=41,
    COATL_UCD_JG_MANICHAEAN_NUN=42,
    COATL_UCD_JG_MANICHAEAN_ONE=43,
    COATL_UCD_JG_MANICHAEAN_PE=44,
    COATL_UCD_JG_MANICHAEAN_QOPH=45,
    COATL_UCD_JG_MANICHAEAN_RESH=46,
    COATL_UCD_JG_MANICHAEAN_SADHE=47,
    COATL_UCD_JG_MANICHAEAN_SAMEKH=48,
    COATL_UCD_JG_MANICHAEAN_TAW=49,
    COATL_UCD_JG_MANICHAEAN_TEN=50,
    COATL_UCD_JG_MANICHAEAN_TETH=51,
    COATL_UCD_JG_MANICHAEAN_THAMEDH=52,
    COATL_UCD_JG_MANICHAEAN_TWENTY=53,
    COATL_UCD_JG_MANICHAEAN_WAW=54,
    COATL_UCD_JG_MANICHAEAN_YODH=55,
    COATL_UCD_JG_MANICHAEAN_ZAYIN=56,
    COATL_UCD_JG_MEEM=57,
    COATL_UCD_JG_MIM=58,
    COATL_UCD_JG_NO_JOINING_GROUP=59,
    COATL_UCD_JG_NOON=60,
    COATL_UCD_JG_NUN=61,
    COATL_UCD_JG_NYA=62,
    COATL_UCD_JG_PE=63,
    COATL_UCD_JG_QAF=64,
    COATL_UCD_JG_QAPH=65,
    COATL_UCD_JG_REH=66,
    COATL_UCD_JG_REVERSED_PE=67,
    COATL_UCD_JG_ROHINGYA_YEH=68,
    COATL_UCD_JG_SAD=69,
    COATL_UCD_JG_SADHE=70,
    COATL_UCD_JG_SEEN=71,
    COATL_UCD_JG_SEMKATH=72,
    COATL_UCD_JG_SHIN=73,
    COATL_UCD_JG_STRAIGHT_WAW=74,
    COATL_UCD_JG_SWASH_KAF=75,
    COATL_UCD_JG_SYRIAC_WAW=76,
    COATL_UCD_JG_TAH=77,
    COATL_UCD_JG_TAW=78,
    COATL_UCD_JG_TEH_MARBUTA=79,
    COATL_UCD_JG_TEH_MARBUTA_GOAL=80,
        COATL_UCD_JG_HAMZA_ON_HEH_GOAL=COATL_UCD_JG_TEH_MARBUTA_GOAL,
    COATL_UCD_JG_TETH=81,
    COATL_UCD_JG_WAW=82,
    COATL_UCD_JG_YEH=83,
    COATL_UCD_JG_YEH_BARREE=84,
    COATL_UCD_JG_YEH_WITH_TAIL=85,
    COATL_UCD_JG_YUDH=86,
    COATL_UCD_JG_YUDH_HE=87,
    COATL_UCD_JG_ZAIN=88,
    COATL_UCD_JG_ZHAIN=89,

} Coatl_Ucd_Jg;

/**
 * Number of values for Unicode character property '*jg*'.
 *
 * @see Coatl_Ucd_Jg
 */
#define COATL_UCD_JG_NBVALUES        89

/**
 * @enum Coatl_Ucd_Jt
 *      Values for Unicode character property '**jt**'.
 *
 *      Names are automatically generated from the UCD file
 *      `PropertyValueAliases.txt`.
 *
 * @see COATL_UCD_JT
 *
 * @var COATL_UCD_JT_C
 *      '**C**', '**Join_Causing**'
 * @var COATL_UCD_JT_JOIN_CAUSING
 *      Alias for #COATL_UCD_JT_C
 * @var COATL_UCD_JT_D
 *      '**D**', '**Dual_Joining**'
 * @var COATL_UCD_JT_DUAL_JOINING
 *      Alias for #COATL_UCD_JT_D
 * @var COATL_UCD_JT_L
 *      '**L**', '**Left_Joining**'
 * @var COATL_UCD_JT_LEFT_JOINING
 *      Alias for #COATL_UCD_JT_L
 * @var COATL_UCD_JT_R
 *      '**R**', '**Right_Joining**'
 * @var COATL_UCD_JT_RIGHT_JOINING
 *      Alias for #COATL_UCD_JT_R
 * @var COATL_UCD_JT_T
 *      '**T**', '**Transparent**'
 * @var COATL_UCD_JT_TRANSPARENT
 *      Alias for #COATL_UCD_JT_T
 * @var COATL_UCD_JT_U
 *      '**U**', '**Non_Joining**'
 * @var COATL_UCD_JT_NON_JOINING
 *      Alias for #COATL_UCD_JT_U
 */
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

/**
 * Number of values for Unicode character property '*jt*'.
 *
 * @see Coatl_Ucd_Jt
 */
#define COATL_UCD_JT_NBVALUES        6

/**
 * @enum Coatl_Ucd_Lb
 *      Values for Unicode character property '**lb**'.
 *
 *      Names are automatically generated from the UCD file
 *      `PropertyValueAliases.txt`.
 *
 * @see COATL_UCD_LB
 *
 * @var COATL_UCD_LB_AI
 *      '**AI**', '**Ambiguous**'
 * @var COATL_UCD_LB_AMBIGUOUS
 *      Alias for #COATL_UCD_LB_AI
 * @var COATL_UCD_LB_AL
 *      '**AL**', '**Alphabetic**'
 * @var COATL_UCD_LB_ALPHABETIC
 *      Alias for #COATL_UCD_LB_AL
 * @var COATL_UCD_LB_B2
 *      '**B2**', '**Break_Both**'
 * @var COATL_UCD_LB_BREAK_BOTH
 *      Alias for #COATL_UCD_LB_B2
 * @var COATL_UCD_LB_BA
 *      '**BA**', '**Break_After**'
 * @var COATL_UCD_LB_BREAK_AFTER
 *      Alias for #COATL_UCD_LB_BA
 * @var COATL_UCD_LB_BB
 *      '**BB**', '**Break_Before**'
 * @var COATL_UCD_LB_BREAK_BEFORE
 *      Alias for #COATL_UCD_LB_BB
 * @var COATL_UCD_LB_BK
 *      '**BK**', '**Mandatory_Break**'
 * @var COATL_UCD_LB_MANDATORY_BREAK
 *      Alias for #COATL_UCD_LB_BK
 * @var COATL_UCD_LB_CB
 *      '**CB**', '**Contingent_Break**'
 * @var COATL_UCD_LB_CONTINGENT_BREAK
 *      Alias for #COATL_UCD_LB_CB
 * @var COATL_UCD_LB_CJ
 *      '**CJ**', '**Conditional_Japanese_Starter**'
 * @var COATL_UCD_LB_CONDITIONAL_JAPANESE_STARTER
 *      Alias for #COATL_UCD_LB_CJ
 * @var COATL_UCD_LB_CL
 *      '**CL**', '**Close_Punctuation**'
 * @var COATL_UCD_LB_CLOSE_PUNCTUATION
 *      Alias for #COATL_UCD_LB_CL
 * @var COATL_UCD_LB_CM
 *      '**CM**', '**Combining_Mark**'
 * @var COATL_UCD_LB_COMBINING_MARK
 *      Alias for #COATL_UCD_LB_CM
 * @var COATL_UCD_LB_CP
 *      '**CP**', '**Close_Parenthesis**'
 * @var COATL_UCD_LB_CLOSE_PARENTHESIS
 *      Alias for #COATL_UCD_LB_CP
 * @var COATL_UCD_LB_CR
 *      '**CR**', '**Carriage_Return**'
 * @var COATL_UCD_LB_CARRIAGE_RETURN
 *      Alias for #COATL_UCD_LB_CR
 * @var COATL_UCD_LB_EB
 *      '**EB**', '**E_Base**'
 * @var COATL_UCD_LB_E_BASE
 *      Alias for #COATL_UCD_LB_EB
 * @var COATL_UCD_LB_EM
 *      '**EM**', '**E_Modifier**'
 * @var COATL_UCD_LB_E_MODIFIER
 *      Alias for #COATL_UCD_LB_EM
 * @var COATL_UCD_LB_EX
 *      '**EX**', '**Exclamation**'
 * @var COATL_UCD_LB_EXCLAMATION
 *      Alias for #COATL_UCD_LB_EX
 * @var COATL_UCD_LB_GL
 *      '**GL**', '**Glue**'
 * @var COATL_UCD_LB_GLUE
 *      Alias for #COATL_UCD_LB_GL
 * @var COATL_UCD_LB_H2
 *      '**H2**'
 * @var COATL_UCD_LB_H3
 *      '**H3**'
 * @var COATL_UCD_LB_HL
 *      '**HL**', '**Hebrew_Letter**'
 * @var COATL_UCD_LB_HEBREW_LETTER
 *      Alias for #COATL_UCD_LB_HL
 * @var COATL_UCD_LB_HY
 *      '**HY**', '**Hyphen**'
 * @var COATL_UCD_LB_HYPHEN
 *      Alias for #COATL_UCD_LB_HY
 * @var COATL_UCD_LB_ID
 *      '**ID**', '**Ideographic**'
 * @var COATL_UCD_LB_IDEOGRAPHIC
 *      Alias for #COATL_UCD_LB_ID
 * @var COATL_UCD_LB_IN
 *      '**IN**', '**Inseparable**', '**Inseperable**'
 * @var COATL_UCD_LB_INSEPARABLE
 *      Alias for #COATL_UCD_LB_IN
 * @var COATL_UCD_LB_INSEPERABLE
 *      Alias for #COATL_UCD_LB_IN
 * @var COATL_UCD_LB_IS
 *      '**IS**', '**Infix_Numeric**'
 * @var COATL_UCD_LB_INFIX_NUMERIC
 *      Alias for #COATL_UCD_LB_IS
 * @var COATL_UCD_LB_JL
 *      '**JL**'
 * @var COATL_UCD_LB_JT
 *      '**JT**'
 * @var COATL_UCD_LB_JV
 *      '**JV**'
 * @var COATL_UCD_LB_LF
 *      '**LF**', '**Line_Feed**'
 * @var COATL_UCD_LB_LINE_FEED
 *      Alias for #COATL_UCD_LB_LF
 * @var COATL_UCD_LB_NL
 *      '**NL**', '**Next_Line**'
 * @var COATL_UCD_LB_NEXT_LINE
 *      Alias for #COATL_UCD_LB_NL
 * @var COATL_UCD_LB_NS
 *      '**NS**', '**Nonstarter**'
 * @var COATL_UCD_LB_NONSTARTER
 *      Alias for #COATL_UCD_LB_NS
 * @var COATL_UCD_LB_NU
 *      '**NU**', '**Numeric**'
 * @var COATL_UCD_LB_NUMERIC
 *      Alias for #COATL_UCD_LB_NU
 * @var COATL_UCD_LB_OP
 *      '**OP**', '**Open_Punctuation**'
 * @var COATL_UCD_LB_OPEN_PUNCTUATION
 *      Alias for #COATL_UCD_LB_OP
 * @var COATL_UCD_LB_PO
 *      '**PO**', '**Postfix_Numeric**'
 * @var COATL_UCD_LB_POSTFIX_NUMERIC
 *      Alias for #COATL_UCD_LB_PO
 * @var COATL_UCD_LB_PR
 *      '**PR**', '**Prefix_Numeric**'
 * @var COATL_UCD_LB_PREFIX_NUMERIC
 *      Alias for #COATL_UCD_LB_PR
 * @var COATL_UCD_LB_QU
 *      '**QU**', '**Quotation**'
 * @var COATL_UCD_LB_QUOTATION
 *      Alias for #COATL_UCD_LB_QU
 * @var COATL_UCD_LB_RI
 *      '**RI**', '**Regional_Indicator**'
 * @var COATL_UCD_LB_REGIONAL_INDICATOR
 *      Alias for #COATL_UCD_LB_RI
 * @var COATL_UCD_LB_SA
 *      '**SA**', '**Complex_Context**'
 * @var COATL_UCD_LB_COMPLEX_CONTEXT
 *      Alias for #COATL_UCD_LB_SA
 * @var COATL_UCD_LB_SG
 *      '**SG**', '**Surrogate**'
 * @var COATL_UCD_LB_SURROGATE
 *      Alias for #COATL_UCD_LB_SG
 * @var COATL_UCD_LB_SP
 *      '**SP**', '**Space**'
 * @var COATL_UCD_LB_SPACE
 *      Alias for #COATL_UCD_LB_SP
 * @var COATL_UCD_LB_SY
 *      '**SY**', '**Break_Symbols**'
 * @var COATL_UCD_LB_BREAK_SYMBOLS
 *      Alias for #COATL_UCD_LB_SY
 * @var COATL_UCD_LB_WJ
 *      '**WJ**', '**Word_Joiner**'
 * @var COATL_UCD_LB_WORD_JOINER
 *      Alias for #COATL_UCD_LB_WJ
 * @var COATL_UCD_LB_XX
 *      '**XX**', '**Unknown**'
 * @var COATL_UCD_LB_UNKNOWN
 *      Alias for #COATL_UCD_LB_XX
 * @var COATL_UCD_LB_ZW
 *      '**ZW**', '**ZWSpace**'
 * @var COATL_UCD_LB_ZWSPACE
 *      Alias for #COATL_UCD_LB_ZW
 * @var COATL_UCD_LB_ZWJ
 *      '**ZWJ**'
 */
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
    COATL_UCD_LB_EB=13,
        COATL_UCD_LB_E_BASE=COATL_UCD_LB_EB,
    COATL_UCD_LB_EM=14,
        COATL_UCD_LB_E_MODIFIER=COATL_UCD_LB_EM,
    COATL_UCD_LB_EX=15,
        COATL_UCD_LB_EXCLAMATION=COATL_UCD_LB_EX,
    COATL_UCD_LB_GL=16,
        COATL_UCD_LB_GLUE=COATL_UCD_LB_GL,
    COATL_UCD_LB_H2=17,
    COATL_UCD_LB_H3=18,
    COATL_UCD_LB_HL=19,
        COATL_UCD_LB_HEBREW_LETTER=COATL_UCD_LB_HL,
    COATL_UCD_LB_HY=20,
        COATL_UCD_LB_HYPHEN=COATL_UCD_LB_HY,
    COATL_UCD_LB_ID=21,
        COATL_UCD_LB_IDEOGRAPHIC=COATL_UCD_LB_ID,
    COATL_UCD_LB_IN=22,
        COATL_UCD_LB_INSEPARABLE=COATL_UCD_LB_IN,
        COATL_UCD_LB_INSEPERABLE=COATL_UCD_LB_IN,
    COATL_UCD_LB_IS=23,
        COATL_UCD_LB_INFIX_NUMERIC=COATL_UCD_LB_IS,
    COATL_UCD_LB_JL=24,
    COATL_UCD_LB_JT=25,
    COATL_UCD_LB_JV=26,
    COATL_UCD_LB_LF=27,
        COATL_UCD_LB_LINE_FEED=COATL_UCD_LB_LF,
    COATL_UCD_LB_NL=28,
        COATL_UCD_LB_NEXT_LINE=COATL_UCD_LB_NL,
    COATL_UCD_LB_NS=29,
        COATL_UCD_LB_NONSTARTER=COATL_UCD_LB_NS,
    COATL_UCD_LB_NU=30,
        COATL_UCD_LB_NUMERIC=COATL_UCD_LB_NU,
    COATL_UCD_LB_OP=31,
        COATL_UCD_LB_OPEN_PUNCTUATION=COATL_UCD_LB_OP,
    COATL_UCD_LB_PO=32,
        COATL_UCD_LB_POSTFIX_NUMERIC=COATL_UCD_LB_PO,
    COATL_UCD_LB_PR=33,
        COATL_UCD_LB_PREFIX_NUMERIC=COATL_UCD_LB_PR,
    COATL_UCD_LB_QU=34,
        COATL_UCD_LB_QUOTATION=COATL_UCD_LB_QU,
    COATL_UCD_LB_RI=35,
        COATL_UCD_LB_REGIONAL_INDICATOR=COATL_UCD_LB_RI,
    COATL_UCD_LB_SA=36,
        COATL_UCD_LB_COMPLEX_CONTEXT=COATL_UCD_LB_SA,
    COATL_UCD_LB_SG=37,
        COATL_UCD_LB_SURROGATE=COATL_UCD_LB_SG,
    COATL_UCD_LB_SP=38,
        COATL_UCD_LB_SPACE=COATL_UCD_LB_SP,
    COATL_UCD_LB_SY=39,
        COATL_UCD_LB_BREAK_SYMBOLS=COATL_UCD_LB_SY,
    COATL_UCD_LB_WJ=40,
        COATL_UCD_LB_WORD_JOINER=COATL_UCD_LB_WJ,
    COATL_UCD_LB_XX=41,
        COATL_UCD_LB_UNKNOWN=COATL_UCD_LB_XX,
    COATL_UCD_LB_ZW=42,
        COATL_UCD_LB_ZWSPACE=COATL_UCD_LB_ZW,
    COATL_UCD_LB_ZWJ=43,

} Coatl_Ucd_Lb;

/**
 * Number of values for Unicode character property '*lb*'.
 *
 * @see Coatl_Ucd_Lb
 */
#define COATL_UCD_LB_NBVALUES        43

/**
 * @enum Coatl_Ucd_NFC_QC
 *      Values for Unicode character property '**NFC_QC**'.
 *
 *      Names are automatically generated from the UCD file
 *      `PropertyValueAliases.txt`.
 *
 * @see COATL_UCD_NFC_QC
 *
 * @var COATL_UCD_NFC_QC_M
 *      '**M**', '**Maybe**'
 * @var COATL_UCD_NFC_QC_MAYBE
 *      Alias for #COATL_UCD_NFC_QC_M
 * @var COATL_UCD_NFC_QC_N
 *      '**N**', '**No**'
 * @var COATL_UCD_NFC_QC_NO
 *      Alias for #COATL_UCD_NFC_QC_N
 * @var COATL_UCD_NFC_QC_Y
 *      '**Y**', '**Yes**'
 * @var COATL_UCD_NFC_QC_YES
 *      Alias for #COATL_UCD_NFC_QC_Y
 */
typedef enum Coatl_Ucd_NFC_QC {
    COATL_UCD_NFC_QC_M=1,
        COATL_UCD_NFC_QC_MAYBE=COATL_UCD_NFC_QC_M,
    COATL_UCD_NFC_QC_N=2,
        COATL_UCD_NFC_QC_NO=COATL_UCD_NFC_QC_N,
    COATL_UCD_NFC_QC_Y=3,
        COATL_UCD_NFC_QC_YES=COATL_UCD_NFC_QC_Y,

} Coatl_Ucd_NFC_QC;

/**
 * Number of values for Unicode character property '*NFC_QC*'.
 *
 * @see Coatl_Ucd_NFC_QC
 */
#define COATL_UCD_NFC_QC_NBVALUES    3

/**
 * @enum Coatl_Ucd_NFKC_QC
 *      Values for Unicode character property '**NFKC_QC**'.
 *
 *      Names are automatically generated from the UCD file
 *      `PropertyValueAliases.txt`.
 *
 * @see COATL_UCD_NFKC_QC
 *
 * @var COATL_UCD_NFKC_QC_M
 *      '**M**', '**Maybe**'
 * @var COATL_UCD_NFKC_QC_MAYBE
 *      Alias for #COATL_UCD_NFKC_QC_M
 * @var COATL_UCD_NFKC_QC_N
 *      '**N**', '**No**'
 * @var COATL_UCD_NFKC_QC_NO
 *      Alias for #COATL_UCD_NFKC_QC_N
 * @var COATL_UCD_NFKC_QC_Y
 *      '**Y**', '**Yes**'
 * @var COATL_UCD_NFKC_QC_YES
 *      Alias for #COATL_UCD_NFKC_QC_Y
 */
typedef enum Coatl_Ucd_NFKC_QC {
    COATL_UCD_NFKC_QC_M=1,
        COATL_UCD_NFKC_QC_MAYBE=COATL_UCD_NFKC_QC_M,
    COATL_UCD_NFKC_QC_N=2,
        COATL_UCD_NFKC_QC_NO=COATL_UCD_NFKC_QC_N,
    COATL_UCD_NFKC_QC_Y=3,
        COATL_UCD_NFKC_QC_YES=COATL_UCD_NFKC_QC_Y,

} Coatl_Ucd_NFKC_QC;

/**
 * Number of values for Unicode character property '*NFKC_QC*'.
 *
 * @see Coatl_Ucd_NFKC_QC
 */
#define COATL_UCD_NFKC_QC_NBVALUES   3

/**
 * @enum Coatl_Ucd_Nt
 *      Values for Unicode character property '**nt**'.
 *
 *      Names are automatically generated from the UCD file
 *      `PropertyValueAliases.txt`.
 *
 * @see COATL_UCD_NT
 *
 * @var COATL_UCD_NT_DE
 *      '**De**', '**Decimal**'
 * @var COATL_UCD_NT_DECIMAL
 *      Alias for #COATL_UCD_NT_DE
 * @var COATL_UCD_NT_DI
 *      '**Di**', '**Digit**'
 * @var COATL_UCD_NT_DIGIT
 *      Alias for #COATL_UCD_NT_DI
 * @var COATL_UCD_NT_NONE
 *      '**None**'
 * @var COATL_UCD_NT_NU
 *      '**Nu**', '**Numeric**'
 * @var COATL_UCD_NT_NUMERIC
 *      Alias for #COATL_UCD_NT_NU
 */
typedef enum Coatl_Ucd_Nt {
    COATL_UCD_NT_DE=1,
        COATL_UCD_NT_DECIMAL=COATL_UCD_NT_DE,
    COATL_UCD_NT_DI=2,
        COATL_UCD_NT_DIGIT=COATL_UCD_NT_DI,
    COATL_UCD_NT_NONE=3,
    COATL_UCD_NT_NU=4,
        COATL_UCD_NT_NUMERIC=COATL_UCD_NT_NU,

} Coatl_Ucd_Nt;

/**
 * Number of values for Unicode character property '*nt*'.
 *
 * @see Coatl_Ucd_Nt
 */
#define COATL_UCD_NT_NBVALUES        4

/**
 * @enum Coatl_Ucd_SB
 *      Values for Unicode character property '**SB**'.
 *
 *      Names are automatically generated from the UCD file
 *      `PropertyValueAliases.txt`.
 *
 * @see COATL_UCD_SB
 *
 * @var COATL_UCD_SB_AT
 *      '**AT**', '**ATerm**'
 * @var COATL_UCD_SB_ATERM
 *      Alias for #COATL_UCD_SB_AT
 * @var COATL_UCD_SB_CL
 *      '**CL**', '**Close**'
 * @var COATL_UCD_SB_CLOSE
 *      Alias for #COATL_UCD_SB_CL
 * @var COATL_UCD_SB_CR
 *      '**CR**'
 * @var COATL_UCD_SB_EX
 *      '**EX**', '**Extend**'
 * @var COATL_UCD_SB_EXTEND
 *      Alias for #COATL_UCD_SB_EX
 * @var COATL_UCD_SB_FO
 *      '**FO**', '**Format**'
 * @var COATL_UCD_SB_FORMAT
 *      Alias for #COATL_UCD_SB_FO
 * @var COATL_UCD_SB_LE
 *      '**LE**', '**OLetter**'
 * @var COATL_UCD_SB_OLETTER
 *      Alias for #COATL_UCD_SB_LE
 * @var COATL_UCD_SB_LF
 *      '**LF**'
 * @var COATL_UCD_SB_LO
 *      '**LO**', '**Lower**'
 * @var COATL_UCD_SB_LOWER
 *      Alias for #COATL_UCD_SB_LO
 * @var COATL_UCD_SB_NU
 *      '**NU**', '**Numeric**'
 * @var COATL_UCD_SB_NUMERIC
 *      Alias for #COATL_UCD_SB_NU
 * @var COATL_UCD_SB_SC
 *      '**SC**', '**SContinue**'
 * @var COATL_UCD_SB_SCONTINUE
 *      Alias for #COATL_UCD_SB_SC
 * @var COATL_UCD_SB_SE
 *      '**SE**', '**Sep**'
 * @var COATL_UCD_SB_SEP
 *      Alias for #COATL_UCD_SB_SE
 * @var COATL_UCD_SB_SP
 *      '**SP**', '**Sp**'
 * @var COATL_UCD_SB_ST
 *      '**ST**', '**STerm**'
 * @var COATL_UCD_SB_STERM
 *      Alias for #COATL_UCD_SB_ST
 * @var COATL_UCD_SB_UP
 *      '**UP**', '**Upper**'
 * @var COATL_UCD_SB_UPPER
 *      Alias for #COATL_UCD_SB_UP
 * @var COATL_UCD_SB_XX
 *      '**XX**', '**Other**'
 * @var COATL_UCD_SB_OTHER
 *      Alias for #COATL_UCD_SB_XX
 */
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

/**
 * Number of values for Unicode character property '*SB*'.
 *
 * @see Coatl_Ucd_SB
 */
#define COATL_UCD_SB_NBVALUES        15

/**
 * @enum Coatl_Ucd_Sc
 *      Values for Unicode character property '**sc**'.
 *
 *      Names are automatically generated from the UCD file
 *      `PropertyValueAliases.txt`.
 *
 * @see COATL_UCD_SC
 *
 * @var COATL_UCD_SC_ADLM
 *      '**Adlm**', '**Adlam**'
 * @var COATL_UCD_SC_ADLAM
 *      Alias for #COATL_UCD_SC_ADLM
 * @var COATL_UCD_SC_AGHB
 *      '**Aghb**', '**Caucasian_Albanian**'
 * @var COATL_UCD_SC_CAUCASIAN_ALBANIAN
 *      Alias for #COATL_UCD_SC_AGHB
 * @var COATL_UCD_SC_AHOM
 *      '**Ahom**'
 * @var COATL_UCD_SC_ARAB
 *      '**Arab**', '**Arabic**'
 * @var COATL_UCD_SC_ARABIC
 *      Alias for #COATL_UCD_SC_ARAB
 * @var COATL_UCD_SC_ARMI
 *      '**Armi**', '**Imperial_Aramaic**'
 * @var COATL_UCD_SC_IMPERIAL_ARAMAIC
 *      Alias for #COATL_UCD_SC_ARMI
 * @var COATL_UCD_SC_ARMN
 *      '**Armn**', '**Armenian**'
 * @var COATL_UCD_SC_ARMENIAN
 *      Alias for #COATL_UCD_SC_ARMN
 * @var COATL_UCD_SC_AVST
 *      '**Avst**', '**Avestan**'
 * @var COATL_UCD_SC_AVESTAN
 *      Alias for #COATL_UCD_SC_AVST
 * @var COATL_UCD_SC_BALI
 *      '**Bali**', '**Balinese**'
 * @var COATL_UCD_SC_BALINESE
 *      Alias for #COATL_UCD_SC_BALI
 * @var COATL_UCD_SC_BAMU
 *      '**Bamu**', '**Bamum**'
 * @var COATL_UCD_SC_BAMUM
 *      Alias for #COATL_UCD_SC_BAMU
 * @var COATL_UCD_SC_BASS
 *      '**Bass**', '**Bassa_Vah**'
 * @var COATL_UCD_SC_BASSA_VAH
 *      Alias for #COATL_UCD_SC_BASS
 * @var COATL_UCD_SC_BATK
 *      '**Batk**', '**Batak**'
 * @var COATL_UCD_SC_BATAK
 *      Alias for #COATL_UCD_SC_BATK
 * @var COATL_UCD_SC_BENG
 *      '**Beng**', '**Bengali**'
 * @var COATL_UCD_SC_BENGALI
 *      Alias for #COATL_UCD_SC_BENG
 * @var COATL_UCD_SC_BHKS
 *      '**Bhks**', '**Bhaiksuki**'
 * @var COATL_UCD_SC_BHAIKSUKI
 *      Alias for #COATL_UCD_SC_BHKS
 * @var COATL_UCD_SC_BOPO
 *      '**Bopo**', '**Bopomofo**'
 * @var COATL_UCD_SC_BOPOMOFO
 *      Alias for #COATL_UCD_SC_BOPO
 * @var COATL_UCD_SC_BRAH
 *      '**Brah**', '**Brahmi**'
 * @var COATL_UCD_SC_BRAHMI
 *      Alias for #COATL_UCD_SC_BRAH
 * @var COATL_UCD_SC_BRAI
 *      '**Brai**', '**Braille**'
 * @var COATL_UCD_SC_BRAILLE
 *      Alias for #COATL_UCD_SC_BRAI
 * @var COATL_UCD_SC_BUGI
 *      '**Bugi**', '**Buginese**'
 * @var COATL_UCD_SC_BUGINESE
 *      Alias for #COATL_UCD_SC_BUGI
 * @var COATL_UCD_SC_BUHD
 *      '**Buhd**', '**Buhid**'
 * @var COATL_UCD_SC_BUHID
 *      Alias for #COATL_UCD_SC_BUHD
 * @var COATL_UCD_SC_CAKM
 *      '**Cakm**', '**Chakma**'
 * @var COATL_UCD_SC_CHAKMA
 *      Alias for #COATL_UCD_SC_CAKM
 * @var COATL_UCD_SC_CANS
 *      '**Cans**', '**Canadian_Aboriginal**'
 * @var COATL_UCD_SC_CANADIAN_ABORIGINAL
 *      Alias for #COATL_UCD_SC_CANS
 * @var COATL_UCD_SC_CARI
 *      '**Cari**', '**Carian**'
 * @var COATL_UCD_SC_CARIAN
 *      Alias for #COATL_UCD_SC_CARI
 * @var COATL_UCD_SC_CHAM
 *      '**Cham**'
 * @var COATL_UCD_SC_CHER
 *      '**Cher**', '**Cherokee**'
 * @var COATL_UCD_SC_CHEROKEE
 *      Alias for #COATL_UCD_SC_CHER
 * @var COATL_UCD_SC_COPT
 *      '**Copt**', '**Coptic**', '**Qaac**'
 * @var COATL_UCD_SC_COPTIC
 *      Alias for #COATL_UCD_SC_COPT
 * @var COATL_UCD_SC_QAAC
 *      Alias for #COATL_UCD_SC_COPT
 * @var COATL_UCD_SC_CPRT
 *      '**Cprt**', '**Cypriot**'
 * @var COATL_UCD_SC_CYPRIOT
 *      Alias for #COATL_UCD_SC_CPRT
 * @var COATL_UCD_SC_CYRL
 *      '**Cyrl**', '**Cyrillic**'
 * @var COATL_UCD_SC_CYRILLIC
 *      Alias for #COATL_UCD_SC_CYRL
 * @var COATL_UCD_SC_DEVA
 *      '**Deva**', '**Devanagari**'
 * @var COATL_UCD_SC_DEVANAGARI
 *      Alias for #COATL_UCD_SC_DEVA
 * @var COATL_UCD_SC_DSRT
 *      '**Dsrt**', '**Deseret**'
 * @var COATL_UCD_SC_DESERET
 *      Alias for #COATL_UCD_SC_DSRT
 * @var COATL_UCD_SC_DUPL
 *      '**Dupl**', '**Duployan**'
 * @var COATL_UCD_SC_DUPLOYAN
 *      Alias for #COATL_UCD_SC_DUPL
 * @var COATL_UCD_SC_EGYP
 *      '**Egyp**', '**Egyptian_Hieroglyphs**'
 * @var COATL_UCD_SC_EGYPTIAN_HIEROGLYPHS
 *      Alias for #COATL_UCD_SC_EGYP
 * @var COATL_UCD_SC_ELBA
 *      '**Elba**', '**Elbasan**'
 * @var COATL_UCD_SC_ELBASAN
 *      Alias for #COATL_UCD_SC_ELBA
 * @var COATL_UCD_SC_ETHI
 *      '**Ethi**', '**Ethiopic**'
 * @var COATL_UCD_SC_ETHIOPIC
 *      Alias for #COATL_UCD_SC_ETHI
 * @var COATL_UCD_SC_GEOR
 *      '**Geor**', '**Georgian**'
 * @var COATL_UCD_SC_GEORGIAN
 *      Alias for #COATL_UCD_SC_GEOR
 * @var COATL_UCD_SC_GLAG
 *      '**Glag**', '**Glagolitic**'
 * @var COATL_UCD_SC_GLAGOLITIC
 *      Alias for #COATL_UCD_SC_GLAG
 * @var COATL_UCD_SC_GOTH
 *      '**Goth**', '**Gothic**'
 * @var COATL_UCD_SC_GOTHIC
 *      Alias for #COATL_UCD_SC_GOTH
 * @var COATL_UCD_SC_GRAN
 *      '**Gran**', '**Grantha**'
 * @var COATL_UCD_SC_GRANTHA
 *      Alias for #COATL_UCD_SC_GRAN
 * @var COATL_UCD_SC_GREK
 *      '**Grek**', '**Greek**'
 * @var COATL_UCD_SC_GREEK
 *      Alias for #COATL_UCD_SC_GREK
 * @var COATL_UCD_SC_GUJR
 *      '**Gujr**', '**Gujarati**'
 * @var COATL_UCD_SC_GUJARATI
 *      Alias for #COATL_UCD_SC_GUJR
 * @var COATL_UCD_SC_GURU
 *      '**Guru**', '**Gurmukhi**'
 * @var COATL_UCD_SC_GURMUKHI
 *      Alias for #COATL_UCD_SC_GURU
 * @var COATL_UCD_SC_HANG
 *      '**Hang**', '**Hangul**'
 * @var COATL_UCD_SC_HANGUL
 *      Alias for #COATL_UCD_SC_HANG
 * @var COATL_UCD_SC_HANI
 *      '**Hani**', '**Han**'
 * @var COATL_UCD_SC_HAN
 *      Alias for #COATL_UCD_SC_HANI
 * @var COATL_UCD_SC_HANO
 *      '**Hano**', '**Hanunoo**'
 * @var COATL_UCD_SC_HANUNOO
 *      Alias for #COATL_UCD_SC_HANO
 * @var COATL_UCD_SC_HATR
 *      '**Hatr**', '**Hatran**'
 * @var COATL_UCD_SC_HATRAN
 *      Alias for #COATL_UCD_SC_HATR
 * @var COATL_UCD_SC_HEBR
 *      '**Hebr**', '**Hebrew**'
 * @var COATL_UCD_SC_HEBREW
 *      Alias for #COATL_UCD_SC_HEBR
 * @var COATL_UCD_SC_HIRA
 *      '**Hira**', '**Hiragana**'
 * @var COATL_UCD_SC_HIRAGANA
 *      Alias for #COATL_UCD_SC_HIRA
 * @var COATL_UCD_SC_HLUW
 *      '**Hluw**', '**Anatolian_Hieroglyphs**'
 * @var COATL_UCD_SC_ANATOLIAN_HIEROGLYPHS
 *      Alias for #COATL_UCD_SC_HLUW
 * @var COATL_UCD_SC_HMNG
 *      '**Hmng**', '**Pahawh_Hmong**'
 * @var COATL_UCD_SC_PAHAWH_HMONG
 *      Alias for #COATL_UCD_SC_HMNG
 * @var COATL_UCD_SC_HRKT
 *      '**Hrkt**', '**Katakana_Or_Hiragana**'
 * @var COATL_UCD_SC_KATAKANA_OR_HIRAGANA
 *      Alias for #COATL_UCD_SC_HRKT
 * @var COATL_UCD_SC_HUNG
 *      '**Hung**', '**Old_Hungarian**'
 * @var COATL_UCD_SC_OLD_HUNGARIAN
 *      Alias for #COATL_UCD_SC_HUNG
 * @var COATL_UCD_SC_ITAL
 *      '**Ital**', '**Old_Italic**'
 * @var COATL_UCD_SC_OLD_ITALIC
 *      Alias for #COATL_UCD_SC_ITAL
 * @var COATL_UCD_SC_JAVA
 *      '**Java**', '**Javanese**'
 * @var COATL_UCD_SC_JAVANESE
 *      Alias for #COATL_UCD_SC_JAVA
 * @var COATL_UCD_SC_KALI
 *      '**Kali**', '**Kayah_Li**'
 * @var COATL_UCD_SC_KAYAH_LI
 *      Alias for #COATL_UCD_SC_KALI
 * @var COATL_UCD_SC_KANA
 *      '**Kana**', '**Katakana**'
 * @var COATL_UCD_SC_KATAKANA
 *      Alias for #COATL_UCD_SC_KANA
 * @var COATL_UCD_SC_KHAR
 *      '**Khar**', '**Kharoshthi**'
 * @var COATL_UCD_SC_KHAROSHTHI
 *      Alias for #COATL_UCD_SC_KHAR
 * @var COATL_UCD_SC_KHMR
 *      '**Khmr**', '**Khmer**'
 * @var COATL_UCD_SC_KHMER
 *      Alias for #COATL_UCD_SC_KHMR
 * @var COATL_UCD_SC_KHOJ
 *      '**Khoj**', '**Khojki**'
 * @var COATL_UCD_SC_KHOJKI
 *      Alias for #COATL_UCD_SC_KHOJ
 * @var COATL_UCD_SC_KNDA
 *      '**Knda**', '**Kannada**'
 * @var COATL_UCD_SC_KANNADA
 *      Alias for #COATL_UCD_SC_KNDA
 * @var COATL_UCD_SC_KTHI
 *      '**Kthi**', '**Kaithi**'
 * @var COATL_UCD_SC_KAITHI
 *      Alias for #COATL_UCD_SC_KTHI
 * @var COATL_UCD_SC_LANA
 *      '**Lana**', '**Tai_Tham**'
 * @var COATL_UCD_SC_TAI_THAM
 *      Alias for #COATL_UCD_SC_LANA
 * @var COATL_UCD_SC_LAOO
 *      '**Laoo**', '**Lao**'
 * @var COATL_UCD_SC_LAO
 *      Alias for #COATL_UCD_SC_LAOO
 * @var COATL_UCD_SC_LATN
 *      '**Latn**', '**Latin**'
 * @var COATL_UCD_SC_LATIN
 *      Alias for #COATL_UCD_SC_LATN
 * @var COATL_UCD_SC_LEPC
 *      '**Lepc**', '**Lepcha**'
 * @var COATL_UCD_SC_LEPCHA
 *      Alias for #COATL_UCD_SC_LEPC
 * @var COATL_UCD_SC_LIMB
 *      '**Limb**', '**Limbu**'
 * @var COATL_UCD_SC_LIMBU
 *      Alias for #COATL_UCD_SC_LIMB
 * @var COATL_UCD_SC_LINA
 *      '**Lina**', '**Linear_A**'
 * @var COATL_UCD_SC_LINEAR_A
 *      Alias for #COATL_UCD_SC_LINA
 * @var COATL_UCD_SC_LINB
 *      '**Linb**', '**Linear_B**'
 * @var COATL_UCD_SC_LINEAR_B
 *      Alias for #COATL_UCD_SC_LINB
 * @var COATL_UCD_SC_LISU
 *      '**Lisu**'
 * @var COATL_UCD_SC_LYCI
 *      '**Lyci**', '**Lycian**'
 * @var COATL_UCD_SC_LYCIAN
 *      Alias for #COATL_UCD_SC_LYCI
 * @var COATL_UCD_SC_LYDI
 *      '**Lydi**', '**Lydian**'
 * @var COATL_UCD_SC_LYDIAN
 *      Alias for #COATL_UCD_SC_LYDI
 * @var COATL_UCD_SC_MAHJ
 *      '**Mahj**', '**Mahajani**'
 * @var COATL_UCD_SC_MAHAJANI
 *      Alias for #COATL_UCD_SC_MAHJ
 * @var COATL_UCD_SC_MAND
 *      '**Mand**', '**Mandaic**'
 * @var COATL_UCD_SC_MANDAIC
 *      Alias for #COATL_UCD_SC_MAND
 * @var COATL_UCD_SC_MANI
 *      '**Mani**', '**Manichaean**'
 * @var COATL_UCD_SC_MANICHAEAN
 *      Alias for #COATL_UCD_SC_MANI
 * @var COATL_UCD_SC_MARC
 *      '**Marc**', '**Marchen**'
 * @var COATL_UCD_SC_MARCHEN
 *      Alias for #COATL_UCD_SC_MARC
 * @var COATL_UCD_SC_MEND
 *      '**Mend**', '**Mende_Kikakui**'
 * @var COATL_UCD_SC_MENDE_KIKAKUI
 *      Alias for #COATL_UCD_SC_MEND
 * @var COATL_UCD_SC_MERC
 *      '**Merc**', '**Meroitic_Cursive**'
 * @var COATL_UCD_SC_MEROITIC_CURSIVE
 *      Alias for #COATL_UCD_SC_MERC
 * @var COATL_UCD_SC_MERO
 *      '**Mero**', '**Meroitic_Hieroglyphs**'
 * @var COATL_UCD_SC_MEROITIC_HIEROGLYPHS
 *      Alias for #COATL_UCD_SC_MERO
 * @var COATL_UCD_SC_MLYM
 *      '**Mlym**', '**Malayalam**'
 * @var COATL_UCD_SC_MALAYALAM
 *      Alias for #COATL_UCD_SC_MLYM
 * @var COATL_UCD_SC_MODI
 *      '**Modi**'
 * @var COATL_UCD_SC_MONG
 *      '**Mong**', '**Mongolian**'
 * @var COATL_UCD_SC_MONGOLIAN
 *      Alias for #COATL_UCD_SC_MONG
 * @var COATL_UCD_SC_MROO
 *      '**Mroo**', '**Mro**'
 * @var COATL_UCD_SC_MRO
 *      Alias for #COATL_UCD_SC_MROO
 * @var COATL_UCD_SC_MTEI
 *      '**Mtei**', '**Meetei_Mayek**'
 * @var COATL_UCD_SC_MEETEI_MAYEK
 *      Alias for #COATL_UCD_SC_MTEI
 * @var COATL_UCD_SC_MULT
 *      '**Mult**', '**Multani**'
 * @var COATL_UCD_SC_MULTANI
 *      Alias for #COATL_UCD_SC_MULT
 * @var COATL_UCD_SC_MYMR
 *      '**Mymr**', '**Myanmar**'
 * @var COATL_UCD_SC_MYANMAR
 *      Alias for #COATL_UCD_SC_MYMR
 * @var COATL_UCD_SC_NARB
 *      '**Narb**', '**Old_North_Arabian**'
 * @var COATL_UCD_SC_OLD_NORTH_ARABIAN
 *      Alias for #COATL_UCD_SC_NARB
 * @var COATL_UCD_SC_NBAT
 *      '**Nbat**', '**Nabataean**'
 * @var COATL_UCD_SC_NABATAEAN
 *      Alias for #COATL_UCD_SC_NBAT
 * @var COATL_UCD_SC_NEWA
 *      '**Newa**'
 * @var COATL_UCD_SC_NKOO
 *      '**Nkoo**', '**Nko**'
 * @var COATL_UCD_SC_NKO
 *      Alias for #COATL_UCD_SC_NKOO
 * @var COATL_UCD_SC_OGAM
 *      '**Ogam**', '**Ogham**'
 * @var COATL_UCD_SC_OGHAM
 *      Alias for #COATL_UCD_SC_OGAM
 * @var COATL_UCD_SC_OLCK
 *      '**Olck**', '**Ol_Chiki**'
 * @var COATL_UCD_SC_OL_CHIKI
 *      Alias for #COATL_UCD_SC_OLCK
 * @var COATL_UCD_SC_ORKH
 *      '**Orkh**', '**Old_Turkic**'
 * @var COATL_UCD_SC_OLD_TURKIC
 *      Alias for #COATL_UCD_SC_ORKH
 * @var COATL_UCD_SC_ORYA
 *      '**Orya**', '**Oriya**'
 * @var COATL_UCD_SC_ORIYA
 *      Alias for #COATL_UCD_SC_ORYA
 * @var COATL_UCD_SC_OSGE
 *      '**Osge**', '**Osage**'
 * @var COATL_UCD_SC_OSAGE
 *      Alias for #COATL_UCD_SC_OSGE
 * @var COATL_UCD_SC_OSMA
 *      '**Osma**', '**Osmanya**'
 * @var COATL_UCD_SC_OSMANYA
 *      Alias for #COATL_UCD_SC_OSMA
 * @var COATL_UCD_SC_PALM
 *      '**Palm**', '**Palmyrene**'
 * @var COATL_UCD_SC_PALMYRENE
 *      Alias for #COATL_UCD_SC_PALM
 * @var COATL_UCD_SC_PAUC
 *      '**Pauc**', '**Pau_Cin_Hau**'
 * @var COATL_UCD_SC_PAU_CIN_HAU
 *      Alias for #COATL_UCD_SC_PAUC
 * @var COATL_UCD_SC_PERM
 *      '**Perm**', '**Old_Permic**'
 * @var COATL_UCD_SC_OLD_PERMIC
 *      Alias for #COATL_UCD_SC_PERM
 * @var COATL_UCD_SC_PHAG
 *      '**Phag**', '**Phags_Pa**'
 * @var COATL_UCD_SC_PHAGS_PA
 *      Alias for #COATL_UCD_SC_PHAG
 * @var COATL_UCD_SC_PHLI
 *      '**Phli**', '**Inscriptional_Pahlavi**'
 * @var COATL_UCD_SC_INSCRIPTIONAL_PAHLAVI
 *      Alias for #COATL_UCD_SC_PHLI
 * @var COATL_UCD_SC_PHLP
 *      '**Phlp**', '**Psalter_Pahlavi**'
 * @var COATL_UCD_SC_PSALTER_PAHLAVI
 *      Alias for #COATL_UCD_SC_PHLP
 * @var COATL_UCD_SC_PHNX
 *      '**Phnx**', '**Phoenician**'
 * @var COATL_UCD_SC_PHOENICIAN
 *      Alias for #COATL_UCD_SC_PHNX
 * @var COATL_UCD_SC_PLRD
 *      '**Plrd**', '**Miao**'
 * @var COATL_UCD_SC_MIAO
 *      Alias for #COATL_UCD_SC_PLRD
 * @var COATL_UCD_SC_PRTI
 *      '**Prti**', '**Inscriptional_Parthian**'
 * @var COATL_UCD_SC_INSCRIPTIONAL_PARTHIAN
 *      Alias for #COATL_UCD_SC_PRTI
 * @var COATL_UCD_SC_RJNG
 *      '**Rjng**', '**Rejang**'
 * @var COATL_UCD_SC_REJANG
 *      Alias for #COATL_UCD_SC_RJNG
 * @var COATL_UCD_SC_RUNR
 *      '**Runr**', '**Runic**'
 * @var COATL_UCD_SC_RUNIC
 *      Alias for #COATL_UCD_SC_RUNR
 * @var COATL_UCD_SC_SAMR
 *      '**Samr**', '**Samaritan**'
 * @var COATL_UCD_SC_SAMARITAN
 *      Alias for #COATL_UCD_SC_SAMR
 * @var COATL_UCD_SC_SARB
 *      '**Sarb**', '**Old_South_Arabian**'
 * @var COATL_UCD_SC_OLD_SOUTH_ARABIAN
 *      Alias for #COATL_UCD_SC_SARB
 * @var COATL_UCD_SC_SAUR
 *      '**Saur**', '**Saurashtra**'
 * @var COATL_UCD_SC_SAURASHTRA
 *      Alias for #COATL_UCD_SC_SAUR
 * @var COATL_UCD_SC_SGNW
 *      '**Sgnw**', '**SignWriting**'
 * @var COATL_UCD_SC_SIGNWRITING
 *      Alias for #COATL_UCD_SC_SGNW
 * @var COATL_UCD_SC_SHAW
 *      '**Shaw**', '**Shavian**'
 * @var COATL_UCD_SC_SHAVIAN
 *      Alias for #COATL_UCD_SC_SHAW
 * @var COATL_UCD_SC_SHRD
 *      '**Shrd**', '**Sharada**'
 * @var COATL_UCD_SC_SHARADA
 *      Alias for #COATL_UCD_SC_SHRD
 * @var COATL_UCD_SC_SIDD
 *      '**Sidd**', '**Siddham**'
 * @var COATL_UCD_SC_SIDDHAM
 *      Alias for #COATL_UCD_SC_SIDD
 * @var COATL_UCD_SC_SIND
 *      '**Sind**', '**Khudawadi**'
 * @var COATL_UCD_SC_KHUDAWADI
 *      Alias for #COATL_UCD_SC_SIND
 * @var COATL_UCD_SC_SINH
 *      '**Sinh**', '**Sinhala**'
 * @var COATL_UCD_SC_SINHALA
 *      Alias for #COATL_UCD_SC_SINH
 * @var COATL_UCD_SC_SORA
 *      '**Sora**', '**Sora_Sompeng**'
 * @var COATL_UCD_SC_SORA_SOMPENG
 *      Alias for #COATL_UCD_SC_SORA
 * @var COATL_UCD_SC_SUND
 *      '**Sund**', '**Sundanese**'
 * @var COATL_UCD_SC_SUNDANESE
 *      Alias for #COATL_UCD_SC_SUND
 * @var COATL_UCD_SC_SYLO
 *      '**Sylo**', '**Syloti_Nagri**'
 * @var COATL_UCD_SC_SYLOTI_NAGRI
 *      Alias for #COATL_UCD_SC_SYLO
 * @var COATL_UCD_SC_SYRC
 *      '**Syrc**', '**Syriac**'
 * @var COATL_UCD_SC_SYRIAC
 *      Alias for #COATL_UCD_SC_SYRC
 * @var COATL_UCD_SC_TAGB
 *      '**Tagb**', '**Tagbanwa**'
 * @var COATL_UCD_SC_TAGBANWA
 *      Alias for #COATL_UCD_SC_TAGB
 * @var COATL_UCD_SC_TAKR
 *      '**Takr**', '**Takri**'
 * @var COATL_UCD_SC_TAKRI
 *      Alias for #COATL_UCD_SC_TAKR
 * @var COATL_UCD_SC_TALE
 *      '**Tale**', '**Tai_Le**'
 * @var COATL_UCD_SC_TAI_LE
 *      Alias for #COATL_UCD_SC_TALE
 * @var COATL_UCD_SC_TALU
 *      '**Talu**', '**New_Tai_Lue**'
 * @var COATL_UCD_SC_NEW_TAI_LUE
 *      Alias for #COATL_UCD_SC_TALU
 * @var COATL_UCD_SC_TAML
 *      '**Taml**', '**Tamil**'
 * @var COATL_UCD_SC_TAMIL
 *      Alias for #COATL_UCD_SC_TAML
 * @var COATL_UCD_SC_TANG
 *      '**Tang**', '**Tangut**'
 * @var COATL_UCD_SC_TANGUT
 *      Alias for #COATL_UCD_SC_TANG
 * @var COATL_UCD_SC_TAVT
 *      '**Tavt**', '**Tai_Viet**'
 * @var COATL_UCD_SC_TAI_VIET
 *      Alias for #COATL_UCD_SC_TAVT
 * @var COATL_UCD_SC_TELU
 *      '**Telu**', '**Telugu**'
 * @var COATL_UCD_SC_TELUGU
 *      Alias for #COATL_UCD_SC_TELU
 * @var COATL_UCD_SC_TFNG
 *      '**Tfng**', '**Tifinagh**'
 * @var COATL_UCD_SC_TIFINAGH
 *      Alias for #COATL_UCD_SC_TFNG
 * @var COATL_UCD_SC_TGLG
 *      '**Tglg**', '**Tagalog**'
 * @var COATL_UCD_SC_TAGALOG
 *      Alias for #COATL_UCD_SC_TGLG
 * @var COATL_UCD_SC_THAA
 *      '**Thaa**', '**Thaana**'
 * @var COATL_UCD_SC_THAANA
 *      Alias for #COATL_UCD_SC_THAA
 * @var COATL_UCD_SC_THAI
 *      '**Thai**'
 * @var COATL_UCD_SC_TIBT
 *      '**Tibt**', '**Tibetan**'
 * @var COATL_UCD_SC_TIBETAN
 *      Alias for #COATL_UCD_SC_TIBT
 * @var COATL_UCD_SC_TIRH
 *      '**Tirh**', '**Tirhuta**'
 * @var COATL_UCD_SC_TIRHUTA
 *      Alias for #COATL_UCD_SC_TIRH
 * @var COATL_UCD_SC_UGAR
 *      '**Ugar**', '**Ugaritic**'
 * @var COATL_UCD_SC_UGARITIC
 *      Alias for #COATL_UCD_SC_UGAR
 * @var COATL_UCD_SC_VAII
 *      '**Vaii**', '**Vai**'
 * @var COATL_UCD_SC_VAI
 *      Alias for #COATL_UCD_SC_VAII
 * @var COATL_UCD_SC_WARA
 *      '**Wara**', '**Warang_Citi**'
 * @var COATL_UCD_SC_WARANG_CITI
 *      Alias for #COATL_UCD_SC_WARA
 * @var COATL_UCD_SC_XPEO
 *      '**Xpeo**', '**Old_Persian**'
 * @var COATL_UCD_SC_OLD_PERSIAN
 *      Alias for #COATL_UCD_SC_XPEO
 * @var COATL_UCD_SC_XSUX
 *      '**Xsux**', '**Cuneiform**'
 * @var COATL_UCD_SC_CUNEIFORM
 *      Alias for #COATL_UCD_SC_XSUX
 * @var COATL_UCD_SC_YIII
 *      '**Yiii**', '**Yi**'
 * @var COATL_UCD_SC_YI
 *      Alias for #COATL_UCD_SC_YIII
 * @var COATL_UCD_SC_ZINH
 *      '**Zinh**', '**Inherited**', '**Qaai**'
 * @var COATL_UCD_SC_INHERITED
 *      Alias for #COATL_UCD_SC_ZINH
 * @var COATL_UCD_SC_QAAI
 *      Alias for #COATL_UCD_SC_ZINH
 * @var COATL_UCD_SC_ZYYY
 *      '**Zyyy**', '**Common**'
 * @var COATL_UCD_SC_COMMON
 *      Alias for #COATL_UCD_SC_ZYYY
 * @var COATL_UCD_SC_ZZZZ
 *      '**Zzzz**', '**Unknown**'
 * @var COATL_UCD_SC_UNKNOWN
 *      Alias for #COATL_UCD_SC_ZZZZ
 */
typedef enum Coatl_Ucd_Sc {
    COATL_UCD_SC_ADLM=1,
        COATL_UCD_SC_ADLAM=COATL_UCD_SC_ADLM,
    COATL_UCD_SC_AGHB=2,
        COATL_UCD_SC_CAUCASIAN_ALBANIAN=COATL_UCD_SC_AGHB,
    COATL_UCD_SC_AHOM=3,
    COATL_UCD_SC_ARAB=4,
        COATL_UCD_SC_ARABIC=COATL_UCD_SC_ARAB,
    COATL_UCD_SC_ARMI=5,
        COATL_UCD_SC_IMPERIAL_ARAMAIC=COATL_UCD_SC_ARMI,
    COATL_UCD_SC_ARMN=6,
        COATL_UCD_SC_ARMENIAN=COATL_UCD_SC_ARMN,
    COATL_UCD_SC_AVST=7,
        COATL_UCD_SC_AVESTAN=COATL_UCD_SC_AVST,
    COATL_UCD_SC_BALI=8,
        COATL_UCD_SC_BALINESE=COATL_UCD_SC_BALI,
    COATL_UCD_SC_BAMU=9,
        COATL_UCD_SC_BAMUM=COATL_UCD_SC_BAMU,
    COATL_UCD_SC_BASS=10,
        COATL_UCD_SC_BASSA_VAH=COATL_UCD_SC_BASS,
    COATL_UCD_SC_BATK=11,
        COATL_UCD_SC_BATAK=COATL_UCD_SC_BATK,
    COATL_UCD_SC_BENG=12,
        COATL_UCD_SC_BENGALI=COATL_UCD_SC_BENG,
    COATL_UCD_SC_BHKS=13,
        COATL_UCD_SC_BHAIKSUKI=COATL_UCD_SC_BHKS,
    COATL_UCD_SC_BOPO=14,
        COATL_UCD_SC_BOPOMOFO=COATL_UCD_SC_BOPO,
    COATL_UCD_SC_BRAH=15,
        COATL_UCD_SC_BRAHMI=COATL_UCD_SC_BRAH,
    COATL_UCD_SC_BRAI=16,
        COATL_UCD_SC_BRAILLE=COATL_UCD_SC_BRAI,
    COATL_UCD_SC_BUGI=17,
        COATL_UCD_SC_BUGINESE=COATL_UCD_SC_BUGI,
    COATL_UCD_SC_BUHD=18,
        COATL_UCD_SC_BUHID=COATL_UCD_SC_BUHD,
    COATL_UCD_SC_CAKM=19,
        COATL_UCD_SC_CHAKMA=COATL_UCD_SC_CAKM,
    COATL_UCD_SC_CANS=20,
        COATL_UCD_SC_CANADIAN_ABORIGINAL=COATL_UCD_SC_CANS,
    COATL_UCD_SC_CARI=21,
        COATL_UCD_SC_CARIAN=COATL_UCD_SC_CARI,
    COATL_UCD_SC_CHAM=22,
    COATL_UCD_SC_CHER=23,
        COATL_UCD_SC_CHEROKEE=COATL_UCD_SC_CHER,
    COATL_UCD_SC_COPT=24,
        COATL_UCD_SC_COPTIC=COATL_UCD_SC_COPT,
        COATL_UCD_SC_QAAC=COATL_UCD_SC_COPT,
    COATL_UCD_SC_CPRT=25,
        COATL_UCD_SC_CYPRIOT=COATL_UCD_SC_CPRT,
    COATL_UCD_SC_CYRL=26,
        COATL_UCD_SC_CYRILLIC=COATL_UCD_SC_CYRL,
    COATL_UCD_SC_DEVA=27,
        COATL_UCD_SC_DEVANAGARI=COATL_UCD_SC_DEVA,
    COATL_UCD_SC_DSRT=28,
        COATL_UCD_SC_DESERET=COATL_UCD_SC_DSRT,
    COATL_UCD_SC_DUPL=29,
        COATL_UCD_SC_DUPLOYAN=COATL_UCD_SC_DUPL,
    COATL_UCD_SC_EGYP=30,
        COATL_UCD_SC_EGYPTIAN_HIEROGLYPHS=COATL_UCD_SC_EGYP,
    COATL_UCD_SC_ELBA=31,
        COATL_UCD_SC_ELBASAN=COATL_UCD_SC_ELBA,
    COATL_UCD_SC_ETHI=32,
        COATL_UCD_SC_ETHIOPIC=COATL_UCD_SC_ETHI,
    COATL_UCD_SC_GEOR=33,
        COATL_UCD_SC_GEORGIAN=COATL_UCD_SC_GEOR,
    COATL_UCD_SC_GLAG=34,
        COATL_UCD_SC_GLAGOLITIC=COATL_UCD_SC_GLAG,
    COATL_UCD_SC_GOTH=35,
        COATL_UCD_SC_GOTHIC=COATL_UCD_SC_GOTH,
    COATL_UCD_SC_GRAN=36,
        COATL_UCD_SC_GRANTHA=COATL_UCD_SC_GRAN,
    COATL_UCD_SC_GREK=37,
        COATL_UCD_SC_GREEK=COATL_UCD_SC_GREK,
    COATL_UCD_SC_GUJR=38,
        COATL_UCD_SC_GUJARATI=COATL_UCD_SC_GUJR,
    COATL_UCD_SC_GURU=39,
        COATL_UCD_SC_GURMUKHI=COATL_UCD_SC_GURU,
    COATL_UCD_SC_HANG=40,
        COATL_UCD_SC_HANGUL=COATL_UCD_SC_HANG,
    COATL_UCD_SC_HANI=41,
        COATL_UCD_SC_HAN=COATL_UCD_SC_HANI,
    COATL_UCD_SC_HANO=42,
        COATL_UCD_SC_HANUNOO=COATL_UCD_SC_HANO,
    COATL_UCD_SC_HATR=43,
        COATL_UCD_SC_HATRAN=COATL_UCD_SC_HATR,
    COATL_UCD_SC_HEBR=44,
        COATL_UCD_SC_HEBREW=COATL_UCD_SC_HEBR,
    COATL_UCD_SC_HIRA=45,
        COATL_UCD_SC_HIRAGANA=COATL_UCD_SC_HIRA,
    COATL_UCD_SC_HLUW=46,
        COATL_UCD_SC_ANATOLIAN_HIEROGLYPHS=COATL_UCD_SC_HLUW,
    COATL_UCD_SC_HMNG=47,
        COATL_UCD_SC_PAHAWH_HMONG=COATL_UCD_SC_HMNG,
    COATL_UCD_SC_HRKT=48,
        COATL_UCD_SC_KATAKANA_OR_HIRAGANA=COATL_UCD_SC_HRKT,
    COATL_UCD_SC_HUNG=49,
        COATL_UCD_SC_OLD_HUNGARIAN=COATL_UCD_SC_HUNG,
    COATL_UCD_SC_ITAL=50,
        COATL_UCD_SC_OLD_ITALIC=COATL_UCD_SC_ITAL,
    COATL_UCD_SC_JAVA=51,
        COATL_UCD_SC_JAVANESE=COATL_UCD_SC_JAVA,
    COATL_UCD_SC_KALI=52,
        COATL_UCD_SC_KAYAH_LI=COATL_UCD_SC_KALI,
    COATL_UCD_SC_KANA=53,
        COATL_UCD_SC_KATAKANA=COATL_UCD_SC_KANA,
    COATL_UCD_SC_KHAR=54,
        COATL_UCD_SC_KHAROSHTHI=COATL_UCD_SC_KHAR,
    COATL_UCD_SC_KHMR=55,
        COATL_UCD_SC_KHMER=COATL_UCD_SC_KHMR,
    COATL_UCD_SC_KHOJ=56,
        COATL_UCD_SC_KHOJKI=COATL_UCD_SC_KHOJ,
    COATL_UCD_SC_KNDA=57,
        COATL_UCD_SC_KANNADA=COATL_UCD_SC_KNDA,
    COATL_UCD_SC_KTHI=58,
        COATL_UCD_SC_KAITHI=COATL_UCD_SC_KTHI,
    COATL_UCD_SC_LANA=59,
        COATL_UCD_SC_TAI_THAM=COATL_UCD_SC_LANA,
    COATL_UCD_SC_LAOO=60,
        COATL_UCD_SC_LAO=COATL_UCD_SC_LAOO,
    COATL_UCD_SC_LATN=61,
        COATL_UCD_SC_LATIN=COATL_UCD_SC_LATN,
    COATL_UCD_SC_LEPC=62,
        COATL_UCD_SC_LEPCHA=COATL_UCD_SC_LEPC,
    COATL_UCD_SC_LIMB=63,
        COATL_UCD_SC_LIMBU=COATL_UCD_SC_LIMB,
    COATL_UCD_SC_LINA=64,
        COATL_UCD_SC_LINEAR_A=COATL_UCD_SC_LINA,
    COATL_UCD_SC_LINB=65,
        COATL_UCD_SC_LINEAR_B=COATL_UCD_SC_LINB,
    COATL_UCD_SC_LISU=66,
    COATL_UCD_SC_LYCI=67,
        COATL_UCD_SC_LYCIAN=COATL_UCD_SC_LYCI,
    COATL_UCD_SC_LYDI=68,
        COATL_UCD_SC_LYDIAN=COATL_UCD_SC_LYDI,
    COATL_UCD_SC_MAHJ=69,
        COATL_UCD_SC_MAHAJANI=COATL_UCD_SC_MAHJ,
    COATL_UCD_SC_MAND=70,
        COATL_UCD_SC_MANDAIC=COATL_UCD_SC_MAND,
    COATL_UCD_SC_MANI=71,
        COATL_UCD_SC_MANICHAEAN=COATL_UCD_SC_MANI,
    COATL_UCD_SC_MARC=72,
        COATL_UCD_SC_MARCHEN=COATL_UCD_SC_MARC,
    COATL_UCD_SC_MEND=73,
        COATL_UCD_SC_MENDE_KIKAKUI=COATL_UCD_SC_MEND,
    COATL_UCD_SC_MERC=74,
        COATL_UCD_SC_MEROITIC_CURSIVE=COATL_UCD_SC_MERC,
    COATL_UCD_SC_MERO=75,
        COATL_UCD_SC_MEROITIC_HIEROGLYPHS=COATL_UCD_SC_MERO,
    COATL_UCD_SC_MLYM=76,
        COATL_UCD_SC_MALAYALAM=COATL_UCD_SC_MLYM,
    COATL_UCD_SC_MODI=77,
    COATL_UCD_SC_MONG=78,
        COATL_UCD_SC_MONGOLIAN=COATL_UCD_SC_MONG,
    COATL_UCD_SC_MROO=79,
        COATL_UCD_SC_MRO=COATL_UCD_SC_MROO,
    COATL_UCD_SC_MTEI=80,
        COATL_UCD_SC_MEETEI_MAYEK=COATL_UCD_SC_MTEI,
    COATL_UCD_SC_MULT=81,
        COATL_UCD_SC_MULTANI=COATL_UCD_SC_MULT,
    COATL_UCD_SC_MYMR=82,
        COATL_UCD_SC_MYANMAR=COATL_UCD_SC_MYMR,
    COATL_UCD_SC_NARB=83,
        COATL_UCD_SC_OLD_NORTH_ARABIAN=COATL_UCD_SC_NARB,
    COATL_UCD_SC_NBAT=84,
        COATL_UCD_SC_NABATAEAN=COATL_UCD_SC_NBAT,
    COATL_UCD_SC_NEWA=85,
    COATL_UCD_SC_NKOO=86,
        COATL_UCD_SC_NKO=COATL_UCD_SC_NKOO,
    COATL_UCD_SC_OGAM=87,
        COATL_UCD_SC_OGHAM=COATL_UCD_SC_OGAM,
    COATL_UCD_SC_OLCK=88,
        COATL_UCD_SC_OL_CHIKI=COATL_UCD_SC_OLCK,
    COATL_UCD_SC_ORKH=89,
        COATL_UCD_SC_OLD_TURKIC=COATL_UCD_SC_ORKH,
    COATL_UCD_SC_ORYA=90,
        COATL_UCD_SC_ORIYA=COATL_UCD_SC_ORYA,
    COATL_UCD_SC_OSGE=91,
        COATL_UCD_SC_OSAGE=COATL_UCD_SC_OSGE,
    COATL_UCD_SC_OSMA=92,
        COATL_UCD_SC_OSMANYA=COATL_UCD_SC_OSMA,
    COATL_UCD_SC_PALM=93,
        COATL_UCD_SC_PALMYRENE=COATL_UCD_SC_PALM,
    COATL_UCD_SC_PAUC=94,
        COATL_UCD_SC_PAU_CIN_HAU=COATL_UCD_SC_PAUC,
    COATL_UCD_SC_PERM=95,
        COATL_UCD_SC_OLD_PERMIC=COATL_UCD_SC_PERM,
    COATL_UCD_SC_PHAG=96,
        COATL_UCD_SC_PHAGS_PA=COATL_UCD_SC_PHAG,
    COATL_UCD_SC_PHLI=97,
        COATL_UCD_SC_INSCRIPTIONAL_PAHLAVI=COATL_UCD_SC_PHLI,
    COATL_UCD_SC_PHLP=98,
        COATL_UCD_SC_PSALTER_PAHLAVI=COATL_UCD_SC_PHLP,
    COATL_UCD_SC_PHNX=99,
        COATL_UCD_SC_PHOENICIAN=COATL_UCD_SC_PHNX,
    COATL_UCD_SC_PLRD=100,
        COATL_UCD_SC_MIAO=COATL_UCD_SC_PLRD,
    COATL_UCD_SC_PRTI=101,
        COATL_UCD_SC_INSCRIPTIONAL_PARTHIAN=COATL_UCD_SC_PRTI,
    COATL_UCD_SC_RJNG=102,
        COATL_UCD_SC_REJANG=COATL_UCD_SC_RJNG,
    COATL_UCD_SC_RUNR=103,
        COATL_UCD_SC_RUNIC=COATL_UCD_SC_RUNR,
    COATL_UCD_SC_SAMR=104,
        COATL_UCD_SC_SAMARITAN=COATL_UCD_SC_SAMR,
    COATL_UCD_SC_SARB=105,
        COATL_UCD_SC_OLD_SOUTH_ARABIAN=COATL_UCD_SC_SARB,
    COATL_UCD_SC_SAUR=106,
        COATL_UCD_SC_SAURASHTRA=COATL_UCD_SC_SAUR,
    COATL_UCD_SC_SGNW=107,
        COATL_UCD_SC_SIGNWRITING=COATL_UCD_SC_SGNW,
    COATL_UCD_SC_SHAW=108,
        COATL_UCD_SC_SHAVIAN=COATL_UCD_SC_SHAW,
    COATL_UCD_SC_SHRD=109,
        COATL_UCD_SC_SHARADA=COATL_UCD_SC_SHRD,
    COATL_UCD_SC_SIDD=110,
        COATL_UCD_SC_SIDDHAM=COATL_UCD_SC_SIDD,
    COATL_UCD_SC_SIND=111,
        COATL_UCD_SC_KHUDAWADI=COATL_UCD_SC_SIND,
    COATL_UCD_SC_SINH=112,
        COATL_UCD_SC_SINHALA=COATL_UCD_SC_SINH,
    COATL_UCD_SC_SORA=113,
        COATL_UCD_SC_SORA_SOMPENG=COATL_UCD_SC_SORA,
    COATL_UCD_SC_SUND=114,
        COATL_UCD_SC_SUNDANESE=COATL_UCD_SC_SUND,
    COATL_UCD_SC_SYLO=115,
        COATL_UCD_SC_SYLOTI_NAGRI=COATL_UCD_SC_SYLO,
    COATL_UCD_SC_SYRC=116,
        COATL_UCD_SC_SYRIAC=COATL_UCD_SC_SYRC,
    COATL_UCD_SC_TAGB=117,
        COATL_UCD_SC_TAGBANWA=COATL_UCD_SC_TAGB,
    COATL_UCD_SC_TAKR=118,
        COATL_UCD_SC_TAKRI=COATL_UCD_SC_TAKR,
    COATL_UCD_SC_TALE=119,
        COATL_UCD_SC_TAI_LE=COATL_UCD_SC_TALE,
    COATL_UCD_SC_TALU=120,
        COATL_UCD_SC_NEW_TAI_LUE=COATL_UCD_SC_TALU,
    COATL_UCD_SC_TAML=121,
        COATL_UCD_SC_TAMIL=COATL_UCD_SC_TAML,
    COATL_UCD_SC_TANG=122,
        COATL_UCD_SC_TANGUT=COATL_UCD_SC_TANG,
    COATL_UCD_SC_TAVT=123,
        COATL_UCD_SC_TAI_VIET=COATL_UCD_SC_TAVT,
    COATL_UCD_SC_TELU=124,
        COATL_UCD_SC_TELUGU=COATL_UCD_SC_TELU,
    COATL_UCD_SC_TFNG=125,
        COATL_UCD_SC_TIFINAGH=COATL_UCD_SC_TFNG,
    COATL_UCD_SC_TGLG=126,
        COATL_UCD_SC_TAGALOG=COATL_UCD_SC_TGLG,
    COATL_UCD_SC_THAA=127,
        COATL_UCD_SC_THAANA=COATL_UCD_SC_THAA,
    COATL_UCD_SC_THAI=128,
    COATL_UCD_SC_TIBT=129,
        COATL_UCD_SC_TIBETAN=COATL_UCD_SC_TIBT,
    COATL_UCD_SC_TIRH=130,
        COATL_UCD_SC_TIRHUTA=COATL_UCD_SC_TIRH,
    COATL_UCD_SC_UGAR=131,
        COATL_UCD_SC_UGARITIC=COATL_UCD_SC_UGAR,
    COATL_UCD_SC_VAII=132,
        COATL_UCD_SC_VAI=COATL_UCD_SC_VAII,
    COATL_UCD_SC_WARA=133,
        COATL_UCD_SC_WARANG_CITI=COATL_UCD_SC_WARA,
    COATL_UCD_SC_XPEO=134,
        COATL_UCD_SC_OLD_PERSIAN=COATL_UCD_SC_XPEO,
    COATL_UCD_SC_XSUX=135,
        COATL_UCD_SC_CUNEIFORM=COATL_UCD_SC_XSUX,
    COATL_UCD_SC_YIII=136,
        COATL_UCD_SC_YI=COATL_UCD_SC_YIII,
    COATL_UCD_SC_ZINH=137,
        COATL_UCD_SC_INHERITED=COATL_UCD_SC_ZINH,
        COATL_UCD_SC_QAAI=COATL_UCD_SC_ZINH,
    COATL_UCD_SC_ZYYY=138,
        COATL_UCD_SC_COMMON=COATL_UCD_SC_ZYYY,
    COATL_UCD_SC_ZZZZ=139,
        COATL_UCD_SC_UNKNOWN=COATL_UCD_SC_ZZZZ,

} Coatl_Ucd_Sc;

/**
 * Number of values for Unicode character property '*sc*'.
 *
 * @see Coatl_Ucd_Sc
 */
#define COATL_UCD_SC_NBVALUES        139

/**
 * @enum Coatl_Ucd_WB
 *      Values for Unicode character property '**WB**'.
 *
 *      Names are automatically generated from the UCD file
 *      `PropertyValueAliases.txt`.
 *
 * @see COATL_UCD_WB
 *
 * @var COATL_UCD_WB_CR
 *      '**CR**'
 * @var COATL_UCD_WB_DQ
 *      '**DQ**', '**Double_Quote**'
 * @var COATL_UCD_WB_DOUBLE_QUOTE
 *      Alias for #COATL_UCD_WB_DQ
 * @var COATL_UCD_WB_EB
 *      '**EB**', '**E_Base**'
 * @var COATL_UCD_WB_E_BASE
 *      Alias for #COATL_UCD_WB_EB
 * @var COATL_UCD_WB_EBG
 *      '**EBG**', '**E_Base_GAZ**'
 * @var COATL_UCD_WB_E_BASE_GAZ
 *      Alias for #COATL_UCD_WB_EBG
 * @var COATL_UCD_WB_EM
 *      '**EM**', '**E_Modifier**'
 * @var COATL_UCD_WB_E_MODIFIER
 *      Alias for #COATL_UCD_WB_EM
 * @var COATL_UCD_WB_EX
 *      '**EX**', '**ExtendNumLet**'
 * @var COATL_UCD_WB_EXTENDNUMLET
 *      Alias for #COATL_UCD_WB_EX
 * @var COATL_UCD_WB_EXTEND
 *      '**Extend**'
 * @var COATL_UCD_WB_FO
 *      '**FO**', '**Format**'
 * @var COATL_UCD_WB_FORMAT
 *      Alias for #COATL_UCD_WB_FO
 * @var COATL_UCD_WB_GAZ
 *      '**GAZ**', '**Glue_After_Zwj**'
 * @var COATL_UCD_WB_GLUE_AFTER_ZWJ
 *      Alias for #COATL_UCD_WB_GAZ
 * @var COATL_UCD_WB_HL
 *      '**HL**', '**Hebrew_Letter**'
 * @var COATL_UCD_WB_HEBREW_LETTER
 *      Alias for #COATL_UCD_WB_HL
 * @var COATL_UCD_WB_KA
 *      '**KA**', '**Katakana**'
 * @var COATL_UCD_WB_KATAKANA
 *      Alias for #COATL_UCD_WB_KA
 * @var COATL_UCD_WB_LE
 *      '**LE**', '**ALetter**'
 * @var COATL_UCD_WB_ALETTER
 *      Alias for #COATL_UCD_WB_LE
 * @var COATL_UCD_WB_LF
 *      '**LF**'
 * @var COATL_UCD_WB_MB
 *      '**MB**', '**MidNumLet**'
 * @var COATL_UCD_WB_MIDNUMLET
 *      Alias for #COATL_UCD_WB_MB
 * @var COATL_UCD_WB_ML
 *      '**ML**', '**MidLetter**'
 * @var COATL_UCD_WB_MIDLETTER
 *      Alias for #COATL_UCD_WB_ML
 * @var COATL_UCD_WB_MN
 *      '**MN**', '**MidNum**'
 * @var COATL_UCD_WB_MIDNUM
 *      Alias for #COATL_UCD_WB_MN
 * @var COATL_UCD_WB_NL
 *      '**NL**', '**Newline**'
 * @var COATL_UCD_WB_NEWLINE
 *      Alias for #COATL_UCD_WB_NL
 * @var COATL_UCD_WB_NU
 *      '**NU**', '**Numeric**'
 * @var COATL_UCD_WB_NUMERIC
 *      Alias for #COATL_UCD_WB_NU
 * @var COATL_UCD_WB_RI
 *      '**RI**', '**Regional_Indicator**'
 * @var COATL_UCD_WB_REGIONAL_INDICATOR
 *      Alias for #COATL_UCD_WB_RI
 * @var COATL_UCD_WB_SQ
 *      '**SQ**', '**Single_Quote**'
 * @var COATL_UCD_WB_SINGLE_QUOTE
 *      Alias for #COATL_UCD_WB_SQ
 * @var COATL_UCD_WB_XX
 *      '**XX**', '**Other**'
 * @var COATL_UCD_WB_OTHER
 *      Alias for #COATL_UCD_WB_XX
 * @var COATL_UCD_WB_ZWJ
 *      '**ZWJ**'
 */
typedef enum Coatl_Ucd_WB {
    COATL_UCD_WB_CR=1,
    COATL_UCD_WB_DQ=2,
        COATL_UCD_WB_DOUBLE_QUOTE=COATL_UCD_WB_DQ,
    COATL_UCD_WB_EB=3,
        COATL_UCD_WB_E_BASE=COATL_UCD_WB_EB,
    COATL_UCD_WB_EBG=4,
        COATL_UCD_WB_E_BASE_GAZ=COATL_UCD_WB_EBG,
    COATL_UCD_WB_EM=5,
        COATL_UCD_WB_E_MODIFIER=COATL_UCD_WB_EM,
    COATL_UCD_WB_EX=6,
        COATL_UCD_WB_EXTENDNUMLET=COATL_UCD_WB_EX,
    COATL_UCD_WB_EXTEND=7,
    COATL_UCD_WB_FO=8,
        COATL_UCD_WB_FORMAT=COATL_UCD_WB_FO,
    COATL_UCD_WB_GAZ=9,
        COATL_UCD_WB_GLUE_AFTER_ZWJ=COATL_UCD_WB_GAZ,
    COATL_UCD_WB_HL=10,
        COATL_UCD_WB_HEBREW_LETTER=COATL_UCD_WB_HL,
    COATL_UCD_WB_KA=11,
        COATL_UCD_WB_KATAKANA=COATL_UCD_WB_KA,
    COATL_UCD_WB_LE=12,
        COATL_UCD_WB_ALETTER=COATL_UCD_WB_LE,
    COATL_UCD_WB_LF=13,
    COATL_UCD_WB_MB=14,
        COATL_UCD_WB_MIDNUMLET=COATL_UCD_WB_MB,
    COATL_UCD_WB_ML=15,
        COATL_UCD_WB_MIDLETTER=COATL_UCD_WB_ML,
    COATL_UCD_WB_MN=16,
        COATL_UCD_WB_MIDNUM=COATL_UCD_WB_MN,
    COATL_UCD_WB_NL=17,
        COATL_UCD_WB_NEWLINE=COATL_UCD_WB_NL,
    COATL_UCD_WB_NU=18,
        COATL_UCD_WB_NUMERIC=COATL_UCD_WB_NU,
    COATL_UCD_WB_RI=19,
        COATL_UCD_WB_REGIONAL_INDICATOR=COATL_UCD_WB_RI,
    COATL_UCD_WB_SQ=20,
        COATL_UCD_WB_SINGLE_QUOTE=COATL_UCD_WB_SQ,
    COATL_UCD_WB_XX=21,
        COATL_UCD_WB_OTHER=COATL_UCD_WB_XX,
    COATL_UCD_WB_ZWJ=22,

} Coatl_Ucd_WB;

/**
 * Number of values for Unicode character property '*WB*'.
 *
 * @see Coatl_Ucd_WB
 */
#define COATL_UCD_WB_NBVALUES        22

/**
 * @enum Coatl_Ucd_Bpt
 *      Values for Unicode character property '**bpt**'.
 *
 *      Names are automatically generated from the UCD file
 *      `PropertyValueAliases.txt`.
 *
 * @see COATL_UCD_BPT
 *
 * @var COATL_UCD_BPT_C
 *      '**c**', '**Close**'
 * @var COATL_UCD_BPT_CLOSE
 *      Alias for #COATL_UCD_BPT_C
 * @var COATL_UCD_BPT_N
 *      '**n**', '**None**'
 * @var COATL_UCD_BPT_NONE
 *      Alias for #COATL_UCD_BPT_N
 * @var COATL_UCD_BPT_O
 *      '**o**', '**Open**'
 * @var COATL_UCD_BPT_OPEN
 *      Alias for #COATL_UCD_BPT_O
 */
typedef enum Coatl_Ucd_Bpt {
    COATL_UCD_BPT_C=1,
        COATL_UCD_BPT_CLOSE=COATL_UCD_BPT_C,
    COATL_UCD_BPT_N=2,
        COATL_UCD_BPT_NONE=COATL_UCD_BPT_N,
    COATL_UCD_BPT_O=3,
        COATL_UCD_BPT_OPEN=COATL_UCD_BPT_O,

} Coatl_Ucd_Bpt;

/**
 * Number of values for Unicode character property '*bpt*'.
 *
 * @see Coatl_Ucd_Bpt
 */
#define COATL_UCD_BPT_NBVALUES       3

/* End of UCD Properties *//*!\}*/

/* End of Unicode Character Database *//*!\}*/

#endif /* _COATL_UCDPROPERTIES */
