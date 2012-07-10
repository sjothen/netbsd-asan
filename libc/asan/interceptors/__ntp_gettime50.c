#include "interceptors.h"
#include <sys/time.h>
#include <sys/timex.h>

int __ntp_gettime50(struct ntptimeval *ntvp);
int _asan___ntp_gettime50(struct ntptimeval *ntvp);

int
__ntp_gettime50(struct ntptimeval *ntvp)
{
	int ret = _asan___ntp_gettime50(ntvp);

	if(ret == 0)
		ASAN_WRITE_RANGE(ntvp, sizeof(struct ntptimeval));

	return ret;
}
