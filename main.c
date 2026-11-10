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
		if (metadata->disorder < 0.2)
			metadata->strategy_used = SIMPLE;
		else if (metadata->disorder >= 0.5)
			metadata->strategy_used = COMPLEX;
		else
			metadata->strategy_used = MEDIUM;
	else
		metadata->strategy_used = metadata->strategy;
}

static int	do_sort(t_stack *a, t_stack *b, t_metadata *metadata, t_out *out)
{
	return (select_strategy(a, b, metadata->strategy_used, out));
}

int	main(int argc, char **argv)
{
	int			size;
	t_stack		*a;
	t_stack		*b;
	int			*data;
	int			empty[] = {0};
	t_metadata	metadata;
	t_out		out;

	if (argc == 1)
		return (EXIT_SUCCESS);
	ft_bzero(&metadata, sizeof(metadata));
	size = 0;
	data = parse_args(argc, argv, &metadata, &size);
	if (!data)
		return (write_errmsg());
	if (has_duplicates(data, size))
	{
		free(data);
		return (write_errmsg());
	}
	a = stack_init(data, size, size);
	free(data);
	if (!a)
		return (write_errmsg());
	b = stack_init(empty, 0, size);
	if (!b)
	{
		stack_destroy(&a);
		return (write_errmsg());
	}
	decide_sort(a, &metadata);
	ft_bzero(&out, sizeof(out));
	out.fd = STDOUT_FILENO;
	if (metadata.disorder > 0
		&& do_sort(a, b, &metadata, &out) != EXIT_SUCCESS)
	{
		stack_destroy(&a);
		stack_destroy(&b);
		return (write_errmsg());
	}
	if (metadata.bench)
		bench_report(STDERR_FILENO, &metadata, &out);
	stack_destroy(&a);
	stack_destroy(&b);
	return (EXIT_SUCCESS);
}
