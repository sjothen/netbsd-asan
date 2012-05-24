#include <sys/socket.h>

ssize_t recvfrom(int s, void * restrict buf, size_t len, int flags,
	struct sockaddr * restrict from, socklen_t * restrict fromlen);
ssize_t _asan_recvfrom(int s, void * restrict buf, size_t len, int flags,
	struct sockaddr * restrict from, socklen_t * restrict fromlen);

ssize_t
recvfrom(int s, void * restrict buf, size_t len, int flags,
	struct sockaddr * restrict from, socklen_t * restrict fromlen)
{
	ssize_t ret = _asan_recvfrom(s, buf, len, flags, from, fromlen);

	if(ret >= 0)
		ASAN_WRITE_RANGE(buf, len);

	return ret;
}
