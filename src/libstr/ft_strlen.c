/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <awoimbee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 01:17:54 by awoimbee          #+#    #+#             */
/*   Updated: 2019/05/05 03:14:13 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <x86intrin.h>
#include <inttypes.h>

// size_t	ft_strlen(const char *s)
// {
// 	const char	*start;

// 	start = s;
// 	while (*s)
// 		++s;
// 	return ((size_t)(s - start));
// }

/*
**	We first align the data on 16 bytes (else we cannot use sse)
**	Then we load the strings characters and apply a mask on them to check if
**		one of them is 0 ('\0')
**	If so we use __builtin_ctz() to find the position of this char
**		inside the register.
*/

size_t strlen(const char *str)
{
	register size_t	len;
	__m128i			zero;
	__m128i			chars;
	int				mask;

	len = 0;
	while ((uintptr_t)str % 16U != 0)
		if (*str++ == 0 || ++len == 0)
			return len;
	zero = _mm_setzero_si128();
	mask = 0;
	while (1)
	{
		chars = _mm_load_si128((__m128i *)str);
		mask = _mm_movemask_epi8(_mm_cmpeq_epi8(chars, zero));
		if (mask != 0)
		{
			len += __builtin_ctz(mask);
			break;
		}
		str += sizeof(__m128i);
		len += sizeof(__m128i);
	}
	return len;
}