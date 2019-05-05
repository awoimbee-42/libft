/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gb_add.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <awoimbee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 21:16:26 by awoimbee          #+#    #+#             */
/*   Updated: 2019/05/05 17:44:34 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Function used to add a pointer allocated from different means
**		to the garbage list
*/

void		*gb_add(t_garbage *gb, void *malloced)
{
	void		*tmp;

	if (gb->arr_len == gb->mem_len)
	{
		gb->mem_len *= 2;
		tmp = realloc(gb->pointers, gb->mem_len);
		if (!__builtin_expect((long)tmp, 1))
		{
			free(malloced);
			intrin__gb_fail(gb);
		}
		gb->pointers = tmp;
	}
	gb->pointers[gb->arr_len] = malloced;
	gb->arr_len++;
	return (malloced);
}
