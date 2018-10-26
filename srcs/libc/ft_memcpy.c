/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <awoimbee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 01:06:53 by awoimbee          #+#    #+#             */
/*   Updated: 2018/10/23 20:35:41 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char *d;
	const char *s;

	d = (char *)dest;
	s = (const char *)src;
	while (n-- > 0)
	{
		d[n] = s[n];
	}
	return (dest);
}