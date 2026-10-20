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
			tstexpect(a->size == 1, "size is 1");
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
			tstexpect(a->size == 1, "size is 1");
			capture_begin(&saved_out, pfd);
			sa(a);
			capture_end(saved_out, pfd, out, sizeof(out));
			tstexpect(strcmp(out, "sa") == 0, "prints sa");
			tstexpect(a->size == 1, "size is 1");
			tstexpect(a->data[0] == one[0], "no change");
			stack_destroy(&a);
		}
		tstsection("happy swap")
		{
			a = stack_init(odds, 3);
			tstexpect(a->capacity == 3, "capacity is 3");
			tstexpect(a->size == 3, "size is 3");
			capture_begin(&saved_out, pfd);
			sa(a);
			capture_end(saved_out, pfd, out, sizeof(out));
			tstexpect(strcmp(out, "sa") == 0, "prints sa");
			tstexpect(a->capacity == 3, "capacity is 3");
			tstexpect(a->size == 3, "size is 3");
			tstexpect(a->data[1] == odds[0], "2nd item is now 1st");
			tstexpect(a->data[0] == odds[1], "1st item is now 2nd");
			tstexpect(a->data[2] == odds[2], "no change for 3rd item");
			stack_destroy(&a);
		}
	}
	tstcase("sb")
	{
		tstsection("empty swap")
		{
			b = stack_init(empty, 1);
			tstexpect(b->size == 1, "size is 1");
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
			tstexpect(b->size == 1, "size is 1");
			capture_begin(&saved_out, pfd);
			sb(b);
			capture_end(saved_out, pfd, out, sizeof(out));
			tstexpect(strcmp(out, "sb") == 0, "prints sb");
			tstexpect(b->size == 1, "size is 1");
			tstexpect(b->data[0] == one[0], "no change");
			stack_destroy(&b);
		}
		tstsection("happy swap")
		{
			b = stack_init(evens, 3);
			tstexpect(b->capacity == 3, "capacity is 3");
			tstexpect(b->size == 3, "size is 3");
			capture_begin(&saved_out, pfd);
			sb(b);
			capture_end(saved_out, pfd, out, sizeof(out));
			tstexpect(strcmp(out, "sb") == 0, "prints sb");
			tstexpect(b->capacity == 3, "capacity is 3");
			tstexpect(b->size == 3, "size is 3");
			tstexpect(b->data[1] == evens[0], "2nd item is now 1st");
			tstexpect(b->data[0] == evens[1], "1st item is now 2nd");
			tstexpect(b->data[2] == evens[2], "no change for 3rd item");
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
			tstexpect(a->size == 1, "size is 1");
			tstexpect(a->data[0] == one[0], "no change");
			tstexpect(b->size == 1, "size is 1");
			tstexpect(b->data[0] == one[0], "no change");
			stack_destroy(&a);
			stack_destroy(&b);
		}
		tstsection("happy swap")
		{
			a = stack_init(odds, 3);
			tstexpect(a->capacity == 3, "capacity is 3");
			tstexpect(a->size == 3, "size is 3");
			b = stack_init(evens, 3);
			tstexpect(b->capacity == 3, "capacity is 3");
			tstexpect(b->size == 3, "size is 3");
			capture_begin(&saved_out, pfd);
			ss(a, b);
			capture_end(saved_out, pfd, out, sizeof(out));
			tstexpect(strcmp(out, "ss") == 0, "prints ss");
			tstexpect(a->capacity == 3, "capacity is 3");
			tstexpect(a->size == 3, "size is 3");
			tstexpect(a->data[1] == odds[0], "2nd item is now 1st");
			tstexpect(a->data[0] == odds[1], "1st item is now 2nd");
			tstexpect(a->data[2] == odds[2], "no change for 3rd item");
			tstexpect(b->capacity == 3, "capacity is 3");
			tstexpect(b->size == 3, "size is 3");
			tstexpect(b->data[1] == evens[0], "2nd item is now 1st");
			tstexpect(b->data[0] == evens[1], "1st item is now 2nd");
			tstexpect(b->data[2] == evens[2], "no change for 3rd item");
			stack_destroy(&a);
			stack_destroy(&b);
		}
	}
}
