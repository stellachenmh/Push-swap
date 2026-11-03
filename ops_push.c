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
	size_t	i;
	int		top;

	if (b->size == 0 || a->size == a->capacity)
		return ;
	top = b->data[0];
	b->size--;
	i = 0;
	while (i < b->size)
	{
		b->data[i] = b->data[i + 1];
		i++;
	}
	i = a->size;
	while (i > 0)
	{
		a->data[i] = a->data[i - 1];
		i--;
	}
	a->data[0] = top;
	a->size++;
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
	size_t	i;
	int		top;

	if (a->size == 0 || b->size == b->capacity)
	{
		return ;
	}
	top = a->data[0];
	a->size--;
	i = 0;
	while (i < a->size)
	{
		a->data[i] = a->data[i + 1];
		i++;
	}
	i = b->size;
	while (i > 0)
	{
		b->data[i] = b->data[i - 1];
		i--;
	}
	b->data[0] = top;
	b->size++;
	ft_putstr_fd("pb\n", STDOUT_FILENO);
}
