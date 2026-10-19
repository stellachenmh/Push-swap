/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_duplicates.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelchen <stelchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 14:32:32 by stelchen          #+#    #+#             */
/*   Updated: 2026/10/19 15:38:14 by stelchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assert.h>

#define IDX_OFFSET 1

int	has_duplicates(const int *arr, int size)
{
	int i;
	int	j;
	
	if (!arr || size <= 0) // Pass no of ints, not argc directly
		return (-1);
	if (size == 1)
		return (0);
	i = 0;
	while (i < (size - IDX_OFFSET))
	{
		j = i + 1;
		while (j < size)
		{
			if (arr[i] == arr[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

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

// For each int, check it against every number FOLLOWING it in the array
// Which loop is outer, which inner? No to be checked, outside
// Inner loop starts at + 1, no need to check against itself or prev
// Where does each end? Outer loop should not check last char. Then
// inner loop won't even run on last char
// Inner loop should go all the way to last char 

// Size 2 array. Check pos 0 i against pos 1 j


/**
type int 'size' to match int argc
AI improvements: const int *arr, null ptr chk, else if unnecessary

 */
