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

int	main(int argc, char **argv)
{
	int		size;
	t_stack	*a;
	t_stack	*b;
	int		tmp[1000];
	int		empty[] = {};

	for (int i = 1; i < argc; i++)
	{
		tmp[i - 1] = ft_atoi(argv[i]); // Need to check for valid inputs
	}
	size = argc - 1;
	a = stack_init(tmp, size, size);
	b = stack_init(empty, 0, size);
	
	// If no args given (size 0), display nothing and give prompt back
	
	// KIV what this should return and when run
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
	
	if (a->size > 5 || a->size == 1)
		return ;
	while (a->size > 3) // do I call rank ints again? No, assume called already
	{
		max_idx = find_max_idx(a);
		move_idx_to_top(a, max_idx, 'a');
		pb(a, b); // Does this work even if b already has things on it?
	}
	if (a->size == 3)
		sort_three_ints(a);
	else if (a->size == 2 && (compute_disorder(a) != 0)) // defensive but redundant
		
	// return from stack b 1 or 2 elements
}

/*
Add code that will be shared by all three sorting strategies
If size is 0, do what?
If size is 1, do what?
If size is 2 AND disorder is 1, swap. Otherwise return
Sort 3 ints
Sort 4
Sort 5

Within each algo, call sort X ints once it gets to that level

*/