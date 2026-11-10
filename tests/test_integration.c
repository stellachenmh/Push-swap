#include "../push_swap.h"
#include "test.h"
#include "tst.h"
#include <stdio.h>

static int	op_is(const char *op, const char *name)
{
	return (ft_strlen(op) == ft_strlen(name)
		&& ft_strncmp(op, name, ft_strlen(name)) == 0);
}

static void	apply_named_op(t_stack *a, t_stack *b, const char *op,
		t_out *silent)
{
	if (op_is(op, "sa"))
		sa(a, silent);
	else if (op_is(op, "sb"))
		sb(b, silent);
	else if (op_is(op, "ss"))
		ss(a, b, silent);
	else if (op_is(op, "pa"))
		pa(a, b, silent);
	else if (op_is(op, "pb"))
		pb(a, b, silent);
	else if (op_is(op, "ra"))
		ra(a, silent);
	else if (op_is(op, "rb"))
		rb(b, silent);
	else if (op_is(op, "rr"))
		rr(a, b, silent);
	else if (op_is(op, "rra"))
		rra(a, silent);
	else if (op_is(op, "rrb"))
		rrb(b, silent);
	else if (op_is(op, "rrr"))
		rrr(a, b, silent);
}

static void	apply_ops(t_stack *a, t_stack *b, const char *ops, t_out *silent)
{
	const char	*p;
	size_t		len;
	char		tok[8];

	p = ops;
	while (*p)
	{
		while (*p == ' ' || *p == '\n')
			p++;
		len = 0;
		while (p[len] && p[len] != ' ' && p[len] != '\n')
		{
			if (len < sizeof(tok) - 1)
				tok[len] = p[len];
			len++;
		}
		if (len == 0)
			break ;
		tok[len] = '\0';
		apply_named_op(a, b, tok, silent);
		p += len;
	}
}

/*
 * Replays the emitted operation stream on a fresh copy of the input. This is
 * the seam that catches the "sorted twice" bug: the flow's final stack can be
 * sorted while the emitted ops, applied to the original input, are not.
 */
static int	replay_flow(int *input, int n, int strategy)
{
	t_stack		*a;
	t_stack		*b;
	t_stack		*ra;
	t_stack		*rb;
	t_out		silent;
	t_out		out;
	char		buf[4096];
	int			saved_out;
	int			pfd[2];
	int			empty[1];
	size_t		i;
	int			result;

	empty[0] = 0;
	result = 0;
	ft_bzero(&silent, sizeof(silent));
	silent.fd = -1;
	ft_bzero(&out, sizeof(out));
	out.fd = STDOUT_FILENO;
	a = stack_init(input, n, n);
	b = stack_init(empty, 0, n);
	ra = stack_init(input, n, n);
	rb = stack_init(empty, 0, n);
	if (!a || !b || !ra || !rb)
		return (1);
	capture_begin(&saved_out, pfd);
	if (select_strategy(a, b, strategy, &out) != EXIT_SUCCESS)
		result = 1;
	capture_end(saved_out, pfd, buf, sizeof(buf));
	apply_ops(ra, rb, buf, &silent);
	i = 0;
	while (i + 1 < ra->size)
	{
		if (ra->data[i] > ra->data[i + 1])
			result = 1;
		i++;
	}
	if (rb->size != 0)
		result = 1;
	stack_destroy(&a);
	stack_destroy(&b);
	stack_destroy(&ra);
	stack_destroy(&rb);
	return (result);
}

tstsuite("Integration: emitted ops sort the original input")
{
	tstcase("CLI emits operations for a two-element input")
	{
		FILE	*pipe;
		char	output[16];
		int		status;

		pipe = popen("./push_swap --simple 2 1", "r");
		tstexpect(pipe != NULL, "could not run push_swap");
		if (pipe)
		{
			if (fgets(output, sizeof(output), pipe) == NULL)
				output[0] = '\0';
			status = pclose(pipe);
			tstexpect(status == 0, "push_swap failed with status %d", status);
			tstexpect(ft_strlen(output) == 3
				&& ft_strncmp(output, "sa\n", 3) == 0,
				"expected sa, got %s", output);
		}
	}
	tstcase("adaptive small stacks")
	{
		tstexpect(replay_flow((int[]){2, 1}, 2, ADAPTIVE) == 0, "2 1");
		tstexpect(replay_flow((int[]){1, 3, 2}, 3, ADAPTIVE) == 0, "1 3 2");
		tstexpect(replay_flow((int[]){3, 1, 2}, 3, ADAPTIVE) == 0, "3 1 2");
		tstexpect(replay_flow((int[]){4, 3, 2, 1}, 4, ADAPTIVE) == 0,
			"4 3 2 1");
		tstexpect(replay_flow((int[]){1, 2, 4, 3}, 4, ADAPTIVE) == 0,
			"1 2 4 3");
	}
	tstcase("forced simple small stacks")
	{
		tstexpect(replay_flow((int[]){2, 1}, 2, SIMPLE) == 0, "2 1");
		tstexpect(replay_flow((int[]){1, 3, 2}, 3, SIMPLE) == 0, "1 3 2");
		tstexpect(replay_flow((int[]){4, 3, 2, 1}, 4, SIMPLE) == 0,
			"4 3 2 1");
	}
	tstcase("forced medium small stacks")
	{
		tstexpect(replay_flow((int[]){2, 1}, 2, MEDIUM) == 0, "2 1");
		tstexpect(replay_flow((int[]){1, 3, 2}, 3, MEDIUM) == 0, "1 3 2");
		tstexpect(replay_flow((int[]){4, 3, 2, 1}, 4, MEDIUM) == 0,
			"4 3 2 1");
	}
	tstcase("forced complex small stacks")
	{
		tstexpect(replay_flow((int[]){2, 1}, 2, COMPLEX) == 0, "2 1");
		tstexpect(replay_flow((int[]){1, 3, 2}, 3, COMPLEX) == 0, "1 3 2");
		tstexpect(replay_flow((int[]){4, 3, 2, 1}, 4, COMPLEX) == 0,
			"4 3 2 1");
	}
	tstcase("larger adaptive input")
	{
		int input[] = {5, 4, 3, 2, 1, 9, 8, 7, 6, 10, 11, 12};

		tstexpect(replay_flow(input, 12, ADAPTIVE) == 0, "12 elements");
	}
}
