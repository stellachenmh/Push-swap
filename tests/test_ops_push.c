#include "../push_swap.h"
#include "test.h"
#include "tst.h"

tstsuite("Operations Push")
{
	int		odds[] = {1, 3, 7};
	int		evens[] = {2, 4, 6};
	t_stack	*a;
	t_stack	*b;
	char	out[8];
	int		saved_out;
	int		pfd[2];
	int		check;
	int		empty[] = {};

	// int		one[] = {42};
	tstcase("pa")
	{
		tstsection("b empty no push")
		{
			a = stack_init(odds, 3, 4);
			b = stack_init(empty, 0, 4);
			capture_begin(&saved_out, pfd);
			pa(a, b);
			capture_end(saved_out, pfd, out, sizeof(out));
			tstexpect(strcmp(out, "") == 0, "prints %s not blank", out);
			tstexpect((check = check_stack(a, odds[0], odds[1], odds[2])) == 0,
				"stack a incorrect %d", check);
			tstexpect((check = check_stack(b)) == 0, "stack b incorrect %d",
				check);
			stack_destroy(&a);
			stack_destroy(&b);
		}
		tstsection("happy push")
		{
			a = stack_init(odds, 3, 4);
			b = stack_init(evens, 3, 4);
			capture_begin(&saved_out, pfd);
			pa(a, b);
			capture_end(saved_out, pfd, out, sizeof(out));
			tstexpect(strcmp(out, "pa") == 0, "prints %s not pa", out);
			tstexpect((check = check_stack(a, evens[0], odds[0], odds[1],
						odds[2])) == 0, "stack a incorrect %d", check);
			tstexpect((check = check_stack(b, evens[1], evens[2])) == 0,
				"stack b incorrect %d", check);
			stack_destroy(&a);
			stack_destroy(&b);
		}
	}
	tstcase("pb")
	{
		tstsection("a empty no push")
		{
			a = stack_init(empty, 0, 4);
			b = stack_init(evens, 3, 4);
			capture_begin(&saved_out, pfd);
			pb(a, b);
			capture_end(saved_out, pfd, out, sizeof(out));
			tstexpect(strcmp(out, "") == 0, "prints %s not blank", out);
			tstexpect((check = check_stack(a)) == 0, "stack a incorrect %d",
				check);
			tstexpect((check = check_stack(b, evens[0], evens[1],
						evens[2])) == 0, "stack b incorrect %d", check);
			stack_destroy(&a);
			stack_destroy(&b);
		}
		tstsection("happy push")
		{
			a = stack_init(odds, 3, 4);
			b = stack_init(evens, 3, 4);
			capture_begin(&saved_out, pfd);
			pb(a, b);
			capture_end(saved_out, pfd, out, sizeof(out));
			tstexpect(strcmp(out, "pb") == 0, "prints %s not pb", out);
			tstexpect((check = check_stack(a, odds[1], odds[2])) == 0,
				"stack a incorrect %d", check);
			tstexpect((check = check_stack(b, odds[0], evens[0], evens[1],
						evens[2])) == 0, "stack b incorrect %d", check);
			stack_destroy(&a);
			stack_destroy(&b);
		}
	}
}
