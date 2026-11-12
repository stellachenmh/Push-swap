/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_idx_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelchen <stelchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 12:02:19 by stelchen          #+#    #+#             */
/*   Updated: 2026/11/11 15:58:58 by stelchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rev_rot_stack(t_stack *stack, char c, t_out *out);

size_t	find_max_idx(t_stack *stack)
{
	size_t	i;
	size_t	max_idx;

	i = 0;
	max_idx = 0;
	if (stack->size == 1)
		return (max_idx);
	while (i < stack->size)
	{
		if (stack->data[i] > stack->data[max_idx])
			max_idx = i;
		i++;
	}
	return (max_idx);
}

size_t	find_min_idx(t_stack *stack)
{
	size_t	i;
	size_t	min_idx;

	i = 0;
	min_idx = 0;
	if (stack->size == 1)
		return (min_idx);
	while (i < stack->size)
	{
		if (stack->data[i] < stack->data[min_idx])
			min_idx = i;
		i++;
	}
	return (min_idx);
}

void	move_idx_to_top(t_stack *stack, size_t tgt_idx, char c, t_out *out)
{
	if (tgt_idx < (stack->size / 2))
	{
		while (tgt_idx > 0)
		{
			if (c == 'a')
				ra(stack, out);
			else if (c == 'b')
				rb(stack, out);
			tgt_idx--;
		}
	}
	else
	{
		while (tgt_idx < (stack->size - 1))
		{
			rev_rot_stack(stack, c, out);
			tgt_idx++;
		}
		rev_rot_stack(stack, c, out);
	}
	return ;
}

static void	rev_rot_stack(t_stack *stack, char c, t_out *out)
{
	if (c == 'a')
		rra(stack, out);
	else if (c == 'b')
		rrb(stack, out);
	return ;
}
