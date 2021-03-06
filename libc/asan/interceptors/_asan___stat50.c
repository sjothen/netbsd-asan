#include "interceptors.h"
#include <sys/stat.h>

int __stat50(const char *, struct stat *);
int _asan___stat50(const char *, struct stat *);

int
__stat50(const char *path, struct stat *ub)
{
	int ret = _asan___stat50(path, ub);

	if(ret == 0) {
		touch_mem(path);
		ASAN_WRITE_RANGE(ub, sizeof(struct stat));
	}

	return ret;
}
