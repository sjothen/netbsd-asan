#include <sys/socket.h>

int getsockname(int s, struct sockaddr * restrict, socklen_t * restrict);
int _asan_getsockname(int s, struct sockaddr * restrict,
	socklen_t * restrict);

int
getsockname(int s, struct sockaddr * restrict name,
	socklen_t * restrict namelen)
{
	int ret = _asan_getsockname(s, name, namelen);

	if(ret == 0)
		ASAN_WRITE_RANGE(name, *namelen);

	return ret;
}
