/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <awoimbee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 22:59:38 by awoimbee          #+#    #+#             */
/*   Updated: 2019/01/25 23:22:46 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	rev_memcpy(void *d, const void *s, size_t len)
{
	while (len >= sizeof(unsigned long long))
	{
		len -= sizeof(unsigned long long);
		*(unsigned long long*)(d + len) =
			*(const unsigned long long*)(s + len);
	}
	while (len >= sizeof(unsigned short))
	{
		len -= sizeof(unsigned short);
		*(unsigned short*)(d + len) = *(const unsigned short*)(s + len);
	}
	if (len > 0)
	{
		--len;
		((unsigned char*)d)[len] = ((const unsigned char*)s)[len];
	}
}

void		*ft_memmove(void *dst, const void *src, size_t len)
{
	if (src > dst)
		(void)ft_mempcpy(dst, src, len);
	else if (src < dst)
		rev_memcpy(dst, src, len);
	return (dst);
}
