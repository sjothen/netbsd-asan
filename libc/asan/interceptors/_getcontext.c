#include <sys/ucontext.h>

int _getcontext(struct __ucontext *);
int _asan_getcontext(struct __ucontext *);

int
_getcontext(struct __ucontext *ucp)
{
	int ret = _asan_getcontext(ucp);

	if(ret == 0)
		ASAN_WRITE_RANGE(ucp, sizeof(struct __ucontext));

	return ret;
}
