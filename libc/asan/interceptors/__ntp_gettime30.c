#include <sys/time.h>
#include <sys/timex.h>

int __ntp_gettime30(struct ntptimeval *ntvp);
int _asan__ntp_gettime30(struct ntptimeval *ntvp);

int
__ntp_gettime30(struct ntptimeval *ntvp)
{
	int ret = _asan__ntp_gettime30(ntvp);

	if(ret == 0)
		ASAN_WRITE_RANGE(ntvp, sizeof(struct ntptimeval));

	return ret;
}
