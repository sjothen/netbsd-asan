#include "interceptors.h"
#include <time.h>
#include <signal.h>

int timer_create(clockid_t, struct sigevent * __restrict,
	timer_t * __restrict);
int _asan_timer_create(clockid_t, struct sigevent * __restrict,
	timer_t * __restrict);

int
timer_create(clockid_t clockid, struct sigevent * __restrict evp,
	timer_t * __restrict timerid)
{
	int ret = _asan_timer_create(clockid, evp, timerid);

	if(ret == 0)
		ASAN_WRITE_RANGE(timerid, sizeof(timer_t));

	return ret;
}
