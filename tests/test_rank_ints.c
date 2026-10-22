/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_rank_ints.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelchen <stelchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 21:52:01 by stelchen          #+#    #+#             */
/*   Updated: 2026/10/22 21:52:16 by stelchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int main(void)
{
	// Stack with disorder 1, expected ranks in descending order
	int input[] = {101, 98, -5, -553, -4234, -24111};
	
	t_stack *mystack = stack_init(input, 6, 6);
	rank_ints(mystack);
	for (int i = 0; i < mystack->size; i++)
		printf("%i", mystack->data[i]);
	printf("\n");
	
	
	// Stack with slight disorder. Expect 2, 0, 1
	int input2[] = {3, 1, 2};
	
	t_stack *mystack2 = stack_init(input2, 3, 3);
	rank_ints(mystack2);
	for (int i = 0; i < mystack2->size; i++)
		printf("%i", mystack2->data[i]); 
}