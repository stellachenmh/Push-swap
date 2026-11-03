
#include "../push_swap.h"
#include "tst.h"

void		sort_three_ints(t_stack *a); 

tstsuite("Test simple sort and helper functions")
{
	
	// tst_case("sort_two_elements") 
	// {
	// }

	// tst_case("sort_reverse_order")
	// {
	// }

	// tst_case("sort_already_sorted")
	// {
	// }
	
	// Test "sort 3 ints"
	// Set up all permutations of 3 ints
	int arr132[] = {1, 3, 2};
	int arr213[] = {2, 1, 3};
	int arr231[] = {2, 3, 1};
	int arr312[] = {3, 1, 2};
	int arr321[] = {3, 2, 1};
	int arr123[] = {1, 2, 3};

	t_stack *a132 = stack_init(arr132, 3, 3);
	t_stack *a213 = stack_init(arr213, 3, 3);
	t_stack *a231 = stack_init(arr231, 3, 3);
	t_stack *a312 = stack_init(arr312, 3, 3);
	t_stack *a321 = stack_init(arr321, 3, 3);
	t_stack *a123 = stack_init(arr123, 3, 3);

	tstcase("Sort 3 ints: check initial disorder for 6 permutations")
	{
		tstexpect(compute_disorder(a132) != 0, "A132 must be disordered");
		tstexpect(compute_disorder(a213) != 0, "A213 must be disordered");
		tstexpect(compute_disorder(a231) != 0, "A231 must be disordered");
		tstexpect(compute_disorder(a312) != 0, "A312 must be disordered");
		tstexpect(compute_disorder(a321) != 0, "A321 must be disordered");
		tstexpect(compute_disorder(a123) == 0, "A123 is already sorted");
	}

	sort_three_ints(a132);
	sort_three_ints(a213);
	sort_three_ints(a231);
	sort_three_ints(a312);
	sort_three_ints(a321);
	sort_three_ints(a123);

	tstcase("Sort 3 ints: check successful sorting of 6 permutations")
	{
		tstexpect(compute_disorder(a132) == 0, "A132 should have been sorted");
		tstexpect(compute_disorder(a213) == 0, "A213 should have been sorted");
		tstexpect(compute_disorder(a231) == 0, "A231 should have been sorted");
		tstexpect(compute_disorder(a312) == 0, "A312 should have been sorted");
		tstexpect(compute_disorder(a321) == 0, "A321 should have been sorted");
		tstexpect(compute_disorder(a123) == 0, "A123 was already sorted");
	}
}