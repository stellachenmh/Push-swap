/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelchen <stelchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 11:56:21 by stelchen          #+#    #+#             */
/*   Updated: 2026/11/12 22:09:59 by stelchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Sorts lists of 1-5 elements efficiently. Does not check if list
 * size is 0, left to caller (main). Does not check if list is already
 * sorted or convert list contents to rank - left to caller.
 */

void	sort_small_stk(t_stack *a, t_stack *b, t_out *out)
{
	size_t	min_idx;
	size_t	pa_count;

	pa_count = 0;
	if (a->size > 5 || a->size == 1)
		return ;
	while (a->size > 3)
	{
		min_idx = find_min_idx(a);
		move_idx_to_top(a, min_idx, 'a', out);
		pb(a, b, out);
		pa_count++;
	}
	if (a->size == 3)
		sort_three_ints(a, out);
	else if (a->size == 2 && a->data[0] > a->data[1])
		sa(a, out);
	while (pa_count > 0)
	{
		pa(a, b, out);
		pa_count--;
	}
	return ;
}

void	sort_three_ints(t_stack *a, t_out *out)
{
	size_t	max_idx;
	size_t	min_idx;

	if (!a || a->size != 3)
		return ;
	max_idx = find_max_idx(a);
	min_idx = find_min_idx(a);
	if (min_idx == 0 && max_idx == 1)
	{
		rra(a, out);
		sa(a, out);
	}
	else if (min_idx == 1 && max_idx == 2)
		sa(a, out);
	else if (max_idx == 1 && min_idx == 2)
		rra(a, out);
	else if (max_idx == 0 && min_idx == 1)
		ra(a, out);
	else if (max_idx == 0 && min_idx == 2)
	{
		ra(a, out);
		sa(a, out);
	}
	return ;
}
