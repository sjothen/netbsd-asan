#include <sys/param.h>
#include <sys/mount.h>

int unmount(const char *, int);
int _asan_unmount(const char *, int);

int
unmount(const char *path, int flags)
{
	int ret = _asan_unmount(path, flags);

	if(ret == 0) {
		size_t sz = strlen(path);
		ASAN_READ_RANGE(path, sz+1);
	}

	return ret;
}
