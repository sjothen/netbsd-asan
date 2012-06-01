#include <time.h>

int _sys_nanosleep(const struct timespec *, struct timespec *);
int _asan__sys_nanosleep(const struct timespec *, struct timespec *);

int
_sys_nanosleep(const struct timespec *rqtp, struct timespec *rmtp)
{
	int ret = _asan__sys_nanosleep(rqtp, rmtp);

	if(ret != -1) {
		if(rmtp != NULL)
			ASAN_WRITE_RANGE(rmtp, sizeof(struct timespec));

		ASAN_READ_RANGE(rqtp, sizeof(struct timespec));
	}

	return ret;
}
