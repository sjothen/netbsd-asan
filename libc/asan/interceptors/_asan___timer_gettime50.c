#include "interceptors.h"
#include <time.h>

int __timer_gettime50(timer_t, struct itimerspec *);
int _asan___timer_gettime50(timer_t, struct itimerspec *);

int
__timer_gettime50(timer_t timerid, struct itimerspec *tim)
{
	int ret = _asan___timer_gettime50(timerid, tim);

	if(ret == 0 && tim != NULL)
		ASAN_WRITE_RANGE(tim, sizeof(*tim));

	return ret;
}
