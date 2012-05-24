#include <unistd.h>

ssize_t _sys_read(int, void *, size_t);
ssize_t _asan_sys_read(int, void *, size_t);

ssize_t
_sys_read(int fd, void *buf, size_t nread)
{
	ssize_t ret = _asan_sys_read(fd, buf, nread);
	
	if(ret >= 0)
		ASAN_WRITE_RANGE(buf, ret);

	return ret;
}
