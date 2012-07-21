#include "interceptors.h"
#include <sys/socket.h>

ssize_t sendmsg(int, const struct msghdr *, int);
ssize_t _asan_sendmsg(int, const struct msghdr *, int);

ssize_t
sendmsg(int s, const struct msghdr *msg, int flags)
{
	int i;
	struct iovec iov;
	int ret = _asan_sendmsg(s, msg, flags);

	if(ret >= 0) {
		ASAN_READ_RANGE(msg, sizeof(struct msghdr));

		for(i = 0; i < msg->msg_iovlen; i++) {
			iov = msg->msg_iov[i];
			ASAN_READ_RANGE(iov.iov_base, iov.iov_len);
		}

		ASAN_READ_RANGE(msg->msg_control, msg->msg_controllen);
	}

	return ret;
}
