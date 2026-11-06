/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelchen <stelchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 17:33:39 by stelchen          #+#    #+#             */
/*   Updated: 2026/10/08 17:33:41 by stelchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdint.h>
#include <stdlib.h>

static int	pdt_below_sizemax(size_t count, size_t size);

void	*ft_calloc(size_t count, size_t size)
{
	void	*result;

	if (!pdt_below_sizemax(count, size))
		return (NULL);
	result = malloc(count * size);
	if (!result)
		return (NULL);
	ft_bzero(result, (count * size));
	return (result);
}

static int	pdt_below_sizemax(size_t count, size_t size)
{
	if (count == 0 || size == 0)
		return (1);
	if ((SIZE_MAX / count) < size)
		return (0);
	return (1);
}

/*My notes
Hard to test correct size

size max overflow
-5 and -5
*/
