/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelchen <stelchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 17:35:30 by stelchen          #+#    #+#             */
/*   Updated: 2026/10/08 17:35:31 by stelchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int c, size_t len)
{
	size_t			i;
	unsigned char	*byte_ptr;

	byte_ptr = (unsigned char *)ptr;
	i = 0;
	while (i < len)
	{
		*byte_ptr = (unsigned char)c;
		byte_ptr++;
		i++;
	}
	return (ptr);
}

/*My notes
Can I test bzero with a void pointer instead of a char ptr?

Memcpy
What if src contains garbage values? Just copy over?
What if n exceeds dest length? On application to ensure? Yes
What if n exceeds src length? Stop at null? Memory has no null. Undefd

Can I index into a void ptr? No. Create a cast copy
Gemini's concise version
while (n--)
	*d++ = *s++
Infinite loop because size_t is never -ve!
Must I handle null ptrs? No, for speed. Even if 0 bytes, ptr must be valid

Memmove
Temp array vs copy direction, KIV approaches



Memset
size_t. Difference from unsigned int? Can it be -ve?
Assume that the memset buffer is writable?
What if the len exceeds buffer space?
If don't write all, then I don't expect memory to match

Memset testing
Assert memset 10 bytes of 20-byte buffer matches, I don't expect it to
Array indexing alr derefs a pointer
Mismatch between i and size_t

What happens when you cast an int to unsigned char?
Memset takes only the last 8 bits (last byte)

Unsigned char ptr vs just a char ptr?
Signed vs unsigned char...char to fx, do math, promoted to int
Filled with 1s, so -ve value

Use memcmp! Assert compares the ptrs, do they point to same memory?





*/
