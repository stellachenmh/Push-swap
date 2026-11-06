/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelchen <stelchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 17:34:50 by stelchen          #+#    #+#             */
/*   Updated: 2026/10/08 17:39:43 by stelchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

/*My notes
Prev version
	// t_list	*curr_node;
	// t_list	*prev_node;
	// prev_node = lst;
	// curr_node = lst->next;
	// while (1)
	// {
	// 	if (curr_node == NULL)
	// 		break ;
	// 	prev_node = curr_node;
	// 	curr_node = curr_node->next;
	// }
	// return (prev_node);

*/