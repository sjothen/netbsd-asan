#include "interceptors.h"
#include <sys/module.h>
#include <sys/uio.h>

int modctl(int, void *);
int _asan_modctl(int, void *);

int
modctl(int cmd, void *arg)
{
	int ret = _asan_modctl(cmd, arg);

	if(ret == 0 && cmd == MODCTL_STAT) {
		struct iovec *iov = arg;
		ASAN_WRITE_RANGE(iov, sizeof(*iov));
		ASAN_WRITE_RANGE(iov->iov_base, iov->iov_len);
	}

	return ret;
}
