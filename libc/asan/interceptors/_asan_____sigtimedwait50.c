#include "interceptors.h"
#include <signal.h>
#include <time.h>

int ____sigtimedwait50(const sigset_t *, siginfo_t *,
		struct timespec *);
int _asan_____sigtimedwait50(const sigset_t *, siginfo_t *,
		struct timespec *);

int
____sigtimedwait50(const sigset_t *set, siginfo_t *info,
		struct timespec *timeout)
{
	int ret = _asan_____sigtimedwait50(set, info, timeout);

	if(ret == 0) {
		ASAN_WRITE_RANGE(info, sizeof(siginfo_t));
		ASAN_WRITE_RANGE(timeout, sizeof(struct timespec));
		
		if(timeout != NULL)
			ASAN_READ_RANGE(timeout, sizeof(struct timespec));
	}

	return ret;
}
