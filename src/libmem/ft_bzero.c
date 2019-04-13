/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <awoimbee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 01:07:01 by awoimbee          #+#    #+#             */
/*   Updated: 2019/04/13 02:30:16 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdint.h>

/*
**	ffs I would like to use __m256i from x86intrin.h
*/

void	ft_bzero(void *s, size_t n)
{
	while (n >= sizeof(__uint128_t))
	{
		n -= sizeof(__uint128_t);
		*(__uint128_t*)(s) = 0;
		s += sizeof(__uint128_t);
	}
	while (n >= sizeof(uint64_t))
	{
		n -= sizeof(uint64_t);
		*(uint64_t*)(s) = 0;
		s += sizeof(uint64_t);
	}
	while (n >= sizeof(uint16_t))
	{
		n -= sizeof(uint16_t);
		*(uint16_t*)(s) = 0;
		s += sizeof(uint16_t);
	}
	if (n > 0)
		*(char*)s = 0;
}
