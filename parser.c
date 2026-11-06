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

int	conv_atoi(const char *str);

/**
 * @brief Checks for non-numeric inputs, duplicate ints, numbers outside 
 * the range of ints, and no input. Displays "Error" for the first 3 
 * categories, and displays nothing? if no input. 
 * Only if valid... 
 */

int	*parse_ints(int size, char **argv) // name and parameter change. KIV, this size is an int (Argc) not sizet. >intmax args? int argc
{
	int	error;
	int	i;
	int	*result;

	result = malloc(size * sizeof(*result)); // Skip the int * cast?
	if (!result)
		return (NULL); // This is in a type int helper fx  
	i = 0;
	while (i < size)
	{
		error = 0;
		result[i] = conv_atoi(argv[i], &error);
		// Will result[i] work? Go by every 4 bytes, not per byte
		// Check if ptr to error will work
		if (error)
		{
			free(result);
			return (NULL);
		}
		if (result[i] > INT_MAX || result[i] < INT_MIN) // Test
			return (0);
	}
	return (1);
}

// return a struct to show which flags are present? 

/**
 * @brief Modified version of ft_atoi. Converts str to int, changes 
 * parameter 'error' of calling function to true if input is non-numeric. 
 * Does not accept leading whitespaces
 * or + signs.
 */

static long	numstr_to_long(const char *arg, int *error) // Ugh this is too long
{
	int		i;
	int		multiplier;
	long	result;

	i = 0;
	multiplier = 1;
	result = 0;
	if (arg[i] == '-')
	{
		multiplier *= -1;
		i++;
	}
	while (arg[i])
	{
		if (!ft_isdigit(arg[i])) // Check this works
		{
			error = 1;
			return (0);
		}
		if (ft_isdigit(arg[i])) // Check this is included. This could be 'else'
		{
			result *= 10;
			result += (arg[i] - '0');
			i++;
		}
	}
	return (result * multiplier);
}
