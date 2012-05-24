#include <sys/resource.h>

int getrusage(int, struct rusage *);
int _asan_getrusage(int, struct rusage *);

int
getrusage(int who, struct rusage *rusage)
{
	int ret = _asan_getrusage(who, rusage);

	if(ret != -1)
		ASAN_WRITE_RANGE(rusage, sizeof(*rusage));

	return ret;
}
