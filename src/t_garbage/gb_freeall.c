/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gb_freeall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <awoimbee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 20:56:41 by awoimbee          #+#    #+#             */
/*   Updated: 2020/03/06 00:28:04 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/t_garbage.h>
#include <stdlib.h>

void		gb_freeall(t_garbage *gb)
{
	size_t		i;

	i = 0;
	while (i < gb->arr_len)
	{
		free(gb->pointers[i]);
		++i;
	}
	free(gb->pointers);
	gb->arr_len = 0;
	gb->mem_len = 0;
}
