#include "interceptors.h"
#include <lwp.h>

int _lwp_create(const ucontext_t *, unsigned long, lwpid_t *);
int _asan__lwp_create(const ucontext_t *, unsigned long, lwpid_t *);

int
_lwp_create(const ucontext_t *context, unsigned long flags, lwpid_t *new_lwp)
{
	int ret = _asan__lwp_create(context, flags, new_lwp);

	if(ret == 0) {
		ASAN_WRITE_RANGE(new_lwp, sizeof(lwpid_t));
		ASAN_READ_RANGE(context, sizeof(ucontext_t));
	}

	return ret;
}
