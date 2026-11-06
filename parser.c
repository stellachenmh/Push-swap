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

	result = malloc(size * sizeof(*result)); // Skip the int * cast?
	if (!result)
		return (NULL);
	i = 0;
	while (i < size)
	{
		error = 0;
		result[i] = numstr_to_i(argv[i], &error);
		// Will result[i] work? Go by every 4 bytes, not per byte
		// Check if ptr to error will work
		if (error)
		{
			free(result);
			return (NULL); // And print error message somewhere 
		}
		i++;
	}
	return (result);
}


 // Will this cast work? Am I getting weird results because int and long are diff lengths?


/**
 * @brief Modified version of ft_atoi. Converts str to int, changes 
 * parameter 'error' of calling function to true if input is non-numeric. 
 * Does not accept leading whitespaces
 * or + signs.
 * 
 * check for validity of result too
 */

static int	numstr_to_i(const char *arg, int *error)
{
	int		multiplier;
	long	result;

	multiplier = 1;
	result = 0;
	if (!arg_is_num(arg)) // move to parse ints? 
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
	// while (*arg)
	// {
	// 	result *= 10;
	// 	result += (*arg - '0');
	// 	arg++;
	// }
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
