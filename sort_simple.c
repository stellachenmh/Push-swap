/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slau <slau@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 12:00:00 by slau             #+#    #+#             */
/*   Updated: 2026/11/04 12:00:00 by slau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_simple(t_stack *a, t_stack *b, t_out *out)
{
	size_t	min_idx;

	if (!a || !b || rank_ints(a) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	if (a->size == 2)
	{
		if (a->data[0] > a->data[1])
			sa(a, out);
		return (EXIT_SUCCESS);
	}
	while (a->size > 3)
	{
		min_idx = find_min_idx(a);
		move_idx_to_top(a, min_idx, 'a', out);
		pb(a, b, out);
	}
	sort_three_ints(a, out);
	while (b->size > 0)
		pa(a, b, out);
	return (EXIT_SUCCESS);
}
