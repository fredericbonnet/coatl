#include <stdio.h>
#include <limits.h>

#include <coatl.h>

#include "unitTest.h"

/*
 *---------------------------------------------------------------------------
 *
 * testUnicode --
 *
 *---------------------------------------------------------------------------
 */

TEST_SUITE(testUnicode, 
    testUnicodeCase
)

TEST_FIXTURE_SETUP(testUnicode) {
    Col_Init(COL_SINGLE);
    Col_SetErrorProc(ERROR_PROC);

    Col_PauseGC();
}
TEST_FIXTURE_TEARDOWN(testUnicode) {
    if (!TEST_FAIL) {
	Col_ResumeGC();
    }
    Col_Cleanup();
}

TEST_CASE(testUnicodeCase, testUnicode) {
    static Col_Char lc[] = {'a', 'b'};
    static Col_Char uc[] = {'A', 'B'};
    static Col_Char nc[] = {'1', '2'};
    static Col_Char *pc;

    for (pc = lc; pc < lc+sizeof(lc)/sizeof(*lc); pc++) {
	ASSERT_MSG(Coatl_CharIsCased(*pc), "*pc=U+%x", *pc);
	ASSERT_MSG(Coatl_CharIsLowercase(*pc), "*pc=U+%x", *pc);
	ASSERT_MSG(!Coatl_CharIsUppercase(*pc), "*pc=U+%x", *pc);
	ASSERT_MSG(!Coatl_CharIsTitlecase(*pc), "*pc=U+%x", *pc);

	ASSERT_MSG(Coatl_CharToLowercase(*pc) == *pc, "*pc=U+%x", *pc);
	ASSERT_MSG(Coatl_CharToUppercase(*pc) != *pc, "*pc=U+%x", *pc);
	ASSERT_MSG(Coatl_CharToTitlecase(*pc) != *pc, "*pc=U+%x", *pc);

	ASSERT_MSG(Coatl_CharToLowercase(Coatl_CharToUppercase(*pc)) == *pc, "*pc=U+%x", *pc);
	ASSERT_MSG(Coatl_CharToLowercase(Coatl_CharToTitlecase(*pc)) == *pc, "*pc=U+%x", *pc);

	ASSERT_MSG(Coatl_RopeToLowercase(Col_NewCharWord(*pc), 0) == Col_NewCharWord(*pc), "*pc=U+%x", *pc);
    }

    for (pc = uc; pc < uc+sizeof(uc)/sizeof(*uc); pc++) {
	ASSERT_MSG(Coatl_CharIsCased(*pc), "*pc=U+%x", *pc);
	ASSERT_MSG(!Coatl_CharIsLowercase(*pc), "*pc=U+%x", *pc);
	ASSERT_MSG(Coatl_CharIsUppercase(*pc), "*pc=U+%x", *pc);
	ASSERT_MSG(Coatl_CharToLowercase(*pc) != *pc, "*pc=U+%x", *pc);
	ASSERT_MSG(Coatl_CharToUppercase(*pc) == *pc, "*pc=U+%x", *pc);
	ASSERT_MSG(Coatl_CharToUppercase(Coatl_CharToLowercase(*pc)) == *pc, "*pc=U+%x", *pc);
	ASSERT_MSG(Coatl_CharToUppercase(Coatl_CharToTitlecase(*pc)) == *pc, "*pc=U+%x", *pc);

	ASSERT_MSG(Coatl_RopeToUppercase(Col_NewCharWord(*pc), 0) == Col_NewCharWord(*pc), "*pc=U+%x", *pc);
    }

    for (pc = nc; pc < nc+sizeof(nc)/sizeof(*nc); pc++) {
	ASSERT_MSG(!Coatl_CharIsCased(*pc), "*pc=U+%x", *pc);
	ASSERT_MSG(!Coatl_CharIsLowercase(*pc), "*pc=U+%x", *pc);
	ASSERT_MSG(!Coatl_CharIsUppercase(*pc), "*pc=U+%x", *pc);
	ASSERT_MSG(!Coatl_CharIsTitlecase(*pc), "*pc=U+%x", *pc);
	ASSERT_MSG(Coatl_CharToLowercase(*pc) == *pc, "*pc=U+%x", *pc);
	ASSERT_MSG(Coatl_CharToUppercase(*pc) == *pc, "*pc=U+%x", *pc);
	ASSERT_MSG(Coatl_CharToTitlecase(*pc) == *pc, "*pc=U+%x", *pc);

	ASSERT_MSG(Coatl_RopeToLowercase(Col_NewCharWord(*pc), 0) == Col_NewCharWord(*pc), "*pc=U+%x", *pc);
	ASSERT_MSG(Coatl_RopeToUppercase(Col_NewCharWord(*pc), 0) == Col_NewCharWord(*pc), "*pc=U+%x", *pc);
	ASSERT_MSG(Coatl_RopeToTitlecase(Col_NewCharWord(*pc), 0) == Col_NewCharWord(*pc), "*pc=U+%x", *pc);
    }
}
