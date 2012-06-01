#include <unistd.h>

int __getcwd(char *, size_t);
int _asan___getcwd(char *, size_t);

int
__getcwd(char *bufp, size_t length)
{
	int ret = _asan___getcwd(bufp, length);

	if(ret != -1)
		ASAN_WRITE_RANGE(bufp, ret);

	return ret;
}
