#include <signal.h>

int __sigpending14(sigset_t *);
int _asan__sigpending14(sigset_t *);

int
__sigpending14(sigset_t *set)
{
	int ret = _asan__sigpending14(set);

	if(ret == 0)
		ASAN_WRITE_RANGE(set, sizeof(sigset_t));

	return ret;
}
