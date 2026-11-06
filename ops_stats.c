/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_stats.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slau <slau@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 12:00:00 by slau             #+#    #+#             */
/*   Updated: 2026/11/05 12:00:00 by slau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/** @file ops_stats.c
 * @brief Per-operation counters for push_swap.
 *
 * Counts how many times each operation was applied. Counting is independent
 * of output: a silent context still records its operations.
 */

#include "push_swap.h"

/**
 * @brief Increments the counter for @p op.
 *
 * @param out context holding the counters, NULL is ignored
 * @param op  operation identifier, in range OP_SA..OP_RRR
 */
void	stats_record(t_out *out, t_op op)
{
	if (out == NULL)
	{
		return ;
	}
	out->count[op]++;
}
