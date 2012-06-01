#include "../asan-interceptors.h"
#include <sys/signal.h>

int __sigaction_sigtramp(int, const struct sigaction *,
		struct sigaction *, const void *, int);
int _asan__sigaction_sigtramp(int, const struct sigaction *,
		struct sigaction *, const void *, int);

int
__sigaction_sigtramp(int signum, const struct sigaction *nsa,
		struct sigaction *osa, const void *tramp, int vers)
{
	int ret = _asan__sigaction_sigtramp(signum, nsa, osa,
			tramp, vers);

	if(ret == 0) {
		ASAN_READ_RANGE(nsa, sizeof(struct sigaction));
		if(osa != NULL)
			ASAN_WRITE_RANGE(osa, sizeof(struct sigaction));
	}

	return ret;
}
