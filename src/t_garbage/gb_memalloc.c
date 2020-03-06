/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gb_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <awoimbee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 20:24:44 by awoimbee          #+#    #+#             */
/*   Updated: 2020/03/06 00:28:04 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/t_garbage.h>
#include <libft/ft_mem.h>

void		*gb_memalloc(t_garbage *gb, size_t size)
{
	if (gb->arr_len == gb->mem_len)
		intrin_gb_extend(gb);
	gb->pointers[gb->arr_len] = ft_memalloc(size);
	if (!__builtin_expect((long)gb->pointers[gb->arr_len], 1))
		intrin__gb_fail(gb);
	return (gb->pointers[gb->arr_len++]);
}
