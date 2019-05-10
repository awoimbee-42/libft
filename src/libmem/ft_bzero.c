/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <awoimbee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 01:07:01 by awoimbee          #+#    #+#             */
/*   Updated: 2019/05/07 20:56:42 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdint.h>
#include <x86intrin.h>
#include <avxintrin.h>

static void		scalar_bzero(void *s, size_t n)
{
	while (n >= sizeof(uint64_t))
	{
		n -= sizeof(uint64_t);
		*(uint64_t*)(s) = 0;
		s += sizeof(uint64_t);
	}
	while (n >= sizeof(uint16_t))
	{
		n -= sizeof(uint16_t);
		*(uint16_t*)(s) = 0;
		s += sizeof(uint16_t);
	}
	if (n > 0)
		*(char*)s = 0;
}

static void		avx_bzero(void *s, size_t n)
{
	size_t		padd;

	if ((padd = 32U - (uintptr_t)s % 32U) != 0)
	{
		scalar_bzero(s, padd);
		s += padd;
		n -= padd;
	}
	while (n >= sizeof(__m256i))
	{
		s = __builtin_assume_aligned(s, 32);
		*(__m256i*)s = _mm256_setzero_si256();
		s += sizeof(__m256i);
		n -= sizeof(__m256i);
	}
	scalar_bzero(s, n);
}

static void		sse_bzero(void *s, size_t n)
{
	size_t		padd;

	if ((padd = 16U - (uintptr_t)s % 16U) != 0)
	{
		scalar_bzero(s, padd);
		s += padd;
		n -= padd;
	}
	while (n >= sizeof(__m128i))
	{
		s = __builtin_assume_aligned(s, 16);
		*(__m128i*)s = _mm_setzero_si128();
		s += sizeof(__m128i);
		n -= sizeof(__m128i);
	}
	scalar_bzero(s, n);
}

void			ft_bzero(void *s, size_t n)
{
	if (LFT_AVX && n > sizeof(__m256i) * 2)
		avx_bzero(s, n);
	else if (LFT_SSE2 && n > sizeof(__m128i) * 2)
		sse_bzero(s, n);
	else
		scalar_bzero(s, n);
}
