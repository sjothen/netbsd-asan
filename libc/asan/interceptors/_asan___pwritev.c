#include "interceptors.h"
#include <unistd.h>
#include <sys/uio.h>

ssize_t __pwritev(int, const struct iovec *, int, off_t);
ssize_t _asan___pwritev(int, const struct iovec *, int, off_t);

ssize_t
__pwritev(int d, const struct iovec *iov, int iovcnt, off_t offset)
{
	int i;
	int ret = _asan___pwritev(d, iov, iovcnt, offset);

	if(ret >= 0) {
		ASAN_READ_RANGE(iov, sizeof(struct iovec));

		for(i = 0; i < iovcnt; i++) {
			ASAN_READ_RANGE(iov[i].iov_base, iov[i].iov_len);
		}
	}

	return ret;
}
