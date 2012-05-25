#include <time.h>

int timer_settime(timer_t, int,
	const struct itimerspec * restrict,
	struct itimerspec * restrict);
int _asan_timer_settime(timer_t, int,
	const struct itimerspec * restrict,
	struct itimerspec * restrict);

int
timer_settime(timer_t timerid, int flags,
	const struct itimerspec * restrict tim,
	struct itimerspec * restrict otim)
{
	int ret = _asan_timer_settime(timerid, flags, tim, otim);

	if(ret == 0 && otim != NULL)
		ASAN_WRITE_RANGE(otim, sizeof(*otim));

	return ret;
}
