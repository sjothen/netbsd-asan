#include "interceptors.h"
#include <lwp.h>

int ___lwp_park50(const struct timespec *, lwpid_t, const void *, const void *);
int _asan____lwp_park50(const struct timespec *, lwpid_t, const void *, const void *);

int
___lwp_park50(const struct timespec *ts, lwpid_t unpark,
		const void *hint, const void *unparkhint)
{
	int ret = _asan____lwp_park50(ts, unpark, hint, unparkhint);

	if(ret == 0)
		ASAN_READ_RANGE(ts, sizeof(struct timespec));

	return ret;
}
