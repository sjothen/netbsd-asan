/*	$NetBSD: compat_sigpending13.S,v 1.1 2006/02/18 00:21:28 matt Exp $	*/

#include "SYS.h"

WARN_REFERENCES(sigpending, \
    "warning: reference to compatibility sigpending(); include <signal.h> for correct reference")

ENTRY(sigpending)
	mr	%r5,%r3			# save pointer
	li	%r0,SYS_compat_13_sigpending13
	sc				# sigpending()
	bso	1f
	stw	%r3,0(%r5)		# store return value
	li	%r3,0			# and return 0
	blr
1:
	b	PIC_PLT(_C_LABEL(__cerror))
