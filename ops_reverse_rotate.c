/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_reverse_rotate.c                               :+:      :+:    :+   */
/*                                                    +:+ +:+         +:+     */
/*   By: slau <slau@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 12:00:00 by slau             #+#    #+#             */
/*   Updated: 2026/10/15 12:00:00 by slau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/** @file ops_reverse_rotate.c
 * @brief Stack reverse-rotate operations for push_swap.
 *
 * Provides rra, rrb, and rrr: shift down all elements of a stack by one, so
 * the last element becomes the first one. Per the project spec, reverse
 * rotating an empty stack is a no-op. Each operation prints its name to stdout.
 */

#include "libft/libft.h"
#include "push_swap.h"
#include <unistd.h>

/**
 * @brief Shifts down all elements of @p stack by one position.
 *
 * The element at the last index moves to index 0. Does nothing if the stack
 * is empty.
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
	last becomes first.
 *
 * Per the project spec: "Shift down all elements of stack a by one. The last
 * element becomes the first one." Prints "rra" to stdout.
 *
 * @param a stack to reverse rotate
 */
void	rra(t_stack *a)
{
	shift_down_stack(a);
	ft_putstr_fd("rra\n", STDOUT_FILENO);
}

/**
 * @brief Reverse rotates stack @p b: shifts down all elements by one,
	last becomes first.
 *
 * Per the project spec: "Shift down all elements of stack b by one. The last
 * element becomes the first one." Prints "rrb" to stdout.
 *
 * @param b stack to reverse rotate
 */
void	rrb(t_stack *b)
{
	shift_down_stack(b);
	ft_putstr_fd("rrb\n", STDOUT_FILENO);
}

/**
 * @brief Reverse rotates both stacks @p a and @p b at the same time.
 *
 * Per the project spec: "rra and rrb at the same time." Equivalent to calling
 * rra(a) then rrb(b). Prints "rrr" to stdout.
 *
 * @param a first stack to reverse rotate
 * @param b second stack to reverse rotate
 */
void	rrr(t_stack *a, t_stack *b)
{
	shift_down_stack(a);
	shift_down_stack(b);
	ft_putstr_fd("rrr\n", STDOUT_FILENO);
}
