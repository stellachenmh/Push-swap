
#include <limits.h>

#include "../push_swap.h"
#include "tst.h"



void		sort_three_ints(t_stack *a, t_out *out); 

tstsuite("Test simple sort and helper functions")
{
	t_out	ctx = {0};

	ctx.fd = -1;
	tstcase("sort_reverse_order")
	{
		// int rev[] = {6, 5, 4, 3, 2, 1};
		int rev[] = {INT_MAX, 93124, 2341, 0, -4757, INT_MIN};
		int empty[] = {};
		t_stack *revstk = stack_init(rev, 6, 6);
		t_stack *b = stack_init(empty, 0, 6);
		sort_simple(revstk, b, &ctx);
		tstexpect(compute_disorder(revstk) == 0, "Reversed stack should be sorted");

		// pb caused seg fault when given null ptr for stack b
		// tstexpect(revstk->data[0] == 6);
		// (void)b;
		// pb(revstk, b);
		// tstexpect(revstk->data[0] == 5);
	}
	tstcase("sort_two_elements")
	{
		int		values[] = {2, 1};
		int		empty[] = {};
		t_stack	*a;
		t_stack	*b;

		a = stack_init(values, 2, 2);
		b = stack_init(empty, 0, 2);
		sort_simple(a, b, &ctx);
		tstexpect(compute_disorder(a) == 0,
			"two elements should be sorted");
		tstexpect(b->size == 0, "stack b should be empty");
		stack_destroy(&a);
		stack_destroy(&b);
	}

	// tst_case("sort_already_sorted")
	// {
	// }
	
	// tst_case("sort_two_elements") 
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

	tstcase("Sort 3 ints: check successful sorting of 6 permutations")
	{
		sort_three_ints(a132, &ctx);
		sort_three_ints(a213, &ctx);
		sort_three_ints(a231, &ctx);
		sort_three_ints(a312, &ctx);
		sort_three_ints(a321, &ctx);
		sort_three_ints(a123, &ctx);
		
		tstexpect(compute_disorder(a132) == 0, "A132 should have been sorted");
		tstexpect(compute_disorder(a213) == 0, "A213 should have been sorted");
		tstexpect(compute_disorder(a231) == 0, "A231 should have been sorted");
		tstexpect(compute_disorder(a312) == 0, "A312 should have been sorted");
		tstexpect(compute_disorder(a321) == 0, "A321 should have been sorted");
		tstexpect(compute_disorder(a123) == 0, "A123 was already sorted");
	}
}