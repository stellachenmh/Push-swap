/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rank_ints.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelchen <stelchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 15:25:18 by stelchen          #+#    #+#             */
/*   Updated: 2026/10/22 21:33:29 by stelchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stddef.h>

#include <stdio.h>

/**
 * @brief Takes a stack, ranks its integer values then replaces the stack's
 * data with the array of ranks. E.g. data {10, 30, 20} would be replaced
 * by {0, 2, 1}. Does not check if stack size = 0. Returns EXIT_FAILURE
 * on malloc failure.
 * @remark Need not cast the malloc pointer as local var is already int *
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

	rank_data = malloc((a->size) * sizeof(*(a->data))); // Does this return ptr size or int size? Derefs. * vs -> priority?
	if (!rank_data)
		return (EXIT_FAILURE);
	i = 0;
	while (i < a->size)
	{
		j = 0;
		rank = 0;
		while (j < a->size)
		{
			if ((j != i) && (a->data[i] > a->data[j]))
				rank++;
			j++;
		}
		rank_data[i] = rank;
		i++;
	}
	free(a->data);
	a->data = rank_data;
	return (EXIT_SUCCESS);
}

int main(void)
{
	// Stack with disorder 1
	int input[] = {101, 98, -5, -553, -4234, -24111};
	
	t_stack *mystack = stack_init(input, 6, 6);
	rank_ints(mystack);
	for (int i = 0; i < mystack->size; i++)
		printf("%i", mystack->data[i]); // Expect 0, 2, 1
	
	// Single-element stack
	
}