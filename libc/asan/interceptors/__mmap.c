#include "interceptors.h"
#include <sys/mman.h>

void *__mmap(void *, size_t, int,
		int, int, off_t);
void *_asan___mmap(void *, size_t, int,
		int, int, off_t);

void *
__mmap(void *addr, size_t len, int prot,
		int flags, int fd, off_t offset)
{
	void *ret = _asan___mmap(addr, len, prot, flags, fd, offset);

	if(ret != MAP_FAILED) {
		ASAN_WRITE_RANGE(addr, len);
	}

	return ret;
}
