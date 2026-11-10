/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strategy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slau <slau@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 12:00:00 by slau             #+#    #+#             */
/*   Updated: 2026/11/04 12:00:00 by slau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	select_strategy(t_stack *a, t_stack *b, int strategy, t_out *out)
{
	if (strategy == SIMPLE)
		return (sort_simple(a, b, out));
	if (strategy == MEDIUM)
		return (sort_medium(a, b, out));
	if (strategy == COMPLEX)
		return (sort_complex(a, b, out));
	if (strategy == ADAPTIVE)
		return (sort_adaptive(a, b, out));
	return (EXIT_FAILURE);
}
