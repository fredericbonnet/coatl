/**
 * @file coatlRegexp.h
 *
 * This header file defines the regular expression facility of CoATL.
 */

#ifndef _COATL_REGEXP
#define _COATL_REGEXP


/*
===========================================================================*//*!
\defgroup regexp Regular Expressions
\{*//*==========================================================================
*/

/***************************************************************************//*!
 * @anchor regexp_compile_flags
 * \name Regular Expression Compilation Flags
 *
 * Flags used during compilation of regular expressions.
 *
 * @note
 *      These match the constant values used by the internal regexp package.
 *
 * @see Coatl_RegexpCompile
 ***************************************************************************\{*/

/** BREs (convenience). */
#define COATL_RECOMP_BASIC      000000

/** EREs. */
#define COATL_RECOMP_EXTENDED   000001

/** Advanced features in EREs. */
#define COATL_RECOMP_ADVF       000002

/** AREs (which are also EREs). */
#define COATL_RECOMP_ADVANCED   000003

/** No special characters, none. */
#define COATL_RECOMP_QUOTE      000004

/** Ignore case. */
#define COATL_RECOMP_ICASE      000010

/** Don't care about subexpressions. */
#define COATL_RECOMP_NOSUB      000020

/** Expanded format, white space & comments. */
#define COATL_RECOMP_EXPANDED   000040

/** `"\n"` doesn't match `"."` or `"[^ ]"`. */
#define COATL_RECOMP_NLSTOP     000100

/** `"^"` matches after `"\n"`, `"$"` before. */
#define COATL_RECOMP_NLANCH     000200

/** Newlines are line terminators. */
#define COATL_RECOMP_NEWLINE    000300

/** Report details on partial/limited matches. */
#define COATL_RECOMP_EXPECT     001000

/* End of Regular Expression Compilation Flags *//*!\}*/


/***************************************************************************//*!
 * @anchor regexp_exec_flags
 * \name Regular Expression Execution Flags
 *
 * Flags used during execution of regular expressions.
 *
 * @note
 *      These match the constant values used by the internal regexp package.
 *
 * @see Coatl_RegexpExec
 ***************************************************************************\{*/

/** BOS is not BOL. */
#define COATL_REEXEC_NOTBOL     0001

/** EOS is not EOL. */
#define COATL_REEXEC_NOTEOL     0002

/* End of Regular Expression Execution Flags *//*!\}*/


/***************************************************************************//*!
 * @anchor regexp_compile_errors
 * \name Regular Expression Compilation Error Codes
 *
 * Error codes used during compilation of regular expressions.
 *
 * @note
 *      These match the constant values used by the internal regexp package.
 *
 * @see Coatl_RegexpComp
 ***************************************************************************\{*/

/** No errors detected. */
#define COATL_RECOMP_OKAY        0

/** Invalid regexp. */
#define COATL_RECOMP_BADPAT      2

/** Invalid collating element. */
#define COATL_RECOMP_ECOLLATE    3

/** Invalid character class. */
#define COATL_RECOMP_ECTYPE      4

/** Invalid escape `\` sequence. */
#define COATL_RECOMP_EESCAPE     5

/** Invalid backreference number. */
#define COATL_RECOMP_ESUBREG     6

/** Brackets `[]` not balanced. */
#define COATL_RECOMP_EBRACK      7

/** Parentheses `()` not balanced. */
#define COATL_RECOMP_EPAREN      8

/** Braces `{}` not balanced. */
#define COATL_RECOMP_EBRACE      9

/** Invalid repetition count(s). */
#define COATL_RECOMP_BADBR      10

/** Invalid character range. */
#define COATL_RECOMP_ERANGE     11

/** Out of memory. */
#define COATL_RECOMP_ESPACE     12

/** Quantifier operand invalid. */
#define COATL_RECOMP_BADRPT     13

/** "can't happen" -- you found a bug. */
#define COATL_RECOMP_ASSERT     15

/** Invalid argument to regex function. */
#define COATL_RECOMP_INVARG     16

/** Invalid embedded option. */
#define COATL_RECOMP_BADOPT     18

/** Nfa has too many states. */
#define COATL_RECOMP_ETOOBIG    19

/** End of Regular Expression Compilation Error Codes */


/***************************************************************************//*!
 * @anchor regexp_exec_errors
 * \name Regular Expression Execution Error Codes
 *
 * Error codes used during execution of regular expressions.
 *
 * @note
 *      These match the constant values used by the internal regexp package.
 *
 * @see Coatl_RegexpExec
 ***************************************************************************\{*/

/** No errors detected. */
#define COATL_REEXEC_OKAY        0

/** Failed to match. */
#define COATL_REEXEC_NOMATCH     1

/** Out of memory. */
#define COATL_REEXEC_ESPACE     12

/** "can't happen" -- you found a bug. */
#define COATL_REEXEC_ASSERT     15

/** Invalid argument to regex function. */
#define COATL_REEXEC_INVARG     16

/** Character widths of regex and string differ. */
#define COATL_REEXEC_MIXED      17

/* End of Regular Expression Execution Error Codes *//*!\}*/


/*
 * Remaining declarations.
 */

EXTERN int              Coatl_RegexpCompile(Col_Word string, int flags, 
                            Col_Word *rePtr);
EXTERN size_t           Coatl_RegexpNbSubexpressions(Col_Word re);
EXTERN int              Coatl_RegexpExec(Col_Word re, Col_Word string, 
                            int flags, size_t nbMatches, size_t *matches);

/* End of Regular Expressions *//*!\}*/

#endif /* _COATL_REGEXP */
