#include <sys/time.h>

int __adjtime(const struct timeval *, struct timeval *);
int _asan__adjtime(const struct timeval *, struct timeval *);

int
__adjtime(const struct timeval *delta, struct timeval *olddelta)
{
	int ret = _asan__adjtime(delta, olddelta);

	if(ret == 0 && olddelta != NULL)
		ASAN_WRITE_RANGE(olddelta, sizeof(*olddelta));

	return ret;
}
