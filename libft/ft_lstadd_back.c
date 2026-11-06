/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelchen <stelchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 17:34:21 by stelchen          #+#    #+#             */
/*   Updated: 2026/10/08 17:40:39 by stelchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*curr_node;

	if (!lst || !new)
		return ;
	curr_node = *lst;
	if (curr_node == NULL)
	{
		*lst = new;
		return ;
	}
	while (curr_node->next)
		curr_node = curr_node->next;
	curr_node->next = new;
	return ;
}

/*My notes
Must be able to add a new node to empty list
Check if my other fxs handle empty list

Avoid dereferencing a null ptr
Update original head, not local copy
Double ptr. Which one is null? Do what if each is null?

AI edge cases - empty double ptr, empty new, empty list. Done
Setting to 'null' affects local copy. Change lst new instead

*/