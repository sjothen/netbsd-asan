#include "interceptors.h"
#include <unistd.h>
#include <sys/socket.h>

int _sys_accept(int, struct sockaddr * __restrict,
	socklen_t * __restrict);
int _asan__sys_accept(int, struct sockaddr * __restrict,
	socklen_t * __restrict);

int
_sys_accept(int s, struct sockaddr * __restrict addr,
	socklen_t * __restrict addrlen)
{
	int ret = _asan__sys_accept(s, addr, addrlen);

	if(ret != -1 && addr != NULL)
		ASAN_WRITE_RANGE(addr, *addrlen);

	return ret;
}
