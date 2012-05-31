#include "../asan-interceptors.h"
#include <sys/stat.h>

int mkfifo(const char *, mode_t);
int _asan_mkfifo(const char *, mode_t);

int
mkfifo(const char *path, mode_t mode)
{
	int ret = _asan_mkfifo(path, mode);

	if(ret == 0) {
		touch_mem(path);
	}

	return ret;
}
