/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gb_remove.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <awoimbee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 21:19:19 by awoimbee          #+#    #+#             */
/*   Updated: 2019/05/04 21:23:02 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Used to remove a pointer malloced through gb_malloc but freed elsewhere.
*/

void		gb_remove(t_garbage *gb, void *freed)
{
	void	**i;

	i = gb->pointers;
	while (*i != freed)
		++i;
	*i = NULL;
}
