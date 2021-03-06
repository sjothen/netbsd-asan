#include "interceptors.h"
#include <sys/param.h>
#include <sys/select.h>

int _sys_pselect(int, fd_set * __restrict, fd_set * __restrict,
	fd_set * __restrict, const struct timespec * __restrict,
	const sigset_t * __restrict);
int _asan__sys_pselect(int, fd_set * __restrict, fd_set * __restrict,
	fd_set * __restrict, const struct timespec * __restrict,
	const sigset_t * __restrict);

int
_sys_pselect(int nfds, fd_set * __restrict readfds, fd_set * __restrict writefds,
	fd_set * __restrict exceptfds, const struct timespec * __restrict timeout,
	const sigset_t * __restrict sigmask)
{
	int ret = _asan__sys_pselect(nfds, readfds, writefds, exceptfds, timeout, sigmask);

	if(ret > 0) {
		int ni = howmany(nfds, NFDBITS) * sizeof(fd_mask);

		if(readfds != NULL)
			ASAN_WRITE_RANGE(readfds, ni);

		if(writefds != NULL)
			ASAN_WRITE_RANGE(writefds, ni);

		if(exceptfds != NULL)
			ASAN_WRITE_RANGE(exceptfds, ni);

		if(timeout != NULL)
			ASAN_READ_RANGE(timeout, sizeof(struct timespec));

		if(sigmask != NULL)
			ASAN_READ_RANGE(sigmask, sizeof(sigset_t));
	}

	return ret;
}
