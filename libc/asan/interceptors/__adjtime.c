#include <sys/time.h>

int __adjtime(const struct timeval *, struct timeval *);
int _asan___adjtime(const struct timeval *, struct timeval *);

int
__adjtime(const struct timeval *delta, struct timeval *olddelta)
{
	int ret = _asan___adjtime(delta, olddelta);

	if(ret == 0) {
		ASAN_READ_RANGE(delta, sizeof(struct timeval));
		if(olddelta != NULL)
			ASAN_WRITE_RANGE(olddelta, sizeof(struct timeval));
	}

	return ret;
}
