/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_freeall.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <awoimbee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 16:24:23 by awoimbee          #+#    #+#             */
/*   Updated: 2020/03/06 00:28:04 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft/t_rbtmap.h>

static void	recur_free(t_rbtmap *start)
{
	t_rbtmap *tmp;

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

void		map_freeall(t_rbtmap **root)
{
	recur_free(*root);
	*root = NULL;
}
