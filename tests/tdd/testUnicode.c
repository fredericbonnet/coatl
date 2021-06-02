#include <colibri.h>
#include <coatl.h>
#include <picotest.h>
#include <stdarg.h>

/*
 * Unicode
 */

#include "hooks.h"
#include "colibriFixture.h"

PICOTEST_SUITE(testUnicode, testUnicodeCharacterDatabase,
               testCaseMappingAndFolding);

/* Unicode Character Database */
PICOTEST_SUITE(testUnicodeCharacterDatabase, testUcdNumericProperties,
               testUcdStringProperties, testUcdMiscellaneousProperties,
               testUcdCatalogProperties, testUcdEnumeratedProperties,
               testUcdBinaryProperties);

static void checkNumericProperty(const char *(*proc)(Col_Char), Col_Char c,
                                 const char *value) {
    PICOTEST_ASSERT(strcmp(proc(c), value) == 0);
}
static void checkMcpPropertyIdentity(const int *(*proc)(Col_Char, size_t *),
                                     Col_Char c) {
    size_t length;
    const int *list = proc(c, &length);
    PICOTEST_ASSERT(length == 0);
}
static void checkMcpPropertySingle(const int *(*proc)(Col_Char, size_t *),
                                   Col_Char c, Col_Char e) {
    size_t length;
    const int *list = proc(c, &length);
    PICOTEST_ASSERT(length == 1);
    PICOTEST_ASSERT(e == c + *list);
}
static void checkMcpPropertyMultiple(const int *(*proc)(Col_Char, size_t *),
                                     Col_Char c, Col_Char2 *e) {
    size_t length;
    const int *list = proc(c, &length);
    PICOTEST_ASSERT(length > 1);
    for (int i = 0; i < length; i++) {
        PICOTEST_ASSERT(e[i] == list[i]);
    }
}
static void checkCpProperty(Col_Char (*proc)(Col_Char), Col_Char c,
                            Col_Char e) {
    PICOTEST_ASSERT(proc(c) == e);
}
static void checkEnumListPropertySingle(const unsigned char *(*proc)(Col_Char,
                                                                     size_t *),
                                        Col_Char c, int value) {
    size_t length;
    const unsigned char *list = proc(c, &length);
    PICOTEST_ASSERT(length == 1);
    PICOTEST_ASSERT(*list == value);
}
static void
checkEnumListPropertyMultiple(const unsigned char *(*proc)(Col_Char, size_t *),
                              Col_Char c, ...) {
    va_list values;
    size_t nb;
    size_t length, i, j;
    const unsigned char *list = proc(c, &length);
    va_start(values, c);
    for (nb = 0; va_arg(values, int); nb++)
        ;
    va_end(values);
    PICOTEST_ASSERT(length == nb);
    for (i = 0; i < length; i++) {
        va_start(values, c);
        for (j = 0; j < length; j++) {
            if (va_arg(values, int) == list[i])
                break;
        }
        va_end(values);
        PICOTEST_ASSERT(j != length);
    }
}

PICOTEST_SUITE(testUcdNumericProperties, testUcdPropertyNv);
PICOTEST_CASE(testUcdPropertyNv, colibriFixture) {
    checkNumericProperty(Coatl_GetUcdProperty_Nv, '$', "NaN");
    checkNumericProperty(Coatl_GetUcdProperty_Nv, '0', "0");
    checkNumericProperty(Coatl_GetUcdProperty_Nv, '1', "1");
    checkNumericProperty(Coatl_GetUcdProperty_Nv, '9', "9");
    checkNumericProperty(Coatl_GetUcdProperty_Nv, 0xBD, "1/2");    /* ½ */
    checkNumericProperty(Coatl_GetUcdProperty_Nv, 0x0D5C, "1/10"); /* ൜ */
    checkNumericProperty(Coatl_GetUcdProperty_Nv, 'a', "NaN");
}

PICOTEST_SUITE(testUcdStringProperties, testUcdPropertyCf, testUcdPropertyDm,
               testUcdPropertyLc, testUcdPropertyNFKC_CF, testUcdPropertyScf,
               testUcdPropertySlc, testUcdPropertyStc, testUcdPropertySuc,
               testUcdPropertyTc, testUcdPropertyUc);
PICOTEST_CASE(testUcdPropertyCf, colibriFixture) {
    checkMcpPropertyIdentity(Coatl_GetUcdProperty_Cf, '0');
    checkMcpPropertySingle(Coatl_GetUcdProperty_Cf, 'A', 'a');
    checkMcpPropertyIdentity(Coatl_GetUcdProperty_Cf, 'b');
    checkMcpPropertySingle(Coatl_GetUcdProperty_Cf, 0xB5, 0x03BC); /* µ -> μ */
    checkMcpPropertyMultiple(Coatl_GetUcdProperty_Cf, 0xDF,
                             L"ss"); /* ß -> ss */
    checkMcpPropertyMultiple(Coatl_GetUcdProperty_Cf, 0xFB04,
                             L"ffl"); /* ﬄ -> ffl */
    checkMcpPropertySingle(Coatl_GetUcdProperty_Cf, 0x0533,
                           0x0563); /* Գ -> գ */
    checkMcpPropertyMultiple(Coatl_GetUcdProperty_Cf, 0x1FFC,
                             L"\u03C9\u03B9"); /* ῼ -> ωι */
}
PICOTEST_CASE(testUcdPropertyDm, colibriFixture) {
    checkMcpPropertyIdentity(Coatl_GetUcdProperty_Dm, '$');
    checkMcpPropertyIdentity(Coatl_GetUcdProperty_Dm, 'A');
    checkMcpPropertyIdentity(Coatl_GetUcdProperty_Dm, 'b');
    checkMcpPropertySingle(Coatl_GetUcdProperty_Dm, 0xB5, 0x03BC); /* µ -> μ */
    checkMcpPropertySingle(Coatl_GetUcdProperty_Dm, 0x2460, '1'); /* ① -> 1 */
    checkMcpPropertyMultiple(Coatl_GetUcdProperty_Dm, 0xFB03,
                             L"ffi");                          /* ﬃ -> ffi */
    checkMcpPropertyIdentity(Coatl_GetUcdProperty_Dm, 0x0533); /* Գ */
    checkMcpPropertyMultiple(Coatl_GetUcdProperty_Dm, 0x1FFC,
                             L"\u03A9\u0345"); /* ῼ -> Ω◌ͅ */
}
PICOTEST_CASE(testUcdPropertyLc, colibriFixture) {
    checkMcpPropertyIdentity(Coatl_GetUcdProperty_Lc, '&');
    checkMcpPropertyIdentity(Coatl_GetUcdProperty_Lc, 'a');
    checkMcpPropertySingle(Coatl_GetUcdProperty_Lc, 'B', 'b');
    checkMcpPropertySingle(Coatl_GetUcdProperty_Lc, 0x03A3,
                           0x03C3); /* Σ -> σ */
    checkMcpPropertyMultiple(Coatl_GetUcdProperty_Lc, 0x0130,
                             L"i\u0307"); /* İ -> i◌̇  */
}
PICOTEST_CASE(testUcdPropertyNFKC_CF, colibriFixture) {
    checkMcpPropertyIdentity(Coatl_GetUcdProperty_NFKC_CF, 'c');
    checkMcpPropertySingle(Coatl_GetUcdProperty_NFKC_CF, 'D', 'd');
    checkMcpPropertyMultiple(Coatl_GetUcdProperty_NFKC_CF, 0xBC,
                             L"1\u20444"); /* ¼ -> 1⁄4 */
}
PICOTEST_CASE(testUcdPropertyScf, colibriFixture) {
    checkCpProperty(Coatl_GetUcdProperty_Scf, 'E', 'e');
    checkCpProperty(Coatl_GetUcdProperty_Scf, 'f', 'f');
    checkCpProperty(Coatl_GetUcdProperty_Scf, 0xB5, 0x03BC);   /* µ -> μ */
    checkCpProperty(Coatl_GetUcdProperty_Scf, 0xDF, 0xDF);     /* ß */
    checkCpProperty(Coatl_GetUcdProperty_Scf, 0xFB04, 0xFB04); /* ﬄ */
}
PICOTEST_CASE(testUcdPropertySlc, colibriFixture) {
    checkCpProperty(Coatl_GetUcdProperty_Slc, 'g', 'g');
    checkCpProperty(Coatl_GetUcdProperty_Slc, 'H', 'h');
    checkCpProperty(Coatl_GetUcdProperty_Slc, 0xC0, 0xE0);     /* À -> à */
    checkCpProperty(Coatl_GetUcdProperty_Slc, 0xDF, 0xDF);     /* ß */
    checkCpProperty(Coatl_GetUcdProperty_Slc, 0x0104, 0x0105); /* Ą -> ą */
    checkCpProperty(Coatl_GetUcdProperty_Slc, 0x0240, 0x0240); /* ɀ */
    checkCpProperty(Coatl_GetUcdProperty_Slc, 0x03AB, 0x03CB); /* Ϋ -> ϋ */
    checkCpProperty(Coatl_GetUcdProperty_Slc, 0x2CF2, 0x2CF3); /* Ⳳ -> ⳳ */
}
PICOTEST_CASE(testUcdPropertyStc, colibriFixture) {
    checkCpProperty(Coatl_GetUcdProperty_Stc, 'i', 'I');
    checkCpProperty(Coatl_GetUcdProperty_Stc, 'J', 'J');
    checkCpProperty(Coatl_GetUcdProperty_Stc, 0xB5, 0x039C);   /* µ -> Μ */
    checkCpProperty(Coatl_GetUcdProperty_Stc, 0xDF, 0xDF);     /* ß */
    checkCpProperty(Coatl_GetUcdProperty_Stc, 0x0133, 0x0132); /* ĳ -> Ĳ */
    checkCpProperty(Coatl_GetUcdProperty_Stc, 0x01C7, 0x01C8); /* Ǉ -> ǈ */
    checkCpProperty(Coatl_GetUcdProperty_Stc, 0x01C9, 0x01C8); /* ǉ -> ǈ */
}
PICOTEST_CASE(testUcdPropertySuc, colibriFixture) {
    checkCpProperty(Coatl_GetUcdProperty_Suc, 'k', 'K');
    checkCpProperty(Coatl_GetUcdProperty_Suc, 'l', 'L');
    checkCpProperty(Coatl_GetUcdProperty_Suc, 0xDF, 0xDF);     /* ß */
    checkCpProperty(Coatl_GetUcdProperty_Suc, 0x03BC, 0x039C); /* μ -> Μ */
    checkCpProperty(Coatl_GetUcdProperty_Suc, 0x0133, 0x0132); /* ĳ -> Ĳ */
    checkCpProperty(Coatl_GetUcdProperty_Suc, 0x01C9, 0x01C7); /* ǉ -> Ǉ */
    checkCpProperty(Coatl_GetUcdProperty_Suc, 0x01C8, 0x01C7); /* ǈ -> Ǉ */
}
PICOTEST_CASE(testUcdPropertyTc, colibriFixture) {
    checkMcpPropertySingle(Coatl_GetUcdProperty_Tc, 'm', 'M');
    checkMcpPropertyIdentity(Coatl_GetUcdProperty_Tc, 'N');
    checkMcpPropertyMultiple(Coatl_GetUcdProperty_Tc, 0xDF,
                             L"Ss"); /* ß -> Ss */
    checkMcpPropertyMultiple(Coatl_GetUcdProperty_Tc, 0x01F0,
                             L"J\u030C"); /* ǰ -> J◌̌  */
    checkMcpPropertySingle(Coatl_GetUcdProperty_Tc, 0x03BC,
                           0x039C); /* μ -> Μ */
    checkMcpPropertySingle(Coatl_GetUcdProperty_Tc, 0x0133,
                           0x0132); /* ĳ -> Ĳ */
    checkMcpPropertySingle(Coatl_GetUcdProperty_Tc, 0x01C9,
                           0x01C8);                            /* ǉ -> ǈ */
    checkMcpPropertyIdentity(Coatl_GetUcdProperty_Tc, 0x01C8); /* ǈ */
}
PICOTEST_CASE(testUcdPropertyUc, colibriFixture) {
    checkMcpPropertyIdentity(Coatl_GetUcdProperty_Uc, 'M');
    checkMcpPropertySingle(Coatl_GetUcdProperty_Uc, 'n', 'N');
    checkMcpPropertyMultiple(Coatl_GetUcdProperty_Uc, 0xDF,
                             L"SS"); /* ß -> SS */
    checkMcpPropertySingle(Coatl_GetUcdProperty_Uc, 0x03BC,
                           0x039C); /* μ -> Μ */
    checkMcpPropertySingle(Coatl_GetUcdProperty_Uc, 0x0133,
                           0x0132); /* ĳ -> Ĳ */
    checkMcpPropertySingle(Coatl_GetUcdProperty_Uc, 0x01C9,
                           0x01C7); /* ǉ -> Ǉ */
    checkMcpPropertySingle(Coatl_GetUcdProperty_Uc, 0x01C8,
                           0x01C7); /* ǈ -> Ǉ */
    checkMcpPropertySingle(Coatl_GetUcdProperty_Uc, 0x01C8,
                           0x01C7); /* ǈ -> Ǉ */
}

PICOTEST_SUITE(testUcdMiscellaneousProperties, testUcdPropertyBmg,
               testUcdPropertyBpb, testUcdPropertyScx);
PICOTEST_CASE(testUcdPropertyBmg, colibriFixture) {
    checkCpProperty(Coatl_GetUcdProperty_Bmg, 'A', 'A');
    checkCpProperty(Coatl_GetUcdProperty_Bmg, '(', ')');
    checkCpProperty(Coatl_GetUcdProperty_Bmg, ')', '(');
    checkCpProperty(Coatl_GetUcdProperty_Bmg, 0xAB, 0xBB);     /* « -> » */
    checkCpProperty(Coatl_GetUcdProperty_Bmg, 0x2208, 0x220B); /* ∈ -> ∋ */
}
PICOTEST_CASE(testUcdPropertyBpb, colibriFixture) {
    checkCpProperty(Coatl_GetUcdProperty_Bpb, 'A', 'A');
    checkCpProperty(Coatl_GetUcdProperty_Bpb, '(', ')');
    checkCpProperty(Coatl_GetUcdProperty_Bpb, ')', '(');
    checkCpProperty(Coatl_GetUcdProperty_Bpb, 0xAB, 0xAB);     /* « */
    checkCpProperty(Coatl_GetUcdProperty_Bpb, 0x0F3A, 0x0F3B); /* ༺ -> ༻ */
}
PICOTEST_CASE(testUcdPropertyScx, colibriFixture) {
    checkEnumListPropertySingle(Coatl_GetUcdProperty_Scx, '\t',
                                COATL_UCD_SC_COMMON);
    checkEnumListPropertySingle(Coatl_GetUcdProperty_Scx, '!',
                                COATL_UCD_SC_COMMON);
    checkEnumListPropertySingle(Coatl_GetUcdProperty_Scx, 'A',
                                COATL_UCD_SC_LATIN);
    checkEnumListPropertySingle(Coatl_GetUcdProperty_Scx, 0xB5,
                                COATL_UCD_SC_COMMON); /* µ */
    checkEnumListPropertySingle(Coatl_GetUcdProperty_Scx, 0x03BC,
                                COATL_UCD_SC_GREEK); /* μ */
    checkEnumListPropertySingle(Coatl_GetUcdProperty_Scx, 0x0F3A,
                                COATL_UCD_SC_TIBETAN); /* ༺ */
    checkEnumListPropertyMultiple(Coatl_GetUcdProperty_Scx, 0x0663,
                                  COATL_UCD_SC_ARABIC, COATL_UCD_SC_YEZIDI,
                                  COATL_UCD_SC_THAANA, NULL); /* ٣ */
}

PICOTEST_SUITE(testUcdCatalogProperties, testUcdPropertyAge, testUcdPropertyBlk,
               testUcdPropertySc);
PICOTEST_CASE(testUcdPropertyAge, colibriFixture) {
    PICOTEST_VERIFY(Coatl_GetUcdProperty_Age('A') == COATL_UCD_AGE_V1_1);
    PICOTEST_VERIFY(Coatl_GetUcdProperty_Age(0x0220) == COATL_UCD_AGE_V3_2);
    PICOTEST_VERIFY(Coatl_GetUcdProperty_Age(0x0221) == COATL_UCD_AGE_V4_0);
    PICOTEST_VERIFY(Coatl_GetUcdProperty_Age(0x08BE) == COATL_UCD_AGE_V13_0);
    PICOTEST_VERIFY(Coatl_GetUcdProperty_Age(0x0378) ==
                    COATL_UCD_AGE_UNASSIGNED);
}
PICOTEST_CASE(testUcdPropertyBlk, colibriFixture) {
    PICOTEST_VERIFY(Coatl_GetUcdProperty_Blk('A') == COATL_UCD_BLK_ASCII);
    PICOTEST_VERIFY(Coatl_GetUcdProperty_Blk(' ') == COATL_UCD_BLK_ASCII);
    PICOTEST_VERIFY(Coatl_GetUcdProperty_Blk(0xE9) ==
                    COATL_UCD_BLK_LATIN_1); /* é */
    PICOTEST_VERIFY(Coatl_GetUcdProperty_Blk(0xE9) ==
                    COATL_UCD_BLK_LATIN_1); /* é */
    PICOTEST_VERIFY(Coatl_GetUcdProperty_Blk(0x0628) ==
                    COATL_UCD_BLK_ARABIC); /* ب */
}
PICOTEST_CASE(testUcdPropertySc, colibriFixture) {
    PICOTEST_VERIFY(Coatl_GetUcdProperty_Sc('\t') == COATL_UCD_SC_COMMON);
    PICOTEST_VERIFY(Coatl_GetUcdProperty_Sc('!') == COATL_UCD_SC_COMMON);
    PICOTEST_VERIFY(Coatl_GetUcdProperty_Sc('A') == COATL_UCD_SC_LATIN);
    PICOTEST_VERIFY(Coatl_GetUcdProperty_Sc(0xB5) ==
                    COATL_UCD_SC_COMMON); /* µ */
    PICOTEST_VERIFY(Coatl_GetUcdProperty_Sc(0x03BC) ==
                    COATL_UCD_SC_GREEK); /* μ */
    PICOTEST_VERIFY(Coatl_GetUcdProperty_Sc(0x0F3A) ==
                    COATL_UCD_SC_TIBETAN); /* ༺ */
    PICOTEST_VERIFY(Coatl_GetUcdProperty_Sc(0x0663) ==
                    COATL_UCD_SC_ARABIC); /* ٣ */
}

PICOTEST_SUITE(testUcdEnumeratedProperties, testUcdPropertyBc,
               testUcdPropertyBpt, testUcdPropertyCcc, testUcdPropertyDt,
               testUcdPropertyEa, testUcdPropertyGc, testUcdPropertyGCB,
               testUcdPropertyHst, testUcdPropertyInPC, testUcdPropertyInSC,
               testUcdPropertyJg, testUcdPropertyJt, testUcdPropertyLb,
               testUcdPropertyNFC_QC, testUcdPropertyNFD_QC,
               testUcdPropertyNFKC_QC, testUcdPropertyNFKD_QC,
               testUcdPropertyNt, testUcdPropertySB, testUcdPropertyVo,
               testUcdPropertyWB);
PICOTEST_CASE(testUcdPropertyBc, colibriFixture) {
    PICOTEST_VERIFY(Coatl_GetUcdProperty_Bc(' ') == COATL_UCD_BC_WHITE_SPACE);
    PICOTEST_VERIFY(Coatl_GetUcdProperty_Bc('A') == COATL_UCD_BC_LEFT_TO_RIGHT);
    PICOTEST_VERIFY(Coatl_GetUcdProperty_Bc(0x0629) ==
                    COATL_UCD_BC_ARABIC_LETTER); /* ة */
    PICOTEST_VERIFY(Coatl_GetUcdProperty_Bc(0x0663) ==
                    COATL_UCD_BC_ARABIC_NUMBER); /* ٣ */
}
PICOTEST_CASE(testUcdPropertyBpt, colibriFixture) {
    PICOTEST_VERIFY(Coatl_GetUcdProperty_Bpt('A') == COATL_UCD_BPT_NONE);
    PICOTEST_VERIFY(Coatl_GetUcdProperty_Bpt('(') == COATL_UCD_BPT_OPEN);
    PICOTEST_VERIFY(Coatl_GetUcdProperty_Bpt(')') == COATL_UCD_BPT_CLOSE);
    PICOTEST_VERIFY(Coatl_GetUcdProperty_Bpt(0x169B) ==
                    COATL_UCD_BPT_OPEN); /* ᚛ */
    PICOTEST_VERIFY(Coatl_GetUcdProperty_Bpt(0x169C) ==
                    COATL_UCD_BPT_CLOSE); /* ᚜ */
}
PICOTEST_CASE(testUcdPropertyCcc, colibriFixture) {
    PICOTEST_VERIFY(Coatl_GetUcdProperty_Ccc('A') == COATL_UCD_CCC_0);
    PICOTEST_VERIFY(Coatl_GetUcdProperty_Ccc(0x0303) ==
                    COATL_UCD_CCC_ABOVE); /* ◌̃  */
    PICOTEST_VERIFY(Coatl_GetUcdProperty_Ccc(0x0334) ==
                    COATL_UCD_CCC_OVERLAY); /* ◌̴  */
    PICOTEST_VERIFY(Coatl_GetUcdProperty_Ccc(0x0327) ==
                    COATL_UCD_CCC_ATTACHED_BELOW); /* ◌̧  */
}
PICOTEST_CASE(testUcdPropertyDt, colibriFixture) {
    PICOTEST_VERIFY(Coatl_GetUcdProperty_Dt(' ') == COATL_UCD_DT_NONE);
    PICOTEST_VERIFY(Coatl_GetUcdProperty_Dt('A') == COATL_UCD_DT_NONE);
    PICOTEST_VERIFY(Coatl_GetUcdProperty_Dt(0xA0) == COATL_UCD_DT_NOBREAK);
    PICOTEST_VERIFY(Coatl_GetUcdProperty_Dt(0xCF) ==
                    COATL_UCD_DT_CANONICAL); /* Ï */
    PICOTEST_VERIFY(Coatl_GetUcdProperty_Dt(0xBD) ==
                    COATL_UCD_DT_FRACTION); /* ½ */
}
PICOTEST_CASE(testUcdPropertyEa, colibriFixture) {
    PICOTEST_VERIFY(Coatl_GetUcdProperty_Ea('\t') == COATL_UCD_EA_NEUTRAL);
    PICOTEST_VERIFY(Coatl_GetUcdProperty_Ea(' ') == COATL_UCD_EA_NARROW);
    PICOTEST_VERIFY(Coatl_GetUcdProperty_Ea('A') == COATL_UCD_EA_NARROW);
    PICOTEST_VERIFY(Coatl_GetUcdProperty_Ea(0x111A) ==
                    COATL_UCD_EA_WIDE); /* ᄚ */
    PICOTEST_VERIFY(Coatl_GetUcdProperty_Ea(0xFFE6) ==
                    COATL_UCD_EA_FULLWIDTH); /* ￦ */
}
PICOTEST_CASE(testUcdPropertyGc, colibriFixture) {
    PICOTEST_VERIFY(Coatl_GetUcdProperty_Gc('\t') == COATL_UCD_GC_CONTROL);
    PICOTEST_VERIFY(Coatl_GetUcdProperty_Gc(' ') ==
                    COATL_UCD_GC_SPACE_SEPARATOR);
    PICOTEST_VERIFY(Coatl_GetUcdProperty_Gc('!') ==
                    COATL_UCD_GC_OTHER_PUNCTUATION);
    PICOTEST_VERIFY(Coatl_GetUcdProperty_Gc('A') ==
                    COATL_UCD_GC_UPPERCASE_LETTER);
    PICOTEST_VERIFY(Coatl_GetUcdProperty_Gc('b') ==
                    COATL_UCD_GC_LOWERCASE_LETTER);
    PICOTEST_VERIFY(Coatl_GetUcdProperty_Gc(0x01C8) ==
                    COATL_UCD_GC_TITLECASE_LETTER); /* ǈ */
    PICOTEST_VERIFY(Coatl_GetUcdProperty_Gc(0x0378) == COATL_UCD_GC_UNASSIGNED);
}
PICOTEST_CASE(testUcdPropertyGCB, colibriFixture) {
    PICOTEST_VERIFY(Coatl_GetUcdProperty_GCB('\b') == COATL_UCD_GCB_CONTROL);
    PICOTEST_VERIFY(Coatl_GetUcdProperty_GCB('\n') == COATL_UCD_GCB_LF);
    PICOTEST_VERIFY(Coatl_GetUcdProperty_GCB('\r') == COATL_UCD_GCB_CR);
    PICOTEST_VERIFY(Coatl_GetUcdProperty_GCB(0x0300) ==
                    COATL_UCD_GCB_EXTEND); /* ◌̀  */
}
PICOTEST_CASE(testUcdPropertyHst, colibriFixture) {
    PICOTEST_VERIFY(Coatl_GetUcdProperty_Hst('A') ==
                    COATL_UCD_HST_NOT_APPLICABLE);
    PICOTEST_VERIFY(Coatl_GetUcdProperty_Hst(0x1163) ==
                    COATL_UCD_HST_VOWEL_JAMO); /* ᅣ */
    PICOTEST_VERIFY(Coatl_GetUcdProperty_Hst(0x11AD) ==
                    COATL_UCD_HST_TRAILING_JAMO); /* ᆭ */
}
PICOTEST_CASE(testUcdPropertyInPC, colibriFixture) {
    PICOTEST_VERIFY(Coatl_GetUcdProperty_InPC('A') == COATL_UCD_INPC_NA);
    PICOTEST_VERIFY(Coatl_GetUcdProperty_InPC(0x0900) ==
                    COATL_UCD_INPC_TOP); /* ◌ऀ */
    PICOTEST_VERIFY(Coatl_GetUcdProperty_InPC(0x10A01) ==
                    COATL_UCD_INPC_OVERSTRUCK); /* ◌𐨁 */
}
PICOTEST_CASE(testUcdPropertyInSC, colibriFixture) {
    PICOTEST_VERIFY(Coatl_GetUcdProperty_InSC('A') == COATL_UCD_INSC_OTHER);
    PICOTEST_VERIFY(Coatl_GetUcdProperty_InSC('3') == COATL_UCD_INSC_NUMBER);
    PICOTEST_VERIFY(Coatl_GetUcdProperty_InSC(0xA9D9) ==
                    COATL_UCD_INSC_NUMBER); /* ꧙ */
    PICOTEST_VERIFY(Coatl_GetUcdProperty_InSC('-') ==
                    COATL_UCD_INSC_CONSONANT_PLACEHOLDER);
    PICOTEST_VERIFY(Coatl_GetUcdProperty_InSC(0x0905) ==
                    COATL_UCD_INSC_VOWEL_INDEPENDENT); /* अ */
}
PICOTEST_CASE(testUcdPropertyJg, colibriFixture) {
    PICOTEST_VERIFY(Coatl_GetUcdProperty_Jg('A') ==
                    COATL_UCD_JG_NO_JOINING_GROUP);
    PICOTEST_VERIFY(Coatl_GetUcdProperty_Jg(0x08AC) ==
                    COATL_UCD_JG_ROHINGYA_YEH); /* ࢬ */
}
PICOTEST_CASE(testUcdPropertyJt, colibriFixture) {
    PICOTEST_VERIFY(Coatl_GetUcdProperty_Jt('A') == COATL_UCD_JT_NON_JOINING);
    PICOTEST_VERIFY(Coatl_GetUcdProperty_Jt(0xAD) ==
                    COATL_UCD_JT_TRANSPARENT); /* SOFT HYPHEN*/
    PICOTEST_VERIFY(Coatl_GetUcdProperty_Jt(0x0629) ==
                    COATL_UCD_JT_RIGHT_JOINING); /* ة */
}
PICOTEST_CASE(testUcdPropertyLb, colibriFixture) {
    PICOTEST_VERIFY(Coatl_GetUcdProperty_Lb('\t') == COATL_UCD_LB_BREAK_AFTER);
    PICOTEST_VERIFY(Coatl_GetUcdProperty_Lb('\n') == COATL_UCD_LB_LINE_FEED);
    PICOTEST_VERIFY(Coatl_GetUcdProperty_Lb('\f') ==
                    COATL_UCD_LB_MANDATORY_BREAK);
    PICOTEST_VERIFY(Coatl_GetUcdProperty_Lb('A') == COATL_UCD_LB_ALPHABETIC);
    PICOTEST_VERIFY(Coatl_GetUcdProperty_Lb(' ') == COATL_UCD_LB_SPACE);
    PICOTEST_VERIFY(Coatl_GetUcdProperty_Lb(']') ==
                    COATL_UCD_LB_CLOSE_PARENTHESIS);
    PICOTEST_VERIFY(Coatl_GetUcdProperty_Lb(0x05D0) ==
                    COATL_UCD_LB_HEBREW_LETTER); /* א */
}
PICOTEST_CASE(testUcdPropertyNFC_QC, colibriFixture) {
    PICOTEST_VERIFY(Coatl_GetUcdProperty_NFC_QC('A') == COATL_UCD_NFC_QC_YES);
    PICOTEST_VERIFY(Coatl_GetUcdProperty_NFC_QC(0x0958) ==
                    COATL_UCD_NFC_QC_NO); /* क़ */
    PICOTEST_VERIFY(Coatl_GetUcdProperty_NFC_QC(0x0302) ==
                    COATL_UCD_NFC_QC_MAYBE); /* ◌̂  */
}
PICOTEST_CASE(testUcdPropertyNFD_QC, colibriFixture) {
    PICOTEST_VERIFY(Coatl_GetUcdProperty_NFD_QC('A') == COATL_UCD_NFD_QC_YES);
    PICOTEST_VERIFY(Coatl_GetUcdProperty_NFD_QC(0x0958) ==
                    COATL_UCD_NFD_QC_NO); /* क़ */
}
PICOTEST_CASE(testUcdPropertyNFKC_QC, colibriFixture) {
    PICOTEST_VERIFY(Coatl_GetUcdProperty_NFKC_QC('A') == COATL_UCD_NFKC_QC_YES);
    PICOTEST_VERIFY(Coatl_GetUcdProperty_NFKC_QC(0x0958) ==
                    COATL_UCD_NFKC_QC_NO); /* क़ */
    PICOTEST_VERIFY(Coatl_GetUcdProperty_NFKC_QC(0x0302) ==
                    COATL_UCD_NFKC_QC_MAYBE); /* ◌̂  */
}
PICOTEST_CASE(testUcdPropertyNFKD_QC, colibriFixture) {
    PICOTEST_VERIFY(Coatl_GetUcdProperty_NFKD_QC('A') == COATL_UCD_NFKD_QC_YES);
    PICOTEST_VERIFY(Coatl_GetUcdProperty_NFKD_QC(0x0958) ==
                    COATL_UCD_NFKD_QC_NO); /* क़ */
}
PICOTEST_CASE(testUcdPropertyNt, colibriFixture) {
    PICOTEST_VERIFY(Coatl_GetUcdProperty_Nt('A') == COATL_UCD_NT_NONE);
    PICOTEST_VERIFY(Coatl_GetUcdProperty_Nt('1') == COATL_UCD_NT_DECIMAL);
    PICOTEST_VERIFY(Coatl_GetUcdProperty_Nt(0xB2) ==
                    COATL_UCD_NT_DIGIT); /* ² */
    PICOTEST_VERIFY(Coatl_GetUcdProperty_Nt(0x0664) ==
                    COATL_UCD_NT_DECIMAL); /* ٤ */
    PICOTEST_VERIFY(Coatl_GetUcdProperty_Nt(0x136F) ==
                    COATL_UCD_NT_DIGIT); /* ፯ */
    PICOTEST_VERIFY(Coatl_GetUcdProperty_Nt(0x1373) ==
                    COATL_UCD_NT_NUMERIC); /* ፳ */
}
PICOTEST_CASE(testUcdPropertySB, colibriFixture) {
    PICOTEST_VERIFY(Coatl_GetUcdProperty_SB('\t') == COATL_UCD_SB_SP);
    PICOTEST_VERIFY(Coatl_GetUcdProperty_SB('\'') == COATL_UCD_SB_CLOSE);
    PICOTEST_VERIFY(Coatl_GetUcdProperty_SB('.') == COATL_UCD_SB_ATERM);
    PICOTEST_VERIFY(Coatl_GetUcdProperty_SB('!') == COATL_UCD_SB_STERM);
    PICOTEST_VERIFY(Coatl_GetUcdProperty_SB(0x0700) ==
                    COATL_UCD_SB_STERM); /* ܀ */
}
PICOTEST_CASE(testUcdPropertyVo, colibriFixture) {
    PICOTEST_VERIFY(Coatl_GetUcdProperty_Vo('\t') == COATL_UCD_VO_ROTATED);
    PICOTEST_VERIFY(Coatl_GetUcdProperty_Vo('A') == COATL_UCD_VO_ROTATED);
    PICOTEST_VERIFY(Coatl_GetUcdProperty_Vo(0xA9) ==
                    COATL_UCD_VO_UPRIGHT); /* © */
    PICOTEST_VERIFY(Coatl_GetUcdProperty_Vo(0x2329) ==
                    COATL_UCD_VO_TRANSFORMED_ROTATED); /* 〈 */
    PICOTEST_VERIFY(Coatl_GetUcdProperty_Vo(0x3041) ==
                    COATL_UCD_VO_TRANSFORMED_UPRIGHT); /* ぁ */
}
PICOTEST_CASE(testUcdPropertyWB, colibriFixture) {
    PICOTEST_VERIFY(Coatl_GetUcdProperty_WB('\n') == COATL_UCD_WB_LF);
    PICOTEST_VERIFY(Coatl_GetUcdProperty_WB('\f') == COATL_UCD_WB_NEWLINE);
    PICOTEST_VERIFY(Coatl_GetUcdProperty_WB(' ') == COATL_UCD_WB_WSEGSPACE);
    PICOTEST_VERIFY(Coatl_GetUcdProperty_WB('.') == COATL_UCD_WB_MIDNUMLET);
    PICOTEST_VERIFY(Coatl_GetUcdProperty_WB('@') == COATL_UCD_WB_OTHER);
    PICOTEST_VERIFY(Coatl_GetUcdProperty_WB('A') == COATL_UCD_WB_ALETTER);
    PICOTEST_VERIFY(Coatl_GetUcdProperty_WB(0x3032) ==
                    COATL_UCD_WB_KATAKANA); /* 〲 */
}

PICOTEST_SUITE(testUcdBinaryProperties, testUcdPropertyAHex,
               testUcdPropertyAlpha, testUcdPropertyBidi_C,
               testUcdPropertyBidi_M, testUcdPropertyCased, testUcdPropertyCE,
               testUcdPropertyCI, testUcdPropertyComp_Ex, testUcdPropertyCWCF,
               testUcdPropertyCWCM, testUcdPropertyCWKCF, testUcdPropertyCWL,
               testUcdPropertyCWT, testUcdPropertyCWU, testUcdPropertyDash,
               testUcdPropertyDep, testUcdPropertyDI, testUcdPropertyDia,
               testUcdPropertyEBase, testUcdPropertyEComp, testUcdPropertyEMod,
               testUcdPropertyEmoji, testUcdPropertyEPres, testUcdPropertyExt,
               testUcdPropertyExtPict, testUcdPropertyGr_Base,
               testUcdPropertyGr_Ext, testUcdPropertyHex, testUcdPropertyIDC,
               testUcdPropertyIdeo, testUcdPropertyIDS, testUcdPropertyIDSB,
               testUcdPropertyIDST, testUcdPropertyJoin_C, testUcdPropertyLOE,
               testUcdPropertyLower, testUcdPropertyMath, testUcdPropertyNChar,
               testUcdPropertyOAlpha, testUcdPropertyODI,
               testUcdPropertyOGr_Ext, testUcdPropertyOIDC, testUcdPropertyOIDS,
               testUcdPropertyOLower, testUcdPropertyOMath,
               testUcdPropertyOUpper, testUcdPropertyPat_Syn,
               testUcdPropertyPat_WS, testUcdPropertyPCM, testUcdPropertyQMark,
               testUcdPropertyRadical, testUcdPropertyRI, testUcdPropertySD,
               testUcdPropertySTerm, testUcdPropertyTerm, testUcdPropertyUIdeo,
               testUcdPropertyUpper, testUcdPropertyVS, testUcdPropertyWSpace,
               testUcdPropertyXIDC, testUcdPropertyXIDS);
PICOTEST_CASE(testUcdPropertyAHex, colibriFixture) {
    PICOTEST_VERIFY(!Coatl_GetUcdProperty_AHex('/'));
    PICOTEST_VERIFY(Coatl_GetUcdProperty_AHex('0'));
    PICOTEST_VERIFY(Coatl_GetUcdProperty_AHex('9'));
    PICOTEST_VERIFY(!Coatl_GetUcdProperty_AHex(';'));
    PICOTEST_VERIFY(!Coatl_GetUcdProperty_AHex('@'));
    PICOTEST_VERIFY(Coatl_GetUcdProperty_AHex('A'));
    PICOTEST_VERIFY(Coatl_GetUcdProperty_AHex('F'));
    PICOTEST_VERIFY(!Coatl_GetUcdProperty_AHex('G'));
    PICOTEST_VERIFY(!Coatl_GetUcdProperty_AHex('`'));
    PICOTEST_VERIFY(Coatl_GetUcdProperty_AHex('a'));
    PICOTEST_VERIFY(Coatl_GetUcdProperty_AHex('f'));
    PICOTEST_VERIFY(!Coatl_GetUcdProperty_AHex('g'));
    PICOTEST_VERIFY(!Coatl_GetUcdProperty_AHex(0xFF11)); /* １ */
}
PICOTEST_CASE(testUcdPropertyAlpha, colibriFixture) {
    PICOTEST_VERIFY(!Coatl_GetUcdProperty_Alpha(' '));
    PICOTEST_VERIFY(Coatl_GetUcdProperty_Alpha('A'));
    PICOTEST_VERIFY(!Coatl_GetUcdProperty_Alpha(0xA9));
    PICOTEST_VERIFY(Coatl_GetUcdProperty_Alpha(0xAA));
    PICOTEST_VERIFY(Coatl_GetUcdProperty_Alpha(0x0345)); /* ◌ͅ  */
}
PICOTEST_CASE(testUcdPropertyBidi_C, colibriFixture) {
    PICOTEST_VERIFY(!Coatl_GetUcdProperty_Bidi_C('A'));
    PICOTEST_VERIFY(
        Coatl_GetUcdProperty_Bidi_C(0x061C)); /* ARABIC LETTER MARK */
}
PICOTEST_CASE(testUcdPropertyBidi_M, colibriFixture) {
    PICOTEST_VERIFY(!Coatl_GetUcdProperty_Bidi_M('A'));
    PICOTEST_VERIFY(Coatl_GetUcdProperty_Bidi_M('('));
    PICOTEST_VERIFY(Coatl_GetUcdProperty_Bidi_M(']'));
    PICOTEST_VERIFY(Coatl_GetUcdProperty_Bidi_M(0x0F3D)); /* ༽ */
}
PICOTEST_CASE(testUcdPropertyCased, colibriFixture) {
    PICOTEST_VERIFY(!Coatl_GetUcdProperty_Cased(' '));
    PICOTEST_VERIFY(Coatl_GetUcdProperty_Cased('A'));
    PICOTEST_VERIFY(Coatl_GetUcdProperty_Cased(0x02B4)); /* ʴ */
}
PICOTEST_CASE(testUcdPropertyCE, colibriFixture) {
    PICOTEST_VERIFY(!Coatl_GetUcdProperty_CE('A'));
    PICOTEST_VERIFY(Coatl_GetUcdProperty_CE(0x0958)); /* क़ */
}
PICOTEST_CASE(testUcdPropertyCI, colibriFixture) {
    PICOTEST_VERIFY(!Coatl_GetUcdProperty_CI('A'));
    PICOTEST_VERIFY(Coatl_GetUcdProperty_CI(':'));
    PICOTEST_VERIFY(Coatl_GetUcdProperty_CI(0x055F)); /* ՟ */
}
PICOTEST_CASE(testUcdPropertyComp_Ex, colibriFixture) {
    PICOTEST_VERIFY(!Coatl_GetUcdProperty_Comp_Ex('A'));
    PICOTEST_VERIFY(Coatl_GetUcdProperty_Comp_Ex(0x0341)); /* ◌́ */
}
PICOTEST_CASE(testUcdPropertyCWCF, colibriFixture) {
    PICOTEST_VERIFY(!Coatl_GetUcdProperty_CWCF('!'));
    PICOTEST_VERIFY(Coatl_GetUcdProperty_CWCF('A'));
    PICOTEST_VERIFY(!Coatl_GetUcdProperty_CWCF('a'));
    PICOTEST_VERIFY(!Coatl_GetUcdProperty_CWCF(0xA0));   /* NO-BREAK SPACE */
    PICOTEST_VERIFY(Coatl_GetUcdProperty_CWCF(0xB5));    /* µ */
    PICOTEST_VERIFY(!Coatl_GetUcdProperty_CWCF(0x0341)); /* ◌́ */
    PICOTEST_VERIFY(Coatl_GetUcdProperty_CWCF(0x0345));  /* ◌ͅ */
}
PICOTEST_CASE(testUcdPropertyCWCM, colibriFixture) {
    PICOTEST_VERIFY(Coatl_GetUcdProperty_CWCM('A'));
    PICOTEST_VERIFY(!Coatl_GetUcdProperty_CWCM(0xA0)); /* NO-BREAK SPACE */
}
PICOTEST_CASE(testUcdPropertyCWKCF, colibriFixture) {
    PICOTEST_VERIFY(Coatl_GetUcdProperty_CWKCF('A'));
    PICOTEST_VERIFY(Coatl_GetUcdProperty_CWKCF(0xA0)); /* NO-BREAK SPACE */
}
PICOTEST_CASE(testUcdPropertyCWL, colibriFixture) {
    PICOTEST_VERIFY(!Coatl_GetUcdProperty_CWL(' '));
    PICOTEST_VERIFY(Coatl_GetUcdProperty_CWL('A'));
    PICOTEST_VERIFY(!Coatl_GetUcdProperty_CWL('a'));
    PICOTEST_VERIFY(!Coatl_GetUcdProperty_CWL(0x0341)); /* ◌́ */
    PICOTEST_VERIFY(!Coatl_GetUcdProperty_CWL(0x0345)); /* ◌ͅ */
}
PICOTEST_CASE(testUcdPropertyCWT, colibriFixture) {
    PICOTEST_VERIFY(!Coatl_GetUcdProperty_CWT(' '));
    PICOTEST_VERIFY(!Coatl_GetUcdProperty_CWT('A'));
    PICOTEST_VERIFY(Coatl_GetUcdProperty_CWT('a'));
    PICOTEST_VERIFY(Coatl_GetUcdProperty_CWT(0x0133));  /* ĳ */
    PICOTEST_VERIFY(Coatl_GetUcdProperty_CWT(0x01C7));  /* Ǉ */
    PICOTEST_VERIFY(Coatl_GetUcdProperty_CWT(0x01C9));  /* ǉ */
    PICOTEST_VERIFY(!Coatl_GetUcdProperty_CWT(0x01C8)); /* ǈ */
}
PICOTEST_CASE(testUcdPropertyCWU, colibriFixture) {
    PICOTEST_VERIFY(!Coatl_GetUcdProperty_CWU(' '));
    PICOTEST_VERIFY(!Coatl_GetUcdProperty_CWU('A'));
    PICOTEST_VERIFY(Coatl_GetUcdProperty_CWU('a'));
    PICOTEST_VERIFY(Coatl_GetUcdProperty_CWU(0x0133));  /* ĳ */
    PICOTEST_VERIFY(Coatl_GetUcdProperty_CWU(0x01C9));  /* ǉ */
    PICOTEST_VERIFY(Coatl_GetUcdProperty_CWU(0x01C8));  /* ǈ */
    PICOTEST_VERIFY(!Coatl_GetUcdProperty_CWU(0x01C7)); /* Ǉ */
}
PICOTEST_CASE(testUcdPropertyDash, colibriFixture) {
    PICOTEST_VERIFY(!Coatl_GetUcdProperty_Dash('A'));
    PICOTEST_VERIFY(Coatl_GetUcdProperty_Dash('-'));
    PICOTEST_VERIFY(Coatl_GetUcdProperty_Dash(0x058A)); /* ֊ */
}
PICOTEST_CASE(testUcdPropertyDep, colibriFixture) {
    PICOTEST_VERIFY(!Coatl_GetUcdProperty_Dep('A'));
    PICOTEST_VERIFY(Coatl_GetUcdProperty_Dep(0x0149)); /* ŉ */
}
PICOTEST_CASE(testUcdPropertyDI, colibriFixture) {
    PICOTEST_VERIFY(!Coatl_GetUcdProperty_DI('A'));
    PICOTEST_VERIFY(!Coatl_GetUcdProperty_DI('-'));
    PICOTEST_VERIFY(Coatl_GetUcdProperty_DI(0xAD));   /* SOFT HYPHEN */
    PICOTEST_VERIFY(Coatl_GetUcdProperty_DI(0x034F)); /* ◌͏ */
}
PICOTEST_CASE(testUcdPropertyDia, colibriFixture) {
    PICOTEST_VERIFY(!Coatl_GetUcdProperty_Dia('A'));
    PICOTEST_VERIFY(Coatl_GetUcdProperty_Dia('^'));
    PICOTEST_VERIFY(Coatl_GetUcdProperty_Dia(0x0374)); /* ʹ */
}
PICOTEST_CASE(testUcdPropertyEBase, colibriFixture) {
    PICOTEST_VERIFY(!Coatl_GetUcdProperty_EBase('A'));
    PICOTEST_VERIFY(!Coatl_GetUcdProperty_EBase('#'));
    PICOTEST_VERIFY(!Coatl_GetUcdProperty_EBase('*'));
    PICOTEST_VERIFY(Coatl_GetUcdProperty_EBase(0x261D));   /* ☝ */
    PICOTEST_VERIFY(!Coatl_GetUcdProperty_EBase(0x1F1E6)); /* 🇦 */
}
PICOTEST_CASE(testUcdPropertyEComp, colibriFixture) {
    PICOTEST_VERIFY(!Coatl_GetUcdProperty_EComp('A'));
    PICOTEST_VERIFY(Coatl_GetUcdProperty_EComp('#'));
    PICOTEST_VERIFY(Coatl_GetUcdProperty_EComp('*'));
    PICOTEST_VERIFY(Coatl_GetUcdProperty_EComp(0x1F1E6)); /* 🇦 */
}
PICOTEST_CASE(testUcdPropertyEMod, colibriFixture) {
    PICOTEST_VERIFY(!Coatl_GetUcdProperty_EMod('A'));
    PICOTEST_VERIFY(Coatl_GetUcdProperty_EMod(
        0x1F3FB)); /* EMOJI MODIFIER FITZPATRICK TYPE-3 */
}
PICOTEST_CASE(testUcdPropertyEmoji, colibriFixture) {
    PICOTEST_VERIFY(!Coatl_GetUcdProperty_Emoji('A'));
    PICOTEST_VERIFY(Coatl_GetUcdProperty_Emoji('#'));
    PICOTEST_VERIFY(Coatl_GetUcdProperty_Emoji('*'));
    PICOTEST_VERIFY(Coatl_GetUcdProperty_Emoji(0x261D)); /* ☝ */
}
PICOTEST_CASE(testUcdPropertyEPres, colibriFixture) {
    PICOTEST_VERIFY(!Coatl_GetUcdProperty_EPres('A'));
    PICOTEST_VERIFY(!Coatl_GetUcdProperty_EPres(0x261D)); /* ☝ */
    PICOTEST_VERIFY(Coatl_GetUcdProperty_EPres(0x231B));  /* ⌛ */
}
PICOTEST_CASE(testUcdPropertyExt, colibriFixture) {
    PICOTEST_VERIFY(!Coatl_GetUcdProperty_Ext('A'));
    PICOTEST_VERIFY(!Coatl_GetUcdProperty_Ext(':'));
    PICOTEST_VERIFY(Coatl_GetUcdProperty_Ext(0xB7));   /* · */
    PICOTEST_VERIFY(Coatl_GetUcdProperty_Ext(0x02D0)); /* ː */
    PICOTEST_VERIFY(Coatl_GetUcdProperty_Ext(0x0E46)); /* ๆ */
}
PICOTEST_CASE(testUcdPropertyExtPict, colibriFixture) {
    PICOTEST_VERIFY(!Coatl_GetUcdProperty_ExtPict('A'));
    PICOTEST_VERIFY(Coatl_GetUcdProperty_ExtPict(0xA9));   /* © */
    PICOTEST_VERIFY(Coatl_GetUcdProperty_ExtPict(0x203C)); /* ‼ */
    PICOTEST_VERIFY(Coatl_GetUcdProperty_ExtPict(0x2197)); /* ↗ */
    PICOTEST_VERIFY(Coatl_GetUcdProperty_ExtPict(0x231B)); /* ⌛ */
}
PICOTEST_CASE(testUcdPropertyGr_Base, colibriFixture) {
    PICOTEST_VERIFY(!Coatl_GetUcdProperty_Gr_Base('\t'));
    PICOTEST_VERIFY(Coatl_GetUcdProperty_Gr_Base('A'));
    PICOTEST_VERIFY(!Coatl_GetUcdProperty_Gr_Base(0xAD));   /* SOFT HYPHEN */
    PICOTEST_VERIFY(!Coatl_GetUcdProperty_Gr_Base(0x0300)); /* ◌̀  */
}
PICOTEST_CASE(testUcdPropertyGr_Ext, colibriFixture) {
    PICOTEST_VERIFY(!Coatl_GetUcdProperty_Gr_Ext('A'));
    PICOTEST_VERIFY(!Coatl_GetUcdProperty_Gr_Ext('\t'));
    PICOTEST_VERIFY(!Coatl_GetUcdProperty_Gr_Ext(0xAD));  /* SOFT HYPHEN */
    PICOTEST_VERIFY(Coatl_GetUcdProperty_Gr_Ext(0x0300)); /* ◌̀  */
    PICOTEST_VERIFY(Coatl_GetUcdProperty_Gr_Ext(0x09BE)); /* া */
}
PICOTEST_CASE(testUcdPropertyHex, colibriFixture) {
    PICOTEST_VERIFY(!Coatl_GetUcdProperty_Hex('/'));
    PICOTEST_VERIFY(Coatl_GetUcdProperty_Hex('0'));
    PICOTEST_VERIFY(Coatl_GetUcdProperty_Hex('9'));
    PICOTEST_VERIFY(!Coatl_GetUcdProperty_Hex(';'));
    PICOTEST_VERIFY(!Coatl_GetUcdProperty_Hex('@'));
    PICOTEST_VERIFY(Coatl_GetUcdProperty_Hex('A'));
    PICOTEST_VERIFY(Coatl_GetUcdProperty_Hex('F'));
    PICOTEST_VERIFY(!Coatl_GetUcdProperty_Hex('G'));
    PICOTEST_VERIFY(!Coatl_GetUcdProperty_Hex('`'));
    PICOTEST_VERIFY(Coatl_GetUcdProperty_Hex('a'));
    PICOTEST_VERIFY(Coatl_GetUcdProperty_Hex('f'));
    PICOTEST_VERIFY(!Coatl_GetUcdProperty_Hex('g'));
    PICOTEST_VERIFY(Coatl_GetUcdProperty_Hex(0xFF11)); /* １ */
}
PICOTEST_CASE(testUcdPropertyIDC, colibriFixture) {
    PICOTEST_VERIFY(!Coatl_GetUcdProperty_IDC(' '));
    PICOTEST_VERIFY(!Coatl_GetUcdProperty_IDC('!'));
    PICOTEST_VERIFY(Coatl_GetUcdProperty_IDC('A'));
    PICOTEST_VERIFY(Coatl_GetUcdProperty_IDC(0xB7));   /* · */
    PICOTEST_VERIFY(Coatl_GetUcdProperty_IDC(0x037A)); /* ͺ */
    PICOTEST_VERIFY(Coatl_GetUcdProperty_IDC(0x0387)); /* · */
}
PICOTEST_CASE(testUcdPropertyIdeo, colibriFixture) {
    PICOTEST_VERIFY(!Coatl_GetUcdProperty_Ideo('A'));
    PICOTEST_VERIFY(!Coatl_GetUcdProperty_Ideo(0x3005)); /* 々 */
    PICOTEST_VERIFY(Coatl_GetUcdProperty_Ideo(0x3006));  /* 〆 */
    PICOTEST_VERIFY(Coatl_GetUcdProperty_Ideo(0x3400));  /* 㐀 */
}
PICOTEST_CASE(testUcdPropertyIDS, colibriFixture) {
    PICOTEST_VERIFY(!Coatl_GetUcdProperty_IDS(' '));
    PICOTEST_VERIFY(Coatl_GetUcdProperty_IDS('A'));
    PICOTEST_VERIFY(Coatl_GetUcdProperty_IDS(0x037A)); /* ͺ */
    PICOTEST_VERIFY(Coatl_GetUcdProperty_IDS(0x1885)); /* ◌ᢅ */
}
PICOTEST_CASE(testUcdPropertyIDSB, colibriFixture) {
    PICOTEST_VERIFY(!Coatl_GetUcdProperty_IDSB(' '));
    PICOTEST_VERIFY(!Coatl_GetUcdProperty_IDSB('A'));
    PICOTEST_VERIFY(Coatl_GetUcdProperty_IDSB(0x2FF0));  /* ⿰ */
    PICOTEST_VERIFY(!Coatl_GetUcdProperty_IDSB(0x2FF2)); /* ⿲ */
}
PICOTEST_CASE(testUcdPropertyIDST, colibriFixture) {
    PICOTEST_VERIFY(!Coatl_GetUcdProperty_IDST(' '));
    PICOTEST_VERIFY(!Coatl_GetUcdProperty_IDST('A'));
    PICOTEST_VERIFY(!Coatl_GetUcdProperty_IDST(0x2FF0)); /* ⿰ */
    PICOTEST_VERIFY(Coatl_GetUcdProperty_IDST(0x2FF2));  /* ⿲ */
}
PICOTEST_CASE(testUcdPropertyJoin_C, colibriFixture) {
    PICOTEST_VERIFY(!Coatl_GetUcdProperty_Join_C('A'));
    PICOTEST_VERIFY(
        Coatl_GetUcdProperty_Join_C(0x200C)); /* ZERO WIDTH NON-JOINER */
}
PICOTEST_CASE(testUcdPropertyLOE, colibriFixture) {
    PICOTEST_VERIFY(!Coatl_GetUcdProperty_LOE('A'));
    PICOTEST_VERIFY(Coatl_GetUcdProperty_LOE(0x0E44));  /* ไ */
    PICOTEST_VERIFY(!Coatl_GetUcdProperty_LOE(0x0E45)); /* ๅ */
}
PICOTEST_CASE(testUcdPropertyLower, colibriFixture) {
    PICOTEST_VERIFY(!Coatl_GetUcdProperty_Lower(' '));
    PICOTEST_VERIFY(!Coatl_GetUcdProperty_Lower('A'));
    PICOTEST_VERIFY(Coatl_GetUcdProperty_Lower('a'));
    PICOTEST_VERIFY(Coatl_GetUcdProperty_Lower(0xAA));    /* ª */
    PICOTEST_VERIFY(Coatl_GetUcdProperty_Lower(0xDF));    /* ß */
    PICOTEST_VERIFY(!Coatl_GetUcdProperty_Lower(0x0182)); /* Ƃ */
    PICOTEST_VERIFY(Coatl_GetUcdProperty_Lower(0x0183));  /* ƃ */
}
PICOTEST_CASE(testUcdPropertyMath, colibriFixture) {
    PICOTEST_VERIFY(!Coatl_GetUcdProperty_Math('A'));
    PICOTEST_VERIFY(Coatl_GetUcdProperty_Math('+'));
    PICOTEST_VERIFY(Coatl_GetUcdProperty_Math('='));
    PICOTEST_VERIFY(Coatl_GetUcdProperty_Math(0xB1));   /* ± */
    PICOTEST_VERIFY(Coatl_GetUcdProperty_Math(0x03D0)); /* ϐ */
}
PICOTEST_CASE(testUcdPropertyNChar, colibriFixture) {
    PICOTEST_VERIFY(!Coatl_GetUcdProperty_NChar('A'));
    PICOTEST_VERIFY(Coatl_GetUcdProperty_NChar(0xFFFE));
    PICOTEST_VERIFY(Coatl_GetUcdProperty_NChar(0xFFFF));
}
PICOTEST_CASE(testUcdPropertyOAlpha, colibriFixture) {
    PICOTEST_VERIFY(!Coatl_GetUcdProperty_OAlpha(' '));
    PICOTEST_VERIFY(!Coatl_GetUcdProperty_OAlpha('A'));
    PICOTEST_VERIFY(!Coatl_GetUcdProperty_OAlpha(0xA9));
    PICOTEST_VERIFY(!Coatl_GetUcdProperty_OAlpha(0xAA));
    PICOTEST_VERIFY(Coatl_GetUcdProperty_OAlpha(0x0345)); /* ◌ͅ  */
}
PICOTEST_CASE(testUcdPropertyODI, colibriFixture) {
    PICOTEST_VERIFY(!Coatl_GetUcdProperty_ODI('A'));
    PICOTEST_VERIFY(!Coatl_GetUcdProperty_ODI('-'));
    PICOTEST_VERIFY(!Coatl_GetUcdProperty_ODI(0xAD));  /* SOFT HYPHEN */
    PICOTEST_VERIFY(Coatl_GetUcdProperty_ODI(0x034F)); /* ◌͏ */
}
PICOTEST_CASE(testUcdPropertyOGr_Ext, colibriFixture) {
    PICOTEST_VERIFY(!Coatl_GetUcdProperty_OGr_Ext('A'));
    PICOTEST_VERIFY(!Coatl_GetUcdProperty_OGr_Ext('\t'));
    PICOTEST_VERIFY(!Coatl_GetUcdProperty_OGr_Ext(0xAD));   /* SOFT HYPHEN */
    PICOTEST_VERIFY(!Coatl_GetUcdProperty_OGr_Ext(0x0300)); /* ◌̀  */
    PICOTEST_VERIFY(Coatl_GetUcdProperty_OGr_Ext(0x09BE));  /* া */
}
PICOTEST_CASE(testUcdPropertyOIDC, colibriFixture) {
    PICOTEST_VERIFY(!Coatl_GetUcdProperty_OIDC(' '));
    PICOTEST_VERIFY(!Coatl_GetUcdProperty_OIDC('A'));
    PICOTEST_VERIFY(Coatl_GetUcdProperty_OIDC(0xB7));   /* · */
    PICOTEST_VERIFY(Coatl_GetUcdProperty_OIDC(0x0387)); /* · */
}
PICOTEST_CASE(testUcdPropertyOIDS, colibriFixture) {
    PICOTEST_VERIFY(!Coatl_GetUcdProperty_OIDS(' '));
    PICOTEST_VERIFY(!Coatl_GetUcdProperty_OIDS('A'));
    PICOTEST_VERIFY(Coatl_GetUcdProperty_OIDS(0x1885)); /* ◌ᢅ */
}
PICOTEST_CASE(testUcdPropertyOLower, colibriFixture) {
    PICOTEST_VERIFY(!Coatl_GetUcdProperty_OLower(' '));
    PICOTEST_VERIFY(!Coatl_GetUcdProperty_OLower('A'));
    PICOTEST_VERIFY(!Coatl_GetUcdProperty_OLower('a'));
    PICOTEST_VERIFY(Coatl_GetUcdProperty_OLower(0xAA));    /* ª */
    PICOTEST_VERIFY(!Coatl_GetUcdProperty_OLower(0xDF));   /* ß */
    PICOTEST_VERIFY(!Coatl_GetUcdProperty_OLower(0x0182)); /* Ƃ */
    PICOTEST_VERIFY(!Coatl_GetUcdProperty_OLower(0x0183)); /* ƃ */
}
PICOTEST_CASE(testUcdPropertyOMath, colibriFixture) {
    PICOTEST_VERIFY(!Coatl_GetUcdProperty_OMath('A'));
    PICOTEST_VERIFY(!Coatl_GetUcdProperty_OMath('+'));
    PICOTEST_VERIFY(!Coatl_GetUcdProperty_OMath('='));
    PICOTEST_VERIFY(!Coatl_GetUcdProperty_OMath(0xB1));  /* ± */
    PICOTEST_VERIFY(Coatl_GetUcdProperty_OMath(0x03D0)); /* ϐ */
}
PICOTEST_CASE(testUcdPropertyOUpper, colibriFixture) {
    PICOTEST_VERIFY(!Coatl_GetUcdProperty_OUpper(' '));
    PICOTEST_VERIFY(!Coatl_GetUcdProperty_OUpper('A'));
    PICOTEST_VERIFY(!Coatl_GetUcdProperty_OUpper('a'));
    PICOTEST_VERIFY(!Coatl_GetUcdProperty_OUpper(0xAA));   /* ª */
    PICOTEST_VERIFY(!Coatl_GetUcdProperty_OUpper(0xDF));   /* ß */
    PICOTEST_VERIFY(!Coatl_GetUcdProperty_OUpper(0x0182)); /* Ƃ */
    PICOTEST_VERIFY(Coatl_GetUcdProperty_OUpper(0x2163));  /* Ⅳ */
}
PICOTEST_CASE(testUcdPropertyPat_Syn, colibriFixture) {
    PICOTEST_VERIFY(Coatl_GetUcdProperty_Pat_Syn('!'));
    PICOTEST_VERIFY(!Coatl_GetUcdProperty_Pat_Syn('A'));
    PICOTEST_VERIFY(Coatl_GetUcdProperty_Pat_Syn(0xFE46)); /* ﹆ */
}
PICOTEST_CASE(testUcdPropertyPat_WS, colibriFixture) {
    PICOTEST_VERIFY(Coatl_GetUcdProperty_Pat_WS('\t'));
    PICOTEST_VERIFY(Coatl_GetUcdProperty_Pat_WS(' '));
    PICOTEST_VERIFY(!Coatl_GetUcdProperty_Pat_WS('A'));
    PICOTEST_VERIFY(Coatl_GetUcdProperty_Pat_WS(0x85));   /* NEXT LINE */
    PICOTEST_VERIFY(Coatl_GetUcdProperty_Pat_WS(0x2028)); /* LINE SEPARATOR */
    PICOTEST_VERIFY(
        !Coatl_GetUcdProperty_Pat_WS(0x3000)); /* IDEOGRAPHIC SPACE */
}
PICOTEST_CASE(testUcdPropertyPCM, colibriFixture) {
    PICOTEST_VERIFY(!Coatl_GetUcdProperty_PCM('A'));
    PICOTEST_VERIFY(Coatl_GetUcdProperty_PCM(0x0600)); /* ARABIC NUMBER SIGN */
}
PICOTEST_CASE(testUcdPropertyQMark, colibriFixture) {
    PICOTEST_VERIFY(!Coatl_GetUcdProperty_QMark('A'));
    PICOTEST_VERIFY(Coatl_GetUcdProperty_QMark('"'));
    PICOTEST_VERIFY(Coatl_GetUcdProperty_QMark(0x2018)); /* ‘ */
}
PICOTEST_CASE(testUcdPropertyRadical, colibriFixture) {
    PICOTEST_VERIFY(!Coatl_GetUcdProperty_Radical('A'));
    PICOTEST_VERIFY(Coatl_GetUcdProperty_Radical(0x2E8E)); /* ⺎ */
}
PICOTEST_CASE(testUcdPropertyRI, colibriFixture) {
    PICOTEST_VERIFY(!Coatl_GetUcdProperty_RI('A'));
    PICOTEST_VERIFY(Coatl_GetUcdProperty_RI(0x1F1E6)); /* 🇦 */
}
PICOTEST_CASE(testUcdPropertySD, colibriFixture) {
    PICOTEST_VERIFY(!Coatl_GetUcdProperty_SD('A'));
    PICOTEST_VERIFY(!Coatl_GetUcdProperty_SD('I'));
    PICOTEST_VERIFY(Coatl_GetUcdProperty_SD('i'));
    PICOTEST_VERIFY(Coatl_GetUcdProperty_SD(0x012F));  /* į */
    PICOTEST_VERIFY(!Coatl_GetUcdProperty_SD(0x0130)); /* İ */
}
PICOTEST_CASE(testUcdPropertySTerm, colibriFixture) {
    PICOTEST_VERIFY(!Coatl_GetUcdProperty_STerm('A'));
    PICOTEST_VERIFY(Coatl_GetUcdProperty_STerm('.'));
    PICOTEST_VERIFY(!Coatl_GetUcdProperty_STerm(','));
    PICOTEST_VERIFY(!Coatl_GetUcdProperty_STerm(0x037E)); /* ; */
    PICOTEST_VERIFY(!Coatl_GetUcdProperty_STerm(0x061B)); /* ; */
    PICOTEST_VERIFY(Coatl_GetUcdProperty_STerm(0x061E));  /* ؞ */
}
PICOTEST_CASE(testUcdPropertyTerm, colibriFixture) {
    PICOTEST_VERIFY(!Coatl_GetUcdProperty_Term('A'));
    PICOTEST_VERIFY(Coatl_GetUcdProperty_Term('.'));
    PICOTEST_VERIFY(Coatl_GetUcdProperty_Term(','));
    PICOTEST_VERIFY(Coatl_GetUcdProperty_Term(0x037E)); /* ; */
    PICOTEST_VERIFY(Coatl_GetUcdProperty_Term(0x061B)); /* ; */
    PICOTEST_VERIFY(Coatl_GetUcdProperty_Term(0x061E)); /* ؞ */
}
PICOTEST_CASE(testUcdPropertyUIdeo, colibriFixture) {
    PICOTEST_VERIFY(!Coatl_GetUcdProperty_UIdeo('A'));
    PICOTEST_VERIFY(!Coatl_GetUcdProperty_UIdeo(0x3005)); /* 々 */
    PICOTEST_VERIFY(!Coatl_GetUcdProperty_UIdeo(0x3006)); /* 〆 */
    PICOTEST_VERIFY(Coatl_GetUcdProperty_UIdeo(0x3400));  /* 㐀 */
}
PICOTEST_CASE(testUcdPropertyUpper, colibriFixture) {
    PICOTEST_VERIFY(!Coatl_GetUcdProperty_Upper(' '));
    PICOTEST_VERIFY(Coatl_GetUcdProperty_Upper('A'));
    PICOTEST_VERIFY(!Coatl_GetUcdProperty_Upper('a'));
    PICOTEST_VERIFY(!Coatl_GetUcdProperty_Upper(0xAA));   /* ª */
    PICOTEST_VERIFY(!Coatl_GetUcdProperty_Upper(0xDF));   /* ß */
    PICOTEST_VERIFY(Coatl_GetUcdProperty_Upper(0x0182));  /* Ƃ */
    PICOTEST_VERIFY(!Coatl_GetUcdProperty_Upper(0x0183)); /* ƃ */
    PICOTEST_VERIFY(Coatl_GetUcdProperty_Upper(0x2163));  /* Ⅳ */
}
PICOTEST_CASE(testUcdPropertyVS, colibriFixture) {
    PICOTEST_VERIFY(!Coatl_GetUcdProperty_VS('A'));
    PICOTEST_VERIFY(Coatl_GetUcdProperty_VS(0xFE00)); /* VARIATION SELECTOR-1 */
}
PICOTEST_CASE(testUcdPropertyWSpace, colibriFixture) {
    PICOTEST_VERIFY(Coatl_GetUcdProperty_WSpace('\t'));
    PICOTEST_VERIFY(Coatl_GetUcdProperty_WSpace(' '));
    PICOTEST_VERIFY(!Coatl_GetUcdProperty_WSpace('A'));
    PICOTEST_VERIFY(Coatl_GetUcdProperty_WSpace(0x85));   /* NEXT LINE */
    PICOTEST_VERIFY(Coatl_GetUcdProperty_WSpace(0x2028)); /* LINE SEPARATOR */
    PICOTEST_VERIFY(
        Coatl_GetUcdProperty_WSpace(0x3000)); /* IDEOGRAPHIC SPACE */
}
PICOTEST_CASE(testUcdPropertyXIDC, colibriFixture) {
    PICOTEST_VERIFY(!Coatl_GetUcdProperty_XIDC(' '));
    PICOTEST_VERIFY(Coatl_GetUcdProperty_XIDC('A'));
    PICOTEST_VERIFY(Coatl_GetUcdProperty_XIDC(0xB7));    /* · */
    PICOTEST_VERIFY(!Coatl_GetUcdProperty_XIDC(0x037A)); /* ͺ */
    PICOTEST_VERIFY(Coatl_GetUcdProperty_XIDC(0x0387));  /* · */
}
PICOTEST_CASE(testUcdPropertyXIDS, colibriFixture) {
    PICOTEST_VERIFY(!Coatl_GetUcdProperty_XIDS(' '));
    PICOTEST_VERIFY(Coatl_GetUcdProperty_XIDS('A'));
    PICOTEST_VERIFY(!Coatl_GetUcdProperty_XIDS(0x037A)); /* ͺ */
    PICOTEST_VERIFY(Coatl_GetUcdProperty_XIDS(0x1885));  /* ◌ᢅ */
}

/* Case Mapping and Folding */
PICOTEST_SUITE(testCaseMappingAndFolding, testUnicodeCasePredicates,
               testUnicodeCaseTransform);

PICOTEST_SUITE(testUnicodeCasePredicates, testCharIsLowercase,
               testCharIsUppercase, testCharIsCased, testCharIsTitlecase,
               testRopeIsLowercase, testRopeIsUppercase, testRopeIsCased);
PICOTEST_CASE(testCharIsLowercase, colibriFixture) {
    PICOTEST_VERIFY(!Coatl_CharIsLowercase(' '));
    PICOTEST_VERIFY(!Coatl_CharIsLowercase('1'));
    PICOTEST_VERIFY(!Coatl_CharIsLowercase('A'));
    PICOTEST_VERIFY(Coatl_CharIsLowercase('a'));
    PICOTEST_VERIFY(Coatl_CharIsLowercase(0xAA));    /* ª */
    PICOTEST_VERIFY(Coatl_CharIsLowercase(0xDF));    /* ß */
    PICOTEST_VERIFY(!Coatl_CharIsLowercase(0x1E9E)); /* ẞ */
    PICOTEST_VERIFY(!Coatl_CharIsLowercase(0x0182)); /* Ƃ */
    PICOTEST_VERIFY(Coatl_CharIsLowercase(0x0183));  /* ƃ */
    PICOTEST_VERIFY(!Coatl_CharIsLowercase(0x0132)); /* Ĳ */
    PICOTEST_VERIFY(Coatl_CharIsLowercase(0x0133));  /* ĳ */
    PICOTEST_VERIFY(!Coatl_CharIsLowercase(0x01C7)); /* Ǉ */
    PICOTEST_VERIFY(!Coatl_CharIsLowercase(0x01C8)); /* ǈ */
    PICOTEST_VERIFY(Coatl_CharIsLowercase(0x01C9));  /* ǉ */
    PICOTEST_VERIFY(!Coatl_CharIsLowercase(0x2163)); /* Ⅳ */
    PICOTEST_VERIFY(Coatl_CharIsLowercase(0x2173));  /* ⅳ */
}
PICOTEST_CASE(testCharIsUppercase, colibriFixture) {
    PICOTEST_VERIFY(!Coatl_CharIsUppercase(' '));
    PICOTEST_VERIFY(!Coatl_CharIsUppercase('1'));
    PICOTEST_VERIFY(Coatl_CharIsUppercase('A'));
    PICOTEST_VERIFY(!Coatl_CharIsUppercase('a'));
    PICOTEST_VERIFY(!Coatl_CharIsUppercase(0xAA));   /* ª */
    PICOTEST_VERIFY(!Coatl_CharIsUppercase(0xDF));   /* ß */
    PICOTEST_VERIFY(Coatl_CharIsUppercase(0x1E9E));  /* ẞ */
    PICOTEST_VERIFY(Coatl_CharIsUppercase(0x0182));  /* Ƃ */
    PICOTEST_VERIFY(!Coatl_CharIsUppercase(0x0183)); /* ƃ */
    PICOTEST_VERIFY(Coatl_CharIsUppercase(0x0132));  /* Ĳ */
    PICOTEST_VERIFY(!Coatl_CharIsUppercase(0x0133)); /* ĳ */
    PICOTEST_VERIFY(Coatl_CharIsUppercase(0x01C7));  /* Ǉ */
    PICOTEST_VERIFY(!Coatl_CharIsUppercase(0x01C8)); /* ǈ */
    PICOTEST_VERIFY(!Coatl_CharIsUppercase(0x01C9)); /* ǉ */
    PICOTEST_VERIFY(Coatl_CharIsUppercase(0x2163));  /* Ⅳ */
    PICOTEST_VERIFY(!Coatl_CharIsUppercase(0x2173)); /* ⅳ */
}
PICOTEST_CASE(testCharIsCased, colibriFixture) {
    PICOTEST_VERIFY(!Coatl_CharIsCased(' '));
    PICOTEST_VERIFY(!Coatl_CharIsCased('1'));
    PICOTEST_VERIFY(Coatl_CharIsCased('A'));
    PICOTEST_VERIFY(Coatl_CharIsCased('a'));
    PICOTEST_VERIFY(Coatl_CharIsCased(0xAA));   /* ª */
    PICOTEST_VERIFY(Coatl_CharIsCased(0xDF));   /* ß */
    PICOTEST_VERIFY(Coatl_CharIsCased(0x1E9E)); /* ẞ */
    PICOTEST_VERIFY(Coatl_CharIsCased(0x0182)); /* Ƃ */
    PICOTEST_VERIFY(Coatl_CharIsCased(0x0183)); /* ƃ */
    PICOTEST_VERIFY(Coatl_CharIsCased(0x0132)); /* Ĳ */
    PICOTEST_VERIFY(Coatl_CharIsCased(0x0133)); /* ĳ */
    PICOTEST_VERIFY(Coatl_CharIsCased(0x01C7)); /* Ǉ */
    PICOTEST_VERIFY(Coatl_CharIsCased(0x01C8)); /* ǈ */
    PICOTEST_VERIFY(Coatl_CharIsCased(0x01C9)); /* ǉ */
    PICOTEST_VERIFY(Coatl_CharIsCased(0x2163)); /* Ⅳ */
    PICOTEST_VERIFY(Coatl_CharIsCased(0x2173)); /* ⅳ */
}
PICOTEST_CASE(testCharIsTitlecase, colibriFixture) {
    PICOTEST_VERIFY(!Coatl_CharIsTitlecase(' '));
    PICOTEST_VERIFY(!Coatl_CharIsTitlecase('1'));
    PICOTEST_VERIFY(Coatl_CharIsTitlecase('A'));
    PICOTEST_VERIFY(!Coatl_CharIsTitlecase('a'));
    PICOTEST_VERIFY(Coatl_CharIsTitlecase(0xAA));    /* ª */
    PICOTEST_VERIFY(!Coatl_CharIsTitlecase(0xDF));   /* ß */
    PICOTEST_VERIFY(Coatl_CharIsTitlecase(0x1E9E));  /* ẞ */
    PICOTEST_VERIFY(Coatl_CharIsTitlecase(0x0182));  /* Ƃ */
    PICOTEST_VERIFY(!Coatl_CharIsTitlecase(0x0183)); /* ƃ */
    PICOTEST_VERIFY(Coatl_CharIsTitlecase(0x0132));  /* Ĳ */
    PICOTEST_VERIFY(!Coatl_CharIsTitlecase(0x0133)); /* ĳ */
    PICOTEST_VERIFY(!Coatl_CharIsTitlecase(0x01C7)); /* Ǉ */
    PICOTEST_VERIFY(Coatl_CharIsTitlecase(0x01C8));  /* ǈ */
    PICOTEST_VERIFY(!Coatl_CharIsTitlecase(0x01C9)); /* ǉ */
    PICOTEST_VERIFY(Coatl_CharIsTitlecase(0x2163));  /* Ⅳ */
    PICOTEST_VERIFY(!Coatl_CharIsTitlecase(0x2173)); /* ⅳ */
}

#define UTF8(s) (Col_NewRope(COL_UTF8, s, strlen(s)))
#define UCS2(s) (Col_NewRope(COL_UCS2, s, wcslen(s) * 2))

PICOTEST_CASE(testRopeIsLowercase, colibriFixture) {
    PICOTEST_VERIFY(!Coatl_RopeIsLowercase(UTF8("1234")));
    PICOTEST_VERIFY(Coatl_RopeIsLowercase(UTF8("1234a")));
    PICOTEST_VERIFY(!Coatl_RopeIsLowercase(UTF8("1234A")));
    PICOTEST_VERIFY(Coatl_RopeIsLowercase(UTF8("abcd")));
    PICOTEST_VERIFY(!Coatl_RopeIsLowercase(UTF8("abCd")));
    PICOTEST_VERIFY(Coatl_RopeIsLowercase(UTF8("straße")));
    PICOTEST_VERIFY(!Coatl_RopeIsLowercase(UTF8("straẞe")));
    PICOTEST_VERIFY(!Coatl_RopeIsLowercase(UTF8("Հայոց գրեր")));
    PICOTEST_VERIFY(Coatl_RopeIsLowercase(UTF8("հայոց գրեր")));
    PICOTEST_VERIFY(!Coatl_RopeIsLowercase(UTF8("האלפבית העברי")));
}
PICOTEST_CASE(testRopeIsUppercase, colibriFixture) {
    PICOTEST_VERIFY(!Coatl_RopeIsUppercase(UTF8("1234")));
    PICOTEST_VERIFY(!Coatl_RopeIsUppercase(UTF8("1234a")));
    PICOTEST_VERIFY(Coatl_RopeIsUppercase(UTF8("1234A")));
    PICOTEST_VERIFY(Coatl_RopeIsUppercase(UTF8("ABCD")));
    PICOTEST_VERIFY(!Coatl_RopeIsUppercase(UTF8("ABcD")));
    PICOTEST_VERIFY(!Coatl_RopeIsUppercase(UTF8("STRAßE")));
    PICOTEST_VERIFY(Coatl_RopeIsUppercase(UTF8("STRAẞE")));
    PICOTEST_VERIFY(!Coatl_RopeIsUppercase(UTF8("Հայոց գրեր")));
    PICOTEST_VERIFY(Coatl_RopeIsUppercase(UTF8("ՀԱՅՈՑ ԳՐԵՐ")));
    PICOTEST_VERIFY(!Coatl_RopeIsUppercase(UTF8("האלפבית העברי")));
}
PICOTEST_CASE(testRopeIsCased, colibriFixture) {
    PICOTEST_VERIFY(!Coatl_RopeIsCased(UTF8("1234")));
    PICOTEST_VERIFY(Coatl_RopeIsCased(UTF8("1234a")));
    PICOTEST_VERIFY(Coatl_RopeIsCased(UTF8("1234A")));
    PICOTEST_VERIFY(Coatl_RopeIsCased(UTF8("abcd")));
    PICOTEST_VERIFY(Coatl_RopeIsCased(UTF8("abCd")));
    PICOTEST_VERIFY(Coatl_RopeIsCased(UTF8("ABCD")));
    PICOTEST_VERIFY(Coatl_RopeIsCased(UTF8("ABcD")));
    PICOTEST_VERIFY(Coatl_RopeIsCased(UTF8("straße")));
    PICOTEST_VERIFY(Coatl_RopeIsCased(UTF8("straẞe")));
    PICOTEST_VERIFY(Coatl_RopeIsCased(UTF8("STRAßE")));
    PICOTEST_VERIFY(Coatl_RopeIsCased(UTF8("STRAẞE")));
    PICOTEST_VERIFY(Coatl_RopeIsCased(UTF8("Հայոց գրեր")));
    PICOTEST_VERIFY(Coatl_RopeIsCased(UTF8("հայոց գրեր")));
    PICOTEST_VERIFY(Coatl_RopeIsCased(UTF8("Հայոց Գրեր")));
    PICOTEST_VERIFY(Coatl_RopeIsCased(UTF8("ՀԱՅՈՑ ԳՐԵՐ")));
    PICOTEST_VERIFY(!Coatl_RopeIsCased(UTF8("האלפבית העברי")));
}

PICOTEST_SUITE(testUnicodeCaseTransform, testCharToLowercase,
               testCharToUppercase, testCharToTitlecase, testCharToCaseFolded,
               testRopeToLowercase, testRopeToUppercase, testRopeToCaseFolded);

PICOTEST_CASE(testCharToLowercase, colibriFixture) {
    PICOTEST_VERIFY(Coatl_CharToLowercase(' ') == ' ');
    PICOTEST_VERIFY(Coatl_CharToLowercase('1') == '1');
    PICOTEST_VERIFY(Coatl_CharToLowercase('A') == 'a');
    PICOTEST_VERIFY(Coatl_CharToLowercase('a') == 'a');
    PICOTEST_VERIFY(Coatl_CharToLowercase(0xAA) == 0xAA);     /* ª */
    PICOTEST_VERIFY(Coatl_CharToLowercase(0xDF) == 0xDF);     /* ß */
    PICOTEST_VERIFY(Coatl_CharToLowercase(0x1E9E) == 0xDF);   /* ẞ -> ß */
    PICOTEST_VERIFY(Coatl_CharToLowercase(0x0182) == 0x0183); /* Ƃ -> ƃ */
    PICOTEST_VERIFY(Coatl_CharToLowercase(0x0183) == 0x0183); /* ƃ */
    PICOTEST_VERIFY(Coatl_CharToLowercase(0x2163) == 0x2173); /* Ⅳ -> ⅳ */
    PICOTEST_VERIFY(Coatl_CharToLowercase(0x2173) == 0x2173); /* ⅳ */
    PICOTEST_VERIFY(Coatl_CharToLowercase(0x0132) == 0x0133); /* Ĳ -> ĳ */
    PICOTEST_VERIFY(Coatl_CharToLowercase(0x0133) == 0x0133); /* ĳ */
    PICOTEST_VERIFY(Coatl_CharToLowercase(0x01C7) == 0x01C9); /* Ǉ -> ǉ */
    PICOTEST_VERIFY(Coatl_CharToLowercase(0x01C8) == 0x01C9); /* ǈ -> ǉ */
    PICOTEST_VERIFY(Coatl_CharToLowercase(0x01C9) == 0x01C9); /* ǉ */
}
PICOTEST_CASE(testCharToUppercase, colibriFixture) {
    PICOTEST_VERIFY(Coatl_CharToUppercase(' ') == ' ');
    PICOTEST_VERIFY(Coatl_CharToUppercase('1') == '1');
    PICOTEST_VERIFY(Coatl_CharToUppercase('A') == 'A');
    PICOTEST_VERIFY(Coatl_CharToUppercase('a') == 'A');
    PICOTEST_VERIFY(Coatl_CharToUppercase(0xAA) == 0xAA);     /* ª */
    PICOTEST_VERIFY(Coatl_CharToUppercase(0xDF) == 0xDF);     /* ß */
    PICOTEST_VERIFY(Coatl_CharToUppercase(0x1E9E) == 0x1E9E); /* ẞ */
    PICOTEST_VERIFY(Coatl_CharToUppercase(0x0182) == 0x0182); /* Ƃ */
    PICOTEST_VERIFY(Coatl_CharToUppercase(0x0183) == 0x0182); /* ƃ -> Ƃ */
    PICOTEST_VERIFY(Coatl_CharToUppercase(0x2163) == 0x2163); /* Ⅳ */
    PICOTEST_VERIFY(Coatl_CharToUppercase(0x2173) == 0x2163); /* ⅳ -> Ⅳ */
    PICOTEST_VERIFY(Coatl_CharToUppercase(0x0132) == 0x0132); /* Ĳ */
    PICOTEST_VERIFY(Coatl_CharToUppercase(0x0133) == 0x0132); /* ĳ -> Ĳ */
    PICOTEST_VERIFY(Coatl_CharToUppercase(0x01C7) == 0x01C7); /* Ǉ */
    PICOTEST_VERIFY(Coatl_CharToUppercase(0x01C8) == 0x01C7); /* ǈ -> Ǉ */
    PICOTEST_VERIFY(Coatl_CharToUppercase(0x01C9) == 0x01C7); /* ǉ -> Ǉ */
}
PICOTEST_CASE(testCharToTitlecase, colibriFixture) {
    PICOTEST_VERIFY(Coatl_CharToTitlecase(' ') == ' ');
    PICOTEST_VERIFY(Coatl_CharToTitlecase('1') == '1');
    PICOTEST_VERIFY(Coatl_CharToTitlecase('A') == 'A');
    PICOTEST_VERIFY(Coatl_CharToTitlecase('a') == 'A');
    PICOTEST_VERIFY(Coatl_CharToTitlecase(0xAA) == 0xAA);     /* ª */
    PICOTEST_VERIFY(Coatl_CharToTitlecase(0xDF) == 0xDF);     /* ß */
    PICOTEST_VERIFY(Coatl_CharToTitlecase(0x1E9E) == 0x1E9E); /* ẞ */
    PICOTEST_VERIFY(Coatl_CharToTitlecase(0x0182) == 0x0182); /* Ƃ */
    PICOTEST_VERIFY(Coatl_CharToTitlecase(0x0183) == 0x0182); /* ƃ -> Ƃ */
    PICOTEST_VERIFY(Coatl_CharToTitlecase(0x2163) == 0x2163); /* Ⅳ */
    PICOTEST_VERIFY(Coatl_CharToTitlecase(0x2173) == 0x2163); /* ⅳ -> Ⅳ */
    PICOTEST_VERIFY(Coatl_CharToTitlecase(0x0132) == 0x0132); /* Ĳ */
    PICOTEST_VERIFY(Coatl_CharToTitlecase(0x0133) == 0x0132); /* ĳ -> Ĳ */
    PICOTEST_VERIFY(Coatl_CharToTitlecase(0x01C7) == 0x01C8); /* Ǉ -> ǈ */
    PICOTEST_VERIFY(Coatl_CharToTitlecase(0x01C8) == 0x01C8); /* ǈ */
    PICOTEST_VERIFY(Coatl_CharToTitlecase(0x01C9) == 0x01C8); /* ǉ -> ǈ */
}
PICOTEST_CASE(testCharToCaseFolded, colibriFixture) {
    PICOTEST_VERIFY(Coatl_CharToCaseFolded('E') == 'e');
    PICOTEST_VERIFY(Coatl_CharToCaseFolded('f') == 'f');
    PICOTEST_VERIFY(Coatl_CharToCaseFolded(0xB5) == 0x03BC);   /* µ -> μ */
    PICOTEST_VERIFY(Coatl_CharToCaseFolded(0xDF) == 0xDF);     /* ß */
    PICOTEST_VERIFY(Coatl_CharToCaseFolded(0xFB04) == 0xFB04); /* ﬄ */
}

#define EQ(rope1, rope2) (Col_CompareRopes(rope1, rope2) == 0)

PICOTEST_SUITE(testRopeToLowercase, testRopeToLowercaseSimple,
               testRopeToLowercaseFull);
PICOTEST_CASE(testRopeToLowercaseSimple, colibriFixture) {
    PICOTEST_VERIFY(EQ(Coatl_RopeToLowercase(UTF8("1234"), 0), UTF8("1234")));
    PICOTEST_VERIFY(EQ(Coatl_RopeToLowercase(UTF8("1234a"), 0), UTF8("1234a")));
    PICOTEST_VERIFY(EQ(Coatl_RopeToLowercase(UTF8("1234A"), 0), UTF8("1234a")));
    PICOTEST_VERIFY(EQ(Coatl_RopeToLowercase(UTF8("İ"), 0), UTF8("i")));
    PICOTEST_VERIFY(EQ(Coatl_RopeToLowercase(UTF8("abcd"), 0), UTF8("abcd")));
    PICOTEST_VERIFY(EQ(Coatl_RopeToLowercase(UTF8("abCd"), 0), UTF8("abcd")));
    PICOTEST_VERIFY(EQ(Coatl_RopeToLowercase(UTF8("ABCD"), 0), UTF8("abcd")));
    PICOTEST_VERIFY(EQ(Coatl_RopeToLowercase(UTF8("ABcD"), 0), UTF8("abcd")));
    PICOTEST_VERIFY(
        EQ(Coatl_RopeToLowercase(UTF8("straße"), 0), UTF8("straße")));
    PICOTEST_VERIFY(
        EQ(Coatl_RopeToLowercase(UTF8("straẞe"), 0), UTF8("straße")));
    PICOTEST_VERIFY(
        EQ(Coatl_RopeToLowercase(UTF8("STRAßE"), 0), UTF8("straße")));
    PICOTEST_VERIFY(
        EQ(Coatl_RopeToLowercase(UTF8("STRAẞE"), 0), UTF8("straße")));
    PICOTEST_VERIFY(
        EQ(Coatl_RopeToLowercase(UTF8("Հայոց գրեր"), 0), UTF8("հայոց գրեր")));
    PICOTEST_VERIFY(
        EQ(Coatl_RopeToLowercase(UTF8("հայոց գրեր"), 0), UTF8("հայոց գրեր")));
    PICOTEST_VERIFY(
        EQ(Coatl_RopeToLowercase(UTF8("Հայոց Գրեր"), 0), UTF8("հայոց գրեր")));
    PICOTEST_VERIFY(
        EQ(Coatl_RopeToLowercase(UTF8("ՀԱՅՈՑ ԳՐԵՐ"), 0), UTF8("հայոց գրեր")));
    PICOTEST_VERIFY(EQ(Coatl_RopeToLowercase(UTF8("האלפבית העברי"), 0),
                       UTF8("האלפבית העברי")));
}
PICOTEST_CASE(testRopeToLowercaseFull, colibriFixture) {
    PICOTEST_VERIFY(EQ(Coatl_RopeToLowercase(UTF8("1234"), 1), UTF8("1234")));
    PICOTEST_VERIFY(EQ(Coatl_RopeToLowercase(UTF8("1234a"), 1), UTF8("1234a")));
    PICOTEST_VERIFY(EQ(Coatl_RopeToLowercase(UTF8("1234A"), 1), UTF8("1234a")));
    PICOTEST_VERIFY(EQ(Coatl_RopeToLowercase(UTF8("İ"), 1), UCS2(L"i\u0307")));
    PICOTEST_VERIFY(EQ(Coatl_RopeToLowercase(UTF8("abcd"), 1), UTF8("abcd")));
    PICOTEST_VERIFY(EQ(Coatl_RopeToLowercase(UTF8("abCd"), 1), UTF8("abcd")));
    PICOTEST_VERIFY(EQ(Coatl_RopeToLowercase(UTF8("ABCD"), 1), UTF8("abcd")));
    PICOTEST_VERIFY(EQ(Coatl_RopeToLowercase(UTF8("ABcD"), 1), UTF8("abcd")));
    PICOTEST_VERIFY(
        EQ(Coatl_RopeToLowercase(UTF8("straße"), 1), UTF8("straße")));
    PICOTEST_VERIFY(
        EQ(Coatl_RopeToLowercase(UTF8("straẞe"), 1), UTF8("straße")));
    PICOTEST_VERIFY(
        EQ(Coatl_RopeToLowercase(UTF8("STRAßE"), 1), UTF8("straße")));
    PICOTEST_VERIFY(
        EQ(Coatl_RopeToLowercase(UTF8("STRAẞE"), 1), UTF8("straße")));
    PICOTEST_VERIFY(
        EQ(Coatl_RopeToLowercase(UTF8("Հայոց գրեր"), 1), UTF8("հայոց գրեր")));
    PICOTEST_VERIFY(
        EQ(Coatl_RopeToLowercase(UTF8("հայոց գրեր"), 1), UTF8("հայոց գրեր")));
    PICOTEST_VERIFY(
        EQ(Coatl_RopeToLowercase(UTF8("Հայոց Գրեր"), 1), UTF8("հայոց գրեր")));
    PICOTEST_VERIFY(
        EQ(Coatl_RopeToLowercase(UTF8("ՀԱՅՈՑ ԳՐԵՐ"), 1), UTF8("հայոց գրեր")));
    PICOTEST_VERIFY(EQ(Coatl_RopeToLowercase(UTF8("האלפבית העברי"), 1),
                       UTF8("האלפבית העברי")));
}

PICOTEST_SUITE(testRopeToUppercase, testRopeToUppercaseSimple,
               testRopeToUppercaseFull);
PICOTEST_CASE(testRopeToUppercaseSimple, colibriFixture) {
    PICOTEST_VERIFY(EQ(Coatl_RopeToUppercase(UTF8("1234"), 0), UTF8("1234")));
    PICOTEST_VERIFY(EQ(Coatl_RopeToUppercase(UTF8("1234a"), 0), UTF8("1234A")));
    PICOTEST_VERIFY(EQ(Coatl_RopeToUppercase(UTF8("1234A"), 0), UTF8("1234A")));
    PICOTEST_VERIFY(EQ(Coatl_RopeToUppercase(UTF8("İ"), 1), UTF8("İ")));
    PICOTEST_VERIFY(EQ(Coatl_RopeToUppercase(UTF8("abcd"), 0), UTF8("ABCD")));
    PICOTEST_VERIFY(EQ(Coatl_RopeToUppercase(UTF8("abCd"), 0), UTF8("ABCD")));
    PICOTEST_VERIFY(EQ(Coatl_RopeToUppercase(UTF8("ABCD"), 0), UTF8("ABCD")));
    PICOTEST_VERIFY(EQ(Coatl_RopeToUppercase(UTF8("ABcD"), 0), UTF8("ABCD")));
    PICOTEST_VERIFY(EQ(Coatl_RopeToUppercase(UTF8("riﬄle"), 0), UTF8("RIﬄLE")));
    PICOTEST_VERIFY(
        EQ(Coatl_RopeToUppercase(UTF8("straße"), 0), UTF8("STRAßE")));
    PICOTEST_VERIFY(
        EQ(Coatl_RopeToUppercase(UTF8("straẞe"), 0), UTF8("STRAẞE")));
    PICOTEST_VERIFY(
        EQ(Coatl_RopeToUppercase(UTF8("STRAßE"), 0), UTF8("STRAßE")));
    PICOTEST_VERIFY(
        EQ(Coatl_RopeToUppercase(UTF8("STRAẞE"), 0), UTF8("STRAẞE")));
    PICOTEST_VERIFY(
        EQ(Coatl_RopeToUppercase(UTF8("Հայոց գրեր"), 0), UTF8("ՀԱՅՈՑ ԳՐԵՐ")));
    PICOTEST_VERIFY(
        EQ(Coatl_RopeToUppercase(UTF8("հայոց գրեր"), 0), UTF8("ՀԱՅՈՑ ԳՐԵՐ")));
    PICOTEST_VERIFY(
        EQ(Coatl_RopeToUppercase(UTF8("Հայոց Գրեր"), 0), UTF8("ՀԱՅՈՑ ԳՐԵՐ")));
    PICOTEST_VERIFY(
        EQ(Coatl_RopeToUppercase(UTF8("ՀԱՅՈՑ ԳՐԵՐ"), 0), UTF8("ՀԱՅՈՑ ԳՐԵՐ")));
    PICOTEST_VERIFY(EQ(Coatl_RopeToUppercase(UTF8("האלפבית העברי"), 0),
                       UTF8("האלפבית העברי")));
}
PICOTEST_CASE(testRopeToUppercaseFull, colibriFixture) {
    PICOTEST_VERIFY(EQ(Coatl_RopeToUppercase(UTF8("1234"), 1), UTF8("1234")));
    PICOTEST_VERIFY(EQ(Coatl_RopeToUppercase(UTF8("1234a"), 1), UTF8("1234A")));
    PICOTEST_VERIFY(EQ(Coatl_RopeToUppercase(UTF8("1234A"), 1), UTF8("1234A")));
    PICOTEST_VERIFY(EQ(Coatl_RopeToUppercase(UTF8("abcd"), 1), UTF8("ABCD")));
    PICOTEST_VERIFY(EQ(Coatl_RopeToUppercase(UTF8("abCd"), 1), UTF8("ABCD")));
    PICOTEST_VERIFY(EQ(Coatl_RopeToUppercase(UTF8("ABCD"), 1), UTF8("ABCD")));
    PICOTEST_VERIFY(EQ(Coatl_RopeToUppercase(UTF8("ABcD"), 1), UTF8("ABCD")));
    PICOTEST_VERIFY(EQ(Coatl_RopeToUppercase(UTF8("riﬄe"), 1), UTF8("RIFFLE")));
    PICOTEST_VERIFY(
        EQ(Coatl_RopeToUppercase(UTF8("straße"), 1), UTF8("STRASSE")));
    PICOTEST_VERIFY(
        EQ(Coatl_RopeToUppercase(UTF8("straẞe"), 1), UTF8("STRAẞE")));
    PICOTEST_VERIFY(
        EQ(Coatl_RopeToUppercase(UTF8("STRAßE"), 1), UTF8("STRASSE")));
    PICOTEST_VERIFY(
        EQ(Coatl_RopeToUppercase(UTF8("STRAẞE"), 1), UTF8("STRAẞE")));
    PICOTEST_VERIFY(
        EQ(Coatl_RopeToUppercase(UTF8("Հայոց գրեր"), 1), UTF8("ՀԱՅՈՑ ԳՐԵՐ")));
    PICOTEST_VERIFY(
        EQ(Coatl_RopeToUppercase(UTF8("հայոց գրեր"), 1), UTF8("ՀԱՅՈՑ ԳՐԵՐ")));
    PICOTEST_VERIFY(
        EQ(Coatl_RopeToUppercase(UTF8("Հայոց գրեր"), 1), UTF8("ՀԱՅՈՑ ԳՐԵՐ")));
    PICOTEST_VERIFY(
        EQ(Coatl_RopeToUppercase(UTF8("ՀԱՅՈՑ ԳՐԵՐ"), 1), UTF8("ՀԱՅՈՑ ԳՐԵՐ")));
    PICOTEST_VERIFY(EQ(Coatl_RopeToUppercase(UTF8("האלפבית העברי"), 1),
                       UTF8("האלפבית העברי")));
}

PICOTEST_SUITE(testRopeToCaseFolded, testRopeToCaseFoldedSimple,
               testRopeToCaseFoldedFull);
PICOTEST_CASE(testRopeToCaseFoldedSimple, colibriFixture) {
    PICOTEST_VERIFY(EQ(Coatl_RopeToCaseFolded(UTF8("riﬄe"), 0), UTF8("riﬄe")));
    PICOTEST_VERIFY(
        EQ(Coatl_RopeToCaseFolded(UTF8("Ĳssel"), 0), UTF8("ĳssel")));
    PICOTEST_VERIFY(
        EQ(Coatl_RopeToCaseFolded(UTF8("straße"), 0), UTF8("straße")));
    PICOTEST_VERIFY(
        EQ(Coatl_RopeToCaseFolded(UTF8("straẞe"), 0), UTF8("straße")));
    PICOTEST_VERIFY(
        EQ(Coatl_RopeToCaseFolded(UTF8("STRAẞE"), 0), UTF8("straße")));
    PICOTEST_VERIFY(EQ(Coatl_RopeToCaseFolded(UTF8("15µm"), 0), UTF8("15μm")));
}
PICOTEST_CASE(testRopeToCaseFoldedFull, colibriFixture) {
    PICOTEST_VERIFY(
        EQ(Coatl_RopeToCaseFolded(UTF8("riﬄe"), 1), UTF8("riffle")));
    PICOTEST_VERIFY(
        EQ(Coatl_RopeToCaseFolded(UTF8("Ĳssel"), 1), UTF8("ĳssel")));
    PICOTEST_VERIFY(
        EQ(Coatl_RopeToCaseFolded(UTF8("straße"), 1), UTF8("strasse")));
    PICOTEST_VERIFY(
        EQ(Coatl_RopeToCaseFolded(UTF8("straẞe"), 1), UTF8("strasse")));
    PICOTEST_VERIFY(
        EQ(Coatl_RopeToCaseFolded(UTF8("STRAẞE"), 1), UTF8("strasse")));
    PICOTEST_VERIFY(EQ(Coatl_RopeToCaseFolded(UTF8("15µm"), 1), UTF8("15μm")));
}