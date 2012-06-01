#include "../asan-interceptors.h"
#include <lwp.h>

ssize_t _lwp_unpark_all(const lwpid_t *, size_t,
		const void *);
ssize_t _asan_lwp_unpark_all(const lwpid_t *, size_t,
		const void *);

ssize_t
_lwp_unpark_all(const lwpid_t *targets, size_t ntargets,
		const void *hint)
{
	int ret = _asan_lwp_unpark_all(targets, ntargets, hint);

	if(ret == 0)
		ASAN_READ_RANGE(targets, ntargets*sizeof(lwpid_t));

	return ret;
}
