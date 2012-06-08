#include "interceptors.h"
#include <fcntl.h>

int _sys_open(const char *path, int flags, mode_t mode);
int _asan__sys_open(const char *path, int flags, ...);

int
_sys_open(const char *path, int flags, mode_t mode)
{
	int ret = _asan__sys_open(path, flags, mode);

	touch_mem(path);

	return ret;
}
