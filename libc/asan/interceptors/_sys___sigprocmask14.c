#include <signal.h>

int _sys___sigprocmask14(int, const sigset_t *,
		sigset_t *);
int _asan_sys___sigprocmask14(int, const sigset_t *,
		sigset_t *);

int
_sys___sigprocmask14(int how, const sigset_t *set,
		sigset_t *oset)
{
	int ret = _asan_sys___sigprocmask14(how, set, oset);

	if(ret == 0) {
		if(oset != NULL)
			ASAN_WRITE_RANGE(oset, sizeof(sigset_t));
	}

	return ret;
}
