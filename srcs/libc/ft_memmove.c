/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <awoimbee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 22:59:38 by awoimbee          #+#    #+#             */
/*   Updated: 2018/11/06 17:56:41 by awoimbee         ###   ########.fr       */
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
	{
		while (len-- > 0)
			*d++ = *s++;
	}
	else if (src < dst)
	{
		while (len > 0)
		{
			--len;
			d[len] = s[len];
		}
	}
	return (dst);
}
