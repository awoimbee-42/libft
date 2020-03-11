/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_endian.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <awoimbee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 17:46:49 by awoimbee          #+#    #+#             */
/*   Updated: 2020/03/11 19:19:25 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/ft_defines.h>
#include <inttypes.h>

uint64_t	ft_swap_endian64(uint64_t val)
{
	if (LFT_SSE2)
		return (__builtin_bswap64(val));
	val = (val & 0x00000000FFFFFFFF) << 32 | (val & 0xFFFFFFFF00000000) >> 32;
	val = (val & 0x0000FFFF0000FFFF) << 16 | (val & 0xFFFF0000FFFF0000) >> 16;
	val = (val & 0x00FF00FF00FF00FF) << 8 | (val & 0xFF00FF00FF00FF00) >> 8;
	return (val);
}

uint32_t	ft_swap_endian32(uint32_t val)
{
	if (LFT_SSE2)
		return (__builtin_bswap32(val));
	val = ((val << 8) & 0xFF00FF00) | ((val >> 8) & 0x00FF00FF);
	return (val << 16) | (val >> 16);
}

uint16_t	ft_swap_endian16(uint16_t val)
{
	if (LFT_SSE2)
		return (__builtin_bswap16(val));
	val = (uint16_t)(val << 8) | (uint16_t)(val >> 8);
	return (val);
}
