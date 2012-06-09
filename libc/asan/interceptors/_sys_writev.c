#include "interceptors.h"
#include <unistd.h>
#include <sys/uio.h>

ssize_t _sys_writev(int d, const struct iovec *iov, int iovcnt);
ssize_t _asan__sys_writev(int d, const struct iovec *iov, int iovcnt);

ssize_t
_sys_writev(int d, const struct iovec *iov, int iovcnt)
{
	int i;
	int ret = _asan__sys_writev(d, iov, iovcnt);

	if(ret >= 0) {
		ASAN_READ_RANGE(iov, sizeof(struct iovec));

		for(i = 0; i < iovcnt; i++) {
			ASAN_READ_RANGE(iov[i].iov_base, iov[i].iov_len);
		}
	}

	return ret;
}
