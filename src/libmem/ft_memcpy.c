/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <awoimbee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 01:06:53 by awoimbee          #+#    #+#             */
/*   Updated: 2019/01/25 23:19:23 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	void	*dst_start;

	dst_start = dst;
	while (n >= sizeof(unsigned long))
	{
		*(unsigned long*)dst = *(unsigned long *)src;
		dst += sizeof(unsigned long);
		src += sizeof(unsigned long);
		n -= sizeof(unsigned long);
	}
	while (n >= sizeof(unsigned int))
	{
		*(unsigned int*)dst = *(unsigned int*)src;
		dst += sizeof(unsigned int);
		src += sizeof(unsigned int);
		n -= sizeof(unsigned int);
	}
	while (n-- > 0)
		*(unsigned char*)dst++ = *((unsigned char *)src++);
	return (dst_start);
}
