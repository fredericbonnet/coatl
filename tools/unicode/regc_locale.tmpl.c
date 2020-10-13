header
{/**
 * @file regc_locale.c
 *
 * This file implements Unicode locale specific regexp routines.
 *
 * This file is included by regcomp.c.
 *
 * It is automatically generated from the Unicode Character Database (UCD) using
 * the file `coatlUcd.tcl`; Do not modify.
 */


typedef struct cvec * (ClassCvecProc) (struct vars *v);

/*
 * Prototypes for functions used only in this file.
 */

/*! \cond IGNORE */
static int              StrEq(const char *name, const rchr startp, 
                            const rchr endp);}

headerEnd
{/*! \endcond *//* IGNORE */
}

charVar
{/**
 * Codepoints of individual characters for class '**${class}**'.
 *
 * Automatically generated from the UCD.
 *
 * @see ranges_${class}
 */
static const chr chars_${class}[] = {${chars}};
}

nbCharConstant
{/**
 * Number of individual characters for class '**${class}**'.
 *
 * Automatically generated from the UCD.
 *
 * @see chars_${class}
 */
#define NBCHARS_${CLASS}${padding}  ${nbChars}
}

rangeVar
{/**
 * Codepoint ranges of characters for class '**${class}**'.
 *
 * Automatically generated from the UCD.
 *
 * @see chars_${class}
 */
static const chr ranges_${class}[] = {${ranges}};
}

nbRangeConstant
{/**
 * Number of character ranges for class '**${class}**'.
 *
 * Automatically generated from the UCD.
 *
 * @see ranges_${class}
 */
#define NBRANGES_${CLASS}${padding} ${nbRanges}
}

procDecl
{static struct cvec *    GetCvec_${class}(struct vars *v);}


procDef
{/**
 * Build vector of characters and ranges for class '**${class}**'.
 *
 * @return Vector for class '**${class}**'.
 *
 * @see NBCHARS_${CLASS}
 * @see NBRANGES_${CLASS}
 * @see classes
 */
static struct cvec *
GetCvec_${class}(
    struct vars *v) /*!< Context. */
{
    struct cvec *cv;
    const chr *c;

    cv = getcvec(v, NBCHARS_${CLASS}, NBRANGES_${CLASS});
    NOERRN();
#if NBCHARS_${CLASS} > 0
    for (c=chars_${class}; c < chars_${class}+NBCHARS_${CLASS}; c++) {
        addchr(cv, *c);
    }
#endif
#if NBRANGES_${CLASS} > 0
    for (c=ranges_${class}; c < ranges_${class}+NBRANGES_${CLASS}*2; c+=2) {
        addrange(cv, *c, *(c+1));
    }
#endif
    return cv;
}
}

classes
{/**
 * POSIX character classes, for use with the '*[:classname:]*' syntax within
 * bracket expressions.
 *
 * We use the compiled UCD data accordingly to generate character ranges 
 * suitable for the regexp engine.
 *
 * @see http://unicode.org/reports/tr18/
 * @see http://www.regular-expressions.info/posixbrackets.html
 */
typedef struct ClassInfo {
    const char *name;
     ClassCvecProc *proc;
     ClassCvecProc *procNocase;
} ClassInfo;
static const ClassInfo classes[] = {${classInfos}
    {NULL}
};
}

classInfo 
{
    {"${class}",${padding}  GetCvec_${class},${padding} GetCvec_${classNocase}},}

    
symbols
{
/**
 * POSIX+ASCII symbolic names, for use with the '*[.symbol.]*' syntax within
 * bracket expressions.
 *
 * We use the compiled UCD data accordingly to generate character ranges 
 * suitable for the regexp engine.
 */
typedef struct SymbolInfo {
    const char *const name;
    const celt code;
} SymbolInfo;
static const SymbolInfo symbols[] = {${symbolInfos}
    {NULL}
};
}

symbolInfo 
{
    {"${symbol}",${padding} '$char'},}


footer 
{/**
 * Utility predicate, compares character sequence to C string.
 *
 * @return Whether strings are equal.
 */
static int
StrEq(
    const char *name,   /*!< C string to compare to. */
    const rchr startp,  /*!< Points to start of name. */
    const rchr endp)    /*!< Points just past end of name. */
{
    const char *n=name; rchr c;
    RCHR_SET(c, startp); 
    while (RCHR_LT(c, endp)) {
        if (*n == 0 || *n != RCHR_CHR(c)) return 0;
        n++; RCHR_FWD(c,1);
    }
    return (*n==0);
}


/*******************************************************************************
 * Generic regexp locale procs
 ******************************************************************************/

/*
 - element - map collating-element name to celt
 ^ static celt element(struct vars *, const rchr, const rchr);
 */
static celt
element(
    struct vars *v,             /* context */
    const rchr startp,          /* points to start of name */
    const rchr endp)            /* points just past end of name */
{
    const SymbolInfo *info;
    rchr tmp;

    /*
     * Generic: one-chr names stand for themselves.
     */

    assert(RCHR_LT(startp, endp));
    if ((RCHR_SET(tmp, startp), RCHR_FWD(tmp,1), !RCHR_LT(tmp, endp))) {
        return RCHR_CHR(startp);
    }

    NOTE(REG_ULOCALE);

    /*
     * Lookup name into symbol array.
     */

    for (info=symbols; info->name; info++) {
        if (StrEq(info->name, startp, endp)) {
            /*
             * Found, return matching code.
             */

            return info->code;
        }
    }

    /*
     * Not found.
     */

    ERR(REG_ECOLLATE);
    return 0;
}

/*
 - range - supply cvec for a range, including legality check
 ^ static struct cvec *range(struct vars *, celt, celt, int);
 */
static struct cvec *
range(
    struct vars *v,             /* context */
    celt a,                     /* range start */
    celt b,                     /* range end, might equal a */
    int cases)                  /* case-independent? */
{
    int nchrs;
    struct cvec *cv;
    celt c, lc, uc, tc;

    if (a != b && !before(a, b)) {
        ERR(REG_ERANGE);
        return NULL;
    }

    if (!cases) {               /* easy version */
        cv = getcvec(v, 0, 1);
        NOERRN();
        if (a == b) {
            addchr(cv, a);
        } else {
            addrange(cv, a, b);
        }
        return cv;
    }

    /*
     * When case-independent, it's hard to decide when cvec ranges are usable,
     * so for now at least, we won't try. We allocate enough space for two
     * case variants plus a little extra for the two title case variants.
     */

    //TODO use Unicode property 'Cased' to find proper ranges?

    nchrs = (b - a + 1)*2 + 4;

    cv = getcvec(v, nchrs, 0);
    NOERRN();

    for (c=a; c<=b; c++) {
        addchr(cv, c);
        lc = Coatl_CharToLowercase((chr)c);
        uc = Coatl_CharToUppercase((chr)c);
        tc = Coatl_CharToTitlecase((chr)c);
        if (c != lc) {
            addchr(cv, lc);
        }
        if (c != uc) {
            addchr(cv, uc);
        }
        if (c != tc && tc != uc) {
            addchr(cv, tc);
        }
    }

    return cv;
}

/*
 - before - is celt x before celt y, for purposes of range legality?
 ^ static int before(celt, celt);
 */
static int                      /* predicate */
before(
    celt x, celt y)             /* collating elements */
{
    return (x < y ? 1 : 0);
}

/*
 - eclass - supply cvec for an equivalence class
 * Must include case counterparts on request.
 ^ static struct cvec *eclass(struct vars *, celt, int);
 */
static struct cvec *
eclass(
    struct vars *v,             /* context */
    celt c,                     /* collating element representing the
                                 * equivalence class. */
    int cases)                  /* all cases? */
{
    struct cvec *cv;

    /*
     * Crude fake equivalence class for testing.
     */

    if ((v->cflags&REG_FAKE) && c == 'x') {
        cv = getcvec(v, 4, 0);
        NOERRN();
        addchr(cv, (chr)'x');
        addchr(cv, (chr)'y');
        if (cases) {
            addchr(cv, (chr)'X');
            addchr(cv, (chr)'Y');
        }
        return cv;
    }

    /*
     * Add character itself.
     */

    if (cases) {
        return allcases(v, c);
    }
    cv = getcvec(v, 1, 0);
    NOERRN();
    addchr(cv, (chr)c);
    return cv;
}

/*
 - cclass - supply cvec for a character class
 * Must include case counterparts on request.
 ^ static struct cvec *cclass(struct vars *, const rchr, const rchr, int);
 */
static struct cvec *
cclass(
    struct vars *v,             /* context */
    const rchr startp,          /* where the name starts */
    const rchr endp,            /* just past the end of the name */
    int cases)                  /* case-independent? */
{
    struct cvec *cv;
    const ClassInfo *info;

    /*
     * Lookup name into class array.
     */

    for (info=classes; info->name; info++) {
        if (StrEq(info->name, startp, endp)) {
            /*
             * Found, call proc for cvec.
             */

            cv = (cases?(*info->procNocase):(*info->proc))(v);
            NOERRN();
            return cv;
        }
    }

    /*
     * Not found.
     */

    ERR(REG_ECTYPE);
    return NULL;
}

/*
 - allcases - supply cvec for all case counterparts of a chr (including itself)
 * This is a shortcut, preferably an efficient one, for simple characters;
 * messy cases are done via range().
 ^ static struct cvec *allcases(struct vars *, pchr);
 */
static struct cvec *
allcases(
    struct vars *v,             /* context */
    pchr pc)                    /* character to get case equivs of */
{
    struct cvec *cv;
    chr lc, uc, tc;

    lc = Coatl_CharToLowercase((chr)pc);
    uc = Coatl_CharToUppercase((chr)pc);
    tc = Coatl_CharToTitlecase((chr)pc);

    if (tc != uc) {
        cv = getcvec(v, 3, 0);
    } else if (lc != uc) {
        cv = getcvec(v, 2, 0);
    } else {
        cv = getcvec(v, 1, 0);
    }
    NOERRN();
    addchr(cv, lc);
    if (lc != uc) addchr(cv, uc);
    if (tc != uc) addchr(cv, tc);
    return cv;
}

/*
 - cmp - chr-substring compare
 * Backrefs need this.  It should preferably be efficient.
 * Note that it does not need to report anything except equal/unequal.
 * Note also that the length is exact, and the comparison should not
 * stop at embedded NULs!
 ^ static int cmp(rchr, rchr, size_t);
 */
static int                      /* 0 for equal, nonzero for unequal */
cmp(
    const rchr x, const rchr y, /* strings to compare */
    size_t len)                 /* exact length of comparison */
{
    rchr x2, y2; RCHR_SET(x2, x), RCHR_SET(y2, y);
    for (; len > 0; len--, RCHR_FWD(x2,1), RCHR_FWD(y2,1)) {
        chr cx = RCHR_CHR(x2), cy = RCHR_CHR(y2);
        if (cx != cy) return 1;
    }
    return 0;
}

/*
 - casecmp - case-independent chr-substring compare
 * REG_ICASE backrefs need this.  It should preferably be efficient.
 * Note that it does not need to report anything except equal/unequal.
 * Note also that the length is exact, and the comparison should not
 * stop at embedded NULs!
 ^ static int casecmp(rchr, rchr, size_t);
 */
static int                      /* 0 for equal, nonzero for unequal */
casecmp(
    const rchr x, const rchr y, /* strings to compare */
    size_t len)                 /* exact length of comparison */
{
    rchr x2, y2; RCHR_SET(x2, x), RCHR_SET(y2, y);
    for (; len > 0; len--, RCHR_FWD(x2,1), RCHR_FWD(y2,1)) {
        chr cx = RCHR_CHR(x2), cy = RCHR_CHR(y2);
        if (cx != cy 
                && Coatl_CharToLowercase(cx) != Coatl_CharToLowercase(cy)) {
            return 1;
        }
    }
    return 0;
}
}
