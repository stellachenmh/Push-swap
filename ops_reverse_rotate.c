/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_reverse_rotate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slau <slau@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 12:00:00 by slau             #+#    #+#             */
/*   Updated: 2026/11/04 12:00:00 by slau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/** @file ops_reverse_rotate.c
 * @brief Stack reverse-rotate operations for push_swap.
 *
 * Provides rra, rrb, and rrr: shift down all elements of a stack by one, so
 * the last element becomes the first one. Per the project spec, reverse
 * rotating an empty stack is a no-op. Each operation emits its name to
 * @p out once.
 */

#include "push_swap.h"

/**
 * @brief Shifts down all elements of @p stack by one position.
 *
 * The element at the last index moves to index 0. Does nothing if the stack
 * is empty. The caller must pass a non-NULL stack.
 *
 * @param stack stack to reverse rotate
 */
static void	shift_down_stack(t_stack *stack)
{
	size_t	i;
	size_t	last_index;
	int		num;

	if (stack->size == 0)
	{
		return ;
	}
	i = 0;
	last_index = stack->size - 1;
	num = stack->data[last_index];
	while (i < last_index)
	{
		stack->data[last_index - i] = stack->data[last_index - i - 1];
		i++;
	}
	stack->data[0] = num;
}

/**
 * @brief Reverse rotates stack @p a: shifts down all elements by one,
 *        last becomes first.
 *
 * Per the project spec: "Shift down all elements of stack a by one. The last
 * element becomes the first one."
 *
 * @param a   stack to reverse rotate, NULL is ignored
 * @param out output context, NULL is silent
 */
void	rra(t_stack *a, t_out *out)
{
	if (a == NULL)
	{
		return ;
	}
	shift_down_stack(a);
	op_emit(out, "rra\n");
}

/**
 * @brief Reverse rotates stack @p b: shifts down all elements by one,
 *        last becomes first.
 *
 * Per the project spec: "Shift down all elements of stack b by one. The last
 * element becomes the first one."
 *
 * @param b   stack to reverse rotate, NULL is ignored
 * @param out output context, NULL is silent
 */
void	rrb(t_stack *b, t_out *out)
{
	if (b == NULL)
	{
		return ;
	}
	shift_down_stack(b);
	op_emit(out, "rrb\n");
}

/**
 * @brief Reverse rotates both stacks @p a and @p b at the same time.
 *
 * Per the project spec: "rra and rrb at the same time." Emits "rrr" to @p out
 * exactly once.
 *
 * @param a   first stack to reverse rotate, NULL is ignored
 * @param b   second stack to reverse rotate, NULL is ignored
 * @param out output context, NULL is silent
 */
void	rrr(t_stack *a, t_stack *b, t_out *out)
{
	if (a == NULL || b == NULL)
	{
		return ;
	}
	shift_down_stack(a);
	shift_down_stack(b);
	op_emit(out, "rrr\n");
}
