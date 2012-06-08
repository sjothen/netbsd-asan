#include "interceptors.h"
#include <fcntl.h>
#include <stdarg.h>

int _sys_fcntl(int fd, int cmd, ...);
int _asan__sys_fcntl(int fd, int cmd, ...);

int
_sys_fcntl(int fd, int cmd, ...)
{
	va_list ap;
	int ret;
	int arg;
	struct flock *fl;

	va_start(ap, cmd);

	switch(cmd) {
	case F_GETFD:
	case F_GETFL:
	case F_GETOWN:
	case F_CLOSEM:
	case F_MAXFD:
		ret = _asan__sys_fcntl(fd, cmd);
		break;
	case F_DUPFD:
	case F_SETFD:
	case F_SETFL:
	case F_SETOWN:
		arg = va_arg(ap, int);
		ret = _asan__sys_fcntl(fd, cmd, arg);
		break;
	case F_GETLK:
	case F_SETLK:
	case F_SETLKW:
		fl = va_arg(ap, struct flock *);
		ret = _asan__sys_fcntl(fd, cmd, fl);

		if(ret != -1) {
			ASAN_WRITE_RANGE(fl, sizeof(struct flock));
		}

		break;
	}

	va_end(ap);

	return ret;
}
