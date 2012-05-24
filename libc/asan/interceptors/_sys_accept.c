#include <sys/socket.h>

int _sys_accept(int, struct sockaddr * restrict,
	socklen_t * restrict);
int _asan_sys_accept(int, struct sockaddr * restrict,
	socklen_t * restrict);

int
_sys_accept(int s, struct sockaddr * restrict addr,
	socklen_t * restrict addrlen)
{
	int ret = _asan_sys_accept(s, addr, addrlen);

	if(ret != -1)
		ASAN_WRITE_RANGE(addr, *addrlen);

	return ret;
}
