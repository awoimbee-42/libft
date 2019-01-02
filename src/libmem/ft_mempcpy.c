/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mempcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <awoimbee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 11:52:36 by awoimbee          #+#    #+#             */
/*   Updated: 2019/01/02 04:22:50 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_mempcpy(void *restrict dst, const void *restrict src, size_t n)
{
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
	return (dst);
}
