#include "interceptors.h"
#include <sys/statvfs.h>

int fstatvfs1(int, struct statvfs *, int);
int _asan_fstatvfs1(int, struct statvfs *, int);

int
fstatvfs1(int fd, struct statvfs *buf, int flags)
{
	int ret = _asan_fstatvfs1(fd, buf, flags);

	if(ret == 0)
		ASAN_WRITE_RANGE(buf, sizeof(struct statvfs));

	return ret;
}
