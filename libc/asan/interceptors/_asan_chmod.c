#include "interceptors.h"
#include <sys/stat.h>

int chmod(const char *, mode_t);
int _asan_chmod(const char *, mode_t);

int
chmod(const char *path, mode_t mode)
{
	int ret = _asan_chmod(path, mode);

	if(ret == 0) {
		touch_mem(path);
	}

	return ret;
}
