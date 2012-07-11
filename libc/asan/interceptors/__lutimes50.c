#include "interceptors.h"
#include <sys/time.h>

int __lutimes50(const char *, const struct timeval[2]);
int _asan___lutimes50(const char *, const struct timeval[2]);

int
__lutimes50(const char *path, const struct timeval times[2])
{
	int ret = _asan___lutimes50(path, times);

	if(ret == 0) {
		touch_mem(path);

		if(times != NULL)
			ASAN_READ_RANGE(times, 2*sizeof(struct timeval));
	}

	return ret;
}
