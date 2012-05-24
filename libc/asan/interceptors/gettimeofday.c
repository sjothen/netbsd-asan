#include <sys/time.h>

int gettimeofday(struct timeval * restrict, void * restrict);
int _asan_gettimeofday(struct timeval * restrict, void * restrict);

int
gettimeofday(struct timeval * restrict tp, void * restrict tzp)
{
	int ret = _asan_gettimeofday(tp, tzp);

	if(ret == 0) {
		if(tp != NULL)
			ASAN_WRITE_RANGE(tp, sizeof(*tp));
		if(tzp != NULL)
			ASAN_WRITE_RANGE(tzp, sizeof(*tzp));
	}

	return ret;
}
