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

int	main(int argc, char **argv)
{
	int		size;
	t_stack	*a;
	t_stack	*b;
	t_out	out;
	int		tmp[1000];
	int		empty[] = {};

	for (int i = 1; i < argc; i++)
	{
		tmp[i - 1] = ft_atoi(argv[i]);
	}
	size = argc - 1;
	a = stack_init(tmp, size, size);
	b = stack_init(empty, 0, size);
	ft_bzero(&out, sizeof(out));
	out.fd = STDOUT_FILENO;
	sort_complex(a, b, &out);
	return (EXIT_SUCCESS);
}
