/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <awoimbee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 01:22:21 by awoimbee          #+#    #+#             */
/*   Updated: 2020/03/06 00:47:26 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <stddef.h>

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
