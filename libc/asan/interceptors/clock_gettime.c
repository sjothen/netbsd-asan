#include <time.h>

int clock_gettime(clockid_t, struct timespec *);
int _asan_clock_gettime(clockid_t, struct timespec *);

int
clock_gettime(clockid_t clock_id, struct timespec *tp)
{
	int ret = _asan_clock_gettime(clock_id, tp);

	if(ret == 0)
		ASAN_WRITE_RANGE(tp, sizeof(struct timespec));

	return ret;
}
