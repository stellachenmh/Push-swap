/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium.c                                      :+:      :+:    :+   */
/*                                                    +:+ +:+         +:+     */
/*   By: slau <slau@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 12:00:00 by slau             #+#    #+#             */
/*   Updated: 2026/10/15 12:00:00 by slau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @details Range-based sorting strategy. Start with a range of 0 to sqrt n, 
 * where n is the no of elements. Inspect stack a element by element. If the 
 * element falls within the range, push it to stack b and add 1 to the top 
 * and bottom of range. Before pushing, check if element is above or below the 
 * range midpoint, ie (range bottom + range top) / 2. If below, rotate stack B 
 * to push smaller nos towards stack B's bottom. If above, leave it at the top. 
 * When stack a is empty, rank the ints in stack B. Then push them back to 
 * stack A starting from the maximum.
 */

void	sort_medium(t_stack *a, t_stack *b)
{
	(void)a;
	(void)b;
}
