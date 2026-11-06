#include "../push_swap.h"
#include "../checker_bonus.h"
#include "test.h"
#include "tst.h"

tstsuite("Checker Ops")
{
	int		odds[] = {1, 3, 7};
	int		evens[] = {2, 4, 6};
	int		empty[] = {};
	t_stack	*a;
	t_stack	*b;
	t_out	ctx = {0};
	int		saved_out;
	int		pfd[2];
	char	out[8];
	int		check;
	int		rc;

	ctx.fd = -1;
	tstcase("mappings")
	{
		tstsection("sa")
		{
			a = stack_init(odds, 3, 3);
			b = stack_init(empty, 0, 3);
			rc = apply_instruction(a, b, "sa\n", &ctx);
			tstexpect(rc == 0, "returned %d", rc);
			tstexpect((check = check_stack(a, odds[1], odds[0], odds[2])) == 0,
				"incorrect %d", check);
			stack_destroy(&a);
			stack_destroy(&b);
		}
		tstsection("sb")
		{
			a = stack_init(empty, 0, 3);
			b = stack_init(evens, 3, 3);
			rc = apply_instruction(a, b, "sb\n", &ctx);
			tstexpect(rc == 0, "returned %d", rc);
			tstexpect((check = check_stack(b, evens[1], evens[0],
						evens[2])) == 0, "incorrect %d", check);
			stack_destroy(&a);
			stack_destroy(&b);
		}
		tstsection("ss")
		{
			a = stack_init(odds, 3, 3);
			b = stack_init(evens, 3, 3);
			rc = apply_instruction(a, b, "ss\n", &ctx);
			tstexpect(rc == 0, "returned %d", rc);
			tstexpect((check = check_stack(a, odds[1], odds[0], odds[2])) == 0,
				"incorrect %d", check);
			tstexpect((check = check_stack(b, evens[1], evens[0],
						evens[2])) == 0, "incorrect %d", check);
			stack_destroy(&a);
			stack_destroy(&b);
		}
		tstsection("pa")
		{
			a = stack_init(empty, 0, 3);
			b = stack_init(evens, 3, 3);
			rc = apply_instruction(a, b, "pa\n", &ctx);
			tstexpect(rc == 0, "returned %d", rc);
			tstexpect((check = check_stack(a, evens[0])) == 0, "incorrect %d",
				check);
			tstexpect((check = check_stack(b, evens[1], evens[2])) == 0,
				"incorrect %d", check);
			stack_destroy(&a);
			stack_destroy(&b);
		}
		tstsection("pb")
		{
			a = stack_init(odds, 3, 3);
			b = stack_init(empty, 0, 3);
			rc = apply_instruction(a, b, "pb\n", &ctx);
			tstexpect(rc == 0, "returned %d", rc);
			tstexpect((check = check_stack(a, odds[1], odds[2])) == 0,
				"incorrect %d", check);
			tstexpect((check = check_stack(b, odds[0])) == 0, "incorrect %d",
				check);
			stack_destroy(&a);
			stack_destroy(&b);
		}
		tstsection("ra")
		{
			a = stack_init(odds, 3, 3);
			b = stack_init(empty, 0, 3);
			rc = apply_instruction(a, b, "ra\n", &ctx);
			tstexpect(rc == 0, "returned %d", rc);
			tstexpect((check = check_stack(a, odds[1], odds[2], odds[0])) == 0,
				"incorrect %d", check);
			stack_destroy(&a);
			stack_destroy(&b);
		}
		tstsection("rb")
		{
			a = stack_init(empty, 0, 3);
			b = stack_init(evens, 3, 3);
			rc = apply_instruction(a, b, "rb\n", &ctx);
			tstexpect(rc == 0, "returned %d", rc);
			tstexpect((check = check_stack(b, evens[1], evens[2],
						evens[0])) == 0, "incorrect %d", check);
			stack_destroy(&a);
			stack_destroy(&b);
		}
		tstsection("rr")
		{
			a = stack_init(odds, 3, 3);
			b = stack_init(evens, 3, 3);
			rc = apply_instruction(a, b, "rr\n", &ctx);
			tstexpect(rc == 0, "returned %d", rc);
			tstexpect((check = check_stack(a, odds[1], odds[2], odds[0])) == 0,
				"incorrect %d", check);
			tstexpect((check = check_stack(b, evens[1], evens[2],
						evens[0])) == 0, "incorrect %d", check);
			stack_destroy(&a);
			stack_destroy(&b);
		}
		tstsection("rra")
		{
			a = stack_init(odds, 3, 3);
			b = stack_init(empty, 0, 3);
			rc = apply_instruction(a, b, "rra\n", &ctx);
			tstexpect(rc == 0, "returned %d", rc);
			tstexpect((check = check_stack(a, odds[2], odds[0], odds[1])) == 0,
				"incorrect %d", check);
			stack_destroy(&a);
			stack_destroy(&b);
		}
		tstsection("rrb")
		{
			a = stack_init(empty, 0, 3);
			b = stack_init(evens, 3, 3);
			rc = apply_instruction(a, b, "rrb\n", &ctx);
			tstexpect(rc == 0, "returned %d", rc);
			tstexpect((check = check_stack(b, evens[2], evens[0],
						evens[1])) == 0, "incorrect %d", check);
			stack_destroy(&a);
			stack_destroy(&b);
		}
		tstsection("rrr")
		{
			a = stack_init(odds, 3, 3);
			b = stack_init(evens, 3, 3);
			rc = apply_instruction(a, b, "rrr\n", &ctx);
			tstexpect(rc == 0, "returned %d", rc);
			tstexpect((check = check_stack(a, odds[2], odds[0], odds[1])) == 0,
				"incorrect %d", check);
			tstexpect((check = check_stack(b, evens[2], evens[0],
						evens[1])) == 0, "incorrect %d", check);
			stack_destroy(&a);
			stack_destroy(&b);
		}
	}
	tstcase("unknown instruction")
	{
		a = stack_init(odds, 3, 3);
		b = stack_init(empty, 0, 3);
		rc = apply_instruction(a, b, "xx\n", &ctx);
		tstexpect(rc == -1, "returned %d", rc);
		tstexpect((check = check_stack(a, odds[0], odds[1], odds[2])) == 0,
			"state changed %d", check);
		stack_destroy(&a);
		stack_destroy(&b);
	}
	tstcase("silent by construction")
	{
		a = stack_init(odds, 3, 3);
		b = stack_init(empty, 0, 3);
		capture_begin(&saved_out, pfd);
		rc = apply_instruction(a, b, "sa\n", &ctx);
		capture_end(saved_out, pfd, out, sizeof(out));
		tstexpect(rc == 0, "returned %d", rc);
		tstexpect(strcmp(out, "") == 0, "wrote %s", out);
		stack_destroy(&a);
		stack_destroy(&b);
	}
}
