/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gb_defrag.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <awoimbee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 02:20:17 by awoimbee          #+#    #+#             */
/*   Updated: 2020/03/06 00:28:04 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/t_garbage.h>
#include <libft/ft_mem.h>

/*
**	This function restructurates the garbage collectors array.
**	It is automatically called by gb_free()
*/

void		gb_defrag(t_garbage *gb)
{
	void		**end;
	void		**it;
	void		**it2;

	end = &gb->pointers[gb->arr_len];
	it = gb->pointers;
	while (it < end)
	{
		if (*it == NULL)
		{
			it2 = &it[1];
			while (it2 != end && *it2 == NULL)
				it2 = &it2[1];
			ft_memcpy(it, it2, (end - it2) * sizeof(void**));
			gb->arr_len -= (it2 - it);
			end = &gb->pointers[gb->arr_len];
		}
		it = &it[1];
	}
}
