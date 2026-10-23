/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rotate.c                                       :+:      :+:    :+   */
/*                                                    +:+ +:+         +:+     */
/*   By: slau <slau@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 12:00:00 by slau             #+#    #+#             */
/*   Updated: 2026/10/15 12:00:00 by slau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/** @file ops_rotate.c
 * @brief Stack rotate operations for push_swap.
 *
 * Provides ra, rb, and rr: shift up all elements of a stack by one, so the
 * first element becomes the last one. Per the project spec, rotating an
 * empty stack is a no-op. Each operation prints its name to stdout.
 */

#include "libft/libft.h"
#include "push_swap.h"
#include <unistd.h>

/**
 * @brief Shifts up all elements of @p stack by one position.
 *
 * The element at index 0 moves to the last index. Does nothing if the stack
 * is empty.
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
 * element becomes the last one." Prints "ra" to stdout.
 *
 * @param a stack to rotate
 */
void	ra(t_stack *a)
{
	rotate(a);
	ft_putstr_fd("ra\n", STDOUT_FILENO);
}

/**
 * @brief Rotates stack @p b: shifts up all elements by one, first becomes last.
 *
 * Per the project spec: "Shift up all elements of stack b by one. The first
 * element becomes the last one." Prints "rb" to stdout.
 *
 * @param b stack to rotate
 */
void	rb(t_stack *b)
{
	rotate(b);
	ft_putstr_fd("rb\n", STDOUT_FILENO);
}

/**
 * @brief Rotates both stacks @p a and @p b at the same time.
 *
 * Per the project spec: "ra and rb at the same time." Equivalent to calling
 * ra(a) then rb(b). Prints "rr" to stdout.
 *
 * @param a first stack to rotate
 * @param b second stack to rotate
 */
void	rr(t_stack *a, t_stack *b)
{
	rotate(a);
	rotate(b);
	ft_putstr_fd("rr\n", STDOUT_FILENO);
}
