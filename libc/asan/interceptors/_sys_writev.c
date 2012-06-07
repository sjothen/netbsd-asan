#include "interceptors.h"
#include <unistd.h>
#include <sys/uio.h>

ssize_t _sys_writev(int d, const struct iovec *iov, int iovcnt);
ssize_t _asan__sys_writev(int d, const struct iovec *iov, int iovcnt);

ssize_t
_sys_writev(int d, const struct iovec *iov, int iovcnt)
{
	int ret = _asan__sys_writev(d, iov, iovcnt);

	if(ret >= 0) {
	}

	return ret;
}
