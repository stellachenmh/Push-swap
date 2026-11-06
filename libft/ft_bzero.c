/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelchen <stelchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 17:33:34 by stelchen          #+#    #+#             */
/*   Updated: 2026/10/08 17:33:35 by stelchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *str, size_t n)
{
	unsigned char	*byte_ptr;
	size_t			i;

	byte_ptr = (unsigned char *)str;
	i = 0;
	while (i < n)
	{
		byte_ptr[i] = 0;
		i++;
	}
	return ;
}
