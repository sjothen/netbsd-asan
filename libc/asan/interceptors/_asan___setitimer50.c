#include "interceptors.h"
#include <sys/time.h>

int __setitimer50(int, const struct itimerval * __restrict,
	struct itimerval * __restrict);
int _asan___setitimer50(int, const struct itimerval * __restrict,
	struct itimerval * __restrict);

int
__setitimer50(int which, const struct itimerval * __restrict value,
	struct itimerval * __restrict ovalue)
{
	int ret = _asan___setitimer50(which, value, ovalue);

	if(ret == 0)
		ASAN_WRITE_RANGE(ovalue, sizeof(*ovalue));

	return ret;
}
