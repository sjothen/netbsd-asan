#include "interceptors.h"
#include <sys/time.h>

int futimes(int, const struct timeval[2]);
int _asan_futimes(int, const struct timeval[2]);

int
futimes(int fd, const struct timeval times[2])
{
	int ret = _asan_futimes(fd, times);

	if(ret == 0) {
		if(times != NULL)
			ASAN_READ_RANGE(times, 2*sizeof(struct timeval));
	}

	return ret;
}
