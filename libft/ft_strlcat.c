/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelchen <stelchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 17:36:20 by stelchen          #+#    #+#             */
/*   Updated: 2026/10/08 17:36:21 by stelchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	dest_len_init;
	size_t	src_ctr;

	dest_len_init = ft_strlen(dest);
	if (size == 0 || dest_len_init >= size)
		return (size + ft_strlen(src));
	src_ctr = 0;
	while ((dest_len_init + src_ctr < size - 1) && src[src_ctr])
	{
		dest[dest_len_init + src_ctr] = src[src_ctr];
		src_ctr++;
	}
	dest[dest_len_init + src_ctr] = '\0';
	return (dest_len_init + ft_strlen(src));
}
