#include "interceptors.h"
#include <sys/ucontext.h>

int _getcontext(struct __ucontext *);
int _asan__getcontext(struct __ucontext *);

int
_getcontext(struct __ucontext *ucp)
{
	int ret = _asan__getcontext(ucp);

	if(ret == 0)
		ASAN_WRITE_RANGE(ucp, sizeof(struct __ucontext));

	return ret;
}
