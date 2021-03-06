#include "interceptors.h"
#include <ufs/ufs/dinode.h>
#include <sys/mount.h>
#include <sys/types.h>
#include <ufs/lfs/lfs.h>

int lfs_bmapv(fsid_t *, struct block_info *, int);
int _asan_lfs_bmapv(fsid_t *, struct block_info *, int);

int
lfs_bmapv(fsid_t *fsidp, struct block_info *blkiov, int blkcnt)
{
	int ret = _asan_lfs_bmapv(fsidp, blkiov, blkcnt);

	if(ret == 0)
		ASAN_WRITE_RANGE(blkiov, blkcnt*sizeof(struct block_info));

	return ret;
}
