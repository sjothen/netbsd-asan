#include <sys/socket.h>

int getsockname(int s, struct sockaddr * __restrict, socklen_t * __restrict);
int _asan_getsockname(int s, struct sockaddr * __restrict,
	socklen_t * __restrict);

int
getsockname(int s, struct sockaddr * __restrict name,
	socklen_t * __restrict namelen)
{
	int ret = _asan_getsockname(s, name, namelen);

	if(ret == 0)
		ASAN_WRITE_RANGE(name, *namelen);

	return ret;
}
