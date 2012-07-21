#include "interceptors.h"
#include <sys/time.h>

int __getitimer50(int, struct itimerval *);
int _asan___getitimer50(int, struct itimerval *);

int
__getitimer50(int which, struct itimerval *value)
{
	int ret = _asan___getitimer50(which, value);

	if(ret == 0)
		ASAN_WRITE_RANGE(value, sizeof(*value));

	return ret;
}
