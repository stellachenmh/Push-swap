/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelchen <stelchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 17:35:25 by stelchen          #+#    #+#             */
/*   Updated: 2026/10/14 18:00:48 by stelchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char	*dst_ptr;
	unsigned char	*src_ptr;

	dst_ptr = (unsigned char *)dst;
	src_ptr = (unsigned char *)src;
	if (src == dst || n == 0)
		return (dst);
	if (src_ptr > dst_ptr)
		ft_memcpy(dst, src, n);
	else if (src_ptr < dst_ptr)
	{
		while (n > 0)
		{
			dst_ptr[n - 1] = src_ptr[n - 1];
			n--;
		}
	}
	return (dst);
}

/*My notes

Two null pointers, one null pointer - passing NULL is UB. C++ forums
https://en.cppreference.com/cpp/string/byte/memmove

One or two empty strings. Still return dest

Backwards copy started from null, doesn't fix the first char - think fixed
Index vs len

'Not initialised in some paths' seems ok

If i is defined outside while loop, i will not update even if n updates
	n = 5;
	i = n - 1;
	while (n > 0)
	{
		printf("n %zu, i %d\n", n, i);
		n--; // Would i = n - 1 ever update this way?
	}




*/