/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_emit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slau <slau@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 12:00:00 by slau             #+#    #+#             */
/*   Updated: 2026/11/04 12:00:00 by slau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/** @file ops_emit.c
 * @brief Shared output sink for stack operations.
 *
 * Operations always mutate the stacks; whether they also print their name is
 * decided by the t_out context. A NULL context or a negative fd means silent.
 */

#include "libft/libft.h"
#include "push_swap.h"

/**
 * @brief Records @p op on the context and writes @p name unless silent.
 *
 * Counting happens even when @p out is silent; only a NULL context skips
 * both counting and output.
 *
 * @param out  output context, NULL is treated as silent
 * @param op   operation identifier for the counters
 * @param name operation name including its trailing newline
 */
void	op_emit(t_out *out, t_op op, char *name)
{
	if (out == NULL)
	{
		return ;
	}
	stats_record(out, op);
	if (out->fd < 0)
	{
		return ;
	}
	ft_putstr_fd(name, out->fd);
}
