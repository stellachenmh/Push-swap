/** @file test.c
 * @brief Test utilities for push_swap unit tests.
 *
 * Provides helpers to capture stdout via a pipe and to compare a stack's
 * contents against a list of expected values.
 */

#include "../push_swap.h"
#include "test.h"
#include <stdarg.h>
#include <stdio.h>

/**
 * @brief Redirects stdout into a pipe for capture.
 *
 * Creates a pipe, duplicates the current STDOUT_FILENO, then points fd 1 at
 * the pipe's write end so subsequent writes (e.g. ft_putstr_fd) are captured.
 *
 * @param saved_out  output pointer storing the duplicated original stdout fd
 * @param pfd        pipe file descriptors array (size 2)
 */
void	capture_begin(int *saved_out, int pfd[2])
{
	pipe(pfd);
	*saved_out = dup(STDOUT_FILENO);
	dup2(pfd[PIPE_WRITE_END], STDOUT_FILENO);
	close(pfd[PIPE_WRITE_END]); /* stdout now holds the write end */
}

/**
 * @brief Restores stdout and reads captured output from the pipe.
 *
 * Flushes stdout, restores the original stdout fd, then reads the bytes the
 * operation wrote into the pipe into @p buf. The buffer is NUL-terminated.
 *
 * @param saved_out  original stdout fd captured by capture_begin
 * @param pfd        pipe file descriptors array (size 2)
 * @param buf        destination buffer for captured output
 * @param len        size of @p buf
 * @return number of bytes read, or -1 on error
 */
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

/**
 * @brief Compares a stack's contents against expected values.
 *
 * Iterates over s->data[0 .. s->size-1] and compares each element against the
 * variadic arguments in order.
 *
 * @param s          stack to inspect
 * @param ...        exactly s->size expected int values
 * @return index + 1 of the first mismatch, 0 if all correct,
	-1 on invalid input
 */
int	check_stack(t_stack *s, ...)
{
	va_list	ap;
	int		i;
	int		expected;

	if (s == NULL || s->size < 0 || s->capacity < s->size || s->data == NULL)
		return (-1);
	va_start(ap, s);
	i = 0;
	while (i < s->size)
	{
		expected = va_arg(ap, int);
		if (s->data[i] != expected)
		{
			va_end(ap);
			return (i + 1);
		}
		i++;
	}
	va_end(ap);
	if (i == s->size)
	{
		return (0);
	}
	return (-1);
}
