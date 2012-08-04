#include "interceptors.h"
#include <sys/sched.h>

size_t _cpuset_size(const cpuset_t *);

int _sys__sched_setaffinity(pid_t pid, lwpid_t lid,
		size_t size, const cpuset_t *cpuset);
int _asan__sys__sched_setaffinity(pid_t pid, lwpid_t lid,
		size_t size, const cpuset_t *cpuset);

int
_sys__sched_setaffinity(pid_t pid, lwpid_t lid,
		size_t size, const cpuset_t *cpuset)
{
	int ret = _asan__sys__sched_setaffinity(pid, lid,
			size, cpuset);

	if(ret == 0)
		ASAN_READ_RANGE(cpuset, cpuset_size(cpuset));

	return ret;
}
