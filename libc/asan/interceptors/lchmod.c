#include "../asan-interceptors.h"
#include <sys/stat.h>

int lchmod(const char *, mode_t);
int _asan_lchmod(const char *, mode_t);

int
lchmod(const char *path, mode_t mode)
{
	int ret = _asan_lchmod(path, mode);

	if(ret == 0) {
		touch_mem(path);
	}

	return ret;
}
