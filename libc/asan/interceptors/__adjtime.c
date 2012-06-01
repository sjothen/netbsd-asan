#include <sys/time.h>

int __adjtime(const struct timeval *, struct timeval *);
int _asan__adjtime(const struct timeval *, struct timeval *);

int
__adjtime(const struct timeval *delta, struct timeval *olddelta)
{
	int ret = _asan__adjtime(delta, olddelta);

	if(ret == 0) {
		ASAN_READ_RANGE(delta, sizeof(struct timeval));
		if(olddelta != NULL)
			ASAN_WRITE_RANGE(olddelta, sizeof(struct timeval));
	}

	return ret;
}
