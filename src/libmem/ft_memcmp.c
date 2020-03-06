/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <awoimbee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 00:50:54 by awoimbee          #+#    #+#             */
/*   Updated: 2020/03/06 01:00:05 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	uc1;
	unsigned char	uc2;

	while (n--)
	{
		uc1 = *(unsigned char *)s1;
		uc2 = *(unsigned char *)s2;
		if (uc1 != uc2)
			return (uc1 - uc2);
		s1++;
		s2++;
	}
	return (0);
}
