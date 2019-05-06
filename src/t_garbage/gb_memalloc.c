/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gb_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <awoimbee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 20:24:44 by awoimbee          #+#    #+#             */
/*   Updated: 2019/05/06 14:49:44 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*gb_memalloc(t_garbage *gb, size_t size)
{
	void		*tmp;

	if (gb->arr_len == gb->mem_len)
	{
		gb->mem_len *= 2;
		tmp = realloc(gb->pointers, gb->mem_len);
		if (!__builtin_expect((long)tmp, 1))
			intrin__gb_fail(gb);
		gb->pointers = tmp;
	}
	gb->pointers[gb->arr_len] = ft_memalloc(size);
	if (!__builtin_expect((long)gb->pointers[gb->arr_len], 1))
		intrin__gb_fail(gb);
	return (gb->pointers[gb->arr_len++]);
}
