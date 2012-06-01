#define _NETBSD_SOURCE
#include <sys/select.h>

int pselect(int, fd_set * __restrict, fd_set * __restrict,
	fd_set * __restrict, const struct timespec * __restrict,
	const sigset_t * __restrict);
int _asan_pselect(int, fd_set * __restrict, fd_set * __restrict,
	fd_set * __restrict, const struct timespec * __restrict,
	const sigset_t * __restrict);

int
pselect(int nfds, fd_set * __restrict readfds, fd_set * __restrict writefds,
	fd_set * __restrict exceptfds, const struct timespec * __restrict timeout,
	const sigset_t * __restrict sigmask)
{
	int ret = _asan_pselect(nfds, readfds, writefds, exceptfds, timeout, sigmask);

	if(ret > 0) {
		int ni = howmany(nfds, NFDBITS) * sizeof(fd_mask);

		if(readfds != NULL)
			ASAN_WRITE_RANGE(readfds, ni);

		if(writefds != NULL)
			ASAN_WRITE_RANGE(writefds, ni);

		if(exceptfds != NULL)
			ASAN_WRITE_RANGE(exceptfds, ni);
	}

	return ret;
}
