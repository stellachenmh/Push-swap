/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+   */
/*                                                    +:+ +:+         +:+     */
/*   By: slau <slau@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 12:00:00 by slau             #+#    #+#             */
/*   Updated: 2026/10/15 12:00:00 by slau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief init the stack from the arr and capacity
 *
 * @param arr the int array to copy, cannot be null
 * @param size number of elements to copy from arr
 * @param capacity total allocated space for the stack
 * @return t_stack*
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

void	stack_destroy(t_stack **stack_ptr)
{
	if (stack_ptr == NULL || *stack_ptr == NULL)
	{
		return ;
	}
	free((*stack_ptr)->data);
	free(*stack_ptr);
	*stack_ptr = NULL;
}
