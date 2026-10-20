#ifndef TEST_H
# define TEST_H

# include "libft/libft.h"
# include <unistd.h>

# define PIPE_READ_END 0
# define PIPE_WRITE_END 1

void	capture_begin(int *saved_out, int pfd[2]);

ssize_t	capture_end(int saved_out, int pfd[2], char *buf, size_t len);

#endif
