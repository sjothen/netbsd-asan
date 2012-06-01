#include "../asan-interceptors.h"
#include <lwp.h>

int _lwp_setname(lwpid_t, const char *);
int _asan_lwp_setname(lwpid_t, const char *);

int
_lwp_setname(lwpid_t target, const char *name)
{
	int ret = _asan_lwp_setname(target, name);

	touch_mem(name);

	return ret;
}
