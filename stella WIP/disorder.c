/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelchen <stelchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 13:00:15 by stelchen          #+#    #+#             */
/*   Updated: 2026/10/19 18:48:51 by stelchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

#include <stdio.h>

/* 
t_stack 
capacity vs size...clear enough? curr size?
size_t instead of int? Would suggest 

*/



t_stack	*stack_init(int *arr, int capacity)
{
	int		i;
	t_stack	*stack;

	if (capacity <= 0)
		return (NULL);
	stack = (t_stack *)malloc(sizeof(t_stack *));
	if (stack == NULL)
		return (NULL);
	stack->data = (int *)malloc(capacity * sizeof(*arr));
	if (stack->data == NULL)
	{
		free(stack);
		return (NULL);
	}
	i = 0;
	while (i < capacity)
	{
		stack->data[i] = arr[i];
		i++;
	}
	stack->size = capacity;
	stack->capacity = capacity;
	return (stack);
}


// KIV float return value
float compute_disorder(t_stack *stack_a)
{
	int		i; // Must match type of 'size'
	int		j;
	int		mistakes; // KIV size_t?
	int		total_pairs;

	if (stack_a->size == 1)
		return (0);
	i = 0;
	mistakes = 0;
	total_pairs = (stack_a->size - 1); // Check against their suggested imple? 
	while (i < stack_a->size - 1)
	{
		j = i + 1;
		if (j < stack_a->size)
			if (stack_a->data[i] > stack_a->data[j])
				mistakes++;
		i++;
	}
	printf("Mistakes %f, total pairs %f\n", (float)mistakes, (float)total_pairs); 
	return ((float)mistakes / (float)total_pairs); 
}


// Compile w stack init to test

#include <assert.h>
#include <limits.h>


int main(void)
{
	int arr_single[1] = {5};
	int arr_sorted[] = {INT_MIN, -6, -4, 0, 15};
	int arr_rev_sorted[] = {INT_MAX, 9999, 405};
	int arr_onethird_sorted[] = {2, 1, 3, 4};
	
	t_stack *single = stack_init(arr_single, 1);
	t_stack *sorted = stack_init(arr_sorted, 5);
	t_stack *rev_sorted = stack_init(arr_rev_sorted, 3);
	t_stack *onethird_sorted = stack_init(arr_onethird_sorted, 4);

	assert(compute_disorder(single) == 0);
	assert(compute_disorder(sorted) == 0);
	assert(compute_disorder(rev_sorted) == 1);
	assert(compute_disorder(onethird_sorted) == (1.0f/3.0f));
}




/* My notes
Total pairs
For 2 numbers, 1 pair
3 numbers, 2 pairs
4 numbers, 3. Just size - 1? Should be 
Everything with a number after it has a pair. size - 1

*/