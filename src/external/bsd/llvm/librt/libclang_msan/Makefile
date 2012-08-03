#	$NetBSD: Makefile,v 1.1 2012/06/17 18:48:47 joerg Exp $

LIB=		clang_msan
USE_SHLIBDIR=	yes
#WARNS=		4
CWARNFLAGS+=	-Wno-missing-noreturn

.include <bsd.init.mk>

LDFLAGS+=	-nodefaultlibs

.PATH: ${COMPILER_RT_SRCDIR}/lib/interception

SRCS+=		interception_linux.cc

.PATH: ${COMPILER_RT_SRCDIR}/lib/msan

SRCS+=		msan.cc msan_interceptors.cc

.PATH: ${COMPILER_RT_SRCDIR}/lib/sanitizer_common

SRCS+=		sanitizer_allocator.cc sanitizer_common.cc \
		sanitizer_libc.cc \
		sanitizer_posix.cc sanitizer_printf.cc sanitizer_symbolizer.cc \
		sanitizer_netbsd.cc

CPPFLAGS+=-I${COMPILER_RT_SRCDIR}/lib
CPPFLAGS+=-I${COMPILER_RT_SRCDIR}/lib/sanitizer_common

.include <bsd.lib.mk>
