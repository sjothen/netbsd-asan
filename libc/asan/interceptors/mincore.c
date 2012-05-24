#include <sys/mman.h>

int mincore(void *, size_t, char *);
int _asan_mincore(void *, size_t, char *);

int
mincore(void *addr, size_t len, char *vec)
{
	int ret = _asan_mincore(addr, len, vec);

	return ret;
}
