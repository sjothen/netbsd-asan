#include <unistd.h>
#include <sys/uio.h>

ssize_t _sys_readv(int, const struct iovec *, int);
ssize_t _asan__sys_readv(int, const struct iovec *, int);

ssize_t
_sys_readv(int d, const struct iovec *iov, int iovcnt)
{
	int i;
	ssize_t ret = _asan__sys_readv(d, iov, iovcnt);

	if(ret >= 0) {
		for(i = 0; i < iovcnt; i++) {
			ASAN_WRITE_RANGE(iov[i].iov_base, iov[i].iov_len);
		}
	}

	return ret;
}
