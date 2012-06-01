#include "../asan-interceptors.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/extattr.h>

int extattr_delete_fd(int, int,
		const char *);
int _asan_extattr_delete_fd(int, int,
		const char *);

int
extattr_delete_fd(int fd, int attrnamespace,
		const char *attrname)
{
	int ret = _asan_extattr_delete_fd(fd, attrnamespace,
			attrname);

	if(ret == 0) {
		touch_mem(attrname);
	}

	return ret;
}
