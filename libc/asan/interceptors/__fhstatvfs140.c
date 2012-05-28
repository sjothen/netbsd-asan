#include <sys/types.h>
#include <sys/statvfs.h>

int __fhstatvfs140(const void *, size_t,
		struct statvfs *, int);
int _asan__fhstatvfs140(const void *, size_t,
		struct statvfs *, int);

int
__fhstatvfs140(const void *fhp, size_t fh_size,
		struct statvfs *buf, int flags)
{
	int ret = _asan__fhstatvfs140(fhp, fh_size, buf, flags);

	if(ret == 0)
		ASAN_WRITE_RANGE(buf, sizeof(struct statvfs));

	return ret;
}
