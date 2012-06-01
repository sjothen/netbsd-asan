#include <unistd.h>
#include <sys/types.h>
#include <sys/statvfs.h>

int getvfsstat(struct statvfs *, size_t, int);
int _asan_getvfsstat(struct statvfs *, size_t, int);

int
getvfsstat(struct statvfs *buf, size_t bufsize, int flags)
{
	int ret = _asan_getvfsstat(buf, bufsize, flags);

	if(ret != -1 && buf != NULL)
		ASAN_WRITE_RANGE(buf, bufsize);

	return ret;
}
