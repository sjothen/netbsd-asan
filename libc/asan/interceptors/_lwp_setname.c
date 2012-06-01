#include "../asan-interceptors.h"
#include <lwp.h>

int _lwp_setname(lwpid_t, const char *);
int _asan__lwp_setname(lwpid_t, const char *);

int
_lwp_setname(lwpid_t target, const char *name)
{
	int ret = _asan__lwp_setname(target, name);

	touch_mem(name);

	return ret;
}
