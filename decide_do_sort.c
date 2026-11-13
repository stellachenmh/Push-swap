/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decide_do_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelchen <stelchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 18:36:51 by stelchen          #+#    #+#             */
/*   Updated: 2026/11/13 18:37:35 by stelchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>
#include "libft/libft.h"

void	decide_sort(t_stack *a, t_metadata *metadata)
{
	metadata->disorder = compute_disorder(a);
	if (metadata->strategy == ADAPTIVE)
	{
		if (metadata->disorder < 0.2)
			metadata->strategy_used = SIMPLE;
		else if (metadata->disorder >= 0.5)
			metadata->strategy_used = COMPLEX;
		else
			metadata->strategy_used = MEDIUM;
	}
	else
		metadata->strategy_used = metadata->strategy;
}
int	do_sort(t_stack *a, t_stack *b, t_metadata *metadata, t_out *out)
{
	if (a->size <= 5)
	{
		if (rank_ints(a))
			return (EXIT_FAILURE);
		sort_small_stk(a, b, out);
	}
	else if (metadata->strategy_used == SIMPLE)
		return (sort_simple(a, b, out));
	else if (metadata->strategy_used == MEDIUM)
		return (sort_medium(a, b, out));
	else if (metadata->strategy_used == COMPLEX)
		return (sort_complex(a, b, out));
	return (EXIT_SUCCESS);
}

int	sort_and_report(t_stack *a, t_stack *b, t_metadata *metadata)
{
	t_out	out;
	int		status;

	ft_bzero(&out, sizeof(out));
	out.fd = STDOUT_FILENO;
	decide_sort(a, metadata);
	status = EXIT_SUCCESS;
	if (metadata->disorder != 0)
		status = do_sort(a, b, metadata, &out);
	if (metadata->bench && status == EXIT_SUCCESS)
		bench_report(STDERR_FILENO, metadata, &out);
	return (status);
}