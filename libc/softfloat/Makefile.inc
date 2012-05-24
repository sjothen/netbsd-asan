#	$NetBSD: Makefile.inc,v 1.4 2004/09/26 21:13:27 jmmv Exp $

SOFTFLOAT_BITS?=64
.PATH:		${ARCHDIR}/softfloat \
		${.CURDIR}/softfloat/bits${SOFTFLOAT_BITS} ${.CURDIR}/softfloat

CPPFLAGS+=	-I${ARCHDIR}/softfloat -I${.CURDIR}/softfloat
CPPFLAGS+=	-DSOFTFLOAT_FOR_GCC

SRCS+=		softfloat.c

SRCS+=		fpgetround.c fpsetround.c fpgetmask.c fpsetmask.c \
		fpgetsticky.c fpsetsticky.c

SRCS+=		eqsf2.c nesf2.c gtsf2.c gesf2.c ltsf2.c lesf2.c negsf2.c \
		eqdf2.c nedf2.c gtdf2.c gedf2.c ltdf2.c ledf2.c negdf2.c \
		nexf2.c gtxf2.c gexf2.c negxf2.c unordsf2.c unorddf2.c
