#include "interceptors.h"
#include <time.h>

int timer_gettime(timer_t, struct itimerspec *);
int _asan_timer_gettime(timer_t, struct itimerspec *);

int
timer_gettime(timer_t timerid, struct itimerspec *tim)
{
	int ret = _asan_timer_gettime(timerid, tim);

	if(ret == 0 && tim != NULL)
		ASAN_WRITE_RANGE(tim, sizeof(*tim));

	return ret;
}
