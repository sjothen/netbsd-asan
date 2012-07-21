#include "interceptors.h"
#include <sys/time.h>

int __gettimeofday50(struct timeval * __restrict, void * __restrict);
int _asan___gettimeofday50(struct timeval * __restrict, void * __restrict);

int
__gettimeofday50(struct timeval * __restrict tp, void * __restrict tzp)
{
	int ret = _asan___gettimeofday50(tp, tzp);

	if(ret == 0) {
		if(tp != NULL)
			ASAN_WRITE_RANGE(tp, sizeof(*tp));

		if(tzp != NULL)
			ASAN_WRITE_RANGE(tzp, sizeof(struct timezone));
	}

	return ret;
}
