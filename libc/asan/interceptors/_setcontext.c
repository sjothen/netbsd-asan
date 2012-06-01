#include "../asan-interceptors.h"
#include <sys/ucontext.h>

int _setcontext(struct __ucontext *);
int _asan__setcontext(struct __ucontext *);

int
_setcontext(struct __ucontext *ucp)
{
	int ret = _asan__setcontext(ucp);

	if(ret == 0)
		ASAN_READ_RANGE(ucp, sizeof(struct __ucontext));

	return ret;
}
