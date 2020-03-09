/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <awoimbee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 00:39:36 by awoimbee          #+#    #+#             */
/*   Updated: 2020/03/06 01:00:16 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*src;
	unsigned char	*src_end;

	src = (unsigned char *)s;
	src_end = (unsigned char *)(s + n);
	while (src != src_end)
	{
		if (*src == (unsigned char)c)
			return ((void *)src);
		++src;
	}
	return (0);
}
