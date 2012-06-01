#include <unistd.h>
#include <sys/sched.h>

int _sys__sched_getparam(pid_t, lwpid_t, int *,
		struct sched_param *);
int _asan__sys__sched_getparam(pid_t, lwpid_t, int *,
		struct sched_param *);

int
_sys__sched_getparam(pid_t pid, lwpid_t lid, int *policy,
		struct sched_param *params)
{
	int ret = _asan__sys__sched_getparam(pid, lid, policy, params);

	if(ret == 0) {
		if(policy != NULL)
			ASAN_WRITE_RANGE(policy, sizeof(int));

		if(params != NULL)
			ASAN_WRITE_RANGE(params, sizeof(struct sched_params));
	}

	return ret;
}
