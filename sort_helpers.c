/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simonlau <simonlau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 12:00:00 by slau              #+#    #+#             */
/*   Updated: 2026/11/11 07:59:21 by simonlau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	find_min_idx(t_stack *stack)
{
	size_t	i;
	size_t	min_idx;

	i = 0;
	min_idx = 0;
	while (i < stack->size)
	{
		if (stack->data[i] < stack->data[min_idx])
			min_idx = i;
		i++;
	}
	return (min_idx);
}

static void	rotate_stack(t_stack *stack, char c, int reverse, t_out *out)
{
	if (reverse && c == 'a')
		rra(stack, out);
	else if (reverse && c == 'b')
		rrb(stack, out);
	else if (c == 'a')
		ra(stack, out);
	else if (c == 'b')
		rb(stack, out);
}

void	move_idx_to_top(t_stack *stack, size_t tgt_idx, char c, t_out *out)
{
	if (tgt_idx < (stack->size / 2))
	{
		while (tgt_idx > 0)
		{
			rotate_stack(stack, c, 0, out);
			tgt_idx--;
		}
	}
	else
	{
		while (tgt_idx < (stack->size - 1))
		{
			rotate_stack(stack, c, 1, out);
			tgt_idx++;
		}
		rotate_stack(stack, c, 1, out);
	}
}

static void	sort_three_min_top(t_stack *a, size_t max_idx, t_out *out)
{
	if (max_idx == 1)
	{
		rra(a, out);
		sa(a, out);
	}
}

void	sort_three_ints(t_stack *a, t_out *out)
{
	size_t	max_idx;
	size_t	min_idx;

	if (!a || a->size != 3)
		return ;
	max_idx = find_max_idx(a);
	min_idx = find_min_idx(a);
	if (min_idx == 0)
		sort_three_min_top(a, max_idx, out);
	else if (min_idx == 1 && max_idx == 2)
		sa(a, out);
	else if (min_idx == 1)
		ra(a, out);
	else if (max_idx == 1)
		rra(a, out);
	else if (max_idx == 0)
	{
		ra(a, out);
		sa(a, out);
	}
}
