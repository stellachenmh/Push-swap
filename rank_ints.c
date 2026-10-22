/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rank_ints.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelchen <stelchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 15:25:18 by stelchen          #+#    #+#             */
/*   Updated: 2026/10/22 16:39:35 by stelchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stddef.h>

#include <stdio.h>

/**
 * @brief Takes a stack, ranks its integer values then replaces the stack's
 * data with the array of ranks. E.g. data {10, 30, 20} would be replaced
 * by {0, 2, 1}. No-op for stack size 1.
 * To test: Output if stack size is 0 or 1. Check that stack data has been
 * replaced (differs from old data) but has the same disorder value.
 * 
 * void vs new stack...you need malloc anyway
 */

t_stack	*stack_init(int *arr, size_t size, size_t capacity)
{
	size_t	i;
	t_stack	*stack;

	if (capacity == 0 || arr == NULL || size > capacity)
		return (NULL);
	stack = (t_stack *)malloc(sizeof(*stack));
	if (stack == NULL)
		return (NULL);
	stack->data = (int *)malloc(capacity * sizeof(int));
	if (stack->data == NULL)
	{
		free(stack);
		return (NULL);
	}
	i = 0;
	while (i < size)
	{
		stack->data[i] = arr[i];
		i++;
	}
	stack->size = size;
	stack->capacity = capacity;
	return (stack);
}
 
void	rank_ints(t_stack *a)
{
	int		*rank_data;
	size_t	i;
	size_t	j;
	size_t	rank; // Type? Can't be -ve

	rank_data = malloc((a->size) * sizeof(*(a->data))); // Does this return ptr size or int size? Derefs. * vs -> priority? Do I need to cast the ptr fr malloc?
	if (!rank_data)
		return ; // No warning msg? 
	i = 0;
	while (i < (a->size - 1))
	{
		j = 0;
		rank = 0;
		while (j < (a->size - 1))
		{
			if ((j != i) && (a->data[i] > a->data[j]))
				rank++;
			j++;
		}
		rank_data[i] = rank;
		printf("Pos %zu's rank is %zu\n", i, rank);
		i++;
	}
	free(a->data);
	a->data = rank_data;
	return ;
}

int main(void)
{
	int input[] = {5, 7, 6};
	
	t_stack *mystack = stack_init(input, 3, 3);
	rank_ints(mystack);
	for (int i = 0; i < mystack->size; i++)
		printf("%i", mystack->data[i]); // Expect 0, 2, 1
		
}