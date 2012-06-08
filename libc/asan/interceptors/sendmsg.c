#include "interceptors.h"
#include <sys/socket.h>

ssize_t sendmsg(int, const struct msghdr *, int);
ssize_t _asan_sendmsg(int, const struct msghdr *, int);

ssize_t
sendmsg(int s, const struct msghdr *msg, int flags)
{
	int ret = _asan_sendmsg(s, msg, flags);

	return ret;
}
