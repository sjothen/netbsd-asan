#include <dirent.h>

int __getdents30(int, char *, size_t);
int _asan__getdents30(int, char *, size_t);

int
__getdents30(int fd, char *buf, size_t count)
{
	int ret = _asan__getdents30(fd, buf, count);

	if(ret != -1)
		ASAN_WRITE_RANGE(buf, ret);

	return ret;
}
