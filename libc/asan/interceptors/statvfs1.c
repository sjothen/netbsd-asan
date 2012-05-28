#include <sys/statvfs.h>

int statvfs1(const char *, struct statvfs *, int);
int _asan_statvfs1(const char *, struct statvfs *, int);

int
statvfs1(const char *path, struct statvfs *buf, int flags)
{
	int ret = _asan_statvfs1(path, buf, flags);

	if(ret == 0)
		ASAN_WRITE_RANGE(buf, sizeof(struct statvfs));

	return ret;
}
