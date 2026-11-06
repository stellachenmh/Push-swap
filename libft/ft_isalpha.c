/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelchen <stelchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 17:33:50 by stelchen          #+#    #+#             */
/*   Updated: 2026/10/08 17:33:51 by stelchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c > 64 && c < 91) || (c > 96 && c < 123))
		return (1);
	else
		return (0);
}

/*My notes
Isalpha. Test for true isupper or islower. 3?
*Unsigned char or EOF value - what to do?
- Appn to ensure https://pubs.opengroup.org/onlinepubs/
009604499/functions/isalpha.html
Only in ASCII?
Must pass only single char, in single quotes

Isalpha cannot compile if no character given. Google, undef behav
Must validate input BEFORE calling isalpha

isascii, using octal vs decimal, Gemini
If c is passed as a signed char with a negative value (for example,
extended ASCII characters like 0x80 to 0xFF which evaluate to negative
numbers when converted to a signed int), a simple decimal range check
will correctly evaluate to 0 (false), whereas an improperly cast
bitwise check might produce unexpected results depending on sign extension.

How do I test isascii?
Wide characters. '' means 1-byte char

Escape sequences works only with octal or hex.


To KIV:
What about actual integers?
Handle unsigned chars?

*/
