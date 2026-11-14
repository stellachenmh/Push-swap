/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_report.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slau <slau@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 12:00:00 by slau             #+#    #+#             */
/*   Updated: 2026/11/10 12:00:00 by slau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/** @file bench_report.c
 * @brief Formats the disorder and strategy header of the --bench report.
 *
 * The caller decides whether benchmarking is enabled and where the report
 * goes; production passes STDERR_FILENO. Keeping the fd in the interface lets
 * tests capture the report through a pipe without redirecting stdout.
 */

#include "libft/libft.h"
#include "push_swap.h"

/**
 * @brief Writes @p n as exactly two digits, zero-padded.
 */
static void	put_two_digits(unsigned int n, int fd)
{
	if (n < 10)
		ft_putchar_fd('0', fd);
	ft_putnbr_fd((int)n, fd);
}

/**
 * @brief Writes the disorder as a percentage with two decimals.
 *
 * Floats are rounded to hundredths and printed with integer helpers because
 * the project's ft_printf supports neither %f nor a destination fd.
 */
static void	put_disorder(float disorder, int fd)
{
	unsigned int	hundredths;

	hundredths = (unsigned int)(disorder * 10000.0f + 0.5f);
	ft_putstr_fd("[bench] disorder: ", fd);
	ft_putnbr_fd((int)(hundredths / 100), fd);
	ft_putchar_fd('.', fd);
	put_two_digits(hundredths % 100, fd);
	ft_putstr_fd("%\n", fd);
}

/**
 * @brief Writes the requested strategy and the complexity class that ran.
 *
 * Adaptive runs a sub-strategy chosen from the disorder, so its class comes
 * from @c strategy_used. An unset or invalid value falls back to the worst
 * case rather than printing a class the run did not use.
 */
static void	put_strategy(t_metadata *meta, int fd)
{
	int	used;

	used = meta->strategy;
	ft_putstr_fd("[bench] strategy: ", fd);
	if (used == ADAPTIVE)
	{
		ft_putstr_fd("Adaptive / ", fd);
		used = meta->strategy_used;
		if (used < SIMPLE || used > COMPLEX)
			used = COMPLEX;
	}
	else if (used == SIMPLE)
		ft_putstr_fd("Simple / ", fd);
	else if (used == MEDIUM)
		ft_putstr_fd("Medium / ", fd);
	else
		ft_putstr_fd("Complex / ", fd);
	if (used == SIMPLE)
		ft_putstr_fd("O(n^2)\n", fd);
	else if (used == MEDIUM)
		ft_putstr_fd("O(n*sqrt(n))\n", fd);
	else
		ft_putstr_fd("O(n log n)\n", fd);
}

/**
 * @brief Writes the benchmark report to @p fd.
 *
 * The caller gates this on @c meta->bench (typically @c if (meta->bench)) and
 * passes STDERR_FILENO in production. Printing is skipped for a negative fd
 * or a NULL argument, mirroring the silent-context rule used by op_emit.
 *
 * @param fd   destination file descriptor
 * @param meta benchmark configuration and measured metrics
 * @param out  operation counters
 */
void	bench_report(int fd, t_metadata *meta, t_out *out)
{
	if (fd < 0 || meta == NULL || out == NULL)
		return ;
	put_disorder(meta->disorder, fd);
	put_strategy(meta, fd);
	bench_counts(fd, out);
}

#include <stdio.h>
void	count_report(int fd, t_out *out)
{
	if (fd < 0 || out == NULL)
		return ;
	bench_counts(fd, out);
	printf("count report");
}