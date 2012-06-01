#include <lwp.h>

int _lwp_ctl(int, struct lwpctl **);
int _asan__lwp_ctl(int, struct lwpctl **);

int
_lwp_ctl(int features, struct lwpctl **address)
{
	int ret = _asan__lwp_ctl(features, address);

	if(ret == 0)
		ASAN_WRITE_RANGE(address, sizeof(void *));

	return ret;
}
