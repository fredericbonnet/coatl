/**
 * @file coatlNumber.h
 *
 * This header file defines the number handling facility of CoATL.
 */

#ifndef _COATL_NUMBER
#define _COATL_NUMBER

#include <limits.h>


/*
===========================================================================*//*!
\defgroup numbers Numbers
\{*//*==========================================================================
*/

/*
===========================================================================*//*!
\defgroup large_int_words Large Integer Words

Words holding **intmax_t** values.

Colibri integer words support the integer type defined by the C standard as 
__intptr_t__, whose size matches native pointers and thus varies between 32- and
64-bit architectures. However the C standard also defines **intmax_t** as the
largest supported integer type, which is usually 64-bit on both architectures.

CoATL large integer words provide **intmax_t** support on architectures where it
is larger than **intptr_t**, and are identical to Colibri integer words on
architectures where both types are identical.
\{*//*==========================================================================
*/

/** True when CoATL large integers are identical to Colibri integers. */
#define COATL_NATIVELARGEINT    (INTPTR_MAX == INTMAX_MAX)


/***************************************************************************//*!
 * \name Large Integer Word Creation
 ***************************************************************************\{*/

#if COATL_NATIVELARGEINT
#   define Coatl_NewLargeIntWord        Col_NewIntWord
#else
EXTERN Col_Word         Coatl_NewLargeIntWord(intmax_t value);
#endif /* COATL_NATIVELARGEINT */

/* End of Large Integer Word Creation *//*!\}*/


/***************************************************************************//*!
 * \name Large Integer Word Predicates
 ***************************************************************************\{*/

#if COATL_NATIVELARGEINT
#   define Coatl_WordIsLargeInt(word)   (Col_WordType(word) & COL_INT)
#else
EXTERN int              Coatl_WordIsLargeInt(Col_Word word);
#endif /* COATL_NATIVELARGEINT */

/* End of Large Integer Word Predicates *//*!\}*/


/***************************************************************************//*!
 * \name Large Integer Word Accessors
 ***************************************************************************\{*/

#if COATL_NATIVELARGEINT
#   define Coatl_LargeIntWordValue      Col_IntWordValue
#else
EXTERN intmax_t         Coatl_LargeIntWordValue(Col_Word word);
#endif /* COATL_NATIVELARGEINT */

/* End of Large Integer Word Accessors *//*!\}*/

/* End of Large Integer Words *//*!\}*/


/*
===========================================================================*//*!
\defgroup mp_int_words Multiple Precision Integer Words
\{*//*==========================================================================
*/

/***************************************************************************//*!
 * \name Multiple Precision Integer Word Predicates
 ***************************************************************************\{*/

EXTERN int              Coatl_WordIsMpInt(Col_Word word);

/* End of Multiple Precision Integer Word Predicates *//*!\}*/

/* End of Multiple Precision Integer Words *//*!\}*/


/*
===========================================================================*//*!
\defgroup mp_float_words Multiple Precision Floating Point Words
\{*//*==========================================================================
*/

/***************************************************************************//*!
 * \name Multiple Precision Floating Point Word Predicates
 ***************************************************************************\{*/

EXTERN int              Coatl_WordIsMpFloat(Col_Word word);

/* End of Multiple Precision Floating Point Word Predicates *//*!\}*/

/* End of Multiple Precision Floating Point Words *//*!\}*/


/*
===========================================================================*//*!
\defgroup number_io Number Input/Output
\{*//*==========================================================================
*/

/**
 * C-style radix character handling.
 *
 * For example, use '`x`' / '`X`' radix characters for base 16 using `"0x"`/`"0X"`
 * prefix.
 *
 * To handle octals, use the `NUL` character.
 */
typedef struct Coatl_NumReadFormat_RadixChar {
    Col_Char c;     /*!< Radix character. */
    unsigned int r; /*!< Radix value. */
} Coatl_NumReadFormat_RadixChar;

/**
 * Number reading format. Fields marked with **[F]** are for floating points
 * only.
 *
 * Character lists are arrays of **Col_Char** terminated by a
 * **COL_CHAR_INVALID** value, or NULL for empty lists.
 *
 * @see Coatl_ReadIntWord
 * @see Coatl_ReadFloatWord
 */
typedef struct Coatl_NumReadFormat {
    unsigned int radix;             /*!< Default numeric radix (2..62) when no
                                         prefix is used. */
    const Col_Char *ignoreChars;    /*!< List of ignored characters in the
                                         middle of sequence (excluding leading
                                         or trailing characters). */
    const Col_Char *prefixChars;    /*!< List of prefix separator characters. */
    const Coatl_NumReadFormat_RadixChar *radixChars;
                                    /*!< List of C-style radix characters. To
                                         handle C-style octals, use the `NUL`
                                         character in last position. */
    const Col_Char *pointChars;     /*!< **[F]** List of accepted radix point
                                         characters. */
    const Col_Char *expChars;       /*!< **[F]** List of accepted exponent
                                         characters. */
    const Col_Char *exp2Chars;      /*!< **[F]** List of accepted exponent
                                         characters for C99-style 2-power
                                         exponent. Requires radix 16, either
                                         explicitly or with prefix. */
} Coatl_NumReadFormat;


/***************************************************************************//*!
 * \name Predefined Number Reading Formats
 *
 * @see Coatl_NumReadFormat
 ***************************************************************************\{*/

/** Default format (same as NULL). */
#define COATL_NUMREAD_DEFAULT   NULL

/** C-style integer format. */
#define COATL_INTREAD_C         ((const Coatl_NumReadFormat *) 1)

/** C-style floating point format (with C99 floats). */
#define COATL_FLOATREAD_C       ((const Coatl_NumReadFormat *) 2)

/* End of Predefined Number Reading Formats *//*!\}*/


/***************************************************************************//*!
 * @anchor number_read_flags
 * \name Number Reading Word Type Flags
 *
 * Accepted output word types for number reading. OR-able values.
 *
 * @see Coatl_ReadIntWord
 * @see Coatl_ReadFloatWord
 ***************************************************************************\{*/

/** Native (Colibri) integer words. */
#define COATL_INTREAD_NATIVE    1

/** Large integer words. (note: this includes native) */
#define COATL_INTREAD_LARGE     2

/** Multiple precision integer words. */
#define COATL_INTREAD_MP        4

/** Native (Colibri) floating point words. */
#define COATL_FLOATREAD_NATIVE  1

/** Multiple precision floating point words. */
#define COATL_FLOATREAD_MP      2

/* End of Number Reading Word Type Flags *//*!\}*/


/**
 * Number writing format. Fields marked with **[F]** are for floating points
 * only.
 *
 * @see Coatl_WriteIntWord
 * @see Coatl_WriteFloatWord
 * @see @ref number_write_flags "Number Write Flags"
 */
typedef struct Coatl_NumWriteFormat {
    int flags;                  /*!< OR'ed @ref number_write_flags 
                                     "Number Write Flags" or zero. */
    unsigned int radix;         /*!< Numeric radix (2..62). */
    size_t minWidth;            /*!< Minimum number of output characters. */
    Col_Char padChar;           /*!< Character used to pad field up to
                                 *   **minWidth**. */
    Col_Char prefixChar;        /*!< Character used for radix prefix, or
                                 *   **COL_CHAR_INVALID**. */
    size_t groupSize;           /*!< Size of digit groups (zero for no
                                     grouping). */
    Col_Char groupChar;         /*!< Digit grouping character. */
    size_t minDigits;           /*!< Minimum number of output digits. For
                                     floating point numbers, this applies to the
                                     integral part. */
    size_t maxDigitsSigd;       /*!< **[F]** Max number of generated significand
                                     digits. */
    size_t minDigitsFrac;       /*!< **[F]** Minimum number of output digits for
                                     fractional part. */
    size_t maxDigitsFrac;       /*!< **[F]** Maximum number of output digits for
                                     fractional part. */
    size_t minDigitsExp;        /*!< **[F]** Minimum number of output digits for
                                     exponent. */
    long minFixed;              /*!< **[F]** Minimum exponent value for 
                                     fixed-point notation. */
    long maxFixed;              /*!< **[F]** Maximum exponent value for 
                                     fixed-point notation. */
    Col_Char pointChar;         /*!< **[F]** Character used for radix point. */
    unsigned long expMul;       /*!< **[F]** Multiple for exponent. If zero, 
                                     this gives a zero integral part (e.g
                                     1230.0 => 0.123e4). */
    Col_Char expChar;           /*!< **[F]** Character used for exponent. */
} Coatl_NumWriteFormat;


/***************************************************************************//*!
 * @anchor number_write_flags
 * \name Number Write Flags
 *
 * Flags for use in Coatl_NumWriteFormat **flags** field. Flags marked with 
 * **[F]** are for floating points only.
 ***************************************************************************\{*/

/** Use C-style radix prefix. */
#define COATL_NUMWRITE_PREFIX_C 0x1

/** Use radix prefix for zero values as well. */
#define COATL_NUMWRITE_PREFIX_0 0x2

/** Use lower case letters for radices <= 36. */
#define COATL_NUMWRITE_L        0x4

/** Use 0 instead of padding character to pad field (use with 
    Coatl_NumWriteFormat **minWidth** field). */
#define COATL_NUMWRITE_PAD_0    0x8

/** Prefix non-negative numbers with a padding character. */
#define COATL_NUMWRITE_SIGNPAD  0x10

/** Prefix non-negative numbers with a + sign (this includes zero). */
#define COATL_NUMWRITE_PLUS     0x20

/** **[F]** Always add radix point even with zero fractional digits. */
#define COATL_NUMWRITE_POINT    0x40

/** **[F]** Prefix non-negative exponents with a + sign. */
#define COATL_NUMWRITE_EXP_PLUS 0x80

/** **[F]** C99-style 2-power exponent. Requires radix 16 and 
    COATL_NUMWRITE_PREFIX_C. */
#define COATL_NUMWRITE_EXP_C2   0x100

/* End of Number Write Flags *//*!\}*/


/***************************************************************************//*!
 * \name Predefined Number Writing Formats
 *
 * @see Coatl_NumWriteFormat
 ***************************************************************************\{*/

/** Default formatting (same as NULL). */
#define COATL_NUMWRITE_DEFAULT  NULL

/** Hexadecimal C-style formatting (with C99 floats). Negative values use signed
    format. */
#define COATL_NUMWRITE_C16      ((const Coatl_NumWriteFormat *) 1)

/** Octal C-style integer formatting. Negative values use signed format. Only 
    suitable for integer numbers. */
#define COATL_INTWRITE_C8       ((const Coatl_NumWriteFormat *) 2)

/* End of Predefined Number Writing Formats *//*!\}*/


/*
 * Remaining declarations.
 */

EXTERN int              Coatl_ReadIntWord(Col_RopeIterator begin,
                            Col_RopeIterator end,
                            const Coatl_NumReadFormat *format,
                            int types, Col_Word *wordPtr);
EXTERN int              Coatl_ReadFloatWord(Col_RopeIterator begin,
                            Col_RopeIterator end,
                            const Coatl_NumReadFormat *format,
                            int types, Col_Word *wordPtr);
EXTERN size_t           Coatl_WriteIntWord(Col_Word strbuf, Col_Word word,
                            const Coatl_NumWriteFormat *format);
EXTERN size_t           Coatl_WriteFloatWord(Col_Word strbuf, Col_Word word,
                            const Coatl_NumWriteFormat *format);

/* End of Number Input/Output *//*!\}*/


/*
===========================================================================*//*!
\defgroup number_conversion Number Conversion
\{*//*==========================================================================
*/

EXTERN Col_Word         Coatl_RopeToIntWord(Col_Word rope,
                            const Coatl_NumReadFormat *format,
                            int types);
EXTERN Col_Word         Coatl_RopeToFloatWord(Col_Word rope,
                            const Coatl_NumReadFormat *format,
                            int types);
EXTERN Col_Word         Coatl_IntWordToRope(Col_Word word,
                            Col_StringFormat strFormat,
                            const Coatl_NumWriteFormat *format);
EXTERN Col_Word         Coatl_FloatWordToRope(Col_Word word,
                            Col_StringFormat strFormat,
                            const Coatl_NumWriteFormat *format);

/* End of Number Input/Output *//*!\}*/

/* End of Numbers *//*!\}*/

#endif /* _COATL_NUMBER */
