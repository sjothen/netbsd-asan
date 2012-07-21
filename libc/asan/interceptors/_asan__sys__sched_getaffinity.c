#include "interceptors.h"
#include <sys/sched.h>

int _sys__sched_getaffinity(pid_t pid, lwpid_t lid,
		size_t size, cpuset_t *cpuset);
int _asan__sys__sched_getaffinity(pid_t pid, lwpid_t lid,
		size_t size, cpuset_t *cpuset);

int
_sys__sched_getaffinity(pid_t pid, lwpid_t lid,
		size_t size, cpuset_t *cpuset)
{
	int ret = _asan__sys__sched_getaffinity(pid, lid,
			size, cpuset);

	if(ret == 0)
		ASAN_WRITE_RANGE(cpuset, sizeof(cpuset_t));

	return ret;
}
