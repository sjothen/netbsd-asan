#include "interceptors.h"
#include <sys/mman.h>

int munmap(void *, size_t);
int _asan_munmap(void *, size_t);

int
munmap(void *addr, size_t len)
{
	int ret = _asan_munmap(addr, len);

	if(ret == 0) {
		ASAN_READ_RANGE(addr, len);
	}

	return ret;
}
