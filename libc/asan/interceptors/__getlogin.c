#include <unistd.h>

int __getlogin(char *, size_t);
int _asan__getlogin(char *, size_t);

int
__getlogin(char *namebuf, size_t namelen)
{
	int ret = _asan__getlogin(namebuf, namelen);

	if(ret == 0)
		ASAN_WRITE_RANGE(namebuf, namelen);

	return ret;
}
