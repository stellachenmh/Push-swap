#include "../push_swap.h"
#include "tst.h"
#include <stdint.h>

/**
 * @brief Forces oversized allocations to return NULL instead of aborting under
 * AddressSanitizer, so the allocation-failure paths can be tested like a real
 * out-of-memory error.
 */

const char	*__asan_default_options(void)
{
	return ("allocator_may_return_null=1");
}

tstsuite("Sort allocation failures")
{
	int			vals[] = {3, 2, 1};
	int			empty[] = {};
	t_out		ctx = {0};
	t_stack		*a;
	t_stack		*b;

	ctx.fd = -1;
	tstcase("sorters report rank_ints allocation failure")
	{
		a = stack_init(vals, 3, 3);
		b = stack_init(empty, 0, 3);
		/* A size this large makes rank_ints' malloc fail like real OOM. */
		a->size = SIZE_MAX / sizeof(int);
				tstexpect(sort_simple(a, b, &ctx) == EXIT_FAILURE,
			"sort_simple should fail when ranking fails");
		tstexpect(sort_medium(a, b, &ctx) == EXIT_FAILURE,
			"sort_medium should fail when ranking fails");
		tstexpect(sort_complex(a, b, &ctx) == EXIT_FAILURE,
			"sort_complex should fail when ranking fails");
		stack_destroy(&a);
		stack_destroy(&b);
	}
}
