#include "interceptors.h"
#include <sys/stat.h>

int __lstat30(const char *, struct stat *);
int _asan___lstat30(const char *, struct stat *);

int
__lstat30(const char *path, struct stat *sb)
{
	int ret = _asan___lstat30(path, sb);

	if(ret == 0) {
		touch_mem(path);
		ASAN_WRITE_RANGE(sb, sizeof(struct stat));
	}

	return ret;
}
