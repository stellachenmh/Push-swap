/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slau <slau@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 12:00:00 by slau             #+#    #+#             */
/*   Updated: 2026/11/04 12:00:00 by slau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/** @file ops_swap.c
 * @brief Stack swap operations for push_swap.
 *
 * Provides sa, sb, and ss: swap the first two elements at the top of a stack.
 * Per the project spec, these do nothing if there is only one or no elements.
 * Each operation records itself and emits its name to @p out after mutating
 * the stack.
 */

#include "push_swap.h"

/**
 * @brief Swaps the first two elements of @p s in place.
 *
 * Does nothing if @p s has fewer than 2 elements. The caller must pass a
 * non-NULL stack.
 *
 * @param s stack whose top two elements are swapped
 */
static void	swap(t_stack *s)
{
	int	tmp;

	if (s->size < (size_t)2)
	{
		return ;
	}
	tmp = s->data[0];
	s->data[0] = s->data[1];
	s->data[1] = tmp;
}

/**
 * @brief Swaps the first two elements at the top of stack @p a.
 *
 * Per the project spec: "Swap the first two elements at the top of stack a.
 * Do nothing if there is only one or no elements." Emits "sa" to @p out.
 *
 * @param a   stack to modify, NULL is ignored
 * @param out output context, NULL is silent
 */
void	sa(t_stack *a, t_out *out)
{
	if (a == NULL)
	{
		return ;
	}
	swap(a);
	op_emit(out, OP_SA, "sa\n");
}

/**
 * @brief Swaps the first two elements at the top of stack @p b.
 *
 * Per the project spec: "Swap the first two elements at the top of stack b.
 * Do nothing if there is only one or no elements." Emits "sb" to @p out.
 *
 * @param b   stack to modify, NULL is ignored
 * @param out output context, NULL is silent
 */
void	sb(t_stack *b, t_out *out)
{
	if (b == NULL)
	{
		return ;
	}
	swap(b);
	op_emit(out, OP_SB, "sb\n");
}

/**
 * @brief Swaps the first two elements at the top of both stacks @p a and @p b.
 *
 * Per the project spec: "sa and sb at the same time." Emits "ss" to @p out
 * exactly once.
 *
 * @param a   first stack to modify, NULL is ignored
 * @param b   second stack to modify, NULL is ignored
 * @param out output context, NULL is silent
 */
void	ss(t_stack *a, t_stack *b, t_out *out)
{
	if (a == NULL || b == NULL)
	{
		return ;
	}
	swap(a);
	swap(b);
	op_emit(out, OP_SS, "ss\n");
}
