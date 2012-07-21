#include "interceptors.h"
#include <unistd.h>
#include <sys/swap.h>

int swapctl(int, void *, int);
int _asan_swapctl(int, void *, int);

int
swapctl(int cmd, void *arg, int misc)
{
	int ret = _asan_swapctl(cmd, arg, misc);

	if(ret != -1) {
		if(cmd == SWAP_STATS)
			ASAN_WRITE_RANGE(arg, ret*sizeof(struct swapent));
		else if(cmd == SWAP_GETDUMPDEV)
			ASAN_WRITE_RANGE(arg, sizeof(dev_t));
	}

	return ret;
}
