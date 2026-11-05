/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simonlau <simonlau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 12:59:32 by simon.lau         #+#    #+#             */
/*   Updated: 2026/10/23 19:57:49 by simonlau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/**
 * @brief stddef for EXIT_SUCCESS and failure macros
 */
# include <stddef.h>
# include <stdlib.h>

/**
 * @brief stack with size elements up to capacity, zero index is the top
 *
 */
typedef struct s_stack
{
	int		*data;
	size_t	size;
	size_t	capacity;
}			t_stack;

/**
 * @brief operation identifiers used by the stats counters
 *
 */
typedef enum e_op
{
	OP_SA,
	OP_SB,
	OP_SS,
	OP_PA,
	OP_PB,
	OP_RA,
	OP_RB,
	OP_RR,
	OP_RRA,
	OP_RRB,
	OP_RRR,
	OP_COUNT
}			t_op;

/**
 * @brief output sink and operation counters; fd < 0 means silent
 *
 */
typedef struct s_out
{
	int			fd;
	unsigned	count[OP_COUNT];
}			t_out;

void		op_emit(t_out *out, t_op op, char *name);
void		stats_record(t_out *out, t_op op);

t_stack		*stack_init(int *arr, size_t size, size_t capacity);
void		stack_destroy(t_stack **stack_ptr);
int			parse_args(int argc, char **argv, t_stack *a);

void		sa(t_stack *a, t_out *out);
void		sb(t_stack *b, t_out *out);
void		ss(t_stack *a, t_stack *b, t_out *out);
void		pa(t_stack *a, t_stack *b, t_out *out);
void		pb(t_stack *a, t_stack *b, t_out *out);
void		ra(t_stack *a, t_out *out);
void		rb(t_stack *b, t_out *out);
void		rr(t_stack *a, t_stack *b, t_out *out);
void		rra(t_stack *a, t_out *out);
void		rrb(t_stack *b, t_out *out);
void		rrr(t_stack *a, t_stack *b, t_out *out);

void		sort_simple(t_stack *a, t_stack *b, t_out *out);
void		sort_medium(t_stack *a, t_stack *b, t_out *out);
void		sort_complex(t_stack *a, t_stack *b, t_out *out);
void		sort_adaptive(t_stack *a, t_stack *b, t_out *out);
void		select_strategy(t_stack *a, t_stack *b, int strategy, t_out *out);

int			ft_abs(int n);
int			ft_min(int a, int b);
int			ft_max(int a, int b);

int			has_duplicates(const int *arr, int size);
int			checker_parse_args(int argc, char **argv, t_stack *a);
float		compute_disorder(t_stack *stack_a);
int			rank_ints(t_stack *a);

#endif
