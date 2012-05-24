#include <sys/time.h>

int getitimer(int, struct itimerval *);
int _asan_getitimer(int, struct itimerval *);

int
getitimer(int which, struct itimerval *value)
{
	int ret = _asan_getitimer(which, value);

	if(ret == 0)
		ASAN_WRITE_RANGE(value, sizeof(*value));

	return ret;
}
