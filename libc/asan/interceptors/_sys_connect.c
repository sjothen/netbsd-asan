#include <sys/socket.h>

int _sys_connect(int, const struct sockaddr *,
		unsigned int);
int _asan_sys_connect(int, const struct sockaddr *,
		unsigned int);

int
_sys_connect(int s, const struct sockaddr *name,
		unsigned int namelen)
{
	int ret = _asan_sys_connect(s, name, namelen);

	if(ret == 0) {
		ASAN_READ_RANGE(name, namelen);
	}

	return ret;
}
