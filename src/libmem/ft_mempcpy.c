/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mempcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <awoimbee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 11:52:36 by awoimbee          #+#    #+#             */
/*   Updated: 2019/04/11 14:59:39 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdint.h>

void	*ft_mempcpy(void *restrict dst, const void *restrict src, size_t n)
{
	while (n >= sizeof(uintmax_t))
	{
		*(uintmax_t*)dst = *(uintmax_t*)src;
		dst += sizeof(uintmax_t);
		src += sizeof(uintmax_t);
		n -= sizeof(uintmax_t);
	}
	while (n >= sizeof(unsigned int))
	{
		*(unsigned int*)dst = *(unsigned int*)src;
		dst += sizeof(unsigned int);
		src += sizeof(unsigned int);
		n -= sizeof(unsigned int);
	}
	while (n > 0)
	{
		*(unsigned char*)dst++ = *((unsigned char *)src++);
		--n;
	}
	return (dst);
}
