#include "interceptors.h"
#include <sys/time.h>

int __utimes50(const char *, const struct timeval[2]);
int _asan___utimes50(const char *, const struct timeval[2]);

int
__utimes50(const char *path, const struct timeval times[2])
{
	int ret = _asan___utimes50(path, times);

	if(ret == 0) {
		touch_mem(path);

		if(times != NULL)
			ASAN_READ_RANGE(times, 2*sizeof(struct timeval));
	}

	return ret;
}
