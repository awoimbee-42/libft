/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gb_add.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <awoimbee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 21:16:26 by awoimbee          #+#    #+#             */
/*   Updated: 2020/03/06 00:28:04 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/t_garbage.h>

/*
**	Used to add a pointer allocated from different means to the garbage list
**	Panics if malloced == NULL !
*/

void		*gb_add(t_garbage *gb, void *malloced)
{
	if (malloced == NULL)
		intrin__gb_fail(gb);
	if (gb->arr_len == gb->mem_len)
		intrin_gb_extend(gb);
	gb->pointers[gb->arr_len] = malloced;
	gb->arr_len++;
	return (malloced);
}
