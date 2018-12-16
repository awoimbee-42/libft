/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 01:22:21 by awoimbee          #+#    #+#             */
/*   Updated: 2018/12/16 17:53:27 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char *d;

	d = (unsigned char *)dst;
	while (n-- != 0)
	{
		if ((*d++ = *((unsigned char *)src++)) == (unsigned char)c)
			return ((void *)d);
	}
	return (NULL);
}
