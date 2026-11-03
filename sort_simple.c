/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_simple.c                                      :+:      :+:    :+   */
/*                                                    +:+ +:+         +:+     */
/*   By: slau <slau@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 12:00:00 by slau             #+#    #+#             */
/*   Updated: 2026/10/15 12:00:00 by slau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/**
 * @brief Max extraction sort. Change all ints to their ranks, find max rank,
 * rotate or reverse-rotate stack to bring it to top (depending on its location)
 * then push to stack b. Once stack reduced to a trivial size, sort using
 * an algorithm specifically for that no of elements, then push stack b's ints
 * back to stack a.
 * 
 * Have a function for 3 ints. And 5. 2? 4?
 * Find max int, pb, then push back in order? KIV 'trivial size' first. Take 3
 */

void	sort_simple(t_stack *a, t_stack *b)
{
	size_t	i;
	size_t	max_idx;

	rank_ints(a); // Check for stack size 2 or smaller. Centralise? Size 3 or smaller?
	i = 0;
	max_idx = 0;
	if (a->size > 3)
	{
		while (i < a->size)
		{

			i++;
		}
	}

}

