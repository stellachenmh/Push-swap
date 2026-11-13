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
