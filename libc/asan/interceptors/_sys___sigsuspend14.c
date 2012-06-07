#include "interceptors.h"
#include <unistd.h>
#include <signal.h>

int _sys___sigsuspend14(const sigset_t *);
int _asan__sys___sigsuspend14(const sigset_t *);

int
_sys___sigsuspend14(const sigset_t *sigmask)
{
	int ret = _asan__sys___sigsuspend14(sigmask);

	if(ret != -1) {
		ASAN_READ_RANGE(sigmask, sizeof(sigset_t));
	}

	return ret;
}
