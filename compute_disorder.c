/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_disorder.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simonlau <simonlau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 13:00:15 by stelchen          #+#    #+#             */
/*   Updated: 2026/11/11 07:59:21 by simonlau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

float	compute_disorder(t_stack *stack_a)
{
	size_t	i;
	size_t	j;
	size_t	mistakes;
	size_t	total_pairs;

	if (!stack_a || stack_a->size < 2)
		return (0);
	i = 0;
	mistakes = 0;
	total_pairs = 0;
	while (i < (stack_a->size - 1))
	{
		j = i + 1;
		while (j < stack_a->size)
		{
			total_pairs++;
			if (stack_a->data[i] > stack_a->data[j])
				mistakes++;
			j++;
		}
		i++;
	}
	return ((float)mistakes / (float)total_pairs);
}
