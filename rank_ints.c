/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rank_ints.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simonlau <simonlau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 15:25:18 by stelchen          #+#    #+#             */
/*   Updated: 2026/10/23 20:24:14 by simonlau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Takes a stack, ranks its integer values then replaces the stack's
 * data with the array of ranks. E.g. data {10, 30, 20} would be replaced
 * by {0, 2, 1}. Does not check if stack size = 0. Returns EXIT_FAILURE
 * on malloc failure.
 * @remark Need not cast the malloc pointer as local var is already int *
 */

int	rank_ints(t_stack *a)
{
	int		*rank_data;
	size_t	i;
	size_t	j;
	size_t	rank;

	rank_data = malloc((a->size) * sizeof(*(a->data)));
	if (!rank_data)
		return (1);
	i = 0;
	while (i < a->size)
	{
		j = 0;
		rank = 0;
		while (j < a->size)
		{
			if ((j != i) && (a->data[i] > a->data[j]))
				rank++;
			j++;
		}
		rank_data[i] = rank;
		i++;
	}
	free(a->data);
	a->data = rank_data;
	return (0);
}
