#include <sys/types.h>
#include <ufs/lfs/lfs.h>

int lfs_bmapv(fsid_t *, BLOCK_INFO *, int);
int _asan_lfs_bmapv(fsid_t *, BLOCK_INFO *, int);

int
lfs_bmapv(fsid_t *fsidp, BLOCK_INFO *blkiov, int blkcnt)
{
	int ret = _asan_lfs_bmapv(fsidp, blkiov, blkcnt);

	if(ret == 0)
		ASAN_WRITE_RANGE(blkiov, blkcnt*sizeof(BLOCK_INFO));

	return ret;
}
