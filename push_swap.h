/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simon.lau <simon.lau@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 12:59:32 by simon.lau         #+#    #+#             */
/*   Updated: 2026/10/19 12:59:32 by simon.lau        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>

/**
 * @brief stack with size elements up to capacity, zero index is the top
 *
 */
typedef struct s_stack
{
	int	*data;
	int	size;
	int	capacity;
}		t_stack;

t_stack	*stack_init(int *arr, int capacity);
int		parse_args(int argc, char **argv, t_stack *a);

void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);

void	sort_simple(t_stack *a, t_stack *b);
void	sort_medium(t_stack *a, t_stack *b);
void	sort_complex(t_stack *a, t_stack *b);
void	sort_adaptive(t_stack *a, t_stack *b);
void	select_strategy(t_stack *a, t_stack *b, int strategy);

int		ft_abs(int n);
int		ft_min(int a, int b);
int		ft_max(int a, int b);

int		checker_parse_args(int argc, char **argv, t_stack *a);

#endif
