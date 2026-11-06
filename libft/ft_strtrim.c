/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelchen <stelchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 17:36:54 by stelchen          #+#    #+#             */
/*   Updated: 2026/10/08 17:36:55 by stelchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	to_trim(char c, char const *set);

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*result;
	size_t	substr_len;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	end = ft_strlen(s1);
	while ((s1[start]) && to_trim(s1[start], set))
		start++;
	while ((end > start) && to_trim(s1[end - 1], set))
		end--;
	substr_len = end - start;
	result = ft_substr(s1, start, substr_len);
	return (result);
}

static int	to_trim(char c, char const *set)
{
	size_t	i;
	size_t	set_len;

	i = 0;
	set_len = ft_strlen(set);
	while (i < set_len)
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

/*My notes
Off by one. Position 1 - position 0 is 2 chars.
- But end is exclusive! One char after the actual end.

Do not set end as strlen - 1. Underflow to size max. Check in loop condition
instead

	printf("Start %zu, end %zu, len %zu\n", start, end, substr_len);

Checked AI edge cases

*/