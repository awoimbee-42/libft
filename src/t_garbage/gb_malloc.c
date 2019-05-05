/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gb_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <awoimbee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 20:44:45 by awoimbee          #+#    #+#             */
/*   Updated: 2019/05/05 20:57:04 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*gb_malloc(t_garbage *gb, size_t size)
{
	void		*tmp;

	if (gb->arr_len == gb->mem_len)
	{
		gb->mem_len = gb->mem_len == 0 ? 10 : gb->mem_len * 2;
		tmp = realloc(gb->pointers, gb->mem_len);
		if (!__builtin_expect((long)tmp, 1))
			intrin__gb_fail(gb);
		gb->pointers = tmp;
	}
	gb->pointers[gb->arr_len] = malloc(size);
	if (!__builtin_expect((long)gb->pointers[gb->arr_len], 1))
		intrin__gb_fail(gb);
	return (gb->pointers[gb->arr_len++]);
}
