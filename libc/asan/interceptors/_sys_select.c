#define _NETBSD_SOURCE
#include <sys/select.h>

int select(int, fd_set * __restrict, fd_set * __restrict,
	fd_set * __restrict, struct timeval * __restrict);
int _asan_select(int, fd_set * __restrict, fd_set * __restrict,
	fd_set * __restrict, struct timeval * __restrict);

int
select(int nfds, fd_set * __restrict readfds, fd_set * __restrict writefds,
	fd_set * __restrict exceptfds, struct timeval * __restrict timeout)
{
	int ret = _asan_select(nfds, readfds, writefds, exceptfds, timeout);

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
