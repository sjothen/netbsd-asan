#include <sys/time.h>
#include <string.h>

int utimes(const char *, const struct timeval[2]);
int _asan_utimes(const char *, const struct timeval[2]);

int
utimes(const char *path, const struct timeval times[2])
{
	int ret = _asan_utimes(path, times);

	if(ret == 0) {
		size_t sz = strlen(path);
		ASAN_READ_RANGE(path, sz+1);

		if(times != NULL)
			ASAN_READ_RANGE(times, 2*sizeof(struct timeval));
	}

	return ret;
}
