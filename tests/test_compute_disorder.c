/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_compute_disorder.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simonlau <simonlau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 18:54:48 by stelchen          #+#    #+#             */
/*   Updated: 2026/10/26 14:01:54 by simonlau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <assert.h>
#include <limits.h>
#include <stdio.h>

int	main(void)
{
	int		arr_single[1] = {5};
	t_stack	*single;
	t_stack	*sorted;
	t_stack	*rev_sorted;
	t_stack	*onethird_sorted;
	t_stack	*half_sorted;

	int arr_sorted[] = {INT_MIN, -6, -4, 0, 15}; // 0 mistakes, 10 total pairs
	int arr_rev_sorted[] = {INT_MAX, 9999, 405}; // 3 mistakes, 3 total pairs
	int arr_onethird_sorted[] = {2, 1, 3, 4};    // 1 mistake, 6 total pairs
	int arr_half_sorted[] = {3, 4, 1, 2};        // 4 mistakes, 6 total pairs
	single = stack_init(arr_single, 1, 1);
	sorted = stack_init(arr_sorted, 5, 5);
	rev_sorted = stack_init(arr_rev_sorted, 3, 3);
	onethird_sorted = stack_init(arr_onethird_sorted, 4, 4);
	half_sorted = stack_init(arr_half_sorted, 4, 4);
	assert(compute_disorder(single) == 0);
	assert(compute_disorder(sorted) == 0);
	assert(compute_disorder(rev_sorted) == 1);
	assert(compute_disorder(onethird_sorted) < compute_disorder(half_sorted));
	// printf("One third: %f, half: %f", compute_disorder(onethird_sorted),
	// compute_disorder(half_sorted));
	stack_destroy(single);
	stack_destroy(sorted);
	stack_destroy(rev_sorted);
	stack_destroy(onethird_sorted);
	stack_destroy(half_sorted);
}
