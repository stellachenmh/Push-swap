#include "../push_swap.h"
#include "tst.h"
#include <string.h>

tstsuite("Index helpers")
{
	int		one[] = {42};
	int		vals[] = {10, 20, 30, 40};
	t_stack	*a;
	t_out	ctx;

	tstcase("single element stack needs no rotation")
	{
		memset(&ctx, 0, sizeof(ctx));
		ctx.fd = -1;
		a = stack_init(one, 1, 1);
		move_idx_to_top(a, 0, 'a', &ctx);
		move_idx_to_top(a, 0, 'b', &ctx);
		tstexpect(ctx.count[OP_RRA] == 0, "rra emitted for one element");
		tstexpect(ctx.count[OP_RRB] == 0, "rrb emitted for one element");
		tstexpect(a->size == 1 && a->data[0] == 42, "stack changed");
		stack_destroy(&a);
	}
	tstcase("forward rotation moves index to top")
	{
		memset(&ctx, 0, sizeof(ctx));
		ctx.fd = -1;
		a = stack_init(vals, 4, 4);
		move_idx_to_top(a, 1, 'a', &ctx);
		tstexpect(ctx.count[OP_RA] == 1, "ra %u", ctx.count[OP_RA]);
		tstexpect(a->data[0] == 20, "top is %d", a->data[0]);
		stack_destroy(&a);
	}
	tstcase("reverse rotation on b moves index to top")
	{
		memset(&ctx, 0, sizeof(ctx));
		ctx.fd = -1;
		a = stack_init(vals, 4, 4);
		move_idx_to_top(a, 2, 'b', &ctx);
		tstexpect(ctx.count[OP_RRB] == 2, "rrb %u", ctx.count[OP_RRB]);
		tstexpect(a->data[0] == 30, "top is %d", a->data[0]);
		stack_destroy(&a);
	}
}
