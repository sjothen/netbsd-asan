#include "interceptors.h"
#include <unistd.h>

ssize_t _sys_write(int, const void *, size_t);
ssize_t _asan__sys_write(int, const void *, size_t);

ssize_t
_sys_write(int fd, const void *buf, size_t nbyte)
{
	int ret = _asan__sys_write(fd, buf, nbyte);

	if(ret >= 0)
		ASAN_READ_RANGE(buf, ret);

	return ret;
}
