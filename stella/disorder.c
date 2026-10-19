/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelchen <stelchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 13:00:15 by stelchen          #+#    #+#             */
/*   Updated: 2026/10/19 13:20:16 by stelchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdargs.h> 

// KIV float
float compute_disorder(int capacity, ...) // KIV int capacity. Or size_t? 
{
	va_list ints;
	int		i; // Must match type of 'capacity'
	int		i_curr;
	int		i_next;
	int		mistakes; // KIV size_t?

	if (capacity < 2)
		return (-1); // KIV error value
	va_start(ints, capacity);
	i = 0;
	i_curr = va_arg(ints, int)
	
}