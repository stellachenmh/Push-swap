#include "../push_swap.h"
#include "test.h"
#include "tst.h"

tstsuite("Operations Swap")
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

	tstcase("sa")
	{
		tstsection("empty swap")
		{
			a = stack_init(empty, 1);
			capture_begin(&saved_out, pfd);
			sa(a);
			capture_end(saved_out, pfd, out, sizeof(out));
			tstexpect(strcmp(out, "sa") == 0, "prints sa");
			tstexpect(a->size == 1, "size is 1");
			stack_destroy(&a);
		}
		tstsection("one swap")
		{
			a = stack_init(one, 1);
			capture_begin(&saved_out, pfd);
			sa(a);
			capture_end(saved_out, pfd, out, sizeof(out));
			tstexpect(strcmp(out, "sa") == 0, "prints sa");
			tstexpect(check_stack(a, one[0]) == 0, "no swap");
			stack_destroy(&a);
		}
		tstsection("happy swap")
		{
			a = stack_init(odds, 3);
			capture_begin(&saved_out, pfd);
			sa(a);
			capture_end(saved_out, pfd, out, sizeof(out));
			tstexpect(strcmp(out, "sa") == 0, "prints sa");
			tstexpect(check_stack(a, odds[1], odds[0], odds[2]) == 0,
				"swap correct");
			stack_destroy(&a);
		}
	}
	tstcase("sb")
	{
		tstsection("empty swap")
		{
			b = stack_init(empty, 1);
			capture_begin(&saved_out, pfd);
			sb(b);
			capture_end(saved_out, pfd, out, sizeof(out));
			tstexpect(strcmp(out, "sb") == 0, "prints sb");
			tstexpect(b->size == 1, "size is 1");
			stack_destroy(&b);
		}
		tstsection("one swap")
		{
			b = stack_init(one, 1);
			capture_begin(&saved_out, pfd);
			sb(b);
			capture_end(saved_out, pfd, out, sizeof(out));
			tstexpect(strcmp(out, "sb") == 0, "prints sb");
			tstexpect(check_stack(b, one[0]) == 0, "no swap");
			stack_destroy(&b);
		}
		tstsection("happy swap")
		{
			b = stack_init(evens, 3);
			capture_begin(&saved_out, pfd);
			sb(b);
			capture_end(saved_out, pfd, out, sizeof(out));
			tstexpect(strcmp(out, "sb") == 0, "prints sb");
			tstexpect(check_stack(b, evens[1], evens[0], evens[2]) == 0,
				"swap correct");
			stack_destroy(&b);
		}
	}
	tstcase("ss")
	{
		tstsection("empty swap")
		{
			a = stack_init(empty, 1);
			b = stack_init(empty, 1);
			capture_begin(&saved_out, pfd);
			ss(a, b);
			capture_end(saved_out, pfd, out, sizeof(out));
			tstexpect(strcmp(out, "ss") == 0, "prints ss");
			tstexpect(a->size == 1, "size is 1");
			tstexpect(b->size == 1, "size is 1");
			stack_destroy(&a);
			stack_destroy(&b);
		}
		tstsection("one swap")
		{
			a = stack_init(one, 1);
			b = stack_init(one, 1);
			capture_begin(&saved_out, pfd);
			ss(a, b);
			capture_end(saved_out, pfd, out, sizeof(out));
			tstexpect(strcmp(out, "ss") == 0, "prints ss");
			tstexpect(check_stack(a, one[0]) == 0, "no swap");
			tstexpect(check_stack(b, one[0]) == 0, "no swap");
			stack_destroy(&a);
			stack_destroy(&b);
		}
		tstsection("happy swap")
		{
			a = stack_init(odds, 3);
			b = stack_init(evens, 3);
			capture_begin(&saved_out, pfd);
			ss(a, b);
			capture_end(saved_out, pfd, out, sizeof(out));
			tstexpect(strcmp(out, "ss") == 0, "prints ss");
			tstexpect(check_stack(a, odds[1], odds[0], odds[2]) == 0,
				"swap correct");
			tstexpect(check_stack(b, evens[1], evens[0], evens[2]) == 0,
				"swap correct");
			stack_destroy(&a);
			stack_destroy(&b);
		}
	}
}
