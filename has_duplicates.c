/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_duplicates.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelchen <stelchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 14:32:32 by stelchen          #+#    #+#             */
/*   Updated: 2026/10/19 17:27:05 by stelchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
@param Size - pass no of ints, not argc directly. Type now 'int' to match int 
argc but can KIV using size_t instead and cast argc

 */

int	has_duplicates(const int *arr, const int size)
{
	int	i;
	int	j;

	if (!arr || size <= 0)
		return (-1);
	if (size == 1)
		return (0);
	i = 0;
	while (i < (size - 1))
	{
		j = i + 1;
		while (j < size)
		{
			if (arr[i] == arr[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
