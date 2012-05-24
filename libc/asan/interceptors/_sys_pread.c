#include <unistd.h>

ssize_t _sys_pread(int, void *, size_t, off_t);
ssize_t _asan_sys_pread(int, void *, size_t, off_t);

ssize_t
_sys_pread(int fd, void *buf, size_t nread, off_t offset)
{
	ssize_t ret = _asan_sys_pread(fd, buf, nread, offset);
	
	if(ret >= 0)
		ASAN_WRITE_RANGE(buf, ret);

	return ret;
}
