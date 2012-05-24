/*	$NetBSD: compat___stat13.c,v 1.3 2006/07/31 16:34:42 martin Exp $	*/

/*
 * Copyright (c) 1997 Frank van der Linden
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. All advertising materials mentioning features or use of this software
 *    must display the following acknowledgement:
 *      This product includes software developed for the NetBSD Project
 *      by Frank van der Linden
 * 4. The name of the author may not be used to endorse or promote products
 *    derived from this software without specific prior written permission
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
 * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <sys/cdefs.h>
#if defined(LIBC_SCCS) && !defined(lint)
__RCSID("$NetBSD: compat___stat13.c,v 1.3 2006/07/31 16:34:42 martin Exp $");
#endif /* LIBC_SCCS and not lint */

#define __LIBC12_SOURCE__

#include <sys/types.h>
#include <sys/param.h>
#include <sys/stat.h>
#include <sys/mount.h>
#include <compat/sys/stat.h>
#include <compat/sys/mount.h>

__warn_references(__stat13,
    "warning: reference to compatibility __stat13(); include <sys/stat.h> to generate correct reference")

__warn_references(__fstat13,
    "warning: reference to compatibility __fstat13(); include <sys/stat.h> to generate correct reference")

__warn_references(__lstat13,
    "warning: reference to compatibility __lstat13(); include <sys/stat.h> to generate correct reference")

__warn_references(fhstat,
    "warning: reference to compatibility fhstat(); include <sys/mount.h> to generate correct reference")


/*
 * Convert from a new to an old stat structure.
 */

static void cvtstat(struct stat13 *, const struct stat *);

static void
cvtstat(struct stat13 *ost, const struct stat *st)
{

	ost->st_dev = st->st_dev;
	ost->st_ino = (uint32_t)st->st_ino;
	ost->st_mode = st->st_mode;
	ost->st_nlink = st->st_nlink;
	ost->st_uid = st->st_uid;
	ost->st_gid = st->st_gid;
	ost->st_rdev = st->st_rdev;
	ost->st_atimespec = st->st_atimespec;
	ost->st_mtimespec = st->st_mtimespec;
	ost->st_ctimespec = st->st_ctimespec;
	ost->st_birthtimespec = st->st_birthtimespec;
	ost->st_size = st->st_size;
	ost->st_blocks = st->st_blocks;
	ost->st_blksize = st->st_blksize;
	ost->st_flags = st->st_flags;
	ost->st_gen = st->st_gen;
}

int
__stat13(const char *file, struct stat13 *ost)
{
	struct stat nst;
	int ret;

	if ((ret = __stat30(file, &nst)) == -1)
		return ret;
	cvtstat(ost, &nst);
	return ret;
}

int
__fstat13(int f, struct stat13 *ost)
{
	struct stat nst;
	int ret;

	if ((ret = __fstat30(f, &nst)) == -1)
		return ret;
	cvtstat(ost, &nst);
	return ret;
}

int
__lstat13(const char *file, struct stat13 *ost)
{
	struct stat nst;
	int ret;

	if ((ret = __lstat30(file, &nst)) == -1)
		return ret;
	cvtstat(ost, &nst);
	return ret;
}

int
fhstat(const struct compat_30_fhandle *fh, struct stat13 *ost)
{
	struct stat nst;
	int ret;

	if ((ret = __fhstat30(fh, &nst)) == -1)
		return ret;
	cvtstat(ost, &nst);
	return ret;
}
