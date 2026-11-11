#include "../push_swap.h"
#include "test.h"
#include "tst.h"
#include <string.h>
#include <sys/wait.h>

static void	read_all(int fd, char *buf, size_t len)
{
	ssize_t	n;
	size_t	total;

	total = 0;
	if (len == 0)
		return ;
	while (total < len - 1
		&& (n = read(fd, buf + total, len - 1 - total)) > 0)
		total += (size_t)n;
	buf[total] = '\0';
}

static int	run_cli(char *const argv[], char *out, size_t out_len,
		char *err, size_t err_len)
{
	int		out_pipe[2];
	int		err_pipe[2];
	pid_t	pid;
	int		status;

	if (pipe(out_pipe) < 0 || pipe(err_pipe) < 0)
		return (-1);
	pid = fork();
	if (pid < 0)
		return (-1);
	if (pid == 0)
	{
		dup2(out_pipe[PIPE_WRITE_END], STDOUT_FILENO);
		dup2(err_pipe[PIPE_WRITE_END], STDERR_FILENO);
		close(out_pipe[PIPE_READ_END]);
		close(out_pipe[PIPE_WRITE_END]);
		close(err_pipe[PIPE_READ_END]);
		close(err_pipe[PIPE_WRITE_END]);
		execv("./push_swap", argv);
		_exit(127);
	}
	close(out_pipe[PIPE_WRITE_END]);
	close(err_pipe[PIPE_WRITE_END]);
	read_all(out_pipe[PIPE_READ_END], out, out_len);
	read_all(err_pipe[PIPE_READ_END], err, err_len);
	close(out_pipe[PIPE_READ_END]);
	close(err_pipe[PIPE_READ_END]);
	waitpid(pid, &status, 0);
	return (status);
}

tstsuite("push_swap CLI")
{
	char	out[4096];
	char	err[4096];

	tstcase("--bench reports to stderr after sorting")
	{
		char	*args[] = {"./push_swap", "--bench", "3", "1", "2", NULL};

		tstexpect(run_cli(args, out, sizeof(out), err, sizeof(err)) == 0);
		tstexpect(strstr(err, "[bench] disorder:") != NULL, "got: %s", err);
		tstexpect(strstr(err, "[bench] strategy:") != NULL, "got: %s", err);
		tstexpect(strstr(err, "[bench] total_ops:") != NULL, "got: %s", err);
		tstexpect(strstr(err, "[bench] sa:") != NULL, "got: %s", err);
		tstexpect(strstr(out, "[bench]") == NULL, "got: %s", out);
		tstexpect(out[0] != '\0', "operation stream is empty");
	}
	tstcase("--bench reports on already sorted input")
	{
		char	*args[] = {"./push_swap", "--bench", "1", "2", "3", NULL};

		tstexpect(run_cli(args, out, sizeof(out), err, sizeof(err)) == 0);
		tstexpect(strstr(err, "[bench] disorder: 0.00%") != NULL,
			"got: %s", err);
		tstexpect(strstr(err, "[bench] total_ops: 0") != NULL,
			"got: %s", err);
		tstexpect(out[0] == '\0', "sorted input should emit no operations");
	}
	tstcase("bench report is silent without --bench")
	{
		char	*args[] = {"./push_swap", "3", "1", "2", NULL};

		tstexpect(run_cli(args, out, sizeof(out), err, sizeof(err)) == 0);
		tstexpect(err[0] == '\0', "got: %s", err);
	}
	tstcase("flags may appear in either order")
	{
		char	*args[] = {"./push_swap", "--simple", "--bench", "3", "1",
				"2", NULL};

		tstexpect(run_cli(args, out, sizeof(out), err, sizeof(err)) == 0);
		tstexpect(strstr(err, "[bench] strategy: Simple") != NULL,
			"got: %s", err);
		tstexpect(out[0] != '\0', "operation stream is empty");
	}
	tstcase("invalid input reports to stderr and exits non-zero")
	{
		char	*nonnum[] = {"./push_swap", "1", "x", "2", NULL};
		char	*dupe[] = {"./push_swap", "1", "1", "2", NULL};
		int		status;

		status = run_cli(nonnum, out, sizeof(out), err, sizeof(err));
		tstexpect(WIFEXITED(status) && WEXITSTATUS(status) == EXIT_FAILURE);
		tstexpect(strcmp(err, "Error\n") == 0, "got: %s", err);
		tstexpect(out[0] == '\0', "got: %s", out);
		status = run_cli(dupe, out, sizeof(out), err, sizeof(err));
		tstexpect(WIFEXITED(status) && WEXITSTATUS(status) == EXIT_FAILURE);
		tstexpect(strcmp(err, "Error\n") == 0, "got: %s", err);
		tstexpect(out[0] == '\0', "got: %s", out);
	}
}
