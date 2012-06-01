#include "../asan-interceptors.h"
#include <sys/sched.h>

int _sys__sched_setparam(pid_t, lwpid_t, int,
		const struct sched_param *);
int _asan_sys__sched_setparam(pid_t, lwpid_t, int,
		const struct sched_param *);

int
_sys__sched_setparam(pid_t pid, lwpid_t lid, int policy,
		const struct sched_param *params)
{
	int ret = _asan_sys__sched_setparam(pid, lid, policy, params);

	if(ret == 0) {
		ASAN_READ_RANGE(params, sizeof(struct sched_params));
	}

	return ret;
}
