#include "../asan-interceptors.h"
#include <sys/time.h>

int lutimes(const char *, const struct timeval[2]);
int _asan_lutimes(const char *, const struct timeval[2]);

int
lutimes(const char *path, const struct timeval times[2])
{
	int ret = _asan_lutimes(path, times);

	if(ret == 0) {
		touch_mem(path);

		if(times != NULL)
			ASAN_READ_RANGE(times, 2*sizeof(struct timeval));
	}

	return ret;
}
