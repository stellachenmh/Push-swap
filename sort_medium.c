/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium.c                                      :+:      :+:    :+   */
/*                                                    +:+ +:+         +:+     */
/*   By: slau <slau@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 12:00:00 by slau             #+#    #+#             */
/*   Updated: 2026/10/15 12:00:00 by slau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @details Range-based sorting strategy. First rank the ints in stack A.
 * Start with a range of 0 to sqrt n, where n is the no of elements. Inspect 
 * stack a element by element. 
 * If the element is <= the range lower bound, push to stack b and rotate
 * stack b so element goes to bottom. Increment range lower bound only.
 * If element is above lower bound but within range, push to stack b. Increment
 * range lower and upper bound. If element is higher than range, inspect next
 * element.
 * When stack A is empty, push ints back to stack A starting from maximum.
 * 
 * @remark Time complexity of push phase and extraction phase both O n sqrt n
 */

static int	find_sqrt(int n);

static void	push_to_b(t_stack *a, t_stack *b, t_out *out, int pivot)
{
	size_t	range;

	range = 1.4 * find_sqrt(a->size);
	while (a->size > 0)
	{
		if (a->data[0] <= pivot)
		{
			pb(a, b, out);
			rb(b, out);
			pivot++;
		}
		else if (a->data[0] <= (int)(pivot + range))
		{
			pb(a, b, out);
			pivot++;
		}
		else
			ra(a, out);
	}
}

static void	pull_from_b(t_stack *a, t_stack *b, t_out *out)
{
	size_t	max_idx;

	while (b->size > 0)
	{
		max_idx = find_max_idx(b);
		move_idx_to_top(b, max_idx, 'b', out);
		pa(a, b, out);
	}
}

void	sort_medium(t_stack *a, t_stack *b, t_out *out)
{
	int		pivot;

	pivot = (1.4 * find_sqrt(a->size)) / 2;
	rank_ints(a);
	push_to_b(a, b, out, pivot);
	pull_from_b(a, b, out);
}

static int	find_sqrt(int n)
{
	int	sqrt;

	sqrt = 1;
	if (n <= 0)
		return (-1);
	while ((sqrt * sqrt) <= n)
		sqrt++;
	return (sqrt - 1);
}
