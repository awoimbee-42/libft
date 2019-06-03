/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <awoimbee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 01:06:53 by awoimbee          #+#    #+#             */
/*   Updated: 2019/06/03 17:14:15 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdint.h>
#include <x86intrin.h>
#include <avxintrin.h>

/*
**	In scalar memcpy we try to use the native cpu register widths
**	before falling back to using char to finish it off
*/

static void	scalar_memcpy(void *restrict d, const void *restrict s, size_t n)
{
	while (n >= sizeof(uintmax_t))
	{
		*(uintmax_t*)d = *(uintmax_t*)s;
		d += sizeof(uintmax_t);
		s += sizeof(uintmax_t);
		n -= sizeof(uintmax_t);
	}
	while (n >= sizeof(unsigned int))
	{
		*(unsigned int*)d = *(unsigned int*)s;
		d += sizeof(unsigned int);
		s += sizeof(unsigned int);
		n -= sizeof(unsigned int);
	}
	while (n > 0)
	{
		*(unsigned char*)d++ = *((unsigned char *)s++);
		--n;
	}
}

static void	sse_memcpy(void *restrict d, const void *restrict s, size_t n)
{
	while (n >= sizeof(__m128i))
	{
		_mm_storeu_si128(d, _mm_loadu_si128(s));
		s += sizeof(__m128i);
		d += sizeof(__m128i);
		n -= sizeof(__m128i);
	}
	scalar_memcpy(d, s, n);
}

void		*ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	if (LFT_SSE2)
		sse_memcpy(dst, src, n);
	else
		scalar_memcpy(dst, src, n);
	return (dst);
}
