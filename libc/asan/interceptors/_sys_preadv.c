#include <unistd.h>
#include <sys/uio.h>

ssize_t _sys_preadv(int, const struct iovec *, int, off_t);
ssize_t _asan_sys_preadv(int, const struct iovec *, int, off_t);

ssize_t
_sys_preadv(int d, const struct iovec *iov, int iovcnt, off_t offset)
{
	int i;
	ssize_t ret = _asan_sys_preadv(d, iov, iovcnt, offset);

	if(ret >= 0) {
		for(i = 0; i < iovcnt; i++) {
			ASAN_WRITE_RANGE(iov[i].iov_base, iov[i].iov_len);
		}
	}

	return ret;
}
