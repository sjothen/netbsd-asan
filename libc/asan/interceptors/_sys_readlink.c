#include <unistd.h>

ssize_t _sys_readlink(const char * restrict, char * restrict, size_t);
ssize_t _asan_sys_readlink(const char * restrict, char * restrict, size_t);

ssize_t
_sys_readlink(const char * restrict path, char * restrict buf,
	size_t bufsiz);
{
	ssize_t ret = _asan_sys_readlink(path, buf, bufsiz);
	
	if(ret >= 0)
		ASAN_WRITE_RANGE(buf, ret);

	return ret;
}
