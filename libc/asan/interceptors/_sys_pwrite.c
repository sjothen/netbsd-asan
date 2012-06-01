#include <unistd.h>

ssize_t _sys_pwrite(int, const void *, size_t,
		int, off_t);
ssize_t _asan_sys_pwrite(int, const void *, size_t,
		int, off_t);

ssize_t
_sys_pwrite(int fd, const void *buf, size_t nbyte,
		int pad, off_t offset)
{
	ssize_t ret = _asan_sys_pwrite(fd, buf, nbyte, pad, offset);

	if(ret >= 0)
		ASAN_READ_RANGE(buf, nbyte);

	return ret;
}
