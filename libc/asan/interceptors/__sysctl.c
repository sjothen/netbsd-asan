#include "../asan-interceptors.h"
#include <sys/sysctl.h>
#include <errno.h>

int __sysctl(const int *, u_int, void *,
		size_t *, const void *, size_t);
int _asan__sysctl(const int *, u_int, void *,
		size_t *, const void *, size_t);

int
__sysctl(const int *name, u_int namelen, void *old,
		size_t *oldlenp, const void *new, size_t newlen)
{
	int ret = _asan__sysctl(name, namelen, old, oldlenp,
			new, newlen);

	touch_mem(name);

	if(ret == 0 || (ret == -1 && errno == ENOMEM)) {
		if(old != NULL)
			ASAN_WRITE_RANGE(old, *oldlenp);

		ASAN_WRITE_RANGE(oldlenp, sizeof(size_t));

		if(new != NULL)
			ASAN_READ_RANGE(new, newlen);
	}

	return ret;
}
