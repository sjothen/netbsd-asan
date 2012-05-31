#include <unistd.h>
#include <string.h>

int _sys_execve(const char *, char * const *, char * const *);
int _asan_sys_execve(const char *, char * const *, char * const *);

int
_sys_execve(const char *path, char * const *argp, char * const *envp)
{
	int ret = _asan_sys_execve(path, argp, envp);

	return ret;
}
