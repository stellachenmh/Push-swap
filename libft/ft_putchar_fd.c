/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelchen <stelchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 17:35:35 by stelchen          #+#    #+#             */
/*   Updated: 2026/10/08 17:35:37 by stelchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, sizeof(c));
	return ;
}

/*My notes

putchar
Seems only ASCII is 1 byte, other chars longer.
https://www.baeldung.com/cs/unicode-character-bytes

For all 3 fxs, need to handle wrong type parameter?

putnbr
write goes byte by byte. Need to split off tens, ones etc

*/
