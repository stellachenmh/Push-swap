/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_adaptive.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slau <slau@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 12:00:00 by slau             #+#    #+#             */
/*   Updated: 2026/11/04 12:00:00 by slau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_adaptive(t_stack *a, t_stack *b, t_out *out)
{
	float	disorder;

	if (!a || !b)
		return (EXIT_FAILURE);
	disorder = compute_disorder(a);
	if (disorder < 0.2f)
		return (select_strategy(a, b, SIMPLE, out));
	if (disorder >= 0.5f)
		return (select_strategy(a, b, COMPLEX, out));
	return (select_strategy(a, b, MEDIUM, out));
}
