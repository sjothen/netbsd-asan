#include "interceptors.h"
#include <time.h>

int clock_getres(clockid_t, struct timespec *);
int _asan_clock_gettime(clockid_t, struct timespec *);

int
clock_getres(clockid_t clock_id, struct timespec *res)
{
	int ret = _asan_clock_getres(clock_id, res);

	if(ret == 0)
		ASAN_WRITE_RANGE(res, sizeof(struct timespec));

	return ret;
}
