/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelchen <stelchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 17:36:10 by stelchen          #+#    #+#             */
/*   Updated: 2026/10/08 17:36:11 by stelchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	size_t	i;
	size_t	str_len;

	if (!s || !f)
		return ;
	i = 0;
	str_len = ft_strlen(s);
	while (i < str_len)
	{
		f(i, &s[i]);
		i++;
	}
	return ;
}
