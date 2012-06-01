#include "../asan-interceptors.h"
#include <sys/sched.h>

int _sys__sched_setaffinity(pid_t pid, lwpid_t lid,
		size_t size, const cpuset_t *cpuset);
int _asan_sys__sched_setaffinity(pid_t pid, lwpid_t lid,
		size_t size, const cpuset_t *cpuset);

int
_sys__sched_setaffinity(pid_t pid, lwpid_t lid,
		size_t size, const cpuset_t *cpuset)
{
	int ret = _asan_sys__sched_setaffinity(pid, lid,
			size, cpuset);

	if(ret == 0)
		ASAN_READ_RANGE(cpuset, sizeof(cpuset_t));

	return ret;
}
