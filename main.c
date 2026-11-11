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

static int	write_errmsg(void)
{
	ft_putstr_fd("Error\n", STDOUT_FILENO);
	return (0);
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

static void	do_sort(t_stack *a, t_stack *b, t_metadata *metadata)
{
	t_out	out;

	ft_bzero(&out, sizeof(out));
	out.fd = STDOUT_FILENO;
	if (a->size <= 5)
	{
		rank_ints(a);
		sort_small_stk(a, b, &out, metadata);
	}
	else if (metadata->strategy_used == SIMPLE)
		sort_simple(a, b, &out, metadata);
	else if (metadata->strategy_used == MEDIUM)
		sort_medium(a, b, &out);
	else if (metadata->strategy_used == COMPLEX)
		sort_complex(a, b, &out);
}

int	main(int argc, char **argv)
{
	int			size;
	t_stack		*a;
	t_stack		*b;
	int			*data;
	int			empty[] = {0};
	t_metadata	metadata;

	if (argc == 1)
		return (EXIT_FAILURE);
	size = argc - 1;
	ft_bzero(&metadata, sizeof(metadata));
	data = parse_args(argc, argv, &metadata);
	if (!data || has_duplicates(data, size))
	{
		free(data);
		return (write_errmsg());
	}
	a = stack_init(data, size, size);
	b = stack_init(empty, 0, size);
	decide_sort(a, &metadata);
	if (metadata.disorder == 0)
		return (EXIT_SUCCESS);
	do_sort(a, b, &metadata);
	return (EXIT_SUCCESS);
}
