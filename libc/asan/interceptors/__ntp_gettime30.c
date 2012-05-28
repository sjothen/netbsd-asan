#include <sys/time.h>
#include <sys/timex.h>

int __ntp_gettime30(struct ntptimeval *ntvp);
int _asan__ntp_gettime30(struct ntptimeval *ntvp);

int
__ntp_gettime30(struct ntptimeval *ntvp)
{
}
