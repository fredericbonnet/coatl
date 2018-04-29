#include <stdio.h>
#include <limits.h>

#include <coatl.h>

#include <picotest.h>

#include "testCoatl.h"

/*
 *---------------------------------------------------------------------------
 *
 * testRegexp --
 *
 *---------------------------------------------------------------------------
 */

PICOTEST_FIXTURE_SETUP(testRegexps) {
    Col_Init(COL_SINGLE);
    Col_SetErrorProc(ERROR_PROC);

    Col_PauseGC();
}
PICOTEST_FIXTURE_TEARDOWN(testRegexps) {
    if (!PICOTEST_FAIL) {
	Col_ResumeGC();
    }
    Col_Cleanup();
}

static int testRegexp(Col_Word re, Col_Word string, size_t nbMatches, size_t *matches) {
    if (Coatl_RegexpCompile(re, COATL_RECOMP_ADVANCED, &re) != COATL_RECOMP_OKAY) return 0;
    return (Coatl_RegexpExec(re, string, 0, nbMatches, matches) == COATL_REEXEC_OKAY);
}

PICOTEST_CASE(testRegexps, testRegexps) {
    Col_Word r = Col_NewRopeFromString("12ab23");
    size_t matches[2];

    ASSERT(testRegexp(Col_NewRopeFromString(".*"), r, 1, matches));

    ASSERT(testRegexp(Col_NewRopeFromString("ab"), r, 1, matches));

    ASSERT(testRegexp(Col_NewRopeFromString("[[:alpha:]]{2}"), r, 1, matches));

    ASSERT(!testRegexp(Col_NewRopeFromString("[[:alpha:]]{4}"), r, 1, matches));

    ASSERT(testRegexp(Col_NewRopeFromString("[[:digit:]]{2}"), r, 1, matches));
    ASSERT(testRegexp(Col_NewRopeFromString("[\\d]{2}"), r, 1, matches));
    ASSERT(testRegexp(Col_NewRopeFromString("\\d{2}"), r, 1, matches));

    ASSERT(!testRegexp(Col_NewRopeFromString("[[:digit:]]{4}"), r, 1, matches));
    ASSERT(!testRegexp(Col_NewRopeFromString("[\\d]{4}"), r, 1, matches));
    ASSERT(!testRegexp(Col_NewRopeFromString("\\d{4}"), r, 1, matches));

    ASSERT(testRegexp(Col_NewRopeFromString("[[:alnum:]]{4}"), r, 1, matches));
    ASSERT(testRegexp(Col_NewRopeFromString("[\\w]{4}"), r, 1, matches));
    ASSERT(testRegexp(Col_NewRopeFromString("\\w{4}"), r, 1, matches));

    return;
}
