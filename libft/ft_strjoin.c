/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelchen <stelchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 17:36:15 by stelchen          #+#    #+#             */
/*   Updated: 2026/10/08 17:36:16 by stelchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdint.h>
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	size_t	result_len;

	if (ft_strlen(s1) < (SIZE_MAX - ft_strlen(s2) - 1))
		result_len = ft_strlen(s1) + ft_strlen(s2) + 1;
	else
		return (NULL);
	result = malloc(result_len * sizeof(char));
	if (!result)
		return (NULL);
	ft_strlcpy(result, s1, result_len);
	ft_strlcat(result, s2, result_len);
	return (result);
}
