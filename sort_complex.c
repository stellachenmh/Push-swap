/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_complex.c                                     :+:      :+:    :+   */
/*                                                    +:+ +:+         +:+     */
/*   By: slau <slau@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 12:00:00 by slau             #+#    #+#             */
/*   Updated: 2026/10/15 12:00:00 by slau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static size_t	num_bits(size_t num)
{
	size_t	i;
	size_t	total;

	i = 0;
	total = 1;
	while (total < num)
	{
		total *= 2;
		i++;
	}
	return (i);
}

int	is_top_stack_k_bit_zero(t_stack *stack, size_t k)
{
	int	top;
	int	shifted;
	int	masked;

	top = stack->data[0];
	shifted = top >> k;
	masked = shifted & 1;
	return (masked == 0);
}

void	sort_complex(t_stack *a, t_stack *b)
{
	size_t	i;
	size_t	num_elements;
	size_t	num_pass;
	size_t	k;

	rank_ints(a);
	k = 0;
	num_pass = num_bits(a->size);
	num_elements = a->size;
	while (k < num_pass)
	{
		i = 0;
		while (i < num_elements)
		{
			if (is_top_stack_k_bit_zero(a, k))
				pb(a, b);
			else
				ra(a);
			i++;
		}
		while (b->size > 0)
			pa(a, b);
		k++;
	}
}
