/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_check_duplicates.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelchen <stelchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 17:17:51 by stelchen          #+#    #+#             */
/*   Updated: 2026/10/19 17:24:29 by stelchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <assert.h> 

int	has_duplicates(const int *arr, int size); 

int main(void)
{
	int size0[0];
	int size1[1] = {3};
	int size2uniq[2] = {5, 6};
	int size2dupe[2] = {5, 5};
	int	size7uniq[7] = {-1, 2, -4, 3, 5, 6, 0};
	int size7dupe[7] = {1, 2, 3, 4, 5, 6, 6};
	
	assert(has_duplicates(size0, 0) == -1);
	assert(has_duplicates(size1, 1) == 0);
	assert(has_duplicates(size2uniq, 2) == 0);
	assert(has_duplicates(size2dupe, 2) == 1);
	assert(has_duplicates(size7uniq, 7) == 0);
	assert(has_duplicates(size7dupe, 7) == 1);
}