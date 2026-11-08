/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelchen <stelchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/07 14:16:38 by stelchen          #+#    #+#             */
/*   Updated: 2026/11/08 16:05:21 by stelchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/**
 * Checks if user entered the optional flags --bench or --(strategy name)
 and activates the respective mode. A flag can be entered alone or together
 with the other flag. 'bench' must come before the strategy flag if any.
 Flags must be entered before the int arguments.
 */


 
int	parse_flags(int size, char **argv) // KIV int return type. For bool
{
	
}
 // Start from argv[1]