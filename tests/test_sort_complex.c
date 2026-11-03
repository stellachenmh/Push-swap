#include "../push_swap.h"
#include "test.h"
#include "tst.h"

tstsuite("Sort Complex")
{
	int		start[] = {19, 2, 34, 8, 5, 21, 0};
	int		empty[] = {};
	int		check;
	t_stack	*a;
	t_stack	*b;
	int		saved_out;
	int		pfd[2];
	char	out[8];

	tstcase("sort_complex_simple")
	{
		a = stack_init(start, 7, 7);
		b = stack_init(empty, 0, 7);
		capture_begin(&saved_out, pfd);
		sort_complex(a, b);
		capture_end(saved_out, pfd, out, sizeof(out));
		tstexpect((check = check_stack(a, 0, 1, 2, 3, 4, 5, 6)) == 0,
			" invalid check %d", check);
		tstexpect((check = check_stack(b)) == 0, " invalid check %d", check);
		stack_destroy(&a);
		stack_destroy(&b);
	}
	tst_case("sort_complex_large_input")
	{
	}
	tst_case("sort_complex_nearly_sorted")
	{
	}
}
