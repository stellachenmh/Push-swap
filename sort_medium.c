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
 * @details Range-based sorting strategy. First rank the ints in stack A.
 * Start with a range of 0 to sqrt n, where n is the no of elements. Inspect 
 * stack a element by element. 
 * If the element is <= the range lower bound, push to stack b and rotate
 * stack b so element goes to bottom. Increment range lower bound only.
 * If element is above lower bound but within range, push to stack b. Increment
 * range lower and upper bound. If element is higher than range, inspect next
 * element.
 * When stack A is empty, push ints back to stack A starting from maximum.

 *  
 * I coded a recursive fx to find sq root in Piscine...Hard code the values?
 * 
 */

void	sort_medium(t_stack *a, t_stack *b)
{
	
	
	
	(void)a;
	(void)b;
}
