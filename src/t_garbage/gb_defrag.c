/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gb_defrag.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <awoimbee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 02:20:17 by awoimbee          #+#    #+#             */
/*   Updated: 2019/05/05 17:44:38 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	This function restructurates the garbage collectors array.
**	It should be called if a lot of elements are freed and malloced
*/

void		gb_defrag(t_garbage *gb)
{
	size_t		i;
	size_t		nb_bad;

	i = 0;
	while (i < gb->arr_len)
	{
		if (gb->pointers[i] == NULL)
		{
			nb_bad = 1;
			while (gb->pointers[i + nb_bad] == NULL)
				++nb_bad;
			ft_mempcpy(&gb->pointers[i],
				&gb->pointers[i + nb_bad],
				nb_bad * sizeof(void*));
			gb->arr_len -= nb_bad;
		}
		++i;
	}
}
