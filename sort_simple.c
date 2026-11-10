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
 * back to stack a.
 * 
 * Have a function for 3 ints. And 5. 2? 4?
 * Find max int, pb, then push back in order? KIV 'trivial size' first. Take 3
 */

static size_t	find_min_idx(t_stack *a);
static void		rev_rot_stack(t_stack *stack, char c, t_out *out);

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

void	rev_rot_stack(t_stack *stack, char c, t_out *out)
{
	if (c == 'a')
		rra(stack, out);
	else if (c == 'b')
		rrb(stack, out);
	return ;
}

void	sort_three_ints(t_stack *a, t_out *out) // KIV moving some helper fxs to utils
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

size_t find_max_idx(t_stack *stack)
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

static size_t find_min_idx(t_stack *stack)
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
