#include "../asan-interceptors.h"
#include <sys/stat.h>

int mknod(const char *, mode_t, dev_t);
int _asan_mknod(const char *, mode_t, dev_t);

int
mknod(const char *path, mode_t mode, dev_t dev)
{
	int ret = _asan_mknod(path, mode, dev);

	if(ret == 0) {
		touch_mem(path);
	}

	return ret;
}
