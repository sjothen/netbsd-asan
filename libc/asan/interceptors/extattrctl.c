#include "../asan-interceptors.h" 
#include <sys/extattr.h>
#include <unistd.h>

int extattrctl(const char *, int, const char *,
		int, const char *);
int _asan_extattrctl(const char *, int, const char *,
		int, const char *);

int
extattrctl(const char *path, int cmd, const char *filename,
		int attrnamespace, const char *attrname)
{
	int ret = _asan_extattrctl(path, cmd, filename,
			attrnamespace, attrname);

	if(ret == 0) {
		if(filename != NULL)
			touch_mem(filename);

		if(attrname != NULL)
			touch_mem(attrname);

		touch_mem(path);
	}

	return ret;
}
