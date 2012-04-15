/*
 * Copyright (c) 1998, 1999 Henry Spencer.  All rights reserved.
 *
 * Development of this software was funded, in part, by Cray Research Inc.,
 * UUNET Communications Services Inc., Sun Microsystems Inc., and Scriptics
 * Corporation, none of whom are responsible for the results. The author
 * thanks all of them.
 *
 * Redistribution and use in source and binary forms - with or without
 * modification - are permitted for any purpose, provided that redistributions
 * in source form retain this entire copyright notice and indicate the origin
 * and nature of any modifications.
 *
 * I'd appreciate being given credit for this package in the documentation of
 * software which uses it, but that is not a requirement.
 *
 * THIS SOFTWARE IS PROVIDED ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES,
 * INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY
 * AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL
 * HENRY SPENCER BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
 * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/*
 * Headers if any.
 */

#include "regex.h"

/*
 * Overrides for regguts.h definitions, if any.
 */

#define	FUNCPTR(name, args)	(*name)args
#define	MALLOC(n)		VS(malloc(n))
#define	FREE(p)			free(VS(p))
#define	REALLOC(p,n)		VS(realloc(VS(p),n))

/*
 * Do not insert extras between the "begin" and "end" lines - this chunk is
 * automatically extracted to be fitted into regex.h.
 */

/* --- begin --- */
/* Ensure certain things don't sneak in from system headers. */
#ifdef __REG_WIDE_T
#undef __REG_WIDE_T
#endif
#ifdef __REG_RWIDE_T
#undef __REG_RWIDE_T
#endif
#ifdef __REG_WIDE_COMPILE
#undef __REG_WIDE_COMPILE
#endif
#ifdef __REG_WIDE_EXEC
#undef __REG_WIDE_EXEC
#endif
#ifdef __REG_REGOFF_T
#undef __REG_REGOFF_T
#endif
#ifdef __REG_VOID_T
#undef __REG_VOID_T
#endif
#ifdef __REG_CONST
#undef __REG_CONST
#endif
#ifdef __REG_NOFRONT
#undef __REG_NOFRONT
#endif
#ifdef __REG_NOCHAR
#undef __REG_NOCHAR
#endif
/* Interface types */
#define __REG_WIDE_T	Col_Char4
#if 1
#define __REG_RWIDE_T	Col_RopeIterator
#else
#define __REG_RWIDE_T	const Col_Char4 *
#endif
#define	__REG_REGOFF_T	intptr_t	/* Not really right, but good enough... */
#define	__REG_VOID_T	void
#define	__REG_CONST	const
/* Names and declarations */
#define	__REG_WIDE_COMPILE	CoatlReCompile
#define	__REG_WIDE_EXEC		CoatlReExec
#define	__REG_NOFRONT		/* Don't want regcomp() and regexec() */
#define	__REG_NOCHAR		/* Or the char versions */
#define	regfree		CoatlReFree
#define	regerror	CoatlReError
/* --- end --- */

/*
 * Internal character type and related.
 */

typedef Col_Char4 chr;		/* The type itself. */
typedef int pchr;		/* What it promotes to. */
typedef unsigned uchr;		/* Unsigned type that will hold a chr. */
typedef int celt;		/* Type to hold chr, or NOCELT */
#if 1
typedef Col_RopeIterator rchr;	/* Reference to chr. */
#define	RCHR_INDEX(p,start)	Col_RopeIterIndex(&(p))
#define RCHR_FWD(p,o)	Col_RopeIterForward(&(p),(o))
#define RCHR_BWD(p,o)	Col_RopeIterBackward(&(p),(o))
#define RCHR_CHR(p)	Col_RopeIterAt(&(p))
#define RCHR_CMP(p1,p2)	Col_RopeIterCompare(&(p1),&(p2))
#define RCHR_INIT(begin,end,data,len) \
    (Col_RopeIterString(COL_UCS4, (data), (len), &(begin)), (end) = (begin), Col_RopeIterForward(&(end), (len)))
#define RCHR_ISNULL(p)	Col_RopeIterNull(&(p))
#define RCHR_NULL	COL_ROPEITER_NULL
#else
typedef const chr *rchr;	/* Reference to chr. */
#define	RCHR_INDEX(p,start)	((p)-(start))
#define RCHR_FWD(p,o)	((p) += (o))
#define RCHR_BWD(p,o)	((p) -= (o))
#define RCHR_CHR(p)	(*(p))
#define RCHR_CMP(p1,p2)	(!(p1)?!(p2)?0:1:!(p2)?-1:(p1)<(p2)?-1:(p1)==(p2)?0:1)
#define RCHR_INIT(begin,end,data,len) ((begin) = (data), (end) = (begin)+(len))
#define RCHR_ISNULL(p)	((p)==NULL)
#define RCHR_NULL	NULL
#endif
#define	NOCELT (-1)		/* Celt value which is not valid chr */
#define	CHR(c) ((Col_Char)(c))	/* Turn char literal into chr literal */
#define	DIGITVAL(c) ((c)-'0')	/* Turn chr digit into its value */
#define	CHRBITS	32		/* Bits in a chr; must not use sizeof */
#define	CHR_MIN	0x00000000	/* Smallest and largest chr; the value */
#define	CHR_MAX	0x00ffffff	/* CHR_MAX-CHR_MIN+1 should fit in uchr */

/*
 * Functions operating on chr.
 */

#define	iscalnum(x)	(iscalpha(x) || iscdigit(x))
#define	iscalpha(x)	Coatl_GetUcdProperty_Alpha(x)
#define	iscdigit(x)	(Coatl_GetUcdProperty_Gc(x)==COATL_UCD_GC_DECIMAL_NUMBER)
#define	iscspace(x)	Coatl_GetUcdProperty_WSpace(x)

/*
 * Name the external functions.
 */

#define	compile		CoatlReCompile
#define	exec		CoatlReExec

/*
& Enable/disable debugging code (by whether REG_DEBUG is defined or not).
*/

#if 1//0 FIXME				/* No debug unless requested by makefile. */
#define	REG_DEBUG	/* */
#endif

/*
 * Method of allocating a local workspace. We used a thread-specific data
 * space to store this because the regular expression engine is never
 * reentered from the same thread; it doesn't make any callbacks.
 */

#if 0 //FIXME use thread-local storage
#define AllocVars(vPtr) \
    static Tcl_ThreadDataKey varsKey; \
    register struct vars *vPtr = (struct vars *) \
	    Tcl_GetThreadData(&varsKey, sizeof(struct vars))
#else
/*
 * This strategy for allocating workspace is "more proper" in some sense, but
 * quite a bit slower. Using TSD (as above) leads to code that is quite a bit
 * faster in practice (measured!)
 */
#define AllocVars(vPtr) \
    register struct vars *vPtr = (struct vars *) MALLOC(sizeof(struct vars))
#define FreeVars(vPtr) \
    FREE(vPtr)
#endif

/*
 * Local Variables:
 * mode: c
 * c-basic-offset: 4
 * fill-column: 78
 * End:
 */
