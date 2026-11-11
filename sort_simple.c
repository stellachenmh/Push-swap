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
/**
 * @brief Max extraction sort. Change all ints to their ranks, find max rank,
 * rotate or reverse-rotate stack to bring it to top (depending on its location)
 * then push to stack b. Once stack reduced to a trivial size, sort using
 * an algorithm specifically for that no of elements, then push stack b's ints
 * back to stack a. Does not check if stack is already sorted.
 */

void	sort_simple(t_stack *a, t_stack *b, t_out *out, t_metadata metadata)
{
	size_t	min_idx;

	rank_ints(a); 
	while (a->size > 5)
	{
		min_idx = find_min_idx(a);
		move_idx_to_top(a, min_idx, 'a', out);
		pb(a, b, out);
	}
	sort_small_stk(a, b, out, metadata);
	while (b->size > 0)
		pa(a, b, out);
	return ;
}
