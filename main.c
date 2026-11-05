/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+   */
/*                                                    +:+ +:+         +:+     */
/*   By: slau <slau@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 12:00:00 by slau             #+#    #+#             */
/*   Updated: 2026/10/15 12:00:00 by slau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

#include <stdio.h> // To update

int	main(int argc, char **argv)
{
	int		size;
	t_stack	*a;
	t_stack	*b;
	int		tmp[1000];
	int		empty[] = {};

	// If no args given (size 0), display nothing and give prompt back
	if (argc == 1)
	{
		printf("%s\n", argv[0]); // Change to ft printf. Does this meet subject pdf req?
		return (EXIT_FAILURE); // Is it an exit failure? 
	}
	// Move this to parser, and change to while loop
	for (int i = 1; i < argc; i++)
	{
		tmp[i - 1] = ft_atoi(argv[i]); // Need to check for valid inputs
	}
	
	// Create stacks
	size = argc - 1;
	a = stack_init(tmp, size, size);
	b = stack_init(empty, 0, size);
		
	// Call rank ints here, remove from each sort
	// Makes it hard to test them independently though
	if (a->size <= 5)
	{
		rank_ints(a);
		sort_small_stk(a, b);
	}
	// KIV what this should return and when run
	// Works for both small lists that sorted successfully, and big sorted lists
	if (compute_disorder(a) == 0)
		return (EXIT_SUCCESS);
	
	// Call strategy selector?
	sort_complex(a, b);
	return (EXIT_SUCCESS);
}

/**
 * @brief Sorts lists of 1-5 elements efficiently. Does not check if list 
 * size is 0, left to caller (main). Does not check if list is already
 * sorted, also left to caller (main).
 */

void	sort_small_stk(t_stack *a, t_stack *b) // add to .h
{
	size_t	max_idx;
	size_t	pa_count;
	
	pa_count = 0;
	if (a->size > 5 || a->size == 1)
		return ;
	while (a->size > 3)
	{
		max_idx = find_max_idx(a);
		move_idx_to_top(a, max_idx, 'a');
		pb(a, b);
		pa_count++;
	}
	if (a->size == 3)
		sort_three_ints(a);
	else if (a->size == 2 && (compute_disorder(a) != 0)) // defensive but redundant. Not redundant
		sa(a);
	while (pa_count > 0)
	{
		pa(a, b);
		pa_count--;
	}
	return ;
}

// Meaning?
// The program must display the smallest list of Push_swap operations possible to
// sort stack a, the smallest number being at the top.

/*
Add code that will be shared by all three sorting strategies
If size is 0, do what?
If size is 1, do what?
If size is 2 AND disorder is 1, swap. Otherwise return
Sort 3 ints
Sort 4
Sort 5

Within each algo, call sort X ints once it gets to that level

Test this
For a list originally of that size
For a whittled-down list
5 and 4 same line, reverts to 3
2 is separate. Sorted and unsorted
1
More than 5

*/
