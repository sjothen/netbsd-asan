#include "interceptors.h"
#include <unistd.h>
#include <sys/socket.h>

int getsockopt(int, int, int, void * __restrict, socklen_t * __restrict);
int _asan_getsockopt(int, int, int, void * __restrict, socklen_t * __restrict);

int
getsockopt(int s, int level, int optname, void * __restrict optval,
	socklen_t * __restrict optlen)
{
	int ret = _asan_getsockopt(s, level, optname, optval, optlen);

	if(ret == 0 && optval != NULL && optlen != NULL)
		ASAN_WRITE_RANGE(optval, *optlen);

	return ret;
}
