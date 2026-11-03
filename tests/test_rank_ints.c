/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_rank_ints.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simonlau <simonlau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 21:52:01 by stelchen          #+#    #+#             */
/*   Updated: 2026/10/23 22:39:35 by simonlau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <assert.h>
#include <stdio.h>

int	main(void)
{
	int		input[] = {101, 98, -5, -553, -4234, -24111};
	int		expect[] = {5, 4, 3, 2, 1, 0};
	t_stack	*mystack;
	int		input2[] = {3, 1, 2};
	int		expect2[] = {2, 0, 1};
	t_stack	*mystack2;

	// Stack with disorder 1, expected ranks in descending order
	mystack = stack_init(input, 6, 6);
	rank_ints(mystack);
	for (size_t i = 0; i < mystack->size; i++)
		assert(expect[i] == mystack->data[i]);
	// Stack with slight disorder. Expect 2, 0, 1
	mystack2 = stack_init(input2, 3, 3);
	rank_ints(mystack2);
	for (size_t i = 0; i < mystack2->size; i++)
		assert(expect2[i] == mystack2->data[i]);
	stack_destroy(&mystack);
	stack_destroy(&mystack2);
}
