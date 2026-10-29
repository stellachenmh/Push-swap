/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_push.c                                         :+:      :+:    :+   */
/*                                                    +:+ +:+         +:+     */
/*   By: slau <slau@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 12:00:00 by slau             #+#    #+#             */
/*   Updated: 2026/10/15 12:00:00 by slau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/** @file ops_push.c
 * @brief Stack push operations for push_swap.
 *
 * Provides pa and pb: push the top element from one stack onto the other.
 * Per the project spec, pa does nothing if stack b is empty; pb does nothing
 * if stack a is empty. Each operation prints its name to stdout.
 */

#include "libft/libft.h"
#include "push_swap.h"
#include <unistd.h>

/**
 * @brief Shifts all elements of @p stack down by one position to make room
 *        at index 0, then places @p num there and increments size.
 *
 * Does nothing if the stack is empty or already at capacity.
 *
 * @param stack target stack
 * @param num   value to insert at the top
 */
static void	shift_down_stack_to_add(t_stack *stack, int num)
{
	size_t	i;
	size_t	last;

	if (stack->size == stack->capacity)
	{
		return ;
	}
	i = 0;
	last = stack->size;
	while (i < last)
	{
		stack->data[last - i] = stack->data[last - i - 1];
		i++;
	}
	stack->data[0] = num;
	stack->size++;
}

/**
 * @brief Removes the top element (index 0) from @p stack by shifting all
 *        remaining elements up one position and decrementing size.
 *
 * Does nothing if the stack is empty.
 *
 * @param stack source stack
 */
static void	shift_up_stack_to_del(t_stack *stack)
{
	size_t	i;

	if (stack->size == 0)
	{
		return ;
	}
	stack->size--;
	i = 0;
	while (i < stack->size)
	{
		stack->data[i] = stack->data[i + 1];
		i++;
	}
}

/**
 * @brief Pushes the top element of stack @p b onto the top of stack @p a.
 *
 * Per the project spec: "Take the first element at the top of b and put it
 * at the top of a. Do nothing if b is empty." Prints "pa" to stdout.
 *
 * @param a destination stack
 * @param b source stack
 */
void	pa(t_stack *a, t_stack *b)
{
	int	top;

	if (b->size == 0 || a->size == a->capacity)
	{
		return ;
	}
	top = b->data[0];
	shift_up_stack_to_del(b);
	shift_down_stack_to_add(a, top);
	ft_putstr_fd("pa\n", STDOUT_FILENO);
}

/**
 * @brief Pushes the top element of stack @p a onto the top of stack @p b.
 *
 * Per the project spec: "Take the first element at the top of a and put it
 * at the top of b. Do nothing if a is empty." Prints "pb" to stdout.
 *
 * @param a source stack
 * @param b destination stack
 */
void	pb(t_stack *a, t_stack *b)
{
	int	top;

	if (a->size == 0 || b->size == b->capacity)
	{
		return ;
	}
	top = a->data[0];
	shift_up_stack_to_del(a);
	shift_down_stack_to_add(b, top);
	ft_putstr_fd("pb\n", STDOUT_FILENO);
}
