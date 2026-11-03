/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_simple.c                                      :+:      :+:    :+   */
/*                                                    +:+ +:+         +:+     */
/*   By: slau <slau@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 12:00:00 by slau             #+#    #+#             */
/*   Updated: 2026/10/15 12:00:00 by slau            ###   ########.fr       */
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

static	size_t find_max_idx(t_stack *a);
static size_t find_min_idx(t_stack *a);


// void	sort_simple(t_stack *a, t_stack *b)
// {
// 	size_t	i;
// 	size_t	max_idx;

// 	rank_ints(a); // Check for stack size 2 or smaller. Centralise? Size 3 or smaller?
// 					// Centrally check if already sorted. For any size. Defensive vs DRY
// 	i = 0;
// 	max_idx = 0;
// 	if (a->size > 3)
// 	{
// 		while (i < a->size)
// 		{

// 			i++;
// 		}
// 	}

// }

void	sort_three_ints(t_stack *a)
{
	size_t	max_idx;
	size_t	min_idx;

	if (!a || a->size != 3)
		return ;
	max_idx = find_max_idx(a);
	min_idx = find_min_idx(a);
	if (min_idx == 0 && max_idx == 1) // 1 3 2
	{
		rra(a);
		sa(a);
	}
	else if (min_idx == 1 && max_idx == 2) // 2 1 3
		sa(a);
	else if (max_idx == 1 && min_idx == 2) // 2 3 1
		rra(a);
	else if (max_idx == 0 && min_idx == 1) // 3 1 2
		ra(a);
	else if (max_idx == 0 && min_idx == 2) // 3 2 1
	{
		ra(a);
		sa(a);
	}
	return ;
}

static	size_t find_max_idx(t_stack *a)
{
	size_t	i;
	size_t	max_idx;

	i = 0;
	max_idx = 0;
	if (a->size == 1)
		return (max_idx);
	while (i < a->size)
	{
		if (a->data[i] > a->data[max_idx])
			max_idx = i;
		i++;
	}
	return (max_idx);
}

static size_t find_min_idx(t_stack *a)
{
	size_t	i;
	size_t	min_idx;

	i = 0;
	min_idx = 0;
	if (a->size == 1)
		return (min_idx);
	while (i < a->size)
	{
		if (a->data[i] < a->data[min_idx])
			min_idx = i;
		i++;
	}
	return (min_idx);
}

// Test find max/find min helpers? kIV

#include <assert.h>
#include <stdio.h>

int main(void)
{
	// Test sort three ints
	int arr132[] = {1, 3, 2};
	int arr213[] = {2, 1, 3};
	int arr231[] = {2, 3, 1};
	int arr312[] = {3, 1, 2};
	int arr321[] = {3, 2, 1};
	int arr123[] = {1, 2, 3};

	t_stack *a132 = stack_init(arr132, 3, 3);
	t_stack *a213 = stack_init(arr213, 3, 3);
	t_stack *a231 = stack_init(arr231, 3, 3);
	t_stack *a312 = stack_init(arr312, 3, 3);
	t_stack *a321 = stack_init(arr321, 3, 3);
	t_stack *a123 = stack_init(arr123, 3, 3);

	for (int i = 0; i < 3; i++)
	{
		printf("%i\n", a132->data[i]);
	}
	assert(compute_disorder(a132) != 0);
	assert(compute_disorder(a213) != 0);
	assert(compute_disorder(a231) != 0);
	assert(compute_disorder(a312) != 0);
	assert(compute_disorder(a321) != 0);
	assert(compute_disorder(a123) == 0);

	sort_three_ints(a132);
	sort_three_ints(a213);
	sort_three_ints(a231);
	sort_three_ints(a312);
	sort_three_ints(a321);

	for (int i = 0; i < 3; i++)
	{
		printf("%i\n", a132->data[i]);
	}

	assert(compute_disorder(a132) == 0);
	assert(compute_disorder(a213) == 0);
	assert(compute_disorder(a231) == 0);
	assert(compute_disorder(a312) == 0);
	assert(compute_disorder(a321) == 0);
	assert(compute_disorder(a123) == 0);
	printf("All sort three tests succeeded\n");
}

/* what happened when I accidentally init with 1, 1?
Got 100 before and after? But after the disorder is 0? Why? 

To get the makefile to work, I commented out most of sort medium,
removed main.c from my folder and the Makefile, added 2 libs
*/