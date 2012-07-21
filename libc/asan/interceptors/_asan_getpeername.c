#include "interceptors.h"
#include <sys/socket.h>

int getpeername(int s, struct sockaddr * __restrict, socklen_t * __restrict);
int _asan_getpeername(int s, struct sockaddr * __restrict,
	socklen_t * __restrict);

int
getpeername(int s, struct sockaddr * __restrict name,
	socklen_t * __restrict namelen)
{
	int ret = _asan_getpeername(s, name, namelen);

	if(ret == 0)
		ASAN_WRITE_RANGE(name, *namelen);

	return ret;
}
