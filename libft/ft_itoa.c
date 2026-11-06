/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelchen <stelchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 17:34:15 by stelchen          #+#    #+#             */
/*   Updated: 2026/10/08 17:34:16 by stelchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	calc_itoa_strlen(long n, size_t result_strlen);
static void		put_i_to_a(char *str, long i, size_t index);

char	*ft_itoa(int n)
{
	size_t	n_len;
	long	n_long;
	char	*result;

	n_len = 1;
	n_long = n;
	if (n_long < 0)
	{
		n_len += 1;
		n_long *= -1;
	}
	n_len = calc_itoa_strlen(n_long, n_len);
	result = malloc((n_len + 1) * sizeof(*result));
	if (!result)
		return (NULL);
	if (n < 0)
		result[0] = '-';
	put_i_to_a(result, n_long, (n_len - 1));
	result[n_len] = '\0';
	return (result);
}

static void	put_i_to_a(char *str, long n, size_t index)
{
	char	digit;

	if (n >= 10)
	{
		digit = (n % 10) + '0';
		put_i_to_a(str, n / 10, index - 1);
		str[index] = digit;
	}
	else if (n >= 0 && n < 10)
	{
		digit = n + '0';
		str[index] = digit;
	}
	return ;
}

static size_t	calc_itoa_strlen(long n, size_t result_strlen)
{
	while (n / 10 != 0)
	{
		result_strlen++;
		n = n / 10;
		calc_itoa_strlen(n, result_strlen);
	}
	return (result_strlen);
}

/*My notes
Start from the back
Signed or unsigned char for digit doesn't matter since it only stores 1-digit nos
*/