#include "interceptors.h"
#include <unistd.h>

ssize_t _sys_readlink(const char * __restrict, char * __restrict, size_t);
ssize_t _asan__sys_readlink(const char * __restrict, char * __restrict, size_t);

ssize_t
_sys_readlink(const char * __restrict path, char * __restrict buf,
	size_t bufsiz)
{
	ssize_t ret = _asan__sys_readlink(path, buf, bufsiz);
	
	if(ret >= 0) {
		ASAN_WRITE_RANGE(buf, ret);
	}

	return ret;
}
