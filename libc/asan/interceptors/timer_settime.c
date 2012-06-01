#include <time.h>

int timer_settime(timer_t, int,
	const struct itimerspec * __restrict,
	struct itimerspec * __restrict);
int _asan_timer_settime(timer_t, int,
	const struct itimerspec * __restrict,
	struct itimerspec * __restrict);

int
timer_settime(timer_t timerid, int flags,
	const struct itimerspec * __restrict tim,
	struct itimerspec * __restrict otim)
{
	int ret = _asan_timer_settime(timerid, flags, tim, otim);

	if(ret == 0) {
		if(otim != NULL)
			ASAN_WRITE_RANGE(otim, sizeof(struct itimerspec));

		ASAN_READ_RANGE(tim, sizeof(struct itimerspec));
	}

	return ret;
}
