#include "interceptors.h"
#include <sys/types.h>
#include <sys/stat.h>

int __fhstat50(const void *, size_t, struct stat *);
int _asan___fhstat50(const void *, size_t, struct stat *);

int
__fhstat50(const void *fhp, size_t fh_size, struct stat *sb)
{
	int ret = _asan___fhstat50(fhp, fh_size, sb);

	if(ret == 0) {
		ASAN_READ_RANGE(fhp, fh_size);
		ASAN_WRITE_RANGE(sb, sizeof(struct stat));
	}

	return ret;
}
