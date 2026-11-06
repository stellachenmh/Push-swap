/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelchen <stelchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 17:34:55 by stelchen          #+#    #+#             */
/*   Updated: 2026/10/08 17:34:56 by stelchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*clear_lst_return_null(t_list **head, void (*del)(void *));

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	void	*new_content;
	t_list	*new_head;
	t_list	*new_node;

	if (!lst || !f || !del)
		return (NULL);
	new_head = NULL;
	while (lst)
	{
		new_content = f(lst->content);
		if (!new_content)
			return (clear_lst_return_null(&new_head, del));
		new_node = ft_lstnew(new_content);
		if (!new_node)
		{
			del(new_content);
			return (clear_lst_return_null(&new_head, del));
		}
		ft_lstadd_back(&new_head, new_node);
		lst = lst->next;
	}
	return (new_head);
}

static t_list	*clear_lst_return_null(t_list **head, void (*del)(void *))
{
	ft_lstclear(head, del);
	return (NULL);
}

/*My notes

Possible for creating new content to fail

Main testing mistakes
- Created node contents with stack memory, so can't modify or del
- Called lst add back with **NULL instead of &NULL
- Threw away return value of mapped list, printed old list instead
- Passed function wrongly in parameter 2
- Didn't realise lstnew and addback already modify next
- Didn't realise addback works w empty list
- Didn't delete already-made content

*/