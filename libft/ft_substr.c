/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelchen <stelchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 17:37:03 by stelchen          #+#    #+#             */
/*   Updated: 2026/10/08 18:10:41 by stelchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	chars_copied;
	char	*result;

	if (!s)
		return (NULL);
	chars_copied = 0;
	if (len == 0 || (start >= ft_strlen(s)))
		len = 0;
	else
	{
		if (len >= ft_strlen(s) - start)
			len = (ft_strlen(s) - start);
	}
	result = malloc((len + 1) * sizeof(*s));
	if (!result)
		return (NULL);
	while (chars_copied < len)
	{
		result[chars_copied] = s[start + chars_copied];
		chars_copied++;
	}
	result[chars_copied] = '\0';
	return (result);
}

/* My notes
Error - if start < len is wrong. Start is 4,
	len is 2 (copy 2 chars.) SUBSTR len!
Did my own main testing...look for edge cases?

No need to check for -ve parameters

If		len = 0, return an empty string
If start >= ft strlen, return an empty string

	// What if len is longer than str len? INclude in below
	// WHat if start + len is longer than str len?
	// Int overflow?

Last null, and empty null if start > len, or len 0

Possible start+len overflow, changing algo didn't work
UPdated. Underflow won't happen because of prior if

*/