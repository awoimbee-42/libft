/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <awoimbee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 00:39:36 by awoimbee          #+#    #+#             */
/*   Updated: 2018/11/06 15:14:30 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
	return (NULL);
}
