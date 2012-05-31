#include "../asan-interceptors.h"
#include <sys/stat.h>

int mkdir(const char *, mode_t);
int _asan_mkdir(const char *, mode_t);

int
mkdir(const char *path, mode_t mode)
{
	int ret = _asan_mkdir(path, mode);

	if(ret == 0) {
		touch_mem(path);
	}

	return ret;
}
