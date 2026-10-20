/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_swap.c                                         :+:      :+:    :+   */
/*                                                    +:+ +:+         +:+     */
/*   By: slau <slau@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 12:00:00 by slau             #+#    #+#             */
/*   Updated: 2026/10/15 12:00:00 by slau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"
#include <unistd.h>

static void	swap(t_stack *s)
{
	int	tmp;

	if (s == NULL || s->size < (size_t)2)
	{
		return ;
	}
	tmp = s->data[0];
	s->data[0] = s->data[1];
	s->data[1] = tmp;
}

void	sa(t_stack *a)
{
	swap(a);
	ft_putstr_fd("sa", STDOUT_FILENO);
}

void	sb(t_stack *b)
{
	swap(b);
	ft_putstr_fd("sb", STDOUT_FILENO);
}

void	ss(t_stack *a, t_stack *b)
{
	swap(a);
	swap(b);
	ft_putstr_fd("ss", STDOUT_FILENO);
}
