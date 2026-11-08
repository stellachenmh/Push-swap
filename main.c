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
#include <unistd.h>

// #include <stdio.h> // To update
#include <unistd.h> // stdout fileno


int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	return (0);

// 	int		size;
// 	t_stack	*a;
// 	t_stack	*b;
// 	int		*data;
// 	t_out	out;
// 	// int		tmp[1000];
// 	int		empty[] = {};
	
// 	// If no args given (size 0), display nothing and give prompt back
// 	if (argc == 1)
// 		return (EXIT_FAILURE); // Is it an exit failure? KIV

// 	// Check for flags before ints
	
// 	// Convert args to array of ints. Check for non-numeric and outside int range. Parse ints
// 	size = argc - 1; // KIV this way of doing size. Why did they increment it?
// 	data = parse_ints(size, argv);
// 	if (!data)
// 		return(write_errmsg(void)); // write error
// 	// Check for duplicates
// 	if (has_duplicates(data, size))
// 		return(write_errmsg(void));

// 	// Check again for size = 0? Why? Because of possible bench and complexity flag!

// 	// Create stacks
// 	a = stack_init(data, size, size); // why do we need both size and capacity? For malloc? 
// 	b = stack_init(empty, 0, size);

// // 	Check if list is already sorted. KIV what this should return and when run
// // 	Works for both small lists that sorted successfully, and big sorted lists
// // 	if (compute_disorder(a) == 0)
// // 		return (EXIT_SUCCESS);

// 	// Sort small stacks
// 	if (a->size <= 5)
// 	{
// 		rank_ints(a);
// 		sort_small_stk(a, b);
// 	}

	
// // 	// Call strategy selector?
// // 	sort_complex(a, b);
// // 	return (EXIT_SUCCESS);

// 	ft_bzero(&out, sizeof(out));
// 	out.fd = STDOUT_FILENO;
// 	sort_complex(a, b, &out);
// 	return (EXIT_SUCCESS);
}

// static int	write_errmsg(void)
// {
// 	ft_putstr_fd("Error\n", STDOUT_FILENO);
// 	return (0);
// }



/**
 * @brief Sorts lists of 1-5 elements efficiently. Does not check if list 
 * size is 0, left to caller (main). Does not check if list is already
 * sorted, also left to caller (main).
 */

// void	sort_small_stk(t_stack *a, t_stack *b) // add to .h
// {
// 	size_t	max_idx;
// 	size_t	pa_count;
	
// 	pa_count = 0;
// 	if (a->size > 5 || a->size == 1)
// 		return ;
// 	while (a->size > 3)
// 	{
// 		max_idx = find_max_idx(a);
// 		move_idx_to_top(a, max_idx, 'a');
// 		pb(a, b);
// 		pa_count++;
// 	}
// 	if (a->size == 3)
// 		sort_three_ints(a);
// 	else if (a->size == 2 && (compute_disorder(a) != 0)) // defensive but redundant. Not redundant
// 		sa(a);
// 	while (pa_count > 0)
// 	{
// 		pa(a, b);
// 		pa_count--;
// 	}
// 	return ;
// }

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

do we really need both size and capacity? 

*/
