#include "interceptors.h"
#include <unistd.h>
#include <sys/pmc.h>

int pmc_get_info(int, int, void *);
int _asan_pmc_get_info(int, int, void *);

int
pmc_get_info(int ctr, int op, void *args)
{
	int ret = _asan_pmc_get_info(ctr, op, args);

	if(ret == 0) {
		if(op == PMC_INFO_NCOUNTERS)
			ASAN_WRITE_RANGE(args, sizeof(int));
		else if(op == PMC_INFO_CPUCTR_TYPE)
			ASAN_WRITE_RANGE(args, sizeof(int));
		else if(op == PMC_INFO_COUNTER_VALUE)
			ASAN_WRITE_RANGE(args, sizeof(uint64_t));
	}

	return ret;
}
