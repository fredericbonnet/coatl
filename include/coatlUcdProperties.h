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
 * Unicode character properties.
 *
 * Names are automatically generated from the UCD file `PropertyAliases.txt`.
 */
typedef enum Coatl_UcdProperty {
    /** '**nv**', '**Numeric_Value**' */
    COATL_UCD_NV=1,
        /** Alias for #COATL_UCD_NV */
        COATL_UCD_NUMERIC_VALUE=COATL_UCD_NV,

    /** '**cf**', '**Case_Folding**' */
    COATL_UCD_CF=2,
        /** Alias for #COATL_UCD_CF */
        COATL_UCD_CASE_FOLDING=COATL_UCD_CF,

    /** '**dm**', '**Decomposition_Mapping**' */
    COATL_UCD_DM=3,
        /** Alias for #COATL_UCD_DM */
        COATL_UCD_DECOMPOSITION_MAPPING=COATL_UCD_DM,

    /** '**lc**', '**Lowercase_Mapping**' */
    COATL_UCD_LC=4,
        /** Alias for #COATL_UCD_LC */
        COATL_UCD_LOWERCASE_MAPPING=COATL_UCD_LC,

    /** '**NFKC_CF**', '**NFKC_Casefold**' */
    COATL_UCD_NFKC_CF=5,
        /** Alias for #COATL_UCD_NFKC_CF */
        COATL_UCD_NFKC_CASEFOLD=COATL_UCD_NFKC_CF,

    /** '**scf**', '**Simple_Case_Folding**', '**sfc**' */
    COATL_UCD_SCF=6,
        /** Alias for #COATL_UCD_SCF */
        COATL_UCD_SIMPLE_CASE_FOLDING=COATL_UCD_SCF,
        /** Alias for #COATL_UCD_SCF */
        COATL_UCD_SFC=COATL_UCD_SCF,

    /** '**slc**', '**Simple_Lowercase_Mapping**' */
    COATL_UCD_SLC=7,
        /** Alias for #COATL_UCD_SLC */
        COATL_UCD_SIMPLE_LOWERCASE_MAPPING=COATL_UCD_SLC,

    /** '**stc**', '**Simple_Titlecase_Mapping**' */
    COATL_UCD_STC=8,
        /** Alias for #COATL_UCD_STC */
        COATL_UCD_SIMPLE_TITLECASE_MAPPING=COATL_UCD_STC,

    /** '**suc**', '**Simple_Uppercase_Mapping**' */
    COATL_UCD_SUC=9,
        /** Alias for #COATL_UCD_SUC */
        COATL_UCD_SIMPLE_UPPERCASE_MAPPING=COATL_UCD_SUC,

    /** '**tc**', '**Titlecase_Mapping**' */
    COATL_UCD_TC=10,
        /** Alias for #COATL_UCD_TC */
        COATL_UCD_TITLECASE_MAPPING=COATL_UCD_TC,

    /** '**uc**', '**Uppercase_Mapping**' */
    COATL_UCD_UC=11,
        /** Alias for #COATL_UCD_UC */
        COATL_UCD_UPPERCASE_MAPPING=COATL_UCD_UC,

    /** '**bmg**', '**Bidi_Mirroring_Glyph**' */
    COATL_UCD_BMG=12,
        /** Alias for #COATL_UCD_BMG */
        COATL_UCD_BIDI_MIRRORING_GLYPH=COATL_UCD_BMG,

    /** '**bpb**', '**Bidi_Paired_Bracket**' */
    COATL_UCD_BPB=13,
        /** Alias for #COATL_UCD_BPB */
        COATL_UCD_BIDI_PAIRED_BRACKET=COATL_UCD_BPB,

    /** '**JSN**', '**Jamo_Short_Name**' */
    COATL_UCD_JSN=14,
        /** Alias for #COATL_UCD_JSN */
        COATL_UCD_JAMO_SHORT_NAME=COATL_UCD_JSN,

    /** '**na**', '**Name**' */
    COATL_UCD_NA=15,
        /** Alias for #COATL_UCD_NA */
        COATL_UCD_NAME=COATL_UCD_NA,

    /** '**na1**', '**Unicode_1_Name**' */
    COATL_UCD_NA1=16,
        /** Alias for #COATL_UCD_NA1 */
        COATL_UCD_UNICODE_1_NAME=COATL_UCD_NA1,

    /** '**Name_Alias**', '**Name_Alias**' */
    COATL_UCD_NAME_ALIAS=17,

    /** '**scx**', '**Script_Extensions**' */
    COATL_UCD_SCX=18,
        /** Alias for #COATL_UCD_SCX */
        COATL_UCD_SCRIPT_EXTENSIONS=COATL_UCD_SCX,

    /** '**age**', '**Age**' */
    COATL_UCD_AGE=19,

    /** '**blk**', '**Block**' */
    COATL_UCD_BLK=20,
        /** Alias for #COATL_UCD_BLK */
        COATL_UCD_BLOCK=COATL_UCD_BLK,

    /** '**sc**', '**Script**' */
    COATL_UCD_SC=21,
        /** Alias for #COATL_UCD_SC */
        COATL_UCD_SCRIPT=COATL_UCD_SC,

    /** '**bc**', '**Bidi_Class**' */
    COATL_UCD_BC=22,
        /** Alias for #COATL_UCD_BC */
        COATL_UCD_BIDI_CLASS=COATL_UCD_BC,

    /** '**bpt**', '**Bidi_Paired_Bracket_Type**' */
    COATL_UCD_BPT=23,
        /** Alias for #COATL_UCD_BPT */
        COATL_UCD_BIDI_PAIRED_BRACKET_TYPE=COATL_UCD_BPT,

    /** '**ccc**', '**Canonical_Combining_Class**' */
    COATL_UCD_CCC=24,
        /** Alias for #COATL_UCD_CCC */
        COATL_UCD_CANONICAL_COMBINING_CLASS=COATL_UCD_CCC,

    /** '**dt**', '**Decomposition_Type**' */
    COATL_UCD_DT=25,
        /** Alias for #COATL_UCD_DT */
        COATL_UCD_DECOMPOSITION_TYPE=COATL_UCD_DT,

    /** '**ea**', '**East_Asian_Width**' */
    COATL_UCD_EA=26,
        /** Alias for #COATL_UCD_EA */
        COATL_UCD_EAST_ASIAN_WIDTH=COATL_UCD_EA,

    /** '**gc**', '**General_Category**' */
    COATL_UCD_GC=27,
        /** Alias for #COATL_UCD_GC */
        COATL_UCD_GENERAL_CATEGORY=COATL_UCD_GC,

    /** '**GCB**', '**Grapheme_Cluster_Break**' */
    COATL_UCD_GCB=28,
        /** Alias for #COATL_UCD_GCB */
        COATL_UCD_GRAPHEME_CLUSTER_BREAK=COATL_UCD_GCB,

    /** '**hst**', '**Hangul_Syllable_Type**' */
    COATL_UCD_HST=29,
        /** Alias for #COATL_UCD_HST */
        COATL_UCD_HANGUL_SYLLABLE_TYPE=COATL_UCD_HST,

    /** '**InPC**', '**Indic_Positional_Category**' */
    COATL_UCD_INPC=30,
        /** Alias for #COATL_UCD_INPC */
        COATL_UCD_INDIC_POSITIONAL_CATEGORY=COATL_UCD_INPC,

    /** '**InSC**', '**Indic_Syllabic_Category**' */
    COATL_UCD_INSC=31,
        /** Alias for #COATL_UCD_INSC */
        COATL_UCD_INDIC_SYLLABIC_CATEGORY=COATL_UCD_INSC,

    /** '**jg**', '**Joining_Group**' */
    COATL_UCD_JG=32,
        /** Alias for #COATL_UCD_JG */
        COATL_UCD_JOINING_GROUP=COATL_UCD_JG,

    /** '**jt**', '**Joining_Type**' */
    COATL_UCD_JT=33,
        /** Alias for #COATL_UCD_JT */
        COATL_UCD_JOINING_TYPE=COATL_UCD_JT,

    /** '**lb**', '**Line_Break**' */
    COATL_UCD_LB=34,
        /** Alias for #COATL_UCD_LB */
        COATL_UCD_LINE_BREAK=COATL_UCD_LB,

    /** '**NFC_QC**', '**NFC_Quick_Check**' */
    COATL_UCD_NFC_QC=35,
        /** Alias for #COATL_UCD_NFC_QC */
        COATL_UCD_NFC_QUICK_CHECK=COATL_UCD_NFC_QC,

    /** '**NFD_QC**', '**NFD_Quick_Check**' */
    COATL_UCD_NFD_QC=36,
        /** Alias for #COATL_UCD_NFD_QC */
        COATL_UCD_NFD_QUICK_CHECK=COATL_UCD_NFD_QC,

    /** '**NFKC_QC**', '**NFKC_Quick_Check**' */
    COATL_UCD_NFKC_QC=37,
        /** Alias for #COATL_UCD_NFKC_QC */
        COATL_UCD_NFKC_QUICK_CHECK=COATL_UCD_NFKC_QC,

    /** '**NFKD_QC**', '**NFKD_Quick_Check**' */
    COATL_UCD_NFKD_QC=38,
        /** Alias for #COATL_UCD_NFKD_QC */
        COATL_UCD_NFKD_QUICK_CHECK=COATL_UCD_NFKD_QC,

    /** '**nt**', '**Numeric_Type**' */
    COATL_UCD_NT=39,
        /** Alias for #COATL_UCD_NT */
        COATL_UCD_NUMERIC_TYPE=COATL_UCD_NT,

    /** '**SB**', '**Sentence_Break**' */
    COATL_UCD_SB=40,
        /** Alias for #COATL_UCD_SB */
        COATL_UCD_SENTENCE_BREAK=COATL_UCD_SB,

    /** '**vo**', '**Vertical_Orientation**' */
    COATL_UCD_VO=41,
        /** Alias for #COATL_UCD_VO */
        COATL_UCD_VERTICAL_ORIENTATION=COATL_UCD_VO,

    /** '**WB**', '**Word_Break**' */
    COATL_UCD_WB=42,
        /** Alias for #COATL_UCD_WB */
        COATL_UCD_WORD_BREAK=COATL_UCD_WB,

    /** '**AHex**', '**ASCII_Hex_Digit**' */
    COATL_UCD_AHEX=43,
        /** Alias for #COATL_UCD_AHEX */
        COATL_UCD_ASCII_HEX_DIGIT=COATL_UCD_AHEX,

    /** '**Alpha**', '**Alphabetic**' */
    COATL_UCD_ALPHA=44,
        /** Alias for #COATL_UCD_ALPHA */
        COATL_UCD_ALPHABETIC=COATL_UCD_ALPHA,

    /** '**Bidi_C**', '**Bidi_Control**' */
    COATL_UCD_BIDI_C=45,
        /** Alias for #COATL_UCD_BIDI_C */
        COATL_UCD_BIDI_CONTROL=COATL_UCD_BIDI_C,

    /** '**Bidi_M**', '**Bidi_Mirrored**' */
    COATL_UCD_BIDI_M=46,
        /** Alias for #COATL_UCD_BIDI_M */
        COATL_UCD_BIDI_MIRRORED=COATL_UCD_BIDI_M,

    /** '**Cased**', '**Cased**' */
    COATL_UCD_CASED=47,

    /** '**CE**', '**Composition_Exclusion**' */
    COATL_UCD_CE=48,
        /** Alias for #COATL_UCD_CE */
        COATL_UCD_COMPOSITION_EXCLUSION=COATL_UCD_CE,

    /** '**CI**', '**Case_Ignorable**' */
    COATL_UCD_CI=49,
        /** Alias for #COATL_UCD_CI */
        COATL_UCD_CASE_IGNORABLE=COATL_UCD_CI,

    /** '**Comp_Ex**', '**Full_Composition_Exclusion**' */
    COATL_UCD_COMP_EX=50,
        /** Alias for #COATL_UCD_COMP_EX */
        COATL_UCD_FULL_COMPOSITION_EXCLUSION=COATL_UCD_COMP_EX,

    /** '**CWCF**', '**Changes_When_Casefolded**' */
    COATL_UCD_CWCF=51,
        /** Alias for #COATL_UCD_CWCF */
        COATL_UCD_CHANGES_WHEN_CASEFOLDED=COATL_UCD_CWCF,

    /** '**CWCM**', '**Changes_When_Casemapped**' */
    COATL_UCD_CWCM=52,
        /** Alias for #COATL_UCD_CWCM */
        COATL_UCD_CHANGES_WHEN_CASEMAPPED=COATL_UCD_CWCM,

    /** '**CWKCF**', '**Changes_When_NFKC_Casefolded**' */
    COATL_UCD_CWKCF=53,
        /** Alias for #COATL_UCD_CWKCF */
        COATL_UCD_CHANGES_WHEN_NFKC_CASEFOLDED=COATL_UCD_CWKCF,

    /** '**CWL**', '**Changes_When_Lowercased**' */
    COATL_UCD_CWL=54,
        /** Alias for #COATL_UCD_CWL */
        COATL_UCD_CHANGES_WHEN_LOWERCASED=COATL_UCD_CWL,

    /** '**CWT**', '**Changes_When_Titlecased**' */
    COATL_UCD_CWT=55,
        /** Alias for #COATL_UCD_CWT */
        COATL_UCD_CHANGES_WHEN_TITLECASED=COATL_UCD_CWT,

    /** '**CWU**', '**Changes_When_Uppercased**' */
    COATL_UCD_CWU=56,
        /** Alias for #COATL_UCD_CWU */
        COATL_UCD_CHANGES_WHEN_UPPERCASED=COATL_UCD_CWU,

    /** '**Dash**', '**Dash**' */
    COATL_UCD_DASH=57,

    /** '**Dep**', '**Deprecated**' */
    COATL_UCD_DEP=58,
        /** Alias for #COATL_UCD_DEP */
        COATL_UCD_DEPRECATED=COATL_UCD_DEP,

    /** '**DI**', '**Default_Ignorable_Code_Point**' */
    COATL_UCD_DI=59,
        /** Alias for #COATL_UCD_DI */
        COATL_UCD_DEFAULT_IGNORABLE_CODE_POINT=COATL_UCD_DI,

    /** '**Dia**', '**Diacritic**' */
    COATL_UCD_DIA=60,
        /** Alias for #COATL_UCD_DIA */
        COATL_UCD_DIACRITIC=COATL_UCD_DIA,

    /** '**EBase**', '**Emoji_Modifier_Base**' */
    COATL_UCD_EBASE=61,
        /** Alias for #COATL_UCD_EBASE */
        COATL_UCD_EMOJI_MODIFIER_BASE=COATL_UCD_EBASE,

    /** '**EComp**', '**Emoji_Component**' */
    COATL_UCD_ECOMP=62,
        /** Alias for #COATL_UCD_ECOMP */
        COATL_UCD_EMOJI_COMPONENT=COATL_UCD_ECOMP,

    /** '**EMod**', '**Emoji_Modifier**' */
    COATL_UCD_EMOD=63,
        /** Alias for #COATL_UCD_EMOD */
        COATL_UCD_EMOJI_MODIFIER=COATL_UCD_EMOD,

    /** '**Emoji**', '**Emoji**' */
    COATL_UCD_EMOJI=64,

    /** '**EPres**', '**Emoji_Presentation**' */
    COATL_UCD_EPRES=65,
        /** Alias for #COATL_UCD_EPRES */
        COATL_UCD_EMOJI_PRESENTATION=COATL_UCD_EPRES,

    /** '**Ext**', '**Extender**' */
    COATL_UCD_EXT=66,
        /** Alias for #COATL_UCD_EXT */
        COATL_UCD_EXTENDER=COATL_UCD_EXT,

    /** '**ExtPict**', '**Extended_Pictographic**' */
    COATL_UCD_EXTPICT=67,
        /** Alias for #COATL_UCD_EXTPICT */
        COATL_UCD_EXTENDED_PICTOGRAPHIC=COATL_UCD_EXTPICT,

    /** '**Gr_Base**', '**Grapheme_Base**' */
    COATL_UCD_GR_BASE=68,
        /** Alias for #COATL_UCD_GR_BASE */
        COATL_UCD_GRAPHEME_BASE=COATL_UCD_GR_BASE,

    /** '**Gr_Ext**', '**Grapheme_Extend**' */
    COATL_UCD_GR_EXT=69,
        /** Alias for #COATL_UCD_GR_EXT */
        COATL_UCD_GRAPHEME_EXTEND=COATL_UCD_GR_EXT,

    /** '**Hex**', '**Hex_Digit**' */
    COATL_UCD_HEX=70,
        /** Alias for #COATL_UCD_HEX */
        COATL_UCD_HEX_DIGIT=COATL_UCD_HEX,

    /** '**IDC**', '**ID_Continue**' */
    COATL_UCD_IDC=71,
        /** Alias for #COATL_UCD_IDC */
        COATL_UCD_ID_CONTINUE=COATL_UCD_IDC,

    /** '**Ideo**', '**Ideographic**' */
    COATL_UCD_IDEO=72,
        /** Alias for #COATL_UCD_IDEO */
        COATL_UCD_IDEOGRAPHIC=COATL_UCD_IDEO,

    /** '**IDS**', '**ID_Start**' */
    COATL_UCD_IDS=73,
        /** Alias for #COATL_UCD_IDS */
        COATL_UCD_ID_START=COATL_UCD_IDS,

    /** '**IDSB**', '**IDS_Binary_Operator**' */
    COATL_UCD_IDSB=74,
        /** Alias for #COATL_UCD_IDSB */
        COATL_UCD_IDS_BINARY_OPERATOR=COATL_UCD_IDSB,

    /** '**IDST**', '**IDS_Trinary_Operator**' */
    COATL_UCD_IDST=75,
        /** Alias for #COATL_UCD_IDST */
        COATL_UCD_IDS_TRINARY_OPERATOR=COATL_UCD_IDST,

    /** '**Join_C**', '**Join_Control**' */
    COATL_UCD_JOIN_C=76,
        /** Alias for #COATL_UCD_JOIN_C */
        COATL_UCD_JOIN_CONTROL=COATL_UCD_JOIN_C,

    /** '**LOE**', '**Logical_Order_Exception**' */
    COATL_UCD_LOE=77,
        /** Alias for #COATL_UCD_LOE */
        COATL_UCD_LOGICAL_ORDER_EXCEPTION=COATL_UCD_LOE,

    /** '**Lower**', '**Lowercase**' */
    COATL_UCD_LOWER=78,
        /** Alias for #COATL_UCD_LOWER */
        COATL_UCD_LOWERCASE=COATL_UCD_LOWER,

    /** '**Math**', '**Math**' */
    COATL_UCD_MATH=79,

    /** '**NChar**', '**Noncharacter_Code_Point**' */
    COATL_UCD_NCHAR=80,
        /** Alias for #COATL_UCD_NCHAR */
        COATL_UCD_NONCHARACTER_CODE_POINT=COATL_UCD_NCHAR,

    /** '**OAlpha**', '**Other_Alphabetic**' */
    COATL_UCD_OALPHA=81,
        /** Alias for #COATL_UCD_OALPHA */
        COATL_UCD_OTHER_ALPHABETIC=COATL_UCD_OALPHA,

    /** '**ODI**', '**Other_Default_Ignorable_Code_Point**' */
    COATL_UCD_ODI=82,
        /** Alias for #COATL_UCD_ODI */
        COATL_UCD_OTHER_DEFAULT_IGNORABLE_CODE_POINT=COATL_UCD_ODI,

    /** '**OGr_Ext**', '**Other_Grapheme_Extend**' */
    COATL_UCD_OGR_EXT=83,
        /** Alias for #COATL_UCD_OGR_EXT */
        COATL_UCD_OTHER_GRAPHEME_EXTEND=COATL_UCD_OGR_EXT,

    /** '**OIDC**', '**Other_ID_Continue**' */
    COATL_UCD_OIDC=84,
        /** Alias for #COATL_UCD_OIDC */
        COATL_UCD_OTHER_ID_CONTINUE=COATL_UCD_OIDC,

    /** '**OIDS**', '**Other_ID_Start**' */
    COATL_UCD_OIDS=85,
        /** Alias for #COATL_UCD_OIDS */
        COATL_UCD_OTHER_ID_START=COATL_UCD_OIDS,

    /** '**OLower**', '**Other_Lowercase**' */
    COATL_UCD_OLOWER=86,
        /** Alias for #COATL_UCD_OLOWER */
        COATL_UCD_OTHER_LOWERCASE=COATL_UCD_OLOWER,

    /** '**OMath**', '**Other_Math**' */
    COATL_UCD_OMATH=87,
        /** Alias for #COATL_UCD_OMATH */
        COATL_UCD_OTHER_MATH=COATL_UCD_OMATH,

    /** '**OUpper**', '**Other_Uppercase**' */
    COATL_UCD_OUPPER=88,
        /** Alias for #COATL_UCD_OUPPER */
        COATL_UCD_OTHER_UPPERCASE=COATL_UCD_OUPPER,

    /** '**Pat_Syn**', '**Pattern_Syntax**' */
    COATL_UCD_PAT_SYN=89,
        /** Alias for #COATL_UCD_PAT_SYN */
        COATL_UCD_PATTERN_SYNTAX=COATL_UCD_PAT_SYN,

    /** '**Pat_WS**', '**Pattern_White_Space**' */
    COATL_UCD_PAT_WS=90,
        /** Alias for #COATL_UCD_PAT_WS */
        COATL_UCD_PATTERN_WHITE_SPACE=COATL_UCD_PAT_WS,

    /** '**PCM**', '**Prepended_Concatenation_Mark**' */
    COATL_UCD_PCM=91,
        /** Alias for #COATL_UCD_PCM */
        COATL_UCD_PREPENDED_CONCATENATION_MARK=COATL_UCD_PCM,

    /** '**QMark**', '**Quotation_Mark**' */
    COATL_UCD_QMARK=92,
        /** Alias for #COATL_UCD_QMARK */
        COATL_UCD_QUOTATION_MARK=COATL_UCD_QMARK,

    /** '**Radical**', '**Radical**' */
    COATL_UCD_RADICAL=93,

    /** '**RI**', '**Regional_Indicator**' */
    COATL_UCD_RI=94,
        /** Alias for #COATL_UCD_RI */
        COATL_UCD_REGIONAL_INDICATOR=COATL_UCD_RI,

    /** '**SD**', '**Soft_Dotted**' */
    COATL_UCD_SD=95,
        /** Alias for #COATL_UCD_SD */
        COATL_UCD_SOFT_DOTTED=COATL_UCD_SD,

    /** '**STerm**', '**Sentence_Terminal**' */
    COATL_UCD_STERM=96,
        /** Alias for #COATL_UCD_STERM */
        COATL_UCD_SENTENCE_TERMINAL=COATL_UCD_STERM,

    /** '**Term**', '**Terminal_Punctuation**' */
    COATL_UCD_TERM=97,
        /** Alias for #COATL_UCD_TERM */
        COATL_UCD_TERMINAL_PUNCTUATION=COATL_UCD_TERM,

    /** '**UIdeo**', '**Unified_Ideograph**' */
    COATL_UCD_UIDEO=98,
        /** Alias for #COATL_UCD_UIDEO */
        COATL_UCD_UNIFIED_IDEOGRAPH=COATL_UCD_UIDEO,

    /** '**Upper**', '**Uppercase**' */
    COATL_UCD_UPPER=99,
        /** Alias for #COATL_UCD_UPPER */
        COATL_UCD_UPPERCASE=COATL_UCD_UPPER,

    /** '**VS**', '**Variation_Selector**' */
    COATL_UCD_VS=100,
        /** Alias for #COATL_UCD_VS */
        COATL_UCD_VARIATION_SELECTOR=COATL_UCD_VS,

    /** '**WSpace**', '**White_Space**', '**space**' */
    COATL_UCD_WSPACE=101,
        /** Alias for #COATL_UCD_WSPACE */
        COATL_UCD_WHITE_SPACE=COATL_UCD_WSPACE,
        /** Alias for #COATL_UCD_WSPACE */
        COATL_UCD_SPACE=COATL_UCD_WSPACE,

    /** '**XIDC**', '**XID_Continue**' */
    COATL_UCD_XIDC=102,
        /** Alias for #COATL_UCD_XIDC */
        COATL_UCD_XID_CONTINUE=COATL_UCD_XIDC,

    /** '**XIDS**', '**XID_Start**' */
    COATL_UCD_XIDS=103,
        /** Alias for #COATL_UCD_XIDS */
        COATL_UCD_XID_START=COATL_UCD_XIDS,
} Coatl_UcdProperty;

/**
 * Number of Unicode character properties.
 *
 * @see Coatl_UcdProperty
 */
#define COATL_UCD_NBPROPERTIES  103

/**
 * Values for Unicode character property '**age**'.
 *
 * Names are automatically generated from the UCD file 
 * `PropertyValueAliases.txt`.
 *
 * @see COATL_UCD_AGE
 */
typedef enum Coatl_Ucd_Age {
    /** '**1.1**', '**V1_1**' */ 
    COATL_UCD_AGE_1_1=1,
        /** Alias for #COATL_UCD_AGE_1_1 */
        COATL_UCD_AGE_V1_1=COATL_UCD_AGE_1_1,

    /** '**2.0**', '**V2_0**' */ 
    COATL_UCD_AGE_2_0=2,
        /** Alias for #COATL_UCD_AGE_2_0 */
        COATL_UCD_AGE_V2_0=COATL_UCD_AGE_2_0,

    /** '**2.1**', '**V2_1**' */ 
    COATL_UCD_AGE_2_1=3,
        /** Alias for #COATL_UCD_AGE_2_1 */
        COATL_UCD_AGE_V2_1=COATL_UCD_AGE_2_1,

    /** '**3.0**', '**V3_0**' */ 
    COATL_UCD_AGE_3_0=4,
        /** Alias for #COATL_UCD_AGE_3_0 */
        COATL_UCD_AGE_V3_0=COATL_UCD_AGE_3_0,

    /** '**3.1**', '**V3_1**' */ 
    COATL_UCD_AGE_3_1=5,
        /** Alias for #COATL_UCD_AGE_3_1 */
        COATL_UCD_AGE_V3_1=COATL_UCD_AGE_3_1,

    /** '**3.2**', '**V3_2**' */ 
    COATL_UCD_AGE_3_2=6,
        /** Alias for #COATL_UCD_AGE_3_2 */
        COATL_UCD_AGE_V3_2=COATL_UCD_AGE_3_2,

    /** '**4.0**', '**V4_0**' */ 
    COATL_UCD_AGE_4_0=7,
        /** Alias for #COATL_UCD_AGE_4_0 */
        COATL_UCD_AGE_V4_0=COATL_UCD_AGE_4_0,

    /** '**4.1**', '**V4_1**' */ 
    COATL_UCD_AGE_4_1=8,
        /** Alias for #COATL_UCD_AGE_4_1 */
        COATL_UCD_AGE_V4_1=COATL_UCD_AGE_4_1,

    /** '**5.0**', '**V5_0**' */ 
    COATL_UCD_AGE_5_0=9,
        /** Alias for #COATL_UCD_AGE_5_0 */
        COATL_UCD_AGE_V5_0=COATL_UCD_AGE_5_0,

    /** '**5.1**', '**V5_1**' */ 
    COATL_UCD_AGE_5_1=10,
        /** Alias for #COATL_UCD_AGE_5_1 */
        COATL_UCD_AGE_V5_1=COATL_UCD_AGE_5_1,

    /** '**5.2**', '**V5_2**' */ 
    COATL_UCD_AGE_5_2=11,
        /** Alias for #COATL_UCD_AGE_5_2 */
        COATL_UCD_AGE_V5_2=COATL_UCD_AGE_5_2,

    /** '**6.0**', '**V6_0**' */ 
    COATL_UCD_AGE_6_0=12,
        /** Alias for #COATL_UCD_AGE_6_0 */
        COATL_UCD_AGE_V6_0=COATL_UCD_AGE_6_0,

    /** '**6.1**', '**V6_1**' */ 
    COATL_UCD_AGE_6_1=13,
        /** Alias for #COATL_UCD_AGE_6_1 */
        COATL_UCD_AGE_V6_1=COATL_UCD_AGE_6_1,

    /** '**6.2**', '**V6_2**' */ 
    COATL_UCD_AGE_6_2=14,
        /** Alias for #COATL_UCD_AGE_6_2 */
        COATL_UCD_AGE_V6_2=COATL_UCD_AGE_6_2,

    /** '**6.3**', '**V6_3**' */ 
    COATL_UCD_AGE_6_3=15,
        /** Alias for #COATL_UCD_AGE_6_3 */
        COATL_UCD_AGE_V6_3=COATL_UCD_AGE_6_3,

    /** '**7.0**', '**V7_0**' */ 
    COATL_UCD_AGE_7_0=16,
        /** Alias for #COATL_UCD_AGE_7_0 */
        COATL_UCD_AGE_V7_0=COATL_UCD_AGE_7_0,

    /** '**8.0**', '**V8_0**' */ 
    COATL_UCD_AGE_8_0=17,
        /** Alias for #COATL_UCD_AGE_8_0 */
        COATL_UCD_AGE_V8_0=COATL_UCD_AGE_8_0,

    /** '**9.0**', '**V9_0**' */ 
    COATL_UCD_AGE_9_0=18,
        /** Alias for #COATL_UCD_AGE_9_0 */
        COATL_UCD_AGE_V9_0=COATL_UCD_AGE_9_0,

    /** '**10.0**', '**V10_0**' */ 
    COATL_UCD_AGE_10_0=19,
        /** Alias for #COATL_UCD_AGE_10_0 */
        COATL_UCD_AGE_V10_0=COATL_UCD_AGE_10_0,

    /** '**11.0**', '**V11_0**' */ 
    COATL_UCD_AGE_11_0=20,
        /** Alias for #COATL_UCD_AGE_11_0 */
        COATL_UCD_AGE_V11_0=COATL_UCD_AGE_11_0,

    /** '**12.0**', '**V12_0**' */ 
    COATL_UCD_AGE_12_0=21,
        /** Alias for #COATL_UCD_AGE_12_0 */
        COATL_UCD_AGE_V12_0=COATL_UCD_AGE_12_0,

    /** '**12.1**', '**V12_1**' */ 
    COATL_UCD_AGE_12_1=22,
        /** Alias for #COATL_UCD_AGE_12_1 */
        COATL_UCD_AGE_V12_1=COATL_UCD_AGE_12_1,

    /** '**13.0**', '**V13_0**' */ 
    COATL_UCD_AGE_13_0=23,
        /** Alias for #COATL_UCD_AGE_13_0 */
        COATL_UCD_AGE_V13_0=COATL_UCD_AGE_13_0,

    /** '**NA**', '**Unassigned**' */ 
    COATL_UCD_AGE_NA=24,
        /** Alias for #COATL_UCD_AGE_NA */
        COATL_UCD_AGE_UNASSIGNED=COATL_UCD_AGE_NA,
} Coatl_Ucd_Age;

/**
 * Number of values for Unicode character property '*age*'.
 *
 * @see Coatl_Ucd_Age
 */
#define COATL_UCD_AGE_NBVALUES       24

/**
 * Values for Unicode character property '**blk**'.
 *
 * Names are automatically generated from the UCD file 
 * `PropertyValueAliases.txt`.
 *
 * @see COATL_UCD_BLK
 */
typedef enum Coatl_Ucd_Blk {
    /** '**Adlam**' */ 
    COATL_UCD_BLK_ADLAM=1,

    /** '**Aegean_Numbers**' */ 
    COATL_UCD_BLK_AEGEAN_NUMBERS=2,

    /** '**Ahom**' */ 
    COATL_UCD_BLK_AHOM=3,

    /** '**Alchemical**', '**Alchemical_Symbols**' */ 
    COATL_UCD_BLK_ALCHEMICAL=4,
        /** Alias for #COATL_UCD_BLK_ALCHEMICAL */
        COATL_UCD_BLK_ALCHEMICAL_SYMBOLS=COATL_UCD_BLK_ALCHEMICAL,

    /** '**Alphabetic_PF**', '**Alphabetic_Presentation_Forms**' */ 
    COATL_UCD_BLK_ALPHABETIC_PF=5,
        /** Alias for #COATL_UCD_BLK_ALPHABETIC_PF */
        COATL_UCD_BLK_ALPHABETIC_PRESENTATION_FORMS=COATL_UCD_BLK_ALPHABETIC_PF,

    /** '**Anatolian_Hieroglyphs**' */ 
    COATL_UCD_BLK_ANATOLIAN_HIEROGLYPHS=6,

    /** '**Ancient_Greek_Music**', '**Ancient_Greek_Musical_Notation**' */ 
    COATL_UCD_BLK_ANCIENT_GREEK_MUSIC=7,
        /** Alias for #COATL_UCD_BLK_ANCIENT_GREEK_MUSIC */
        COATL_UCD_BLK_ANCIENT_GREEK_MUSICAL_NOTATION=COATL_UCD_BLK_ANCIENT_GREEK_MUSIC,

    /** '**Ancient_Greek_Numbers**' */ 
    COATL_UCD_BLK_ANCIENT_GREEK_NUMBERS=8,

    /** '**Ancient_Symbols**' */ 
    COATL_UCD_BLK_ANCIENT_SYMBOLS=9,

    /** '**Arabic**' */ 
    COATL_UCD_BLK_ARABIC=10,

    /** '**Arabic_Ext_A**', '**Arabic_Extended_A**' */ 
    COATL_UCD_BLK_ARABIC_EXT_A=11,
        /** Alias for #COATL_UCD_BLK_ARABIC_EXT_A */
        COATL_UCD_BLK_ARABIC_EXTENDED_A=COATL_UCD_BLK_ARABIC_EXT_A,

    /** '**Arabic_Math**', '**Arabic_Mathematical_Alphabetic_Symbols**' */ 
    COATL_UCD_BLK_ARABIC_MATH=12,
        /** Alias for #COATL_UCD_BLK_ARABIC_MATH */
        COATL_UCD_BLK_ARABIC_MATHEMATICAL_ALPHABETIC_SYMBOLS=COATL_UCD_BLK_ARABIC_MATH,

    /** '**Arabic_PF_A**', '**Arabic_Presentation_Forms_A**', '**Arabic_Presentation_Forms-A**' */ 
    COATL_UCD_BLK_ARABIC_PF_A=13,
        /** Alias for #COATL_UCD_BLK_ARABIC_PF_A */
        COATL_UCD_BLK_ARABIC_PRESENTATION_FORMS_A=COATL_UCD_BLK_ARABIC_PF_A,

    /** '**Arabic_PF_B**', '**Arabic_Presentation_Forms_B**' */ 
    COATL_UCD_BLK_ARABIC_PF_B=14,
        /** Alias for #COATL_UCD_BLK_ARABIC_PF_B */
        COATL_UCD_BLK_ARABIC_PRESENTATION_FORMS_B=COATL_UCD_BLK_ARABIC_PF_B,

    /** '**Arabic_Sup**', '**Arabic_Supplement**' */ 
    COATL_UCD_BLK_ARABIC_SUP=15,
        /** Alias for #COATL_UCD_BLK_ARABIC_SUP */
        COATL_UCD_BLK_ARABIC_SUPPLEMENT=COATL_UCD_BLK_ARABIC_SUP,

    /** '**Armenian**' */ 
    COATL_UCD_BLK_ARMENIAN=16,

    /** '**Arrows**' */ 
    COATL_UCD_BLK_ARROWS=17,

    /** '**ASCII**', '**Basic_Latin**' */ 
    COATL_UCD_BLK_ASCII=18,
        /** Alias for #COATL_UCD_BLK_ASCII */
        COATL_UCD_BLK_BASIC_LATIN=COATL_UCD_BLK_ASCII,

    /** '**Avestan**' */ 
    COATL_UCD_BLK_AVESTAN=19,

    /** '**Balinese**' */ 
    COATL_UCD_BLK_BALINESE=20,

    /** '**Bamum**' */ 
    COATL_UCD_BLK_BAMUM=21,

    /** '**Bamum_Sup**', '**Bamum_Supplement**' */ 
    COATL_UCD_BLK_BAMUM_SUP=22,
        /** Alias for #COATL_UCD_BLK_BAMUM_SUP */
        COATL_UCD_BLK_BAMUM_SUPPLEMENT=COATL_UCD_BLK_BAMUM_SUP,

    /** '**Bassa_Vah**' */ 
    COATL_UCD_BLK_BASSA_VAH=23,

    /** '**Batak**' */ 
    COATL_UCD_BLK_BATAK=24,

    /** '**Bengali**' */ 
    COATL_UCD_BLK_BENGALI=25,

    /** '**Bhaiksuki**' */ 
    COATL_UCD_BLK_BHAIKSUKI=26,

    /** '**Block_Elements**' */ 
    COATL_UCD_BLK_BLOCK_ELEMENTS=27,

    /** '**Bopomofo**' */ 
    COATL_UCD_BLK_BOPOMOFO=28,

    /** '**Bopomofo_Ext**', '**Bopomofo_Extended**' */ 
    COATL_UCD_BLK_BOPOMOFO_EXT=29,
        /** Alias for #COATL_UCD_BLK_BOPOMOFO_EXT */
        COATL_UCD_BLK_BOPOMOFO_EXTENDED=COATL_UCD_BLK_BOPOMOFO_EXT,

    /** '**Box_Drawing**' */ 
    COATL_UCD_BLK_BOX_DRAWING=30,

    /** '**Brahmi**' */ 
    COATL_UCD_BLK_BRAHMI=31,

    /** '**Braille**', '**Braille_Patterns**' */ 
    COATL_UCD_BLK_BRAILLE=32,
        /** Alias for #COATL_UCD_BLK_BRAILLE */
        COATL_UCD_BLK_BRAILLE_PATTERNS=COATL_UCD_BLK_BRAILLE,

    /** '**Buginese**' */ 
    COATL_UCD_BLK_BUGINESE=33,

    /** '**Buhid**' */ 
    COATL_UCD_BLK_BUHID=34,

    /** '**Byzantine_Music**', '**Byzantine_Musical_Symbols**' */ 
    COATL_UCD_BLK_BYZANTINE_MUSIC=35,
        /** Alias for #COATL_UCD_BLK_BYZANTINE_MUSIC */
        COATL_UCD_BLK_BYZANTINE_MUSICAL_SYMBOLS=COATL_UCD_BLK_BYZANTINE_MUSIC,

    /** '**Carian**' */ 
    COATL_UCD_BLK_CARIAN=36,

    /** '**Caucasian_Albanian**' */ 
    COATL_UCD_BLK_CAUCASIAN_ALBANIAN=37,

    /** '**Chakma**' */ 
    COATL_UCD_BLK_CHAKMA=38,

    /** '**Cham**' */ 
    COATL_UCD_BLK_CHAM=39,

    /** '**Cherokee**' */ 
    COATL_UCD_BLK_CHEROKEE=40,

    /** '**Cherokee_Sup**', '**Cherokee_Supplement**' */ 
    COATL_UCD_BLK_CHEROKEE_SUP=41,
        /** Alias for #COATL_UCD_BLK_CHEROKEE_SUP */
        COATL_UCD_BLK_CHEROKEE_SUPPLEMENT=COATL_UCD_BLK_CHEROKEE_SUP,

    /** '**Chess_Symbols**' */ 
    COATL_UCD_BLK_CHESS_SYMBOLS=42,

    /** '**Chorasmian**' */ 
    COATL_UCD_BLK_CHORASMIAN=43,

    /** '**CJK**', '**CJK_Unified_Ideographs**' */ 
    COATL_UCD_BLK_CJK=44,
        /** Alias for #COATL_UCD_BLK_CJK */
        COATL_UCD_BLK_CJK_UNIFIED_IDEOGRAPHS=COATL_UCD_BLK_CJK,

    /** '**CJK_Compat**', '**CJK_Compatibility**' */ 
    COATL_UCD_BLK_CJK_COMPAT=45,
        /** Alias for #COATL_UCD_BLK_CJK_COMPAT */
        COATL_UCD_BLK_CJK_COMPATIBILITY=COATL_UCD_BLK_CJK_COMPAT,

    /** '**CJK_Compat_Forms**', '**CJK_Compatibility_Forms**' */ 
    COATL_UCD_BLK_CJK_COMPAT_FORMS=46,
        /** Alias for #COATL_UCD_BLK_CJK_COMPAT_FORMS */
        COATL_UCD_BLK_CJK_COMPATIBILITY_FORMS=COATL_UCD_BLK_CJK_COMPAT_FORMS,

    /** '**CJK_Compat_Ideographs**', '**CJK_Compatibility_Ideographs**' */ 
    COATL_UCD_BLK_CJK_COMPAT_IDEOGRAPHS=47,
        /** Alias for #COATL_UCD_BLK_CJK_COMPAT_IDEOGRAPHS */
        COATL_UCD_BLK_CJK_COMPATIBILITY_IDEOGRAPHS=COATL_UCD_BLK_CJK_COMPAT_IDEOGRAPHS,

    /** '**CJK_Compat_Ideographs_Sup**', '**CJK_Compatibility_Ideographs_Supplement**' */ 
    COATL_UCD_BLK_CJK_COMPAT_IDEOGRAPHS_SUP=48,
        /** Alias for #COATL_UCD_BLK_CJK_COMPAT_IDEOGRAPHS_SUP */
        COATL_UCD_BLK_CJK_COMPATIBILITY_IDEOGRAPHS_SUPPLEMENT=COATL_UCD_BLK_CJK_COMPAT_IDEOGRAPHS_SUP,

    /** '**CJK_Ext_A**', '**CJK_Unified_Ideographs_Extension_A**' */ 
    COATL_UCD_BLK_CJK_EXT_A=49,
        /** Alias for #COATL_UCD_BLK_CJK_EXT_A */
        COATL_UCD_BLK_CJK_UNIFIED_IDEOGRAPHS_EXTENSION_A=COATL_UCD_BLK_CJK_EXT_A,

    /** '**CJK_Ext_B**', '**CJK_Unified_Ideographs_Extension_B**' */ 
    COATL_UCD_BLK_CJK_EXT_B=50,
        /** Alias for #COATL_UCD_BLK_CJK_EXT_B */
        COATL_UCD_BLK_CJK_UNIFIED_IDEOGRAPHS_EXTENSION_B=COATL_UCD_BLK_CJK_EXT_B,

    /** '**CJK_Ext_C**', '**CJK_Unified_Ideographs_Extension_C**' */ 
    COATL_UCD_BLK_CJK_EXT_C=51,
        /** Alias for #COATL_UCD_BLK_CJK_EXT_C */
        COATL_UCD_BLK_CJK_UNIFIED_IDEOGRAPHS_EXTENSION_C=COATL_UCD_BLK_CJK_EXT_C,

    /** '**CJK_Ext_D**', '**CJK_Unified_Ideographs_Extension_D**' */ 
    COATL_UCD_BLK_CJK_EXT_D=52,
        /** Alias for #COATL_UCD_BLK_CJK_EXT_D */
        COATL_UCD_BLK_CJK_UNIFIED_IDEOGRAPHS_EXTENSION_D=COATL_UCD_BLK_CJK_EXT_D,

    /** '**CJK_Ext_E**', '**CJK_Unified_Ideographs_Extension_E**' */ 
    COATL_UCD_BLK_CJK_EXT_E=53,
        /** Alias for #COATL_UCD_BLK_CJK_EXT_E */
        COATL_UCD_BLK_CJK_UNIFIED_IDEOGRAPHS_EXTENSION_E=COATL_UCD_BLK_CJK_EXT_E,

    /** '**CJK_Ext_F**', '**CJK_Unified_Ideographs_Extension_F**' */ 
    COATL_UCD_BLK_CJK_EXT_F=54,
        /** Alias for #COATL_UCD_BLK_CJK_EXT_F */
        COATL_UCD_BLK_CJK_UNIFIED_IDEOGRAPHS_EXTENSION_F=COATL_UCD_BLK_CJK_EXT_F,

    /** '**CJK_Ext_G**', '**CJK_Unified_Ideographs_Extension_G**' */ 
    COATL_UCD_BLK_CJK_EXT_G=55,
        /** Alias for #COATL_UCD_BLK_CJK_EXT_G */
        COATL_UCD_BLK_CJK_UNIFIED_IDEOGRAPHS_EXTENSION_G=COATL_UCD_BLK_CJK_EXT_G,

    /** '**CJK_Radicals_Sup**', '**CJK_Radicals_Supplement**' */ 
    COATL_UCD_BLK_CJK_RADICALS_SUP=56,
        /** Alias for #COATL_UCD_BLK_CJK_RADICALS_SUP */
        COATL_UCD_BLK_CJK_RADICALS_SUPPLEMENT=COATL_UCD_BLK_CJK_RADICALS_SUP,

    /** '**CJK_Strokes**' */ 
    COATL_UCD_BLK_CJK_STROKES=57,

    /** '**CJK_Symbols**', '**CJK_Symbols_And_Punctuation**' */ 
    COATL_UCD_BLK_CJK_SYMBOLS=58,
        /** Alias for #COATL_UCD_BLK_CJK_SYMBOLS */
        COATL_UCD_BLK_CJK_SYMBOLS_AND_PUNCTUATION=COATL_UCD_BLK_CJK_SYMBOLS,

    /** '**Compat_Jamo**', '**Hangul_Compatibility_Jamo**' */ 
    COATL_UCD_BLK_COMPAT_JAMO=59,
        /** Alias for #COATL_UCD_BLK_COMPAT_JAMO */
        COATL_UCD_BLK_HANGUL_COMPATIBILITY_JAMO=COATL_UCD_BLK_COMPAT_JAMO,

    /** '**Control_Pictures**' */ 
    COATL_UCD_BLK_CONTROL_PICTURES=60,

    /** '**Coptic**' */ 
    COATL_UCD_BLK_COPTIC=61,

    /** '**Coptic_Epact_Numbers**' */ 
    COATL_UCD_BLK_COPTIC_EPACT_NUMBERS=62,

    /** '**Counting_Rod**', '**Counting_Rod_Numerals**' */ 
    COATL_UCD_BLK_COUNTING_ROD=63,
        /** Alias for #COATL_UCD_BLK_COUNTING_ROD */
        COATL_UCD_BLK_COUNTING_ROD_NUMERALS=COATL_UCD_BLK_COUNTING_ROD,

    /** '**Cuneiform**' */ 
    COATL_UCD_BLK_CUNEIFORM=64,

    /** '**Cuneiform_Numbers**', '**Cuneiform_Numbers_And_Punctuation**' */ 
    COATL_UCD_BLK_CUNEIFORM_NUMBERS=65,
        /** Alias for #COATL_UCD_BLK_CUNEIFORM_NUMBERS */
        COATL_UCD_BLK_CUNEIFORM_NUMBERS_AND_PUNCTUATION=COATL_UCD_BLK_CUNEIFORM_NUMBERS,

    /** '**Currency_Symbols**' */ 
    COATL_UCD_BLK_CURRENCY_SYMBOLS=66,

    /** '**Cypriot_Syllabary**' */ 
    COATL_UCD_BLK_CYPRIOT_SYLLABARY=67,

    /** '**Cyrillic**' */ 
    COATL_UCD_BLK_CYRILLIC=68,

    /** '**Cyrillic_Ext_A**', '**Cyrillic_Extended_A**' */ 
    COATL_UCD_BLK_CYRILLIC_EXT_A=69,
        /** Alias for #COATL_UCD_BLK_CYRILLIC_EXT_A */
        COATL_UCD_BLK_CYRILLIC_EXTENDED_A=COATL_UCD_BLK_CYRILLIC_EXT_A,

    /** '**Cyrillic_Ext_B**', '**Cyrillic_Extended_B**' */ 
    COATL_UCD_BLK_CYRILLIC_EXT_B=70,
        /** Alias for #COATL_UCD_BLK_CYRILLIC_EXT_B */
        COATL_UCD_BLK_CYRILLIC_EXTENDED_B=COATL_UCD_BLK_CYRILLIC_EXT_B,

    /** '**Cyrillic_Ext_C**', '**Cyrillic_Extended_C**' */ 
    COATL_UCD_BLK_CYRILLIC_EXT_C=71,
        /** Alias for #COATL_UCD_BLK_CYRILLIC_EXT_C */
        COATL_UCD_BLK_CYRILLIC_EXTENDED_C=COATL_UCD_BLK_CYRILLIC_EXT_C,

    /** '**Cyrillic_Sup**', '**Cyrillic_Supplement**', '**Cyrillic_Supplementary**' */ 
    COATL_UCD_BLK_CYRILLIC_SUP=72,
        /** Alias for #COATL_UCD_BLK_CYRILLIC_SUP */
        COATL_UCD_BLK_CYRILLIC_SUPPLEMENT=COATL_UCD_BLK_CYRILLIC_SUP,
        /** Alias for #COATL_UCD_BLK_CYRILLIC_SUP */
        COATL_UCD_BLK_CYRILLIC_SUPPLEMENTARY=COATL_UCD_BLK_CYRILLIC_SUP,

    /** '**Deseret**' */ 
    COATL_UCD_BLK_DESERET=73,

    /** '**Devanagari**' */ 
    COATL_UCD_BLK_DEVANAGARI=74,

    /** '**Devanagari_Ext**', '**Devanagari_Extended**' */ 
    COATL_UCD_BLK_DEVANAGARI_EXT=75,
        /** Alias for #COATL_UCD_BLK_DEVANAGARI_EXT */
        COATL_UCD_BLK_DEVANAGARI_EXTENDED=COATL_UCD_BLK_DEVANAGARI_EXT,

    /** '**Diacriticals**', '**Combining_Diacritical_Marks**' */ 
    COATL_UCD_BLK_DIACRITICALS=76,
        /** Alias for #COATL_UCD_BLK_DIACRITICALS */
        COATL_UCD_BLK_COMBINING_DIACRITICAL_MARKS=COATL_UCD_BLK_DIACRITICALS,

    /** '**Diacriticals_Ext**', '**Combining_Diacritical_Marks_Extended**' */ 
    COATL_UCD_BLK_DIACRITICALS_EXT=77,
        /** Alias for #COATL_UCD_BLK_DIACRITICALS_EXT */
        COATL_UCD_BLK_COMBINING_DIACRITICAL_MARKS_EXTENDED=COATL_UCD_BLK_DIACRITICALS_EXT,

    /** '**Diacriticals_For_Symbols**', '**Combining_Diacritical_Marks_For_Symbols**', '**Combining_Marks_For_Symbols**' */ 
    COATL_UCD_BLK_DIACRITICALS_FOR_SYMBOLS=78,
        /** Alias for #COATL_UCD_BLK_DIACRITICALS_FOR_SYMBOLS */
        COATL_UCD_BLK_COMBINING_DIACRITICAL_MARKS_FOR_SYMBOLS=COATL_UCD_BLK_DIACRITICALS_FOR_SYMBOLS,
        /** Alias for #COATL_UCD_BLK_DIACRITICALS_FOR_SYMBOLS */
        COATL_UCD_BLK_COMBINING_MARKS_FOR_SYMBOLS=COATL_UCD_BLK_DIACRITICALS_FOR_SYMBOLS,

    /** '**Diacriticals_Sup**', '**Combining_Diacritical_Marks_Supplement**' */ 
    COATL_UCD_BLK_DIACRITICALS_SUP=79,
        /** Alias for #COATL_UCD_BLK_DIACRITICALS_SUP */
        COATL_UCD_BLK_COMBINING_DIACRITICAL_MARKS_SUPPLEMENT=COATL_UCD_BLK_DIACRITICALS_SUP,

    /** '**Dingbats**' */ 
    COATL_UCD_BLK_DINGBATS=80,

    /** '**Dives_Akuru**' */ 
    COATL_UCD_BLK_DIVES_AKURU=81,

    /** '**Dogra**' */ 
    COATL_UCD_BLK_DOGRA=82,

    /** '**Domino**', '**Domino_Tiles**' */ 
    COATL_UCD_BLK_DOMINO=83,
        /** Alias for #COATL_UCD_BLK_DOMINO */
        COATL_UCD_BLK_DOMINO_TILES=COATL_UCD_BLK_DOMINO,

    /** '**Duployan**' */ 
    COATL_UCD_BLK_DUPLOYAN=84,

    /** '**Early_Dynastic_Cuneiform**' */ 
    COATL_UCD_BLK_EARLY_DYNASTIC_CUNEIFORM=85,

    /** '**Egyptian_Hieroglyph_Format_Controls**' */ 
    COATL_UCD_BLK_EGYPTIAN_HIEROGLYPH_FORMAT_CONTROLS=86,

    /** '**Egyptian_Hieroglyphs**' */ 
    COATL_UCD_BLK_EGYPTIAN_HIEROGLYPHS=87,

    /** '**Elbasan**' */ 
    COATL_UCD_BLK_ELBASAN=88,

    /** '**Elymaic**' */ 
    COATL_UCD_BLK_ELYMAIC=89,

    /** '**Emoticons**' */ 
    COATL_UCD_BLK_EMOTICONS=90,

    /** '**Enclosed_Alphanum**', '**Enclosed_Alphanumerics**' */ 
    COATL_UCD_BLK_ENCLOSED_ALPHANUM=91,
        /** Alias for #COATL_UCD_BLK_ENCLOSED_ALPHANUM */
        COATL_UCD_BLK_ENCLOSED_ALPHANUMERICS=COATL_UCD_BLK_ENCLOSED_ALPHANUM,

    /** '**Enclosed_Alphanum_Sup**', '**Enclosed_Alphanumeric_Supplement**' */ 
    COATL_UCD_BLK_ENCLOSED_ALPHANUM_SUP=92,
        /** Alias for #COATL_UCD_BLK_ENCLOSED_ALPHANUM_SUP */
        COATL_UCD_BLK_ENCLOSED_ALPHANUMERIC_SUPPLEMENT=COATL_UCD_BLK_ENCLOSED_ALPHANUM_SUP,

    /** '**Enclosed_CJK**', '**Enclosed_CJK_Letters_And_Months**' */ 
    COATL_UCD_BLK_ENCLOSED_CJK=93,
        /** Alias for #COATL_UCD_BLK_ENCLOSED_CJK */
        COATL_UCD_BLK_ENCLOSED_CJK_LETTERS_AND_MONTHS=COATL_UCD_BLK_ENCLOSED_CJK,

    /** '**Enclosed_Ideographic_Sup**', '**Enclosed_Ideographic_Supplement**' */ 
    COATL_UCD_BLK_ENCLOSED_IDEOGRAPHIC_SUP=94,
        /** Alias for #COATL_UCD_BLK_ENCLOSED_IDEOGRAPHIC_SUP */
        COATL_UCD_BLK_ENCLOSED_IDEOGRAPHIC_SUPPLEMENT=COATL_UCD_BLK_ENCLOSED_IDEOGRAPHIC_SUP,

    /** '**Ethiopic**' */ 
    COATL_UCD_BLK_ETHIOPIC=95,

    /** '**Ethiopic_Ext**', '**Ethiopic_Extended**' */ 
    COATL_UCD_BLK_ETHIOPIC_EXT=96,
        /** Alias for #COATL_UCD_BLK_ETHIOPIC_EXT */
        COATL_UCD_BLK_ETHIOPIC_EXTENDED=COATL_UCD_BLK_ETHIOPIC_EXT,

    /** '**Ethiopic_Ext_A**', '**Ethiopic_Extended_A**' */ 
    COATL_UCD_BLK_ETHIOPIC_EXT_A=97,
        /** Alias for #COATL_UCD_BLK_ETHIOPIC_EXT_A */
        COATL_UCD_BLK_ETHIOPIC_EXTENDED_A=COATL_UCD_BLK_ETHIOPIC_EXT_A,

    /** '**Ethiopic_Sup**', '**Ethiopic_Supplement**' */ 
    COATL_UCD_BLK_ETHIOPIC_SUP=98,
        /** Alias for #COATL_UCD_BLK_ETHIOPIC_SUP */
        COATL_UCD_BLK_ETHIOPIC_SUPPLEMENT=COATL_UCD_BLK_ETHIOPIC_SUP,

    /** '**Geometric_Shapes**' */ 
    COATL_UCD_BLK_GEOMETRIC_SHAPES=99,

    /** '**Geometric_Shapes_Ext**', '**Geometric_Shapes_Extended**' */ 
    COATL_UCD_BLK_GEOMETRIC_SHAPES_EXT=100,
        /** Alias for #COATL_UCD_BLK_GEOMETRIC_SHAPES_EXT */
        COATL_UCD_BLK_GEOMETRIC_SHAPES_EXTENDED=COATL_UCD_BLK_GEOMETRIC_SHAPES_EXT,

    /** '**Georgian**' */ 
    COATL_UCD_BLK_GEORGIAN=101,

    /** '**Georgian_Ext**', '**Georgian_Extended**' */ 
    COATL_UCD_BLK_GEORGIAN_EXT=102,
        /** Alias for #COATL_UCD_BLK_GEORGIAN_EXT */
        COATL_UCD_BLK_GEORGIAN_EXTENDED=COATL_UCD_BLK_GEORGIAN_EXT,

    /** '**Georgian_Sup**', '**Georgian_Supplement**' */ 
    COATL_UCD_BLK_GEORGIAN_SUP=103,
        /** Alias for #COATL_UCD_BLK_GEORGIAN_SUP */
        COATL_UCD_BLK_GEORGIAN_SUPPLEMENT=COATL_UCD_BLK_GEORGIAN_SUP,

    /** '**Glagolitic**' */ 
    COATL_UCD_BLK_GLAGOLITIC=104,

    /** '**Glagolitic_Sup**', '**Glagolitic_Supplement**' */ 
    COATL_UCD_BLK_GLAGOLITIC_SUP=105,
        /** Alias for #COATL_UCD_BLK_GLAGOLITIC_SUP */
        COATL_UCD_BLK_GLAGOLITIC_SUPPLEMENT=COATL_UCD_BLK_GLAGOLITIC_SUP,

    /** '**Gothic**' */ 
    COATL_UCD_BLK_GOTHIC=106,

    /** '**Grantha**' */ 
    COATL_UCD_BLK_GRANTHA=107,

    /** '**Greek**', '**Greek_And_Coptic**' */ 
    COATL_UCD_BLK_GREEK=108,
        /** Alias for #COATL_UCD_BLK_GREEK */
        COATL_UCD_BLK_GREEK_AND_COPTIC=COATL_UCD_BLK_GREEK,

    /** '**Greek_Ext**', '**Greek_Extended**' */ 
    COATL_UCD_BLK_GREEK_EXT=109,
        /** Alias for #COATL_UCD_BLK_GREEK_EXT */
        COATL_UCD_BLK_GREEK_EXTENDED=COATL_UCD_BLK_GREEK_EXT,

    /** '**Gujarati**' */ 
    COATL_UCD_BLK_GUJARATI=110,

    /** '**Gunjala_Gondi**' */ 
    COATL_UCD_BLK_GUNJALA_GONDI=111,

    /** '**Gurmukhi**' */ 
    COATL_UCD_BLK_GURMUKHI=112,

    /** '**Half_And_Full_Forms**', '**Halfwidth_And_Fullwidth_Forms**' */ 
    COATL_UCD_BLK_HALF_AND_FULL_FORMS=113,
        /** Alias for #COATL_UCD_BLK_HALF_AND_FULL_FORMS */
        COATL_UCD_BLK_HALFWIDTH_AND_FULLWIDTH_FORMS=COATL_UCD_BLK_HALF_AND_FULL_FORMS,

    /** '**Half_Marks**', '**Combining_Half_Marks**' */ 
    COATL_UCD_BLK_HALF_MARKS=114,
        /** Alias for #COATL_UCD_BLK_HALF_MARKS */
        COATL_UCD_BLK_COMBINING_HALF_MARKS=COATL_UCD_BLK_HALF_MARKS,

    /** '**Hangul**', '**Hangul_Syllables**' */ 
    COATL_UCD_BLK_HANGUL=115,
        /** Alias for #COATL_UCD_BLK_HANGUL */
        COATL_UCD_BLK_HANGUL_SYLLABLES=COATL_UCD_BLK_HANGUL,

    /** '**Hanifi_Rohingya**' */ 
    COATL_UCD_BLK_HANIFI_ROHINGYA=116,

    /** '**Hanunoo**' */ 
    COATL_UCD_BLK_HANUNOO=117,

    /** '**Hatran**' */ 
    COATL_UCD_BLK_HATRAN=118,

    /** '**Hebrew**' */ 
    COATL_UCD_BLK_HEBREW=119,

    /** '**High_PU_Surrogates**', '**High_Private_Use_Surrogates**' */ 
    COATL_UCD_BLK_HIGH_PU_SURROGATES=120,
        /** Alias for #COATL_UCD_BLK_HIGH_PU_SURROGATES */
        COATL_UCD_BLK_HIGH_PRIVATE_USE_SURROGATES=COATL_UCD_BLK_HIGH_PU_SURROGATES,

    /** '**High_Surrogates**' */ 
    COATL_UCD_BLK_HIGH_SURROGATES=121,

    /** '**Hiragana**' */ 
    COATL_UCD_BLK_HIRAGANA=122,

    /** '**IDC**', '**Ideographic_Description_Characters**' */ 
    COATL_UCD_BLK_IDC=123,
        /** Alias for #COATL_UCD_BLK_IDC */
        COATL_UCD_BLK_IDEOGRAPHIC_DESCRIPTION_CHARACTERS=COATL_UCD_BLK_IDC,

    /** '**Ideographic_Symbols**', '**Ideographic_Symbols_And_Punctuation**' */ 
    COATL_UCD_BLK_IDEOGRAPHIC_SYMBOLS=124,
        /** Alias for #COATL_UCD_BLK_IDEOGRAPHIC_SYMBOLS */
        COATL_UCD_BLK_IDEOGRAPHIC_SYMBOLS_AND_PUNCTUATION=COATL_UCD_BLK_IDEOGRAPHIC_SYMBOLS,

    /** '**Imperial_Aramaic**' */ 
    COATL_UCD_BLK_IMPERIAL_ARAMAIC=125,

    /** '**Indic_Number_Forms**', '**Common_Indic_Number_Forms**' */ 
    COATL_UCD_BLK_INDIC_NUMBER_FORMS=126,
        /** Alias for #COATL_UCD_BLK_INDIC_NUMBER_FORMS */
        COATL_UCD_BLK_COMMON_INDIC_NUMBER_FORMS=COATL_UCD_BLK_INDIC_NUMBER_FORMS,

    /** '**Indic_Siyaq_Numbers**' */ 
    COATL_UCD_BLK_INDIC_SIYAQ_NUMBERS=127,

    /** '**Inscriptional_Pahlavi**' */ 
    COATL_UCD_BLK_INSCRIPTIONAL_PAHLAVI=128,

    /** '**Inscriptional_Parthian**' */ 
    COATL_UCD_BLK_INSCRIPTIONAL_PARTHIAN=129,

    /** '**IPA_Ext**', '**IPA_Extensions**' */ 
    COATL_UCD_BLK_IPA_EXT=130,
        /** Alias for #COATL_UCD_BLK_IPA_EXT */
        COATL_UCD_BLK_IPA_EXTENSIONS=COATL_UCD_BLK_IPA_EXT,

    /** '**Jamo**', '**Hangul_Jamo**' */ 
    COATL_UCD_BLK_JAMO=131,
        /** Alias for #COATL_UCD_BLK_JAMO */
        COATL_UCD_BLK_HANGUL_JAMO=COATL_UCD_BLK_JAMO,

    /** '**Jamo_Ext_A**', '**Hangul_Jamo_Extended_A**' */ 
    COATL_UCD_BLK_JAMO_EXT_A=132,
        /** Alias for #COATL_UCD_BLK_JAMO_EXT_A */
        COATL_UCD_BLK_HANGUL_JAMO_EXTENDED_A=COATL_UCD_BLK_JAMO_EXT_A,

    /** '**Jamo_Ext_B**', '**Hangul_Jamo_Extended_B**' */ 
    COATL_UCD_BLK_JAMO_EXT_B=133,
        /** Alias for #COATL_UCD_BLK_JAMO_EXT_B */
        COATL_UCD_BLK_HANGUL_JAMO_EXTENDED_B=COATL_UCD_BLK_JAMO_EXT_B,

    /** '**Javanese**' */ 
    COATL_UCD_BLK_JAVANESE=134,

    /** '**Kaithi**' */ 
    COATL_UCD_BLK_KAITHI=135,

    /** '**Kana_Ext_A**', '**Kana_Extended_A**' */ 
    COATL_UCD_BLK_KANA_EXT_A=136,
        /** Alias for #COATL_UCD_BLK_KANA_EXT_A */
        COATL_UCD_BLK_KANA_EXTENDED_A=COATL_UCD_BLK_KANA_EXT_A,

    /** '**Kana_Sup**', '**Kana_Supplement**' */ 
    COATL_UCD_BLK_KANA_SUP=137,
        /** Alias for #COATL_UCD_BLK_KANA_SUP */
        COATL_UCD_BLK_KANA_SUPPLEMENT=COATL_UCD_BLK_KANA_SUP,

    /** '**Kanbun**' */ 
    COATL_UCD_BLK_KANBUN=138,

    /** '**Kangxi**', '**Kangxi_Radicals**' */ 
    COATL_UCD_BLK_KANGXI=139,
        /** Alias for #COATL_UCD_BLK_KANGXI */
        COATL_UCD_BLK_KANGXI_RADICALS=COATL_UCD_BLK_KANGXI,

    /** '**Kannada**' */ 
    COATL_UCD_BLK_KANNADA=140,

    /** '**Katakana**' */ 
    COATL_UCD_BLK_KATAKANA=141,

    /** '**Katakana_Ext**', '**Katakana_Phonetic_Extensions**' */ 
    COATL_UCD_BLK_KATAKANA_EXT=142,
        /** Alias for #COATL_UCD_BLK_KATAKANA_EXT */
        COATL_UCD_BLK_KATAKANA_PHONETIC_EXTENSIONS=COATL_UCD_BLK_KATAKANA_EXT,

    /** '**Kayah_Li**' */ 
    COATL_UCD_BLK_KAYAH_LI=143,

    /** '**Kharoshthi**' */ 
    COATL_UCD_BLK_KHAROSHTHI=144,

    /** '**Khitan_Small_Script**' */ 
    COATL_UCD_BLK_KHITAN_SMALL_SCRIPT=145,

    /** '**Khmer**' */ 
    COATL_UCD_BLK_KHMER=146,

    /** '**Khmer_Symbols**' */ 
    COATL_UCD_BLK_KHMER_SYMBOLS=147,

    /** '**Khojki**' */ 
    COATL_UCD_BLK_KHOJKI=148,

    /** '**Khudawadi**' */ 
    COATL_UCD_BLK_KHUDAWADI=149,

    /** '**Lao**' */ 
    COATL_UCD_BLK_LAO=150,

    /** '**Latin_1_Sup**', '**Latin_1_Supplement**', '**Latin_1**' */ 
    COATL_UCD_BLK_LATIN_1_SUP=151,
        /** Alias for #COATL_UCD_BLK_LATIN_1_SUP */
        COATL_UCD_BLK_LATIN_1_SUPPLEMENT=COATL_UCD_BLK_LATIN_1_SUP,
        /** Alias for #COATL_UCD_BLK_LATIN_1_SUP */
        COATL_UCD_BLK_LATIN_1=COATL_UCD_BLK_LATIN_1_SUP,

    /** '**Latin_Ext_A**', '**Latin_Extended_A**' */ 
    COATL_UCD_BLK_LATIN_EXT_A=152,
        /** Alias for #COATL_UCD_BLK_LATIN_EXT_A */
        COATL_UCD_BLK_LATIN_EXTENDED_A=COATL_UCD_BLK_LATIN_EXT_A,

    /** '**Latin_Ext_Additional**', '**Latin_Extended_Additional**' */ 
    COATL_UCD_BLK_LATIN_EXT_ADDITIONAL=153,
        /** Alias for #COATL_UCD_BLK_LATIN_EXT_ADDITIONAL */
        COATL_UCD_BLK_LATIN_EXTENDED_ADDITIONAL=COATL_UCD_BLK_LATIN_EXT_ADDITIONAL,

    /** '**Latin_Ext_B**', '**Latin_Extended_B**' */ 
    COATL_UCD_BLK_LATIN_EXT_B=154,
        /** Alias for #COATL_UCD_BLK_LATIN_EXT_B */
        COATL_UCD_BLK_LATIN_EXTENDED_B=COATL_UCD_BLK_LATIN_EXT_B,

    /** '**Latin_Ext_C**', '**Latin_Extended_C**' */ 
    COATL_UCD_BLK_LATIN_EXT_C=155,
        /** Alias for #COATL_UCD_BLK_LATIN_EXT_C */
        COATL_UCD_BLK_LATIN_EXTENDED_C=COATL_UCD_BLK_LATIN_EXT_C,

    /** '**Latin_Ext_D**', '**Latin_Extended_D**' */ 
    COATL_UCD_BLK_LATIN_EXT_D=156,
        /** Alias for #COATL_UCD_BLK_LATIN_EXT_D */
        COATL_UCD_BLK_LATIN_EXTENDED_D=COATL_UCD_BLK_LATIN_EXT_D,

    /** '**Latin_Ext_E**', '**Latin_Extended_E**' */ 
    COATL_UCD_BLK_LATIN_EXT_E=157,
        /** Alias for #COATL_UCD_BLK_LATIN_EXT_E */
        COATL_UCD_BLK_LATIN_EXTENDED_E=COATL_UCD_BLK_LATIN_EXT_E,

    /** '**Lepcha**' */ 
    COATL_UCD_BLK_LEPCHA=158,

    /** '**Letterlike_Symbols**' */ 
    COATL_UCD_BLK_LETTERLIKE_SYMBOLS=159,

    /** '**Limbu**' */ 
    COATL_UCD_BLK_LIMBU=160,

    /** '**Linear_A**' */ 
    COATL_UCD_BLK_LINEAR_A=161,

    /** '**Linear_B_Ideograms**' */ 
    COATL_UCD_BLK_LINEAR_B_IDEOGRAMS=162,

    /** '**Linear_B_Syllabary**' */ 
    COATL_UCD_BLK_LINEAR_B_SYLLABARY=163,

    /** '**Lisu**' */ 
    COATL_UCD_BLK_LISU=164,

    /** '**Lisu_Sup**', '**Lisu_Supplement**' */ 
    COATL_UCD_BLK_LISU_SUP=165,
        /** Alias for #COATL_UCD_BLK_LISU_SUP */
        COATL_UCD_BLK_LISU_SUPPLEMENT=COATL_UCD_BLK_LISU_SUP,

    /** '**Low_Surrogates**' */ 
    COATL_UCD_BLK_LOW_SURROGATES=166,

    /** '**Lycian**' */ 
    COATL_UCD_BLK_LYCIAN=167,

    /** '**Lydian**' */ 
    COATL_UCD_BLK_LYDIAN=168,

    /** '**Mahajani**' */ 
    COATL_UCD_BLK_MAHAJANI=169,

    /** '**Mahjong**', '**Mahjong_Tiles**' */ 
    COATL_UCD_BLK_MAHJONG=170,
        /** Alias for #COATL_UCD_BLK_MAHJONG */
        COATL_UCD_BLK_MAHJONG_TILES=COATL_UCD_BLK_MAHJONG,

    /** '**Makasar**' */ 
    COATL_UCD_BLK_MAKASAR=171,

    /** '**Malayalam**' */ 
    COATL_UCD_BLK_MALAYALAM=172,

    /** '**Mandaic**' */ 
    COATL_UCD_BLK_MANDAIC=173,

    /** '**Manichaean**' */ 
    COATL_UCD_BLK_MANICHAEAN=174,

    /** '**Marchen**' */ 
    COATL_UCD_BLK_MARCHEN=175,

    /** '**Masaram_Gondi**' */ 
    COATL_UCD_BLK_MASARAM_GONDI=176,

    /** '**Math_Alphanum**', '**Mathematical_Alphanumeric_Symbols**' */ 
    COATL_UCD_BLK_MATH_ALPHANUM=177,
        /** Alias for #COATL_UCD_BLK_MATH_ALPHANUM */
        COATL_UCD_BLK_MATHEMATICAL_ALPHANUMERIC_SYMBOLS=COATL_UCD_BLK_MATH_ALPHANUM,

    /** '**Math_Operators**', '**Mathematical_Operators**' */ 
    COATL_UCD_BLK_MATH_OPERATORS=178,
        /** Alias for #COATL_UCD_BLK_MATH_OPERATORS */
        COATL_UCD_BLK_MATHEMATICAL_OPERATORS=COATL_UCD_BLK_MATH_OPERATORS,

    /** '**Mayan_Numerals**' */ 
    COATL_UCD_BLK_MAYAN_NUMERALS=179,

    /** '**Medefaidrin**' */ 
    COATL_UCD_BLK_MEDEFAIDRIN=180,

    /** '**Meetei_Mayek**' */ 
    COATL_UCD_BLK_MEETEI_MAYEK=181,

    /** '**Meetei_Mayek_Ext**', '**Meetei_Mayek_Extensions**' */ 
    COATL_UCD_BLK_MEETEI_MAYEK_EXT=182,
        /** Alias for #COATL_UCD_BLK_MEETEI_MAYEK_EXT */
        COATL_UCD_BLK_MEETEI_MAYEK_EXTENSIONS=COATL_UCD_BLK_MEETEI_MAYEK_EXT,

    /** '**Mende_Kikakui**' */ 
    COATL_UCD_BLK_MENDE_KIKAKUI=183,

    /** '**Meroitic_Cursive**' */ 
    COATL_UCD_BLK_MEROITIC_CURSIVE=184,

    /** '**Meroitic_Hieroglyphs**' */ 
    COATL_UCD_BLK_MEROITIC_HIEROGLYPHS=185,

    /** '**Miao**' */ 
    COATL_UCD_BLK_MIAO=186,

    /** '**Misc_Arrows**', '**Miscellaneous_Symbols_And_Arrows**' */ 
    COATL_UCD_BLK_MISC_ARROWS=187,
        /** Alias for #COATL_UCD_BLK_MISC_ARROWS */
        COATL_UCD_BLK_MISCELLANEOUS_SYMBOLS_AND_ARROWS=COATL_UCD_BLK_MISC_ARROWS,

    /** '**Misc_Math_Symbols_A**', '**Miscellaneous_Mathematical_Symbols_A**' */ 
    COATL_UCD_BLK_MISC_MATH_SYMBOLS_A=188,
        /** Alias for #COATL_UCD_BLK_MISC_MATH_SYMBOLS_A */
        COATL_UCD_BLK_MISCELLANEOUS_MATHEMATICAL_SYMBOLS_A=COATL_UCD_BLK_MISC_MATH_SYMBOLS_A,

    /** '**Misc_Math_Symbols_B**', '**Miscellaneous_Mathematical_Symbols_B**' */ 
    COATL_UCD_BLK_MISC_MATH_SYMBOLS_B=189,
        /** Alias for #COATL_UCD_BLK_MISC_MATH_SYMBOLS_B */
        COATL_UCD_BLK_MISCELLANEOUS_MATHEMATICAL_SYMBOLS_B=COATL_UCD_BLK_MISC_MATH_SYMBOLS_B,

    /** '**Misc_Pictographs**', '**Miscellaneous_Symbols_And_Pictographs**' */ 
    COATL_UCD_BLK_MISC_PICTOGRAPHS=190,
        /** Alias for #COATL_UCD_BLK_MISC_PICTOGRAPHS */
        COATL_UCD_BLK_MISCELLANEOUS_SYMBOLS_AND_PICTOGRAPHS=COATL_UCD_BLK_MISC_PICTOGRAPHS,

    /** '**Misc_Symbols**', '**Miscellaneous_Symbols**' */ 
    COATL_UCD_BLK_MISC_SYMBOLS=191,
        /** Alias for #COATL_UCD_BLK_MISC_SYMBOLS */
        COATL_UCD_BLK_MISCELLANEOUS_SYMBOLS=COATL_UCD_BLK_MISC_SYMBOLS,

    /** '**Misc_Technical**', '**Miscellaneous_Technical**' */ 
    COATL_UCD_BLK_MISC_TECHNICAL=192,
        /** Alias for #COATL_UCD_BLK_MISC_TECHNICAL */
        COATL_UCD_BLK_MISCELLANEOUS_TECHNICAL=COATL_UCD_BLK_MISC_TECHNICAL,

    /** '**Modi**' */ 
    COATL_UCD_BLK_MODI=193,

    /** '**Modifier_Letters**', '**Spacing_Modifier_Letters**' */ 
    COATL_UCD_BLK_MODIFIER_LETTERS=194,
        /** Alias for #COATL_UCD_BLK_MODIFIER_LETTERS */
        COATL_UCD_BLK_SPACING_MODIFIER_LETTERS=COATL_UCD_BLK_MODIFIER_LETTERS,

    /** '**Modifier_Tone_Letters**' */ 
    COATL_UCD_BLK_MODIFIER_TONE_LETTERS=195,

    /** '**Mongolian**' */ 
    COATL_UCD_BLK_MONGOLIAN=196,

    /** '**Mongolian_Sup**', '**Mongolian_Supplement**' */ 
    COATL_UCD_BLK_MONGOLIAN_SUP=197,
        /** Alias for #COATL_UCD_BLK_MONGOLIAN_SUP */
        COATL_UCD_BLK_MONGOLIAN_SUPPLEMENT=COATL_UCD_BLK_MONGOLIAN_SUP,

    /** '**Mro**' */ 
    COATL_UCD_BLK_MRO=198,

    /** '**Multani**' */ 
    COATL_UCD_BLK_MULTANI=199,

    /** '**Music**', '**Musical_Symbols**' */ 
    COATL_UCD_BLK_MUSIC=200,
        /** Alias for #COATL_UCD_BLK_MUSIC */
        COATL_UCD_BLK_MUSICAL_SYMBOLS=COATL_UCD_BLK_MUSIC,

    /** '**Myanmar**' */ 
    COATL_UCD_BLK_MYANMAR=201,

    /** '**Myanmar_Ext_A**', '**Myanmar_Extended_A**' */ 
    COATL_UCD_BLK_MYANMAR_EXT_A=202,
        /** Alias for #COATL_UCD_BLK_MYANMAR_EXT_A */
        COATL_UCD_BLK_MYANMAR_EXTENDED_A=COATL_UCD_BLK_MYANMAR_EXT_A,

    /** '**Myanmar_Ext_B**', '**Myanmar_Extended_B**' */ 
    COATL_UCD_BLK_MYANMAR_EXT_B=203,
        /** Alias for #COATL_UCD_BLK_MYANMAR_EXT_B */
        COATL_UCD_BLK_MYANMAR_EXTENDED_B=COATL_UCD_BLK_MYANMAR_EXT_B,

    /** '**Nabataean**' */ 
    COATL_UCD_BLK_NABATAEAN=204,

    /** '**Nandinagari**' */ 
    COATL_UCD_BLK_NANDINAGARI=205,

    /** '**NB**', '**No_Block**' */ 
    COATL_UCD_BLK_NB=206,
        /** Alias for #COATL_UCD_BLK_NB */
        COATL_UCD_BLK_NO_BLOCK=COATL_UCD_BLK_NB,

    /** '**New_Tai_Lue**' */ 
    COATL_UCD_BLK_NEW_TAI_LUE=207,

    /** '**Newa**' */ 
    COATL_UCD_BLK_NEWA=208,

    /** '**NKo**' */ 
    COATL_UCD_BLK_NKO=209,

    /** '**Number_Forms**' */ 
    COATL_UCD_BLK_NUMBER_FORMS=210,

    /** '**Nushu**' */ 
    COATL_UCD_BLK_NUSHU=211,

    /** '**Nyiakeng_Puachue_Hmong**' */ 
    COATL_UCD_BLK_NYIAKENG_PUACHUE_HMONG=212,

    /** '**OCR**', '**Optical_Character_Recognition**' */ 
    COATL_UCD_BLK_OCR=213,
        /** Alias for #COATL_UCD_BLK_OCR */
        COATL_UCD_BLK_OPTICAL_CHARACTER_RECOGNITION=COATL_UCD_BLK_OCR,

    /** '**Ogham**' */ 
    COATL_UCD_BLK_OGHAM=214,

    /** '**Ol_Chiki**' */ 
    COATL_UCD_BLK_OL_CHIKI=215,

    /** '**Old_Hungarian**' */ 
    COATL_UCD_BLK_OLD_HUNGARIAN=216,

    /** '**Old_Italic**' */ 
    COATL_UCD_BLK_OLD_ITALIC=217,

    /** '**Old_North_Arabian**' */ 
    COATL_UCD_BLK_OLD_NORTH_ARABIAN=218,

    /** '**Old_Permic**' */ 
    COATL_UCD_BLK_OLD_PERMIC=219,

    /** '**Old_Persian**' */ 
    COATL_UCD_BLK_OLD_PERSIAN=220,

    /** '**Old_Sogdian**' */ 
    COATL_UCD_BLK_OLD_SOGDIAN=221,

    /** '**Old_South_Arabian**' */ 
    COATL_UCD_BLK_OLD_SOUTH_ARABIAN=222,

    /** '**Old_Turkic**' */ 
    COATL_UCD_BLK_OLD_TURKIC=223,

    /** '**Oriya**' */ 
    COATL_UCD_BLK_ORIYA=224,

    /** '**Ornamental_Dingbats**' */ 
    COATL_UCD_BLK_ORNAMENTAL_DINGBATS=225,

    /** '**Osage**' */ 
    COATL_UCD_BLK_OSAGE=226,

    /** '**Osmanya**' */ 
    COATL_UCD_BLK_OSMANYA=227,

    /** '**Ottoman_Siyaq_Numbers**' */ 
    COATL_UCD_BLK_OTTOMAN_SIYAQ_NUMBERS=228,

    /** '**Pahawh_Hmong**' */ 
    COATL_UCD_BLK_PAHAWH_HMONG=229,

    /** '**Palmyrene**' */ 
    COATL_UCD_BLK_PALMYRENE=230,

    /** '**Pau_Cin_Hau**' */ 
    COATL_UCD_BLK_PAU_CIN_HAU=231,

    /** '**Phags_Pa**' */ 
    COATL_UCD_BLK_PHAGS_PA=232,

    /** '**Phaistos**', '**Phaistos_Disc**' */ 
    COATL_UCD_BLK_PHAISTOS=233,
        /** Alias for #COATL_UCD_BLK_PHAISTOS */
        COATL_UCD_BLK_PHAISTOS_DISC=COATL_UCD_BLK_PHAISTOS,

    /** '**Phoenician**' */ 
    COATL_UCD_BLK_PHOENICIAN=234,

    /** '**Phonetic_Ext**', '**Phonetic_Extensions**' */ 
    COATL_UCD_BLK_PHONETIC_EXT=235,
        /** Alias for #COATL_UCD_BLK_PHONETIC_EXT */
        COATL_UCD_BLK_PHONETIC_EXTENSIONS=COATL_UCD_BLK_PHONETIC_EXT,

    /** '**Phonetic_Ext_Sup**', '**Phonetic_Extensions_Supplement**' */ 
    COATL_UCD_BLK_PHONETIC_EXT_SUP=236,
        /** Alias for #COATL_UCD_BLK_PHONETIC_EXT_SUP */
        COATL_UCD_BLK_PHONETIC_EXTENSIONS_SUPPLEMENT=COATL_UCD_BLK_PHONETIC_EXT_SUP,

    /** '**Playing_Cards**' */ 
    COATL_UCD_BLK_PLAYING_CARDS=237,

    /** '**Psalter_Pahlavi**' */ 
    COATL_UCD_BLK_PSALTER_PAHLAVI=238,

    /** '**PUA**', '**Private_Use_Area**', '**Private_Use**' */ 
    COATL_UCD_BLK_PUA=239,
        /** Alias for #COATL_UCD_BLK_PUA */
        COATL_UCD_BLK_PRIVATE_USE_AREA=COATL_UCD_BLK_PUA,
        /** Alias for #COATL_UCD_BLK_PUA */
        COATL_UCD_BLK_PRIVATE_USE=COATL_UCD_BLK_PUA,

    /** '**Punctuation**', '**General_Punctuation**' */ 
    COATL_UCD_BLK_PUNCTUATION=240,
        /** Alias for #COATL_UCD_BLK_PUNCTUATION */
        COATL_UCD_BLK_GENERAL_PUNCTUATION=COATL_UCD_BLK_PUNCTUATION,

    /** '**Rejang**' */ 
    COATL_UCD_BLK_REJANG=241,

    /** '**Rumi**', '**Rumi_Numeral_Symbols**' */ 
    COATL_UCD_BLK_RUMI=242,
        /** Alias for #COATL_UCD_BLK_RUMI */
        COATL_UCD_BLK_RUMI_NUMERAL_SYMBOLS=COATL_UCD_BLK_RUMI,

    /** '**Runic**' */ 
    COATL_UCD_BLK_RUNIC=243,

    /** '**Samaritan**' */ 
    COATL_UCD_BLK_SAMARITAN=244,

    /** '**Saurashtra**' */ 
    COATL_UCD_BLK_SAURASHTRA=245,

    /** '**Sharada**' */ 
    COATL_UCD_BLK_SHARADA=246,

    /** '**Shavian**' */ 
    COATL_UCD_BLK_SHAVIAN=247,

    /** '**Shorthand_Format_Controls**' */ 
    COATL_UCD_BLK_SHORTHAND_FORMAT_CONTROLS=248,

    /** '**Siddham**' */ 
    COATL_UCD_BLK_SIDDHAM=249,

    /** '**Sinhala**' */ 
    COATL_UCD_BLK_SINHALA=250,

    /** '**Sinhala_Archaic_Numbers**' */ 
    COATL_UCD_BLK_SINHALA_ARCHAIC_NUMBERS=251,

    /** '**Small_Forms**', '**Small_Form_Variants**' */ 
    COATL_UCD_BLK_SMALL_FORMS=252,
        /** Alias for #COATL_UCD_BLK_SMALL_FORMS */
        COATL_UCD_BLK_SMALL_FORM_VARIANTS=COATL_UCD_BLK_SMALL_FORMS,

    /** '**Small_Kana_Ext**', '**Small_Kana_Extension**' */ 
    COATL_UCD_BLK_SMALL_KANA_EXT=253,
        /** Alias for #COATL_UCD_BLK_SMALL_KANA_EXT */
        COATL_UCD_BLK_SMALL_KANA_EXTENSION=COATL_UCD_BLK_SMALL_KANA_EXT,

    /** '**Sogdian**' */ 
    COATL_UCD_BLK_SOGDIAN=254,

    /** '**Sora_Sompeng**' */ 
    COATL_UCD_BLK_SORA_SOMPENG=255,

    /** '**Soyombo**' */ 
    COATL_UCD_BLK_SOYOMBO=256,

    /** '**Specials**' */ 
    COATL_UCD_BLK_SPECIALS=257,

    /** '**Sundanese**' */ 
    COATL_UCD_BLK_SUNDANESE=258,

    /** '**Sundanese_Sup**', '**Sundanese_Supplement**' */ 
    COATL_UCD_BLK_SUNDANESE_SUP=259,
        /** Alias for #COATL_UCD_BLK_SUNDANESE_SUP */
        COATL_UCD_BLK_SUNDANESE_SUPPLEMENT=COATL_UCD_BLK_SUNDANESE_SUP,

    /** '**Sup_Arrows_A**', '**Supplemental_Arrows_A**' */ 
    COATL_UCD_BLK_SUP_ARROWS_A=260,
        /** Alias for #COATL_UCD_BLK_SUP_ARROWS_A */
        COATL_UCD_BLK_SUPPLEMENTAL_ARROWS_A=COATL_UCD_BLK_SUP_ARROWS_A,

    /** '**Sup_Arrows_B**', '**Supplemental_Arrows_B**' */ 
    COATL_UCD_BLK_SUP_ARROWS_B=261,
        /** Alias for #COATL_UCD_BLK_SUP_ARROWS_B */
        COATL_UCD_BLK_SUPPLEMENTAL_ARROWS_B=COATL_UCD_BLK_SUP_ARROWS_B,

    /** '**Sup_Arrows_C**', '**Supplemental_Arrows_C**' */ 
    COATL_UCD_BLK_SUP_ARROWS_C=262,
        /** Alias for #COATL_UCD_BLK_SUP_ARROWS_C */
        COATL_UCD_BLK_SUPPLEMENTAL_ARROWS_C=COATL_UCD_BLK_SUP_ARROWS_C,

    /** '**Sup_Math_Operators**', '**Supplemental_Mathematical_Operators**' */ 
    COATL_UCD_BLK_SUP_MATH_OPERATORS=263,
        /** Alias for #COATL_UCD_BLK_SUP_MATH_OPERATORS */
        COATL_UCD_BLK_SUPPLEMENTAL_MATHEMATICAL_OPERATORS=COATL_UCD_BLK_SUP_MATH_OPERATORS,

    /** '**Sup_PUA_A**', '**Supplementary_Private_Use_Area_A**' */ 
    COATL_UCD_BLK_SUP_PUA_A=264,
        /** Alias for #COATL_UCD_BLK_SUP_PUA_A */
        COATL_UCD_BLK_SUPPLEMENTARY_PRIVATE_USE_AREA_A=COATL_UCD_BLK_SUP_PUA_A,

    /** '**Sup_PUA_B**', '**Supplementary_Private_Use_Area_B**' */ 
    COATL_UCD_BLK_SUP_PUA_B=265,
        /** Alias for #COATL_UCD_BLK_SUP_PUA_B */
        COATL_UCD_BLK_SUPPLEMENTARY_PRIVATE_USE_AREA_B=COATL_UCD_BLK_SUP_PUA_B,

    /** '**Sup_Punctuation**', '**Supplemental_Punctuation**' */ 
    COATL_UCD_BLK_SUP_PUNCTUATION=266,
        /** Alias for #COATL_UCD_BLK_SUP_PUNCTUATION */
        COATL_UCD_BLK_SUPPLEMENTAL_PUNCTUATION=COATL_UCD_BLK_SUP_PUNCTUATION,

    /** '**Sup_Symbols_And_Pictographs**', '**Supplemental_Symbols_And_Pictographs**' */ 
    COATL_UCD_BLK_SUP_SYMBOLS_AND_PICTOGRAPHS=267,
        /** Alias for #COATL_UCD_BLK_SUP_SYMBOLS_AND_PICTOGRAPHS */
        COATL_UCD_BLK_SUPPLEMENTAL_SYMBOLS_AND_PICTOGRAPHS=COATL_UCD_BLK_SUP_SYMBOLS_AND_PICTOGRAPHS,

    /** '**Super_And_Sub**', '**Superscripts_And_Subscripts**' */ 
    COATL_UCD_BLK_SUPER_AND_SUB=268,
        /** Alias for #COATL_UCD_BLK_SUPER_AND_SUB */
        COATL_UCD_BLK_SUPERSCRIPTS_AND_SUBSCRIPTS=COATL_UCD_BLK_SUPER_AND_SUB,

    /** '**Sutton_SignWriting**' */ 
    COATL_UCD_BLK_SUTTON_SIGNWRITING=269,

    /** '**Syloti_Nagri**' */ 
    COATL_UCD_BLK_SYLOTI_NAGRI=270,

    /** '**Symbols_And_Pictographs_Ext_A**', '**Symbols_And_Pictographs_Extended_A**' */ 
    COATL_UCD_BLK_SYMBOLS_AND_PICTOGRAPHS_EXT_A=271,
        /** Alias for #COATL_UCD_BLK_SYMBOLS_AND_PICTOGRAPHS_EXT_A */
        COATL_UCD_BLK_SYMBOLS_AND_PICTOGRAPHS_EXTENDED_A=COATL_UCD_BLK_SYMBOLS_AND_PICTOGRAPHS_EXT_A,

    /** '**Symbols_For_Legacy_Computing**' */ 
    COATL_UCD_BLK_SYMBOLS_FOR_LEGACY_COMPUTING=272,

    /** '**Syriac**' */ 
    COATL_UCD_BLK_SYRIAC=273,

    /** '**Syriac_Sup**', '**Syriac_Supplement**' */ 
    COATL_UCD_BLK_SYRIAC_SUP=274,
        /** Alias for #COATL_UCD_BLK_SYRIAC_SUP */
        COATL_UCD_BLK_SYRIAC_SUPPLEMENT=COATL_UCD_BLK_SYRIAC_SUP,

    /** '**Tagalog**' */ 
    COATL_UCD_BLK_TAGALOG=275,

    /** '**Tagbanwa**' */ 
    COATL_UCD_BLK_TAGBANWA=276,

    /** '**Tags**' */ 
    COATL_UCD_BLK_TAGS=277,

    /** '**Tai_Le**' */ 
    COATL_UCD_BLK_TAI_LE=278,

    /** '**Tai_Tham**' */ 
    COATL_UCD_BLK_TAI_THAM=279,

    /** '**Tai_Viet**' */ 
    COATL_UCD_BLK_TAI_VIET=280,

    /** '**Tai_Xuan_Jing**', '**Tai_Xuan_Jing_Symbols**' */ 
    COATL_UCD_BLK_TAI_XUAN_JING=281,
        /** Alias for #COATL_UCD_BLK_TAI_XUAN_JING */
        COATL_UCD_BLK_TAI_XUAN_JING_SYMBOLS=COATL_UCD_BLK_TAI_XUAN_JING,

    /** '**Takri**' */ 
    COATL_UCD_BLK_TAKRI=282,

    /** '**Tamil**' */ 
    COATL_UCD_BLK_TAMIL=283,

    /** '**Tamil_Sup**', '**Tamil_Supplement**' */ 
    COATL_UCD_BLK_TAMIL_SUP=284,
        /** Alias for #COATL_UCD_BLK_TAMIL_SUP */
        COATL_UCD_BLK_TAMIL_SUPPLEMENT=COATL_UCD_BLK_TAMIL_SUP,

    /** '**Tangut**' */ 
    COATL_UCD_BLK_TANGUT=285,

    /** '**Tangut_Components**' */ 
    COATL_UCD_BLK_TANGUT_COMPONENTS=286,

    /** '**Tangut_Sup**', '**Tangut_Supplement**' */ 
    COATL_UCD_BLK_TANGUT_SUP=287,
        /** Alias for #COATL_UCD_BLK_TANGUT_SUP */
        COATL_UCD_BLK_TANGUT_SUPPLEMENT=COATL_UCD_BLK_TANGUT_SUP,

    /** '**Telugu**' */ 
    COATL_UCD_BLK_TELUGU=288,

    /** '**Thaana**' */ 
    COATL_UCD_BLK_THAANA=289,

    /** '**Thai**' */ 
    COATL_UCD_BLK_THAI=290,

    /** '**Tibetan**' */ 
    COATL_UCD_BLK_TIBETAN=291,

    /** '**Tifinagh**' */ 
    COATL_UCD_BLK_TIFINAGH=292,

    /** '**Tirhuta**' */ 
    COATL_UCD_BLK_TIRHUTA=293,

    /** '**Transport_And_Map**', '**Transport_And_Map_Symbols**' */ 
    COATL_UCD_BLK_TRANSPORT_AND_MAP=294,
        /** Alias for #COATL_UCD_BLK_TRANSPORT_AND_MAP */
        COATL_UCD_BLK_TRANSPORT_AND_MAP_SYMBOLS=COATL_UCD_BLK_TRANSPORT_AND_MAP,

    /** '**UCAS**', '**Unified_Canadian_Aboriginal_Syllabics**', '**Canadian_Syllabics**' */ 
    COATL_UCD_BLK_UCAS=295,
        /** Alias for #COATL_UCD_BLK_UCAS */
        COATL_UCD_BLK_UNIFIED_CANADIAN_ABORIGINAL_SYLLABICS=COATL_UCD_BLK_UCAS,
        /** Alias for #COATL_UCD_BLK_UCAS */
        COATL_UCD_BLK_CANADIAN_SYLLABICS=COATL_UCD_BLK_UCAS,

    /** '**UCAS_Ext**', '**Unified_Canadian_Aboriginal_Syllabics_Extended**' */ 
    COATL_UCD_BLK_UCAS_EXT=296,
        /** Alias for #COATL_UCD_BLK_UCAS_EXT */
        COATL_UCD_BLK_UNIFIED_CANADIAN_ABORIGINAL_SYLLABICS_EXTENDED=COATL_UCD_BLK_UCAS_EXT,

    /** '**Ugaritic**' */ 
    COATL_UCD_BLK_UGARITIC=297,

    /** '**Vai**' */ 
    COATL_UCD_BLK_VAI=298,

    /** '**Vedic_Ext**', '**Vedic_Extensions**' */ 
    COATL_UCD_BLK_VEDIC_EXT=299,
        /** Alias for #COATL_UCD_BLK_VEDIC_EXT */
        COATL_UCD_BLK_VEDIC_EXTENSIONS=COATL_UCD_BLK_VEDIC_EXT,

    /** '**Vertical_Forms**' */ 
    COATL_UCD_BLK_VERTICAL_FORMS=300,

    /** '**VS**', '**Variation_Selectors**' */ 
    COATL_UCD_BLK_VS=301,
        /** Alias for #COATL_UCD_BLK_VS */
        COATL_UCD_BLK_VARIATION_SELECTORS=COATL_UCD_BLK_VS,

    /** '**VS_Sup**', '**Variation_Selectors_Supplement**' */ 
    COATL_UCD_BLK_VS_SUP=302,
        /** Alias for #COATL_UCD_BLK_VS_SUP */
        COATL_UCD_BLK_VARIATION_SELECTORS_SUPPLEMENT=COATL_UCD_BLK_VS_SUP,

    /** '**Wancho**' */ 
    COATL_UCD_BLK_WANCHO=303,

    /** '**Warang_Citi**' */ 
    COATL_UCD_BLK_WARANG_CITI=304,

    /** '**Yezidi**' */ 
    COATL_UCD_BLK_YEZIDI=305,

    /** '**Yi_Radicals**' */ 
    COATL_UCD_BLK_YI_RADICALS=306,

    /** '**Yi_Syllables**' */ 
    COATL_UCD_BLK_YI_SYLLABLES=307,

    /** '**Yijing**', '**Yijing_Hexagram_Symbols**' */ 
    COATL_UCD_BLK_YIJING=308,
        /** Alias for #COATL_UCD_BLK_YIJING */
        COATL_UCD_BLK_YIJING_HEXAGRAM_SYMBOLS=COATL_UCD_BLK_YIJING,

    /** '**Zanabazar_Square**' */ 
    COATL_UCD_BLK_ZANABAZAR_SQUARE=309,
} Coatl_Ucd_Blk;

/**
 * Number of values for Unicode character property '*blk*'.
 *
 * @see Coatl_Ucd_Blk
 */
#define COATL_UCD_BLK_NBVALUES       309

/**
 * Values for Unicode character property '**sc**'.
 *
 * Names are automatically generated from the UCD file 
 * `PropertyValueAliases.txt`.
 *
 * @see COATL_UCD_SC
 */
typedef enum Coatl_Ucd_Sc {
    /** '**Adlm**', '**Adlam**' */ 
    COATL_UCD_SC_ADLM=1,
        /** Alias for #COATL_UCD_SC_ADLM */
        COATL_UCD_SC_ADLAM=COATL_UCD_SC_ADLM,

    /** '**Aghb**', '**Caucasian_Albanian**' */ 
    COATL_UCD_SC_AGHB=2,
        /** Alias for #COATL_UCD_SC_AGHB */
        COATL_UCD_SC_CAUCASIAN_ALBANIAN=COATL_UCD_SC_AGHB,

    /** '**Ahom**' */ 
    COATL_UCD_SC_AHOM=3,

    /** '**Arab**', '**Arabic**' */ 
    COATL_UCD_SC_ARAB=4,
        /** Alias for #COATL_UCD_SC_ARAB */
        COATL_UCD_SC_ARABIC=COATL_UCD_SC_ARAB,

    /** '**Armi**', '**Imperial_Aramaic**' */ 
    COATL_UCD_SC_ARMI=5,
        /** Alias for #COATL_UCD_SC_ARMI */
        COATL_UCD_SC_IMPERIAL_ARAMAIC=COATL_UCD_SC_ARMI,

    /** '**Armn**', '**Armenian**' */ 
    COATL_UCD_SC_ARMN=6,
        /** Alias for #COATL_UCD_SC_ARMN */
        COATL_UCD_SC_ARMENIAN=COATL_UCD_SC_ARMN,

    /** '**Avst**', '**Avestan**' */ 
    COATL_UCD_SC_AVST=7,
        /** Alias for #COATL_UCD_SC_AVST */
        COATL_UCD_SC_AVESTAN=COATL_UCD_SC_AVST,

    /** '**Bali**', '**Balinese**' */ 
    COATL_UCD_SC_BALI=8,
        /** Alias for #COATL_UCD_SC_BALI */
        COATL_UCD_SC_BALINESE=COATL_UCD_SC_BALI,

    /** '**Bamu**', '**Bamum**' */ 
    COATL_UCD_SC_BAMU=9,
        /** Alias for #COATL_UCD_SC_BAMU */
        COATL_UCD_SC_BAMUM=COATL_UCD_SC_BAMU,

    /** '**Bass**', '**Bassa_Vah**' */ 
    COATL_UCD_SC_BASS=10,
        /** Alias for #COATL_UCD_SC_BASS */
        COATL_UCD_SC_BASSA_VAH=COATL_UCD_SC_BASS,

    /** '**Batk**', '**Batak**' */ 
    COATL_UCD_SC_BATK=11,
        /** Alias for #COATL_UCD_SC_BATK */
        COATL_UCD_SC_BATAK=COATL_UCD_SC_BATK,

    /** '**Beng**', '**Bengali**' */ 
    COATL_UCD_SC_BENG=12,
        /** Alias for #COATL_UCD_SC_BENG */
        COATL_UCD_SC_BENGALI=COATL_UCD_SC_BENG,

    /** '**Bhks**', '**Bhaiksuki**' */ 
    COATL_UCD_SC_BHKS=13,
        /** Alias for #COATL_UCD_SC_BHKS */
        COATL_UCD_SC_BHAIKSUKI=COATL_UCD_SC_BHKS,

    /** '**Bopo**', '**Bopomofo**' */ 
    COATL_UCD_SC_BOPO=14,
        /** Alias for #COATL_UCD_SC_BOPO */
        COATL_UCD_SC_BOPOMOFO=COATL_UCD_SC_BOPO,

    /** '**Brah**', '**Brahmi**' */ 
    COATL_UCD_SC_BRAH=15,
        /** Alias for #COATL_UCD_SC_BRAH */
        COATL_UCD_SC_BRAHMI=COATL_UCD_SC_BRAH,

    /** '**Brai**', '**Braille**' */ 
    COATL_UCD_SC_BRAI=16,
        /** Alias for #COATL_UCD_SC_BRAI */
        COATL_UCD_SC_BRAILLE=COATL_UCD_SC_BRAI,

    /** '**Bugi**', '**Buginese**' */ 
    COATL_UCD_SC_BUGI=17,
        /** Alias for #COATL_UCD_SC_BUGI */
        COATL_UCD_SC_BUGINESE=COATL_UCD_SC_BUGI,

    /** '**Buhd**', '**Buhid**' */ 
    COATL_UCD_SC_BUHD=18,
        /** Alias for #COATL_UCD_SC_BUHD */
        COATL_UCD_SC_BUHID=COATL_UCD_SC_BUHD,

    /** '**Cakm**', '**Chakma**' */ 
    COATL_UCD_SC_CAKM=19,
        /** Alias for #COATL_UCD_SC_CAKM */
        COATL_UCD_SC_CHAKMA=COATL_UCD_SC_CAKM,

    /** '**Cans**', '**Canadian_Aboriginal**' */ 
    COATL_UCD_SC_CANS=20,
        /** Alias for #COATL_UCD_SC_CANS */
        COATL_UCD_SC_CANADIAN_ABORIGINAL=COATL_UCD_SC_CANS,

    /** '**Cari**', '**Carian**' */ 
    COATL_UCD_SC_CARI=21,
        /** Alias for #COATL_UCD_SC_CARI */
        COATL_UCD_SC_CARIAN=COATL_UCD_SC_CARI,

    /** '**Cham**' */ 
    COATL_UCD_SC_CHAM=22,

    /** '**Cher**', '**Cherokee**' */ 
    COATL_UCD_SC_CHER=23,
        /** Alias for #COATL_UCD_SC_CHER */
        COATL_UCD_SC_CHEROKEE=COATL_UCD_SC_CHER,

    /** '**Chrs**', '**Chorasmian**' */ 
    COATL_UCD_SC_CHRS=24,
        /** Alias for #COATL_UCD_SC_CHRS */
        COATL_UCD_SC_CHORASMIAN=COATL_UCD_SC_CHRS,

    /** '**Copt**', '**Coptic**', '**Qaac**' */ 
    COATL_UCD_SC_COPT=25,
        /** Alias for #COATL_UCD_SC_COPT */
        COATL_UCD_SC_COPTIC=COATL_UCD_SC_COPT,
        /** Alias for #COATL_UCD_SC_COPT */
        COATL_UCD_SC_QAAC=COATL_UCD_SC_COPT,

    /** '**Cprt**', '**Cypriot**' */ 
    COATL_UCD_SC_CPRT=26,
        /** Alias for #COATL_UCD_SC_CPRT */
        COATL_UCD_SC_CYPRIOT=COATL_UCD_SC_CPRT,

    /** '**Cyrl**', '**Cyrillic**' */ 
    COATL_UCD_SC_CYRL=27,
        /** Alias for #COATL_UCD_SC_CYRL */
        COATL_UCD_SC_CYRILLIC=COATL_UCD_SC_CYRL,

    /** '**Deva**', '**Devanagari**' */ 
    COATL_UCD_SC_DEVA=28,
        /** Alias for #COATL_UCD_SC_DEVA */
        COATL_UCD_SC_DEVANAGARI=COATL_UCD_SC_DEVA,

    /** '**Diak**', '**Dives_Akuru**' */ 
    COATL_UCD_SC_DIAK=29,
        /** Alias for #COATL_UCD_SC_DIAK */
        COATL_UCD_SC_DIVES_AKURU=COATL_UCD_SC_DIAK,

    /** '**Dogr**', '**Dogra**' */ 
    COATL_UCD_SC_DOGR=30,
        /** Alias for #COATL_UCD_SC_DOGR */
        COATL_UCD_SC_DOGRA=COATL_UCD_SC_DOGR,

    /** '**Dsrt**', '**Deseret**' */ 
    COATL_UCD_SC_DSRT=31,
        /** Alias for #COATL_UCD_SC_DSRT */
        COATL_UCD_SC_DESERET=COATL_UCD_SC_DSRT,

    /** '**Dupl**', '**Duployan**' */ 
    COATL_UCD_SC_DUPL=32,
        /** Alias for #COATL_UCD_SC_DUPL */
        COATL_UCD_SC_DUPLOYAN=COATL_UCD_SC_DUPL,

    /** '**Egyp**', '**Egyptian_Hieroglyphs**' */ 
    COATL_UCD_SC_EGYP=33,
        /** Alias for #COATL_UCD_SC_EGYP */
        COATL_UCD_SC_EGYPTIAN_HIEROGLYPHS=COATL_UCD_SC_EGYP,

    /** '**Elba**', '**Elbasan**' */ 
    COATL_UCD_SC_ELBA=34,
        /** Alias for #COATL_UCD_SC_ELBA */
        COATL_UCD_SC_ELBASAN=COATL_UCD_SC_ELBA,

    /** '**Elym**', '**Elymaic**' */ 
    COATL_UCD_SC_ELYM=35,
        /** Alias for #COATL_UCD_SC_ELYM */
        COATL_UCD_SC_ELYMAIC=COATL_UCD_SC_ELYM,

    /** '**Ethi**', '**Ethiopic**' */ 
    COATL_UCD_SC_ETHI=36,
        /** Alias for #COATL_UCD_SC_ETHI */
        COATL_UCD_SC_ETHIOPIC=COATL_UCD_SC_ETHI,

    /** '**Geor**', '**Georgian**' */ 
    COATL_UCD_SC_GEOR=37,
        /** Alias for #COATL_UCD_SC_GEOR */
        COATL_UCD_SC_GEORGIAN=COATL_UCD_SC_GEOR,

    /** '**Glag**', '**Glagolitic**' */ 
    COATL_UCD_SC_GLAG=38,
        /** Alias for #COATL_UCD_SC_GLAG */
        COATL_UCD_SC_GLAGOLITIC=COATL_UCD_SC_GLAG,

    /** '**Gong**', '**Gunjala_Gondi**' */ 
    COATL_UCD_SC_GONG=39,
        /** Alias for #COATL_UCD_SC_GONG */
        COATL_UCD_SC_GUNJALA_GONDI=COATL_UCD_SC_GONG,

    /** '**Gonm**', '**Masaram_Gondi**' */ 
    COATL_UCD_SC_GONM=40,
        /** Alias for #COATL_UCD_SC_GONM */
        COATL_UCD_SC_MASARAM_GONDI=COATL_UCD_SC_GONM,

    /** '**Goth**', '**Gothic**' */ 
    COATL_UCD_SC_GOTH=41,
        /** Alias for #COATL_UCD_SC_GOTH */
        COATL_UCD_SC_GOTHIC=COATL_UCD_SC_GOTH,

    /** '**Gran**', '**Grantha**' */ 
    COATL_UCD_SC_GRAN=42,
        /** Alias for #COATL_UCD_SC_GRAN */
        COATL_UCD_SC_GRANTHA=COATL_UCD_SC_GRAN,

    /** '**Grek**', '**Greek**' */ 
    COATL_UCD_SC_GREK=43,
        /** Alias for #COATL_UCD_SC_GREK */
        COATL_UCD_SC_GREEK=COATL_UCD_SC_GREK,

    /** '**Gujr**', '**Gujarati**' */ 
    COATL_UCD_SC_GUJR=44,
        /** Alias for #COATL_UCD_SC_GUJR */
        COATL_UCD_SC_GUJARATI=COATL_UCD_SC_GUJR,

    /** '**Guru**', '**Gurmukhi**' */ 
    COATL_UCD_SC_GURU=45,
        /** Alias for #COATL_UCD_SC_GURU */
        COATL_UCD_SC_GURMUKHI=COATL_UCD_SC_GURU,

    /** '**Hang**', '**Hangul**' */ 
    COATL_UCD_SC_HANG=46,
        /** Alias for #COATL_UCD_SC_HANG */
        COATL_UCD_SC_HANGUL=COATL_UCD_SC_HANG,

    /** '**Hani**', '**Han**' */ 
    COATL_UCD_SC_HANI=47,
        /** Alias for #COATL_UCD_SC_HANI */
        COATL_UCD_SC_HAN=COATL_UCD_SC_HANI,

    /** '**Hano**', '**Hanunoo**' */ 
    COATL_UCD_SC_HANO=48,
        /** Alias for #COATL_UCD_SC_HANO */
        COATL_UCD_SC_HANUNOO=COATL_UCD_SC_HANO,

    /** '**Hatr**', '**Hatran**' */ 
    COATL_UCD_SC_HATR=49,
        /** Alias for #COATL_UCD_SC_HATR */
        COATL_UCD_SC_HATRAN=COATL_UCD_SC_HATR,

    /** '**Hebr**', '**Hebrew**' */ 
    COATL_UCD_SC_HEBR=50,
        /** Alias for #COATL_UCD_SC_HEBR */
        COATL_UCD_SC_HEBREW=COATL_UCD_SC_HEBR,

    /** '**Hira**', '**Hiragana**' */ 
    COATL_UCD_SC_HIRA=51,
        /** Alias for #COATL_UCD_SC_HIRA */
        COATL_UCD_SC_HIRAGANA=COATL_UCD_SC_HIRA,

    /** '**Hluw**', '**Anatolian_Hieroglyphs**' */ 
    COATL_UCD_SC_HLUW=52,
        /** Alias for #COATL_UCD_SC_HLUW */
        COATL_UCD_SC_ANATOLIAN_HIEROGLYPHS=COATL_UCD_SC_HLUW,

    /** '**Hmng**', '**Pahawh_Hmong**' */ 
    COATL_UCD_SC_HMNG=53,
        /** Alias for #COATL_UCD_SC_HMNG */
        COATL_UCD_SC_PAHAWH_HMONG=COATL_UCD_SC_HMNG,

    /** '**Hmnp**', '**Nyiakeng_Puachue_Hmong**' */ 
    COATL_UCD_SC_HMNP=54,
        /** Alias for #COATL_UCD_SC_HMNP */
        COATL_UCD_SC_NYIAKENG_PUACHUE_HMONG=COATL_UCD_SC_HMNP,

    /** '**Hrkt**', '**Katakana_Or_Hiragana**' */ 
    COATL_UCD_SC_HRKT=55,
        /** Alias for #COATL_UCD_SC_HRKT */
        COATL_UCD_SC_KATAKANA_OR_HIRAGANA=COATL_UCD_SC_HRKT,

    /** '**Hung**', '**Old_Hungarian**' */ 
    COATL_UCD_SC_HUNG=56,
        /** Alias for #COATL_UCD_SC_HUNG */
        COATL_UCD_SC_OLD_HUNGARIAN=COATL_UCD_SC_HUNG,

    /** '**Ital**', '**Old_Italic**' */ 
    COATL_UCD_SC_ITAL=57,
        /** Alias for #COATL_UCD_SC_ITAL */
        COATL_UCD_SC_OLD_ITALIC=COATL_UCD_SC_ITAL,

    /** '**Java**', '**Javanese**' */ 
    COATL_UCD_SC_JAVA=58,
        /** Alias for #COATL_UCD_SC_JAVA */
        COATL_UCD_SC_JAVANESE=COATL_UCD_SC_JAVA,

    /** '**Kali**', '**Kayah_Li**' */ 
    COATL_UCD_SC_KALI=59,
        /** Alias for #COATL_UCD_SC_KALI */
        COATL_UCD_SC_KAYAH_LI=COATL_UCD_SC_KALI,

    /** '**Kana**', '**Katakana**' */ 
    COATL_UCD_SC_KANA=60,
        /** Alias for #COATL_UCD_SC_KANA */
        COATL_UCD_SC_KATAKANA=COATL_UCD_SC_KANA,

    /** '**Khar**', '**Kharoshthi**' */ 
    COATL_UCD_SC_KHAR=61,
        /** Alias for #COATL_UCD_SC_KHAR */
        COATL_UCD_SC_KHAROSHTHI=COATL_UCD_SC_KHAR,

    /** '**Khmr**', '**Khmer**' */ 
    COATL_UCD_SC_KHMR=62,
        /** Alias for #COATL_UCD_SC_KHMR */
        COATL_UCD_SC_KHMER=COATL_UCD_SC_KHMR,

    /** '**Khoj**', '**Khojki**' */ 
    COATL_UCD_SC_KHOJ=63,
        /** Alias for #COATL_UCD_SC_KHOJ */
        COATL_UCD_SC_KHOJKI=COATL_UCD_SC_KHOJ,

    /** '**Kits**', '**Khitan_Small_Script**' */ 
    COATL_UCD_SC_KITS=64,
        /** Alias for #COATL_UCD_SC_KITS */
        COATL_UCD_SC_KHITAN_SMALL_SCRIPT=COATL_UCD_SC_KITS,

    /** '**Knda**', '**Kannada**' */ 
    COATL_UCD_SC_KNDA=65,
        /** Alias for #COATL_UCD_SC_KNDA */
        COATL_UCD_SC_KANNADA=COATL_UCD_SC_KNDA,

    /** '**Kthi**', '**Kaithi**' */ 
    COATL_UCD_SC_KTHI=66,
        /** Alias for #COATL_UCD_SC_KTHI */
        COATL_UCD_SC_KAITHI=COATL_UCD_SC_KTHI,

    /** '**Lana**', '**Tai_Tham**' */ 
    COATL_UCD_SC_LANA=67,
        /** Alias for #COATL_UCD_SC_LANA */
        COATL_UCD_SC_TAI_THAM=COATL_UCD_SC_LANA,

    /** '**Laoo**', '**Lao**' */ 
    COATL_UCD_SC_LAOO=68,
        /** Alias for #COATL_UCD_SC_LAOO */
        COATL_UCD_SC_LAO=COATL_UCD_SC_LAOO,

    /** '**Latn**', '**Latin**' */ 
    COATL_UCD_SC_LATN=69,
        /** Alias for #COATL_UCD_SC_LATN */
        COATL_UCD_SC_LATIN=COATL_UCD_SC_LATN,

    /** '**Lepc**', '**Lepcha**' */ 
    COATL_UCD_SC_LEPC=70,
        /** Alias for #COATL_UCD_SC_LEPC */
        COATL_UCD_SC_LEPCHA=COATL_UCD_SC_LEPC,

    /** '**Limb**', '**Limbu**' */ 
    COATL_UCD_SC_LIMB=71,
        /** Alias for #COATL_UCD_SC_LIMB */
        COATL_UCD_SC_LIMBU=COATL_UCD_SC_LIMB,

    /** '**Lina**', '**Linear_A**' */ 
    COATL_UCD_SC_LINA=72,
        /** Alias for #COATL_UCD_SC_LINA */
        COATL_UCD_SC_LINEAR_A=COATL_UCD_SC_LINA,

    /** '**Linb**', '**Linear_B**' */ 
    COATL_UCD_SC_LINB=73,
        /** Alias for #COATL_UCD_SC_LINB */
        COATL_UCD_SC_LINEAR_B=COATL_UCD_SC_LINB,

    /** '**Lisu**' */ 
    COATL_UCD_SC_LISU=74,

    /** '**Lyci**', '**Lycian**' */ 
    COATL_UCD_SC_LYCI=75,
        /** Alias for #COATL_UCD_SC_LYCI */
        COATL_UCD_SC_LYCIAN=COATL_UCD_SC_LYCI,

    /** '**Lydi**', '**Lydian**' */ 
    COATL_UCD_SC_LYDI=76,
        /** Alias for #COATL_UCD_SC_LYDI */
        COATL_UCD_SC_LYDIAN=COATL_UCD_SC_LYDI,

    /** '**Mahj**', '**Mahajani**' */ 
    COATL_UCD_SC_MAHJ=77,
        /** Alias for #COATL_UCD_SC_MAHJ */
        COATL_UCD_SC_MAHAJANI=COATL_UCD_SC_MAHJ,

    /** '**Maka**', '**Makasar**' */ 
    COATL_UCD_SC_MAKA=78,
        /** Alias for #COATL_UCD_SC_MAKA */
        COATL_UCD_SC_MAKASAR=COATL_UCD_SC_MAKA,

    /** '**Mand**', '**Mandaic**' */ 
    COATL_UCD_SC_MAND=79,
        /** Alias for #COATL_UCD_SC_MAND */
        COATL_UCD_SC_MANDAIC=COATL_UCD_SC_MAND,

    /** '**Mani**', '**Manichaean**' */ 
    COATL_UCD_SC_MANI=80,
        /** Alias for #COATL_UCD_SC_MANI */
        COATL_UCD_SC_MANICHAEAN=COATL_UCD_SC_MANI,

    /** '**Marc**', '**Marchen**' */ 
    COATL_UCD_SC_MARC=81,
        /** Alias for #COATL_UCD_SC_MARC */
        COATL_UCD_SC_MARCHEN=COATL_UCD_SC_MARC,

    /** '**Medf**', '**Medefaidrin**' */ 
    COATL_UCD_SC_MEDF=82,
        /** Alias for #COATL_UCD_SC_MEDF */
        COATL_UCD_SC_MEDEFAIDRIN=COATL_UCD_SC_MEDF,

    /** '**Mend**', '**Mende_Kikakui**' */ 
    COATL_UCD_SC_MEND=83,
        /** Alias for #COATL_UCD_SC_MEND */
        COATL_UCD_SC_MENDE_KIKAKUI=COATL_UCD_SC_MEND,

    /** '**Merc**', '**Meroitic_Cursive**' */ 
    COATL_UCD_SC_MERC=84,
        /** Alias for #COATL_UCD_SC_MERC */
        COATL_UCD_SC_MEROITIC_CURSIVE=COATL_UCD_SC_MERC,

    /** '**Mero**', '**Meroitic_Hieroglyphs**' */ 
    COATL_UCD_SC_MERO=85,
        /** Alias for #COATL_UCD_SC_MERO */
        COATL_UCD_SC_MEROITIC_HIEROGLYPHS=COATL_UCD_SC_MERO,

    /** '**Mlym**', '**Malayalam**' */ 
    COATL_UCD_SC_MLYM=86,
        /** Alias for #COATL_UCD_SC_MLYM */
        COATL_UCD_SC_MALAYALAM=COATL_UCD_SC_MLYM,

    /** '**Modi**' */ 
    COATL_UCD_SC_MODI=87,

    /** '**Mong**', '**Mongolian**' */ 
    COATL_UCD_SC_MONG=88,
        /** Alias for #COATL_UCD_SC_MONG */
        COATL_UCD_SC_MONGOLIAN=COATL_UCD_SC_MONG,

    /** '**Mroo**', '**Mro**' */ 
    COATL_UCD_SC_MROO=89,
        /** Alias for #COATL_UCD_SC_MROO */
        COATL_UCD_SC_MRO=COATL_UCD_SC_MROO,

    /** '**Mtei**', '**Meetei_Mayek**' */ 
    COATL_UCD_SC_MTEI=90,
        /** Alias for #COATL_UCD_SC_MTEI */
        COATL_UCD_SC_MEETEI_MAYEK=COATL_UCD_SC_MTEI,

    /** '**Mult**', '**Multani**' */ 
    COATL_UCD_SC_MULT=91,
        /** Alias for #COATL_UCD_SC_MULT */
        COATL_UCD_SC_MULTANI=COATL_UCD_SC_MULT,

    /** '**Mymr**', '**Myanmar**' */ 
    COATL_UCD_SC_MYMR=92,
        /** Alias for #COATL_UCD_SC_MYMR */
        COATL_UCD_SC_MYANMAR=COATL_UCD_SC_MYMR,

    /** '**Nand**', '**Nandinagari**' */ 
    COATL_UCD_SC_NAND=93,
        /** Alias for #COATL_UCD_SC_NAND */
        COATL_UCD_SC_NANDINAGARI=COATL_UCD_SC_NAND,

    /** '**Narb**', '**Old_North_Arabian**' */ 
    COATL_UCD_SC_NARB=94,
        /** Alias for #COATL_UCD_SC_NARB */
        COATL_UCD_SC_OLD_NORTH_ARABIAN=COATL_UCD_SC_NARB,

    /** '**Nbat**', '**Nabataean**' */ 
    COATL_UCD_SC_NBAT=95,
        /** Alias for #COATL_UCD_SC_NBAT */
        COATL_UCD_SC_NABATAEAN=COATL_UCD_SC_NBAT,

    /** '**Newa**' */ 
    COATL_UCD_SC_NEWA=96,

    /** '**Nkoo**', '**Nko**' */ 
    COATL_UCD_SC_NKOO=97,
        /** Alias for #COATL_UCD_SC_NKOO */
        COATL_UCD_SC_NKO=COATL_UCD_SC_NKOO,

    /** '**Nshu**', '**Nushu**' */ 
    COATL_UCD_SC_NSHU=98,
        /** Alias for #COATL_UCD_SC_NSHU */
        COATL_UCD_SC_NUSHU=COATL_UCD_SC_NSHU,

    /** '**Ogam**', '**Ogham**' */ 
    COATL_UCD_SC_OGAM=99,
        /** Alias for #COATL_UCD_SC_OGAM */
        COATL_UCD_SC_OGHAM=COATL_UCD_SC_OGAM,

    /** '**Olck**', '**Ol_Chiki**' */ 
    COATL_UCD_SC_OLCK=100,
        /** Alias for #COATL_UCD_SC_OLCK */
        COATL_UCD_SC_OL_CHIKI=COATL_UCD_SC_OLCK,

    /** '**Orkh**', '**Old_Turkic**' */ 
    COATL_UCD_SC_ORKH=101,
        /** Alias for #COATL_UCD_SC_ORKH */
        COATL_UCD_SC_OLD_TURKIC=COATL_UCD_SC_ORKH,

    /** '**Orya**', '**Oriya**' */ 
    COATL_UCD_SC_ORYA=102,
        /** Alias for #COATL_UCD_SC_ORYA */
        COATL_UCD_SC_ORIYA=COATL_UCD_SC_ORYA,

    /** '**Osge**', '**Osage**' */ 
    COATL_UCD_SC_OSGE=103,
        /** Alias for #COATL_UCD_SC_OSGE */
        COATL_UCD_SC_OSAGE=COATL_UCD_SC_OSGE,

    /** '**Osma**', '**Osmanya**' */ 
    COATL_UCD_SC_OSMA=104,
        /** Alias for #COATL_UCD_SC_OSMA */
        COATL_UCD_SC_OSMANYA=COATL_UCD_SC_OSMA,

    /** '**Palm**', '**Palmyrene**' */ 
    COATL_UCD_SC_PALM=105,
        /** Alias for #COATL_UCD_SC_PALM */
        COATL_UCD_SC_PALMYRENE=COATL_UCD_SC_PALM,

    /** '**Pauc**', '**Pau_Cin_Hau**' */ 
    COATL_UCD_SC_PAUC=106,
        /** Alias for #COATL_UCD_SC_PAUC */
        COATL_UCD_SC_PAU_CIN_HAU=COATL_UCD_SC_PAUC,

    /** '**Perm**', '**Old_Permic**' */ 
    COATL_UCD_SC_PERM=107,
        /** Alias for #COATL_UCD_SC_PERM */
        COATL_UCD_SC_OLD_PERMIC=COATL_UCD_SC_PERM,

    /** '**Phag**', '**Phags_Pa**' */ 
    COATL_UCD_SC_PHAG=108,
        /** Alias for #COATL_UCD_SC_PHAG */
        COATL_UCD_SC_PHAGS_PA=COATL_UCD_SC_PHAG,

    /** '**Phli**', '**Inscriptional_Pahlavi**' */ 
    COATL_UCD_SC_PHLI=109,
        /** Alias for #COATL_UCD_SC_PHLI */
        COATL_UCD_SC_INSCRIPTIONAL_PAHLAVI=COATL_UCD_SC_PHLI,

    /** '**Phlp**', '**Psalter_Pahlavi**' */ 
    COATL_UCD_SC_PHLP=110,
        /** Alias for #COATL_UCD_SC_PHLP */
        COATL_UCD_SC_PSALTER_PAHLAVI=COATL_UCD_SC_PHLP,

    /** '**Phnx**', '**Phoenician**' */ 
    COATL_UCD_SC_PHNX=111,
        /** Alias for #COATL_UCD_SC_PHNX */
        COATL_UCD_SC_PHOENICIAN=COATL_UCD_SC_PHNX,

    /** '**Plrd**', '**Miao**' */ 
    COATL_UCD_SC_PLRD=112,
        /** Alias for #COATL_UCD_SC_PLRD */
        COATL_UCD_SC_MIAO=COATL_UCD_SC_PLRD,

    /** '**Prti**', '**Inscriptional_Parthian**' */ 
    COATL_UCD_SC_PRTI=113,
        /** Alias for #COATL_UCD_SC_PRTI */
        COATL_UCD_SC_INSCRIPTIONAL_PARTHIAN=COATL_UCD_SC_PRTI,

    /** '**Rjng**', '**Rejang**' */ 
    COATL_UCD_SC_RJNG=114,
        /** Alias for #COATL_UCD_SC_RJNG */
        COATL_UCD_SC_REJANG=COATL_UCD_SC_RJNG,

    /** '**Rohg**', '**Hanifi_Rohingya**' */ 
    COATL_UCD_SC_ROHG=115,
        /** Alias for #COATL_UCD_SC_ROHG */
        COATL_UCD_SC_HANIFI_ROHINGYA=COATL_UCD_SC_ROHG,

    /** '**Runr**', '**Runic**' */ 
    COATL_UCD_SC_RUNR=116,
        /** Alias for #COATL_UCD_SC_RUNR */
        COATL_UCD_SC_RUNIC=COATL_UCD_SC_RUNR,

    /** '**Samr**', '**Samaritan**' */ 
    COATL_UCD_SC_SAMR=117,
        /** Alias for #COATL_UCD_SC_SAMR */
        COATL_UCD_SC_SAMARITAN=COATL_UCD_SC_SAMR,

    /** '**Sarb**', '**Old_South_Arabian**' */ 
    COATL_UCD_SC_SARB=118,
        /** Alias for #COATL_UCD_SC_SARB */
        COATL_UCD_SC_OLD_SOUTH_ARABIAN=COATL_UCD_SC_SARB,

    /** '**Saur**', '**Saurashtra**' */ 
    COATL_UCD_SC_SAUR=119,
        /** Alias for #COATL_UCD_SC_SAUR */
        COATL_UCD_SC_SAURASHTRA=COATL_UCD_SC_SAUR,

    /** '**Sgnw**', '**SignWriting**' */ 
    COATL_UCD_SC_SGNW=120,
        /** Alias for #COATL_UCD_SC_SGNW */
        COATL_UCD_SC_SIGNWRITING=COATL_UCD_SC_SGNW,

    /** '**Shaw**', '**Shavian**' */ 
    COATL_UCD_SC_SHAW=121,
        /** Alias for #COATL_UCD_SC_SHAW */
        COATL_UCD_SC_SHAVIAN=COATL_UCD_SC_SHAW,

    /** '**Shrd**', '**Sharada**' */ 
    COATL_UCD_SC_SHRD=122,
        /** Alias for #COATL_UCD_SC_SHRD */
        COATL_UCD_SC_SHARADA=COATL_UCD_SC_SHRD,

    /** '**Sidd**', '**Siddham**' */ 
    COATL_UCD_SC_SIDD=123,
        /** Alias for #COATL_UCD_SC_SIDD */
        COATL_UCD_SC_SIDDHAM=COATL_UCD_SC_SIDD,

    /** '**Sind**', '**Khudawadi**' */ 
    COATL_UCD_SC_SIND=124,
        /** Alias for #COATL_UCD_SC_SIND */
        COATL_UCD_SC_KHUDAWADI=COATL_UCD_SC_SIND,

    /** '**Sinh**', '**Sinhala**' */ 
    COATL_UCD_SC_SINH=125,
        /** Alias for #COATL_UCD_SC_SINH */
        COATL_UCD_SC_SINHALA=COATL_UCD_SC_SINH,

    /** '**Sogd**', '**Sogdian**' */ 
    COATL_UCD_SC_SOGD=126,
        /** Alias for #COATL_UCD_SC_SOGD */
        COATL_UCD_SC_SOGDIAN=COATL_UCD_SC_SOGD,

    /** '**Sogo**', '**Old_Sogdian**' */ 
    COATL_UCD_SC_SOGO=127,
        /** Alias for #COATL_UCD_SC_SOGO */
        COATL_UCD_SC_OLD_SOGDIAN=COATL_UCD_SC_SOGO,

    /** '**Sora**', '**Sora_Sompeng**' */ 
    COATL_UCD_SC_SORA=128,
        /** Alias for #COATL_UCD_SC_SORA */
        COATL_UCD_SC_SORA_SOMPENG=COATL_UCD_SC_SORA,

    /** '**Soyo**', '**Soyombo**' */ 
    COATL_UCD_SC_SOYO=129,
        /** Alias for #COATL_UCD_SC_SOYO */
        COATL_UCD_SC_SOYOMBO=COATL_UCD_SC_SOYO,

    /** '**Sund**', '**Sundanese**' */ 
    COATL_UCD_SC_SUND=130,
        /** Alias for #COATL_UCD_SC_SUND */
        COATL_UCD_SC_SUNDANESE=COATL_UCD_SC_SUND,

    /** '**Sylo**', '**Syloti_Nagri**' */ 
    COATL_UCD_SC_SYLO=131,
        /** Alias for #COATL_UCD_SC_SYLO */
        COATL_UCD_SC_SYLOTI_NAGRI=COATL_UCD_SC_SYLO,

    /** '**Syrc**', '**Syriac**' */ 
    COATL_UCD_SC_SYRC=132,
        /** Alias for #COATL_UCD_SC_SYRC */
        COATL_UCD_SC_SYRIAC=COATL_UCD_SC_SYRC,

    /** '**Tagb**', '**Tagbanwa**' */ 
    COATL_UCD_SC_TAGB=133,
        /** Alias for #COATL_UCD_SC_TAGB */
        COATL_UCD_SC_TAGBANWA=COATL_UCD_SC_TAGB,

    /** '**Takr**', '**Takri**' */ 
    COATL_UCD_SC_TAKR=134,
        /** Alias for #COATL_UCD_SC_TAKR */
        COATL_UCD_SC_TAKRI=COATL_UCD_SC_TAKR,

    /** '**Tale**', '**Tai_Le**' */ 
    COATL_UCD_SC_TALE=135,
        /** Alias for #COATL_UCD_SC_TALE */
        COATL_UCD_SC_TAI_LE=COATL_UCD_SC_TALE,

    /** '**Talu**', '**New_Tai_Lue**' */ 
    COATL_UCD_SC_TALU=136,
        /** Alias for #COATL_UCD_SC_TALU */
        COATL_UCD_SC_NEW_TAI_LUE=COATL_UCD_SC_TALU,

    /** '**Taml**', '**Tamil**' */ 
    COATL_UCD_SC_TAML=137,
        /** Alias for #COATL_UCD_SC_TAML */
        COATL_UCD_SC_TAMIL=COATL_UCD_SC_TAML,

    /** '**Tang**', '**Tangut**' */ 
    COATL_UCD_SC_TANG=138,
        /** Alias for #COATL_UCD_SC_TANG */
        COATL_UCD_SC_TANGUT=COATL_UCD_SC_TANG,

    /** '**Tavt**', '**Tai_Viet**' */ 
    COATL_UCD_SC_TAVT=139,
        /** Alias for #COATL_UCD_SC_TAVT */
        COATL_UCD_SC_TAI_VIET=COATL_UCD_SC_TAVT,

    /** '**Telu**', '**Telugu**' */ 
    COATL_UCD_SC_TELU=140,
        /** Alias for #COATL_UCD_SC_TELU */
        COATL_UCD_SC_TELUGU=COATL_UCD_SC_TELU,

    /** '**Tfng**', '**Tifinagh**' */ 
    COATL_UCD_SC_TFNG=141,
        /** Alias for #COATL_UCD_SC_TFNG */
        COATL_UCD_SC_TIFINAGH=COATL_UCD_SC_TFNG,

    /** '**Tglg**', '**Tagalog**' */ 
    COATL_UCD_SC_TGLG=142,
        /** Alias for #COATL_UCD_SC_TGLG */
        COATL_UCD_SC_TAGALOG=COATL_UCD_SC_TGLG,

    /** '**Thaa**', '**Thaana**' */ 
    COATL_UCD_SC_THAA=143,
        /** Alias for #COATL_UCD_SC_THAA */
        COATL_UCD_SC_THAANA=COATL_UCD_SC_THAA,

    /** '**Thai**' */ 
    COATL_UCD_SC_THAI=144,

    /** '**Tibt**', '**Tibetan**' */ 
    COATL_UCD_SC_TIBT=145,
        /** Alias for #COATL_UCD_SC_TIBT */
        COATL_UCD_SC_TIBETAN=COATL_UCD_SC_TIBT,

    /** '**Tirh**', '**Tirhuta**' */ 
    COATL_UCD_SC_TIRH=146,
        /** Alias for #COATL_UCD_SC_TIRH */
        COATL_UCD_SC_TIRHUTA=COATL_UCD_SC_TIRH,

    /** '**Ugar**', '**Ugaritic**' */ 
    COATL_UCD_SC_UGAR=147,
        /** Alias for #COATL_UCD_SC_UGAR */
        COATL_UCD_SC_UGARITIC=COATL_UCD_SC_UGAR,

    /** '**Vaii**', '**Vai**' */ 
    COATL_UCD_SC_VAII=148,
        /** Alias for #COATL_UCD_SC_VAII */
        COATL_UCD_SC_VAI=COATL_UCD_SC_VAII,

    /** '**Wara**', '**Warang_Citi**' */ 
    COATL_UCD_SC_WARA=149,
        /** Alias for #COATL_UCD_SC_WARA */
        COATL_UCD_SC_WARANG_CITI=COATL_UCD_SC_WARA,

    /** '**Wcho**', '**Wancho**' */ 
    COATL_UCD_SC_WCHO=150,
        /** Alias for #COATL_UCD_SC_WCHO */
        COATL_UCD_SC_WANCHO=COATL_UCD_SC_WCHO,

    /** '**Xpeo**', '**Old_Persian**' */ 
    COATL_UCD_SC_XPEO=151,
        /** Alias for #COATL_UCD_SC_XPEO */
        COATL_UCD_SC_OLD_PERSIAN=COATL_UCD_SC_XPEO,

    /** '**Xsux**', '**Cuneiform**' */ 
    COATL_UCD_SC_XSUX=152,
        /** Alias for #COATL_UCD_SC_XSUX */
        COATL_UCD_SC_CUNEIFORM=COATL_UCD_SC_XSUX,

    /** '**Yezi**', '**Yezidi**' */ 
    COATL_UCD_SC_YEZI=153,
        /** Alias for #COATL_UCD_SC_YEZI */
        COATL_UCD_SC_YEZIDI=COATL_UCD_SC_YEZI,

    /** '**Yiii**', '**Yi**' */ 
    COATL_UCD_SC_YIII=154,
        /** Alias for #COATL_UCD_SC_YIII */
        COATL_UCD_SC_YI=COATL_UCD_SC_YIII,

    /** '**Zanb**', '**Zanabazar_Square**' */ 
    COATL_UCD_SC_ZANB=155,
        /** Alias for #COATL_UCD_SC_ZANB */
        COATL_UCD_SC_ZANABAZAR_SQUARE=COATL_UCD_SC_ZANB,

    /** '**Zinh**', '**Inherited**', '**Qaai**' */ 
    COATL_UCD_SC_ZINH=156,
        /** Alias for #COATL_UCD_SC_ZINH */
        COATL_UCD_SC_INHERITED=COATL_UCD_SC_ZINH,
        /** Alias for #COATL_UCD_SC_ZINH */
        COATL_UCD_SC_QAAI=COATL_UCD_SC_ZINH,

    /** '**Zyyy**', '**Common**' */ 
    COATL_UCD_SC_ZYYY=157,
        /** Alias for #COATL_UCD_SC_ZYYY */
        COATL_UCD_SC_COMMON=COATL_UCD_SC_ZYYY,

    /** '**Zzzz**', '**Unknown**' */ 
    COATL_UCD_SC_ZZZZ=158,
        /** Alias for #COATL_UCD_SC_ZZZZ */
        COATL_UCD_SC_UNKNOWN=COATL_UCD_SC_ZZZZ,
} Coatl_Ucd_Sc;

/**
 * Number of values for Unicode character property '*sc*'.
 *
 * @see Coatl_Ucd_Sc
 */
#define COATL_UCD_SC_NBVALUES        158

/**
 * Values for Unicode character property '**bc**'.
 *
 * Names are automatically generated from the UCD file 
 * `PropertyValueAliases.txt`.
 *
 * @see COATL_UCD_BC
 */
typedef enum Coatl_Ucd_Bc {
    /** '**AL**', '**Arabic_Letter**' */ 
    COATL_UCD_BC_AL=1,
        /** Alias for #COATL_UCD_BC_AL */
        COATL_UCD_BC_ARABIC_LETTER=COATL_UCD_BC_AL,

    /** '**AN**', '**Arabic_Number**' */ 
    COATL_UCD_BC_AN=2,
        /** Alias for #COATL_UCD_BC_AN */
        COATL_UCD_BC_ARABIC_NUMBER=COATL_UCD_BC_AN,

    /** '**B**', '**Paragraph_Separator**' */ 
    COATL_UCD_BC_B=3,
        /** Alias for #COATL_UCD_BC_B */
        COATL_UCD_BC_PARAGRAPH_SEPARATOR=COATL_UCD_BC_B,

    /** '**BN**', '**Boundary_Neutral**' */ 
    COATL_UCD_BC_BN=4,
        /** Alias for #COATL_UCD_BC_BN */
        COATL_UCD_BC_BOUNDARY_NEUTRAL=COATL_UCD_BC_BN,

    /** '**CS**', '**Common_Separator**' */ 
    COATL_UCD_BC_CS=5,
        /** Alias for #COATL_UCD_BC_CS */
        COATL_UCD_BC_COMMON_SEPARATOR=COATL_UCD_BC_CS,

    /** '**EN**', '**European_Number**' */ 
    COATL_UCD_BC_EN=6,
        /** Alias for #COATL_UCD_BC_EN */
        COATL_UCD_BC_EUROPEAN_NUMBER=COATL_UCD_BC_EN,

    /** '**ES**', '**European_Separator**' */ 
    COATL_UCD_BC_ES=7,
        /** Alias for #COATL_UCD_BC_ES */
        COATL_UCD_BC_EUROPEAN_SEPARATOR=COATL_UCD_BC_ES,

    /** '**ET**', '**European_Terminator**' */ 
    COATL_UCD_BC_ET=8,
        /** Alias for #COATL_UCD_BC_ET */
        COATL_UCD_BC_EUROPEAN_TERMINATOR=COATL_UCD_BC_ET,

    /** '**FSI**', '**First_Strong_Isolate**' */ 
    COATL_UCD_BC_FSI=9,
        /** Alias for #COATL_UCD_BC_FSI */
        COATL_UCD_BC_FIRST_STRONG_ISOLATE=COATL_UCD_BC_FSI,

    /** '**L**', '**Left_To_Right**' */ 
    COATL_UCD_BC_L=10,
        /** Alias for #COATL_UCD_BC_L */
        COATL_UCD_BC_LEFT_TO_RIGHT=COATL_UCD_BC_L,

    /** '**LRE**', '**Left_To_Right_Embedding**' */ 
    COATL_UCD_BC_LRE=11,
        /** Alias for #COATL_UCD_BC_LRE */
        COATL_UCD_BC_LEFT_TO_RIGHT_EMBEDDING=COATL_UCD_BC_LRE,

    /** '**LRI**', '**Left_To_Right_Isolate**' */ 
    COATL_UCD_BC_LRI=12,
        /** Alias for #COATL_UCD_BC_LRI */
        COATL_UCD_BC_LEFT_TO_RIGHT_ISOLATE=COATL_UCD_BC_LRI,

    /** '**LRO**', '**Left_To_Right_Override**' */ 
    COATL_UCD_BC_LRO=13,
        /** Alias for #COATL_UCD_BC_LRO */
        COATL_UCD_BC_LEFT_TO_RIGHT_OVERRIDE=COATL_UCD_BC_LRO,

    /** '**NSM**', '**Nonspacing_Mark**' */ 
    COATL_UCD_BC_NSM=14,
        /** Alias for #COATL_UCD_BC_NSM */
        COATL_UCD_BC_NONSPACING_MARK=COATL_UCD_BC_NSM,

    /** '**ON**', '**Other_Neutral**' */ 
    COATL_UCD_BC_ON=15,
        /** Alias for #COATL_UCD_BC_ON */
        COATL_UCD_BC_OTHER_NEUTRAL=COATL_UCD_BC_ON,

    /** '**PDF**', '**Pop_Directional_Format**' */ 
    COATL_UCD_BC_PDF=16,
        /** Alias for #COATL_UCD_BC_PDF */
        COATL_UCD_BC_POP_DIRECTIONAL_FORMAT=COATL_UCD_BC_PDF,

    /** '**PDI**', '**Pop_Directional_Isolate**' */ 
    COATL_UCD_BC_PDI=17,
        /** Alias for #COATL_UCD_BC_PDI */
        COATL_UCD_BC_POP_DIRECTIONAL_ISOLATE=COATL_UCD_BC_PDI,

    /** '**R**', '**Right_To_Left**' */ 
    COATL_UCD_BC_R=18,
        /** Alias for #COATL_UCD_BC_R */
        COATL_UCD_BC_RIGHT_TO_LEFT=COATL_UCD_BC_R,

    /** '**RLE**', '**Right_To_Left_Embedding**' */ 
    COATL_UCD_BC_RLE=19,
        /** Alias for #COATL_UCD_BC_RLE */
        COATL_UCD_BC_RIGHT_TO_LEFT_EMBEDDING=COATL_UCD_BC_RLE,

    /** '**RLI**', '**Right_To_Left_Isolate**' */ 
    COATL_UCD_BC_RLI=20,
        /** Alias for #COATL_UCD_BC_RLI */
        COATL_UCD_BC_RIGHT_TO_LEFT_ISOLATE=COATL_UCD_BC_RLI,

    /** '**RLO**', '**Right_To_Left_Override**' */ 
    COATL_UCD_BC_RLO=21,
        /** Alias for #COATL_UCD_BC_RLO */
        COATL_UCD_BC_RIGHT_TO_LEFT_OVERRIDE=COATL_UCD_BC_RLO,

    /** '**S**', '**Segment_Separator**' */ 
    COATL_UCD_BC_S=22,
        /** Alias for #COATL_UCD_BC_S */
        COATL_UCD_BC_SEGMENT_SEPARATOR=COATL_UCD_BC_S,

    /** '**WS**', '**White_Space**' */ 
    COATL_UCD_BC_WS=23,
        /** Alias for #COATL_UCD_BC_WS */
        COATL_UCD_BC_WHITE_SPACE=COATL_UCD_BC_WS,
} Coatl_Ucd_Bc;

/**
 * Number of values for Unicode character property '*bc*'.
 *
 * @see Coatl_Ucd_Bc
 */
#define COATL_UCD_BC_NBVALUES        23

/**
 * Values for Unicode character property '**bpt**'.
 *
 * Names are automatically generated from the UCD file 
 * `PropertyValueAliases.txt`.
 *
 * @see COATL_UCD_BPT
 */
typedef enum Coatl_Ucd_Bpt {
    /** '**c**', '**Close**' */ 
    COATL_UCD_BPT_C=1,
        /** Alias for #COATL_UCD_BPT_C */
        COATL_UCD_BPT_CLOSE=COATL_UCD_BPT_C,

    /** '**n**', '**None**' */ 
    COATL_UCD_BPT_N=2,
        /** Alias for #COATL_UCD_BPT_N */
        COATL_UCD_BPT_NONE=COATL_UCD_BPT_N,

    /** '**o**', '**Open**' */ 
    COATL_UCD_BPT_O=3,
        /** Alias for #COATL_UCD_BPT_O */
        COATL_UCD_BPT_OPEN=COATL_UCD_BPT_O,
} Coatl_Ucd_Bpt;

/**
 * Number of values for Unicode character property '*bpt*'.
 *
 * @see Coatl_Ucd_Bpt
 */
#define COATL_UCD_BPT_NBVALUES       3

/**
 * Values for Unicode character property '**ccc**'.
 *
 * Names are automatically generated from the UCD file 
 * `PropertyValueAliases.txt`.
 *
 * @see COATL_UCD_CCC
 */
typedef enum Coatl_Ucd_Ccc {
    /** '**0**', '**NR**', '**Not_Reordered**' */ 
    COATL_UCD_CCC_0=1,
        /** Alias for #COATL_UCD_CCC_0 */
        COATL_UCD_CCC_NR=COATL_UCD_CCC_0,
        /** Alias for #COATL_UCD_CCC_0 */
        COATL_UCD_CCC_NOT_REORDERED=COATL_UCD_CCC_0,

    /** '**1**', '**OV**', '**Overlay**' */ 
    COATL_UCD_CCC_1=2,
        /** Alias for #COATL_UCD_CCC_1 */
        COATL_UCD_CCC_OV=COATL_UCD_CCC_1,
        /** Alias for #COATL_UCD_CCC_1 */
        COATL_UCD_CCC_OVERLAY=COATL_UCD_CCC_1,

    /** '**6**', '**HANR**', '**Han_Reading**' */ 
    COATL_UCD_CCC_6=3,
        /** Alias for #COATL_UCD_CCC_6 */
        COATL_UCD_CCC_HANR=COATL_UCD_CCC_6,
        /** Alias for #COATL_UCD_CCC_6 */
        COATL_UCD_CCC_HAN_READING=COATL_UCD_CCC_6,

    /** '**7**', '**NK**', '**Nukta**' */ 
    COATL_UCD_CCC_7=4,
        /** Alias for #COATL_UCD_CCC_7 */
        COATL_UCD_CCC_NK=COATL_UCD_CCC_7,
        /** Alias for #COATL_UCD_CCC_7 */
        COATL_UCD_CCC_NUKTA=COATL_UCD_CCC_7,

    /** '**8**', '**KV**', '**Kana_Voicing**' */ 
    COATL_UCD_CCC_8=5,
        /** Alias for #COATL_UCD_CCC_8 */
        COATL_UCD_CCC_KV=COATL_UCD_CCC_8,
        /** Alias for #COATL_UCD_CCC_8 */
        COATL_UCD_CCC_KANA_VOICING=COATL_UCD_CCC_8,

    /** '**9**', '**VR**', '**Virama**' */ 
    COATL_UCD_CCC_9=6,
        /** Alias for #COATL_UCD_CCC_9 */
        COATL_UCD_CCC_VR=COATL_UCD_CCC_9,
        /** Alias for #COATL_UCD_CCC_9 */
        COATL_UCD_CCC_VIRAMA=COATL_UCD_CCC_9,

    /** '**10**', '**CCC10**' */ 
    COATL_UCD_CCC_10=7,
        /** Alias for #COATL_UCD_CCC_10 */
        COATL_UCD_CCC_CCC10=COATL_UCD_CCC_10,

    /** '**11**', '**CCC11**' */ 
    COATL_UCD_CCC_11=8,
        /** Alias for #COATL_UCD_CCC_11 */
        COATL_UCD_CCC_CCC11=COATL_UCD_CCC_11,

    /** '**12**', '**CCC12**' */ 
    COATL_UCD_CCC_12=9,
        /** Alias for #COATL_UCD_CCC_12 */
        COATL_UCD_CCC_CCC12=COATL_UCD_CCC_12,

    /** '**13**', '**CCC13**' */ 
    COATL_UCD_CCC_13=10,
        /** Alias for #COATL_UCD_CCC_13 */
        COATL_UCD_CCC_CCC13=COATL_UCD_CCC_13,

    /** '**14**', '**CCC14**' */ 
    COATL_UCD_CCC_14=11,
        /** Alias for #COATL_UCD_CCC_14 */
        COATL_UCD_CCC_CCC14=COATL_UCD_CCC_14,

    /** '**15**', '**CCC15**' */ 
    COATL_UCD_CCC_15=12,
        /** Alias for #COATL_UCD_CCC_15 */
        COATL_UCD_CCC_CCC15=COATL_UCD_CCC_15,

    /** '**16**', '**CCC16**' */ 
    COATL_UCD_CCC_16=13,
        /** Alias for #COATL_UCD_CCC_16 */
        COATL_UCD_CCC_CCC16=COATL_UCD_CCC_16,

    /** '**17**', '**CCC17**' */ 
    COATL_UCD_CCC_17=14,
        /** Alias for #COATL_UCD_CCC_17 */
        COATL_UCD_CCC_CCC17=COATL_UCD_CCC_17,

    /** '**18**', '**CCC18**' */ 
    COATL_UCD_CCC_18=15,
        /** Alias for #COATL_UCD_CCC_18 */
        COATL_UCD_CCC_CCC18=COATL_UCD_CCC_18,

    /** '**19**', '**CCC19**' */ 
    COATL_UCD_CCC_19=16,
        /** Alias for #COATL_UCD_CCC_19 */
        COATL_UCD_CCC_CCC19=COATL_UCD_CCC_19,

    /** '**20**', '**CCC20**' */ 
    COATL_UCD_CCC_20=17,
        /** Alias for #COATL_UCD_CCC_20 */
        COATL_UCD_CCC_CCC20=COATL_UCD_CCC_20,

    /** '**21**', '**CCC21**' */ 
    COATL_UCD_CCC_21=18,
        /** Alias for #COATL_UCD_CCC_21 */
        COATL_UCD_CCC_CCC21=COATL_UCD_CCC_21,

    /** '**22**', '**CCC22**' */ 
    COATL_UCD_CCC_22=19,
        /** Alias for #COATL_UCD_CCC_22 */
        COATL_UCD_CCC_CCC22=COATL_UCD_CCC_22,

    /** '**23**', '**CCC23**' */ 
    COATL_UCD_CCC_23=20,
        /** Alias for #COATL_UCD_CCC_23 */
        COATL_UCD_CCC_CCC23=COATL_UCD_CCC_23,

    /** '**24**', '**CCC24**' */ 
    COATL_UCD_CCC_24=21,
        /** Alias for #COATL_UCD_CCC_24 */
        COATL_UCD_CCC_CCC24=COATL_UCD_CCC_24,

    /** '**25**', '**CCC25**' */ 
    COATL_UCD_CCC_25=22,
        /** Alias for #COATL_UCD_CCC_25 */
        COATL_UCD_CCC_CCC25=COATL_UCD_CCC_25,

    /** '**26**', '**CCC26**' */ 
    COATL_UCD_CCC_26=23,
        /** Alias for #COATL_UCD_CCC_26 */
        COATL_UCD_CCC_CCC26=COATL_UCD_CCC_26,

    /** '**27**', '**CCC27**' */ 
    COATL_UCD_CCC_27=24,
        /** Alias for #COATL_UCD_CCC_27 */
        COATL_UCD_CCC_CCC27=COATL_UCD_CCC_27,

    /** '**28**', '**CCC28**' */ 
    COATL_UCD_CCC_28=25,
        /** Alias for #COATL_UCD_CCC_28 */
        COATL_UCD_CCC_CCC28=COATL_UCD_CCC_28,

    /** '**29**', '**CCC29**' */ 
    COATL_UCD_CCC_29=26,
        /** Alias for #COATL_UCD_CCC_29 */
        COATL_UCD_CCC_CCC29=COATL_UCD_CCC_29,

    /** '**30**', '**CCC30**' */ 
    COATL_UCD_CCC_30=27,
        /** Alias for #COATL_UCD_CCC_30 */
        COATL_UCD_CCC_CCC30=COATL_UCD_CCC_30,

    /** '**31**', '**CCC31**' */ 
    COATL_UCD_CCC_31=28,
        /** Alias for #COATL_UCD_CCC_31 */
        COATL_UCD_CCC_CCC31=COATL_UCD_CCC_31,

    /** '**32**', '**CCC32**' */ 
    COATL_UCD_CCC_32=29,
        /** Alias for #COATL_UCD_CCC_32 */
        COATL_UCD_CCC_CCC32=COATL_UCD_CCC_32,

    /** '**33**', '**CCC33**' */ 
    COATL_UCD_CCC_33=30,
        /** Alias for #COATL_UCD_CCC_33 */
        COATL_UCD_CCC_CCC33=COATL_UCD_CCC_33,

    /** '**34**', '**CCC34**' */ 
    COATL_UCD_CCC_34=31,
        /** Alias for #COATL_UCD_CCC_34 */
        COATL_UCD_CCC_CCC34=COATL_UCD_CCC_34,

    /** '**35**', '**CCC35**' */ 
    COATL_UCD_CCC_35=32,
        /** Alias for #COATL_UCD_CCC_35 */
        COATL_UCD_CCC_CCC35=COATL_UCD_CCC_35,

    /** '**36**', '**CCC36**' */ 
    COATL_UCD_CCC_36=33,
        /** Alias for #COATL_UCD_CCC_36 */
        COATL_UCD_CCC_CCC36=COATL_UCD_CCC_36,

    /** '**84**', '**CCC84**' */ 
    COATL_UCD_CCC_84=34,
        /** Alias for #COATL_UCD_CCC_84 */
        COATL_UCD_CCC_CCC84=COATL_UCD_CCC_84,

    /** '**91**', '**CCC91**' */ 
    COATL_UCD_CCC_91=35,
        /** Alias for #COATL_UCD_CCC_91 */
        COATL_UCD_CCC_CCC91=COATL_UCD_CCC_91,

    /** '**103**', '**CCC103**' */ 
    COATL_UCD_CCC_103=36,
        /** Alias for #COATL_UCD_CCC_103 */
        COATL_UCD_CCC_CCC103=COATL_UCD_CCC_103,

    /** '**107**', '**CCC107**' */ 
    COATL_UCD_CCC_107=37,
        /** Alias for #COATL_UCD_CCC_107 */
        COATL_UCD_CCC_CCC107=COATL_UCD_CCC_107,

    /** '**118**', '**CCC118**' */ 
    COATL_UCD_CCC_118=38,
        /** Alias for #COATL_UCD_CCC_118 */
        COATL_UCD_CCC_CCC118=COATL_UCD_CCC_118,

    /** '**122**', '**CCC122**' */ 
    COATL_UCD_CCC_122=39,
        /** Alias for #COATL_UCD_CCC_122 */
        COATL_UCD_CCC_CCC122=COATL_UCD_CCC_122,

    /** '**129**', '**CCC129**' */ 
    COATL_UCD_CCC_129=40,
        /** Alias for #COATL_UCD_CCC_129 */
        COATL_UCD_CCC_CCC129=COATL_UCD_CCC_129,

    /** '**130**', '**CCC130**' */ 
    COATL_UCD_CCC_130=41,
        /** Alias for #COATL_UCD_CCC_130 */
        COATL_UCD_CCC_CCC130=COATL_UCD_CCC_130,

    /** '**132**', '**CCC132**' */ 
    COATL_UCD_CCC_132=42,
        /** Alias for #COATL_UCD_CCC_132 */
        COATL_UCD_CCC_CCC132=COATL_UCD_CCC_132,

    /** '**133**', '**CCC133**' */ 
    COATL_UCD_CCC_133=43,
        /** Alias for #COATL_UCD_CCC_133 */
        COATL_UCD_CCC_CCC133=COATL_UCD_CCC_133,

    /** '**200**', '**ATBL**', '**Attached_Below_Left**' */ 
    COATL_UCD_CCC_200=44,
        /** Alias for #COATL_UCD_CCC_200 */
        COATL_UCD_CCC_ATBL=COATL_UCD_CCC_200,
        /** Alias for #COATL_UCD_CCC_200 */
        COATL_UCD_CCC_ATTACHED_BELOW_LEFT=COATL_UCD_CCC_200,

    /** '**202**', '**ATB**', '**Attached_Below**' */ 
    COATL_UCD_CCC_202=45,
        /** Alias for #COATL_UCD_CCC_202 */
        COATL_UCD_CCC_ATB=COATL_UCD_CCC_202,
        /** Alias for #COATL_UCD_CCC_202 */
        COATL_UCD_CCC_ATTACHED_BELOW=COATL_UCD_CCC_202,

    /** '**214**', '**ATA**', '**Attached_Above**' */ 
    COATL_UCD_CCC_214=46,
        /** Alias for #COATL_UCD_CCC_214 */
        COATL_UCD_CCC_ATA=COATL_UCD_CCC_214,
        /** Alias for #COATL_UCD_CCC_214 */
        COATL_UCD_CCC_ATTACHED_ABOVE=COATL_UCD_CCC_214,

    /** '**216**', '**ATAR**', '**Attached_Above_Right**' */ 
    COATL_UCD_CCC_216=47,
        /** Alias for #COATL_UCD_CCC_216 */
        COATL_UCD_CCC_ATAR=COATL_UCD_CCC_216,
        /** Alias for #COATL_UCD_CCC_216 */
        COATL_UCD_CCC_ATTACHED_ABOVE_RIGHT=COATL_UCD_CCC_216,

    /** '**218**', '**BL**', '**Below_Left**' */ 
    COATL_UCD_CCC_218=48,
        /** Alias for #COATL_UCD_CCC_218 */
        COATL_UCD_CCC_BL=COATL_UCD_CCC_218,
        /** Alias for #COATL_UCD_CCC_218 */
        COATL_UCD_CCC_BELOW_LEFT=COATL_UCD_CCC_218,

    /** '**220**', '**B**', '**Below**' */ 
    COATL_UCD_CCC_220=49,
        /** Alias for #COATL_UCD_CCC_220 */
        COATL_UCD_CCC_B=COATL_UCD_CCC_220,
        /** Alias for #COATL_UCD_CCC_220 */
        COATL_UCD_CCC_BELOW=COATL_UCD_CCC_220,

    /** '**222**', '**BR**', '**Below_Right**' */ 
    COATL_UCD_CCC_222=50,
        /** Alias for #COATL_UCD_CCC_222 */
        COATL_UCD_CCC_BR=COATL_UCD_CCC_222,
        /** Alias for #COATL_UCD_CCC_222 */
        COATL_UCD_CCC_BELOW_RIGHT=COATL_UCD_CCC_222,

    /** '**224**', '**L**', '**Left**' */ 
    COATL_UCD_CCC_224=51,
        /** Alias for #COATL_UCD_CCC_224 */
        COATL_UCD_CCC_L=COATL_UCD_CCC_224,
        /** Alias for #COATL_UCD_CCC_224 */
        COATL_UCD_CCC_LEFT=COATL_UCD_CCC_224,

    /** '**226**', '**R**', '**Right**' */ 
    COATL_UCD_CCC_226=52,
        /** Alias for #COATL_UCD_CCC_226 */
        COATL_UCD_CCC_R=COATL_UCD_CCC_226,
        /** Alias for #COATL_UCD_CCC_226 */
        COATL_UCD_CCC_RIGHT=COATL_UCD_CCC_226,

    /** '**228**', '**AL**', '**Above_Left**' */ 
    COATL_UCD_CCC_228=53,
        /** Alias for #COATL_UCD_CCC_228 */
        COATL_UCD_CCC_AL=COATL_UCD_CCC_228,
        /** Alias for #COATL_UCD_CCC_228 */
        COATL_UCD_CCC_ABOVE_LEFT=COATL_UCD_CCC_228,

    /** '**230**', '**A**', '**Above**' */ 
    COATL_UCD_CCC_230=54,
        /** Alias for #COATL_UCD_CCC_230 */
        COATL_UCD_CCC_A=COATL_UCD_CCC_230,
        /** Alias for #COATL_UCD_CCC_230 */
        COATL_UCD_CCC_ABOVE=COATL_UCD_CCC_230,

    /** '**232**', '**AR**', '**Above_Right**' */ 
    COATL_UCD_CCC_232=55,
        /** Alias for #COATL_UCD_CCC_232 */
        COATL_UCD_CCC_AR=COATL_UCD_CCC_232,
        /** Alias for #COATL_UCD_CCC_232 */
        COATL_UCD_CCC_ABOVE_RIGHT=COATL_UCD_CCC_232,

    /** '**233**', '**DB**', '**Double_Below**' */ 
    COATL_UCD_CCC_233=56,
        /** Alias for #COATL_UCD_CCC_233 */
        COATL_UCD_CCC_DB=COATL_UCD_CCC_233,
        /** Alias for #COATL_UCD_CCC_233 */
        COATL_UCD_CCC_DOUBLE_BELOW=COATL_UCD_CCC_233,

    /** '**234**', '**DA**', '**Double_Above**' */ 
    COATL_UCD_CCC_234=57,
        /** Alias for #COATL_UCD_CCC_234 */
        COATL_UCD_CCC_DA=COATL_UCD_CCC_234,
        /** Alias for #COATL_UCD_CCC_234 */
        COATL_UCD_CCC_DOUBLE_ABOVE=COATL_UCD_CCC_234,

    /** '**240**', '**IS**', '**Iota_Subscript**' */ 
    COATL_UCD_CCC_240=58,
        /** Alias for #COATL_UCD_CCC_240 */
        COATL_UCD_CCC_IS=COATL_UCD_CCC_240,
        /** Alias for #COATL_UCD_CCC_240 */
        COATL_UCD_CCC_IOTA_SUBSCRIPT=COATL_UCD_CCC_240,
} Coatl_Ucd_Ccc;

/**
 * Number of values for Unicode character property '*ccc*'.
 *
 * @see Coatl_Ucd_Ccc
 */
#define COATL_UCD_CCC_NBVALUES       58

/**
 * Values for Unicode character property '**dt**'.
 *
 * Names are automatically generated from the UCD file 
 * `PropertyValueAliases.txt`.
 *
 * @see COATL_UCD_DT
 */
typedef enum Coatl_Ucd_Dt {
    /** '**Can**', '**Canonical**', '**can**' */ 
    COATL_UCD_DT_CAN=1,
        /** Alias for #COATL_UCD_DT_CAN */
        COATL_UCD_DT_CANONICAL=COATL_UCD_DT_CAN,

    /** '**Com**', '**Compat**', '**com**' */ 
    COATL_UCD_DT_COM=2,
        /** Alias for #COATL_UCD_DT_COM */
        COATL_UCD_DT_COMPAT=COATL_UCD_DT_COM,

    /** '**Enc**', '**Circle**', '**enc**' */ 
    COATL_UCD_DT_ENC=3,
        /** Alias for #COATL_UCD_DT_ENC */
        COATL_UCD_DT_CIRCLE=COATL_UCD_DT_ENC,

    /** '**Fin**', '**Final**', '**fin**' */ 
    COATL_UCD_DT_FIN=4,
        /** Alias for #COATL_UCD_DT_FIN */
        COATL_UCD_DT_FINAL=COATL_UCD_DT_FIN,

    /** '**Font**', '**font**' */ 
    COATL_UCD_DT_FONT=5,

    /** '**Fra**', '**Fraction**', '**fra**' */ 
    COATL_UCD_DT_FRA=6,
        /** Alias for #COATL_UCD_DT_FRA */
        COATL_UCD_DT_FRACTION=COATL_UCD_DT_FRA,

    /** '**Init**', '**Initial**', '**init**' */ 
    COATL_UCD_DT_INIT=7,
        /** Alias for #COATL_UCD_DT_INIT */
        COATL_UCD_DT_INITIAL=COATL_UCD_DT_INIT,

    /** '**Iso**', '**Isolated**', '**iso**' */ 
    COATL_UCD_DT_ISO=8,
        /** Alias for #COATL_UCD_DT_ISO */
        COATL_UCD_DT_ISOLATED=COATL_UCD_DT_ISO,

    /** '**Med**', '**Medial**', '**med**' */ 
    COATL_UCD_DT_MED=9,
        /** Alias for #COATL_UCD_DT_MED */
        COATL_UCD_DT_MEDIAL=COATL_UCD_DT_MED,

    /** '**Nar**', '**Narrow**', '**nar**' */ 
    COATL_UCD_DT_NAR=10,
        /** Alias for #COATL_UCD_DT_NAR */
        COATL_UCD_DT_NARROW=COATL_UCD_DT_NAR,

    /** '**Nb**', '**Nobreak**', '**nb**' */ 
    COATL_UCD_DT_NB=11,
        /** Alias for #COATL_UCD_DT_NB */
        COATL_UCD_DT_NOBREAK=COATL_UCD_DT_NB,

    /** '**None**', '**none**' */ 
    COATL_UCD_DT_NONE=12,

    /** '**Sml**', '**Small**', '**sml**' */ 
    COATL_UCD_DT_SML=13,
        /** Alias for #COATL_UCD_DT_SML */
        COATL_UCD_DT_SMALL=COATL_UCD_DT_SML,

    /** '**Sqr**', '**Square**', '**sqr**' */ 
    COATL_UCD_DT_SQR=14,
        /** Alias for #COATL_UCD_DT_SQR */
        COATL_UCD_DT_SQUARE=COATL_UCD_DT_SQR,

    /** '**Sub**', '**sub**' */ 
    COATL_UCD_DT_SUB=15,

    /** '**Sup**', '**Super**', '**sup**' */ 
    COATL_UCD_DT_SUP=16,
        /** Alias for #COATL_UCD_DT_SUP */
        COATL_UCD_DT_SUPER=COATL_UCD_DT_SUP,

    /** '**Vert**', '**Vertical**', '**vert**' */ 
    COATL_UCD_DT_VERT=17,
        /** Alias for #COATL_UCD_DT_VERT */
        COATL_UCD_DT_VERTICAL=COATL_UCD_DT_VERT,

    /** '**Wide**', '**wide**' */ 
    COATL_UCD_DT_WIDE=18,
} Coatl_Ucd_Dt;

/**
 * Number of values for Unicode character property '*dt*'.
 *
 * @see Coatl_Ucd_Dt
 */
#define COATL_UCD_DT_NBVALUES        18

/**
 * Values for Unicode character property '**ea**'.
 *
 * Names are automatically generated from the UCD file 
 * `PropertyValueAliases.txt`.
 *
 * @see COATL_UCD_EA
 */
typedef enum Coatl_Ucd_Ea {
    /** '**A**', '**Ambiguous**' */ 
    COATL_UCD_EA_A=1,
        /** Alias for #COATL_UCD_EA_A */
        COATL_UCD_EA_AMBIGUOUS=COATL_UCD_EA_A,

    /** '**F**', '**Fullwidth**' */ 
    COATL_UCD_EA_F=2,
        /** Alias for #COATL_UCD_EA_F */
        COATL_UCD_EA_FULLWIDTH=COATL_UCD_EA_F,

    /** '**H**', '**Halfwidth**' */ 
    COATL_UCD_EA_H=3,
        /** Alias for #COATL_UCD_EA_H */
        COATL_UCD_EA_HALFWIDTH=COATL_UCD_EA_H,

    /** '**N**', '**Neutral**' */ 
    COATL_UCD_EA_N=4,
        /** Alias for #COATL_UCD_EA_N */
        COATL_UCD_EA_NEUTRAL=COATL_UCD_EA_N,

    /** '**Na**', '**Narrow**' */ 
    COATL_UCD_EA_NA=5,
        /** Alias for #COATL_UCD_EA_NA */
        COATL_UCD_EA_NARROW=COATL_UCD_EA_NA,

    /** '**W**', '**Wide**' */ 
    COATL_UCD_EA_W=6,
        /** Alias for #COATL_UCD_EA_W */
        COATL_UCD_EA_WIDE=COATL_UCD_EA_W,
} Coatl_Ucd_Ea;

/**
 * Number of values for Unicode character property '*ea*'.
 *
 * @see Coatl_Ucd_Ea
 */
#define COATL_UCD_EA_NBVALUES        6

/**
 * Values for Unicode character property '**gc**'.
 *
 * Names are automatically generated from the UCD file 
 * `PropertyValueAliases.txt`.
 *
 * @see COATL_UCD_GC
 */
typedef enum Coatl_Ucd_Gc {
    /** '**Cc**', '**Control**', '**cntrl**' */ 
    COATL_UCD_GC_CC=1,
        /** Alias for #COATL_UCD_GC_CC */
        COATL_UCD_GC_CONTROL=COATL_UCD_GC_CC,
        /** Alias for #COATL_UCD_GC_CC */
        COATL_UCD_GC_CNTRL=COATL_UCD_GC_CC,

    /** '**Cf**', '**Format**' */ 
    COATL_UCD_GC_CF=2,
        /** Alias for #COATL_UCD_GC_CF */
        COATL_UCD_GC_FORMAT=COATL_UCD_GC_CF,

    /** '**Cn**', '**Unassigned**' */ 
    COATL_UCD_GC_CN=3,
        /** Alias for #COATL_UCD_GC_CN */
        COATL_UCD_GC_UNASSIGNED=COATL_UCD_GC_CN,

    /** '**Co**', '**Private_Use**' */ 
    COATL_UCD_GC_CO=4,
        /** Alias for #COATL_UCD_GC_CO */
        COATL_UCD_GC_PRIVATE_USE=COATL_UCD_GC_CO,

    /** '**Cs**', '**Surrogate**' */ 
    COATL_UCD_GC_CS=5,
        /** Alias for #COATL_UCD_GC_CS */
        COATL_UCD_GC_SURROGATE=COATL_UCD_GC_CS,

    /** '**Ll**', '**Lowercase_Letter**' */ 
    COATL_UCD_GC_LL=6,
        /** Alias for #COATL_UCD_GC_LL */
        COATL_UCD_GC_LOWERCASE_LETTER=COATL_UCD_GC_LL,

    /** '**Lm**', '**Modifier_Letter**' */ 
    COATL_UCD_GC_LM=7,
        /** Alias for #COATL_UCD_GC_LM */
        COATL_UCD_GC_MODIFIER_LETTER=COATL_UCD_GC_LM,

    /** '**Lo**', '**Other_Letter**' */ 
    COATL_UCD_GC_LO=8,
        /** Alias for #COATL_UCD_GC_LO */
        COATL_UCD_GC_OTHER_LETTER=COATL_UCD_GC_LO,

    /** '**Lt**', '**Titlecase_Letter**' */ 
    COATL_UCD_GC_LT=9,
        /** Alias for #COATL_UCD_GC_LT */
        COATL_UCD_GC_TITLECASE_LETTER=COATL_UCD_GC_LT,

    /** '**Lu**', '**Uppercase_Letter**' */ 
    COATL_UCD_GC_LU=10,
        /** Alias for #COATL_UCD_GC_LU */
        COATL_UCD_GC_UPPERCASE_LETTER=COATL_UCD_GC_LU,

    /** '**Mc**', '**Spacing_Mark**' */ 
    COATL_UCD_GC_MC=11,
        /** Alias for #COATL_UCD_GC_MC */
        COATL_UCD_GC_SPACING_MARK=COATL_UCD_GC_MC,

    /** '**Me**', '**Enclosing_Mark**' */ 
    COATL_UCD_GC_ME=12,
        /** Alias for #COATL_UCD_GC_ME */
        COATL_UCD_GC_ENCLOSING_MARK=COATL_UCD_GC_ME,

    /** '**Mn**', '**Nonspacing_Mark**' */ 
    COATL_UCD_GC_MN=13,
        /** Alias for #COATL_UCD_GC_MN */
        COATL_UCD_GC_NONSPACING_MARK=COATL_UCD_GC_MN,

    /** '**Nd**', '**Decimal_Number**', '**digit**' */ 
    COATL_UCD_GC_ND=14,
        /** Alias for #COATL_UCD_GC_ND */
        COATL_UCD_GC_DECIMAL_NUMBER=COATL_UCD_GC_ND,
        /** Alias for #COATL_UCD_GC_ND */
        COATL_UCD_GC_DIGIT=COATL_UCD_GC_ND,

    /** '**Nl**', '**Letter_Number**' */ 
    COATL_UCD_GC_NL=15,
        /** Alias for #COATL_UCD_GC_NL */
        COATL_UCD_GC_LETTER_NUMBER=COATL_UCD_GC_NL,

    /** '**No**', '**Other_Number**' */ 
    COATL_UCD_GC_NO=16,
        /** Alias for #COATL_UCD_GC_NO */
        COATL_UCD_GC_OTHER_NUMBER=COATL_UCD_GC_NO,

    /** '**Pc**', '**Connector_Punctuation**' */ 
    COATL_UCD_GC_PC=17,
        /** Alias for #COATL_UCD_GC_PC */
        COATL_UCD_GC_CONNECTOR_PUNCTUATION=COATL_UCD_GC_PC,

    /** '**Pd**', '**Dash_Punctuation**' */ 
    COATL_UCD_GC_PD=18,
        /** Alias for #COATL_UCD_GC_PD */
        COATL_UCD_GC_DASH_PUNCTUATION=COATL_UCD_GC_PD,

    /** '**Pe**', '**Close_Punctuation**' */ 
    COATL_UCD_GC_PE=19,
        /** Alias for #COATL_UCD_GC_PE */
        COATL_UCD_GC_CLOSE_PUNCTUATION=COATL_UCD_GC_PE,

    /** '**Pf**', '**Final_Punctuation**' */ 
    COATL_UCD_GC_PF=20,
        /** Alias for #COATL_UCD_GC_PF */
        COATL_UCD_GC_FINAL_PUNCTUATION=COATL_UCD_GC_PF,

    /** '**Pi**', '**Initial_Punctuation**' */ 
    COATL_UCD_GC_PI=21,
        /** Alias for #COATL_UCD_GC_PI */
        COATL_UCD_GC_INITIAL_PUNCTUATION=COATL_UCD_GC_PI,

    /** '**Po**', '**Other_Punctuation**' */ 
    COATL_UCD_GC_PO=22,
        /** Alias for #COATL_UCD_GC_PO */
        COATL_UCD_GC_OTHER_PUNCTUATION=COATL_UCD_GC_PO,

    /** '**Ps**', '**Open_Punctuation**' */ 
    COATL_UCD_GC_PS=23,
        /** Alias for #COATL_UCD_GC_PS */
        COATL_UCD_GC_OPEN_PUNCTUATION=COATL_UCD_GC_PS,

    /** '**Sc**', '**Currency_Symbol**' */ 
    COATL_UCD_GC_SC=24,
        /** Alias for #COATL_UCD_GC_SC */
        COATL_UCD_GC_CURRENCY_SYMBOL=COATL_UCD_GC_SC,

    /** '**Sk**', '**Modifier_Symbol**' */ 
    COATL_UCD_GC_SK=25,
        /** Alias for #COATL_UCD_GC_SK */
        COATL_UCD_GC_MODIFIER_SYMBOL=COATL_UCD_GC_SK,

    /** '**Sm**', '**Math_Symbol**' */ 
    COATL_UCD_GC_SM=26,
        /** Alias for #COATL_UCD_GC_SM */
        COATL_UCD_GC_MATH_SYMBOL=COATL_UCD_GC_SM,

    /** '**So**', '**Other_Symbol**' */ 
    COATL_UCD_GC_SO=27,
        /** Alias for #COATL_UCD_GC_SO */
        COATL_UCD_GC_OTHER_SYMBOL=COATL_UCD_GC_SO,

    /** '**Zl**', '**Line_Separator**' */ 
    COATL_UCD_GC_ZL=28,
        /** Alias for #COATL_UCD_GC_ZL */
        COATL_UCD_GC_LINE_SEPARATOR=COATL_UCD_GC_ZL,

    /** '**Zp**', '**Paragraph_Separator**' */ 
    COATL_UCD_GC_ZP=29,
        /** Alias for #COATL_UCD_GC_ZP */
        COATL_UCD_GC_PARAGRAPH_SEPARATOR=COATL_UCD_GC_ZP,

    /** '**Zs**', '**Space_Separator**' */ 
    COATL_UCD_GC_ZS=30,
        /** Alias for #COATL_UCD_GC_ZS */
        COATL_UCD_GC_SPACE_SEPARATOR=COATL_UCD_GC_ZS,
} Coatl_Ucd_Gc;

/**
 * Number of values for Unicode character property '*gc*'.
 *
 * @see Coatl_Ucd_Gc
 */
#define COATL_UCD_GC_NBVALUES        30

/**
 * Values for Unicode character property '**GCB**'.
 *
 * Names are automatically generated from the UCD file 
 * `PropertyValueAliases.txt`.
 *
 * @see COATL_UCD_GCB
 */
typedef enum Coatl_Ucd_GCB {
    /** '**CN**', '**Control**' */ 
    COATL_UCD_GCB_CN=1,
        /** Alias for #COATL_UCD_GCB_CN */
        COATL_UCD_GCB_CONTROL=COATL_UCD_GCB_CN,

    /** '**CR**' */ 
    COATL_UCD_GCB_CR=2,

    /** '**EB**', '**E_Base**' */ 
    COATL_UCD_GCB_EB=3,
        /** Alias for #COATL_UCD_GCB_EB */
        COATL_UCD_GCB_E_BASE=COATL_UCD_GCB_EB,

    /** '**EBG**', '**E_Base_GAZ**' */ 
    COATL_UCD_GCB_EBG=4,
        /** Alias for #COATL_UCD_GCB_EBG */
        COATL_UCD_GCB_E_BASE_GAZ=COATL_UCD_GCB_EBG,

    /** '**EM**', '**E_Modifier**' */ 
    COATL_UCD_GCB_EM=5,
        /** Alias for #COATL_UCD_GCB_EM */
        COATL_UCD_GCB_E_MODIFIER=COATL_UCD_GCB_EM,

    /** '**EX**', '**Extend**' */ 
    COATL_UCD_GCB_EX=6,
        /** Alias for #COATL_UCD_GCB_EX */
        COATL_UCD_GCB_EXTEND=COATL_UCD_GCB_EX,

    /** '**GAZ**', '**Glue_After_Zwj**' */ 
    COATL_UCD_GCB_GAZ=7,
        /** Alias for #COATL_UCD_GCB_GAZ */
        COATL_UCD_GCB_GLUE_AFTER_ZWJ=COATL_UCD_GCB_GAZ,

    /** '**L**' */ 
    COATL_UCD_GCB_L=8,

    /** '**LF**' */ 
    COATL_UCD_GCB_LF=9,

    /** '**LV**' */ 
    COATL_UCD_GCB_LV=10,

    /** '**LVT**' */ 
    COATL_UCD_GCB_LVT=11,

    /** '**PP**', '**Prepend**' */ 
    COATL_UCD_GCB_PP=12,
        /** Alias for #COATL_UCD_GCB_PP */
        COATL_UCD_GCB_PREPEND=COATL_UCD_GCB_PP,

    /** '**RI**', '**Regional_Indicator**' */ 
    COATL_UCD_GCB_RI=13,
        /** Alias for #COATL_UCD_GCB_RI */
        COATL_UCD_GCB_REGIONAL_INDICATOR=COATL_UCD_GCB_RI,

    /** '**SM**', '**SpacingMark**' */ 
    COATL_UCD_GCB_SM=14,
        /** Alias for #COATL_UCD_GCB_SM */
        COATL_UCD_GCB_SPACINGMARK=COATL_UCD_GCB_SM,

    /** '**T**' */ 
    COATL_UCD_GCB_T=15,

    /** '**V**' */ 
    COATL_UCD_GCB_V=16,

    /** '**XX**', '**Other**' */ 
    COATL_UCD_GCB_XX=17,
        /** Alias for #COATL_UCD_GCB_XX */
        COATL_UCD_GCB_OTHER=COATL_UCD_GCB_XX,

    /** '**ZWJ**' */ 
    COATL_UCD_GCB_ZWJ=18,
} Coatl_Ucd_GCB;

/**
 * Number of values for Unicode character property '*GCB*'.
 *
 * @see Coatl_Ucd_GCB
 */
#define COATL_UCD_GCB_NBVALUES       18

/**
 * Values for Unicode character property '**hst**'.
 *
 * Names are automatically generated from the UCD file 
 * `PropertyValueAliases.txt`.
 *
 * @see COATL_UCD_HST
 */
typedef enum Coatl_Ucd_Hst {
    /** '**L**', '**Leading_Jamo**' */ 
    COATL_UCD_HST_L=1,
        /** Alias for #COATL_UCD_HST_L */
        COATL_UCD_HST_LEADING_JAMO=COATL_UCD_HST_L,

    /** '**LV**', '**LV_Syllable**' */ 
    COATL_UCD_HST_LV=2,
        /** Alias for #COATL_UCD_HST_LV */
        COATL_UCD_HST_LV_SYLLABLE=COATL_UCD_HST_LV,

    /** '**LVT**', '**LVT_Syllable**' */ 
    COATL_UCD_HST_LVT=3,
        /** Alias for #COATL_UCD_HST_LVT */
        COATL_UCD_HST_LVT_SYLLABLE=COATL_UCD_HST_LVT,

    /** '**NA**', '**Not_Applicable**' */ 
    COATL_UCD_HST_NA=4,
        /** Alias for #COATL_UCD_HST_NA */
        COATL_UCD_HST_NOT_APPLICABLE=COATL_UCD_HST_NA,

    /** '**T**', '**Trailing_Jamo**' */ 
    COATL_UCD_HST_T=5,
        /** Alias for #COATL_UCD_HST_T */
        COATL_UCD_HST_TRAILING_JAMO=COATL_UCD_HST_T,

    /** '**V**', '**Vowel_Jamo**' */ 
    COATL_UCD_HST_V=6,
        /** Alias for #COATL_UCD_HST_V */
        COATL_UCD_HST_VOWEL_JAMO=COATL_UCD_HST_V,
} Coatl_Ucd_Hst;

/**
 * Number of values for Unicode character property '*hst*'.
 *
 * @see Coatl_Ucd_Hst
 */
#define COATL_UCD_HST_NBVALUES       6

/**
 * Values for Unicode character property '**InPC**'.
 *
 * Names are automatically generated from the UCD file 
 * `PropertyValueAliases.txt`.
 *
 * @see COATL_UCD_INPC
 */
typedef enum Coatl_Ucd_InPC {
    /** '**Bottom**' */ 
    COATL_UCD_INPC_BOTTOM=1,

    /** '**Bottom_And_Left**' */ 
    COATL_UCD_INPC_BOTTOM_AND_LEFT=2,

    /** '**Bottom_And_Right**' */ 
    COATL_UCD_INPC_BOTTOM_AND_RIGHT=3,

    /** '**Left**' */ 
    COATL_UCD_INPC_LEFT=4,

    /** '**Left_And_Right**' */ 
    COATL_UCD_INPC_LEFT_AND_RIGHT=5,

    /** '**NA**' */ 
    COATL_UCD_INPC_NA=6,

    /** '**Overstruck**' */ 
    COATL_UCD_INPC_OVERSTRUCK=7,

    /** '**Right**' */ 
    COATL_UCD_INPC_RIGHT=8,

    /** '**Top**' */ 
    COATL_UCD_INPC_TOP=9,

    /** '**Top_And_Bottom**' */ 
    COATL_UCD_INPC_TOP_AND_BOTTOM=10,

    /** '**Top_And_Bottom_And_Left**' */ 
    COATL_UCD_INPC_TOP_AND_BOTTOM_AND_LEFT=11,

    /** '**Top_And_Bottom_And_Right**' */ 
    COATL_UCD_INPC_TOP_AND_BOTTOM_AND_RIGHT=12,

    /** '**Top_And_Left**' */ 
    COATL_UCD_INPC_TOP_AND_LEFT=13,

    /** '**Top_And_Left_And_Right**' */ 
    COATL_UCD_INPC_TOP_AND_LEFT_AND_RIGHT=14,

    /** '**Top_And_Right**' */ 
    COATL_UCD_INPC_TOP_AND_RIGHT=15,

    /** '**Visual_Order_Left**' */ 
    COATL_UCD_INPC_VISUAL_ORDER_LEFT=16,
} Coatl_Ucd_InPC;

/**
 * Number of values for Unicode character property '*InPC*'.
 *
 * @see Coatl_Ucd_InPC
 */
#define COATL_UCD_INPC_NBVALUES      16

/**
 * Values for Unicode character property '**InSC**'.
 *
 * Names are automatically generated from the UCD file 
 * `PropertyValueAliases.txt`.
 *
 * @see COATL_UCD_INSC
 */
typedef enum Coatl_Ucd_InSC {
    /** '**Avagraha**' */ 
    COATL_UCD_INSC_AVAGRAHA=1,

    /** '**Bindu**' */ 
    COATL_UCD_INSC_BINDU=2,

    /** '**Brahmi_Joining_Number**' */ 
    COATL_UCD_INSC_BRAHMI_JOINING_NUMBER=3,

    /** '**Cantillation_Mark**' */ 
    COATL_UCD_INSC_CANTILLATION_MARK=4,

    /** '**Consonant**' */ 
    COATL_UCD_INSC_CONSONANT=5,

    /** '**Consonant_Dead**' */ 
    COATL_UCD_INSC_CONSONANT_DEAD=6,

    /** '**Consonant_Final**' */ 
    COATL_UCD_INSC_CONSONANT_FINAL=7,

    /** '**Consonant_Head_Letter**' */ 
    COATL_UCD_INSC_CONSONANT_HEAD_LETTER=8,

    /** '**Consonant_Initial_Postfixed**' */ 
    COATL_UCD_INSC_CONSONANT_INITIAL_POSTFIXED=9,

    /** '**Consonant_Killer**' */ 
    COATL_UCD_INSC_CONSONANT_KILLER=10,

    /** '**Consonant_Medial**' */ 
    COATL_UCD_INSC_CONSONANT_MEDIAL=11,

    /** '**Consonant_Placeholder**' */ 
    COATL_UCD_INSC_CONSONANT_PLACEHOLDER=12,

    /** '**Consonant_Preceding_Repha**' */ 
    COATL_UCD_INSC_CONSONANT_PRECEDING_REPHA=13,

    /** '**Consonant_Prefixed**' */ 
    COATL_UCD_INSC_CONSONANT_PREFIXED=14,

    /** '**Consonant_Subjoined**' */ 
    COATL_UCD_INSC_CONSONANT_SUBJOINED=15,

    /** '**Consonant_Succeeding_Repha**' */ 
    COATL_UCD_INSC_CONSONANT_SUCCEEDING_REPHA=16,

    /** '**Consonant_With_Stacker**' */ 
    COATL_UCD_INSC_CONSONANT_WITH_STACKER=17,

    /** '**Gemination_Mark**' */ 
    COATL_UCD_INSC_GEMINATION_MARK=18,

    /** '**Invisible_Stacker**' */ 
    COATL_UCD_INSC_INVISIBLE_STACKER=19,

    /** '**Joiner**' */ 
    COATL_UCD_INSC_JOINER=20,

    /** '**Modifying_Letter**' */ 
    COATL_UCD_INSC_MODIFYING_LETTER=21,

    /** '**Non_Joiner**' */ 
    COATL_UCD_INSC_NON_JOINER=22,

    /** '**Nukta**' */ 
    COATL_UCD_INSC_NUKTA=23,

    /** '**Number**' */ 
    COATL_UCD_INSC_NUMBER=24,

    /** '**Number_Joiner**' */ 
    COATL_UCD_INSC_NUMBER_JOINER=25,

    /** '**Other**' */ 
    COATL_UCD_INSC_OTHER=26,

    /** '**Pure_Killer**' */ 
    COATL_UCD_INSC_PURE_KILLER=27,

    /** '**Register_Shifter**' */ 
    COATL_UCD_INSC_REGISTER_SHIFTER=28,

    /** '**Syllable_Modifier**' */ 
    COATL_UCD_INSC_SYLLABLE_MODIFIER=29,

    /** '**Tone_Letter**' */ 
    COATL_UCD_INSC_TONE_LETTER=30,

    /** '**Tone_Mark**' */ 
    COATL_UCD_INSC_TONE_MARK=31,

    /** '**Virama**' */ 
    COATL_UCD_INSC_VIRAMA=32,

    /** '**Visarga**' */ 
    COATL_UCD_INSC_VISARGA=33,

    /** '**Vowel**' */ 
    COATL_UCD_INSC_VOWEL=34,

    /** '**Vowel_Dependent**' */ 
    COATL_UCD_INSC_VOWEL_DEPENDENT=35,

    /** '**Vowel_Independent**' */ 
    COATL_UCD_INSC_VOWEL_INDEPENDENT=36,
} Coatl_Ucd_InSC;

/**
 * Number of values for Unicode character property '*InSC*'.
 *
 * @see Coatl_Ucd_InSC
 */
#define COATL_UCD_INSC_NBVALUES      36

/**
 * Values for Unicode character property '**jg**'.
 *
 * Names are automatically generated from the UCD file 
 * `PropertyValueAliases.txt`.
 *
 * @see COATL_UCD_JG
 */
typedef enum Coatl_Ucd_Jg {
    /** '**African_Feh**' */ 
    COATL_UCD_JG_AFRICAN_FEH=1,

    /** '**African_Noon**' */ 
    COATL_UCD_JG_AFRICAN_NOON=2,

    /** '**African_Qaf**' */ 
    COATL_UCD_JG_AFRICAN_QAF=3,

    /** '**Ain**' */ 
    COATL_UCD_JG_AIN=4,

    /** '**Alaph**' */ 
    COATL_UCD_JG_ALAPH=5,

    /** '**Alef**' */ 
    COATL_UCD_JG_ALEF=6,

    /** '**Beh**' */ 
    COATL_UCD_JG_BEH=7,

    /** '**Beth**' */ 
    COATL_UCD_JG_BETH=8,

    /** '**Burushaski_Yeh_Barree**' */ 
    COATL_UCD_JG_BURUSHASKI_YEH_BARREE=9,

    /** '**Dal**' */ 
    COATL_UCD_JG_DAL=10,

    /** '**Dalath_Rish**' */ 
    COATL_UCD_JG_DALATH_RISH=11,

    /** '**E**' */ 
    COATL_UCD_JG_E=12,

    /** '**Farsi_Yeh**' */ 
    COATL_UCD_JG_FARSI_YEH=13,

    /** '**Fe**' */ 
    COATL_UCD_JG_FE=14,

    /** '**Feh**' */ 
    COATL_UCD_JG_FEH=15,

    /** '**Final_Semkath**' */ 
    COATL_UCD_JG_FINAL_SEMKATH=16,

    /** '**Gaf**' */ 
    COATL_UCD_JG_GAF=17,

    /** '**Gamal**' */ 
    COATL_UCD_JG_GAMAL=18,

    /** '**Hah**' */ 
    COATL_UCD_JG_HAH=19,

    /** '**Hanifi_Rohingya_Kinna_Ya**' */ 
    COATL_UCD_JG_HANIFI_ROHINGYA_KINNA_YA=20,

    /** '**Hanifi_Rohingya_Pa**' */ 
    COATL_UCD_JG_HANIFI_ROHINGYA_PA=21,

    /** '**He**' */ 
    COATL_UCD_JG_HE=22,

    /** '**Heh**' */ 
    COATL_UCD_JG_HEH=23,

    /** '**Heh_Goal**' */ 
    COATL_UCD_JG_HEH_GOAL=24,

    /** '**Heth**' */ 
    COATL_UCD_JG_HETH=25,

    /** '**Kaf**' */ 
    COATL_UCD_JG_KAF=26,

    /** '**Kaph**' */ 
    COATL_UCD_JG_KAPH=27,

    /** '**Khaph**' */ 
    COATL_UCD_JG_KHAPH=28,

    /** '**Knotted_Heh**' */ 
    COATL_UCD_JG_KNOTTED_HEH=29,

    /** '**Lam**' */ 
    COATL_UCD_JG_LAM=30,

    /** '**Lamadh**' */ 
    COATL_UCD_JG_LAMADH=31,

    /** '**Malayalam_Bha**' */ 
    COATL_UCD_JG_MALAYALAM_BHA=32,

    /** '**Malayalam_Ja**' */ 
    COATL_UCD_JG_MALAYALAM_JA=33,

    /** '**Malayalam_Lla**' */ 
    COATL_UCD_JG_MALAYALAM_LLA=34,

    /** '**Malayalam_Llla**' */ 
    COATL_UCD_JG_MALAYALAM_LLLA=35,

    /** '**Malayalam_Nga**' */ 
    COATL_UCD_JG_MALAYALAM_NGA=36,

    /** '**Malayalam_Nna**' */ 
    COATL_UCD_JG_MALAYALAM_NNA=37,

    /** '**Malayalam_Nnna**' */ 
    COATL_UCD_JG_MALAYALAM_NNNA=38,

    /** '**Malayalam_Nya**' */ 
    COATL_UCD_JG_MALAYALAM_NYA=39,

    /** '**Malayalam_Ra**' */ 
    COATL_UCD_JG_MALAYALAM_RA=40,

    /** '**Malayalam_Ssa**' */ 
    COATL_UCD_JG_MALAYALAM_SSA=41,

    /** '**Malayalam_Tta**' */ 
    COATL_UCD_JG_MALAYALAM_TTA=42,

    /** '**Manichaean_Aleph**' */ 
    COATL_UCD_JG_MANICHAEAN_ALEPH=43,

    /** '**Manichaean_Ayin**' */ 
    COATL_UCD_JG_MANICHAEAN_AYIN=44,

    /** '**Manichaean_Beth**' */ 
    COATL_UCD_JG_MANICHAEAN_BETH=45,

    /** '**Manichaean_Daleth**' */ 
    COATL_UCD_JG_MANICHAEAN_DALETH=46,

    /** '**Manichaean_Dhamedh**' */ 
    COATL_UCD_JG_MANICHAEAN_DHAMEDH=47,

    /** '**Manichaean_Five**' */ 
    COATL_UCD_JG_MANICHAEAN_FIVE=48,

    /** '**Manichaean_Gimel**' */ 
    COATL_UCD_JG_MANICHAEAN_GIMEL=49,

    /** '**Manichaean_Heth**' */ 
    COATL_UCD_JG_MANICHAEAN_HETH=50,

    /** '**Manichaean_Hundred**' */ 
    COATL_UCD_JG_MANICHAEAN_HUNDRED=51,

    /** '**Manichaean_Kaph**' */ 
    COATL_UCD_JG_MANICHAEAN_KAPH=52,

    /** '**Manichaean_Lamedh**' */ 
    COATL_UCD_JG_MANICHAEAN_LAMEDH=53,

    /** '**Manichaean_Mem**' */ 
    COATL_UCD_JG_MANICHAEAN_MEM=54,

    /** '**Manichaean_Nun**' */ 
    COATL_UCD_JG_MANICHAEAN_NUN=55,

    /** '**Manichaean_One**' */ 
    COATL_UCD_JG_MANICHAEAN_ONE=56,

    /** '**Manichaean_Pe**' */ 
    COATL_UCD_JG_MANICHAEAN_PE=57,

    /** '**Manichaean_Qoph**' */ 
    COATL_UCD_JG_MANICHAEAN_QOPH=58,

    /** '**Manichaean_Resh**' */ 
    COATL_UCD_JG_MANICHAEAN_RESH=59,

    /** '**Manichaean_Sadhe**' */ 
    COATL_UCD_JG_MANICHAEAN_SADHE=60,

    /** '**Manichaean_Samekh**' */ 
    COATL_UCD_JG_MANICHAEAN_SAMEKH=61,

    /** '**Manichaean_Taw**' */ 
    COATL_UCD_JG_MANICHAEAN_TAW=62,

    /** '**Manichaean_Ten**' */ 
    COATL_UCD_JG_MANICHAEAN_TEN=63,

    /** '**Manichaean_Teth**' */ 
    COATL_UCD_JG_MANICHAEAN_TETH=64,

    /** '**Manichaean_Thamedh**' */ 
    COATL_UCD_JG_MANICHAEAN_THAMEDH=65,

    /** '**Manichaean_Twenty**' */ 
    COATL_UCD_JG_MANICHAEAN_TWENTY=66,

    /** '**Manichaean_Waw**' */ 
    COATL_UCD_JG_MANICHAEAN_WAW=67,

    /** '**Manichaean_Yodh**' */ 
    COATL_UCD_JG_MANICHAEAN_YODH=68,

    /** '**Manichaean_Zayin**' */ 
    COATL_UCD_JG_MANICHAEAN_ZAYIN=69,

    /** '**Meem**' */ 
    COATL_UCD_JG_MEEM=70,

    /** '**Mim**' */ 
    COATL_UCD_JG_MIM=71,

    /** '**No_Joining_Group**' */ 
    COATL_UCD_JG_NO_JOINING_GROUP=72,

    /** '**Noon**' */ 
    COATL_UCD_JG_NOON=73,

    /** '**Nun**' */ 
    COATL_UCD_JG_NUN=74,

    /** '**Nya**' */ 
    COATL_UCD_JG_NYA=75,

    /** '**Pe**' */ 
    COATL_UCD_JG_PE=76,

    /** '**Qaf**' */ 
    COATL_UCD_JG_QAF=77,

    /** '**Qaph**' */ 
    COATL_UCD_JG_QAPH=78,

    /** '**Reh**' */ 
    COATL_UCD_JG_REH=79,

    /** '**Reversed_Pe**' */ 
    COATL_UCD_JG_REVERSED_PE=80,

    /** '**Rohingya_Yeh**' */ 
    COATL_UCD_JG_ROHINGYA_YEH=81,

    /** '**Sad**' */ 
    COATL_UCD_JG_SAD=82,

    /** '**Sadhe**' */ 
    COATL_UCD_JG_SADHE=83,

    /** '**Seen**' */ 
    COATL_UCD_JG_SEEN=84,

    /** '**Semkath**' */ 
    COATL_UCD_JG_SEMKATH=85,

    /** '**Shin**' */ 
    COATL_UCD_JG_SHIN=86,

    /** '**Straight_Waw**' */ 
    COATL_UCD_JG_STRAIGHT_WAW=87,

    /** '**Swash_Kaf**' */ 
    COATL_UCD_JG_SWASH_KAF=88,

    /** '**Syriac_Waw**' */ 
    COATL_UCD_JG_SYRIAC_WAW=89,

    /** '**Tah**' */ 
    COATL_UCD_JG_TAH=90,

    /** '**Taw**' */ 
    COATL_UCD_JG_TAW=91,

    /** '**Teh_Marbuta**' */ 
    COATL_UCD_JG_TEH_MARBUTA=92,

    /** '**Teh_Marbuta_Goal**', '**Hamza_On_Heh_Goal**' */ 
    COATL_UCD_JG_TEH_MARBUTA_GOAL=93,
        /** Alias for #COATL_UCD_JG_TEH_MARBUTA_GOAL */
        COATL_UCD_JG_HAMZA_ON_HEH_GOAL=COATL_UCD_JG_TEH_MARBUTA_GOAL,

    /** '**Teth**' */ 
    COATL_UCD_JG_TETH=94,

    /** '**Waw**' */ 
    COATL_UCD_JG_WAW=95,

    /** '**Yeh**' */ 
    COATL_UCD_JG_YEH=96,

    /** '**Yeh_Barree**' */ 
    COATL_UCD_JG_YEH_BARREE=97,

    /** '**Yeh_With_Tail**' */ 
    COATL_UCD_JG_YEH_WITH_TAIL=98,

    /** '**Yudh**' */ 
    COATL_UCD_JG_YUDH=99,

    /** '**Yudh_He**' */ 
    COATL_UCD_JG_YUDH_HE=100,

    /** '**Zain**' */ 
    COATL_UCD_JG_ZAIN=101,

    /** '**Zhain**' */ 
    COATL_UCD_JG_ZHAIN=102,
} Coatl_Ucd_Jg;

/**
 * Number of values for Unicode character property '*jg*'.
 *
 * @see Coatl_Ucd_Jg
 */
#define COATL_UCD_JG_NBVALUES        102

/**
 * Values for Unicode character property '**jt**'.
 *
 * Names are automatically generated from the UCD file 
 * `PropertyValueAliases.txt`.
 *
 * @see COATL_UCD_JT
 */
typedef enum Coatl_Ucd_Jt {
    /** '**C**', '**Join_Causing**' */ 
    COATL_UCD_JT_C=1,
        /** Alias for #COATL_UCD_JT_C */
        COATL_UCD_JT_JOIN_CAUSING=COATL_UCD_JT_C,

    /** '**D**', '**Dual_Joining**' */ 
    COATL_UCD_JT_D=2,
        /** Alias for #COATL_UCD_JT_D */
        COATL_UCD_JT_DUAL_JOINING=COATL_UCD_JT_D,

    /** '**L**', '**Left_Joining**' */ 
    COATL_UCD_JT_L=3,
        /** Alias for #COATL_UCD_JT_L */
        COATL_UCD_JT_LEFT_JOINING=COATL_UCD_JT_L,

    /** '**R**', '**Right_Joining**' */ 
    COATL_UCD_JT_R=4,
        /** Alias for #COATL_UCD_JT_R */
        COATL_UCD_JT_RIGHT_JOINING=COATL_UCD_JT_R,

    /** '**T**', '**Transparent**' */ 
    COATL_UCD_JT_T=5,
        /** Alias for #COATL_UCD_JT_T */
        COATL_UCD_JT_TRANSPARENT=COATL_UCD_JT_T,

    /** '**U**', '**Non_Joining**' */ 
    COATL_UCD_JT_U=6,
        /** Alias for #COATL_UCD_JT_U */
        COATL_UCD_JT_NON_JOINING=COATL_UCD_JT_U,
} Coatl_Ucd_Jt;

/**
 * Number of values for Unicode character property '*jt*'.
 *
 * @see Coatl_Ucd_Jt
 */
#define COATL_UCD_JT_NBVALUES        6

/**
 * Values for Unicode character property '**lb**'.
 *
 * Names are automatically generated from the UCD file 
 * `PropertyValueAliases.txt`.
 *
 * @see COATL_UCD_LB
 */
typedef enum Coatl_Ucd_Lb {
    /** '**AI**', '**Ambiguous**' */ 
    COATL_UCD_LB_AI=1,
        /** Alias for #COATL_UCD_LB_AI */
        COATL_UCD_LB_AMBIGUOUS=COATL_UCD_LB_AI,

    /** '**AL**', '**Alphabetic**' */ 
    COATL_UCD_LB_AL=2,
        /** Alias for #COATL_UCD_LB_AL */
        COATL_UCD_LB_ALPHABETIC=COATL_UCD_LB_AL,

    /** '**B2**', '**Break_Both**' */ 
    COATL_UCD_LB_B2=3,
        /** Alias for #COATL_UCD_LB_B2 */
        COATL_UCD_LB_BREAK_BOTH=COATL_UCD_LB_B2,

    /** '**BA**', '**Break_After**' */ 
    COATL_UCD_LB_BA=4,
        /** Alias for #COATL_UCD_LB_BA */
        COATL_UCD_LB_BREAK_AFTER=COATL_UCD_LB_BA,

    /** '**BB**', '**Break_Before**' */ 
    COATL_UCD_LB_BB=5,
        /** Alias for #COATL_UCD_LB_BB */
        COATL_UCD_LB_BREAK_BEFORE=COATL_UCD_LB_BB,

    /** '**BK**', '**Mandatory_Break**' */ 
    COATL_UCD_LB_BK=6,
        /** Alias for #COATL_UCD_LB_BK */
        COATL_UCD_LB_MANDATORY_BREAK=COATL_UCD_LB_BK,

    /** '**CB**', '**Contingent_Break**' */ 
    COATL_UCD_LB_CB=7,
        /** Alias for #COATL_UCD_LB_CB */
        COATL_UCD_LB_CONTINGENT_BREAK=COATL_UCD_LB_CB,

    /** '**CJ**', '**Conditional_Japanese_Starter**' */ 
    COATL_UCD_LB_CJ=8,
        /** Alias for #COATL_UCD_LB_CJ */
        COATL_UCD_LB_CONDITIONAL_JAPANESE_STARTER=COATL_UCD_LB_CJ,

    /** '**CL**', '**Close_Punctuation**' */ 
    COATL_UCD_LB_CL=9,
        /** Alias for #COATL_UCD_LB_CL */
        COATL_UCD_LB_CLOSE_PUNCTUATION=COATL_UCD_LB_CL,

    /** '**CM**', '**Combining_Mark**' */ 
    COATL_UCD_LB_CM=10,
        /** Alias for #COATL_UCD_LB_CM */
        COATL_UCD_LB_COMBINING_MARK=COATL_UCD_LB_CM,

    /** '**CP**', '**Close_Parenthesis**' */ 
    COATL_UCD_LB_CP=11,
        /** Alias for #COATL_UCD_LB_CP */
        COATL_UCD_LB_CLOSE_PARENTHESIS=COATL_UCD_LB_CP,

    /** '**CR**', '**Carriage_Return**' */ 
    COATL_UCD_LB_CR=12,
        /** Alias for #COATL_UCD_LB_CR */
        COATL_UCD_LB_CARRIAGE_RETURN=COATL_UCD_LB_CR,

    /** '**EB**', '**E_Base**' */ 
    COATL_UCD_LB_EB=13,
        /** Alias for #COATL_UCD_LB_EB */
        COATL_UCD_LB_E_BASE=COATL_UCD_LB_EB,

    /** '**EM**', '**E_Modifier**' */ 
    COATL_UCD_LB_EM=14,
        /** Alias for #COATL_UCD_LB_EM */
        COATL_UCD_LB_E_MODIFIER=COATL_UCD_LB_EM,

    /** '**EX**', '**Exclamation**' */ 
    COATL_UCD_LB_EX=15,
        /** Alias for #COATL_UCD_LB_EX */
        COATL_UCD_LB_EXCLAMATION=COATL_UCD_LB_EX,

    /** '**GL**', '**Glue**' */ 
    COATL_UCD_LB_GL=16,
        /** Alias for #COATL_UCD_LB_GL */
        COATL_UCD_LB_GLUE=COATL_UCD_LB_GL,

    /** '**H2**' */ 
    COATL_UCD_LB_H2=17,

    /** '**H3**' */ 
    COATL_UCD_LB_H3=18,

    /** '**HL**', '**Hebrew_Letter**' */ 
    COATL_UCD_LB_HL=19,
        /** Alias for #COATL_UCD_LB_HL */
        COATL_UCD_LB_HEBREW_LETTER=COATL_UCD_LB_HL,

    /** '**HY**', '**Hyphen**' */ 
    COATL_UCD_LB_HY=20,
        /** Alias for #COATL_UCD_LB_HY */
        COATL_UCD_LB_HYPHEN=COATL_UCD_LB_HY,

    /** '**ID**', '**Ideographic**' */ 
    COATL_UCD_LB_ID=21,
        /** Alias for #COATL_UCD_LB_ID */
        COATL_UCD_LB_IDEOGRAPHIC=COATL_UCD_LB_ID,

    /** '**IN**', '**Inseparable**', '**Inseperable**' */ 
    COATL_UCD_LB_IN=22,
        /** Alias for #COATL_UCD_LB_IN */
        COATL_UCD_LB_INSEPARABLE=COATL_UCD_LB_IN,
        /** Alias for #COATL_UCD_LB_IN */
        COATL_UCD_LB_INSEPERABLE=COATL_UCD_LB_IN,

    /** '**IS**', '**Infix_Numeric**' */ 
    COATL_UCD_LB_IS=23,
        /** Alias for #COATL_UCD_LB_IS */
        COATL_UCD_LB_INFIX_NUMERIC=COATL_UCD_LB_IS,

    /** '**JL**' */ 
    COATL_UCD_LB_JL=24,

    /** '**JT**' */ 
    COATL_UCD_LB_JT=25,

    /** '**JV**' */ 
    COATL_UCD_LB_JV=26,

    /** '**LF**', '**Line_Feed**' */ 
    COATL_UCD_LB_LF=27,
        /** Alias for #COATL_UCD_LB_LF */
        COATL_UCD_LB_LINE_FEED=COATL_UCD_LB_LF,

    /** '**NL**', '**Next_Line**' */ 
    COATL_UCD_LB_NL=28,
        /** Alias for #COATL_UCD_LB_NL */
        COATL_UCD_LB_NEXT_LINE=COATL_UCD_LB_NL,

    /** '**NS**', '**Nonstarter**' */ 
    COATL_UCD_LB_NS=29,
        /** Alias for #COATL_UCD_LB_NS */
        COATL_UCD_LB_NONSTARTER=COATL_UCD_LB_NS,

    /** '**NU**', '**Numeric**' */ 
    COATL_UCD_LB_NU=30,
        /** Alias for #COATL_UCD_LB_NU */
        COATL_UCD_LB_NUMERIC=COATL_UCD_LB_NU,

    /** '**OP**', '**Open_Punctuation**' */ 
    COATL_UCD_LB_OP=31,
        /** Alias for #COATL_UCD_LB_OP */
        COATL_UCD_LB_OPEN_PUNCTUATION=COATL_UCD_LB_OP,

    /** '**PO**', '**Postfix_Numeric**' */ 
    COATL_UCD_LB_PO=32,
        /** Alias for #COATL_UCD_LB_PO */
        COATL_UCD_LB_POSTFIX_NUMERIC=COATL_UCD_LB_PO,

    /** '**PR**', '**Prefix_Numeric**' */ 
    COATL_UCD_LB_PR=33,
        /** Alias for #COATL_UCD_LB_PR */
        COATL_UCD_LB_PREFIX_NUMERIC=COATL_UCD_LB_PR,

    /** '**QU**', '**Quotation**' */ 
    COATL_UCD_LB_QU=34,
        /** Alias for #COATL_UCD_LB_QU */
        COATL_UCD_LB_QUOTATION=COATL_UCD_LB_QU,

    /** '**RI**', '**Regional_Indicator**' */ 
    COATL_UCD_LB_RI=35,
        /** Alias for #COATL_UCD_LB_RI */
        COATL_UCD_LB_REGIONAL_INDICATOR=COATL_UCD_LB_RI,

    /** '**SA**', '**Complex_Context**' */ 
    COATL_UCD_LB_SA=36,
        /** Alias for #COATL_UCD_LB_SA */
        COATL_UCD_LB_COMPLEX_CONTEXT=COATL_UCD_LB_SA,

    /** '**SG**', '**Surrogate**' */ 
    COATL_UCD_LB_SG=37,
        /** Alias for #COATL_UCD_LB_SG */
        COATL_UCD_LB_SURROGATE=COATL_UCD_LB_SG,

    /** '**SP**', '**Space**' */ 
    COATL_UCD_LB_SP=38,
        /** Alias for #COATL_UCD_LB_SP */
        COATL_UCD_LB_SPACE=COATL_UCD_LB_SP,

    /** '**SY**', '**Break_Symbols**' */ 
    COATL_UCD_LB_SY=39,
        /** Alias for #COATL_UCD_LB_SY */
        COATL_UCD_LB_BREAK_SYMBOLS=COATL_UCD_LB_SY,

    /** '**WJ**', '**Word_Joiner**' */ 
    COATL_UCD_LB_WJ=40,
        /** Alias for #COATL_UCD_LB_WJ */
        COATL_UCD_LB_WORD_JOINER=COATL_UCD_LB_WJ,

    /** '**XX**', '**Unknown**' */ 
    COATL_UCD_LB_XX=41,
        /** Alias for #COATL_UCD_LB_XX */
        COATL_UCD_LB_UNKNOWN=COATL_UCD_LB_XX,

    /** '**ZW**', '**ZWSpace**' */ 
    COATL_UCD_LB_ZW=42,
        /** Alias for #COATL_UCD_LB_ZW */
        COATL_UCD_LB_ZWSPACE=COATL_UCD_LB_ZW,

    /** '**ZWJ**' */ 
    COATL_UCD_LB_ZWJ=43,
} Coatl_Ucd_Lb;

/**
 * Number of values for Unicode character property '*lb*'.
 *
 * @see Coatl_Ucd_Lb
 */
#define COATL_UCD_LB_NBVALUES        43

/**
 * Values for Unicode character property '**NFC_QC**'.
 *
 * Names are automatically generated from the UCD file 
 * `PropertyValueAliases.txt`.
 *
 * @see COATL_UCD_NFC_QC
 */
typedef enum Coatl_Ucd_NFC_QC {
    /** '**M**', '**Maybe**' */ 
    COATL_UCD_NFC_QC_M=1,
        /** Alias for #COATL_UCD_NFC_QC_M */
        COATL_UCD_NFC_QC_MAYBE=COATL_UCD_NFC_QC_M,

    /** '**N**', '**No**' */ 
    COATL_UCD_NFC_QC_N=2,
        /** Alias for #COATL_UCD_NFC_QC_N */
        COATL_UCD_NFC_QC_NO=COATL_UCD_NFC_QC_N,

    /** '**Y**', '**Yes**' */ 
    COATL_UCD_NFC_QC_Y=3,
        /** Alias for #COATL_UCD_NFC_QC_Y */
        COATL_UCD_NFC_QC_YES=COATL_UCD_NFC_QC_Y,
} Coatl_Ucd_NFC_QC;

/**
 * Number of values for Unicode character property '*NFC_QC*'.
 *
 * @see Coatl_Ucd_NFC_QC
 */
#define COATL_UCD_NFC_QC_NBVALUES    3

/**
 * Values for Unicode character property '**NFD_QC**'.
 *
 * Names are automatically generated from the UCD file 
 * `PropertyValueAliases.txt`.
 *
 * @see COATL_UCD_NFD_QC
 */
typedef enum Coatl_Ucd_NFD_QC {
    /** '**N**', '**No**' */ 
    COATL_UCD_NFD_QC_N=1,
        /** Alias for #COATL_UCD_NFD_QC_N */
        COATL_UCD_NFD_QC_NO=COATL_UCD_NFD_QC_N,

    /** '**Y**', '**Yes**' */ 
    COATL_UCD_NFD_QC_Y=2,
        /** Alias for #COATL_UCD_NFD_QC_Y */
        COATL_UCD_NFD_QC_YES=COATL_UCD_NFD_QC_Y,
} Coatl_Ucd_NFD_QC;

/**
 * Number of values for Unicode character property '*NFD_QC*'.
 *
 * @see Coatl_Ucd_NFD_QC
 */
#define COATL_UCD_NFD_QC_NBVALUES    2

/**
 * Values for Unicode character property '**NFKC_QC**'.
 *
 * Names are automatically generated from the UCD file 
 * `PropertyValueAliases.txt`.
 *
 * @see COATL_UCD_NFKC_QC
 */
typedef enum Coatl_Ucd_NFKC_QC {
    /** '**M**', '**Maybe**' */ 
    COATL_UCD_NFKC_QC_M=1,
        /** Alias for #COATL_UCD_NFKC_QC_M */
        COATL_UCD_NFKC_QC_MAYBE=COATL_UCD_NFKC_QC_M,

    /** '**N**', '**No**' */ 
    COATL_UCD_NFKC_QC_N=2,
        /** Alias for #COATL_UCD_NFKC_QC_N */
        COATL_UCD_NFKC_QC_NO=COATL_UCD_NFKC_QC_N,

    /** '**Y**', '**Yes**' */ 
    COATL_UCD_NFKC_QC_Y=3,
        /** Alias for #COATL_UCD_NFKC_QC_Y */
        COATL_UCD_NFKC_QC_YES=COATL_UCD_NFKC_QC_Y,
} Coatl_Ucd_NFKC_QC;

/**
 * Number of values for Unicode character property '*NFKC_QC*'.
 *
 * @see Coatl_Ucd_NFKC_QC
 */
#define COATL_UCD_NFKC_QC_NBVALUES   3

/**
 * Values for Unicode character property '**NFKD_QC**'.
 *
 * Names are automatically generated from the UCD file 
 * `PropertyValueAliases.txt`.
 *
 * @see COATL_UCD_NFKD_QC
 */
typedef enum Coatl_Ucd_NFKD_QC {
    /** '**N**', '**No**' */ 
    COATL_UCD_NFKD_QC_N=1,
        /** Alias for #COATL_UCD_NFKD_QC_N */
        COATL_UCD_NFKD_QC_NO=COATL_UCD_NFKD_QC_N,

    /** '**Y**', '**Yes**' */ 
    COATL_UCD_NFKD_QC_Y=2,
        /** Alias for #COATL_UCD_NFKD_QC_Y */
        COATL_UCD_NFKD_QC_YES=COATL_UCD_NFKD_QC_Y,
} Coatl_Ucd_NFKD_QC;

/**
 * Number of values for Unicode character property '*NFKD_QC*'.
 *
 * @see Coatl_Ucd_NFKD_QC
 */
#define COATL_UCD_NFKD_QC_NBVALUES   2

/**
 * Values for Unicode character property '**nt**'.
 *
 * Names are automatically generated from the UCD file 
 * `PropertyValueAliases.txt`.
 *
 * @see COATL_UCD_NT
 */
typedef enum Coatl_Ucd_Nt {
    /** '**De**', '**Decimal**' */ 
    COATL_UCD_NT_DE=1,
        /** Alias for #COATL_UCD_NT_DE */
        COATL_UCD_NT_DECIMAL=COATL_UCD_NT_DE,

    /** '**Di**', '**Digit**' */ 
    COATL_UCD_NT_DI=2,
        /** Alias for #COATL_UCD_NT_DI */
        COATL_UCD_NT_DIGIT=COATL_UCD_NT_DI,

    /** '**None**' */ 
    COATL_UCD_NT_NONE=3,

    /** '**Nu**', '**Numeric**' */ 
    COATL_UCD_NT_NU=4,
        /** Alias for #COATL_UCD_NT_NU */
        COATL_UCD_NT_NUMERIC=COATL_UCD_NT_NU,
} Coatl_Ucd_Nt;

/**
 * Number of values for Unicode character property '*nt*'.
 *
 * @see Coatl_Ucd_Nt
 */
#define COATL_UCD_NT_NBVALUES        4

/**
 * Values for Unicode character property '**SB**'.
 *
 * Names are automatically generated from the UCD file 
 * `PropertyValueAliases.txt`.
 *
 * @see COATL_UCD_SB
 */
typedef enum Coatl_Ucd_SB {
    /** '**AT**', '**ATerm**' */ 
    COATL_UCD_SB_AT=1,
        /** Alias for #COATL_UCD_SB_AT */
        COATL_UCD_SB_ATERM=COATL_UCD_SB_AT,

    /** '**CL**', '**Close**' */ 
    COATL_UCD_SB_CL=2,
        /** Alias for #COATL_UCD_SB_CL */
        COATL_UCD_SB_CLOSE=COATL_UCD_SB_CL,

    /** '**CR**' */ 
    COATL_UCD_SB_CR=3,

    /** '**EX**', '**Extend**' */ 
    COATL_UCD_SB_EX=4,
        /** Alias for #COATL_UCD_SB_EX */
        COATL_UCD_SB_EXTEND=COATL_UCD_SB_EX,

    /** '**FO**', '**Format**' */ 
    COATL_UCD_SB_FO=5,
        /** Alias for #COATL_UCD_SB_FO */
        COATL_UCD_SB_FORMAT=COATL_UCD_SB_FO,

    /** '**LE**', '**OLetter**' */ 
    COATL_UCD_SB_LE=6,
        /** Alias for #COATL_UCD_SB_LE */
        COATL_UCD_SB_OLETTER=COATL_UCD_SB_LE,

    /** '**LF**' */ 
    COATL_UCD_SB_LF=7,

    /** '**LO**', '**Lower**' */ 
    COATL_UCD_SB_LO=8,
        /** Alias for #COATL_UCD_SB_LO */
        COATL_UCD_SB_LOWER=COATL_UCD_SB_LO,

    /** '**NU**', '**Numeric**' */ 
    COATL_UCD_SB_NU=9,
        /** Alias for #COATL_UCD_SB_NU */
        COATL_UCD_SB_NUMERIC=COATL_UCD_SB_NU,

    /** '**SC**', '**SContinue**' */ 
    COATL_UCD_SB_SC=10,
        /** Alias for #COATL_UCD_SB_SC */
        COATL_UCD_SB_SCONTINUE=COATL_UCD_SB_SC,

    /** '**SE**', '**Sep**' */ 
    COATL_UCD_SB_SE=11,
        /** Alias for #COATL_UCD_SB_SE */
        COATL_UCD_SB_SEP=COATL_UCD_SB_SE,

    /** '**SP**', '**Sp**' */ 
    COATL_UCD_SB_SP=12,

    /** '**ST**', '**STerm**' */ 
    COATL_UCD_SB_ST=13,
        /** Alias for #COATL_UCD_SB_ST */
        COATL_UCD_SB_STERM=COATL_UCD_SB_ST,

    /** '**UP**', '**Upper**' */ 
    COATL_UCD_SB_UP=14,
        /** Alias for #COATL_UCD_SB_UP */
        COATL_UCD_SB_UPPER=COATL_UCD_SB_UP,

    /** '**XX**', '**Other**' */ 
    COATL_UCD_SB_XX=15,
        /** Alias for #COATL_UCD_SB_XX */
        COATL_UCD_SB_OTHER=COATL_UCD_SB_XX,
} Coatl_Ucd_SB;

/**
 * Number of values for Unicode character property '*SB*'.
 *
 * @see Coatl_Ucd_SB
 */
#define COATL_UCD_SB_NBVALUES        15

/**
 * Values for Unicode character property '**vo**'.
 *
 * Names are automatically generated from the UCD file 
 * `PropertyValueAliases.txt`.
 *
 * @see COATL_UCD_VO
 */
typedef enum Coatl_Ucd_Vo {
    /** '**R**', '**Rotated**' */ 
    COATL_UCD_VO_R=1,
        /** Alias for #COATL_UCD_VO_R */
        COATL_UCD_VO_ROTATED=COATL_UCD_VO_R,

    /** '**Tr**', '**Transformed_Rotated**' */ 
    COATL_UCD_VO_TR=2,
        /** Alias for #COATL_UCD_VO_TR */
        COATL_UCD_VO_TRANSFORMED_ROTATED=COATL_UCD_VO_TR,

    /** '**Tu**', '**Transformed_Upright**' */ 
    COATL_UCD_VO_TU=3,
        /** Alias for #COATL_UCD_VO_TU */
        COATL_UCD_VO_TRANSFORMED_UPRIGHT=COATL_UCD_VO_TU,

    /** '**U**', '**Upright**' */ 
    COATL_UCD_VO_U=4,
        /** Alias for #COATL_UCD_VO_U */
        COATL_UCD_VO_UPRIGHT=COATL_UCD_VO_U,
} Coatl_Ucd_Vo;

/**
 * Number of values for Unicode character property '*vo*'.
 *
 * @see Coatl_Ucd_Vo
 */
#define COATL_UCD_VO_NBVALUES        4

/**
 * Values for Unicode character property '**WB**'.
 *
 * Names are automatically generated from the UCD file 
 * `PropertyValueAliases.txt`.
 *
 * @see COATL_UCD_WB
 */
typedef enum Coatl_Ucd_WB {
    /** '**CR**' */ 
    COATL_UCD_WB_CR=1,

    /** '**DQ**', '**Double_Quote**' */ 
    COATL_UCD_WB_DQ=2,
        /** Alias for #COATL_UCD_WB_DQ */
        COATL_UCD_WB_DOUBLE_QUOTE=COATL_UCD_WB_DQ,

    /** '**EB**', '**E_Base**' */ 
    COATL_UCD_WB_EB=3,
        /** Alias for #COATL_UCD_WB_EB */
        COATL_UCD_WB_E_BASE=COATL_UCD_WB_EB,

    /** '**EBG**', '**E_Base_GAZ**' */ 
    COATL_UCD_WB_EBG=4,
        /** Alias for #COATL_UCD_WB_EBG */
        COATL_UCD_WB_E_BASE_GAZ=COATL_UCD_WB_EBG,

    /** '**EM**', '**E_Modifier**' */ 
    COATL_UCD_WB_EM=5,
        /** Alias for #COATL_UCD_WB_EM */
        COATL_UCD_WB_E_MODIFIER=COATL_UCD_WB_EM,

    /** '**EX**', '**ExtendNumLet**' */ 
    COATL_UCD_WB_EX=6,
        /** Alias for #COATL_UCD_WB_EX */
        COATL_UCD_WB_EXTENDNUMLET=COATL_UCD_WB_EX,

    /** '**Extend**' */ 
    COATL_UCD_WB_EXTEND=7,

    /** '**FO**', '**Format**' */ 
    COATL_UCD_WB_FO=8,
        /** Alias for #COATL_UCD_WB_FO */
        COATL_UCD_WB_FORMAT=COATL_UCD_WB_FO,

    /** '**GAZ**', '**Glue_After_Zwj**' */ 
    COATL_UCD_WB_GAZ=9,
        /** Alias for #COATL_UCD_WB_GAZ */
        COATL_UCD_WB_GLUE_AFTER_ZWJ=COATL_UCD_WB_GAZ,

    /** '**HL**', '**Hebrew_Letter**' */ 
    COATL_UCD_WB_HL=10,
        /** Alias for #COATL_UCD_WB_HL */
        COATL_UCD_WB_HEBREW_LETTER=COATL_UCD_WB_HL,

    /** '**KA**', '**Katakana**' */ 
    COATL_UCD_WB_KA=11,
        /** Alias for #COATL_UCD_WB_KA */
        COATL_UCD_WB_KATAKANA=COATL_UCD_WB_KA,

    /** '**LE**', '**ALetter**' */ 
    COATL_UCD_WB_LE=12,
        /** Alias for #COATL_UCD_WB_LE */
        COATL_UCD_WB_ALETTER=COATL_UCD_WB_LE,

    /** '**LF**' */ 
    COATL_UCD_WB_LF=13,

    /** '**MB**', '**MidNumLet**' */ 
    COATL_UCD_WB_MB=14,
        /** Alias for #COATL_UCD_WB_MB */
        COATL_UCD_WB_MIDNUMLET=COATL_UCD_WB_MB,

    /** '**ML**', '**MidLetter**' */ 
    COATL_UCD_WB_ML=15,
        /** Alias for #COATL_UCD_WB_ML */
        COATL_UCD_WB_MIDLETTER=COATL_UCD_WB_ML,

    /** '**MN**', '**MidNum**' */ 
    COATL_UCD_WB_MN=16,
        /** Alias for #COATL_UCD_WB_MN */
        COATL_UCD_WB_MIDNUM=COATL_UCD_WB_MN,

    /** '**NL**', '**Newline**' */ 
    COATL_UCD_WB_NL=17,
        /** Alias for #COATL_UCD_WB_NL */
        COATL_UCD_WB_NEWLINE=COATL_UCD_WB_NL,

    /** '**NU**', '**Numeric**' */ 
    COATL_UCD_WB_NU=18,
        /** Alias for #COATL_UCD_WB_NU */
        COATL_UCD_WB_NUMERIC=COATL_UCD_WB_NU,

    /** '**RI**', '**Regional_Indicator**' */ 
    COATL_UCD_WB_RI=19,
        /** Alias for #COATL_UCD_WB_RI */
        COATL_UCD_WB_REGIONAL_INDICATOR=COATL_UCD_WB_RI,

    /** '**SQ**', '**Single_Quote**' */ 
    COATL_UCD_WB_SQ=20,
        /** Alias for #COATL_UCD_WB_SQ */
        COATL_UCD_WB_SINGLE_QUOTE=COATL_UCD_WB_SQ,

    /** '**WSegSpace**' */ 
    COATL_UCD_WB_WSEGSPACE=21,

    /** '**XX**', '**Other**' */ 
    COATL_UCD_WB_XX=22,
        /** Alias for #COATL_UCD_WB_XX */
        COATL_UCD_WB_OTHER=COATL_UCD_WB_XX,

    /** '**ZWJ**' */ 
    COATL_UCD_WB_ZWJ=23,
} Coatl_Ucd_WB;

/**
 * Number of values for Unicode character property '*WB*'.
 *
 * @see Coatl_Ucd_WB
 */
#define COATL_UCD_WB_NBVALUES        23

/* End of UCD Properties *//*!\}*/

/* End of Unicode Character Database *//*!\}*/

#endif /* _COATL_UCDPROPERTIES */
