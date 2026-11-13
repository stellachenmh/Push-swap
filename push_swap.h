/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelchen <stelchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 12:59:32 by simon.lau         #+#    #+#             */
/*   Updated: 2026/11/13 18:35:29 by stelchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/**
 * @brief stddef for EXIT_SUCCESS and failure macros
 */

// Are libft/printf included? Not in this .h

# include <stddef.h>
# include <stdlib.h>

# define ADAPTIVE 0
# define SIMPLE 1
# define MEDIUM 2
# define COMPLEX 3

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

typedef struct s_metadata
{
	int		bench;
	float	disorder;
	int		strategy;
	int		strategy_used;
	int		count;

}			t_metadata;

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
void		bench_report(int fd, t_metadata *meta, t_out *out);
void		bench_counts(int fd, t_out *out);

t_stack		*stack_init(int *arr, size_t size, size_t capacity);
void		stack_destroy(t_stack **stack_ptr);
int			*parse_args(int argc, char **argv, t_metadata *meta);

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

int			sort_simple(t_stack *a, t_stack *b, t_out *out);
int			sort_medium(t_stack *a, t_stack *b, t_out *out);
int			sort_complex(t_stack *a, t_stack *b, t_out *out);

int			checker_parse_args(int argc, char **argv, t_stack *a);
float		compute_disorder(t_stack *stack_a);
void		decide_sort(t_stack *a, t_metadata *metadata);
int			do_sort(t_stack *a, t_stack *b, t_metadata *metadata, t_out *out);

size_t		find_max_idx(t_stack *a);
size_t		find_min_idx(t_stack *stack);

int			has_duplicates(const int *arr, int size);
void		move_idx_to_top(t_stack *stack, size_t tgt_idx, char c, t_out *out);
int			rank_ints(t_stack *a);
int			sort_and_report(t_stack *a, t_stack *b, t_metadata *metadata);
void		sort_small_stk(t_stack *a, t_stack *b, t_out *out);
void		sort_three_ints(t_stack *a, t_out *out);

#endif
