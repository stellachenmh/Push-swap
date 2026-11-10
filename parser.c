/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simonlau <simonlau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/07 14:16:45 by stelchen          #+#    #+#             */
/*   Updated: 2026/11/10 16:44:39 by simonlau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"
#include <limits.h>

static int	arg_is_num(const char *arg);
static int	numstr_to_i(const char *arg, int *error);
static int	parse_bench(char *arg, t_metadata *meta);
static int	parse_strat(char *arg, t_metadata *meta);

/**
 * @brief Checks for non-numeric inputs, duplicate ints, numbers outside
 * the range of ints, and no input. Displays "Error" for the first 3
 * categories, and displays nothing? if no input.
 * Only if valid...
 */

int	*parse_args(int argc, char **argv, t_metadata *meta, int *count)
{
	int	error;
	int	i;
	int	strategy_seen;
	int	*result;

	if (count)
		*count = 0;
	if (argc < 2 || !argv || !meta || !count)
		return (NULL);
	result = malloc((size_t)(argc - 1) * sizeof(*result));
	if (!result)
		return (NULL);
	i = 1;
	strategy_seen = 0;
	while (i < argc && argv[i][0] == '-' && argv[i][1] == '-')
	{
		if (ft_strlen(argv[i]) == 7
			&& ft_strncmp(argv[i], "--bench", 8) == 0)
		{
			if (meta->bench)
				return (free(result), NULL);
			parse_bench(argv[i], meta);
		}
		else if (parse_strat(argv[i], meta))
		{
			if (strategy_seen)
				return (free(result), NULL);
			strategy_seen = 1;
		}
		else
			return (free(result), NULL);
		i++;
	}
	while (i < argc)
	{
		error = 0;
		result[*count] = numstr_to_i(argv[i], &error);
		if (error)
		{
			free(result);
			*count = 0;
			return (NULL); // And print error message somewhere
		}
		(*count)++;
		i++;
	}
	if (*count == 0)
		return (free(result), NULL);
	return (result);
}

static int	parse_bench(char *arg, t_metadata *meta)
{
	if (ft_strlen(arg) == 7 && ft_strncmp(arg, "--bench", 8) == 0)
	{
		meta->bench = 1;
		return (1);
	}
	return (0);
}

static int	parse_strat(char *arg, t_metadata *meta)
{
	size_t	arg_len;

	arg_len = ft_strlen(arg);
	if (arg_len == 8 && ft_strncmp(arg, "--simple", 9) == 0)
	{
		meta->strategy = SIMPLE;
		return (1);
	}
	else if (arg_len == 8 && ft_strncmp(arg, "--medium", 9) == 0)
	{
		meta->strategy = MEDIUM;
		return (1);
	}
	else if (arg_len == 9 && ft_strncmp(arg, "--complex", 10) == 0)
	{
		meta->strategy = COMPLEX;
		return (1);
	}
	else if (arg_len == 10 && ft_strncmp(arg, "--adaptive", 11) == 0)
	{
		meta->strategy = ADAPTIVE;
		return (1);
	}
	return (0);
}

/**
 * @brief Modified version of ft_atoi that converts str to int. Changes
 * parameter 'error' of calling function to true if a) input is non-numeric or
 * b) input is outside valid values for integer. Unlike atoi, does not accept
 * leading whitespaces or + signs.
 */

static int	numstr_to_i(const char *arg, int *error)
{
	int			negative;
	unsigned long	limit;
	unsigned long	result;
	unsigned long	digit;

	negative = (*arg == '-');
	result = 0;
	if (!arg_is_num(arg))
	{
		*error = 1;
		return (0);
	}
	if (negative)
		arg++;
	while (*arg)
	{
		digit = (unsigned long)(*arg++ - '0');
		limit = (unsigned long)INT_MAX + (unsigned long)negative;
		if (result > (limit - digit) / 10)
		{
			*error = 1;
			return (0);
		}
		result = (result * 10) + digit;
	}
	if (negative && result == (unsigned long)INT_MAX + 1UL)
		return (INT_MIN);
	if (negative)
		return (-(int)result);
	if (result > (unsigned long)INT_MAX)
	{
		*error = 1;
		return (0);
	}
	return ((int)result);
}

/**
 * @brief Checks that the argument contains only digits, at least
 * one digit, and at most one leading -.
 */

static int	arg_is_num(const char *arg)
{
	if (*arg == '-')
		arg++;
	if (!*arg)
		return (0);
	while (*arg)
	{
		if (!ft_isdigit(*arg))
			return (0);
		arg++;
	}
	return (1);
}
