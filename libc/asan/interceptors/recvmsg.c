#include "interceptors.h"
#include <sys/socket.h>

ssize_t recvmsg(int, struct msghdr *, int);
ssize_t _asan_recvmsg(int, struct msghdr *, int);

ssize_t
recvmsg(int s, struct msghdr *msg, int flags)
{
	int i;
	struct iovec iov;
	int ret = _asan_recvmsg(s, msg, flags);

	if(ret >= 0) {
		ASAN_WRITE_RANGE(msg, sizeof(struct msghdr));

		for(i = 0; i < msg->msg_iovlen; i++) {
			iov = msg->msg_iov[i];
			ASAN_WRITE_RANGE(iov.iov_base, iov.iov_len);
		}

		ASAN_WRITE_RANGE(msg->msg_control, msg->msg_controllen);
	}

	return ret;
}
