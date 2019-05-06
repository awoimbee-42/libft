/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <awoimbee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 22:59:38 by awoimbee          #+#    #+#             */
/*   Updated: 2019/05/06 19:56:07 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <inttypes.h>

static void	rev_memcpy(void *d, const void *s, size_t len)
{
	while (len >= sizeof(uint64_t))
	{
		len -= sizeof(uint64_t);
		*(uint64_t*)(d + len) = *(const uint64_t*)(s + len);
	}
	while (len >= sizeof(uint16_t))
	{
		len -= sizeof(uint16_t);
		*(uint16_t*)(d + len) = *(const uint16_t*)(s + len);
	}
	if (len > 0)
	{
		--len;
		((uint8_t*)d)[len] = ((const uint8_t*)s)[len];
	}
}

static void	std_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	while (n >= sizeof(uint64_t))
	{
		*(uint64_t*)dst = *(uint64_t *)src;
		dst += sizeof(uint64_t);
		src += sizeof(uint64_t);
		n -= sizeof(uint64_t);
	}
	while (n >= sizeof(uint32_t))
	{
		*(uint32_t*)dst = *(uint32_t*)src;
		dst += sizeof(uint32_t);
		src += sizeof(uint32_t);
		n -= sizeof(uint32_t);
	}
	while (n-- > 0)
		*(unsigned char*)dst++ = *((unsigned char *)src++);
}

void		*ft_memmove(void *dst, const void *src, size_t len)
{
	if (src > dst)
		std_memcpy(dst, src, len);
	else if (src < dst)
		rev_memcpy(dst, src, len);
	return (dst);
}
