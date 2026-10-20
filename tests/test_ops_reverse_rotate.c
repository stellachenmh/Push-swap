#include "../push_swap.h"
#include "test.h"
#include "tst.h"

tstsuite("Operations Reverse Rotate")
{
	int		odds[] = {1, 3, 7};
	int		evens[] = {2, 4, 6};
	int		empty[] = {};
	int		one[] = {42};
	t_stack	*a;
	t_stack	*b;
	char	out[8];
	int		saved_out;
	int		pfd[2];
	int		check;

	tstcase("rra")
	{
		tstsection("empty")
		{
			a = stack_init(empty, 0, 3);
			capture_begin(&saved_out, pfd);
			rra(a);
			capture_end(saved_out, pfd, out, sizeof(out));
			tstexpect(strcmp(out, "rra") == 0, "prints not rra but %s", out);
			tstexpect((check = check_stack(a)) == 0, "rotate incorrect at %d",
				check);
			stack_destroy(&a);
		}
		tstsection("one")
		{
			a = stack_init(one, 1, 3);
			capture_begin(&saved_out, pfd);
			rra(a);
			capture_end(saved_out, pfd, out, sizeof(out));
			tstexpect(strcmp(out, "rra") == 0, "prints not rra but %s", out);
			tstexpect((check = check_stack(a, one[0])) == 0,
				"rotate incorrect at %d", check);
			stack_destroy(&a);
		}
		tstsection("happy rotate")
		{
			a = stack_init(odds, 3, 3);
			capture_begin(&saved_out, pfd);
			rra(a);
			capture_end(saved_out, pfd, out, sizeof(out));
			tstexpect(strcmp(out, "rra") == 0, "prints not rra but %s", out);
			tstexpect((check = check_stack(a, odds[2], odds[0], odds[1])) == 0,
				"rotate incorrect at %d", check);
			stack_destroy(&a);
		}
	}
	tstcase("rrb")
	{
		tstsection("empty")
		{
			b = stack_init(empty, 0, 3);
			capture_begin(&saved_out, pfd);
			rrb(b);
			capture_end(saved_out, pfd, out, sizeof(out));
			tstexpect(strcmp(out, "rrb") == 0, "prints not rrb but %s", out);
			tstexpect((check = check_stack(b)) == 0, "rotate incorrect at %d",
				check);
			stack_destroy(&b);
		}
		tstsection("one")
		{
			b = stack_init(one, 1, 3);
			capture_begin(&saved_out, pfd);
			rrb(b);
			capture_end(saved_out, pfd, out, sizeof(out));
			tstexpect(strcmp(out, "rrb") == 0, "prints not rrb but %s", out);
			tstexpect((check = check_stack(b, one[0])) == 0,
				"rotate incorrect at %d", check);
			stack_destroy(&b);
		}
		tstsection("happy rotate")
		{
			b = stack_init(evens, 3, 3);
			capture_begin(&saved_out, pfd);
			rrb(b);
			capture_end(saved_out, pfd, out, sizeof(out));
			tstexpect(strcmp(out, "rrb") == 0, "prints not rrb but %s", out);
			tstexpect((check = check_stack(b, evens[2], evens[0],
						evens[1])) == 0, "rotate incorrect at %d", check);
			stack_destroy(&b);
		}
	}
	tstcase("rrr")
	{
		tstsection("empty and one")
		{
			a = stack_init(empty, 0, 3);
			b = stack_init(one, 1, 3);
			capture_begin(&saved_out, pfd);
			rrr(a, b);
			capture_end(saved_out, pfd, out, sizeof(out));
			tstexpect(strcmp(out, "rrr") == 0, "prints not rrr but %s", out);
			tstexpect((check = check_stack(a)) == 0, "rotate incorrect at %d",
				check);
			tstexpect((check = check_stack(b, one[0])) == 0,
				"rotate incorrect at %d", check);
			stack_destroy(&a);
			stack_destroy(&b);
		}
		tstsection("happy rotate")
		{
			a = stack_init(odds, 3, 3);
			b = stack_init(evens, 3, 3);
			capture_begin(&saved_out, pfd);
			rrr(a, b);
			capture_end(saved_out, pfd, out, sizeof(out));
			tstexpect(strcmp(out, "rrr") == 0, "prints not rrr but %s", out);
			tstexpect((check = check_stack(a, odds[2], odds[0], odds[1])) == 0,
				"rotate incorrect at %d", check);
			tstexpect((check = check_stack(b, evens[2], evens[0],
						evens[1])) == 0, "rotate incorrect at %d", check);
			stack_destroy(&a);
			stack_destroy(&b);
		}
	}
}
