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
 * @param arr the int array to copy
 * @param capacity size of the int arr, cannot be zero or negative
 * @return t_stack*
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
