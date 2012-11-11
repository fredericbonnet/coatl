/*
 * Header: coatlNumber.h
 *
 *	This header file defines the number handling facility of CoATL.
 */

#ifndef _COATL_NUMBER
#define _COATL_NUMBER

#include <limits.h>


/*
================================================================================
Section: Large Integer Words
================================================================================
*/

/****************************************************************************
 * Group: Large Integer Word Creation
 *
 * Declaration:
 *	<Coatl_NewLargeIntWord>
 ****************************************************************************/

#if INTPTR_MAX != INTMAX_MAX
EXTERN Col_Word		Coatl_NewLargeIntWord(intmax_t value);
#else
#   define Coatl_NewLargeIntWord	Col_NewIntWord
#endif /* INTPTR_MAX != INTMAX_MAX */


/****************************************************************************
 * Group: Large Integer Word Predicates
 *
 * Declaration:
 *	<Coatl_WordIsLargeInt>
 ****************************************************************************/

#if INTPTR_MAX != INTMAX_MAX
EXTERN int		Coatl_WordIsLargeInt(Col_Word word);
#else
#   define Coatl_WordIsLargeInt	(Col_WordType(word) & COL_INT)
#endif /* INTPTR_MAX != INTMAX_MAX */


/****************************************************************************
 * Group: Large Integer Word Accessors
 *
 * Declaration:
 *	<Coatl_LargeIntWordValue>
 ****************************************************************************/

#if INTPTR_MAX != INTMAX_MAX
EXTERN intmax_t		Coatl_LargeIntWordValue(Col_Word word);
#else
#   define Coatl_LargeIntWordValue	Col_IntWordValue
#endif /* INTPTR_MAX != INTMAX_MAX */


/*
================================================================================
Section: Number Input/Output

Declarations:
	<Coatl_ReadIntWord>, <Coatl_ReadFloatWord>, <Coatl_WriteIntWord>, 
	<Coatl_WriteFloatWord>
================================================================================
*/

/*---------------------------------------------------------------------------
 * Typedef: Coatl_NumReadFormat
 *
 *	Number reading format. Fields marked with F are for floating points 
 *	only.
 *
 *	Character lists are arrays of Col_Char terminated by a COL_CHAR_INVALID
 *	value, or NULL for empty lists.
 *
 * Fields:
 *	radix		- Default numeric radix (2..62) when no prefix is used.
 *	ignoreChars	- List of ignored characters in the middle of sequence
 *			  (excluding leading or trailing characters).
 *	prefixChars	- List of prefix separator characters.
 *	radixChars	- List of C-style radix characters along with their 
 *			  radix value. To handle C-style octals, use the NUL
 *			  character in last position.
 *	pointChars	- [F] List of accepted radix point characters.
 *	expChars	- [F] List of accepted exponent characters.
 *	expC2Chars	- [F] List of accepted exponent characters for
 *			  C99-style 2-power exponent. Requires radix 16, either
 *			  explicitly or with prefix.
 *
 * See also:
 *	<Coatl_ReadIntWord>, <Coatl_ReadFloatWord>
 *---------------------------------------------------------------------------*/

typedef struct Coatl_NumReadFormat_RadixChar {
    Col_Char c; 
    unsigned int r;
} Coatl_NumReadFormat_RadixChar;
typedef struct Coatl_NumReadFormat {
    unsigned int radix;
    const Col_Char *ignoreChars;
    const Col_Char *prefixChars;
    const Coatl_NumReadFormat_RadixChar *radixChars;
    const Col_Char *pointChars;
    const Col_Char *expChars;
    const Col_Char *exp2Chars;
} Coatl_NumReadFormat;

/*---------------------------------------------------------------------------
 * Constants: Predefined Number Reading Formats
 *
 *  COATL_NUMREAD_DEFAULT	- Default format (same as NULL).
 *  COATL_INTREAD_C		- C-style integer format.
 *  COATL_FLOATREAD_C		- C-style floating point format (with C99
 *				  floats).
 *
 * See also:
 *	<Coatl_NumReadFormat>
 *---------------------------------------------------------------------------*/

#define COATL_NUMREAD_DEFAULT	NULL
#define COATL_INTREAD_C		((const Coatl_NumReadFormat *) 1)
#define COATL_FLOATREAD_C	((const Coatl_NumReadFormat *) 2)

/*---------------------------------------------------------------------------
 * Constants: Number Reading Word Type Flags
 *
 *	Accepted output word types for number reading. OR-able values.
 *
 *  COATL_INTREAD_NATIVE	- Native (Colibri) integer words.
 *  COATL_INTREAD_LARGE		- Large integer words.
 *  COATL_INTREAD_MP		- Multiple precision integer words.
 *  COATL_FLOATREAD_NATIVE	- Native (Colibri) floating point words.
 *  COATL_FLOATREAD_MP		- Multiple precision floating point words.
 *
 * See also:
 *	<Coatl_ReadIntWord>, <Coatl_ReadFloatWord>
 *---------------------------------------------------------------------------*/

#define COATL_INTREAD_NATIVE	1
#define COATL_INTREAD_LARGE	2
#define COATL_INTREAD_MP	4
#define COATL_FLOATREAD_NATIVE	1
#define COATL_FLOATREAD_MP	2

/*---------------------------------------------------------------------------
 * Typedef: Coatl_NumWriteFormat
 *
 *	Number writing format. Fields marked with F are for floating points 
 *	only.
 *
 * Fields:
 *	flags		- OR'ed <Number Write Flags> or zero.
 *	radix		- Numeric radix (2..62).
 *	minWidth	- Minimum number of output characters.
 *	padChar		- Character used to pad field up to *minWidth*.
 *	prefixChar	- Character used for radix prefix, or COL_CHAR_INVALID.
 *	groupSize	- Size of digit groups (zero for no grouping).
 *	groupChar	- Digit grouping character.
 *	minDigits	- Minimum number of output digits. For floating point 
 *			  numbers, this applies to the integral part.
 *	maxDigitsSigd	- [F] Max number of generated significand digits.
 *	minDigitsFrac	- [F] Minimum number of output digits for fractional 
 *			  part.
 *	maxDigitsFrac	- [F] Maximum number of output digits for fractional 
 *			  part.
 *	minDigitsExp	- [F] Minimum number of output digits for exponent.
 *	minFixed	- [F] Minimum exponent value for fixed-point notation.
 *	maxFixed	- [F] Maximum exponent value for fixed-point notation.
 *	pointChar	- [F] Character used for radix point.
 *	expMul		- [F] Multiple for exponent. If zero, this gives a zero 
 *			  integral part (e.g 1230.0 => 0.123e4).
 *	expChar		- [F] Character used for exponent.
 *
 * See also:
 *	<Coatl_WriteIntWord>, <Coatl_WriteFloatWord>, <Number Write Flags>
 *---------------------------------------------------------------------------*/

typedef struct Coatl_NumWriteFormat {
    int flags;
    unsigned int radix;
    size_t minWidth;
    Col_Char padChar;
    Col_Char prefixChar;
    size_t groupSize;
    Col_Char groupChar;
    size_t minDigits;
    size_t maxDigitsSigd;
    size_t minDigitsFrac, maxDigitsFrac;
    size_t minDigitsExp;
    long minFixed, maxFixed;
    Col_Char pointChar;
    unsigned long expMul;
    Col_Char expChar;
} Coatl_NumWriteFormat;

/*---------------------------------------------------------------------------
 * Constants: Number Write Flags
 *
 *	Flags for use in <Coatl_NumWriteFormat> *flags* field. Flags marked 
 *	with F are for floating points only.
 *
 *  COATL_NUMWRITE_PREFIX_C	- Use C-style radix prefix.
 *  COATL_NUMWRITE_PREFIX_0	- Use radix prefix for zero values as well.
 *  COATL_NUMWRITE_L		- Uses lower case letters for radices <= 36.
 *  COATL_NUMWRITE_PAD_0	- Uses 0 instead of padding character to pad 
 *				  field (use with <Coatl_NumWriteFormat> 
 *				  *minWidth* field).
 *  COATL_NUMWRITE_SIGNPAD	- Prefixes non-negative numbers with a padding 
 *				  character.
 *  COATL_NUMWRITE_PLUS		- Prefixes non-negative numbers with a + sign 
 *				  (this includes zero).
 *  COATL_NUMWRITE_POINT	- [F] Always add radix point even with zero 
 *				  fractional digits.
 *  COATL_NUMWRITE_EXP_PLUS	- [F] Prefix non-negative exponents with a + 
 *				  sign.
 *  COATL_NUMWRITE_EXP_C2	- [F] C99-style 2-power exponent. Requires radix
 *				  16 and <COATL_NUMWRITE_PREFIX_C>.
 *---------------------------------------------------------------------------*/

#define COATL_NUMWRITE_PREFIX_C	0x1
#define COATL_NUMWRITE_PREFIX_0	0x2
#define COATL_NUMWRITE_L	0x4
#define COATL_NUMWRITE_PAD_0	0x8
#define COATL_NUMWRITE_SIGNPAD	0x10
#define COATL_NUMWRITE_PLUS	0x20
#define COATL_NUMWRITE_POINT	0x40
#define COATL_NUMWRITE_EXP_PLUS	0x80
#define COATL_NUMWRITE_EXP_C2	0x100

/*---------------------------------------------------------------------------
 * Constants: Predefined Number Writing Formats
 *
 *  COATL_NUMWRITE_DEFAULT	- Default formatting (same as NULL).
 *  COATL_NUMWRITE_C16		- Hexadecimal C-style formatting (with C99
 *				  floats). Negative values use signed format.
 *  COATL_INTWRITE_C8		- Octal C-style integer formatting. Negative 
 *				  values use signed format. Only suitable
 *				  for integer numbers.
 * See also:
 *	<Coatl_NumWriteFormat>
 *---------------------------------------------------------------------------*/

#define COATL_NUMWRITE_DEFAULT	NULL
#define COATL_NUMWRITE_C16	((const Coatl_NumWriteFormat *) 1)
#define COATL_INTWRITE_C8	((const Coatl_NumWriteFormat *) 2)

/*
 * Remaining declarations.
 */

EXTERN int		Coatl_ReadIntWord(Col_RopeIterator begin, 
			    Col_RopeIterator end, 
			    const Coatl_NumReadFormat *format,
			    int types, Col_Word *wordPtr);
EXTERN int		Coatl_ReadFloatWord(Col_RopeIterator begin, 
			    Col_RopeIterator end, 
			    const Coatl_NumReadFormat *format,
			    int types, Col_Word *wordPtr);
EXTERN size_t		Coatl_WriteIntWord(Col_Word strbuf, Col_Word value,
			    const Coatl_NumWriteFormat *format);
EXTERN size_t		Coatl_WriteFloatWord(Col_Word strbuf, Col_Word value,
			    const Coatl_NumWriteFormat *format);

#endif /* _COATL_NUMBER */
