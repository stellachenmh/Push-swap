/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelchen <stelchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 17:37:14 by stelchen          #+#    #+#             */
/*   Updated: 2026/10/08 17:37:17 by stelchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - ('a' - 'A'));
	else
		return (c);
}

/*My notes
Why do these fxs take and output int rather than char?
If C is neither unsigned char value nor EOF, undefined
EOF macro is usually -1. Type int. Unsigned char only 0-255, so no clash

*/
