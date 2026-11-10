#include "../push_swap.h"
#include "test.h"
#include "tst.h"
#include <string.h>
#include <unistd.h>

/**
 * @brief Runs bench_report into a pipe and copies the captured bytes to @p buf.
 */
static void	run_report(t_metadata *meta, t_out *out, char *buf, size_t len)
{
	int		pfd[2];
	ssize_t	n;

	pipe(pfd);
	bench_report(pfd[PIPE_WRITE_END], meta, out);
	close(pfd[PIPE_WRITE_END]);
	n = read(pfd[PIPE_READ_END], buf, len - 1);
	close(pfd[PIPE_READ_END]);
	if (n > 0)
		buf[n] = '\0';
	else
		buf[0] = '\0';
}

tstsuite("Bench report")
{
	t_metadata	meta;
	t_out		out;
	char		buf[512];

	tstcase("formats the full report")
	{
		ft_bzero(&meta, sizeof(meta));
		ft_bzero(&out, sizeof(out));
		meta.bench = 1;
		meta.disorder = 0.4993f;
		meta.strategy = ADAPTIVE;
		meta.strategy_used = MEDIUM;
		out.count[OP_PA] = 500;
		out.count[OP_PB] = 500;
		out.count[OP_RA] = 4840;
		out.count[OP_RB] = 1098;
		out.count[OP_RRB] = 1059;
		run_report(&meta, &out, buf, sizeof(buf));
		tstexpect(strcmp(buf,
				"[bench] disorder: 49.93%\n"
				"[bench] strategy: Adaptive / O(n*sqrt(n))\n"
				"[bench] total_ops: 7997\n"
				"[bench] sa: 0 sb: 0 ss: 0 pa: 500 pb: 500\n"
				"[bench] ra: 4840 rb: 1098 rr: 0 rra: 0 rrb: 1059 rrr: 0\n")
			== 0, "got: %s", buf);
	}

	tstcase("rounds disorder to two decimals")
	{
		ft_bzero(&meta, sizeof(meta));
		ft_bzero(&out, sizeof(out));
		meta.strategy = COMPLEX;
		meta.disorder = 0.0f;
		run_report(&meta, &out, buf, sizeof(buf));
		tstexpect(strstr(buf, "[bench] disorder: 0.00%") != NULL,
			"got: %s", buf);
		meta.disorder = 0.2f;
		run_report(&meta, &out, buf, sizeof(buf));
		tstexpect(strstr(buf, "[bench] disorder: 20.00%") != NULL,
			"got: %s", buf);
		meta.disorder = 1.0f;
		run_report(&meta, &out, buf, sizeof(buf));
		tstexpect(strstr(buf, "[bench] disorder: 100.00%") != NULL,
			"got: %s", buf);
	}

	tstcase("labels forced strategies")
	{
		ft_bzero(&meta, sizeof(meta));
		ft_bzero(&out, sizeof(out));
		meta.disorder = 0.1f;
		meta.strategy = SIMPLE;
		run_report(&meta, &out, buf, sizeof(buf));
		tstexpect(strstr(buf, "Simple / O(n^2)") != NULL, "got: %s", buf);
		meta.strategy = MEDIUM;
		run_report(&meta, &out, buf, sizeof(buf));
		tstexpect(strstr(buf, "Medium / O(n*sqrt(n))") != NULL,
			"got: %s", buf);
		meta.strategy = COMPLEX;
		run_report(&meta, &out, buf, sizeof(buf));
		tstexpect(strstr(buf, "Complex / O(n log n)") != NULL, "got: %s", buf);
	}

	tstcase("labels the adaptive sub-strategy")
	{
		ft_bzero(&meta, sizeof(meta));
		ft_bzero(&out, sizeof(out));
		meta.strategy = ADAPTIVE;
		meta.strategy_used = SIMPLE;
		run_report(&meta, &out, buf, sizeof(buf));
		tstexpect(strstr(buf, "Adaptive / O(n^2)") != NULL, "got: %s", buf);
		meta.strategy_used = MEDIUM;
		run_report(&meta, &out, buf, sizeof(buf));
		tstexpect(strstr(buf, "Adaptive / O(n*sqrt(n))") != NULL,
			"got: %s", buf);
		meta.strategy_used = COMPLEX;
		run_report(&meta, &out, buf, sizeof(buf));
		tstexpect(strstr(buf, "Adaptive / O(n log n)") != NULL,
			"got: %s", buf);
	}

	tstcase("ignores invalid arguments")
	{
		ft_bzero(&meta, sizeof(meta));
		ft_bzero(&out, sizeof(out));
		bench_report(-1, &meta, &out);
		bench_report(STDERR_FILENO, NULL, &out);
		bench_report(STDERR_FILENO, &meta, NULL);
		tstexpect(1, "no crash on invalid arguments");
	}
}
