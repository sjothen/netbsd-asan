#include "interceptors.h"
#include <lwp.h>

int _lwp_getname(lwpid_t, char *, size_t);
int _asan__lwp_getname(lwpid_t, char *, size_t);

int
_lwp_getname(lwpid_t target, char *name, size_t len)
{
	int ret = _asan__lwp_getname(target, name, len);

	if(ret == 0)
		ASAN_WRITE_RANGE(name, len);

	return ret;
}
