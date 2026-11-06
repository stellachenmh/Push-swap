/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelchen <stelchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 17:36:30 by stelchen          #+#    #+#             */
/*   Updated: 2026/10/09 15:21:46 by stelchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

/*My notes

Memset only works w ASCII values, since it writes byte by byte
Move it to memchr?

strnstr
Null-terminated needle. My implementation checks if first char is null,
but behaviour works. Otherwise need strcmp
Both loops need the len guard


*/
