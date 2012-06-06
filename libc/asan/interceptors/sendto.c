#include "interceptors.h"
#include <sys/socket.h>

ssize_t sendto(int, const void *, size_t, int,
		const struct sockaddr *, socklen_t);
ssize_t _asan_sendto(int, const void *, size_t, int,
		const struct sockaddr *, socklen_t);

ssize_t
sendto(int s, const void *msg, size_t len, int flags,
	const struct sockaddr *to, socklen_t tolen)
{
	ssize_t ret = _asan_sendto(s, msg, len, flags, to, tolen);

	if(ret >= 0) {
		ASAN_READ_RANGE(msg, ret);
		ASAN_READ_RANGE(to, tolen);
	}

	return ret;
}
