#include "../push_swap.h"
#include "test.h"
#include "tst.h"

tstsuite("Operations Stats")
{
	int		odds[] = {1, 3, 7};
	int		evens[] = {2, 4, 6};
	t_stack	*a;
	t_stack	*b;
	t_out	ctx;
	int		saved_out;
	int		pfd[2];
	char	out[8];

	tstcase("counts sa while silent")
	{
		a = stack_init(odds, 3, 3);
		ft_bzero(&ctx, sizeof(ctx));
		ctx.fd = -1;
		sa(a, &ctx);
		tstexpect(ctx.count[OP_SA] == 1, "sa count %u", ctx.count[OP_SA]);
		tstexpect(ctx.count[OP_SB] == 0, "sb count %u", ctx.count[OP_SB]);
		stack_destroy(&a);
	}
	tstcase("counts while writing")
	{
		a = stack_init(odds, 3, 3);
		ft_bzero(&ctx, sizeof(ctx));
		ctx.fd = STDOUT_FILENO;
		capture_begin(&saved_out, pfd);
		sa(a, &ctx);
		capture_end(saved_out, pfd, out, sizeof(out));
		tstexpect(ctx.count[OP_SA] == 1, "sa count %u", ctx.count[OP_SA]);
		tstexpect(strcmp(out, "sa\n") == 0, "wrote %s", out);
		stack_destroy(&a);
	}
	tstcase("counts every operation once")
	{
		a = stack_init(odds, 3, 6);
		b = stack_init(evens, 3, 6);
		ft_bzero(&ctx, sizeof(ctx));
		ctx.fd = -1;
		sa(a, &ctx);
		sb(b, &ctx);
		ss(a, b, &ctx);
		pa(a, b, &ctx);
		pb(a, b, &ctx);
		ra(a, &ctx);
		rb(b, &ctx);
		rr(a, b, &ctx);
		rra(a, &ctx);
		rrb(b, &ctx);
		rrr(a, b, &ctx);
		tstexpect(ctx.count[OP_SA] == 1, "sa %u", ctx.count[OP_SA]);
		tstexpect(ctx.count[OP_SB] == 1, "sb %u", ctx.count[OP_SB]);
		tstexpect(ctx.count[OP_SS] == 1, "ss %u", ctx.count[OP_SS]);
		tstexpect(ctx.count[OP_PA] == 1, "pa %u", ctx.count[OP_PA]);
		tstexpect(ctx.count[OP_PB] == 1, "pb %u", ctx.count[OP_PB]);
		tstexpect(ctx.count[OP_RA] == 1, "ra %u", ctx.count[OP_RA]);
		tstexpect(ctx.count[OP_RB] == 1, "rb %u", ctx.count[OP_RB]);
		tstexpect(ctx.count[OP_RR] == 1, "rr %u", ctx.count[OP_RR]);
		tstexpect(ctx.count[OP_RRA] == 1, "rra %u", ctx.count[OP_RRA]);
		tstexpect(ctx.count[OP_RRB] == 1, "rrb %u", ctx.count[OP_RRB]);
		tstexpect(ctx.count[OP_RRR] == 1, "rrr %u", ctx.count[OP_RRR]);
		stack_destroy(&a);
		stack_destroy(&b);
	}
}
