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

#include "push_swap.h"
#include <unistd.h>
#include "libft/libft.h"

static int	error_exit(t_stack *a, t_stack *b)
{
	stack_destroy(&a);
	stack_destroy(&b);
	ft_putstr_fd("Error\n", STDERR_FILENO);
	return (EXIT_FAILURE);
}

static void	decide_sort(t_stack *a, t_metadata *metadata)
{
	metadata->disorder = compute_disorder(a);
	if (metadata->strategy == ADAPTIVE)
	{
		if (metadata->disorder < 0.2)
			metadata->strategy_used = SIMPLE;
		else if (metadata->disorder >= 0.5)
			metadata->strategy_used = COMPLEX;
		else
			metadata->strategy_used = MEDIUM;
	}
	else
		metadata->strategy_used = metadata->strategy;
}

static int	do_sort(t_stack *a, t_stack *b, t_metadata *metadata, t_out *out)
{
	if (a->size <= 5)
	{
		if (rank_ints(a))
			return (EXIT_FAILURE);
		sort_small_stk(a, b, out, metadata);
	}
	else if (metadata->strategy_used == SIMPLE)
		return (sort_simple(a, b, out, metadata));
	else if (metadata->strategy_used == MEDIUM)
		return (sort_medium(a, b, out));
	else if (metadata->strategy_used == COMPLEX)
		return (sort_complex(a, b, out));
	return (EXIT_SUCCESS);
}

static int	sort_and_report(t_stack *a, t_stack *b, t_metadata *metadata)
{
	t_out	out;
	int		status;

	ft_bzero(&out, sizeof(out));
	out.fd = STDOUT_FILENO;
	decide_sort(a, metadata);
	status = EXIT_SUCCESS;
	if (metadata->disorder != 0)
		status = do_sort(a, b, metadata, &out);
	if (metadata->bench && status == EXIT_SUCCESS)
		bench_report(STDERR_FILENO, metadata, &out);
	return (status);
}

int	main(int argc, char **argv)
{
	t_stack		*a;
	t_stack		*b;
	int			*data;
	int			empty[1];
	t_metadata	metadata;

	empty[0] = 0;
	if (argc == 1)
		return (EXIT_FAILURE);
	ft_bzero(&metadata, sizeof(metadata));
	data = parse_args(argc, argv, &metadata);
	if (!data || has_duplicates(data, metadata.count))
	{
		free(data);
		return (error_exit(NULL, NULL));
	}
	a = stack_init(data, metadata.count, metadata.count);
	b = stack_init(empty, 0, metadata.count);
	free(data);
	if (!a || !b || sort_and_report(a, b, &metadata))
		return (error_exit(a, b));
	stack_destroy(&a);
	stack_destroy(&b);
	return (EXIT_SUCCESS);
}
