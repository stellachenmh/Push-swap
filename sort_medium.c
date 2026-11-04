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

int	find_sqrt(int n);

#include <stdio.h>

void	sort_medium(t_stack *a, t_stack *b)
{
	size_t	max_idx; // KIV type
	int	pivot;
	size_t	range; // KIV type
	
	printf("sq root of a %i, times 1.4 %f\n", find_sqrt(a->size), 1.4 * find_sqrt(a->size));
	range = 1.4 * find_sqrt(a->size); // Previously check if size is <= 0? KIV 1.4. How will it work if n = 1?
	pivot = range / 2; // KIV pivot as this vs starting from 0
	printf("Range %zu, pivot %i\n", range, pivot);
	rank_ints(a);
	printf("Rank ints success\n");
	for (size_t i = 0; i < a->size; i++)
		printf("%i\n", a->data[i]);
	while (a->size > 0) // Check if a's size is 1? Or 2, or 3... Some checking for small arrays
	{
		if (a->data[0] <= pivot)
		{
			pb(a, b);
			rb(b);
			if (pivot < (int)(a->capacity - 1)) // KIV 3 casts
				pivot++; // KIV pivot choice
		}
		else if (a->data[0] <= (int)(pivot + range)) // What is the limit to pivot and range increasing?
		{
			pb(a, b);
			if (pivot < (int)(a->capacity - 1))
				pivot++;
		}
		else
			ra(a);
	}
	// Should the above stop when it reaches 3 ints? But no guarantee that those are the largest 3 ints
	// Push back phase
	// Find the max in b, push to a. Repeat. Very similar to sort simple's bring top pb
	while (b->size > 0)
	{
		max_idx = find_max_idx(b);
		move_idx_to_top(b, max_idx, 'b');
		pa(a, b);
	}
	return ;
}

int	find_sqrt(int n) // KIV static
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
Changing start of pivot to 0 didn't fix the seg fault
My push swap.h doesn't need printf??? 
The pivot should be capped at CAPACITY, not size!


*/