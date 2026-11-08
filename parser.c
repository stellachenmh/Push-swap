/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelchen <stelchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/07 14:16:45 by stelchen          #+#    #+#             */
/*   Updated: 2026/11/08 22:36:20 by stelchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <limits.h>

static int 	arg_is_num(const char *arg);
static int	ft_isdigit(int c);
static int	numstr_to_i(const char *arg, int *error); 

int parse_bench(char *arg, t_metadata *meta);
int	parse_strat(char *arg, t_metadata *meta);


/**
 * @brief Checks for non-numeric inputs, duplicate ints, numbers outside 
 * the range of ints, and no input. Displays "Error" for the first 3 
 * categories, and displays nothing? if no input. 
 * Only if valid... 
 */


 // KIV if 'size' parameter is needed
int	*parse_args(int params, char **argv, t_metadata *meta) // KIV, this size is an int (Argc) not sizet. >intmax args? int argc
{
	int		error;
	int		i;
	int		*result;

	result = malloc(params * sizeof(*result)); // Do this later? KIV freeing. Possib wrong size. Check this works first
	if (!result)
		return (NULL);
	i = 1;
	if (parse_bench(argv[i], meta) && (i < params - 1))
		i++; 
	if (parse_strat(argv[i], meta) && (i < params - 1))
		i++;
	while (i < params)
	{
		error = 0;
		result[i - 1] = numstr_to_i(argv[i], &error);
		if (error)
		{
			free(result);
			return (NULL); // And print error message somewhere 
		}
		i++;
	}
	return (result);
}



// KIV how to initialise/set default bench
// KIV static or header
// If the next one has nothing, error? 

// #include <string.h>
// change to strcmp
int parse_bench(char *arg, t_metadata *meta)
{
	size_t arg_len;

	arg_len = ft_strlen(arg);
	if (ft_strncmp("--bench", arg, arg_len))
	{
		// When is this created? How can this fx access it?
		// Affects dot or ->
		meta->bench = 1;
		return (1);
	}
	return (0);
}

// KIV how to initialise/set default strategy
// KIV static or header
int	parse_strat(char *arg, t_metadata *meta)
{
	size_t arg_len;

	arg_len = ft_strlen(arg);	
	if (ft_strncmp(arg, "--simple", arg_len))
	{
		// When is this created? How can this fx access it?
		// Affects dot or ->
		meta->strategy = SIMPLE;
		return (1);	
	}
	else if (ft_strncmp(arg,"--medium", arg_len))
	{
		meta->strategy = MEDIUM;
		return (1);	
	}
	else if (ft_strncmp(arg, "--complex", arg_len))
	{
		meta->strategy = COMPLEX;
		return (1);	
	}
	else if (ft_strncmp(arg, "--adaptive", arg_len))
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
	int		multiplier;
	long	result;

	multiplier = 1;
	result = 0;
	if (!arg_is_num(arg))
	{
		*error = 1;
		return (0);
	}
	if (*arg == '-')
	{
		multiplier *= -1;
		arg++;
	}
	while (*arg)
		result = (result * 10) + (*arg++ - '0');
	result *= multiplier;
	if (result > INT_MAX || result < INT_MIN)
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

static int arg_is_num(const char *arg)
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

static int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}
