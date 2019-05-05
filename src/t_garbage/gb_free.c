/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gb_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <awoimbee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 20:50:39 by awoimbee          #+#    #+#             */
/*   Updated: 2019/05/05 02:17:52 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Segfault if ptr was not allocated through gb_malloc
*/

void		gb_free(t_garbage *gb, void *ptr)
{
	void	**i;

	i = gb->pointers;
	while (*i != ptr)
		++i;
	free(*i);
	*i = NULL;
}
