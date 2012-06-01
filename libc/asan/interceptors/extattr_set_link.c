#include "../asan-interceptors.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/extattr.h>

int extattr_set_link(const char *, int,
		const char *, const void *, size_t);
int _asan_extattr_set_link(const char *, int,
		const char *, const void *, size_t);

int
extattr_set_link(const char *path, int attrnamespace,
		const char *attrname, const void *data, size_t nbytes)
{
	int ret = _asan_extattr_set_link(path, attrnamespace, attrname,
			data, nbytes);

	if(ret != -1) {
		touch_mem(path);
		touch_mem(attrname);
		
		if(data != NULL)
			ASAN_READ_RANGE(data, ret);
	}

	return ret;
}
