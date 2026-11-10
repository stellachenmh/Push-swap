/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_counts.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slau <slau@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 12:00:00 by slau             #+#    #+#             */
/*   Updated: 2026/11/10 12:00:00 by slau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/** @file bench_counts.c
 * @brief Formats the operation totals of the --bench report.
 *
 * Kept separate from bench_report.c so each file stays within the Norm's
 * five-function limit. The report's order follows the t_op enum.
 */

#include "libft/libft.h"
#include "push_swap.h"

/**
 * @brief Writes an unsigned decimal number to @p fd.
 */
static void	put_uint_fd(unsigned int n, int fd)
{
	if (n >= 10)
		put_uint_fd(n / 10, fd);
	ft_putchar_fd((char)('0' + n % 10), fd);
}

/**
 * @brief Maps an operation identifier to its name.
 */
static char	*op_name(int op)
{
	if (op == OP_SA)
		return ("sa");
	if (op == OP_SB)
		return ("sb");
	if (op == OP_SS)
		return ("ss");
	if (op == OP_PA)
		return ("pa");
	if (op == OP_PB)
		return ("pb");
	if (op == OP_RA)
		return ("ra");
	if (op == OP_RB)
		return ("rb");
	if (op == OP_RR)
		return ("rr");
	if (op == OP_RRA)
		return ("rra");
	if (op == OP_RRB)
		return ("rrb");
	return ("rrr");
}

/**
 * @brief Sums every operation counter.
 */
static unsigned int	total_ops(t_out *out)
{
	int				i;
	unsigned int	total;

	i = 0;
	total = 0;
	while (i < OP_COUNT)
	{
		total += out->count[i];
		i++;
	}
	return (total);
}

/**
 * @brief Writes one "name: count" pair.
 */
static void	put_pair(char *name, unsigned int n, int fd)
{
	ft_putstr_fd(name, fd);
	ft_putstr_fd(": ", fd);
	put_uint_fd(n, fd);
}

/**
 * @brief Writes total_ops and the eleven per-operation counters.
 *
 * The first five counters share a line, the six rotations share the next;
 * the newline and prefix switch happens after OP_PB.
 *
 * @param fd  destination file descriptor
 * @param out operation counters
 */
void	bench_counts(int fd, t_out *out)
{
	int	i;

	ft_putstr_fd("[bench] total_ops: ", fd);
	put_uint_fd(total_ops(out), fd);
	ft_putchar_fd('\n', fd);
	ft_putstr_fd("[bench] ", fd);
	i = 0;
	while (i < OP_COUNT)
	{
		if (i == OP_PB + 1)
			ft_putstr_fd("\n[bench] ", fd);
		else if (i > 0)
			ft_putchar_fd(' ', fd);
		put_pair(op_name(i), out->count[i], fd);
		i++;
	}
	ft_putchar_fd('\n', fd);
}
