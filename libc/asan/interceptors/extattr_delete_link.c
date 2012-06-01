#include "../asan-interceptors.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/extattr.h>

int extattr_delete_link(const char *, int,
		const char *);
int _asan_extattr_delete_link(const char *, int,
		const char *);

int
extattr_delete_link(const char *path, int attrnamespace,
		const char *attrname)
{
	int ret = _asan_extattr_delete_link(path, attrnamespace,
			attrname);

	if(ret == 0) {
		touch_mem(path);
		touch_mem(attrname);
	}

	return ret;
}
