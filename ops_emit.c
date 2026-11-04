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
 * @brief Writes @p name to the context's fd unless the context is silent.
 *
 * @param out  output context, NULL is treated as silent
 * @param name operation name including its trailing newline
 */
void	op_emit(t_out *out, char *name)
{
	if (out == NULL || out->fd < 0)
	{
		return ;
	}
	ft_putstr_fd(name, out->fd);
}
