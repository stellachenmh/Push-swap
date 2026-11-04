#include "tst.h"
#include "../push_swap.h"

int	find_sqrt(int n);

tstsuite("Sort Medium and helper functions") {
	tst_case("sort_medium_random") {
	}

	tst_case("sort_medium_nearly_sorted") {
	}

	tst_case("sort_medium_reverse") {
	}

	tstcase("Test find sqrt helper function")
	{
		tstexpect(find_sqrt(-25) == -1, "Sq rt of negative no should return -1");
		tstexpect(find_sqrt(225) == 15, "Sq rt of sq no test");
		tstexpect(find_sqrt(10) == 3, "Sq rt of non-sq no should give nearest square below it" );
		tstexpect(find_sqrt(1) == 1, "Sq rt of 1 is 1");
	}
}
