#include "interceptors.h"
#include <sys/time.h>

int setitimer(int, const struct itimerval * __restrict,
	struct itimerval * __restrict);
int _asan_setitimer(int, const struct itimerval * __restrict,
	struct itimerval * __restrict);

int
setitimer(int which, const struct itimerval * __restrict value,
	struct itimerval * __restrict ovalue)
{
	int ret = _asan_setitimer(which, value, ovalue);

	if(ret == 0)
		ASAN_WRITE_RANGE(ovalue, sizeof(*ovalue));

	return ret;
}
