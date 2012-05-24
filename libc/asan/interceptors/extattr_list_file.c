#include <sys/types.h>
#include <sys/extattr.h>

ssize_t extattr_list_file(const char *path, int attrnamespace,
	void *data, size_t nbytes);
ssize_t _asan_extattr_list_file(const char *path, int attrnamespace,
	void *data, size_t nbytes);

ssize_t
extattr_list_file(const char *path, int attrnamespace,
	void *data, size_t nbytes)
{
	ssize_t ret = _asan_extattr_list_file(path, attrnamespace,
			data, nbytes);

	if(ret != -1 && data != NULL)
		ASAN_WRITE_RANGE(data, ret);

	return ret;
}
