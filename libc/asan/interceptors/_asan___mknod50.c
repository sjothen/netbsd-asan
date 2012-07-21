#include "interceptors.h"
#include <sys/stat.h>

int __mknod50(const char *, mode_t, dev_t);
int _asan___mknod50(const char *, mode_t, dev_t);

int
__mknod50(const char *path, mode_t mode, dev_t dev)
{
	int ret = _asan___mknod50(path, mode, dev);

	if(ret == 0) {
		touch_mem(path);
	}

	return ret;
}
