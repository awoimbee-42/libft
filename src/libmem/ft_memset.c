/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <awoimbee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 01:07:04 by awoimbee          #+#    #+#             */
/*   Updated: 2020/03/06 00:59:08 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>

void	*ft_memset(void *s, int c, size_t len)
{
	while (len-- > 0)
		((unsigned char *)s)[len] = (unsigned char)c;
	return (s);
}
