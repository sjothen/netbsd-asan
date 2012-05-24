#include <sys/select.h>

int pselect(int, fd_set * restrict, fd_set * restrict,
	fd_set * restrict, struct timeval * restrict, const sigset_t * restrict);
int _asan_pselect(int, fd_set * restrict, fd_set * restrict,
	fd_set * restrict, struct timeval * restrict, const sigset_t * restrict);

int
pselect(int nfds, fd_set * restrict readfds, fd_set * restrict writefds,
	fd_set * restrict exceptfds, struct timeval * restrict timeout,
	const sigset_t * restrict sigmask)
{
	int ret = _asan_select(nfds, readfds, writefds, exceptfds, timeout, sigmask);

	if(ret >= 0) {
	}

	return ret;
}
