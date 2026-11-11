/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simonlau <simonlau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 12:00:00 by slau              #+#    #+#             */
/*   Updated: 2026/11/11 07:59:21 by simonlau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @details Range-based sorting strategy. First rank the integers, then move
 * them to B in progressively advancing ranges. Restore values from largest to
 * smallest after A has been emptied.
 * @remark The push and extraction phases each use O(n sqrt(n)) operations.
 */
static int	find_sqrt(int n);
static void	move_chunks(t_stack *a, t_stack *b, size_t range, t_out *out);
static void	push_back_max(t_stack *a, t_stack *b, t_out *out);

int	sort_medium(t_stack *a, t_stack *b, t_out *out)
{
	size_t	range;

	if (!a || !b)
		return (EXIT_FAILURE);
	if (a->size <= 3)
		return (sort_simple(a, b, out));
	range = 1.4 * find_sqrt(a->size);
	if (rank_ints(a) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	move_chunks(a, b, range, out);
	push_back_max(a, b, out);
	return (EXIT_SUCCESS);
}

static void	move_chunks(t_stack *a, t_stack *b, size_t range, t_out *out)
{
	int	pivot;

	pivot = range / 2;
	while (a->size > 0)
	{
		if (a->data[0] <= pivot)
		{
			pb(a, b, out);
			rb(b, out);
			if (pivot < (int)(a->capacity - 1))
				pivot++;
		}
		else if (a->data[0] <= (int)(pivot + range))
		{
			pb(a, b, out);
			if (pivot < (int)(a->capacity - 1))
				pivot++;
		}
		else
			ra(a, out);
	}
}

static void	push_back_max(t_stack *a, t_stack *b, t_out *out)
{
	size_t	max_idx;

	while (b->size > 0)
	{
		max_idx = find_max_idx(b);
		move_idx_to_top(b, max_idx, 'b', out);
		pa(a, b, out);
	}
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
