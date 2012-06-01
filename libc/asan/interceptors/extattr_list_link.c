#include "../asan-interceptors.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/extattr.h>

ssize_t extattr_list_link(const char *, int,
	void *, size_t);
ssize_t _asan_extattr_list_link(const char *, int,
	void *, size_t);

ssize_t
extattr_list_link(const char *path, int attrnamespace,
	void *data, size_t nbytes)
{
	ssize_t ret = _asan_extattr_list_link(path, attrnamespace,
			data, nbytes);

	if(ret != -1) {
		touch_mem(path);
		if(data != NULL)
			ASAN_WRITE_RANGE(data, ret);
	}

	return ret;
}
