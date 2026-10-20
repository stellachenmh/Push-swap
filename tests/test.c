#include <stdio.h>
#include "test.h"

void	capture_begin(int *saved_out, int pfd[2])
{
	pipe(pfd);
	*saved_out = dup(STDOUT_FILENO);
	dup2(pfd[PIPE_WRITE_END], STDOUT_FILENO);
	close(pfd[PIPE_WRITE_END]); /* stdout now holds the write end */
}

ssize_t	capture_end(int saved_out, int pfd[2], char *buf, size_t len)
{
	ssize_t	n;

	fflush(stdout);                 /* push anything buffered into the pipe */
	dup2(saved_out, STDOUT_FILENO); /* restore real stdout */
	close(saved_out);
	n = read(pfd[PIPE_READ_END], buf, len - 1); /* read what the op wrote */
	close(pfd[PIPE_READ_END]);
	if (n > 0)
		buf[n] = '\0';
	else
		buf[0] = '\0';
	return (n);
}
