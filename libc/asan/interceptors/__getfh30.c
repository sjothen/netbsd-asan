#include <sys/types.h>
#include <sys/mount.h>

int __getfh30(const char *, void *, size_t *);
int _asan__getfh30(const char *, void *, size_t *);

int
__getfh30(const char *fname, void *fhp, size_t *fh_size)
{
	int ret = _asan__getfh30(fname, fhp, fh_size);

	if(ret == 0) {
		if(fhp != NULL)
			ASAN_WRITE_RANGE(fhp, *fh_size);

		ASAN_WRITE_RANGE(fh_size, sizeof(size_t));
	}

	return ret;
}