/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_freeall.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <awoimbee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 16:24:23 by awoimbee          #+#    #+#             */
/*   Updated: 2019/06/11 21:12:39 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static void	recur_free(t_map *start)
{
	t_map *tmp;

	while (start->lft || start->rgt)
		start = start->lft ? start->lft : start->rgt;
	tmp = start->up;
	free(start);
	if (tmp)
	{
		if (start == tmp->lft)
			tmp->lft = NULL;
		else
			tmp->rgt = NULL;
		recur_free(tmp);
	}
}

void		map_freeall(t_map **root)
{
	recur_free(*root);
	*root = NULL;
}
