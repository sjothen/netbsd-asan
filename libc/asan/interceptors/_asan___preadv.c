#include "interceptors.h"
#include <unistd.h>
#include <sys/uio.h>

ssize_t __preadv(int, const struct iovec *, int, off_t);
ssize_t _asan___preadv(int, const struct iovec *, int, off_t);

ssize_t
__preadv(int d, const struct iovec *iov, int iovcnt, off_t offset)
{
	int i;
	ssize_t ret = _asan___preadv(d, iov, iovcnt, offset);

	if(ret >= 0) {
		ASAN_READ_RANGE(iov, sizeof(struct iovec));

		for(i = 0; i < iovcnt; i++) {
			ASAN_WRITE_RANGE(iov[i].iov_base, iov[i].iov_len);
		}
	}

	return ret;
}
