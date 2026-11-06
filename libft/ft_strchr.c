/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelchen <stelchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 17:36:00 by stelchen          #+#    #+#             */
/*   Updated: 2026/10/08 17:36:01 by stelchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	size_t	i;
	char	*ptr;
	char	chr;

	chr = (char)c;
	i = 0;
	while (i < (ft_strlen(str) + 1))
	{
		if (str[i] == chr)
		{
			ptr = (char *)&str[i];
			return (ptr);
		}
		i++;
	}
	return (NULL);
}

/*My notes
Find first or last occurrence of char. No wide or multibyte
Null is part of string

strchr
Convert int to unsigned char...What happens if I don't?
Doing while str[i] means it can't find the first null. Fixed!

USe of i both as a counter to include null, AND a position checker...
i is strlen + 1 to check the null.
But str[i = strlen] IS the null position.

char or unsigned char? For comparison, doesn't matter?
https://stackoverflow.com/questions/42018949/creating-a-simplified-version-
of-strchr
Man says convert to char
Int to char. For 0-255, first 3 bytes aren't used. So int 48 = char 0!

strncmp
Does it compare the two nulls?
s1 - s2, order matters
I need the while s1. Otherwise it could read past str end
i is not the same as n!

*/
