#include "interceptors.h"
#include <lwp.h>

int _lwp_park(const struct timespec *, lwpid_t, const void *, const void *);
int _asan__lwp_park(const struct timespec *, lwpid_t, const void *, const void *);

int
_lwp_park(const struct timespec *ts, lwpid_t unpark,
		const void *hint, const void *unparkhint)
{
	int ret = _asan__lwp_park(ts, unpark, hint, unparkhint);

	if(ret == 0)
		ASAN_READ_RANGE(ts, sizeof(struct timespec));

	return ret;
}
