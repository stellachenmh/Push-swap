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

int	main(int argc, char **argv)
{
	int		size;
	t_stack	*a;
	t_stack	*b;
	int		tmp[1000];
	int		empty[] = {};

	for (int i = 1; i < argc; i++)
	{
		tmp[i - 1] = ft_atoi(argv[i]);
	}
	size = argc - 1;
	a = stack_init(tmp, size, size);
	b = stack_init(empty, 0, size);
	sort_complex(a, b);
	return (EXIT_SUCCESS);
}
