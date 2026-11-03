#include "../push_swap.h"
#include "test.h"
#include "tst.h"

tstsuite("Operations Rotate")
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
	int		one[] = {42};

	tstcase("ra")
	{
		tstsection("empty")
		{
			a = stack_init(empty, 0, 3);
			capture_begin(&saved_out, pfd);
			ra(a);
			capture_end(saved_out, pfd, out, sizeof(out));
			tstexpect(strcmp(out, "ra\n") == 0, "prints not ra but %s", out);
			tstexpect((check = check_stack(a)) == 0, "rotate incorrect at %d",
				check);
			stack_destroy(&a);
		}
		tstsection("one")
		{
			a = stack_init(one, 1, 3);
			capture_begin(&saved_out, pfd);
			ra(a);
			capture_end(saved_out, pfd, out, sizeof(out));
			tstexpect(strcmp(out, "ra\n") == 0, "prints not ra but %s", out);
			tstexpect((check = check_stack(a, one[0])) == 0,
				"rotate incorrect at %d", check);
			stack_destroy(&a);
		}
		tstsection("happy rotate")
		{
			a = stack_init(odds, 3, 3);
			capture_begin(&saved_out, pfd);
			ra(a);
			capture_end(saved_out, pfd, out, sizeof(out));
			tstexpect(strcmp(out, "ra\n") == 0, "prints not ra but %s", out);
			tstexpect((check = check_stack(a, odds[1], odds[2], odds[0])) == 0,
				"rotate incorrect at %d", check);
			stack_destroy(&a);
		}
	}
	tstcase("rb")
	{
		tstsection("empty")
		{
			b = stack_init(empty, 0, 3);
			capture_begin(&saved_out, pfd);
			rb(b);
			capture_end(saved_out, pfd, out, sizeof(out));
			tstexpect(strcmp(out, "rb\n") == 0, "prints not rb but %s", out);
			tstexpect((check = check_stack(b)) == 0, "rotate incorrect at %d",
				check);
			stack_destroy(&b);
		}
		tstsection("one")
		{
			b = stack_init(one, 1, 3);
			capture_begin(&saved_out, pfd);
			rb(b);
			capture_end(saved_out, pfd, out, sizeof(out));
			tstexpect(strcmp(out, "rb\n") == 0, "prints not rb but %s", out);
			tstexpect((check = check_stack(b, one[0])) == 0,
				"rotate incorrect at %d", check);
			stack_destroy(&b);
		}
		tstsection("happy rotate")
		{
			b = stack_init(evens, 3, 3);
			capture_begin(&saved_out, pfd);
			rb(b);
			capture_end(saved_out, pfd, out, sizeof(out));
			tstexpect(strcmp(out, "rb\n") == 0, "prints not rb but %s", out);
			tstexpect((check = check_stack(b, evens[1], evens[2],
						evens[0])) == 0, "rotate incorrect at %d", check);
			stack_destroy(&b);
		}
	}
	tstcase("rr")
	{
		tstsection("empty and one")
		{
			a = stack_init(empty, 0, 3);
			b = stack_init(one, 1, 3);
			capture_begin(&saved_out, pfd);
			rr(a, b);
			capture_end(saved_out, pfd, out, sizeof(out));
			tstexpect(strcmp(out, "rr\n") == 0, "prints not rr but %s", out);
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
			rr(a, b);
			capture_end(saved_out, pfd, out, sizeof(out));
			tstexpect(strcmp(out, "rr\n") == 0, "prints not rr but %s", out);
			tstexpect((check = check_stack(a, odds[1], odds[2], odds[0])) == 0,
				"rotate incorrect at %d", check);
			tstexpect((check = check_stack(b, evens[1], evens[2],
						evens[0])) == 0, "rotate incorrect at %d", check);
			stack_destroy(&a);
			stack_destroy(&b);
		}
	}
}
