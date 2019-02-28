/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <awoimbee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 01:07:01 by awoimbee          #+#    #+#             */
/*   Updated: 2019/02/17 18:37:35 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdint.h>

void	ft_bzero(void *s, size_t n)
{
	s = s + n;
	while (n >= sizeof(__uint128_t))
	{
		n -= sizeof(__uint128_t);
		s -= sizeof(__uint128_t);
		*(__uint128_t*)(s) = 0;
	}
	while (n >= sizeof(long long))
	{
		n -= sizeof(long long);
		s -= sizeof(long long);
		*(unsigned long long*)(s) = 0;
	}
	while (n >= sizeof(short))
	{
		n -= sizeof(short);
		s -= sizeof(short);
		*(unsigned short*)(s) = 0;
	}
	if (n > 0)
		*(char*)--s = 0;
}
