/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_compute_disorder.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simonlau <simonlau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 18:54:48 by stelchen          #+#    #+#             */
/*   Updated: 2026/10/26 14:03:38 by simonlau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "tst.h"
#include <limits.h>

tstsuite("Compute disorder")
{
	int		arr_single[1] = {5};
	int		arr_sorted[] = {INT_MIN, -6, -4, 0, 15};
	int		arr_rev_sorted[] = {INT_MAX, 9999, 405};
	int		arr_onethird_sorted[] = {2, 1, 3, 4};
	int		arr_half_sorted[] = {3, 4, 1, 2};
	t_stack	empty = {NULL, 0, 0};
	t_stack	*single;
	t_stack	*sorted;
	t_stack	*rev_sorted;
	t_stack	*onethird_sorted;
	t_stack	*half_sorted;

	single = stack_init(arr_single, 1, 1);
	sorted = stack_init(arr_sorted, 5, 5);
	rev_sorted = stack_init(arr_rev_sorted, 3, 3);
	onethird_sorted = stack_init(arr_onethird_sorted, 4, 4);
	half_sorted = stack_init(arr_half_sorted, 4, 4);
	tstcase("empty and singleton stacks have zero disorder")
	{
		tstexpect(compute_disorder(&empty) == 0);
		tstexpect(compute_disorder(single) == 0);
		tstexpect(compute_disorder(NULL) == 0);
	}
	tstcase("disorder reflects inversions")
	{
		tstexpect(compute_disorder(sorted) == 0);
		tstexpect(compute_disorder(rev_sorted) == 1);
		tstexpect(compute_disorder(onethird_sorted)
			< compute_disorder(half_sorted));
	}
	stack_destroy(&single);
	stack_destroy(&sorted);
	stack_destroy(&rev_sorted);
	stack_destroy(&onethird_sorted);
	stack_destroy(&half_sorted);
}
