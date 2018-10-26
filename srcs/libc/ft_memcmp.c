/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <awoimbee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 00:50:54 by awoimbee          #+#    #+#             */
/*   Updated: 2018/10/24 01:59:07 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char uc1, uc2;

    while (n--)
	{
		uc1 = *(unsigned char *) s1;
		uc2 = *(unsigned char *) s2;
		if ( uc1 != uc2)
			return (uc1 - uc2);
		s1++;
		s2++;
    }
    return (0);
}