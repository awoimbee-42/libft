/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <awoimbee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 01:17:54 by awoimbee          #+#    #+#             */
/*   Updated: 2019/05/06 14:49:53 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intrisics.h"

/*
**	We first align the data on 16 bytes (for aligned sse loading)
**	Then we load the strings characters and apply a mask on them to check if
**		one of them is 0 ('\0')
**	If so we use __builtin_ctz() to find the position of this char
**		inside the register (int).
**	/!\ This implementation works because malloc is aligned on 16 bytes !
**		--> May cause segfault on older systems !!
**	/!\ Valgrind Freaks out when ft_fast_strlen() is used on haswell or newer
**		CPUs (because of BM1 I think)
*/

static inline size_t	ft_slow_strlen(const char *s)
{
	const char		*start;

	start = s;
	while (*s)
		++s;
	return ((size_t)(s - start));
}

static inline size_t	ft_fast_strlen(const char *str)
{
	__m128i			zero;
	__m128i			chars;
	unsigned int	mask;
	const char		*str_save;

	str_save = str;
	while ((uintptr_t)str % 16U != 0)
	{
		if (*str == 0)
			return (str - str_save);
		++str;
	}
	zero = _mm_setzero_si128();
	mask = 0U;
	while (mask == 0)
	{
		chars = _mm_load_si128((__m128i *)str);
		mask = _mm_movemask_epi8(_mm_cmpeq_epi8(chars, zero));
		str += sizeof(__m128i);
	}
	str += __builtin_ctz(mask) - sizeof(__m128i);
	return (str - str_save);
}

size_t					ft_strlen(const char *s)
{
	if (LFT_SSE2)
		return (ft_fast_strlen(s));
	else
		return (ft_slow_strlen(s));
}
