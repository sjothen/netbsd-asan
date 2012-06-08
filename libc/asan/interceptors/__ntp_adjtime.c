#include "interceptors.h"
#include <sys/time.h>
#include <sys/timex.h>

int __ntp_adjtime(struct timex *tp);
int _asan___ntp_adjtime(struct timex *tp);

int
__ntp_adjtime(struct timex *tp)
{
	int ret = _asan___ntp_adjtime(tp);

	if(ret == 0)
		ASAN_WRITE_RANGE(tp, sizeof(struct timex));

	return ret;
}
