#include "../asan-interceptors.h"
#include <sys/types.h>

int __fhopen40(const void *, size_t, int);
int _asan__fhopen40(const void *, size_t, int);

int
__fhopen40(const void *fhp, size_t fh_size, int flags)
{
	int ret = _asan__fhopen40(fhp, fh_size, flags);

	if(ret != -1) {
		ASAN_READ_RANGE(fhp, fh_size);
	}

	return ret;
}
