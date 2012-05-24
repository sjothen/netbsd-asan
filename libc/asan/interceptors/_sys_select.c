#include <sys/select.h>

int select(int, fd_set * restrict, fd_set * restrict,
	fd_set * restrict, struct timeval * restrict);
int _asan_select(int, fd_set * restrict, fd_set * restrict,
	fd_set * restrict, struct timeval * restrict);

int
select(int nfds, fd_set * restrict readfds, fd_set * restrict writefds,
	fd_set * restrict exceptfds, struct timeval * restrict timeout)
{
	int ret = _asan_select(nfds, readfds, writefds, exceptfds, timeout);

	if(ret >= 0) {
	}

	return ret;
}
