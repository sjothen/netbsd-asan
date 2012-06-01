#include <signal.h>

int __sigtimedwait(const sigset_t *, siginfo_t *,
		struct timespec *);
int _asan___sigtimedwait(const sigset_t *, siginfo_t *,
		struct timespec *);

int
__sigtimedwait(const sigset_t *set, siginfo_t *info,
		struct timespec *timeout)
{
	int ret = _asan___sigtimedwait(set, info, timeout);

	if(ret == 0) {
		ASAN_WRITE_RANGE(info, sizeof(siginfo_t));
		ASAN_WRITE_RANGE(timeout, sizeof(struct timespec));
	}

	return ret;
}
