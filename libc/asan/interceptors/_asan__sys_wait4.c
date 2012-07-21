#include "interceptors.h"
#include <sys/wait.h>
#include <sys/resource.h>

pid_t _sys_wait4(pid_t, int *, int, struct rusage *);
pid_t _asan__sys_wait4(pid_t, int *, int, struct rusage *);

pid_t
_sys_wait4(pid_t wpid, int *status, int options,
	struct rusage *rusage)
{
	pid_t ret = _asan__sys_wait4(wpid, status, options, rusage);

	if(ret != -1) {
		if(rusage != NULL)
			ASAN_WRITE_RANGE(rusage, sizeof(*rusage));
		
		if(status != NULL)
			ASAN_WRITE_RANGE(status, sizeof(*status));
	}

	return ret;
}
