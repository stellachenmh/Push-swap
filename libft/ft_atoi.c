/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelchen <stelchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 17:41:21 by stelchen          #+#    #+#             */
/*   Updated: 2026/11/06 17:23:07 by stelchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_whitespace(char c);

int	ft_atoi(const char *str)
{
	int		i;
	int		multiplier;
	long	result;

	i = 0;
	multiplier = 1;
	result = 0;
	while (is_whitespace(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			multiplier *= -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		result *= 10;
		result += (str[i] - '0');
		i++;
	}
	return ((int)(result * multiplier));
}

static int	is_whitespace(char c)
{
	if (c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r'
		|| c == ' ')
		return (1);
	else
		return (0);
}

// fix - single dash or empty string NOT valid nos

/*My notes
atoi does not check for null ptrs. Undefined.
https://www.pass4sure.com/blog/demystifying-atoi-in-c-basics-syntax
-and-internal-working/

Cannot assign a malloc-ed string

Flushing printf text using \n
indexing takes priority over deref. Arrow also takes priority
Misunderstanding of local copy? char * would work fine, don't need char **



*/
