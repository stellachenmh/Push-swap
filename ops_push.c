/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slau <slau@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 12:00:00 by slau             #+#    #+#             */
/*   Updated: 2026/11/04 12:00:00 by slau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/** @file ops_push.c
 * @brief Stack push operations for push_swap.
 *
 * Provides pa and pb: push the top element from one stack onto the other.
 * Per the project spec, pa does nothing if stack b is empty; pb does nothing
 * if stack a is empty. A push that cannot happen emits nothing.
 */

#include "push_swap.h"

/**
 * @brief Shifts all elements of @p stack down by one position to make room
 *        at index 0, then places @p num there and increments size.
 *
 * Does nothing if the stack is already at capacity. The caller must pass a
 * non-NULL stack.
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
 * Does nothing if the stack is empty. The caller must pass a non-NULL stack.
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
 * at the top of a. Do nothing if b is empty." Blocked pushes emit nothing.
 *
 * @param a   destination stack, NULL is ignored
 * @param b   source stack, NULL is ignored
 * @param out output context, NULL is silent
 */
void	pa(t_stack *a, t_stack *b, t_out *out)
{
	int	top;

	if (a == NULL || b == NULL)
	{
		return ;
	}
	if (b->size == 0 || a->size == a->capacity)
	{
		return ;
	}
	top = b->data[0];
	shift_up_stack_to_del(b);
	shift_down_stack_to_add(a, top);
	op_emit(out, OP_PA, "pa\n");
}

/**
 * @brief Pushes the top element of stack @p a onto the top of stack @p b.
 *
 * Per the project spec: "Take the first element at the top of a and put it
 * at the top of b. Do nothing if a is empty." Blocked pushes emit nothing.
 *
 * @param a   source stack, NULL is ignored
 * @param b   destination stack, NULL is ignored
 * @param out output context, NULL is silent
 */
void	pb(t_stack *a, t_stack *b, t_out *out)
{
	int	top;

	if (a == NULL || b == NULL)
	{
		return ;
	}
	if (a->size == 0 || b->size == b->capacity)
	{
		return ;
	}
	top = a->data[0];
	shift_up_stack_to_del(a);
	shift_down_stack_to_add(b, top);
	op_emit(out, OP_PB, "pb\n");
}
