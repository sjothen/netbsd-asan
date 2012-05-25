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

	if(ret > 0) {
		if(readfds != NULL)
			ASAN_WRITE_RANGE(readfds, sizeof(*readfds));

		if(writefds != NULL)
			ASAN_WRITE_RANGE(writefds, sizeof(*writefds));

		if(exceptfds != NULL)
			ASAN_WRITE_RANGE(exceptfds, sizeof(*exceptfds));
	}

	return ret;
}
