#include "interceptors.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/extattr.h>

ssize_t extattr_get_link(const char *, int,
	const char *, void *, size_t);
ssize_t _asan_extattr_get_link(const char *, int,
	const char *, void *, size_t);

ssize_t
extattr_get_link(const char *path, int attrnamespace, const char *attrname,
	void *data, size_t nbytes)
{
	ssize_t ret = _asan_extattr_get_link(path, attrnamespace, attrname,
			data, nbytes);

	if(ret != -1) {
		touch_mem(path);
		touch_mem(attrname);
		if(data != NULL)
			ASAN_WRITE_RANGE(data, ret);
	}

	return ret;
}
