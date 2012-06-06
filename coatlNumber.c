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
#endif /* INTPTR_MAX != INTMAX_MAX */
static Col_CustomWordType mpIntWordType;
static Col_CustomWordSizeProc MpIntSizeProc;
static Col_CustomWordFreeProc MpIntFreeProc;
static Col_CustomWordType mpFloatWordType;
static Col_CustomWordSizeProc MpFloatSizeProc;
static Col_CustomWordFreeProc MpFloatFreeProc;


/*
================================================================================
Internal Section: Number Input
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
 *	b	- Numeric base (2..62). When > 36, upper-case letters A..Z
 *		  represent 10..35, wherease lower-case letters a..z represent
 *		  36..61. When <= 36, upper- and lower-case letters have the
 *		  same values and represent 10..35.
 *
 * Results:
 *	If *c* is a digit character, its numeric value, else CHAR_MAX. Value
 *	may exceed the given base.
 *---------------------------------------------------------------------------*/

#define DIGIT_VALUE(c, b) \
    (  (c) <  '0' ? CHAR_MAX			\
     : (c) <= '9' ? (c)-'0'			\
     : (c) <  'A' ? CHAR_MAX			\
     : (c) <= 'Z' ? (c)-'A'+10			\
     : (c) <  'a' ? CHAR_MAX			\
     : (c) <= 'z' ? (c)-'a'+(((b)>36)?36:10)	\
     :              CHAR_MAX)

/*---------------------------------------------------------------------------
 * Internal Constant: STRLEN_USE_ALLOCA
 *
 *	Number of bytes above which we use malloc() instead of alloca() when
 *	allocating temporary storage.
 *---------------------------------------------------------------------------*/

#define STRLEN_USE_ALLOCA	100

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
ParseUInt(
    Col_RopeIterator begin,
    Col_RopeIterator end,
    size_t min,
    size_t max,
    unsigned int base,
    Col_Char *ignore)
{
    size_t nb;
    Col_Char c, *pi;

    ASSERT(base >= 2 && base <= 62);

    /*
     * Consume digits.
     */

    ASSERT(min <= max);
    ASSERT(max);
    for (nb = 0; nb < max && Col_RopeIterCompare(begin, end) < 0; nb++,
	    Col_RopeIterNext(begin)) {
	c = Col_RopeIterAt(begin);
	if (DIGIT_VALUE(c, base) >= base) {
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
 * Internal Function: ReadUInt
 *
 *	Read an unsigned integer number from a character sequence.
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
ReadUInt(
    Col_RopeIterator begin,
    Col_RopeIterator end,
    unsigned int base,
    Col_Char *ignore,
    uintmax_t *valuePtr)
{
    uintmax_t v = 0;
    Col_Char c, *pi;
    unsigned int d;

    ASSERT(base >= 2 && base <= 62);

    /*
     * Consume hex digits. Assume hex digit codepoints are contiguous (true
     * in Unicode locale).
     */

    for (; Col_RopeIterCompare(begin, end) < 0; Col_RopeIterNext(begin)) {
	c = Col_RopeIterAt(begin);
	d = DIGIT_VALUE(c, base);
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
 * Internal Function: ReadIntWord
 *
 *	Read an integer number from a character sequence.
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
ReadIntWord(
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
    
    ASSERT(base >= 2 && base <= 62);

    /*
     * First try large integer scan.
     */
    
    len = Col_RopeIterIndex(end) - Col_RopeIterIndex(begin);
    Col_RopeIterSet(it, begin);
    if (Col_RopeIterAt(begin) == '-') {
	Col_RopeIterNext(begin);
	neg = 1;
    }
    if (ReadUInt(begin, end, base, ignore, &v) 
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
 * Internal Function: ReadFloatWord
 *
 *	Read a floating point number from a character sequence.
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
ReadFloatWord(
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

    ASSERT(base >= 2 && base <= 62);

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
Internal Section: Number Output
================================================================================
*/

/*---------------------------------------------------------------------------
 * Internal Variable: digitChars
 *
 *	Digit characters for bases up to 62.
 *---------------------------------------------------------------------------*/

static const char digitChars[] = 
    "0123456789"
    "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    "abcdefghijklmnopqrstuvwxyz";

/*---------------------------------------------------------------------------
 * Internal Variable: digitsPerBit
 *
 *	Number of digits per bit in given base (2-62) = log(2)/log(base).
 *---------------------------------------------------------------------------*/

const double digitsPerBit[61] = {
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
 * Internal Function: WriteUInt
 *
 *	Write an unsigned integer value to a string buffer in canonical form.
 *	Canonical form is:
 *
 *	- no leading or trailing whitespaces,
 *	- no digit grouping,
 *	- no leading zero for nonzero values,
 *	- uppercase digits for 10 < base <= 36.
 *
 * Arguments:
 *	strbuf		- Output string buffer.
 *	value		- Value to write.
 *	base		- Numeric base (2..62).
 *
 * Side effects:
 *	Characters are appended to the string buffer.
 *---------------------------------------------------------------------------*/

void
WriteUInt(
    Col_Word strbuf, 
    uintmax_t value,
    unsigned int base)
{
    char str[sizeof(uintmax_t)*CHAR_BIT], *p;

    ASSERT(base >= 2 && base <= 62);

    if (value == 0) {
	/*
	 * Zero gives "0".
	 */

	Col_StringBufferAppendChar(strbuf, '0');
    }

    /*
     * First build string in reverse order.
     *
     * Note: there cannot be more digits than the size in bits of the max
     * integral type.
     */

    switch (base) {
    case 2:  for (p = str; value; value >>= 1)   *p++ = digitChars[value & 0x01]; break;
    case 4:  for (p = str; value; value >>= 2)   *p++ = digitChars[value & 0x03]; break;
    case 8:  for (p = str; value; value >>= 3)   *p++ = digitChars[value & 0x07]; break;
    case 16: for (p = str; value; value >>= 4)   *p++ = digitChars[value & 0x0F]; break;
    case 32: for (p = str; value; value >>= 5)   *p++ = digitChars[value & 0x1F]; break;
    default: for (p = str; value; value /= base) *p++ = digitChars[value % base];
    }

    /*
     * Now append characters in buffer.
     */

    do Col_StringBufferAppendChar(strbuf, *--p); while (p > str);
}

/*---------------------------------------------------------------------------
 * Internal Function: WriteIntWord
 *
 *	Write an integer word value to a string buffer in canonical form.
 *	Canonical form is:
 *
 *	- no leading or trailing whitespaces,
 *	- no digit grouping,
 *	- no 'plus' sign for positive values,
 *	- no leading zero for nonzero values,
 *	- uppercase digits for 10 < base <= 36.
 *
 * Arguments:
 *	strbuf		- Output string buffer.
 *	value		- Value to write.
 *	base		- Numeric base (2..62).
 *
 * Side effects:
 *	Characters are appended to the string buffer.
 *---------------------------------------------------------------------------*/

void
WriteIntWord(
    Col_Word strbuf, 
    Col_Word value,
    unsigned int base)
{
    int type;

    ASSERT(base >= 2 && base <= 62);

    type = Col_WordType(value);
    if (type & COL_INT) {
	/*
	 * Native integer.
	 */

	intptr_t v = Col_IntWordValue(value);
	if (v < 0) {
	    Col_StringBufferAppendChar(strbuf, '-');
	    WriteUInt(strbuf, (uintmax_t) -v, base);
	} else {
	    WriteUInt(strbuf, v, base);
	}
	return;
    } else if (type & COL_CUSTOM) {
	void *data;
	Col_CustomWordType *wt = Col_CustomWordInfo(value, &data);
	if (wt == &mpIntWordType) {
	    /*
	     * Multiple precision integer.
	     */

	    mpz_t *v = (mpz_t *) data;
	    size_t len = mpz_sizeinbase(*v, base);
	    char *str = (char *) ((len <= STRLEN_USE_ALLOCA) ? alloca(len+2) 
		    : malloc(len+2)), *p;
	    mpz_get_str(str, base, *v);
	    for (p = str; *p; p++) Col_StringBufferAppendChar(strbuf, *p);
	    if (len > STRLEN_USE_ALLOCA) free(str);
#if INTPTR_MAX != INTMAX_MAX
	} else if (wt == &largeIntWordType) {
	    /*
	     * Large integer.
	     */

	    intmax_t v = *(intmax_t *) data;
	    if (v < 0) {
		Col_StringBufferAppendChar(strbuf, '-');
		WriteUInt(strbuf, (uintmax_t) -v, base);
	    } else {
		WriteUInt(strbuf, v, base);
	    }
	    return;
#endif /* INTPTR_MAX != INTMAX_MAX */
	}
    }
    //TODO typecheck ?
}

/*---------------------------------------------------------------------------
 * Internal Function: WriteFloatWord
 *
 *	Write a floating point word value to a string buffer in canonical form.
 *	Canonical form is:
 *
 *	- no leading or trailing whitespaces,
 *	- no digit grouping,
 *	- no 'plus' sign for positive values,
 *	- no leading zero for nonzero values,
 *	- integral mantissa with no trailing zero,
 *	- no zero exponent,
 *	- exponent prefix is *'e'* for bases up to 10, *'@'* otherwise,
 *	- uppercase digits for 10 < base <= 36.
 *
 * Arguments:
 *	strbuf		- Output string buffer.
 *	value		- Value to write.
 *	base		- Numeric base (2..62).
 *
 * Side effects:
 *	Characters are appended to the string buffer.
 *---------------------------------------------------------------------------*/

void
WriteFloatWord(
    Col_Word strbuf, 
    Col_Word value,
    unsigned int base)
{
    mpf_t v, *pv;
    mp_exp_t exp;
    char *str, *p;
    size_t len;
    int type;

    ASSERT(base >= 2 && base <= 62);

    /*
     * Always rely on multiple precision library.
     */

    type = Col_WordType(value);
    if (type & COL_FLOAT) {
	/*
	 * Native floating point.
	 */

	double d = Col_FloatWordValue(value);
	if (d == 0) {
	    /*
	     * Zero gives "0".
	     */

	    Col_StringBufferAppendChar(strbuf, '0');
	    return;
	}

	/*
	 * Convert to multiple precision floating point.
	 */

	mpf_init_set_d(v, d);
	pv = &v;
    } else if (type & COL_CUSTOM) {
	void *data;
	Col_CustomWordType *wt = Col_CustomWordInfo(value, &data);
	if (wt == &mpFloatWordType) {
	    /*
	     * Multiple precision floating point.
	     */

	    pv = (mpf_t *) data;
	}
	//TODO typecheck ?
    }

    /*
     * Convert to string + exponent. MPIR uses an implicitly normalized string,
     * i.e. there is an implicit radix point after the first digit.
     */

    len = (size_t) (mpf_get_prec(*pv) * digitsPerBit[base-2]) + 2;
    str = (char *) ((len <= STRLEN_USE_ALLOCA) ? alloca(len+2) : malloc(len+2));
    mpf_get_str(str, &exp, base, len, *pv);
    if (type & COL_FLOAT) mpf_clear(v);

    /*
     * Normalize exponent so that mantissa is integer.
     */

    len = strlen(str);
    if (len == 0) {
	/*
	 * Zero gives "0".
	 */

	ASSERT(exp == 0);
	Col_StringBufferAppendChar(strbuf, '0');
	return;
    }
    exp -= len;

    /*
     * Append mantissa.
     */

    for (p = str; *p; p++) Col_StringBufferAppendChar(strbuf, *p);

    /*
     * Append exponent.
     */

    if (exp < 0) {
	Col_StringBufferAppendChar(strbuf, (base > 10 ? '@' : 'e'));
	Col_StringBufferAppendChar(strbuf, '-');
	WriteUInt(strbuf, (uintmax_t) -exp, base);
    } else if (exp > 0) {
	Col_StringBufferAppendChar(strbuf, (base > 10 ? '@' : 'e'));
	WriteUInt(strbuf, exp, base);
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
 *	Generate <COL_TYPECHECK> error when *word* is not a large integer word.
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
