#include <sys/poll.h>

int _sys_poll(struct pollfd *, nfds_t, int);
int _asan_sys_poll(struct pollfd *, nfds_t, int);

int
_sys_poll(struct pollfd *fds, nfds_t nfds, int timeout)
{
	int ret = _asan_sys_poll(fds, nfds, timeout);

	if(ret != -1) {
		int ni = nfds * sizeof(struct pollfd);

		ASAN_WRITE_RANGE(fds, ni);
	}

	return ret;
}
