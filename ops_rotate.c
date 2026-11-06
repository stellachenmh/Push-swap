/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slau <slau@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 12:00:00 by slau             #+#    #+#             */
/*   Updated: 2026/11/04 12:00:00 by slau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/** @file ops_rotate.c
 * @brief Stack rotate operations for push_swap.
 *
 * Provides ra, rb, and rr: shift up all elements of a stack by one, so the
 * first element becomes the last one. Per the project spec, rotating an
 * empty stack is a no-op. Each operation emits its name to @p out once.
 */

#include "push_swap.h"

/**
 * @brief Shifts up all elements of @p stack by one position.
 *
 * The element at index 0 moves to the last index. Does nothing if the stack
 * is empty. The caller must pass a non-NULL stack.
 *
 * @param stack stack to rotate
 */
static void	rotate(t_stack *stack)
{
	size_t	i;
	int		top;

	if (stack->size == 0)
	{
		return ;
	}
	top = stack->data[0];
	i = 0;
	while (i < stack->size - 1)
	{
		stack->data[i] = stack->data[i + 1];
		i++;
	}
	stack->data[i] = top;
}

/**
 * @brief Rotates stack @p a: shifts up all elements by one, first becomes last.
 *
 * Per the project spec: "Shift up all elements of stack a by one. The first
 * element becomes the last one."
 *
 * @param a   stack to rotate, NULL is ignored
 * @param out output context, NULL is silent
 */
void	ra(t_stack *a, t_out *out)
{
	if (a == NULL)
	{
		return ;
	}
	rotate(a);
	op_emit(out, OP_RA, "ra\n");
}

/**
 * @brief Rotates stack @p b: shifts up all elements by one, first becomes last.
 *
 * Per the project spec: "Shift up all elements of stack b by one. The first
 * element becomes the last one."
 *
 * @param b   stack to rotate, NULL is ignored
 * @param out output context, NULL is silent
 */
void	rb(t_stack *b, t_out *out)
{
	if (b == NULL)
	{
		return ;
	}
	rotate(b);
	op_emit(out, OP_RB, "rb\n");
}

/**
 * @brief Rotates both stacks @p a and @p b at the same time.
 *
 * Per the project spec: "ra and rb at the same time." Emits "rr" to @p out
 * exactly once.
 *
 * @param a   first stack to rotate, NULL is ignored
 * @param b   second stack to rotate, NULL is ignored
 * @param out output context, NULL is silent
 */
void	rr(t_stack *a, t_stack *b, t_out *out)
{
	if (a == NULL || b == NULL)
	{
		return ;
	}
	rotate(a);
	rotate(b);
	op_emit(out, OP_RR, "rr\n");
}
