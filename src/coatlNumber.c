/*
 * File: coatlNumber.c
 *
 *	This file implements the number handling facility of CoATL.
 *
 * See also:
 *	<coatlJson.h>
 */

#include "../include/coatl.h"
#include "coatlInternal.h"

#include "coatlNumberInt.h"
#include "coatlParseInt.h"

#include <stdlib.h>
#include <limits.h>
#include <float.h>
#include <mpir.h>
#include <malloc.h> /* For malloc & alloca */

/*
 * Prototypes for functions used only in this file.
 */

#if INTPTR_MAX != INTMAX_MAX
static Col_CustomWordType largeIntWordType;
static Col_CustomWordSizeProc LargeIntSizeProc;
#endif /* INTPTR_MAX != INTMAX_MAX */
static Col_CustomWordType mpIntWordType;
static Col_CustomWordSizeProc MpIntSizeProc;
static Col_CustomWordFreeProc MpIntFreeProc;
static Col_CustomWordType mpFloatWordType;
static Col_CustomWordSizeProc MpFloatSizeProc;
static Col_CustomWordFreeProc MpFloatFreeProc;
static void		FormatDigitString(Col_Word strbuf, int sign, 
			    size_t nbDigits, const char *digits, size_t nbTrail,
			    const Coatl_NumWriteFormat *format);
static size_t		UIntDigits(uintmax_t value, int radix);
static size_t		UIntToString(uintmax_t value, char *str, int radix);
static int		ReadNumberPrefix(Col_RopeIterator begin, 
			    Col_RopeIterator end, 
			    const Coatl_NumReadFormat *format, int *negPtr,
			    unsigned int *radixPtr);


/*
================================================================================
Section: Large Integer Words
================================================================================
*/

#if INTPTR_MAX != INTMAX_MAX

/****************************************************************************
 * Internal Group: Large Integer Word Type
 ****************************************************************************/

/*---------------------------------------------------------------------------
 * Internal Variable: largeIntWordType
 *
 *	Custom word type holding an intmax_t on systems where it is larger than
 *	intptr_t supported by basic Colibri types.
 *
 * See also:
 *	<LargeIntSizeProc>
 *---------------------------------------------------------------------------*/

static Col_CustomWordType largeIntWordType = {
    0,
    "largeInt",
    LargeIntSizeProc,
    NULL, /* freeProc */
    NULL /* childrenProc */
};

/*---------------------------------------------------------------------------
 * Internal Function: LargeIntSizeProc
 *
 *	Multiple precision integer word type size proc. Follows 
 *	<Col_CustomWordSizeProc> signature.
 *
 * Argument:
 *	word	- Custom word to get size for.
 *
 * Result:
 *	The custom word size in bytes.
 *
 * See also:
 *	<mpIntWordType>
 *---------------------------------------------------------------------------*/

static size_t
LargeIntSizeProc(
    Col_Word word)
{
    return sizeof(intmax_t);
}

/*---------------------------------------------------------------------------
 * Internal Macro: TYPECHECK_LARGEINT
 *
 *	Type checking macro for large integers.
 *
 * Argument:
 *	word	- Checked word.
 *
 * Result:
 *	liPtr	- Variable receiving address of large integer.
 *
 * Side effects:
 *	Generate <COL_TYPECHECK> error when *word* is not a large integer word.
 *
 * See also:
 *	<COL_RUNTIMECHECK>
 *---------------------------------------------------------------------------*/

#ifdef _DEBUG
#define TYPECHECK_LARGEINT(word, liPtr) \
    COL_RUNTIMECHECK(((Col_WordType(word) & COL_CUSTOM) \
	    && Col_CustomWordInfo((word), (void **) &(liPtr)) \
	    == &largeIntWordType), COL_TYPECHECK, CoatlDomain, \
	    COATL_ERROR_LARGEINT, (word))
#else
#   define TYPECHECK_LARGEINT(word, liPtr) \
	Col_CustomWordInfo((word), (void **) &(liPtr)); if (0)
#endif


/****************************************************************************
 * Group: Large Integer Word Creation
 ****************************************************************************/

/*---------------------------------------------------------------------------
 * Function: Coatl_NewLargeIntWord
 *
 *	Create a new large integer word.
 *
 *	If the integer value is sufficiently small, return a Colibri integer.
 *
 *	On platforms where the largest supported integer differs from the native
 *	word type, large integers store the former whereas Colibri only support 
 *	the latter. This is the case on 32-bit platforms with 64-bit integer 
 *	support (e.g x86). On platforms where sizes are the same (e.g. x86-64),
 *	<Coatl_NewLargeIntWord> is simply an alias of <Col_NewIntWord>.
 *
 * Argument:
 *	value	- Large integer value of the word to create.
 *
 * Result:
 *	The new large integer word.
 *
 * Side effects:
 *	Allocates new word or call <Col_NewIntWord>.
 *---------------------------------------------------------------------------*/

Col_Word
Coatl_NewLargeIntWord(
    intmax_t value)
{
    Col_Word w;
    intmax_t *data;

    if (value >= INTPTR_MIN && value <= INTPTR_MAX) {
	/*
	 * Value fits within a native integer, return a Colibri integer word.
	 */

	return Col_NewIntWord((intptr_t) value);
    }

    w = Col_NewCustomWord(&largeIntWordType, sizeof(*data), (void **) &data);
    *data = value;
    return w;
}


/****************************************************************************
 * Group: Large Integer Word Predicates
 ****************************************************************************/

/*---------------------------------------------------------------------------
 * Function: Coatl_WordIsLargeInt
 *
 *	Test whether word is a large integer word.
 *
 *	On platforms where the largest supported integer differs from the native
 *	word type, large integers store the former whereas Colibri only support 
 *	the latter. This is the case on 32-bit platforms with 64-bit integer 
 *	support (e.g x86). On platforms where sizes are the same (e.g. x86-64),
 *	<Coatl_LargeIntWordValue> simply tests the result of <Col_WordType>
 *	against <COL_INT>.
 *
 * Argument:
 *	word	- The word to test.
 *
 * Result:
 *	Nonzero if word is a large integer word.
 *
 * See also:
 *	<Col_NewLargeIntWord>
 *---------------------------------------------------------------------------*/

int
Coatl_WordIsLargeInt(
    Col_Word word)
{
    void *dummy;
    return ((Col_WordType(word) & COL_CUSTOM) 
	    && Col_CustomWordInfo(word, &dummy) == &largeIntWordType);
}


/****************************************************************************
 * Group: Large Integer Word Accessors
 ****************************************************************************/

/*---------------------------------------------------------------------------
 * Function: Coatl_LargeIntWordValue
 *
 *	Get value of large integer word.
 *
 *	On platforms where the largest supported integer differs from the native
 *	word type, large integers store the former whereas Colibri only support 
 *	the latter. This is the case on 32-bit platforms with 64-bit integer 
 *	support (e.g x86). On platforms where sizes are the same (e.g. x86-64),
 *	<Coatl_LargeIntWordValue> is simply an alias of <Col_IntWordValue>.
 *
 * Argument:
 *	word	- The word to get value for.
 *
 * Type checking:
 *	*word* must be a valid large integer word.
 *
 * Result:
 *	The large integer value.
 *
 * See also:
 *	<Col_NewIntWord>
 *---------------------------------------------------------------------------*/

intmax_t
Coatl_LargeIntWordValue(
    Col_Word li)
{
    intmax_t *liPtr;

    /*
     * Check preconditions.
     */

    TYPECHECK_LARGEINT(li, liPtr) return 0;

    return *liPtr;
}

#endif /* INTPTR_MAX != INTMAX_MAX */ 


/*
================================================================================
Section: Multiple Precision Integer Words
================================================================================
*/

/****************************************************************************
 * Internal Group: Multiple Precision Integer Word Type
 ****************************************************************************/

/*---------------------------------------------------------------------------
 * Internal Variable: mpIntWordType
 *
 *	Custom word type holding a mpz_t structure.
 *
 * See also:
 *	<MpIntSizeProc>, <MpIntFreeProc>
 *---------------------------------------------------------------------------*/

static Col_CustomWordType mpIntWordType = {
    0,
    "mpInt",
    MpIntSizeProc,
    MpIntFreeProc,
    NULL /* childrenProc */
};

/*---------------------------------------------------------------------------
 * Internal Function: MpIntSizeProc
 *
 *	Multiple precision integer word type size proc. Follows 
 *	<Col_CustomWordSizeProc> signature.
 *
 * Argument:
 *	word	- Custom word to get size for.
 *
 * Result:
 *	The custom word size in bytes.
 *
 * See also:
 *	<mpIntWordType>
 *---------------------------------------------------------------------------*/

static size_t
MpIntSizeProc(
    Col_Word word)
{
    return sizeof(mpz_t);
}

/*---------------------------------------------------------------------------
 * Internal Function: MpIntFreeProc
 *
 *	Multiple precision integer word type cleanup proc. Follows 
 *	<Col_CustomWordFreeProc> signature.
 *
 * Argument:
 *	word	- Custom word to cleanup.
 *
 * Side effects:
 *	Calls mpz_clear cleanup procedure.
 *
 * See also: 
 *	<mpIntWordType>
 *---------------------------------------------------------------------------*/

static void
MpIntFreeProc(
    Col_Word word)
{
    mpz_t *mpi;

    REQUIRE(Col_CustomWordInfo(word, (void **) &mpi) == &mpIntWordType);

    mpz_clear(*mpi);
}


/****************************************************************************
 * Group: Multiple Precision Integer Word Predicates
 ****************************************************************************/

/*---------------------------------------------------------------------------
 * Function: Coatl_WordIsMpInt
 *
 *	Test whether word is a multiple precision integer word.
 *
 * Argument:
 *	word	- The word to test.
 *
 * Result:
 *	Nonzero if word is a multiple precision integer word.
 *---------------------------------------------------------------------------*/

int
Coatl_WordIsMpInt(
    Col_Word word)
{
    void *dummy;
    return ((Col_WordType(word) & COL_CUSTOM) 
	    && Col_CustomWordInfo(word, &dummy) == &mpIntWordType);
}


/*
================================================================================
Section: Multiple Precision Floating Point Words
================================================================================
*/

/****************************************************************************
 * Internal Group: Multiple Precision Floating Point Word Type
 ****************************************************************************/

/*---------------------------------------------------------------------------
 * Internal Variable: mpFloatWordType
 *
 *	Custom word type holding a mpz_t structure.
 *
 * See also:
 *	<MpFloatSizeProc>, <MpFloatFreeProc>
 *---------------------------------------------------------------------------*/

static Col_CustomWordType mpFloatWordType = {
    0,
    "mpFloat",
    MpFloatSizeProc,
    MpFloatFreeProc,
    NULL /* childrenProc */
};

/*---------------------------------------------------------------------------
 * Internal Function: MpFloatSizeProc
 *
 *	Multiple precision floating point word type size proc. Follows 
 *	<Col_CustomWordSizeProc> signature.
 *
 * Argument:
 *	word	- Custom word to get size for.
 *
 * Result:
 *	The custom word size in bytes.
 *
 * See also:
 *	<mpFloatWordType>
 *---------------------------------------------------------------------------*/

static size_t
MpFloatSizeProc(
    Col_Word word)
{
    return sizeof(mpf_t);
}

/*---------------------------------------------------------------------------
 * Internal Function: MpFloatFreeProc
 *
 *	Multiple precision floating point word type cleanup proc. Follows 
 *	<Col_CustomWordFreeProc> signature.
 *
 * Argument:
 *	word	- Custom word to cleanup.
 *
 * Side effects:
 *	Calls mpf_clear cleanup procedure.
 *
 * See also: 
 *	<mpFloatWordType>
 *---------------------------------------------------------------------------*/

static void
MpFloatFreeProc(
    Col_Word word)
{
    mpf_t *mpf;

    REQUIRE(Col_CustomWordInfo(word, (void **) &mpf) == &mpFloatWordType);

    mpf_clear(*mpf);
}


/****************************************************************************
 * Group: Multiple Precision Floating Point Word Predicates
 ****************************************************************************/

/*---------------------------------------------------------------------------
 * Function: Coatl_WordIsMpFloat
 *
 *	Test whether word is a multiple precision floating point word.
 *
 * Argument:
 *	word	- The word to test.
 *
 * Result:
 *	Nonzero if word is a multiple precision floating point word.
 *---------------------------------------------------------------------------*/

int
Coatl_WordIsMpFloat(
    Col_Word word)
{
    void *dummy;
    return ((Col_WordType(word) & COL_CUSTOM) 
	    && Col_CustomWordInfo(word, &dummy) == &mpFloatWordType);
}


/*
================================================================================
Section: Number Input/Output
================================================================================
*/

/*---------------------------------------------------------------------------
 * Internal Macro: DIGIT_VALUE
 *
 *	Numeric value of a digit character. Assumes digit character codepoints 
 *	are contiguous for ranges 0..9, A..Z, a..z (true in Unicode locale).
 *
 * Arguments:
 *	c	- Character (Caution: evaluated several times during macro 
 *		  expansion)
 *	b	- Numeric radix (2..62). When > 36, upper-case letters A..Z
 *		  represent 10..35, wherease lower-case letters a..z represent
 *		  36..61. When <= 36, upper- and lower-case letters have the
 *		  same values and represent 10..35.
 *
 * Results:
 *	If *c* is a digit character, its numeric value, else CHAR_MAX. Value
 *	may exceed the given radix.
 *---------------------------------------------------------------------------*/

#define DIGIT_VALUE(c, b) \
    ((unsigned char) (				\
       (c) <  '0' ? CHAR_MAX			\
     : (c) <= '9' ? (c)-'0'			\
     : (c) <  'A' ? CHAR_MAX			\
     : (c) <= 'Z' ? (c)-'A'+10			\
     : (c) <  'a' ? CHAR_MAX			\
     : (c) <= 'z' ? (c)-'a'+(((b)>36)?36:10)	\
     :              CHAR_MAX))

/*---------------------------------------------------------------------------
 * Internal Constant: TMP_USE_ALLOCA
 *
 *	Number of bytes above which we use malloc() instead of alloca() when
 *	allocating temporary storage.
 *
 * See also:
 *	<TMP_ALLOC>, <TMP_FREE>
 *---------------------------------------------------------------------------*/

#define TMP_USE_ALLOCA	100

/*---------------------------------------------------------------------------
 * Internal Macro: TMP_ALLOC
 *
 *	Stack- or heap-based allocation for temporary storage, based on the 
 *	required size.
 *
 * Argument:
 *	size	- Required size in bytes.
 *
 * Result:
 *	Address of allocated buffer.
 *
 * See also:
 *	<TMP_USE_ALLOCA>, <TMP_FREE>
 *---------------------------------------------------------------------------*/

#define TMP_ALLOC(size) \
    ((size) <= TMP_USE_ALLOCA ? alloca(size) : malloc(size))

/*---------------------------------------------------------------------------
 * Internal Macro: TMP_FREE
 *
 *	Free temporary memory allocated by <TMP_ALLOC>.
 *
 * Arguments:
 *	addr	- Value returned by <TMP_ALLOC>
 *	size	- Required size in bytes.
 *
 * See also:
 *	<TMP_USE_ALLOCA>, <TMP_FREE>
 *---------------------------------------------------------------------------*/

#define TMP_FREE(addr, size) \
    if ((size) > TMP_USE_ALLOCA) free(addr);

/*---------------------------------------------------------------------------
 * Internal Function: ParseUInt
 *
 *	Parse an unsigned integer number.
 *
 * Arguments:
 *	begin	- Beginning of digit sequence to parse.
 *	end	- End of sequence.
 *	min	- Minimum number of digits to parse.
 *	max	- Maximum number of digits to parse.
 *	radix	- Numeric radix (2..62).
 *	ignored	- If non-NULL, a COL_CHAR_INVALID-terminated string of 
 *		  characters to ignore.
 *
 * Results:
 *	Nonzero if success.
 *
 * Side effects:
 *	*begin* is moved just past the parsed sequence.
 *---------------------------------------------------------------------------*/

int
ParseUInt(
    Col_RopeIterator begin,
    Col_RopeIterator end,
    size_t min,
    size_t max,
    unsigned int radix,
    const Col_Char *ignored)
{
    size_t nb;
    Col_Char c;

    ASSERT(radix >= 2 && radix <= 62);

    /*
     * Consume digits.
     */

    ASSERT(min <= max);
    ASSERT(max);
    for (nb = 0; nb < max && Col_RopeIterCompare(begin, end) < 0; 
	    Col_RopeIterNext(begin)) {
	c = Col_RopeIterAt(begin);
	if (DIGIT_VALUE(c, radix) >= radix) {
	    /*
	     * Skip ignored chars, else stop there.
	     */

	    IF_CHAR_IN(ignored, c) continue;
	    break;
	}
	nb++;
    }
    if (nb < min) return 0;
    return 1;
}

/*---------------------------------------------------------------------------
 * Internal Function: ReadUInt
 *
 *	Read an unsigned integer number from a character sequence.
 *
 * Arguments:
 *	begin	- Beginning of digit sequence to read.
 *	end	- End of sequence (just past the last character to scan).
 *	radix	- Numeric radix (2..62).
 *	ignored	- If non-NULL, a COL_CHAR_INVALID-terminated string of 
 *		  characters to ignore.
 *
 * Results:
 *	Nonzero if value fits within uintmax_t. Additionally:
 *
 *	valuePtr    - Resulting value upon success.
 *
 * Side effects:
 *	*begin* is moved just past the last scanned character.
 *---------------------------------------------------------------------------*/

int
ReadUInt(
    Col_RopeIterator begin,
    Col_RopeIterator end,
    unsigned int radix,
    const Col_Char *ignored,
    uintmax_t *valuePtr)
{
    uintmax_t v = 0;
    Col_Char c;
    unsigned int d;

    ASSERT(radix >= 2 && radix <= 62);

    /*
     * Consume hex digits. Assume hex digit codepoints are contiguous (true
     * in Unicode locale).
     */

    for (; Col_RopeIterCompare(begin, end) < 0; Col_RopeIterNext(begin)) {
	c = Col_RopeIterAt(begin);
	d = DIGIT_VALUE(c, radix);
	if (d >= radix) {
	    /*
	     * Skip ignored chars, else stop there.
	     */

	    IF_CHAR_IN(ignored, c) continue;
	    break;
	}
	switch (radix) {
	case 2: 
	    if (v > (UINTMAX_MAX>>1)) return 0;
	    v <<= 1; v |= d; 
	    break;

	case 4:
	    if (v > (UINTMAX_MAX>>2)) return 0;
	    v <<= 2; v |= d; 
	    break;

	case 8:
	    if (v > (UINTMAX_MAX>>3)) return 0;
	    v <<= 3; v |= d; 
	    break;

	case 16:
	    if (v > (UINTMAX_MAX>>4)) return 0;
	    v <<= 4; v |= d; 
	    break;

	case 32:
	    if (v > (UINTMAX_MAX>>5)) return 0;
	    v <<= 5; v |= d; 
	    break;

	default:
	    if (v > (UINTMAX_MAX-d)/radix) return 0;
	    v *= radix; v += d; break;
	}
    }
    *valuePtr = v;
    return 1;
}

/*---------------------------------------------------------------------------
 * Internal Variable: digitChars
 *
 *	Digit characters for radices up to 62.
 *---------------------------------------------------------------------------*/

static const char digitChars[] = 
    "0123456789"
    "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    "abcdefghijklmnopqrstuvwxyz";

/*---------------------------------------------------------------------------
 * Internal Variable: digitCharsL
 *
 *	Digit characters for radices up to 36, with lowercase letters for digits
 *	above 10.
 *---------------------------------------------------------------------------*/

static const char digitCharsL[] = 
    "0123456789"
    "abcdefghijklmnopqrstuvwxyz";

/*---------------------------------------------------------------------------
 * Internal Variable: digitsPerBit
 *
 *	Number of digits per bit in given radix (2-62) = log(2)/log(radix).
 *---------------------------------------------------------------------------*/

static const double digitsPerBit[61] = {
    1.0000000000000000, 0.6309297535714574, 0.5000000000000000, 
    0.4306765580733931, 0.3868528072345416, 0.3562071871080222, 
    0.3333333333333334, 0.3154648767857287, 0.3010299956639811, 
    0.2890648263178878, 0.2789429456511298, 0.2702381544273197, 
    0.2626495350371936, 0.2559580248098155, 0.2500000000000000, 
    0.2446505421182260, 0.2398124665681315, 0.2354089133666382, 
    0.2313782131597592, 0.2276702486969530, 0.2242438242175754, 
    0.2210647294575037, 0.2181042919855316, 0.2153382790366965, 
    0.2127460535533632, 0.2103099178571525, 0.2080145976765095, 
    0.2058468324604345, 0.2037950470905062, 0.2018490865820999, 
    0.2000000000000000, 0.1982398631705605, 0.1965616322328226, 
    0.1949590218937863, 0.1934264036172708, 0.1919587200065601, 
    0.1905514124267734, 0.1892003595168700, 0.1879018247091076, 
    0.1866524112389434, 0.1854490234153689, 0.1842888331487062, 
    0.1831692509136336, 0.1820879004699383, 0.1810425967800402, 
    0.1800313266566926, 0.1790522317510414, 0.1781035935540111, 
    0.1771838201355579, 0.1762914343888821, 0.1754250635819545, 
    0.1745834300480449, 0.1737653428714400, 0.1729696904450771, 
    0.1721954337940981, 0.1714416005739134, 0.1707072796637201, 
    0.1699916162869140, 0.1692938075987814, 0.1686130986895011, 
    0.1679487789570419, 
};

/*---------------------------------------------------------------------------
 * Internal Variable: numReadDefaut
 *
 *	Default number reading format.
 *
 *	- Base-10.
 *	- No prefix.
 *	- No ignored char (inc. digit grouping).
 *	- Radix point is dot character *'.'*.
 *	- Exponent characters are *'e'* and *'E'*.
 *
 * See also:
 *	<COATL_NUMREAD_DEFAULT>
 *---------------------------------------------------------------------------*/

static const Col_Char numReadDefaut_pointChars[] = {'.', COL_CHAR_INVALID};
static const Col_Char numReadDefaut_expChars[] = {'e', 'E', COL_CHAR_INVALID};
static const Coatl_NumReadFormat numReadDefaut = {
    /* .radix = */		10,
    /* .ignoreChars = */	NULL,
    /* .prefixChars = */	NULL,
    /* .radixChars = */		NULL,
    /* .pointChars = */		numReadDefaut_pointChars,
    /* .expChars = */		numReadDefaut_expChars,
    /* .expC2Chars = */		NULL
};

/*---------------------------------------------------------------------------
 * Internal Variable: intReadC
 *
 *	C-style integer reading format.
 *
 *	- Defaults to base-10.
 *	- Prefixes: "0" for octal, "0x" and "0X" for hexadecimal.
 *	- No ignored char (inc. digit grouping).
 *
 * See also:
 *	<COATL_NUMREAD_DEFAULT>
 *---------------------------------------------------------------------------*/

static const Coatl_NumReadFormat_RadixChar intReadC_radixChar[] = {
    {'x', 16}, {'X', 16}, {'\0', 8}, {COL_CHAR_INVALID}
};
static const Coatl_NumReadFormat intReadC = {
    /* .radix = */		10,
    /* .ignoreChars = */	NULL,
    /* .prefixChars = */	NULL,
    /* .radixChars = */		intReadC_radixChar,
    /* .pointChars = */		NULL,
    /* .expChars = */		NULL,
    /* .expC2Chars = */		NULL,
};

/*---------------------------------------------------------------------------
 * Internal Variable: floatReadC
 *
 *	C-style floating point reading format.
 *
 *	- Defaults to base-10.
 *	- Prefixes: "0x" and "0X" for hexadecimal.
 *	- No ignored char (inc. digit grouping).
 *	- Radix point is dot character *'.'*.
 *	- Exponent characters are *'e'*,*'E'*,
 *	- C99-style exponent characters are *'p'* and *'P'*.
 *
 * See also:
 *	<COATL_NUMREAD_DEFAULT>
 *---------------------------------------------------------------------------*/

static const Coatl_NumReadFormat_RadixChar floatReadC_radixChar[] = {
    {'x', 16}, {'X', 16}, {COL_CHAR_INVALID}
};
static const Col_Char floatReadC_expC2Chars[] = {'p', 'P', COL_CHAR_INVALID};
static const Coatl_NumReadFormat floatReadC = {
    /* .radix = */		10,
    /* .ignoreChars = */	NULL,
    /* .prefixChars = */	NULL,
    /* .radixChars = */		floatReadC_radixChar,
    /* .pointChars = */		numReadDefaut_pointChars,
    /* .expChars = */		numReadDefaut_expChars,
    /* .expC2Chars = */		floatReadC_expC2Chars
};

/*---------------------------------------------------------------------------
 * Internal Function: ReadNumberPrefix
 *
 *	Read a number sign and radix.
 *
 * Arguments:
 *	begin	- Beginning of sequence to read.
 *	end	- End of sequence (just past the last character to scan).
 *	format	- Read format (NULL means default).
 *
 * Results:
 *	Non-zero for success. Additionally:
 *
 *	negPtr		- Whether number is negative.
 *	radixPtr	- Numeric radix (2..62). 
 *
 * Side effects:
 *	*begin* is moved just past the last scanned character.
 *---------------------------------------------------------------------------*/

static int
ReadNumberPrefix(
    Col_RopeIterator begin, 
    Col_RopeIterator end, 
    const Coatl_NumReadFormat *format,
    int *negPtr,
    unsigned int *radixPtr)
{
    Col_RopeIterator it;
    Col_Char c;
    unsigned int d;

    /*
     * Get optional sign.
     */

    *negPtr = 0;
    GET_CHAR(c, begin, end) return 0;
    SKIP_CHARS(format->ignoreChars, c, begin, end) return 0;
    switch (c) {
    case '-':
	*negPtr = 1;
	/* continued. */
    case '+':
	NEXT_CHAR(c, begin, end) return 0;
	SKIP_CHARS(format->ignoreChars, c, begin, end) return 0;
    }

    /*
     * Handle optional radix prefixes.
     */

    *radixPtr = format->radix;
    if (format->prefixChars || format->radixChars) {
	d = DIGIT_VALUE(c, 10);
	if (d == 0 && format->radixChars) {
	    /*
	     * Potential C-style prefix.
	     */

	    const Coatl_NumReadFormat_RadixChar *r;
	    Col_RopeIterSet(it, begin);
	    NEXT_CHAR(c, it, end) goto success;

	    /*
	     * Check for known radix chars. Handle special cases when radix char
	     * is NUL, such as with C-style octals.
	     */

	    for (r = format->radixChars; r->c != COL_CHAR_INVALID; r++) {
		if (r->c == c || r->c == '\0') {
		    /*
		     * Got radix char.
		     */

		    if (r->c != '\0') {
			NEXT_CHAR(c, it, end) return 0;
		    }
		    Col_RopeIterSet(begin, it);
		    *radixPtr = r->r;
		    break;
		}
	    }
	} else if (d < 10 && format->prefixChars) {
	    /*
	     * Potential radix prefix.
	     */

	    unsigned int radix = d;
	    Col_RopeIterSet(it, begin);
	    NEXT_CHAR(c, it, end) goto success;

	    if ((d = DIGIT_VALUE(c, 10)) < 10) {
		NEXT_CHAR(c, it, end) goto success;
		radix = radix*10 + d;
	    }

	    IF_CHAR_IN(format->prefixChars, c) {
		NEXT_CHAR(c, it, end) return 0;
		Col_RopeIterSet(begin, it);
		*radixPtr = radix;
	    }
	}
    }

success:
    return (*radixPtr >= 2 && *radixPtr <= 62);
}

/*---------------------------------------------------------------------------
 * Function: Coatl_ReadIntWord
 *
 *	Read an integer from a character sequence.
 *
 * Arguments:
 *	begin	- Beginning of sequence to read.
 *	end	- End of sequence (just past the last character to scan).
 *	format	- Read format (NULL means default).
 *	types	- Accepted output word types.
 *
 * Results:
 *	Nonzero if success. Additionally:
 *
 *	wordPtr    - If non-NULL, resulting word upon success. May be a Colibri
 *		     integer word, a CoATL large integer word, or a CoATL 
 *		     multiple precision integer word.
 *
 * Side effects:
 *	*begin* is moved just past the last scanned character.
 *
 * See also:
 *	<Coatl_NumReadFormat>, <Number Reading Word Type Flags>
 *---------------------------------------------------------------------------*/

int
Coatl_ReadIntWord(
    Col_RopeIterator begin, 
    Col_RopeIterator end, 
    const Coatl_NumReadFormat *format,
    int types,
    Col_Word *wordPtr)
{
    mpz_t *data;
    uintmax_t v;
    Col_RopeIterator it;
    Col_Char c;
    char *str, *p;
    size_t len;
    int neg = 0;
    unsigned int radix = 0;
    
    if (!format) format = &numReadDefaut;
    else if (format == COATL_INTREAD_C) format = &intReadC;
    else if (format == COATL_FLOATREAD_C) return 0;

    if (!types) types = COATL_INTREAD_NATIVE | COATL_INTREAD_LARGE 
	    | COATL_INTREAD_MP;

    /*
     * Get sign and radix.
     */

    if (!ReadNumberPrefix(begin, end, format, &neg, &radix)) return 0;

    /*
     * First try large integer scan.
     */
    
    Col_RopeIterSet(it, begin);
    if (ReadUInt(begin, end, radix, format->ignoreChars, &v)) {
	ASSERT(1+~1 == -1);
	if ((types & COATL_INTREAD_NATIVE) 
		&& (v <= (uintptr_t) INTPTR_MAX+(neg?1:0))) {
	    if (wordPtr) *wordPtr = Col_NewIntWord(neg ? -(intptr_t) v 
		    : (intptr_t) v);
	    return 1;
	} else if ((types & COATL_INTREAD_LARGE)
		&& (v <= (uintmax_t) INTMAX_MAX+(neg?1:0))) {
	    if (wordPtr) *wordPtr = Coatl_NewLargeIntWord(neg ? -(intmax_t) v
		    : (intmax_t) v);
	    return 1;
	}
    }
    Col_RopeIterSet(begin, it);

    /*
     * Scan multiple precision integer. Assumes digit character codepoints
     * fit into a char.
     */

    if (!(types & COATL_INTREAD_MP)) return 0;

    if (!wordPtr) {
	/*
	 * Consume all suitable characters.
	 */

	for (; Col_RopeIterCompare(begin, end) < 0; 
		Col_RopeIterNext(begin)) {
	    c = Col_RopeIterAt(begin);
	    if (DIGIT_VALUE(c, radix) < radix) continue;
	    IF_CHAR_IN(format->ignoreChars, c) continue;
	    break;
	}
	return 1;
    }

    /*
     * Build string suitable for MPIR's scan proc.
     */

    len = Col_RopeIterIndex(end) - Col_RopeIterIndex(begin);
    str = (char *) TMP_ALLOC(len+1);
    for (p = str; Col_RopeIterCompare(begin, end) < 0; 
	    Col_RopeIterNext(begin)) {
	c = Col_RopeIterAt(begin);
	if (DIGIT_VALUE(c, radix) < radix) {*p++ = c; continue; }
	IF_CHAR_IN(format->ignoreChars, c) continue;
	break;
    }
    *p = 0;
    *wordPtr = Col_NewCustomWord(&mpIntWordType, sizeof(*data), (void **) &data);
    mpz_init_set_str(*data, str, radix);
    if (neg) mpz_neg(*data, *data);
    TMP_FREE(str, len+1);
    return 1;
}

/*---------------------------------------------------------------------------
 * Function: Coatl_ReadFloatWord
 *
 *	Read a floating point from a character sequence.
 *
 * Arguments:
 *	begin	- Beginning of sequence to read.
 *	end	- End of sequence (just past the last character to scan).
 *	format	- Read format (NULL means default).
 *	types	- Accepted output word types.
 *
 * Results:
 *	Nonzero if success. Additionally:
 *
 *	wordPtr    - If non-NULL, resulting word upon success. May be a Colibri
 *		     floating point word or a CoATL multiple precision floating
 *		     point word.
 *
 * Side effects:
 *	*begin* is moved just past the last scanned character.
 *
 * See also:
 *	<Coatl_NumReadFormat>, <Number Reading Word Type Flags>
 *---------------------------------------------------------------------------*/

int
Coatl_ReadFloatWord(
    Col_RopeIterator begin, 
    Col_RopeIterator end, 
    const Coatl_NumReadFormat *format,
    int types,
    Col_Word *wordPtr)
{
    mpf_t mpf, *data;
    double f;
    Col_Char c;
    char *str, *p;
    size_t len;
    int neg = 0, eneg = 0;
    unsigned int radix = 0;
    enum {NO_EXP, EXP, EXP2} exp = NO_EXP;

    if (!format) format = &numReadDefaut;
    else if (format == COATL_INTREAD_C) return 0;
    else if (format == COATL_FLOATREAD_C) format = &floatReadC;

    if (!types) types = COATL_FLOATREAD_NATIVE | COATL_FLOATREAD_MP;

    /*
     * Get sign and radix.
     */

    if (!ReadNumberPrefix(begin, end, format, &neg, &radix)) return 0;

    if (!wordPtr) {
	/*
	 * Consume all suitable characters.
	 */

	for (; Col_RopeIterCompare(begin, end) < 0; 
		Col_RopeIterNext(begin)) {
	    c = Col_RopeIterAt(begin);
	    if (DIGIT_VALUE(c, radix) < radix) continue;
	    IF_CHAR_IN(format->pointChars, c) continue;
	    IF_CHAR_IN(format->expChars, c) {
		/*
		 * Exponent expressed in same radix as mantissa.
		 */

		exp = EXP;
		NEXT_CHAR(c, begin, end) return 0;
		switch (c) {
		case '-':
		case '+':
		    NEXT_CHAR(c, begin, end) return 0;
		}
		break;
	    }
	    IF_CHAR_IN(format->exp2Chars, c) {
		/*
		 * 2-power exponent needs specific handling.
		 */

		exp = EXP2;
		NEXT_CHAR(c, begin, end) return 0;
		switch (c) {
		case '-':
		case '+':
		    NEXT_CHAR(c, begin, end) return 0;
		}
		break;
	    }
	    IF_CHAR_IN(format->ignoreChars, c) continue;
	    break;
	}

	/*
	 * Then exponent.
	 */

	if (exp == EXP) {
	    for (; Col_RopeIterCompare(begin, end) < 0; 
		    Col_RopeIterNext(begin)) {
		c = Col_RopeIterAt(begin);
		if (DIGIT_VALUE(c, radix) < radix) continue;
		IF_CHAR_IN(format->ignoreChars, c) continue;
		break;
	    }
	}

	if (exp == EXP2) {
	    /*
	     * Scan remainder as 2-power exponent value in decimal.
	     */

	    uintmax_t e;
	    if (!ReadUInt(begin, end, 10, format->ignoreChars, &e) 
		|| e != (mp_bitcnt_t) e) return 0;
	}

	return 1;
    }

    /*
     * Rely on MPIR library, float scanning is too much work to do reliably 
     * because of rounding issues.
     */

    len = Col_RopeIterIndex(end) - Col_RopeIterIndex(begin);
    str = (char *) TMP_ALLOC(len+1);
    exp = 0;

    /*
     * First mantissa.
     */

    for (p = str; Col_RopeIterCompare(begin, end) < 0; 
	    Col_RopeIterNext(begin)) {
	c = Col_RopeIterAt(begin);
	if (DIGIT_VALUE(c, radix) < radix) {*p++ = c; continue; }
	IF_CHAR_IN(format->pointChars, c) {*p++ = '.'; continue; }
	IF_CHAR_IN(format->expChars, c) {
	    /*
	     * Exponent expressed in same radix as mantissa.
	     */

	    exp = EXP;
	    *p++ = '@';
	    NEXT_CHAR(c, begin, end) return 0;
	    switch (c) {
	    case '-':
	    case '+':
		*p++ = c;
		NEXT_CHAR(c, begin, end) return 0;
	    }
	    break;
	}
	IF_CHAR_IN(format->exp2Chars, c) {
	    /*
	     * 2-power exponent needs specific handling.
	     */

	    exp = EXP2;
	    NEXT_CHAR(c, begin, end) return 0;
	    switch (c) {
	    case '-':
		eneg = 1;
		/* continued. */
	    case '+':
		NEXT_CHAR(c, begin, end) return 0;
	    }
	    break;
	}
	IF_CHAR_IN(format->ignoreChars, c) continue;
	break;
    }

    /*
     * Then exponent.
     */

    if (exp == EXP) {
	for (; Col_RopeIterCompare(begin, end) < 0; 
		Col_RopeIterNext(begin)) {
	    c = Col_RopeIterAt(begin);
	    if (DIGIT_VALUE(c, radix) < radix) {*p++ = c; continue; }
	    IF_CHAR_IN(format->ignoreChars, c) continue;
	    break;
	}
    }

    *p = 0;
    mpf_init_set_str(mpf, str, radix);
    if (neg) mpf_neg(mpf, mpf);
    TMP_FREE(str, len+1);

    if (exp == EXP2) {
	/*
	 * Scan remainder as 2-power exponent value in decimal.
	 */

	uintmax_t e;
	if (!ReadUInt(begin, end, 10, format->ignoreChars, &e) 
	    || e != (mp_bitcnt_t) e) return 0;
	if (eneg) {
	    mpf_div_2exp(mpf, mpf, (mp_bitcnt_t) e);
	} else {
	    mpf_mul_2exp(mpf, mpf, (mp_bitcnt_t) e);
	}
    }

    /*
     * Get double value from multiple precision float. If we don't want MP floats,
     * or if values are identical and we accept native floats, then use a float 
     * word instead.
     */

    f = mpf_get_d(mpf);
    if (!(types & COATL_FLOATREAD_MP) || ((types & COATL_FLOATREAD_NATIVE) 
	    && mpf_cmp_d(mpf, f) == 0)) {
	mpf_clear(mpf);
	*wordPtr = Col_NewFloatWord(f);
    } else {
	*wordPtr = Col_NewCustomWord(&mpFloatWordType, sizeof(*data), (void **) &data);
	memcpy(data, &mpf, sizeof(mpf));
    }
    return 1;
}

/*---------------------------------------------------------------------------
 * Internal Variable: numWriteDefaut
 *
 *	Default number writing format.
 *
 *	- Base-10.
 *	- No prefix.
 *	- No digit grouping.
 *	- No leading zeroes in integral part.
 *	- No trailing zeroes in fractional part.
 *	- No truncation.
 *	- Optional radix point is dot character *'.'*.
 *	- Optional exponent character is lowercase *'e'*.
 *
 * See also:
 *	<COATL_NUMWRITE_DEFAULT>
 *---------------------------------------------------------------------------*/

static const Coatl_NumWriteFormat numWriteDefaut = {
    /* .flags = */		0,
    /* .radix = */		10,
    /* .minWidth = */		0,
    /* .padChar = */		' ',
    /* .prefixChar = */		COL_CHAR_INVALID,
    /* .groupSize = */		0,
    /* .groupChar = */		COL_CHAR_INVALID,
    /* .minDigits = */		1,
    /* .maxDigitsSigd = */	SIZE_MAX,
    /* .minDigitsFrac = */	0,
    /* .maxDigitsFrac = */	SIZE_MAX,
    /* .minDigitsExp = */	0,
    /* .minFixed = */		INT_MAX,
    /* .maxFixed = */		INT_MIN,
    /* .pointChar = */		'.',
    /* .expMul = */		1,
    /* .expChar = */		'e',
};

/*---------------------------------------------------------------------------
 * Internal Variable: numWriteC16
 *
 *	C hex number writing format. Uses C99 for floats.
 *
 *	- Base-16.
 *	- Lowercase prefix *'0x'*.
 *	- No digit grouping.
 *	- No leading zeroes in integral part.
 *	- No trailing zeroes in fractional part.
 *	- No truncation.
 *	- Optional radix point is dot character *'.'*.
 *	- Optional exponent character is lowercase *'p'*.
 *	- Power of 2 exponent in decimal.
 *
 * See also:
 *	<COATL_NUMWRITE_C16>
 *---------------------------------------------------------------------------*/

static const Coatl_NumWriteFormat numWriteC16 = {
    /* .flags = */		COATL_NUMWRITE_PREFIX_C | COATL_NUMWRITE_L 
				| COATL_NUMWRITE_EXP_C2,
    /* .radix = */		16,
    /* .minWidth = */		0,
    /* .padChar = */		' ',
    /* .prefixChar = */		'x',
    /* .groupSize = */		0,
    /* .groupChar = */		COL_CHAR_INVALID,
    /* .minDigits = */		1,
    /* .maxDigitsSigd = */	SIZE_MAX,
    /* .minDigitsFrac = */	0,
    /* .maxDigitsFrac = */	SIZE_MAX,
    /* .minDigitsExp = */	0,
    /* .minFixed = */		INT_MAX,
    /* .maxFixed = */		INT_MIN,
    /* .pointChar = */		'.',
    /* .expMul = */		1,
    /* .expChar = */		'p',
};

/*---------------------------------------------------------------------------
 * Internal Variable: intWriteC8
 *
 *	C octal number writing format. Only suitable for integer numbers.
 *
 *	- Base-8.
 *	- Lowercase prefix *'0'*.
 *	- No digit grouping.
 *	- No extra leading zeroes.
 *
 * See also:
 *	<COATL_INTWRITE_C8>
 *---------------------------------------------------------------------------*/

static const Coatl_NumWriteFormat intWriteC8 = {
    /* .flags = */	COATL_NUMWRITE_PREFIX_C,
    /* .radix = */	8,
    /* .minWidth = */	0,
    /* .padChar = */	' ',
    /* .prefixChar = */	COL_CHAR_INVALID,
    /* .groupSize = */	0,
    /* .groupChar = */	COL_CHAR_INVALID,
    /* .minDigits = */	1,
};

/*---------------------------------------------------------------------------
 * Internal Constants: Number Format Flag Masks
 *
 *	Bit masks for <Coatl_NumWriteFormat> flag field.
 *
 *  NUMWRITE_SIGN_MASK		- Mask for sign flag values:
 *				  <COATL_NUMWRITE_SIGNPAD>, 
 *				  <COATL_NUMWRITE_PLUS>
 *
 * See also:
 *	<Coatl_NumWriteFormat>, <Number Write Flags>
 *---------------------------------------------------------------------------*/

#define NUMWRITE_SIGN_MASK	0x30

/*---------------------------------------------------------------------------
 * Internal Function: UIntDigits
 *
 *	Compute number of digits needed to express an unsigned integer value 
 *	in a given radix
 *
 * Arguments:
 *	value	- Value.
 *	radix	- Numeric radix, 2..62.
 *
 * Result:
 *	Number of digits.
 *---------------------------------------------------------------------------*/

static size_t
UIntDigits(
    uintmax_t value,
    int radix)
{
    size_t nb = 0;

    ASSERT(radix >= 2 && radix <= 62);

    switch (radix) {
    case 2:  while (value) {value >>= 1;    nb++;} break;
    case 4:  while (value) {value >>= 2;    nb++;} break;
    case 8:  while (value) {value >>= 3;    nb++;} break;
    case 16: while (value) {value >>= 4;    nb++;} break;
    case 32: while (value) {value >>= 5;    nb++;} break;
    default: while (value) {value /= radix; nb++;} break;
    }

    return nb;
}

/*---------------------------------------------------------------------------
 * Internal Function: UIntToString
 *
 *	Write an unsigned integer value to a character array in reverse order.
 *
 * Arguments:
 *	value	- Value to write.
 *	str	- Character buffer, must be sufficiently large.
 *	radix	- Numeric radix, 2..62, or -2..-36 for lowercase letters.
 *
 * Result:
 *	Number of characters written.
 *
 * Side effects:
 *	Characters are written to the character buffer.
 *---------------------------------------------------------------------------*/

static size_t
UIntToString(
    uintmax_t value,
    char *str,
    int radix)
{
    char *p, *p2;
    size_t len;

    ASSERT((radix >= 2 && radix <= 62) || (radix <= -2 && radix >= -36));

    if (value == 0) {
	/*
	 * Zero gives "0".
	 */

	*str++ = '0';
	return 1;
    }

    /*
     * Build digit string in reverse order.
     */

    if (radix < 0) {
	radix = -radix;
	switch (radix) {
	case 2:  for (p = str; value; value >>= 1)    *p++ = digitCharsL[value & 0x01]; break;
	case 4:  for (p = str; value; value >>= 2)    *p++ = digitCharsL[value & 0x03]; break;
	case 8:  for (p = str; value; value >>= 3)    *p++ = digitCharsL[value & 0x07]; break;
	case 16: for (p = str; value; value >>= 4)    *p++ = digitCharsL[value & 0x0F]; break;
	case 32: for (p = str; value; value >>= 5)    *p++ = digitCharsL[value & 0x1F]; break;
	default: for (p = str; value; value /= radix) *p++ = digitCharsL[value % radix];
	}
    } else {
	switch (radix) {
	case 2:  for (p = str; value; value >>= 1)    *p++ = digitChars[value & 0x01]; break;
	case 4:  for (p = str; value; value >>= 2)    *p++ = digitChars[value & 0x03]; break;
	case 8:  for (p = str; value; value >>= 3)    *p++ = digitChars[value & 0x07]; break;
	case 16: for (p = str; value; value >>= 4)    *p++ = digitChars[value & 0x0F]; break;
	case 32: for (p = str; value; value >>= 5)    *p++ = digitChars[value & 0x1F]; break;
	default: for (p = str; value; value /= radix) *p++ = digitChars[value % radix];
	}
    }
    len = p-str;

    /*
     * Reverse string.
     */

    for (p2 = str; p2 < p; p2++) {
	char c = *--p;
	*p = *p2;
	*p2 = c;
    }

    return len;
}

/*---------------------------------------------------------------------------
 * Internal Function: WriteUInt
 *
 *	Write an unsigned integer value to a string buffer in canonical form.
 *	Canonical form is:
 *
 *	- no leading or trailing whitespaces,
 *	- no digit grouping,
 *	- no leading zero for nonzero values,
 *	- uppercase digits for 10 < radix <= 36.
 *
 * Arguments:
 *	strbuf		- Output string buffer.
 *	value		- Value to write.
 *	radix		- Numeric radix (2..62).
 *
 * Side effects:
 *	Characters are appended to the string buffer.
 *---------------------------------------------------------------------------*/

void
WriteUInt(
    Col_Word strbuf, 
    uintmax_t value,
    unsigned int radix)
{
    char str[sizeof(uintmax_t)*CHAR_BIT], *p;
    size_t len;

    ASSERT(radix >= 2 && radix <= 62);

    len = UIntToString(value, str, radix);
    for (p = str; p < str+len; p++) Col_StringBufferAppendChar(strbuf, *p);
}

/*---------------------------------------------------------------------------
 * Internal Function: FormatDigitString
 *
 *	Write a digit string to a string buffer in the given format.
 *
 * Arguments:
 *	strbuf		- Output string buffer.
 *	sign		- Sign: < 0 for negative, > 0 for positive, else 0.
 *	nbDigits	- Number of digits to write.
 *	digits		- Digit string to write.
 *	nbTrail		- Number of trailing zeroes.
 *	format		- Number format.
 *
 * Side effects:
 *	Characters are appended to the string buffer.
 *---------------------------------------------------------------------------*/

static void
FormatDigitString(
    Col_Word strbuf, 
    int sign,
    size_t nbDigits,
    const char *digits,
    size_t nbTrail,
    const Coatl_NumWriteFormat *format)
{
    Col_CustomWordType *wt = NULL;
    const char *p;
    Col_Char c;
    size_t nbPad, minDigits, prefixLen, width, i;

    /*
     * Compute minimum width.
     */

    width = 0;

    /* - Sign */
    width += ((sign < 0) || (format->flags & NUMWRITE_SIGN_MASK)) ? 1 : 0;

    /* - Prefix */
    if (format->flags & COATL_NUMWRITE_PREFIX_C) {
	/*
	 * C-style prefix: '0' + prefix char.
	 */

	prefixLen = (format->prefixChar != COL_CHAR_INVALID) ? 2 : 1;
    } else if (format->prefixChar != COL_CHAR_INVALID) {
	/*
	 * Base-10 radix + prefix char?
	 */

	prefixLen = (format->radix < 10) ? 2 : 3;
    } else {
	prefixLen = 0;
    }
    if (sign || (format->flags & COATL_NUMWRITE_PREFIX_0)) width += prefixLen;

    /* - Digits, grouping and padding characters */
    minDigits = (format->minDigits > nbDigits) ? format->minDigits : nbDigits;
    if (format->minWidth > width && format->flags & COATL_NUMWRITE_PAD_0) {
	/*
	 * Pad available space with zero digit sequences.
	 */

	if (format->groupSize) {
	    /*
	     * Adjust width for group separators.
	     */

	    size_t nbSep = (format->minWidth - width) / (format->groupSize + 1);
	    if (minDigits <= format->minWidth - width - nbSep) {
		minDigits = format->minWidth - width - nbSep;
		if (! ((format->minWidth - width) % (format->groupSize + 1))) {
		    /*
		     * Add one extra zero so that sequence doesn't start witha 
		     * group separator.
		     */

		    minDigits++;
		}
	    }
	} else if (minDigits < format->minWidth - width) {
	    /*
	     * Extra zeroes take remaining width.
	     */

	    minDigits = format->minWidth - width;
	}
    }

    /* - Digits */
    width += minDigits;

    /* - Grouping characters */
    if (minDigits && format->groupSize) {
	width += (minDigits-1) / format->groupSize;
    }

    /* - Padding characters */
    nbPad = (format->minWidth > width) ? (format->minWidth - width) : 0;

    /*
     * Output string.
     */

    /* - Padding characters */
    for (i = 0; i < nbPad; i++) {
	Col_StringBufferAppendChar(strbuf, format->padChar);
    }

    /* - Sign */
    if (sign < 0) {
	Col_StringBufferAppendChar(strbuf, '-');
    } else {
	switch (format->flags & NUMWRITE_SIGN_MASK) {
	case COATL_NUMWRITE_PLUS:
	    Col_StringBufferAppendChar(strbuf, '+');
	    break;

	case COATL_NUMWRITE_SIGNPAD:
	    Col_StringBufferAppendChar(strbuf, format->padChar);
	    break;
	}
    }

    /* - Prefix */
    if (sign || (format->flags & COATL_NUMWRITE_PREFIX_0)) {
	if (format->flags & COATL_NUMWRITE_PREFIX_C) {
	    Col_StringBufferAppendChar(strbuf, '0');
	    if (format->prefixChar != COL_CHAR_INVALID) {
		Col_StringBufferAppendChar(strbuf, format->prefixChar);
	    }
	} else if (format->prefixChar != COL_CHAR_INVALID) {
	    if (format->radix >= 10) {
		Col_StringBufferAppendChar(strbuf, 
			digitChars[format->radix/10]);
	    }
	    Col_StringBufferAppendChar(strbuf, digitChars[format->radix%10]);
	    Col_StringBufferAppendChar(strbuf, format->prefixChar);
	}
    }

    /* - Digits */
    p = digits;
    i = minDigits;
    while (i > 0) {
	if (i > nbDigits || i <= nbTrail) {
	    c = '0';
	} else {
	    c = *p++;
	}
	Col_StringBufferAppendChar(strbuf, c);
	i--;
	if (i && format->groupSize && (i % format->groupSize) == 0) {
	    Col_StringBufferAppendChar(strbuf, format->groupChar);
	}
    }
}

/*---------------------------------------------------------------------------
 * Function: Coatl_WriteIntWord
 *
 *	Write an integer word to a string buffer in the given format.
 *
 * Arguments:
 *	strbuf	- Output string buffer.
 *	word	- Integer word to write.
 *	format	- Write format (NULL means default).
 *
 * Result:
 *	Number of characters written.
 *
 * Side effects:
 *	Characters are appended to the string buffer.
 *
 * See also:
 *	<Coatl_NumWriteFormat>
 *---------------------------------------------------------------------------*/

size_t
Coatl_WriteIntWord(
    Col_Word strbuf, 
    Col_Word word,
    const Coatl_NumWriteFormat *format)
{
    Col_CustomWordType *wt = NULL;
    void *data;
    intmax_t v;
    char *buf = NULL;
    size_t bufSize, nbDigits, oldLen;
    int sign;
    int type;

    if (!format) format = &numWriteDefaut;
    else if (format == COATL_INTWRITE_C8) format = &intWriteC8;
    else if (format == COATL_NUMWRITE_C16) format = &numWriteC16;

    //TODO error handling
    if (format->radix < 2 || format->radix > 62) return 0;

    oldLen = Col_StringBufferLength(strbuf);

    type = Col_WordType(word);
    if (type & COL_INT) {
	/*
	 * Native integer.
	 */

	v = Col_IntWordValue(word);
    } else if (type & COL_CUSTOM) {
	wt = Col_CustomWordInfo(word, &data);
    }
#if INTPTR_MAX != INTMAX_MAX
    if (wt == &largeIntWordType) {
	/*
	 * Large integer.
	 */

	v = *(intmax_t *) data;
    }
#endif /* INTPTR_MAX != INTMAX_MAX */
    if (wt == &mpIntWordType) {
	/*
	 * Get digit string from multiple precision integer.
	 */

	mpz_t *pv = (mpz_t *) data;
	sign = mpz_cmp_si(*pv, 0);
	if (sign == 0) {
	    nbDigits = 0;
	} else {
	    bufSize = mpz_sizeinbase(*pv, format->radix) + 2;
	    buf = (char *) TMP_ALLOC(bufSize);
	    mpz_get_str(buf, ((format->flags & COATL_NUMWRITE_L) 
		    && format->radix <= 36) ? format->radix 
		    : -(int) format->radix, *pv);
	    nbDigits = strlen(buf)-(sign < 0 ? 1 : 0);
	}
    } else {
	/*
	 * Get digit string from native integer.
	 */

	if (v == 0) {
	    sign = 0;
	    nbDigits = 0;
	} else {
	    bufSize = sizeof(v) * CHAR_BIT+1;
	    buf = (char *) TMP_ALLOC(bufSize);
	    if (v < 0) {
		sign = -1;
		nbDigits = UIntToString((uintmax_t) -v, buf, 
			(format->radix <= 36 
			&& (format->flags & COATL_NUMWRITE_L) 
			? -(int) format->radix : format->radix));
	    } else {
		sign = 1;
		nbDigits = UIntToString(v, buf, 
			(format->radix <= 36 
			&& (format->flags & COATL_NUMWRITE_L)
			? -(int) format->radix : format->radix));
	    }
	}
    }

    /*
     * Output formatted digit string.
     */

    FormatDigitString(strbuf, sign, nbDigits, buf 
	    + ((wt == &mpIntWordType && sign < 0) ? 1 : 0), 0, format);

    if (buf) {
	ASSERT(sign != 0 || format->minDigits > 0);
	TMP_FREE(buf, bufSize);
    }

    return Col_StringBufferLength(strbuf) - oldLen;
}

/*---------------------------------------------------------------------------
 * Function: Coatl_WriteFloatWord
 *
 *	Write a floating point word to a string buffer in the given format.
 *
 * Arguments:
 *	strbuf	- Output string buffer.
 *	word	- Floating point word to write.
 *	format	- Write format (NULL means default).
 *
 * Result:
 *	Number of characters written.
 *
 * Side effects:
 *	Characters are appended to the string buffer.
  *
 * See also:
 *	<Coatl_NumWriteFormat>
*---------------------------------------------------------------------------*/

size_t
Coatl_WriteFloatWord(
    Col_Word strbuf, 
    Col_Word word,
    const Coatl_NumWriteFormat *format)
{
    mpf_t v, *pv;
    mp_exp_t exp;
    char *buf = NULL, *p;
    Col_Char c;
    size_t bufSize, maxDigitsSigd, nbDigitsSigd, nbDigitsInt, nbDigitsFrac, 
	    nbLead0Frac, firstTrail0Frac, nbDigitsExp, width, i, oldLen;
    int sign, fixed;
    Coatl_NumWriteFormat intFormat;
    int type;

    if (!format) format = &numWriteDefaut;
    else if (format == COATL_INTWRITE_C8) return 0; //TODO error handling
    else if (format == COATL_NUMWRITE_C16) format = &numWriteC16;

    //TODO error handling
    if (format->radix < 2 || format->radix > 62) return 0;

    oldLen = Col_StringBufferLength(strbuf);

    /*
     * Get significand digits and exponent. Always rely on multiple precision 
     * library.
     */

    type = Col_WordType(word);
    if (type & COL_FLOAT) {
	/*
	 * Native floating point.
	 */

	double d = Col_FloatWordValue(word);
	//TODO handle special values (inf, NaN...)
	if (d == 0) {
	    sign = 0;
	} else {
	    /*
	     * Convert to multiple precision floating point.
	     */

	    sign = (d < 0) ? -1 : 1;
	    mpf_init_set_d(v, d);
	    pv = &v;
	}
    } else if (type & COL_CUSTOM) {
	void *data;
	Col_CustomWordType *wt = Col_CustomWordInfo(word, &data);
	if (wt == &mpFloatWordType) {
	    /*
	     * Multiple precision floating point.
	     */

	    pv = (mpf_t *) data;
	    sign = mpf_cmp_ui(*pv, 0);
	} else return 0; //TODO typecheck ?
    }

    /*
     * Convert to string + exponent. MPIR uses an implicitly normalized string,
     * i.e. there is an implicit radix point after the first digit.
     */

    if (sign == 0) {
	maxDigitsSigd = 0;
	nbDigitsSigd = 0;
	exp = 0;
    } else {
	maxDigitsSigd = (size_t) (mpf_get_prec(*pv)
		* digitsPerBit[format->radix-2]);
	if (format->maxDigitsSigd < maxDigitsSigd) {
	    /*
	     * Need less digits.
	     */

	    maxDigitsSigd = format->maxDigitsSigd ? format->maxDigitsSigd : 1;
	}
	bufSize = maxDigitsSigd + 2;
	buf = (char *) TMP_ALLOC(bufSize);
	mpf_get_str(buf, &exp, ((format->flags & COATL_NUMWRITE_L) 
		    && format->radix <= 36) ? format->radix 
		    : -(int) format->radix, maxDigitsSigd, *pv);
	if (type & COL_FLOAT) mpf_clear(v);
	nbDigitsSigd = strlen(buf)-(sign < 0 ? 1 : 0);
	ASSERT(nbDigitsSigd <= maxDigitsSigd);
    }

    /*
     * MPIR uses an implicit radix point before the first digit. Compute actual 
     * exponent and number of integer + fractional digits.
     */

adjustExp:
    fixed = (exp >= format->minFixed && exp <= format->maxFixed);
    if (fixed) {
	/*
	 * Use fixed-point notation within this exponent interval.
	 */

	nbDigitsInt = (exp >= 0) ? exp : 0;
	nbDigitsFrac = (nbDigitsSigd > nbDigitsInt) ? nbDigitsSigd - exp : 0;
    } else if (sign && format->expMul > 0) {
	/*
	 * Round down exponent value to a multiple of format->expMul.
	 */

	nbDigitsInt = ((exp-1) % format->expMul) + 1;
	nbDigitsFrac = (nbDigitsSigd > nbDigitsInt) ? nbDigitsSigd - nbDigitsInt
		: 0;
	exp -= (mp_exp_t) nbDigitsInt;
    } else {
	/*
	 * Zero integral digits and no leading fractional zero: same format as 
	 * MPIR.
	 */

	nbDigitsInt = 0;
	nbDigitsFrac = nbDigitsSigd;
    }

    /*
     * Adjust number of fractional digits.
     */

    if (nbDigitsFrac < format->minDigitsFrac) {
	nbDigitsFrac = format->minDigitsFrac;
    }
    if (nbDigitsFrac > format->maxDigitsFrac) {
	nbDigitsFrac = format->maxDigitsFrac;
    }

    /*
     * Compute leading & trailing fractional zeroes.
     */

    if (fixed && exp < 0) {
	/*
	 * Fixed-point format with negative exponents have leading fractional 
	 * zeroes. Trailing zeroes start after leading zeroes + significand
	 * digits.
	 */

	nbLead0Frac = (size_t) -exp;
	firstTrail0Frac = nbDigitsSigd + nbLead0Frac;
    } else {
	/*
	 * Floating-point format have no leading fractional zeroes. Trailing
	 * zeroes start after significand digits in the fractional part.
	 */

	nbLead0Frac = 0;
	if (nbDigitsSigd > nbDigitsInt) {
	    firstTrail0Frac = nbDigitsSigd - nbDigitsInt;
	} else {
	    firstTrail0Frac = 0;
	}
    }

    /*
     * Adjust actual number of significand digits.
     */

    if (nbLead0Frac) {
	if (nbDigitsSigd + nbLead0Frac >= nbDigitsFrac) {
	    maxDigitsSigd = nbDigitsFrac - nbLead0Frac;
	}
    } else if (firstTrail0Frac > nbDigitsFrac) {
	maxDigitsSigd = nbDigitsInt + nbDigitsFrac;
    }

    if (nbDigitsSigd > maxDigitsSigd) {
	/*
	 * Truncate significand, round to nearest value.
	 */

	ASSERT(nbDigitsSigd);
	p = buf + ((sign < 0) ? 1 : 0) + maxDigitsSigd;
	ASSERT(*p);
	i = DIGIT_VALUE(*p, format->radix);
	if (i * 2 >= format->radix) {
	    /*
	     * Round to upper value.
	     */

	    while (maxDigitsSigd > 0) {
		p--;
		i = DIGIT_VALUE(*p, format->radix) + 1;
		if (i < format->radix) {
		    *p = (format->flags & COATL_NUMWRITE_L ? digitCharsL 
			    : digitCharsL)[i];
		    break;
		}

		/*
		 * Propagate to higher digits.
		 */

		maxDigitsSigd--;
	    }
	    if (maxDigitsSigd == 0) {
		/*
		 * Rounded up whole mantissa, shift exponent.
		 */

		exp++;
		i = 1;
		*p = (format->flags & COATL_NUMWRITE_L ? digitCharsL 
				: digitCharsL)[i];
		maxDigitsSigd = 1;
	    }
	    p++;
	}
	ASSERT(p == buf + ((sign < 0) ? 1 : 0) + maxDigitsSigd);
	*p = '\0';
	nbDigitsSigd = maxDigitsSigd;
	goto adjustExp;
    }

    if (!fixed) {
	if (format->radix == 16 && (format->flags & COATL_NUMWRITE_EXP_C2)) {
	    /*
	     * C99-style hex floats with 2-power exponent in decimal.
	     */

	    exp *= 4;
	    nbDigitsExp = UIntDigits(exp > 0 ? exp : -exp, 10);
	} else if (format->radix == 16 && (format->flags 
		& COATL_NUMWRITE_EXP_C2)) {
	    /*
	     * C99-style hex floats with 2-power exponent in decimal.
	     */

	    exp *= 4;
	    nbDigitsExp = UIntDigits(exp > 0 ? exp : -exp, 16);
	} else {
	    /*
	     * Both significand and exponent in the same radix.
	     */

	    nbDigitsExp = UIntDigits(exp > 0 ? exp : -exp, format->radix);
	}
    }

    /*
     * Compute width of fractional + exponent parts.
     */

    width = 0;

    /* - Radix point. */
    if (nbDigitsFrac || (format->flags & COATL_NUMWRITE_POINT)) {
	width++;
    }

    /* - Fractional digits. */
    width += nbDigitsFrac;
    if (!nbDigitsFrac && (format->flags & COATL_NUMWRITE_PREFIX_0)) {
	width++;
    }

    if (!fixed && (exp || format->minDigitsExp)) {
	/* - Exponent character. */
	width++;

	/* - Exponent sign. */
	if (exp < 0 || (format->flags & COATL_NUMWRITE_EXP_PLUS)) {
	    width++;
	}

	/* - Exponent digits. */
	if (nbDigitsExp == 0) nbDigitsExp = 1;
	if (nbDigitsExp < format->minDigitsExp) {
	    width += format->minDigitsExp;
	} else {
	    width += nbDigitsExp;
	}
    }

    /*
     * Output string.
     */

    /* - Padding, sign, prefix and integral part */
    intFormat = *format;
    if (intFormat.minWidth > width) {
	intFormat.minWidth -= width;
    } else {
	intFormat.minWidth = 0;
    }
    FormatDigitString(strbuf, sign, nbDigitsInt, buf + ((sign < 0) ? 1 : 0), 
	    (nbDigitsInt > nbDigitsSigd) ? nbDigitsInt - nbDigitsSigd : 0, 
	    format);

    /* - Radix point. */
    if (nbDigitsFrac || (format->flags & COATL_NUMWRITE_POINT)) {
	Col_StringBufferAppendChar(strbuf, format->pointChar);
    }

    /* - Fractional digits. */
    p = buf + ((sign < 0) ? 1 : 0) + nbDigitsInt;
    i = 0;
    while (i < nbDigitsFrac) {
	if (i && format->groupSize && (i % format->groupSize) == 0) {
	    Col_StringBufferAppendChar(strbuf, format->groupChar);
	}
	if (i < nbLead0Frac || i >= firstTrail0Frac) {
	    c = '0';
	} else {
	    c = *p++;
	}
	Col_StringBufferAppendChar(strbuf, c);
	i++;
    }

    if (!fixed && (exp || format->minDigitsExp)) {
	/* - Exponent character. */
	Col_StringBufferAppendChar(strbuf, format->expChar);

	/* - Exponent sign. */
	if (exp < 0) {
	    Col_StringBufferAppendChar(strbuf, '-');
	} else if (format->flags & COATL_NUMWRITE_EXP_PLUS) {
	    Col_StringBufferAppendChar(strbuf, '+');
	}

	/* - Exponent digits. Don't use grouping characters. */
	i = format->minDigitsExp;
	while (i > nbDigitsExp) {
	    Col_StringBufferAppendChar(strbuf, '0');
	    i--;
	}
	if (format->radix == 16 && (format->flags & COATL_NUMWRITE_EXP_C2)) {
	    WriteUInt(strbuf, exp > 0 ? exp : -exp, 10); 
	} else {
	    WriteUInt(strbuf, exp > 0 ? exp : -exp, format->radix);
	}
    }

    if (buf) {
	ASSERT(sign != 0);
	TMP_FREE(buf, bufSize);
    }

    return Col_StringBufferLength(strbuf) - oldLen;
}


/*
================================================================================
Section: Number Conversion
================================================================================
*/

/*---------------------------------------------------------------------------
 * Function: Coatl_RopeToIntWord
 *
 *	Convert a rope to an integer word.
 *
 * Arguments:
 *	rope	- Rope to convert.
 *	format	- Read format (NULL means default).
 *	types	- Accepted output word types.
 *
 * Results:
 *	Integer word if success, else nil. May be a Colibri integer word, a 
 *	CoATL large integer word, or a CoATL multiple precision integer word.
 *
 * See also:
 *	<Coatl_NumReadFormat>, <Number Reading Word Type Flags>,
 *	<Coatl_ReadIntWord>
 *---------------------------------------------------------------------------*/

Col_Word
Coatl_RopeToIntWord(
    Col_Word rope, 
    const Coatl_NumReadFormat *format,
    int types)
{
    Col_Word word;
    Col_RopeIterator begin, end;
    Col_RopeIterFirst(begin, rope);
    Col_RopeIterBegin(end, rope, SIZE_MAX);
    return (Coatl_ReadIntWord(begin, end, format, types, &word)) ? word 
	    : COL_NIL;
}

/*---------------------------------------------------------------------------
 * Function: Coatl_RopeToFloatWord
 *
 *	Convert a rope to a floating point word.
 *
 * Arguments:
 *	rope	- Rope to convert.
 *	format	- Read format (NULL means default).
 *	types	- Accepted output word types.
 *
 * Results:
 *	Integer word if success, else nil. May be a Colibri floating point word
 *	or a CoATL multiple precision floating point word.
 *
 * See also:
 *	<Coatl_NumReadFormat>, <Number Reading Word Type Flags>,
 *	<Coatl_ReadFloatWord>
 *---------------------------------------------------------------------------*/

Col_Word
Coatl_RopeToFloatWord(
    Col_Word rope, 
    const Coatl_NumReadFormat *format,
    int types)
{
    Col_Word word;
    Col_RopeIterator begin, end;
    Col_RopeIterFirst(begin, rope);
    Col_RopeIterBegin(end, rope, SIZE_MAX);
    return (Coatl_ReadFloatWord(begin, end, format, types, &word)) ? word 
	    : COL_NIL;
}

/*---------------------------------------------------------------------------
 * Function: Coatl_IntWordToRope
 *
 *	Convert an integer word to a rope.
 *
 * Arguments:
 *	word		- Integer word to convert.
 *	strFormat	- String format.
 *	format		- Write format (NULL means default).
 *
 * Result:
 *	String representation of integer value in the given format.
 *
 * See also:
 *	<Coatl_NumWriteFormat>, <Coatl_WriteIntWord>
 *---------------------------------------------------------------------------*/

Col_Word
Coatl_IntWordToRope(
    Col_Word word,
    Col_StringFormat strFormat,
    const Coatl_NumWriteFormat *format)
{
    Col_Word strbuf = Col_NewStringBuffer(0, strFormat); // TODO default length.
    Coatl_WriteIntWord(strbuf, word, format);
    return Col_StringBufferFreeze(strbuf);
}

/*---------------------------------------------------------------------------
 * Function: Coatl_FloatWordToRope
 *
 *	Convert a floating point word to a rope.
 *
 * Arguments:
 *	word		- Floating point word to convert.
 *	strFormat	- String format.
 *	format		- Write format (NULL means default).
 *
 * Result:
 *	String representation of floating point value in the given format.
 *
 * See also:
 *	<Coatl_NumWriteFormat>, <Coatl_WriteIntWord>
 *---------------------------------------------------------------------------*/

Col_Word
Coatl_FloatWordToRope(
    Col_Word word,
    Col_StringFormat strFormat,
    const Coatl_NumWriteFormat *format)
{
    Col_Word strbuf = Col_NewStringBuffer(0, strFormat); // TODO default length.
    Coatl_WriteFloatWord(strbuf, word, format);
    return Col_StringBufferFreeze(strbuf);
}
