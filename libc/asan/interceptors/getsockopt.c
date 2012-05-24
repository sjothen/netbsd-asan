#include <sys/socket.h>

int getsockopt(int, int, int, void * restrict, socklen_t * restrict);
int _asan_getsockopt(int, int, int, void * restrict, socklen_t * restrict);

int
getsockopt(int s, int level, int optname, void * restrict optval,
	socklen_t * restrict optlen)
{
	int ret = _asan_getsockopt(s, level, optname, optval, optlen);

	if(ret == 0 && optval != NULL)
		ASAN_WRITE_RANGE(optval, optlen);

	return ret;
}
