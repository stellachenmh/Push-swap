/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_ops_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slau <slau@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 12:00:00 by slau             #+#    #+#             */
/*   Updated: 2026/11/04 12:00:00 by slau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/** @file checker_ops_bonus.c
 * @brief Maps checker instruction names to silent stack operations.
 *
 * The checker never echoes the operations it reads; callers pass a silent
 * t_out. An unknown or malformed instruction is reported by returning -1.
 */

#include "libft/libft.h"
#include "checker_bonus.h"

/**
 * @brief Compares @p line with @p name, allowing one trailing newline.
 *
 * @param line instruction read from stdin
 * @param name instruction name without newline
 * @return 1 on an exact match, 0 otherwise
 */
static int	line_is(char *line, char *name)
{
	size_t	len;

	len = ft_strlen(name);
	if (ft_strncmp(line, name, len) != 0)
	{
		return (0);
	}
	return (line[len] == '\0' || line[len] == '\n');
}

/**
 * @brief Applies an operation that only touches stack @p a.
 *
 * @return 1 if @p line matched an operation, 0 otherwise
 */
static int	apply_a(char *line, t_stack *a, t_out *out)
{
	if (line_is(line, "sa"))
		sa(a, out);
	else if (line_is(line, "ra"))
		ra(a, out);
	else if (line_is(line, "rra"))
		rra(a, out);
	else
		return (0);
	return (1);
}

/**
 * @brief Applies an operation that only touches stack @p b.
 *
 * @return 1 if @p line matched an operation, 0 otherwise
 */
static int	apply_b(char *line, t_stack *b, t_out *out)
{
	if (line_is(line, "sb"))
		sb(b, out);
	else if (line_is(line, "rb"))
		rb(b, out);
	else if (line_is(line, "rrb"))
		rrb(b, out);
	else
		return (0);
	return (1);
}

/**
 * @brief Applies an operation that touches both stacks.
 *
 * @return 1 if @p line matched an operation, 0 otherwise
 */
static int	apply_ab(char *line, t_stack *a, t_stack *b, t_out *out)
{
	if (line_is(line, "ss"))
		ss(a, b, out);
	else if (line_is(line, "pa"))
		pa(a, b, out);
	else if (line_is(line, "pb"))
		pb(a, b, out);
	else if (line_is(line, "rr"))
		rr(a, b, out);
	else if (line_is(line, "rrr"))
		rrr(a, b, out);
	else
		return (0);
	return (1);
}

/**
 * @brief Applies one checker instruction to the stacks.
 *
 * @param a    stack a, NULL is ignored by the operations
 * @param b    stack b, NULL is ignored by the operations
 * @param line instruction text, optionally ending with a newline
 * @param out  output context, pass a silent one in the checker
 * @return 0 on success, -1 if the instruction is unknown or line is NULL
 */
int	apply_instruction(t_stack *a, t_stack *b, char *line, t_out *out)
{
	if (line == NULL)
		return (-1);
	if (apply_a(line, a, out))
		return (0);
	if (apply_b(line, b, out))
		return (0);
	if (apply_ab(line, a, b, out))
		return (0);
	return (-1);
}
