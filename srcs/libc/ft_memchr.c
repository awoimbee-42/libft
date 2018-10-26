/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <awoimbee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 00:39:36 by awoimbee          #+#    #+#             */
/*   Updated: 2018/10/24 00:50:25 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned int	i;
	unsigned char	*src;
	unsigned char	d;

	src = (unsigned char *)s;
	d = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (src[i] == d)
			return ((void *)s + i);
		++i;
	}
	return (NULL);
}