#include <unistd.h>
#include <sys/types.h>
#include <sys/extattr.h>

ssize_t extattr_list_fd(int, int,
	void *, size_t);
ssize_t _asan_extattr_list_fd(int, int,
	void *, size_t);

ssize_t
extattr_list_fd(int fd, int attrnamespace,
	void *data, size_t nbytes)
{
	ssize_t ret = _asan_extattr_list_fd(fd, attrnamespace,
			data, nbytes);

	if(ret != -1 && data != NULL)
		ASAN_WRITE_RANGE(data, ret);

	return ret;
}
