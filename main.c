/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+   */
/*                                                    +:+ +:+         +:+     */
/*   By: slau <slau@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 12:00:00 by slau             #+#    #+#             */
/*   Updated: 2026/10/15 12:00:00 by slau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"
#include <unistd.h>

static int	write_errmsg(void)
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	return (EXIT_FAILURE);
}

static void	decide_sort(t_stack *a, t_metadata *metadata)
{
	metadata->disorder = compute_disorder(a);
	if (metadata->strategy == ADAPTIVE)
		metadata->strategy_used = adaptive_strategy_for_disorder(
				metadata->disorder);
	else
		metadata->strategy_used = metadata->strategy;
}

static int	sort_and_report(t_stack *a, t_stack *b, t_metadata *metadata)
{
	t_out		out;

	decide_sort(a, metadata);
	ft_bzero(&out, sizeof(out));
	out.fd = STDOUT_FILENO;
	if (metadata->disorder > 0
		&& select_strategy(a, b, metadata->strategy_used, &out) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	if (metadata->bench)
		bench_report(STDERR_FILENO, metadata, &out);
	return (EXIT_SUCCESS);
}

static int	run_sort(int *data, int size, t_metadata *metadata)
{
	int		empty;
	t_stack	*a;
	t_stack	*b;

	empty = 0;
	a = stack_init(data, size, size);
	if (!a)
		return (EXIT_FAILURE);
	b = stack_init(&empty, 0, size);
	if (!b)
	{
		stack_destroy(&a);
		return (EXIT_FAILURE);
	}
	if (sort_and_report(a, b, metadata) != EXIT_SUCCESS)
	{
		stack_destroy(&a);
		stack_destroy(&b);
		return (EXIT_FAILURE);
	}
	stack_destroy(&a);
	stack_destroy(&b);
	return (EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	int			size;
	int			*data;
	t_metadata	metadata;

	if (argc == 1)
		return (EXIT_SUCCESS);
	ft_bzero(&metadata, sizeof(metadata));
	size = 0;
	data = parse_args(argc, argv, &metadata, &size);
	if (!data)
		return (write_errmsg());
	if (has_duplicates(data, size))
		return (free(data), write_errmsg());
	if (run_sort(data, size, &metadata) != EXIT_SUCCESS)
		return (free(data), write_errmsg());
	free(data);
	return (EXIT_SUCCESS);
}
