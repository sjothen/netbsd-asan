#include <sys/socket.h>

int bind(int, const struct sockaddr *, unsigned int);
int _asan_bind(int, const struct sockaddr *, unsigned int);

int
bind(int s, const struct sockaddr *name, unsigned int namelen)
{
	int ret = _asan_bind(s, name, namelen);

	if(ret == 0)
		ASAN_READ_RANGE(name, namelen);

	return ret;
}
