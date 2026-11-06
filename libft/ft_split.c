/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelchen <stelchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 17:35:55 by stelchen          #+#    #+#             */
/*   Updated: 2026/10/09 15:15:47 by stelchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdlib.h>

static int		count_strings(const char *str, char c_sep);
static int		find_substrs(const char *str, char **result, char c_sep);
static int		free_all(char **result, int substr_idx);
static char		*mk_substr(const char *str, int startpt, int curr_pos);

char	**ft_split(char const *str, char c_sep)
{
	int		substr_count;
	char	**result;

	if (!str)
		return (NULL);
	substr_count = count_strings(str, c_sep);
	result = malloc((substr_count + 1) * (sizeof(*result)));
	if (!result)
		return (NULL);
	result[substr_count] = NULL;
	if (find_substrs(str, result, c_sep) == 0)
		return (NULL);
	return (result);
}

static int	free_all(char **result, int substr_idx)
{
	while (substr_idx > 0)
	{
		substr_idx--;
		free(result[substr_idx]);
	}
	free(result);
	return (0);
}

static int	find_substrs(const char *str, char **result, char c_sep)
{
	int	i;
	int	startpt;
	int	substr_idx;

	i = 0;
	startpt = 0;
	substr_idx = 0;
	while (1)
	{
		if ((str[i] != c_sep) && (i == 0 || str[i - 1] == c_sep))
			startpt = i;
		else if (i != 0 && (str[i - 1] != c_sep) && ((str[i] == c_sep)
				|| !str[i]))
		{
			result[substr_idx] = mk_substr(str, startpt, i);
			if (!result[substr_idx])
				return (free_all(result, substr_idx));
			substr_idx += 1;
		}
		if (str[i] == '\0')
			break ;
		i++;
	}
	return (1);
}

static char	*mk_substr(const char *str, int startpt, int curr_pos)
{
	char	*dest;
	int		j;

	dest = malloc(((curr_pos - startpt) + 1) * sizeof(*dest));
	if (!dest)
		return (NULL);
	j = 0;
	while (startpt < curr_pos)
	{
		dest[j] = str[startpt];
		startpt++;
		j++;
	}
	dest[j] = '\0';
	return (dest);
}

static int	count_strings(const char *str, char c_sep)
{
	int	i;
	int	str_count;

	i = 0;
	str_count = 0;
	while (str[i])
	{
		if ((str[i] != c_sep) && ((i == 0) || str[i - 1] == c_sep))
			str_count++;
		i++;
	}
	return (str_count);
}

/*My notes
Changes from Piscine: char c instead of charset, const s
Array of new strings. Null if ANY allocation fails.
Each string can be freed, array can also be freed
Array is null-terminated

Mk substr - could also use ft_substr and ft_strcopy

Testing. Everything from my orig main worked, except 'emptystr'.
I can't pass NULL - type error. I can't leave char empty

Check - const str
Done - freeing each str and arr, null if any alloc fails, array null-term,
AI check of edge cases, s is null ptr, s does not contain c,
allocation failure check, fake now the standard ft split is failing?,


Special compile instructions to test malloc failure
gcc -Wall -Wextra -Werror -Dmalloc=custom_malloc ft_split_main.c srcs/ft_split.c

Do
Shorten code
Valgrind check

*/
