/*
 * Header: coatlRegexp.h
 *
 *	This header file defines the regular expression facility of CoATL.
 */

#ifndef _COATL_REGEXP
#define _COATL_REGEXP


/*
================================================================================
Section: Regular Expressions
================================================================================
*/

/*---------------------------------------------------------------------------
 * Constants: Regular Expression Compilation Flags
 *
 *	Flags used during compilation of regular expressions.
 *
 *  COATL_RECOMP_BASIC		- BREs (convenience).
 *  COATL_RECOMP_EXTENDED	- EREs.
 *  COATL_RECOMP_ADVF		- Advanced features in EREs.
 *  COATL_RECOMP_ADVANCED	- AREs (which are also EREs).
 *  COATL_RECOMP_QUOTE		- No special characters, none.
 *  COATL_RECOMP_ICASE		- Ignore case.
 *  COATL_RECOMP_NOSUB		- Don't care about subexpressions.
 *  COATL_RECOMP_EXPANDED	- Expanded format, white space & comments.
 *  COATL_RECOMP_NLSTOP		- *'\n'* doesn't match *'.'* or *'[^ ]'*.
 *  COATL_RECOMP_NLANCH		- *'^'* matches after *'\n'*, *'$'* before.
 *  COATL_RECOMP_NEWLINE	- Newlines are line terminators.
 *  COATL_RECOMP_EXPECT		- Report details on partial/limited matches.
 *
 * Note:
 *	These match the constant values used by the internal regexp package.
 *
 * See also: 
 *	<Coatl_RegexpCompile>
 *---------------------------------------------------------------------------*/

#define COATL_RECOMP_BASIC	000000
#define COATL_RECOMP_EXTENDED	000001
#define COATL_RECOMP_ADVF	000002
#define COATL_RECOMP_ADVANCED	000003
#define COATL_RECOMP_QUOTE	000004
#define COATL_RECOMP_ICASE	000010
#define COATL_RECOMP_NOSUB	000020
#define COATL_RECOMP_EXPANDED	000040
#define COATL_RECOMP_NLSTOP	000100
#define COATL_RECOMP_NLANCH	000200
#define COATL_RECOMP_NEWLINE	000300
#define COATL_RECOMP_EXPECT	001000

/*---------------------------------------------------------------------------
 * Constants: Regular Expression Execution Flags
 *
 *	Flags used during execution of regular expressions.
 *
 *  COATL_REEXEC_NOTBOL	- BOS is not BOL.
 *  COATL_REEXEC_NOTEOL	- EOS is not EOL.
 *
 * Note:
 *	These match the constant values used by the internal regexp package.
 *
 * See also: 
 *	<Coatl_RegexpExec>
 *---------------------------------------------------------------------------*/

#define	COATL_REEXEC_NOTBOL	0001
#define	COATL_REEXEC_NOTEOL	0002

/*---------------------------------------------------------------------------
 * Constants: Regular Expression Compilation Error Codes
 *
 *	Error codes used during compilation of regular expressions.
 *
 *  COATL_RECOMP_OKAY		-  No errors detected.
 *  COATL_RECOMP_BADPAT		-  Invalid regexp.
 *  COATL_RECOMP_ECOLLATE	-  Invalid collating element.
 *  COATL_RECOMP_ECTYPE		-  Invalid character class.
 *  COATL_RECOMP_EESCAPE	-  Invalid escape \ sequence.
 *  COATL_RECOMP_ESUBREG	-  Invalid backreference number.
 *  COATL_RECOMP_EBRACK		-  Brackets [] not balanced.
 *  COATL_RECOMP_EPAREN		-  Parentheses () not balanced.
 *  COATL_RECOMP_EBRACE		-  Braces {} not balanced.
 *  COATL_RECOMP_BADBR		-  Invalid repetition count(s).
 *  COATL_RECOMP_ERANGE		-  Invalid character range.
 *  COATL_RECOMP_ESPACE		-  Out of memory.
 *  COATL_RECOMP_BADRPT		-  Quantifier operand invalid.
 *  COATL_RECOMP_ASSERT		-  "can't happen" -- you found a bug.
 *  COATL_RECOMP_INVARG		-  Invalid argument to regex function.
 *  COATL_RECOMP_BADOPT		-  Invalid embedded option.
 *  COATL_RECOMP_ETOOBIG	-  Nfa has too many states.
 *
 * Note:
 *	These match the constant values used by the internal regexp package.
 *
 * See also: 
 *	<Coatl_RegexpComp>
 *---------------------------------------------------------------------------*/

#define COATL_RECOMP_OKAY	 0
#define COATL_RECOMP_BADPAT	 2
#define COATL_RECOMP_ECOLLATE	 3
#define COATL_RECOMP_ECTYPE	 4
#define COATL_RECOMP_EESCAPE	 5
#define COATL_RECOMP_ESUBREG	 6
#define COATL_RECOMP_EBRACK	 7
#define COATL_RECOMP_EPAREN	 8
#define COATL_RECOMP_EBRACE	 9
#define COATL_RECOMP_BADBR	10
#define COATL_RECOMP_ERANGE	11
#define COATL_RECOMP_ESPACE	12
#define COATL_RECOMP_BADRPT	13
#define COATL_RECOMP_ASSERT	15
#define COATL_RECOMP_INVARG	16
#define COATL_RECOMP_BADOPT	18
#define COATL_RECOMP_ETOOBIG	19

/*---------------------------------------------------------------------------
 * Constants: Regular Expression Execution Error Codes
 *
 *	Error codes used during execution of regular expressions.
 *
 *  COATL_REEXEC_OKAY		-  No errors detected.
 *  COATL_REEXEC_NOMATCH	-  Failed to match.
 *  COATL_REEXEC_ESPACE		-  Out of memory.
 *  COATL_REEXEC_ASSERT		-  "can't happen" -- you found a bug.
 *  COATL_REEXEC_INVARG		-  Invalid argument to regex function.
 *  COATL_REEXEC_MIXED		-  Character widths of regex and string differ.
 *
 * Note:
 *	These match the constant values used by the internal regexp package.
 *
 * See also: 
 *	<Coatl_RegexpExec>
 *---------------------------------------------------------------------------*/

#define COATL_REEXEC_OKAY	 0
#define COATL_REEXEC_NOMATCH	 1
#define COATL_REEXEC_ESPACE	12
#define COATL_REEXEC_ASSERT	15
#define COATL_REEXEC_INVARG	16
#define COATL_REEXEC_MIXED	17

/*
 * Remaining declarations.
 */

EXTERN int		Coatl_RegexpCompile(Col_Word string, int flags, 
			    Col_Word *rePtr);
EXTERN int		Coatl_RegexpExec(Col_Word re, Col_Word string, 
			    int flags);

#endif /* _COATL_REGEXP */
