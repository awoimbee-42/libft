/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gb_remove.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <awoimbee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 21:19:19 by awoimbee          #+#    #+#             */
/*   Updated: 2020/03/06 00:28:04 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/t_garbage.h>

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
