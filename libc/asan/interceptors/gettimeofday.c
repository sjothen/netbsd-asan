#include "interceptors.h"
#include <sys/time.h>

int gettimeofday(struct timeval * __restrict, void * __restrict);
int _asan_gettimeofday(struct timeval * __restrict, void * __restrict);

int
gettimeofday(struct timeval * __restrict tp, void * __restrict tzp)
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
