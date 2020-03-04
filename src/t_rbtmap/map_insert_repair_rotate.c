/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_insert_repair_rotate.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <awoimbee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 13:05:30 by awoimbee          #+#    #+#             */
/*   Updated: 2020/03/04 12:54:55 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/*
**	implementation of roations for a rb tree, needed to fix the tree after
**	an insertion
*/

void	intrin_rbtree_lft_rot(t_rbtmap **root, t_rbtmap *x)
{
	t_rbtmap		*y;

	if (!x || !x->rgt)
		return ;
	y = x->rgt;
	x->rgt = y->lft;
	if (x->rgt != NULL)
		x->rgt->up = x;
	y->up = x->up;
	if (x->up == NULL)
		(*root) = y;
	else if (x == x->up->lft)
		x->up->lft = y;
	else
		x->up->rgt = y;
	y->lft = x;
	x->up = y;
}

void	intrin_rbtree_rgt_rot(t_rbtmap **root, t_rbtmap *y)
{
	t_rbtmap		*x;

	if (!y || !y->lft)
		return ;
	x = y->lft;
	y->lft = x->rgt;
	if (x->rgt != NULL)
		x->rgt->up = y;
	x->up = y->up;
	if (x->up == NULL)
		(*root) = x;
	else if (y == y->up->lft)
		y->up->lft = x;
	else
		y->up->rgt = x;
	x->rgt = y;
	y->up = x;
}
