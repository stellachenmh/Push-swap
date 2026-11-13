/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_complex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slau <slau@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 12:00:00 by slau             #+#    #+#             */
/*   Updated: 2026/11/04 12:00:00 by slau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

static void	complex_pass(t_stack *a, t_stack *b, t_out *out, size_t k)
{
	size_t	i;
	size_t	num_elements;

	num_elements = a->size;
	i = 0;
	while (i < num_elements)
	{
		if (is_top_stack_k_bit_zero(a, k))
			pb(a, b, out);
		else
			ra(a, out);
		i++;
	}
	while (b->size > 0)
		pa(a, b, out);
}

int	sort_complex(t_stack *a, t_stack *b, t_out *out)
{
	size_t	k;
	size_t	num_pass;

	if (rank_ints(a))
		return (EXIT_FAILURE);
	k = 0;
	num_pass = num_bits(a->size);
	while (k < num_pass)
	{
		complex_pass(a, b, out, k);
		k++;
	}
	return (EXIT_SUCCESS);
}
