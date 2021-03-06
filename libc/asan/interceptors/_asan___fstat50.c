#include "interceptors.h"
#include <sys/stat.h>

int __fstat50(int, struct stat *);
int _asan___fstat50(int, struct stat *);

int
__fstat50(int fd, struct stat *sb)
{
	int ret = _asan___fstat50(fd, sb);

	if(ret == 0)
		ASAN_WRITE_RANGE(sb, sizeof(struct stat));

	return ret;
}
