/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+   */
/*                                                    +:+ +:+         +:+     */
/*   By: slau <slau@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 12:00:00 by slau             #+#    #+#             */
/*   Updated: 2026/10/15 12:00:00 by slau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <limits.h>

static int 	arg_is_num(const char *arg);
static int	ft_isdigit(int c);
static int	numstr_to_i(const char *arg, int *error); 


/**
 * @brief Checks for non-numeric inputs, duplicate ints, numbers outside 
 * the range of ints, and no input. Displays "Error" for the first 3 
 * categories, and displays nothing? if no input. 
 * Only if valid... 
 */

int	*parse_ints(int size, char **argv) // KIV, this size is an int (Argc) not sizet. >intmax args? int argc
{
	int		error;
	int		i;
	int		*result;

	result = malloc(size * sizeof(*result));
	if (!result)
		return (NULL);
	i = 0;
	while (i < size)
	{
		error = 0;
		result[i] = numstr_to_i(argv[i + 1], &error);
		if (error)
		{
			free(result);
			return (NULL); // And print error message somewhere 
		}
		i++;
	}
	return (result);
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
