#include "tst.h"
#include "../push_swap.h"

#include <limits.h>

int	find_sqrt(int n);

tstsuite("Sort Medium and helper functions") {
	int empty[] = {};
	
	tst_case("sort_medium_random") {
	}

	tst_case("sort_medium_nearly_sorted") {
	}

	tstcase("sort_medium_reverse")
	{
		int revarr[] = {INT_MAX, 234211, 3455, 53, 0, -1, -23434, INT_MIN};
		t_stack *revstk = stack_init(revarr, 8, 8);
		t_stack *b = stack_init(empty, 0, 8);
		tstexpect(compute_disorder(revstk) == 1, "Stack has 1 disorder as it is in reverse order");
		
		// // Test that pb works to decrease a's size and top element
		// pb(revstk, b);
		// tstexpect(revstk->data[0] == 234211);
		// tstexpect(revstk->size == 7);
		// tstexpect(b->size == 1);
		
		// // Test that ra works to bring a new element to top of a
		// ra(revstk);
		// tstexpect(revstk->data[0] == 3455);
		
		sort_medium(revstk, b);
		tstexpect(compute_disorder(revstk) == 0, "Reversed array should be fully sorted");
		tstexpect(b->size == 0, "Stack b should be empty");
	}
	tstcase("Test find sqrt helper function")
	{
		tstexpect(find_sqrt(-25) == -1, "Sq rt of negative no should return -1");
		tstexpect(find_sqrt(225) == 15, "Sq rt of sq no test");
		tstexpect(find_sqrt(10) == 3, "Sq rt of non-sq no should give nearest square below it" );
		tstexpect(find_sqrt(1) == 1, "Sq rt of 1 is 1");
	}
}
