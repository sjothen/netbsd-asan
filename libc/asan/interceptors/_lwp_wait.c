#include <lwp.h>

int _lwp_wait(lwpid_t wlwp, lwpid_t *rlwp);
int _asan_lwp_wait(lwpid_t wlwp, lwpid_t *rlwp);

int
_lwp_wait(lwpid_t wlwp, lwpid_t *rlwp)
{
	int ret = _asan_lwp_wait(wlwp, rlwp);

	if(ret == 0) {
		if(rlwp != NULL)
			ASAN_WRITE_RANGE(rlwp, sizeof(lwpid_t));
	}

	return ret;
}
