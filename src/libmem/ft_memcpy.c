/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <awoimbee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 01:06:53 by awoimbee          #+#    #+#             */
/*   Updated: 2019/05/05 17:44:05 by awoimbee         ###   ########.fr       */
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
	while ((uintptr_t)s % 32U != 0)
	{
		*(unsigned char*)d++ = *((unsigned char *)s++);
		--n;
	}
	while (n >= sizeof(__m256i))
	{
		s = __builtin_assume_aligned(s, 32);
		d = __builtin_assume_aligned(d, 32);
		*(__m256i*)d = *(__m256i*)s;
		s += sizeof(__m256i);
		d += sizeof(__m256i);
		n -= sizeof(__m256i);
	}
	scalar_memcpy(d, s, n);
}

static void	sse_memcpy(void *restrict d, const void *restrict s, size_t n)
{
	while ((uintptr_t)s % 16U != 0)
	{
		*(unsigned char*)d++ = *((unsigned char *)s++);
		--n;
	}
	while (n >= sizeof(__m128i))
	{
		s = __builtin_assume_aligned(s, 32);
		d = __builtin_assume_aligned(d, 32);
		*(__m128i*)d = *(__m128i*)s;
		s += sizeof(__m128i);
		d += sizeof(__m128i);
		n -= sizeof(__m128i);
	}
	scalar_memcpy(d, s, n);
}

void		*ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	if (LFT_AVX && n > sizeof(__m256i) + 16)
		avx_memcpy(dst, src, n);
	else if (!LFT_AVX && n > sizeof(__m128i) + 8)
		sse_memcpy(dst, src, n);
	else
		scalar_memcpy(dst, src, n);
	return (dst);
}
