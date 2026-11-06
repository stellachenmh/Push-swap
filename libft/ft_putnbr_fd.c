/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelchen <stelchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 17:35:45 by stelchen          #+#    #+#             */
/*   Updated: 2026/10/08 17:35:46 by stelchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_putnbr_fd(int n, int fd)
{
	char	digit;
	long	n_long;

	n_long = n;
	if (n < 0)
	{
		write(fd, "-", 1);
		n_long *= -1;
	}
	if (n_long >= 10)
	{
		digit = (n_long % 10) + '0';
		ft_putnbr_fd(n_long / 10, fd);
		write(fd, &digit, 1);
	}
	else if (n_long >= 0 && n_long < 10)
	{
		digit = n_long + '0';
		write(fd, &digit, 1);
	}
	return ;
}

/*My notes
Not tested on AI edge cases
*/