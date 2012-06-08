#include "interceptors.h"
#include <sys/socket.h>

ssize_t recvmsg(int, struct msghdr *, int);
ssize_t _asan_recvmsg(int, struct msghdr *, int);

ssize_t
recvmsg(int s, struct msghdr *msg, int flags)
{
	int ret = _asan_recvmsg(s, msg, flags);

	return ret;
}
