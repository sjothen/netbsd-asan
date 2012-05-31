#include <string.h>
#include <unistd.h>

int __setlogin(const char *);
int _asan__setlogin(const char *);

int
__setlogin(const char *namebuf)
{
	int ret = _asan__setlogin(namebuf);

	int sz = strlen(namebuf);
	ASAN_READ_RANGE(namebuf, sz+1);

	return ret;
}
