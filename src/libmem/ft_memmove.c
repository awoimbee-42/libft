/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <awoimbee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 22:59:38 by awoimbee          #+#    #+#             */
/*   Updated: 2019/01/02 04:06:34 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*d;
	const unsigned char	*s;

	d = (unsigned char *)dst;
	s = (const unsigned char *)src;
	if (src > dst)
		(void)ft_mempcpy(dst, src, len);
	else if (src < dst)
	{
		while (len > 0)
		{
			--len;
			((unsigned char*)d)[len] = ((const unsigned char*)s)[len];
		}
	}
	return (dst);
}
