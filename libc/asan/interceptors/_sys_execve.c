#include "../asan-interceptors.h"
#include <unistd.h>

int _sys_execve(const char *, char * const *, char * const *);
int _asan__sys_execve(const char *, char * const *, char * const *);

int
_sys_execve(const char *path, char * const *argp, char * const *envp)
{
	int ret = _asan__sys_execve(path, argp, envp);

	touch_mem(path);

	return ret;
}
