/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelchen <stelchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 17:35:00 by stelchen          #+#    #+#             */
/*   Updated: 2026/10/08 17:35:01 by stelchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstnew(void *content)
{
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}

/*My notes
Dot for actual node, arrow if pointer to node
How to create a linked list https://www.geeksforgeeks.org/c/how-to-create-a-
linked-list-in-c/
-> has precedence over *

lst = &new changed local copy of lst. Must deref.

Address of the POINTER to node, vs address of node itself
== for two pointers check if they point at same thing
Comparing pointers checks addresses stored,
	not values of what they point to. More relev for < >?
https://www.tutorialspoint.com/article/how-to-compare-pointers-in-c-cplusplus

List new
Can pass a NULL ptr for content. Valid. Del heap can handle

List last
	Orig static lst ptr
	t_list **lst_ptr;
	lst_ptr = &node1;
	t_list *orig_listhead = *lst_ptr;

	Testing
	// printf("Content of last node: %s\n",
		(char *)((ft_lstlast(*lst_ptr))->content));
	// printf("Address of last node %p, address of node1 %p, address of node2
		%p", &(*ft_lstlast(*lst_ptr)), &node1, &node2);
	// assert(*lst_ptr == node2);
	// assert((*lst_ptr)->next == node1);

*node3.content vs node3->content?

void * vs char *
I can create node3 using char* contents rather than void*
But to print contents as str, must cast void* to char*

lst size, old code
	count = 1; // Handle null ptr
	curr_node = lst->next; // Equivalent to *lst.next?
	while (1)
	{
		if (curr_node == NULL)
			break ;
		count++;
		curr_node = curr_node->next;
	}
*/
