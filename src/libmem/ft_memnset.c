/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memnset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <awoimbee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 19:14:23 by awoimbee          #+#    #+#             */
/*   Updated: 2019/02/28 01:24:34 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdint.h>

void	ft_mem64set(uint64_t *mem, uint64_t data, size_t memlen)
{
	while (memlen-- > 0)
		*mem++ = data;
}

void	ft_mem32set(uint32_t *mem, uint32_t data, size_t memlen)
{
	while (memlen > 0)
	{
		--memlen;
		*mem++ = data;
	}
}

void	ft_mem16set(uint16_t *mem, uint16_t data, size_t memlen)
{
	while (memlen-- > 0)
		*mem++ = data;
}
