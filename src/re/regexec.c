/*
 * re_*exec and friends - match REs
 *
 * Copyright (c) 1998, 1999 Henry Spencer.  All rights reserved.
 *
 * Development of this software was funded, in part, by Cray Research Inc.,
 * UUNET Communications Services Inc., Sun Microsystems Inc., and Scriptics
 * Corporation, none of whom are responsible for the results.  The author
 * thanks all of them.
 *
 * Redistribution and use in source and binary forms -- with or without
 * modification -- are permitted for any purpose, provided that
 * redistributions in source form retain this entire copyright notice and
 * indicate the origin and nature of any modifications.
 *
 * I'd appreciate being given credit for this package in the documentation of
 * software which uses it, but that is not a requirement.
 *
 * THIS SOFTWARE IS PROVIDED ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES,
 * INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY
 * AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL
 * HENRY SPENCER BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
 * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "regguts.h"

/*
 * Lazy-DFA representation.
 */

struct arcp {			/* "pointer" to an outarc */
    struct sset *ss;
    color co;
};

struct sset {			/* state set */
    unsigned *states;		/* pointer to bitvector */
    unsigned hash;		/* hash of bitvector */
#define	HASH(bv, nw)	(((nw) == 1) ? *(bv) : hash(bv, nw))
#define	HIT(h,bv,ss,nw)	((ss)->hash == (h) && ((nw) == 1 || \
	memcmp(VS(bv), VS((ss)->states), (nw)*sizeof(unsigned)) == 0))
    int flags;
#define	STARTER		01	/* the initial state set */
#define	POSTSTATE	02	/* includes the goal state */
#define	LOCKED		04	/* locked in cache */
#define	NOPROGRESS	010	/* zero-progress state set */
    struct arcp ins;		/* chain of inarcs pointing here */
    rchr lastseen;		/* last entered on arrival here */
    struct sset **outs;		/* outarc vector indexed by color */
    struct arcp *inchain;	/* chain-pointer vector for outarcs */
};

struct dfa {
    int nssets;			/* size of cache */
    int nssused;		/* how many entries occupied yet */
    int nstates;		/* number of states */
    int ncolors;		/* length of outarc and inchain vectors */
    int wordsper;		/* length of state-set bitvectors */
    struct sset *ssets;		/* state-set cache */
    unsigned *statesarea;	/* bitvector storage */
    unsigned *work;		/* pointer to work area within statesarea */
    struct sset **outsarea;	/* outarc-vector storage */
    struct arcp *incarea;	/* inchain storage */
    struct cnfa *cnfa;
    struct colormap *cm;
    rchr lastpost;		/* location of last cache-flushed success */
    rchr lastnopr;		/* location of last cache-flushed NOPROGRESS */
    struct sset *search;	/* replacement-search-pointer memory */
    int cptsmalloced;		/* were the areas individually malloced? */
    char *mallocarea;		/* self, or master malloced area, or NULL */
};

#define	WORK	1		/* number of work bitvectors needed */

/*
 * Setup for non-malloc allocation for small cases.
 */

#define	FEWSTATES	20	/* must be less than UBITS */
#define	FEWCOLORS	15
struct smalldfa {
    struct dfa dfa;
    struct sset ssets[FEWSTATES*2];
    unsigned statesarea[FEWSTATES*2 + WORK];
    struct sset *outsarea[FEWSTATES*2 * FEWCOLORS];
    struct arcp incarea[FEWSTATES*2 * FEWCOLORS];
};
#define	DOMALLOC	((struct smalldfa *)NULL)	/* force malloc */

/*
 * Internal variables, bundled for easy passing around.
 */

struct vars {
    regex_t *re;
    struct guts *g;
    int eflags;			/* copies of arguments */
    size_t nmatch;
    regmatch_t *pmatch;
    rm_detail_t *details;
    rchr start;		/* start of string */
    rchr stop;		/* just past end of string */
    int err;			/* error code if any (0 none) */
    regoff_t *mem;		/* memory vector for backtracking */
    struct smalldfa dfa1;
    struct smalldfa dfa2;
};
#define	VISERR(vv) ((vv)->err != 0)	/* have we seen an error yet? */
#define	ISERR()	VISERR(v)
#define	VERR(vv,e) (((vv)->err) ? (vv)->err : ((vv)->err = (e)))
#define	ERR(e)	VERR(v, e)	/* record an error */
#define	NOERR()	{if (ISERR()) return v->err;}	/* if error seen, return it */
#define	OFF(p)	RCHR_INDEX(p,v->start)
#define	LOFF(p)	((long)OFF(p))

/*
 * forward declarations
 */
/* =====^!^===== begin forwards =====^!^===== */
/* automatically gathered by fwd; do not hand-edit */
/* === regexec.c === */
int exec(regex_t *, rchr, size_t, rm_detail_t *, size_t, regmatch_t [], int);
static int simpleFind(struct vars *const, struct cnfa *const, struct colormap *const);
static int complicatedFind(struct vars *const, struct cnfa *const, struct colormap *const);
static int complicatedFindLoop(struct vars *const, struct cnfa *const, struct colormap *const, struct dfa *const, struct dfa *const, rchr *);
static void zapSubexpressions(regmatch_t *const, const size_t);
static void zapSubtree(struct vars *const, struct subre *const);
static void subset(struct vars *const, struct subre *const, const rchr, const rchr);
static int dissect(struct vars *const, struct subre *, const rchr, const rchr);
static int concatenationDissect(struct vars *const, struct subre *const, const rchr, const rchr);
static int alternationDissect(struct vars *const, struct subre *, const rchr, const rchr);
static int complicatedDissect(struct vars *const, struct subre *const, const rchr, const rchr);
static int complicatedCapturingDissect(struct vars *const, struct subre *const, const rchr, const rchr);
static int complicatedConcatenationDissect(struct vars *const, struct subre *const, const rchr, const rchr);
static int complicatedReversedDissect(struct vars *const, struct subre *const, const rchr, const rchr);
static int complicatedBackrefDissect(struct vars *const, struct subre *const, const rchr, const rchr);
static int complicatedAlternationDissect(struct vars *const, struct subre *, const rchr, const rchr);
/* === rege_dfa.c === */
static void longest(struct vars *const, struct dfa *const, const rchr, const rchr, rchr *, int *const);
static void shortest(struct vars *const, struct dfa *const, const rchr, const rchr, const rchr, rchr *, rchr *, int *const);
static void lastCold(struct vars *const, struct dfa *const, rchr *);
static struct dfa *newDFA(struct vars *const, struct cnfa *const, struct colormap *const, struct smalldfa *);
static void freeDFA(struct dfa *const);
static unsigned hash(unsigned *const, const int);
static struct sset *initialize(struct vars *const, struct dfa *const, const rchr);
static struct sset *miss(struct vars *const, struct dfa *const, struct sset *const, const pcolor, const rchr, const rchr);
static int checkLAConstraint(struct vars *const, struct cnfa *const, const rchr, const pcolor);
static struct sset *getVacantSS(struct vars *const, struct dfa *const, const rchr, const rchr);
static struct sset *pickNextSS(struct vars *const, struct dfa *const, const rchr, const rchr);
/* automatically gathered by fwd; do not hand-edit */
/* =====^!^===== end forwards =====^!^===== */

/*
 - exec - match regular expression
 ^ int exec(regex_t *, const __REG_WIDE_T *, size_t, rm_detail_t *,
 ^					size_t, regmatch_t [], int);
 */
int
exec(
    regex_t *re,
    rchr string,
    size_t len,
    rm_detail_t *details,
    size_t nmatch,
    regmatch_t pmatch[],
    int flags)
{
    AllocVars(v);
    int st, backref;
    size_t n;
#define	LOCALMAT	20
    regmatch_t mat[LOCALMAT];
#define	LOCALMEM	40
    regoff_t mem[LOCALMEM];

    /*
     * Sanity checks.
     */

    if (re == NULL || RCHR_ISNULL(string) || re->re_magic != REMAGIC) {
	FreeVars(v);
	return REG_INVARG;
    }
    if (re->re_csize != sizeof(chr)) {
	FreeVars(v);
	return REG_MIXED;
    }

    /*
     * Setup.
     */

    v->re = re;
    v->g = (struct guts *)re->re_guts;
    if ((v->g->cflags&REG_EXPECT) && details == NULL) {
	FreeVars(v);
	return REG_INVARG;
    }
    if (v->g->info&REG_UIMPOSSIBLE) {
	FreeVars(v);
	return REG_NOMATCH;
    }
    backref = (v->g->info&REG_UBACKREF) ? 1 : 0;
    v->eflags = flags;
    if (v->g->cflags&REG_NOSUB) {
	nmatch = 0;		/* override client */
    }
    v->nmatch = nmatch;
    if (backref) {
	/*
	 * Need work area.
	 */

	if (v->g->nsub + 1 <= LOCALMAT) {
	    v->pmatch = mat;
	} else {
	    v->pmatch = (regmatch_t *)
		    MALLOC((v->g->nsub + 1) * sizeof(regmatch_t));
	}
	if (v->pmatch == NULL) {
	    FreeVars(v);
	    return REG_ESPACE;
	}
	v->nmatch = v->g->nsub + 1;
    } else {
	v->pmatch = pmatch;
    }
    v->details = details;
    RCHR_SET(v->start, string);
    RCHR_SET(v->stop, string); RCHR_FWD(v->stop, len);
    v->err = 0;
    if (backref) {
	/*
	 * Need retry memory.
	 */

	assert(v->g->ntree >= 0);
	n = (size_t)v->g->ntree;
	if (n <= LOCALMEM) {
	    v->mem = mem;
	} else {
	    v->mem = (regoff_t *) MALLOC(n*sizeof(regoff_t));
	}
	if (v->mem == NULL) {
	    if (v->pmatch != pmatch && v->pmatch != mat) {
		FREE(v->pmatch);
	    }
	    FreeVars(v);
	    return REG_ESPACE;
	}
    } else {
	v->mem = NULL;
    }

    /*
     * Do it.
     */

    assert(v->g->tree != NULL);
    if (backref) {
	st = complicatedFind(v, &v->g->tree->cnfa, &v->g->cmap);
    } else {
	st = simpleFind(v, &v->g->tree->cnfa, &v->g->cmap);
    }

    /*
     * Copy (portion of) match vector over if necessary.
     */

    if (st == REG_OKAY && v->pmatch != pmatch && nmatch > 0) {
	zapSubexpressions(pmatch, nmatch);
	n = (nmatch < v->nmatch) ? nmatch : v->nmatch;
	memcpy(VS(pmatch), VS(v->pmatch), n*sizeof(regmatch_t));
    }

    /*
     * Clean up.
     */

    if (v->pmatch != pmatch && v->pmatch != mat) {
	FREE(v->pmatch);
    }
    if (v->mem != NULL && v->mem != mem) {
	FREE(v->mem);
    }
    FreeVars(v);
    return st;
}

/*
 - simpleFind - find a match for the main NFA (no-complications case)
 ^ static int simpleFind(struct vars *, struct cnfa *, struct colormap *);
 */
static int
simpleFind(
    struct vars *const v,
    struct cnfa *const cnfa,
    struct colormap *const cm)
{
    struct dfa *s, *d;
    rchr begin, end = RCHR_NULL;
    rchr cold;
    rchr open, close;		/* Open and close of range of possible
				 * starts */
    int hitend;
    int shorter = (v->g->tree->flags&SHORTER) ? 1 : 0;

    /*
     * First, a shot with the search RE.
     */

    s = newDFA(v, &v->g->search, cm, &v->dfa1);
    assert(!(ISERR() && s != NULL));
    NOERR();
    MDEBUG(("\nsearch at %ld\n", LOFF(v->start)));
    RCHR_SETNULL(cold);
    shortest(v, s, v->start, v->start, v->stop, &close, &cold, NULL);
    freeDFA(s);
    NOERR();
    if (v->g->cflags&REG_EXPECT) {
	assert(v->details != NULL);
	if (!RCHR_ISNULL(cold)) {
	    v->details->rm_extend.rm_so = OFF(cold);
	} else {
	    v->details->rm_extend.rm_so = OFF(v->stop);
	}
	v->details->rm_extend.rm_eo = OFF(v->stop);	/* unknown */
    }
    if (RCHR_ISNULL(close)) {	/* not found */
	return REG_NOMATCH;
    }
    if (v->nmatch == 0) {	/* found, don't need exact location */
	return REG_OKAY;
    }

    /*
     * Find starting point and match.
     */

    assert(!RCHR_ISNULL(cold));
    RCHR_SET(open, cold);
    RCHR_SETNULL(cold);
    MDEBUG(("between %ld and %ld\n", LOFF(open), LOFF(close)));
    d = newDFA(v, cnfa, cm, &v->dfa1);
    assert(!(ISERR() && d != NULL));
    NOERR();
    for (RCHR_SET(begin, open); !RCHR_GT(begin, close); RCHR_FWD(begin,1)) {
	MDEBUG(("\nfind trying at %ld\n", LOFF(begin)));
	if (shorter) {
	    shortest(v, d, begin, begin, v->stop, &end, NULL, &hitend);
	} else {
	    longest(v, d, begin, v->stop, &end, &hitend);
	}
	NOERR();
	if (hitend && RCHR_ISNULL(cold)) {
	    RCHR_SET(cold, begin);
	}
	if (!RCHR_ISNULL(end)) {
	    break;		/* NOTE BREAK OUT */
	}
    }
    assert(!RCHR_ISNULL(end));	/* search RE succeeded so loop should */
    freeDFA(d);

    /*
     * And pin down details.
     */

    assert(v->nmatch > 0);
    v->pmatch[0].rm_so = OFF(begin);
    v->pmatch[0].rm_eo = OFF(end);
    if (v->g->cflags&REG_EXPECT) {
	if (!RCHR_ISNULL(cold)) {
	    v->details->rm_extend.rm_so = OFF(cold);
	} else {
	    v->details->rm_extend.rm_so = OFF(v->stop);
	}
	v->details->rm_extend.rm_eo = OFF(v->stop);	/* unknown */
    }
    if (v->nmatch == 1) {	/* no need for submatches */
	return REG_OKAY;
    }

    /*
     * Submatches.
     */

    zapSubexpressions(v->pmatch, v->nmatch);
    return dissect(v, v->g->tree, begin, end);
}

/*
 - complicatedFind - find a match for the main NFA (with complications)
 ^ static int complicatedFind(struct vars *, struct cnfa *, struct colormap *);
 */
static int
complicatedFind(
    struct vars *const v,
    struct cnfa *const cnfa,
    struct colormap *const cm)
{
    struct dfa *s, *d;
    rchr cold = RCHR_NULL;
    int ret;

    s = newDFA(v, &v->g->search, cm, &v->dfa1);
    NOERR();
    d = newDFA(v, cnfa, cm, &v->dfa2);
    if (ISERR()) {
	assert(d == NULL);
	freeDFA(s);
	return v->err;
    }

    ret = complicatedFindLoop(v, cnfa, cm, d, s, &cold);

    freeDFA(d);
    freeDFA(s);
    NOERR();
    if (v->g->cflags&REG_EXPECT) {
	assert(v->details != NULL);
	if (!RCHR_ISNULL(cold)) {
	    v->details->rm_extend.rm_so = OFF(cold);
	} else {
	    v->details->rm_extend.rm_so = OFF(v->stop);
	}
	v->details->rm_extend.rm_eo = OFF(v->stop);	/* unknown */
    }
    return ret;
}

/*
 - complicatedFindLoop - the heart of complicatedFind
 ^ static int complicatedFindLoop(struct vars *, struct cnfa *, struct colormap *,
 ^	struct dfa *, struct dfa *, rchr *);
 */
static int
complicatedFindLoop(
    struct vars *const v,
    struct cnfa *const cnfa,
    struct colormap *const cm,
    struct dfa *const d,
    struct dfa *const s,
    rchr *coldp)		/* where to put coldstart pointer */
{
    rchr begin, end;
    rchr cold;
    rchr open, close;		/* Open and close of range of possible
				 * starts */
    rchr estart, estop;
    int er, hitend;
    int shorter = v->g->tree->flags&SHORTER;

    assert(d != NULL && s != NULL);
    RCHR_SETNULL(cold);
    RCHR_SET(close, v->start);
    do {
	MDEBUG(("\ncsearch at %ld\n", LOFF(close)));
	shortest(v, s, close, close, v->stop, &close, &cold, NULL);
	if (RCHR_ISNULL(close)) {
	    break;		/* NOTE BREAK */
	}
	assert(!RCHR_ISNULL(cold));
	RCHR_SET(open, cold);
	RCHR_SETNULL(cold);
	MDEBUG(("cbetween %ld and %ld\n", LOFF(open), LOFF(close)));
	for (RCHR_SET(begin, open); !RCHR_GT(begin,close); RCHR_FWD(begin,1)) {
	    MDEBUG(("\ncomplicatedFind trying at %ld\n", LOFF(begin)));
	    RCHR_SET(estart, begin);
	    RCHR_SET(estop, v->stop);
	    for (;;) {
		if (shorter) {
		    shortest(v, d, begin, estart, estop, &end, NULL, &hitend);
		} else {
		    longest(v, d, begin, estop, &end, &hitend);
		}
		if (hitend && RCHR_ISNULL(cold)) {
		    RCHR_SET(cold, begin);
		}
		if (RCHR_ISNULL(end)) {
		    break;	/* NOTE BREAK OUT */
		}

		MDEBUG(("tentative end %ld\n", LOFF(end)));
		zapSubexpressions(v->pmatch, v->nmatch);
		zapSubtree(v, v->g->tree);
		er = complicatedDissect(v, v->g->tree, begin, end);
		if (er == REG_OKAY) {
		    if (v->nmatch > 0) {
			v->pmatch[0].rm_so = OFF(begin);
			v->pmatch[0].rm_eo = OFF(end);
		    }
		    RCHR_SET(*coldp, cold);
		    return REG_OKAY;
		}
		if (er != REG_NOMATCH) {
		    ERR(er);
		    return er;
		}
		if ((shorter) ? RCHR_EQ(end, estop) : RCHR_EQ(end, begin)) {
		    /*
		     * No point in trying again.
		     */

		    RCHR_SET(*coldp, cold);
		    return REG_NOMATCH;
		}

		/*
		 * Go around and try again
		 */

		if (shorter) {
		    RCHR_SET(estart, end); RCHR_FWD(estart,1);
		} else {
		    RCHR_SET(estop, end); RCHR_BWD(estop,1);
		}
	    }
	}
    } while (RCHR_LT(close, v->stop));

    RCHR_SET(*coldp, cold);
    return REG_NOMATCH;
}

/*
 - zapSubexpressions - initialize the subexpression matches to "no match"
 ^ static void zapSubexpressions(regmatch_t *, size_t);
 */
static void
zapSubexpressions(
    regmatch_t *const p,
    const size_t n)
{
    size_t i;

    for (i = n-1; i > 0; i--) {
	p[i].rm_so = -1;
	p[i].rm_eo = -1;
    }
}

/*
 - zapSubtree - initialize the retry memory of a subtree to zeros
 ^ static void zapSubtree(struct vars *, struct subre *);
 */
static void
zapSubtree(
    struct vars *const v,
    struct subre *const t)
{
    if (t == NULL) {
	return;
    }

    assert(v->mem != NULL);
    v->mem[t->retry] = 0;
    if (t->op == '(') {
	assert(t->subno > 0);
	v->pmatch[t->subno].rm_so = -1;
	v->pmatch[t->subno].rm_eo = -1;
    }

    if (t->left != NULL) {
	zapSubtree(v, t->left);
    }
    if (t->right != NULL) {
	zapSubtree(v, t->right);
    }
}

/*
 - subset - set any subexpression relevant to a successful subre
 ^ static void subset(struct vars *, struct subre *, const rchr, const rchr);
 */
static void
subset(
    struct vars *const v,
    struct subre *const sub,
    const rchr begin,
    const rchr end)
{
    int n = sub->subno;

    assert(n > 0);
    if ((size_t)n >= v->nmatch) {
	return;
    }

    MDEBUG(("setting %d\n", n));
    v->pmatch[n].rm_so = OFF(begin);
    v->pmatch[n].rm_eo = OFF(end);
}

/*
 - dissect - determine subexpression matches (uncomplicated case)
 ^ static int dissect(struct vars *, struct subre *, const rchr, const rchr);
 */
static int			/* regexec return code */
dissect(
    struct vars *const v,
    struct subre *t,
    const rchr begin,		/* beginning of relevant substring */
    const rchr end)		/* end of same */
{
#ifndef COMPILER_DOES_TAILCALL_OPTIMIZATION
  restart:
#endif
    assert(t != NULL);
    MDEBUG(("dissect %ld-%ld\n", LOFF(begin), LOFF(end)));

    switch (t->op) {
    case '=':			/* terminal node */
	assert(t->left == NULL && t->right == NULL);
	return REG_OKAY;	/* no action, parent did the work */
    case '|':			/* alternation */
	assert(t->left != NULL);
	return alternationDissect(v, t, begin, end);
    case 'b':			/* back ref -- shouldn't be calling us! */
	return REG_ASSERT;
    case '.':			/* concatenation */
	assert(t->left != NULL && t->right != NULL);
	return concatenationDissect(v, t, begin, end);
    case '(':			/* capturing */
	assert(t->left != NULL && t->right == NULL);
	assert(t->subno > 0);
	subset(v, t, begin, end);
#ifndef COMPILER_DOES_TAILCALL_OPTIMIZATION
	t = t->left;
	goto restart;
#else
	return dissect(v, t->left, begin, end);
#endif
    default:
	return REG_ASSERT;
    }
}

/*
 - concatenationDissect - determine concatenation subexpression matches
 - (uncomplicated)
 ^ static int concatenationDissect(struct vars *, struct subre *, const rchr, const rchr);
 */
static int			/* regexec return code */
concatenationDissect(
    struct vars *const v,
    struct subre *const t,
    const rchr begin,		/* beginning of relevant substring */
    const rchr end)		/* end of same */
{
    struct dfa *d, *d2;
    rchr mid;
    int i;
    int shorter = (t->left->flags&SHORTER) ? 1 : 0;
    rchr stop, tmp;

    RCHR_SET(stop, (shorter) ? end : begin);

    assert(t->op == '.');
    assert(t->left != NULL && t->left->cnfa.nstates > 0);
    assert(t->right != NULL && t->right->cnfa.nstates > 0);

    d = newDFA(v, &t->left->cnfa, &v->g->cmap, &v->dfa1);
    NOERR();
    d2 = newDFA(v, &t->right->cnfa, &v->g->cmap, &v->dfa2);
    if (ISERR()) {
	assert(d2 == NULL);
	freeDFA(d);
	return v->err;
    }

    /*
     * Pick a tentative midpoint.
     */

    if (shorter) {
	shortest(v, d, begin, begin, end, &mid, NULL, NULL);
    } else {
	longest(v, d, begin, end, &mid, NULL);
    }
    if (RCHR_ISNULL(mid)) {
	freeDFA(d);
	freeDFA(d2);
	return REG_ASSERT;
    }
    MDEBUG(("tentative midpoint %ld\n", LOFF(mid)));

    /*
     * Iterate until satisfaction or failure.
     */

    while (longest(v, d2, mid, end, &tmp, NULL), !RCHR_EQ(tmp, end)) {
	/*
	 * That midpoint didn't work, find a new one.
	 */

	if (RCHR_EQ(mid, stop)) {
	    /*
	     * All possibilities exhausted!
	     */

	    MDEBUG(("no midpoint!\n"));
	    freeDFA(d);
	    freeDFA(d2);
	    return REG_ASSERT;
	}
	if (shorter) {
	    RCHR_FWD(mid,1);
	    shortest(v, d, begin, mid, end, &mid, NULL, NULL);
	} else {
	    RCHR_BWD(mid,1);
	    longest(v, d, begin, mid, &mid, NULL);
	}
	if (RCHR_ISNULL(mid)) {
	    /*
	     * Failed to find a new one!
	     */

	    MDEBUG(("failed midpoint!\n"));
	    freeDFA(d);
	    freeDFA(d2);
	    return REG_ASSERT;
	}
	MDEBUG(("new midpoint %ld\n", LOFF(mid)));
    }

    /*
     * Satisfaction.
     */

    MDEBUG(("successful\n"));
    freeDFA(d);
    freeDFA(d2);
    i = dissect(v, t->left, begin, mid);
    if (i != REG_OKAY) {
	return i;
    }
    return dissect(v, t->right, mid, end);
}

/*
 - alternationDissect - determine alternative subexpression matches (uncomplicated)
 ^ static int alternationDissect(struct vars *, struct subre *, const rchr, const rchr);
 */
static int			/* regexec return code */
alternationDissect(
    struct vars *const v,
    struct subre *t,
    const rchr begin,		/* beginning of relevant substring */
    const rchr end)		/* end of same */
{
    int i;
    rchr tmp;

    assert(t != NULL);
    assert(t->op == '|');

    for (i = 0; t != NULL; t = t->right, i++) {
	struct dfa *d;

	MDEBUG(("trying %dth\n", i));
	assert(t->left != NULL && t->left->cnfa.nstates > 0);
	d = newDFA(v, &t->left->cnfa, &v->g->cmap, &v->dfa1);
	if (ISERR()) {
	    return v->err;
	}
	if (longest(v, d, begin, end, &tmp, NULL), RCHR_EQ(tmp, end)) {
	    MDEBUG(("success\n"));
	    freeDFA(d);
	    return dissect(v, t->left, begin, end);
	}
	freeDFA(d);
    }
    return REG_ASSERT;		/* none of them matched?!? */
}

/*
 - complicatedDissect - determine subexpression matches (with complications)
 * The retry memory stores the offset of the trial midpoint from begin, plus 1
 * so that 0 uniquely means "clean slate".
 ^ static int complicatedDissect(struct vars *, struct subre *, const rchr, const rchr);
 */
static int		/* regexec return code */
complicatedDissect(
    struct vars *const v,
    struct subre *const t,
    const rchr begin,		/* beginning of relevant substring */
    const rchr end)		/* end of same */
{
    assert(t != NULL);
    MDEBUG(("complicatedDissect %ld-%ld %c\n", LOFF(begin), LOFF(end), t->op));

    switch (t->op) {
    case '=':			/* terminal node */
	assert(t->left == NULL && t->right == NULL);
	return REG_OKAY;	/* no action, parent did the work */
    case '|':			/* alternation */
	assert(t->left != NULL);
	return complicatedAlternationDissect(v, t, begin, end);
    case 'b':			/* back ref -- shouldn't be calling us! */
	assert(t->left == NULL && t->right == NULL);
	return complicatedBackrefDissect(v, t, begin, end);
    case '.':			/* concatenation */
	assert(t->left != NULL && t->right != NULL);
	return complicatedConcatenationDissect(v, t, begin, end);
    case '(':			/* capturing */
	assert(t->left != NULL && t->right == NULL);
	assert(t->subno > 0);
	return complicatedCapturingDissect(v, t, begin, end);
    default:
	return REG_ASSERT;
    }
}

static int			/* regexec return code */
complicatedCapturingDissect(
    struct vars *const v,
    struct subre *const t,
    const rchr begin,		/* beginning of relevant substring */
    const rchr end)		/* end of same */
{
    int er = complicatedDissect(v, t->left, begin, end);

    if (er == REG_OKAY) {
	subset(v, t, begin, end);
    }
    return er;
}

/*
 - complicatedConcatenationDissect - concatenation subexpression matches (with complications)
 * The retry memory stores the offset of the trial midpoint from begin, plus 1
 * so that 0 uniquely means "clean slate".
 ^ static int complicatedConcatenationDissect(struct vars *, struct subre *, const rchr, const rchr);
 */
static int			/* regexec return code */
complicatedConcatenationDissect(
    struct vars *const v,
    struct subre *const t,
    const rchr begin,		/* beginning of relevant substring */
    const rchr end)		/* end of same */
{
    struct dfa *d, *d2;
    rchr mid;
    rchr tmp;

    assert(t->op == '.');
    assert(t->left != NULL && t->left->cnfa.nstates > 0);
    assert(t->right != NULL && t->right->cnfa.nstates > 0);

    if (t->left->flags&SHORTER) { /* reverse scan */
	return complicatedReversedDissect(v, t, begin, end);
    }

    d = newDFA(v, &t->left->cnfa, &v->g->cmap, DOMALLOC);
    if (ISERR()) {
	return v->err;
    }
    d2 = newDFA(v, &t->right->cnfa, &v->g->cmap, DOMALLOC);
    if (ISERR()) {
	freeDFA(d);
	return v->err;
    }
    MDEBUG(("cConcat %d\n", t->retry));

    /*
     * Pick a tentative midpoint.
     */

    if (v->mem[t->retry] == 0) {
	longest(v, d, begin, end, &mid, NULL);
	if (RCHR_ISNULL(mid)) {
	    freeDFA(d);
	    freeDFA(d2);
	    return REG_NOMATCH;
	}
	MDEBUG(("tentative midpoint %ld\n", LOFF(mid)));
	v->mem[t->retry] = LOFF(mid) - LOFF(begin) + 1;//FIXME? (mid - begin) + 1;
    } else {
	RCHR_SET(mid, begin); RCHR_FWD(mid, (v->mem[t->retry] - 1));
	MDEBUG(("working midpoint %ld\n", LOFF(mid)));
    }

    /*
     * Iterate until satisfaction or failure.
     */

    for (;;) {
	/*
	 * Try this midpoint on for size.
	 */

	if (longest(v, d2, mid, end, &tmp, NULL), RCHR_EQ(tmp, end)) {
	    int er = complicatedDissect(v, t->left, begin, mid);

	    if (er == REG_OKAY) {
		er = complicatedDissect(v, t->right, mid, end);
		if (er == REG_OKAY) {
		    /*
		     * Satisfaction.
		     */

		    MDEBUG(("successful\n"));
		    freeDFA(d);
		    freeDFA(d2);
		    return REG_OKAY;
		}
	    }
	    if ((er != REG_OKAY) && (er != REG_NOMATCH)) {
		freeDFA(d);
		freeDFA(d2);
		return er;
	    }
	}

	/*
	 * That midpoint didn't work, find a new one.
	 */

	if (RCHR_EQ(mid, begin)) {
	    /*
	     * All possibilities exhausted.
	     */

	    MDEBUG(("%d no midpoint\n", t->retry));
	    freeDFA(d);
	    freeDFA(d2);
	    return REG_NOMATCH;
	}
	RCHR_BWD(mid,1);
	longest(v, d, begin, mid, &mid, NULL);
	if (RCHR_ISNULL(mid)) {
	    /*
	     * Failed to find a new one.
	     */

	    MDEBUG(("%d failed midpoint\n", t->retry));
	    freeDFA(d);
	    freeDFA(d2);
	    return REG_NOMATCH;
	}
	MDEBUG(("%d: new midpoint %ld\n", t->retry, LOFF(mid)));
	v->mem[t->retry] = (LOFF(mid) - LOFF(begin)) + 1;//FIXME?(mid - begin) + 1;
	zapSubtree(v, t->left);
	zapSubtree(v, t->right);
    }
}

/*
 - complicatedReversedDissect - determine backref shortest-first subexpression
 - matches
 * The retry memory stores the offset of the trial midpoint from begin, plus 1
 * so that 0 uniquely means "clean slate".
 ^ static int complicatedReversedDissect(struct vars *, struct subre *, const rchr, const rchr);
 */
static int			/* regexec return code */
complicatedReversedDissect(
    struct vars *const v,
    struct subre *const t,
    const rchr begin,		/* beginning of relevant substring */
    const rchr end)		/* end of same */
{
    struct dfa *d, *d2;
    rchr mid;
    rchr tmp;

    assert(t->op == '.');
    assert(t->left != NULL && t->left->cnfa.nstates > 0);
    assert(t->right != NULL && t->right->cnfa.nstates > 0);
    assert(t->left->flags&SHORTER);

    /*
     * Concatenation -- need to split the substring between parts.
     */

    d = newDFA(v, &t->left->cnfa, &v->g->cmap, DOMALLOC);
    if (ISERR()) {
	return v->err;
    }
    d2 = newDFA(v, &t->right->cnfa, &v->g->cmap, DOMALLOC);
    if (ISERR()) {
	freeDFA(d);
	return v->err;
    }
    MDEBUG(("cRev %d\n", t->retry));

    /*
     * Pick a tentative midpoint.
     */

    if (v->mem[t->retry] == 0) {
	shortest(v, d, begin, begin, end, &mid, NULL, NULL);
	if (RCHR_ISNULL(mid)) {
	    freeDFA(d);
	    freeDFA(d2);
	    return REG_NOMATCH;
	}
	MDEBUG(("tentative midpoint %ld\n", LOFF(mid)));
	v->mem[t->retry] = (LOFF(mid) - LOFF(begin)) + 1;//FIXME?(mid - begin) + 1;
    } else {
	RCHR_SET(mid, begin); RCHR_FWD(mid, (v->mem[t->retry] - 1));
	MDEBUG(("working midpoint %ld\n", LOFF(mid)));
    }

    /*
     * Iterate until satisfaction or failure.
     */

    for (;;) {
	/*
	 * Try this midpoint on for size.
	 */

	if (longest(v, d2, mid, end, &tmp, NULL), RCHR_EQ(tmp, end)) {
	    int er = complicatedDissect(v, t->left, begin, mid);

	    if (er == REG_OKAY) {
		er = complicatedDissect(v, t->right, mid, end);
		if (er == REG_OKAY) {
		    /*
		     * Satisfaction.
		     */

		    MDEBUG(("successful\n"));
		    freeDFA(d);
		    freeDFA(d2);
		    return REG_OKAY;
		}
	    }
	    if (er != REG_OKAY && er != REG_NOMATCH) {
		freeDFA(d);
		freeDFA(d2);
		return er;
	    }
	}

	/*
	 * That midpoint didn't work, find a new one.
	 */

	if (RCHR_EQ(mid, end)) {
	    /*
	     * All possibilities exhausted.
	     */

	    MDEBUG(("%d no midpoint\n", t->retry));
	    freeDFA(d);
	    freeDFA(d2);
	    return REG_NOMATCH;
	}
	RCHR_FWD(mid,1);
	shortest(v, d, begin, mid, end, &mid, NULL, NULL);
	if (RCHR_ISNULL(mid)) {
	    /*
	     * Failed to find a new one.
	     */

	    MDEBUG(("%d failed midpoint\n", t->retry));
	    freeDFA(d);
	    freeDFA(d2);
	    return REG_NOMATCH;
	}
	MDEBUG(("%d: new midpoint %ld\n", t->retry, LOFF(mid)));
	v->mem[t->retry] = (LOFF(mid) - LOFF(begin)) + 1;//FIXME?(mid - begin) + 1;
	zapSubtree(v, t->left);
	zapSubtree(v, t->right);
    }
}

/*
 - complicatedBackrefDissect - determine backref subexpression matches
 ^ static int complicatedBackrefDissect(struct vars *, struct subre *, const rchr, const rchr);
 */
static int			/* regexec return code */
complicatedBackrefDissect(
    struct vars *const v,
    struct subre *const t,
    const rchr begin,		/* beginning of relevant substring */
    const rchr end)		/* end of same */
{
    int i, n = t->subno, min = t->min, max = t->max;
    rchr paren, p, stop;
    size_t len;

    assert(t != NULL);
    assert(t->op == 'b');
    assert(n >= 0);
    assert((size_t)n < v->nmatch);

    MDEBUG(("cbackref n%d %d{%d-%d}\n", t->retry, n, min, max));

    if (v->pmatch[n].rm_so == -1) {
	return REG_NOMATCH;
    }
    RCHR_SET(paren, v->start); RCHR_FWD(paren, v->pmatch[n].rm_so);
    len = v->pmatch[n].rm_eo - v->pmatch[n].rm_so;

    /*
     * No room to maneuver -- retries are pointless.
     */

    if (v->mem[t->retry]) {
	return REG_NOMATCH;
    }
    v->mem[t->retry] = 1;

    /*
     * Special-case zero-length string.
     */

    if (len == 0) {
	if (!RCHR_EQ(begin, end)) {
	    return REG_OKAY;
	}
	return REG_NOMATCH;
    }

    /*
     * And too-short string.
     */

    assert(!RCHR_LT(end, begin));
    if ((size_t)(LOFF(end) - LOFF(begin)) < len) {//FIXME?(end - begin) < len) {
	return REG_NOMATCH;
    }
    RCHR_SET(stop, end); RCHR_BWD(stop, len);

    /*
     * Count occurrences.
     */

    i = 0;
    for (RCHR_SET(p, begin); !RCHR_GT(p, stop) && (i < max || max == INFINITY); RCHR_FWD(p, len)) {
	if (v->g->compare(paren, p, len) != 0) {
	    break;
	}
	i++;
    }
    MDEBUG(("cbackref found %d\n", i));

    /*
     * And sort it out.
     */

    if (!RCHR_EQ(p, end)) {		/* didn't consume all of it */
	return REG_NOMATCH;
    }
    if (min <= i && (i <= max || max == INFINITY)) {
	return REG_OKAY;
    }
    return REG_NOMATCH;		/* out of range */
}

/*
 - complicatedAlternationDissect - determine alternative subexpression matches (w.
 - complications)
 ^ static int complicatedAlternationDissect(struct vars *, struct subre *, const rchr, const rchr);
 */
static int			/* regexec return code */
complicatedAlternationDissect(
    struct vars *const v,
    struct subre *t,
    const rchr begin,		/* beginning of relevant substring */
    const rchr end)		/* end of same */
{
    int er;
    rchr tmp;

#define	UNTRIED	0		/* not yet tried at all */
#define	TRYING	1		/* top matched, trying submatches */
#define	TRIED	2		/* top didn't match or submatches exhausted */

#ifndef COMPILER_DOES_TAILCALL_OPTIMIZATION
    if (0) {
    doRight:
	t = t->right;
    }
#endif
    if (t == NULL) {
	return REG_NOMATCH;
    }
    assert(t->op == '|');
    if (v->mem[t->retry] == TRIED) {
	goto doRight;
    }

    MDEBUG(("cAlt n%d\n", t->retry));
    assert(t->left != NULL);

    if (v->mem[t->retry] == UNTRIED) {
	struct dfa *d = newDFA(v, &t->left->cnfa, &v->g->cmap, DOMALLOC);

	if (ISERR()) {
	    return v->err;
	}
	if (longest(v, d, begin, end, &tmp, NULL), !RCHR_EQ(tmp, end)) {
	    freeDFA(d);
	    v->mem[t->retry] = TRIED;
	    goto doRight;
	}
	freeDFA(d);
	MDEBUG(("cAlt matched\n"));
	v->mem[t->retry] = TRYING;
    }

    er = complicatedDissect(v, t->left, begin, end);
    if (er != REG_NOMATCH) {
	return er;
    }

    v->mem[t->retry] = TRIED;
#ifndef COMPILER_DOES_TAILCALL_OPTIMIZATION
    goto doRight;
#else
  doRight:
    return complicatedAlternationDissect(v, t->right, begin, end);
#endif
}

#include "rege_dfa.c"

/*
 * Local Variables:
 * mode: c
 * c-basic-offset: 4
 * fill-column: 78
 * End:
 */
