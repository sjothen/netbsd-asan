#include "interceptors.h"
#include <sys/time.h>

int __futimes50(int, const struct timeval[2]);
int _asan___futimes50(int, const struct timeval[2]);

int
__futimes50(int fd, const struct timeval times[2])
{
	int ret = _asan___futimes50(fd, times);

	if(ret == 0) {
		if(times != NULL)
			ASAN_READ_RANGE(times, 2*sizeof(struct timeval));
	}

	return ret;
}
