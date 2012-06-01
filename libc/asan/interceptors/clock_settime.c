#include "../asan-interceptors.h"
#include <time.h>

int clock_settime(clockid_t, const struct timespec *);
int _asan_clock_settime(clockid_t, const struct timespec *);

int
clock_settime(clockid_t clock_id, const struct timespec *tp)
{
	int ret = _asan_clock_settime(clock_id, tp);

	if(ret == 0)
		ASAN_READ_RANGE(tp, sizeof(struct timespec));

	return ret;
}
