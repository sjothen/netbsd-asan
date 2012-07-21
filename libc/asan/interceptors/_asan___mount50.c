#include "interceptors.h"
#include <sys/param.h>
#include <sys/mount.h>

int __mount50(const char *, const char *, int,
		void *, size_t);
int _asan___mount50(const char *, const char *, int,
		void *, size_t);

int
__mount50(const char *type, const char *path, int flags,
		void *data, size_t data_len)
{
	int ret = _asan___mount50(type, path, flags, data,
			data_len);

	if(ret == 0) {
		touch_mem(type);
		touch_mem(path);

		if(data != NULL)
			ASAN_READ_RANGE(data, data_len);
	}

	return ret;
}
