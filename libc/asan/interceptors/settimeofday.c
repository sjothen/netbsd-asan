#include <sys/time.h>

int settimeofday(const struct timeval *, const void *);
int _asan_settimeofday(const struct timeval *, const void *);

int
settimeofday(const struct timeval *tv, const void *tzp)
{
	int ret = _asan_settimeofday(tv, tzp);

	if(ret == 0) {
		if(tv != NULL)
			ASAN_READ_RANGE(tv, sizeof(struct timeval));

		if(tzp != NULL)
			ASAN_READ_RANGE(tzp, sizeof(struct timezone));
	}

	return ret;
}
