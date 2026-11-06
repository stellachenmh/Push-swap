/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelchen <stelchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 17:36:49 by stelchen          #+#    #+#             */
/*   Updated: 2026/10/08 17:36:50 by stelchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	size_t	i;
	char	*ptr;
	char	chr;

	chr = (char)c;
	i = ft_strlen(str);
	while ((i + 1) > 0)
	{
		if (str[i] == chr)
		{
			ptr = (char *)&str[i];
			return (ptr);
		}
		i--;
	}
	return (NULL);
}
