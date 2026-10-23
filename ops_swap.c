/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_swap.c                                         :+:      :+:    :+   */
/*                                                    +:+ +:+         +:+     */
/*   By: slau <slau@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 12:00:00 by slau             #+#    #+#             */
/*   Updated: 2026/10/15 12:00:00 by slau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/** @file ops_swap.c
 * @brief Stack swap operations for push_swap.
 *
 * Provides sa, sb, and ss: swap the first two elements at the top of a stack.
 * Per the project spec, these do nothing if there is only one or no elements.
 * Each operation prints its name to stdout after mutating the stack.
 */

#include "libft/libft.h"
#include "push_swap.h"
#include <unistd.h>

/**
 * @brief Swaps the first two elements of @p s in place.
 *
 * Does nothing if @p s is NULL or has fewer than 2 elements.
 *
 * @param s stack whose top two elements are swapped
 */
static void	swap(t_stack *s)
{
	int	tmp;

	if (s == NULL || s->size < (size_t)2)
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
 * Do nothing if there is only one or no elements." Prints "sa" to stdout.
 *
 * @param a stack to modify
 */
void	sa(t_stack *a)
{
	swap(a);
	ft_putstr_fd("sa\n", STDOUT_FILENO);
}

/**
 * @brief Swaps the first two elements at the top of stack @p b.
 *
 * Per the project spec: "Swap the first two elements at the top of stack b.
 * Do nothing if there is only one or no elements." Prints "sb" to stdout.
 *
 * @param b stack to modify
 */
void	sb(t_stack *b)
{
	swap(b);
	ft_putstr_fd("sb\n", STDOUT_FILENO);
}

/**
 * @brief Swaps the first two elements at the top of both stacks @p a and @p b.
 *
 * Per the project spec: "sa and sb at the same time." Equivalent to calling
 * sa(a) then sb(b). Prints "ss" to stdout.
 *
 * @param a first stack to modify
 * @param b second stack to modify
 */
void	ss(t_stack *a, t_stack *b)
{
	swap(a);
	swap(b);
	ft_putstr_fd("ss\n", STDOUT_FILENO);
}
