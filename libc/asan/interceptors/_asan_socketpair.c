#include "interceptors.h"
#include <sys/socket.h>

int socketpair(int, int, int, int *);
int _asan_socketpair(int, int, int, int *);

int
socketpair(int d, int type, int protocol, int *sv)
{
	int ret = _asan_socketpair(d, type, protocol, sv);

	if(ret == 0)
		ASAN_WRITE_RANGE(sv, 2*sizeof(int));

	return ret;
}
