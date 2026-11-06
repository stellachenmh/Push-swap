/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelchen <stelchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 17:35:14 by stelchen          #+#    #+#             */
/*   Updated: 2026/10/08 17:39:10 by stelchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*byte_ptr_1;
	const unsigned char	*byte_ptr_2;
	size_t				i;

	if (!s1 || !s2)
		return (0);
	if (n == 0)
		return (0);
	byte_ptr_1 = s1;
	byte_ptr_2 = s2;
	i = 0;
	while ((i < (n - 1)) && (byte_ptr_1[i] == byte_ptr_2[i]))
		i++;
	return (byte_ptr_1[i] - byte_ptr_2[i]);
}

/*My notes
Each condition of while loop
No such thing as which is 'shorter'. Two 'strings' of equal length

Unsigned char. AI suggested as edge case
Subtracting unsigned chars returns int

If passing null, UB or 0. main.c throws an error

Off by one. Len vs position
Which condition first... i has already advanced. Checking str[i]
first is checking one beyond the len to check
*/