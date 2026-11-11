/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_numbers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simonlau <simonlau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 12:00:00 by simonlau          #+#    #+#             */
/*   Updated: 2026/11/11 07:59:21 by simonlau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"
#include <limits.h>

static int	arg_is_num(const char *arg);
static int	parse_mag(const char *arg, unsigned long limit,
				unsigned long *result);

int	parse_int_arg(const char *arg, int *error)
{
	int				negative;
	unsigned long	limit;
	unsigned long	result;

	negative = (*arg == '-');
	if (!arg_is_num(arg))
	{
		*error = 1;
		return (0);
	}
	if (negative)
		arg++;
	limit = (unsigned long)INT_MAX + (unsigned long)negative;
	if (parse_mag(arg, limit, &result))
	{
		*error = 1;
		return (0);
	}
	if (negative && result == limit)
		return (INT_MIN);
	if (negative)
		return (-(int)result);
	return ((int)result);
}

static int	parse_mag(const char *arg, unsigned long limit,
		unsigned long *result)
{
	unsigned long	digit;

	*result = 0;
	while (*arg)
	{
		digit = (unsigned long)(*arg++ - '0');
		if (*result > (limit - digit) / 10)
			return (1);
		*result = (*result * 10) + digit;
	}
	return (0);
}

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
