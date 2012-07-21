#include "interceptors.h"
#include <unistd.h>

int profil(char *, size_t, u_long, u_int);
int _asan_profil(char *, size_t, u_long, u_int);

int
profil(char *samples, size_t size, u_long offset, u_int scale)
{
	int ret = _asan_profil(samples, size, offset, scale);

	if(ret == 0)
		ASAN_WRITE_RANGE(samples, size);

	return ret;
}
