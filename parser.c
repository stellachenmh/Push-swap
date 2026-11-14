/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelchen <stelchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/07 14:16:45 by stelchen          #+#    #+#             */
/*   Updated: 2026/11/14 09:26:08 by stelchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <limits.h>
#include "ft_printf.h"

static int	arg_is_num(const char *arg);
static int	numstr_to_i(const char *arg, int *error);
static int	parse_bench(char *arg, t_metadata *meta);
static int	parse_countonly(char *arg, t_metadata *meta);
static int	parse_strat(char *arg, t_metadata *meta);

int	*parse_args(int argc, char **argv, t_metadata *meta)
{
	int	error;
	int	i;
	int	*result;

	error = 0;
	if (argc < 2)
		return (NULL);
	result = malloc((argc - 1) * sizeof(*result));
	if (!result)
		return (NULL);
	i = 1;
	while (i < argc - 1 && (parse_bench(argv[i], meta)
			|| parse_strat(argv[i], meta) 
			|| parse_countonly(argv[i], meta)))
		i++;
	meta->count = 0; // already used bzero
	while (i < argc && !error)
		result[meta->count++] = numstr_to_i(argv[i++], &error);
	if (error)
		free(result);
	else
		return (result);
	return (NULL);
}


int	parse_countonly(char *arg, t_metadata *meta)
{
	if (ft_strlen(arg) != 7)
	{
		return (0);
	}
	if (ft_strncmp(arg, "--count", 7) == 0)
	{
		meta->countonly = 1;
		return (1);
	}
	return (0);
}


/**
 * @brief Checks if the parameter arg matches the length and contents of
 * othe bench flag, and if so updates metadata's bench variable.
 */

int	parse_bench(char *arg, t_metadata *meta)
{
	if (ft_strlen(arg) != 7)
	{
		return (0);
	}
	if (ft_strncmp(arg, "--bench", 7) == 0)
	{
		meta->bench = 1;
		return (1);
	}
	return (0);
}

/**
 * @brief Checks if the parameter arg matches the length and contents of
 * one of the strategy flags, and if so updates metadata's strategy
 * variable.
 */

int	parse_strat(char *arg, t_metadata *meta)
{
	size_t	arg_len;

	arg_len = ft_strlen(arg);
	if (arg_len == 8 && (ft_strncmp(arg, "--simple", 9) == 0))
	{
		meta->strategy = SIMPLE;
		return (1);
	}
	else if (arg_len == 8 && (ft_strncmp(arg, "--medium", 9) == 0))
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
	int			multiplier;
	long long	result;

	multiplier = 1;
	result = 0;
	if (!arg_is_num(arg))
		*error = 1;
	if (*arg == '-')
	{
		multiplier *= -1;
		arg++;
	}
	while (*arg == '0')
		arg++;
	if (ft_strlen(arg) > 10)
		*error = 1;
	while (*arg && !*error)
		result = (result * 10) + (*arg++ - '0');
	result *= multiplier;
	if (result > INT_MAX || result < INT_MIN)
		*error = 1;
	if (*error)
		return (0);
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
