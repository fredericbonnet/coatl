/*
 * File: coatlNumber.h
 *
 *	This file implements the number handling facility of CoATL.
 *
 * See also:
 *	<coatlJson.h>
 */

#include "include/coatl.h"
#include "coatlInternal.h"

#include "coatlNumberInt.h"

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
#endif
static Col_CustomWordType mpIntWordType;
static Col_CustomWordSizeProc MpIntSizeProc;
static Col_CustomWordFreeProc MpIntFreeProc;
static Col_CustomWordType mpFloatWordType;
static Col_CustomWordSizeProc MpFloatSizeProc;
static Col_CustomWordFreeProc MpFloatFreeProc;


/*
================================================================================
Internal Section: Number Parsing
================================================================================
*/

/*---------------------------------------------------------------------------
 * Internal Macro: DIGIT
 *
 *	Numeric value of a digit character. Assumes digit character codepoints 
 *	are contiguous for ranges 0..9, A..Z, a..z (true in Unicode locale).
 *
 * Arguments:
 *	c	- Character (Caution: evaluated several times during macro 
 *		  expansion)
 *	b	- Numeric base (2..62). When > 36, upper-case letters A..Z
 *		  represent 10..35, wherease lower-case letters a..z represent
 *		  36..61. When <= 36, upper- and lower-case letters have the
 *		  same values and represent 10..35.
 *
 * Results:
 *	If *c* is a digit character, its numeric value, else CHAR_MAX. Value
 *	may exceed the given base.
 *---------------------------------------------------------------------------*/

#define DIGIT(c, b) \
    (   (c) <  '0' ? CHAR_MAX			\
     : (c) <= '9' ? (c)-'0'			\
     : (c) <  'A' ? CHAR_MAX			\
     : (c) <= 'Z' ? (c)-'A'+10			\
     : (c) <  'a' ? CHAR_MAX			\
     : (c) <= 'z' ? (c)-'a'+(b>36)?36:10	\
     :              CHAR_MAX)

/*---------------------------------------------------------------------------
 * Internal Constant: STRLEN_USE_ALLOCA
 *
 *	Number of bytes above which we use malloc() instead of alloca() when
 *	allocating temporary storage.
 *---------------------------------------------------------------------------*/

#define STRLEN_USE_ALLOCA	100

/*---------------------------------------------------------------------------
 * Internal Function: ParseInt
 *
 *	Parse an unsigned integer number.
 *
 * Arguments:
 *	begin	- Beginning of digit sequence to parse.
 *	end	- End of sequence.
 *	min	- Minimum number of digits to parse.
 *	max	- Maximum number of digits to parse.
 *	base	- Numeric base (2..62).
 *	ignore	- If non-NULL, a NUL-terminated string of characters to ignore.
 *
 * Results:
 *	Nonzero if success.
 *
 * Side effects:
 *	*begin* is moved just past the parsed sequence.
 *---------------------------------------------------------------------------*/

int
ParseInt(
    Col_RopeIterator begin,
    Col_RopeIterator end,
    size_t min,
    size_t max,
    unsigned int base,
    Col_Char *ignore)
{
    size_t nb;
    Col_Char c, *pi;

    /*
     * Consume digits.
     */

    ASSERT(min <= max);
    ASSERT(max);
    for (nb = 0; nb < max && Col_RopeIterCompare(begin, end) < 0; nb++,
	    Col_RopeIterNext(begin)) {
	c = Col_RopeIterAt(begin);
	if (DIGIT(c, base) >= base) {
	    /*
	     * Skip ignored chars.
	     */

	    if (!ignore) break;
	    for (pi = ignore; *pi && *pi != c; pi++);
	    if (!*pi) break;
	}
    }
    if (nb < min) return 0;
    return 1;
}

/*---------------------------------------------------------------------------
 * Internal Function: ScanInt
 *
 *	Scan an unsigned integer number.
 *
 * Arguments:
 *	begin	- Beginning of digit sequence to parse.
 *	end	- End of sequence (just past the last character to scan).
 *	base	- Numeric base (2..62).
 *	ignore	- If non-NULL, a NUL-terminated string of characters to ignore.
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
ScanInt(
    Col_RopeIterator begin,
    Col_RopeIterator end,
    unsigned int base,
    Col_Char *ignore,
    uintmax_t *valuePtr)
{
    uintmax_t v = 0;
    Col_Char c, *pi;
    unsigned int d;

    /*
     * Consume hex digits. Assume hex digit codepoints are contiguous (true
     * in Unicode locale).
     */

    for (; Col_RopeIterCompare(begin, end) < 0; Col_RopeIterNext(begin)) {
	c = Col_RopeIterAt(begin);
	d = DIGIT(c, base);
	if (d >= base) {
	    /*
	     * Skip ignored chars.
	     */

	    if (!ignore) break;
	    for (pi = ignore; *pi && *pi != c; pi++);
	    if (!*pi) break;
	    continue;
	}
	switch (base) {
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
	    if (v > (UINTMAX_MAX-d)/base) return 0;
	    v *= base; v += d; break;
	}
    }
    *valuePtr = v;
    return 1;
}

/*---------------------------------------------------------------------------
 * Internal Function: ScanIntWord
 *
 *	Scan an integer number.
 *
 * Arguments:
 *	begin	- Beginning of sequence to parse.
 *	end	- End of sequence (just past the last character to scan).
 *	base	- Numeric base (2..62).
 *	ignore	- If non-NULL, a NUL-terminated string of characters to ignore.
 *
 * Results:
 *	Integer word. May be a Colibri integer word, a large integer word, or 
 *	a multiple precision integer word.
 *
 * Side effects:
 *	*begin* is moved just past the last scanned character.
 *---------------------------------------------------------------------------*/

Col_Word
ScanIntWord(
    Col_RopeIterator begin, 
    Col_RopeIterator end, 
    unsigned int base,
    Col_Char *ignore)
{
    uintmax_t v;
    Col_RopeIterator it;
    int neg = 0;
    Col_Word w;
    mpz_t *data;
    Col_Char c, *pi;
    char *str, *p;
    size_t len;
    
    /*
     * First try large integer scan.
     */
    
    len = Col_RopeIterIndex(end) - Col_RopeIterIndex(begin);
    Col_RopeIterSet(it, begin);
    if (Col_RopeIterAt(begin) == '-') {
	Col_RopeIterNext(begin);
	neg = 1;
    }
    if (ScanInt(begin, end, 10, ignore, &v) 
	    && v <= (neg ? (uintmax_t) -INTMAX_MIN : (uintmax_t) INTMAX_MAX)) {
	return Coatl_NewLargeIntWord(neg ? -(intmax_t) v : (intmax_t) v);
    }

    /*
     * Scan multiple precision integer. Assumes digit character codepoints
     * fit into a char.
     */

    Col_RopeIterSet(begin, it);
    str = (char *) ((len <= STRLEN_USE_ALLOCA) ? alloca(len+1) : malloc(len+1));
    for (p = str; Col_RopeIterCompare(begin, end) < 0; 
	    Col_RopeIterNext(begin)) {
	c = (char) Col_RopeIterAt(begin);
	if (ignore) {
	    for (pi = ignore; *pi && *pi != c; pi++);
	    if (*pi) continue;
	}
	*p++ = c;
    }
    *p = 0;
    w = Col_NewCustomWord(&mpIntWordType, sizeof(*data), (void **) &data);
    mpz_init_set_str(*data, str, base);
    if (len > STRLEN_USE_ALLOCA) free(str);
    return w;
}

/*---------------------------------------------------------------------------
 * Internal Function: ScanFloatWord
 *
 *	Scan a floating point number.
 *
 * Arguments:
 *	begin	- Beginning of sequence to parse.
 *	end	- End of sequence (just past the last character to scan).
 *	base	- Numeric base (2..62).
 *	ignore	- If non-NULL, a NUL-terminated string of characters to ignore.
 *
 * Results:
 *	Floating point word. May be a Colibri floating point word or a multiple
 *	precision floating point word.
 *
 * Side effects:
 *	*begin* is moved just past the last scanned character.
 *---------------------------------------------------------------------------*/

Col_Word
ScanFloatWord(
    Col_RopeIterator begin, 
    Col_RopeIterator end, 
    unsigned int base,
    Col_Char *ignore)
{
    mpf_t mpf, *data;
    Col_Char c, *pi;
    char *str, *p;
    size_t len;
    double d;
    Col_Word w;

    /*
     * Rely on multiple precision library, float scanning is too much work to
     * do reliably because of rounding issues.
     */

    len = Col_RopeIterIndex(end) - Col_RopeIterIndex(begin);
    str = (char *) ((len <= STRLEN_USE_ALLOCA) ? alloca(len+1) : malloc(len+1));
    for (p = str; Col_RopeIterCompare(begin, end) < 0; 
	    Col_RopeIterNext(begin)) {
	c = (char) Col_RopeIterAt(begin);
	if (ignore) {
	    for (pi = ignore; *pi && *pi != c; pi++);
	    if (*pi) continue;
	}
	*p++ = c;
    }
    *p = 0;
    mpf_init_set_str(mpf, str, base);
    if (len > STRLEN_USE_ALLOCA) free(str);

    /*
     * Get double value from multiple precision float. If values are identical,
     * we can use a float word instead.
     */

    d = mpf_get_d(mpf);
    if (mpf_cmp_d(mpf, d) == 0) {
	mpf_clear(mpf);
	return Col_NewFloatWord(d);
    } else {
	w = Col_NewCustomWord(&mpFloatWordType, sizeof(*data), (void **) &data);
	memcpy(data, &mpf, sizeof(mpf));
	return w;
    }
}


/*
================================================================================
Section: Large Integer Word
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
 *	Generate <COL_TYPECHECK> error when *word* is not a regexp word.
 *
 * See also:
 *	<Col_Error>
 *---------------------------------------------------------------------------*/

#define TYPECHECK_LARGEINT(word, liPtr) \
    if (!(Col_WordType(word) & COL_CUSTOM) \
	    || Col_CustomWordInfo((word), (void **) &(liPtr)) != &largeIntWordType) { \
	Col_Error(COL_TYPECHECK, CoatlDomain, COATL_ERROR_LARGEINT, (word)); \
	goto COL_CONCATENATE(FAILED,__LINE__); \
    } \
    if (0) \
COL_CONCATENATE(FAILED,__LINE__): 


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
 * Function: Coatl_IsLargeIntWord
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
Coatl_IsLargeIntWord(
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
Section: Multiple Precision Integer Word
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


/*
================================================================================
Section: Multiple Precision Floating Point Word
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
