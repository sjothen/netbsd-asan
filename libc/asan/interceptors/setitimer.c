#include <sys/time.h>

int setitimer(int, const struct itimerval * restrict,
	struct itimerval * restrict)
int _asan_setitimer(int, const struct itimerval * restrict,
	struct itimerval * restrict)

int
setitimer(int which, const struct itimerval * restrict value,
	struct itimerval * restrict ovalue)
{
	int ret = _asan_setitimer(which, value, ovalue);

	if(ret == 0)
		ASAN_WRITE_RANGE(ovalue, sizeof(*ovalue));

	return ret;
}
