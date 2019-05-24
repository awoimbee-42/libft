/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gb_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <awoimbee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 20:50:39 by awoimbee          #+#    #+#             */
/*   Updated: 2019/05/23 16:37:04 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Segfault if ptr is not inside gb
*/

void		gb_free(t_garbage *gb, void *ptr)
{
	void		**i;
	static int	fragmentation = 0;

	i = gb->pointers;
	while (*i != ptr)
		++i;
	free(*i);
	*i = NULL;
	++fragmentation;
	if (fragmentation == 20)
	{
		gb_defrag(gb);
		fragmentation = 0;
	}
}
