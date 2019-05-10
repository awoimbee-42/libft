/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mempcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <awoimbee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 11:52:36 by awoimbee          #+#    #+#             */
/*   Updated: 2019/05/07 22:43:20 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdint.h>
#include <x86intrin.h>
#include <avxintrin.h>

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
	while (n-- > 0)
		*(unsigned char*)d++ = *((unsigned char *)s++);
}

static void	avx_memcpy(void *restrict d, const void *restrict s, size_t n)
{
	size_t		padd;

	if ((padd = 32U - ((uintptr_t)d % 32U)) != 0)
	{
		scalar_memcpy(d, s, padd);
		d += padd;
		s += padd;
		n -= padd;
	}
	while (n >= sizeof(__m256i))
	{
		d = __builtin_assume_aligned(d, 32);
		*(__m256i*)d = _mm256_loadu_si256(s);
		s += sizeof(__m256i);
		d += sizeof(__m256i);
		n -= sizeof(__m256i);
	}
	scalar_memcpy(d, s, n);
}

static void	sse_memcpy(void *restrict d, const void *restrict s, size_t n)
{
	size_t		padd;

	if ((padd = 16U - ((uintptr_t)d % 16U)) != 0)
	{
		scalar_memcpy(d, s, padd);
		d += padd;
		s += padd;
		n -= padd;
	}
	while (n >= sizeof(__m128i))
	{
		d = __builtin_assume_aligned(d, 16);
		*(__m128i*)d = _mm_loadu_si128(s);
		s += sizeof(__m128i);
		d += sizeof(__m128i);
		n -= sizeof(__m128i);
	}
	scalar_memcpy(d, s, n);
}

void		*ft_mempcpy(void *restrict dst, const void *restrict src, size_t n)
{
	if (LFT_AVX && n > sizeof(__m256i))
		avx_memcpy(dst, src, n);
	else if (LFT_SSE2 && n > sizeof(__m128i))
		sse_memcpy(dst, src, n);
	else
		scalar_memcpy(dst, src, n);
	return (dst + n);
}
