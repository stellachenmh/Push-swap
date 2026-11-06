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
	t_out	ctx = {0};

	ctx.fd = STDOUT_FILENO;
	tstcase("sa")
	{
		tstsection("empty swap")
		{
			a = stack_init(empty, 0, 1);
			capture_begin(&saved_out, pfd);
			sa(a, &ctx);
			capture_end(saved_out, pfd, out, sizeof(out));
			tstexpect(strcmp(out, "sa\n") == 0, "prints sa");
			tstexpect(a->size == 0, "size is 0");
			stack_destroy(&a);
		}
		tstsection("one swap")
		{
			a = stack_init(one, 1, 1);
			capture_begin(&saved_out, pfd);
			sa(a, &ctx);
			capture_end(saved_out, pfd, out, sizeof(out));
			tstexpect(strcmp(out, "sa\n") == 0, "prints sa");
			tstexpect(check_stack(a, one[0]) == 0, "no swap");
			stack_destroy(&a);
		}
		tstsection("happy swap")
		{
			a = stack_init(odds, 3, 3);
			capture_begin(&saved_out, pfd);
			sa(a, &ctx);
			capture_end(saved_out, pfd, out, sizeof(out));
			tstexpect(strcmp(out, "sa\n") == 0, "prints sa");
			tstexpect(check_stack(a, odds[1], odds[0], odds[2]) == 0,
				"swap correct");
			stack_destroy(&a);
		}
	}
	tstcase("sb")
	{
		tstsection("empty swap")
		{
			b = stack_init(empty, 0, 1);
			capture_begin(&saved_out, pfd);
			sb(b, &ctx);
			capture_end(saved_out, pfd, out, sizeof(out));
			tstexpect(strcmp(out, "sb\n") == 0, "prints sb");
			tstexpect(b->size == 0, "size is 0");
			stack_destroy(&b);
		}
		tstsection("one swap")
		{
			b = stack_init(one, 1, 1);
			capture_begin(&saved_out, pfd);
			sb(b, &ctx);
			capture_end(saved_out, pfd, out, sizeof(out));
			tstexpect(strcmp(out, "sb\n") == 0, "prints sb");
			tstexpect(check_stack(b, one[0]) == 0, "no swap");
			stack_destroy(&b);
		}
		tstsection("happy swap")
		{
			b = stack_init(evens, 3, 3);
			capture_begin(&saved_out, pfd);
			sb(b, &ctx);
			capture_end(saved_out, pfd, out, sizeof(out));
			tstexpect(strcmp(out, "sb\n") == 0, "prints sb");
			tstexpect(check_stack(b, evens[1], evens[0], evens[2]) == 0,
				"swap correct");
			stack_destroy(&b);
		}
	}
	tstcase("ss")
	{
		tstsection("empty swap")
		{
			a = stack_init(empty, 0, 1);
			b = stack_init(empty, 0, 1);
			capture_begin(&saved_out, pfd);
			ss(a, b, &ctx);
			capture_end(saved_out, pfd, out, sizeof(out));
			tstexpect(strcmp(out, "ss\n") == 0, "prints ss");
			tstexpect(a->size == 0, "size is 0");
			tstexpect(b->size == 0, "size is 0");
			stack_destroy(&a);
			stack_destroy(&b);
		}
		tstsection("one swap")
		{
			a = stack_init(one, 1, 1);
			b = stack_init(one, 1, 1);
			capture_begin(&saved_out, pfd);
			ss(a, b, &ctx);
			capture_end(saved_out, pfd, out, sizeof(out));
			tstexpect(strcmp(out, "ss\n") == 0, "prints ss");
			tstexpect(check_stack(a, one[0]) == 0, "no swap");
			tstexpect(check_stack(b, one[0]) == 0, "no swap");
			stack_destroy(&a);
			stack_destroy(&b);
		}
		tstsection("happy swap")
		{
			a = stack_init(odds, 3, 3);
			b = stack_init(evens, 3, 3);
			capture_begin(&saved_out, pfd);
			ss(a, b, &ctx);
			capture_end(saved_out, pfd, out, sizeof(out));
			tstexpect(strcmp(out, "ss\n") == 0, "prints ss");
			tstexpect(check_stack(a, odds[1], odds[0], odds[2]) == 0,
				"swap correct");
			tstexpect(check_stack(b, evens[1], evens[0], evens[2]) == 0,
				"swap correct");
			stack_destroy(&a);
			stack_destroy(&b);
		}
	}
	tstcase("context output")
	{
		tstsection("routes to the context fd")
		{
			int		rp[2];
			char	buf[16];
			ssize_t	n;

			a = stack_init(odds, 3, 3);
			pipe(rp);
			ctx.fd = rp[1];
			capture_begin(&saved_out, pfd);
			sa(a, &ctx);
			capture_end(saved_out, pfd, out, sizeof(out));
			close(rp[1]);
			n = read(rp[0], buf, sizeof(buf) - 1);
			close(rp[0]);
			if (n > 0)
				buf[n] = '\0';
			else
				buf[0] = '\0';
			tstexpect(strcmp(out, "") == 0, "leaked to stdout: %s", out);
			tstexpect(strcmp(buf, "sa\n") == 0, "routed %s", buf);
			tstexpect(check_stack(a, odds[1], odds[0], odds[2]) == 0,
				"swap correct");
			stack_destroy(&a);
			ctx.fd = STDOUT_FILENO;
		}
		tstsection("silent context still mutates")
		{
			a = stack_init(odds, 3, 3);
			ctx.fd = -1;
			capture_begin(&saved_out, pfd);
			sa(a, &ctx);
			capture_end(saved_out, pfd, out, sizeof(out));
			tstexpect(strcmp(out, "") == 0, "silent wrote: %s", out);
			tstexpect(check_stack(a, odds[1], odds[0], odds[2]) == 0,
				"swap correct");
			stack_destroy(&a);
			ctx.fd = STDOUT_FILENO;
		}
		tstsection("null context is silent")
		{
			a = stack_init(odds, 3, 3);
			capture_begin(&saved_out, pfd);
			sa(a, NULL);
			capture_end(saved_out, pfd, out, sizeof(out));
			tstexpect(strcmp(out, "") == 0, "null context wrote: %s", out);
			tstexpect(check_stack(a, odds[1], odds[0], odds[2]) == 0,
				"swap correct");
			stack_destroy(&a);
		}
		tstsection("combined op emits once")
		{
			int		rp[2];
			char	buf[16];
			ssize_t	n;

			a = stack_init(odds, 3, 3);
			b = stack_init(evens, 3, 3);
			pipe(rp);
			ctx.fd = rp[1];
			ss(a, b, &ctx);
			close(rp[1]);
			n = read(rp[0], buf, sizeof(buf) - 1);
			close(rp[0]);
			if (n > 0)
				buf[n] = '\0';
			else
				buf[0] = '\0';
			tstexpect(strcmp(buf, "ss\n") == 0, "combined emitted %s", buf);
			stack_destroy(&a);
			stack_destroy(&b);
			ctx.fd = STDOUT_FILENO;
		}
	}
}
