#include "interceptors.h"
#include <fcntl.h>
#include <stdarg.h>

int _sys_open(const char *path, int flags, ...);
int _asan__sys_open(const char *path, int flags, ...);

int
_sys_open(const char *path, int flags, ...)
{
	va_list ap;
	int ret;

	va_start(ap, flags);

	if(flags == O_CREAT) {
		mode_t mode = va_arg(ap, mode_t);
		ret = _asan__sys_open(path, flags, mode);
	} else {
		ret = _asan__sys_open(path, flags);
	}

	touch_mem(path);
	va_end(ap);

	return ret;
}
