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
 * Constants: Regular Expression Flags
 *
 *	Flags used during compilation & execution of regular expressions.
 *
 *  COATL_REGEXP_BASIC		- BREs (convenience).
 *  COATL_REGEXP_EXTENDED	- EREs.
 *  COATL_REGEXP_ADVF		- Advanced features in EREs.
 *  COATL_REGEXP_ADVANCED	- AREs (which are also EREs).
 *  COATL_REGEXP_QUOTE		- No special characters, none.
 *  COATL_REGEXP_ICASE		- Ignore case.
 *  COATL_REGEXP_NOSUB		- Don't care about subexpressions.
 *  COATL_REGEXP_EXPANDED	- Expanded format, white space & comments.
 *  COATL_REGEXP_NLSTOP		- *'\n'* doesn't match *'.'* or *'[^ ]'*.
 *  COATL_REGEXP_NLANCH		- *'^'* matches after *'\n'*, *'$'* before.
 *  COATL_REGEXP_NEWLINE	- Newlines are line terminators.
 *  COATL_REGEXP_EXPECT		- Report details on partial/limited matches.
 *
 * Note:
 *	These match the constant values used by the internal regexp package.
 *
 * See also: 
 *	<Coatl_RegexpCompile>, <Coatl_RegexpExec>
 *---------------------------------------------------------------------------*/

#define COATL_REGEXP_BASIC	000000
#define COATL_REGEXP_EXTENDED	000001
#define COATL_REGEXP_ADVF	000002
#define COATL_REGEXP_ADVANCED	000003
#define COATL_REGEXP_QUOTE	000004
#define COATL_REGEXP_ICASE	000010
#define COATL_REGEXP_NOSUB	000020
#define COATL_REGEXP_EXPANDED	000040
#define COATL_REGEXP_NLSTOP	000100
#define COATL_REGEXP_NLANCH	000200
#define COATL_REGEXP_NEWLINE	000300
#define COATL_REGEXP_EXPECT	001000

/*---------------------------------------------------------------------------
 * Constants: Regular Expression Error Codes
 *
 *	Error codes used during compilation & execution of regular expressions.
 *
 *  COATL_REGEXP_OKAY		-  No errors detected.
 *  COATL_REGEXP_NOMATCH	-  Failed to match.
 *  COATL_REGEXP_BADPAT		-  Invalid regexp.
 *  COATL_REGEXP_ECOLLATE	-  Invalid collating element.
 *  COATL_REGEXP_ECTYPE		-  Invalid character class.
 *  COATL_REGEXP_EESCAPE	-  Invalid escape \ sequence.
 *  COATL_REGEXP_ESUBREG	-  Invalid backreference number.
 *  COATL_REGEXP_EBRACK		-  Brackets [] not balanced.
 *  COATL_REGEXP_EPAREN		-  Parentheses () not balanced.
 *  COATL_REGEXP_EBRACE		-  Braces {} not balanced.
 *  COATL_REGEXP_BADBR		-  Invalid repetition count(s).
 *  COATL_REGEXP_ERANGE		-  Invalid character range.
 *  COATL_REGEXP_ESPACE		-  Out of memory.
 *  COATL_REGEXP_BADRPT		-  Quantifier operand invalid.
 *  COATL_REGEXP_ASSERT		-  "can't happen" -- you found a bug.
 *  COATL_REGEXP_INVARG		-  Invalid argument to regex function.
 *  COATL_REGEXP_MIXED		-  Character widths of regex and string differ.
 *  COATL_REGEXP_BADOPT		-  Invalid embedded option.
 *  COATL_REGEXP_ETOOBIG	-  Nfa has too many states.
 *
 * Debugging and testing:
 *  COATL_REGEXP_ATOI		- Convert error-code name to number.
 *  COATL_REGEXP_ITOA		- Convert error-code number to name.
 *
 * Note:
 *	These match the constant values used by the internal regexp package.
 *
 * See also: 
 *	<Coatl_RegexpCompile>, <Coatl_RegexpExec>
 *---------------------------------------------------------------------------*/

#define COATL_REGEXP_OKAY	  0
#define COATL_REGEXP_NOMATCH	  1
#define COATL_REGEXP_BADPAT	  2
#define COATL_REGEXP_ECOLLATE	  3
#define COATL_REGEXP_ECTYPE	  4
#define COATL_REGEXP_EESCAPE	  5
#define COATL_REGEXP_ESUBREG	  6
#define COATL_REGEXP_EBRACK	  7
#define COATL_REGEXP_EPAREN	  8
#define COATL_REGEXP_EBRACE	  9
#define COATL_REGEXP_BADBR	 10
#define COATL_REGEXP_ERANGE	 11
#define COATL_REGEXP_ESPACE	 12
#define COATL_REGEXP_BADRPT	 13
#define COATL_REGEXP_ASSERT	 15
#define COATL_REGEXP_INVARG	 16
#define COATL_REGEXP_MIXED	 17
#define COATL_REGEXP_BADOPT	 18
#define COATL_REGEXP_ETOOBIG	 19
#define COATL_REGEXP_ATOI	101
#define COATL_REGEXP_ITOA	102

/*
 * Remaining declarations.
 */

EXTERN int		Coatl_RegexpCompile(Col_Word string, int flags, 
			    Col_Word *rePtr);
EXTERN int		Coatl_RegexpExec(Col_Word re, Col_Word string, 
			    int flags);

#endif /* _COATL_REGEXP */
