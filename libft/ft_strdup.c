/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelchen <stelchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 17:36:05 by stelchen          #+#    #+#             */
/*   Updated: 2026/10/08 17:36:06 by stelchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	size_t	i;
	char	*str_copy;
	size_t	strlen_inc_null;

	strlen_inc_null = ft_strlen(s1) + 1;
	str_copy = malloc(strlen_inc_null * sizeof(*str_copy));
	if (!str_copy)
		return (NULL);
	i = 0;
	while (i < strlen_inc_null)
	{
		str_copy[i] = s1[i];
		i++;
	}
	return (str_copy);
}

/*My notes
strdup
Not tested

Substr
Edge case - start is out of string, len is longer'n str, add null
Index into smth beyond str length, garbage

// Start index more than string, or len more than string = empty string
// Start + len more than string - truncate?
// Add null outside len

For first two, should I malloc only enough for an empty string?
Think good practice
Am I supposed to add a null? Within or outside the len?
Assume yes and outside. Gemini,
Gitbook doesn't add a null https://42-cursus.gitbook.io/guide/0-rank-00/
libft/additional-functions/ft_substr
Medium also doesn't mention https://medium.com/@piolodale/libft-42-cursus
-871329cc51d3

Strjoin
SIZE_MAX to check for int overflow
*/
