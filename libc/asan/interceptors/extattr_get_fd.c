#include <sys/types.h>
#include <sys/extattr.h>

ssize_t extattr_get_fd(const char *path, int attrnamespace,
	const char *attrname, void *data, size_t nbytes);
ssize_t _asan_extattr_get_fd(const char *path, int attrnamespace,
	const char *attrname, void *data, size_t nbytes);

ssize_t
extattr_get_fd(const char *path, int attrnamespace, const char *attrname,
	void *data, size_t nbytes)
{
	ssize_t ret = _asan_extattr_get_fd(path, attrnamespace, attrname,
			data, nbytes);

	if(ret != -1 && data != NULL)
		ASAN_WRITE_RANGE(data, ret);

	return ret;
}
