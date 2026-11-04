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

size_t	find_max_idx(t_stack *a);
static size_t	find_min_idx(t_stack *a);
void			sort_three_ints(t_stack *a); // KIV static

static void	rev_rot_stack(t_stack *stack, char c);



void	sort_simple(t_stack *a, t_stack *b)
{
	size_t	min_idx;

	// Check for stack size 2 or smaller. Centralise? Size 3 or smaller?
	// Centrally check if already sorted. For any size. Defensive vs DRY
	rank_ints(a); 
	while (a->size > 3)
	{
		min_idx = find_min_idx(a);
		move_idx_to_top(a, min_idx, 'a');
		pb(a, b);
	}
	sort_three_ints(a);
	while (b->size > 0)
		pa(a, b);
	return ;
}

// void	bring_top_pb(t_stack *a, t_stack *b, size_t tgt_idx)
// {
// 	if (tgt_idx < (a->size / 2))
// 	{
// 		while (tgt_idx > 0)
// 		{
// 			ra(a);
// 			tgt_idx--;
// 		}
// 		pb(a, b);
// 	}
// 	else
// 	{
// 		while (tgt_idx < (a->size - 1))
// 		{
// 			rra(a);
// 			tgt_idx++;
// 		}
// 		rra(a);
// 		tgt_idx = 0;
// 		pb(a, b);
// 	}
// 	return ;
// }


// Can be used for either stack. Try dispensing w helper rot and rev rot
void	move_idx_to_top(t_stack *stack, size_t tgt_idx, char c)
{
	if (tgt_idx < (stack->size / 2))
	{
		while (tgt_idx > 0)
		{
			if (c == 'a')
				ra(stack);
			else if (c == 'b')
				rb(stack);
			tgt_idx--;
		}
	}
	else
	{
		while (tgt_idx < (stack->size - 1))
		{
			rev_rot_stack(stack, c);
			tgt_idx++;
		}
		rev_rot_stack(stack, c);
	}
	return ;
}

void	rev_rot_stack(t_stack *stack, char c)
{
	if (c == 'a')
		rra(stack);
	else if (c == 'b')
		rrb(stack);
	return ;
}

void	sort_three_ints(t_stack *a) // KIV if this should be static
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


// #include <assert.h>
// #include <stdio.h>

// int main(void)
// {
// 	// Test sort three ints
// 	int arr132[] = {1, 3, 2};
// 	int arr213[] = {2, 1, 3};
// 	int arr231[] = {2, 3, 1};
// 	int arr312[] = {3, 1, 2};
// 	int arr321[] = {3, 2, 1};
// 	int arr123[] = {1, 2, 3};

// 	t_stack *a132 = stack_init(arr132, 3, 3);
// 	t_stack *a213 = stack_init(arr213, 3, 3);
// 	t_stack *a231 = stack_init(arr231, 3, 3);
// 	t_stack *a312 = stack_init(arr312, 3, 3);
// 	t_stack *a321 = stack_init(arr321, 3, 3);
// 	t_stack *a123 = stack_init(arr123, 3, 3);

// 	for (int i = 0; i < 3; i++)
// 	{
// 		printf("%i\n", a132->data[i]);
// 	}
// 	assert(compute_disorder(a132) != 0);
// 	assert(compute_disorder(a213) != 0);
// 	assert(compute_disorder(a231) != 0);
// 	assert(compute_disorder(a312) != 0);
// 	assert(compute_disorder(a321) != 0);
// 	assert(compute_disorder(a123) == 0);

// 	sort_three_ints(a132);
// 	sort_three_ints(a213);
// 	sort_three_ints(a231);
// 	sort_three_ints(a312);
// 	sort_three_ints(a321);

// 	for (int i = 0; i < 3; i++)
// 	{
// 		printf("%i\n", a132->data[i]);
// 	}

// 	assert(compute_disorder(a132) == 0);
// 	assert(compute_disorder(a213) == 0);
// 	assert(compute_disorder(a231) == 0);
// 	assert(compute_disorder(a312) == 0);
// 	assert(compute_disorder(a321) == 0);
// 	assert(compute_disorder(a123) == 0);
// 	printf("All sort three tests succeeded\n");
// }

/* what happened when I accidentally init with 1, 1?
Got 100 before and after? But after the disorder is 0? Why? 

To get the makefile to work, I commented out most of sort medium,
removed main.c from my folder and the Makefile, added 2 libs

		// Choose ra or rra
		// 4 elements, then 0 1 top half. 5 elements, 0 and 1. 2 either way.
		// < size / 2 works for even. For 5, < 2, takes first half.
*/