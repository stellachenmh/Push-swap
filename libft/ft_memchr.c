/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelchen <stelchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 17:35:09 by stelchen          #+#    #+#             */
/*   Updated: 2026/10/08 17:35:11 by stelchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *memstr, int c, size_t n)
{
	const unsigned char	*byte_ptr;
	size_t				i;

	if (n == 0)
		return (NULL);
	i = 0;
	byte_ptr = (const unsigned char *)memstr;
	while (i < n)
	{
		if (byte_ptr[i] == (unsigned char)c)
			return ((void *)&byte_ptr[i]);
		i++;
	}
	return (NULL);
}

/*My notes
Memchr
Vs str? Locate in real char * str, vs void * memory string.
Memchr also takes n, because mem strings have no null

Memcmp
Both strs are n bytes long. No unequal lengths

Makefile, can I now use my fxs across diff files? IDK

*/
