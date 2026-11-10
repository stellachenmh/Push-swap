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

int	sort_medium(t_stack *a, t_stack *b, t_out *out)
{
	size_t	max_idx; // KIV type
	int	pivot;
	size_t	range; // KIV type
	
	// printf("sq root of a %i, times 1.4 %f\n", find_sqrt(a->size), 1.4 * find_sqrt(a->size));
	range = 1.4 * find_sqrt(a->size); // Previously check if size is <= 0? KIV 1.4. How will it work if n = 1?
	pivot = range / 2; // KIV pivot as this vs starting from 0
	// printf("Range %zu, pivot %i\n", range, pivot);
	if (!a || !b || rank_ints(a) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	// printf("Rank ints success\n");
	// for (size_t i = 0; i < a->size; i++)
	// 	printf("%i\n", a->data[i]);
	while (a->size > 0)
	{
		if (a->data[0] <= pivot)
		{
			pb(a, b, out);
			rb(b, out);
			if (pivot < (int)(a->capacity - 1)) // KIV 3 casts
				pivot++; // KIV pivot choice
		}
		else if (a->data[0] <= (int)(pivot + range)) // What is the limit to pivot and range increasing?
		{
			pb(a, b, out);
			if (pivot < (int)(a->capacity - 1))
				pivot++;
		}
		else
			ra(a, out);
	}
	while (b->size > 0)
	{
		max_idx = find_max_idx(b);
		move_idx_to_top(b, max_idx, 'b', out);
		pa(a, b, out);
	}
	return (EXIT_SUCCESS);
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

/*My notes
The pivot should be capped at CAPACITY, not size!

*/