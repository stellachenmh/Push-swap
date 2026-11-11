/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simonlau <simonlau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 12:00:00 by slau              #+#    #+#             */
/*   Updated: 2026/11/11 07:59:21 by simonlau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

int	ft_min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

size_t	find_max_idx(t_stack *stack)
{
	size_t	i;
	size_t	max_idx;

	i = 0;
	max_idx = 0;
	while (i < stack->size)
	{
		if (stack->data[i] > stack->data[max_idx])
			max_idx = i;
		i++;
	}
	return (max_idx);
}
