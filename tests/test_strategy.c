#include "../push_swap.h"
#include "tst.h"

tstsuite("Strategy selection")
{
	tstcase("adaptive disorder thresholds")
	{
		tstexpect(adaptive_strategy_for_disorder(0.0f) == SIMPLE);
		tstexpect(adaptive_strategy_for_disorder(0.199f) == SIMPLE);
		tstexpect(adaptive_strategy_for_disorder(0.2f) == MEDIUM);
		tstexpect(adaptive_strategy_for_disorder(0.499f) == MEDIUM);
		tstexpect(adaptive_strategy_for_disorder(0.5f) == COMPLEX);
		tstexpect(adaptive_strategy_for_disorder(1.0f) == COMPLEX);
	}
}
