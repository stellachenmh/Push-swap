/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelchen <stelchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 13:00:15 by stelchen          #+#    #+#             */
/*   Updated: 2026/10/21 18:57:16 by stelchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// KIV float return value
float compute_disorder(t_stack *stack_a)
{
	size_t	i;
	size_t	j;
	size_t	mistakes;
	size_t	total_pairs;

	if (stack_a->size == 1)
		return (0);
	i = 0;
	mistakes = 0;
	total_pairs = 0; 
	while (i < (stack_a->size - 1))
	{
		j = i + 1;
		while (j < stack_a->size) // subject pdf is likely wrong, it says while j < size - 1
		{
			total_pairs++;
			if (stack_a->data[i] > stack_a->data[j])
				mistakes++;
			j++;
		}
		i++;
	}
	// printf("Mistakes %f, total pairs %f\n", (float)mistakes, (float)total_pairs); // Remove later
	return ((float)mistakes / (float)total_pairs); 
}

/* My notes
'compute disorder' local vars must match stack's 'size' type

*/