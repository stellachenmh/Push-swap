/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rank_ints.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelchen <stelchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 15:25:18 by stelchen          #+#    #+#             */
/*   Updated: 2026/10/22 15:39:15 by stelchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/**
 * @brief Takes a stack, ranks its integer values then replaces the stack's
 * data with the array of ranks. E.g. data {10, 30, 20} would be replaced
 * by {0, 2, 1}. No-op for stack size 1.
 * To test: Output if stack size is 0 or 1. Check that stack data has been
 * replaced (differs from old data) but has the same disorder value.
 * 
 * void vs new stack...you need malloc anyway
 */

void	rank_ints(t_stack *a)
{
	int		*rank_data;
	size_t	i;
	size_t	j;

	rank_data = malloc((a->size) * sizeof(*(a->data))); // Does this return ptr size or int size? Derefs. * vs -> priority?
	if (!rank_data)
		return ; // No warning msg? 
	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{

			j++;
		}
		i++;
	}
}