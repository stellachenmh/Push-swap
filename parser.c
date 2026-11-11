/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simonlau <simonlau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/07 14:16:45 by stelchen          #+#    #+#             */
/*   Updated: 2026/11/11 07:59:21 by simonlau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

static int	parse_flags(int argc, char **argv, t_metadata *meta, int *index);
static int	parse_values(int argc, char **argv, int *result, int *count);
static int	parse_strat(char *arg, t_metadata *meta);

/**
 * @brief Parses leading options and compacts valid integers into a new array.
 */
int	*parse_args(int argc, char **argv, t_metadata *meta, int *count)
{
	int	i;
	int	*result;

	if (count)
		*count = 0;
	if (argc < 2 || !argv || !meta || !count)
		return (NULL);
	result = malloc((size_t)(argc - 1) * sizeof(*result));
	if (!result)
		return (NULL);
	i = 1;
	if (!parse_flags(argc, argv, meta, &i)
		|| !parse_values(argc, argv, result, count) || *count == 0)
	{
		free(result);
		*count = 0;
		return (NULL);
	}
	return (result);
}

static int	parse_flags(int argc, char **argv, t_metadata *meta, int *index)
{
	int	strategy_seen;

	strategy_seen = 0;
	while (*index < argc && argv[*index][0] == '-' && argv[*index][1] == '-')
	{
		if (ft_strlen(argv[*index]) == 7
			&& ft_strncmp(argv[*index], "--bench", 8) == 0 && !meta->bench)
			meta->bench = 1;
		else if (!parse_strat(argv[*index], meta) || strategy_seen)
			return (0);
		else
			strategy_seen = 1;
		(*index)++;
	}
	return (1);
}

static int	parse_values(int argc, char **argv, int *result, int *count)
{
	int	error;
	int	i;

	i = 1;
	while (i < argc && argv[i][0] == '-' && argv[i][1] == '-')
		i++;
	while (i < argc)
	{
		error = 0;
		result[*count] = parse_int_arg(argv[i], &error);
		if (error)
			return (0);
		(*count)++;
		i++;
	}
	return (1);
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
