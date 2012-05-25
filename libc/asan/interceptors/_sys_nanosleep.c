#include <time.h>

int _sys_nanosleep(const struct timespec *, struct timespec *);
int _asan_sys_nanosleep(const struct timespec *, struct timespec *);

int
_sys_nanosleep(const struct timespec *rqtp, struct timespec *rmtp)
{
	int ret = _asan_sys_nanosleep(rqtp, rmtp);

	if(ret != -1 && rmtp != NULL)
		ASAN_WRITE_RANGE(rmtp, sizeof(struct timespec));

	return ret;
}
