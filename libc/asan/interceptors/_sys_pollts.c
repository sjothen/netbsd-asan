#include <sys/poll.h>
#include <sys/signal.h>
#include <sys/time.h>

int _sys_pollts(struct pollfd * __restrict, nfds_t,
		const struct timespec * __restrict,
		const sigset_t * __restrict);
int _asan__sys_pollts(struct pollfd * __restrict, nfds_t,
		const struct timespec * __restrict,
		const sigset_t * __restrict);

int
_sys_pollts(struct pollfd * __restrict fds, nfds_t nfds,
		const struct timespec * __restrict ts,
		const sigset_t * __restrict sigmask)
{
	int ret = _asan__sys_pollts(fds, nfds, ts, sigmask);

	if(ret != -1) {
		int ni = nfds * sizeof(struct pollfd);

		ASAN_WRITE_RANGE(fds, ni);
	}

	return ret;
}
