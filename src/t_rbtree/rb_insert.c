/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb_insert.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <awoimbee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 15:59:08 by awoimbee          #+#    #+#             */
/*   Updated: 2019/06/11 19:11:43 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static void		bt_insert(t_rbt_node **root, t_rbt_node *new)
{
	t_rbt_node	*y;
	t_rbt_node	*x;

	y = NULL;
	x = *root;
	while (x)
	{
		y = x;
		if (new->dat < x->dat)
			x = x->lft;
		else
			x = x->rgt;
	}
	new->up = y;
	if (new->dat > y->dat)
		y->rgt = new;
	else
		y->lft = new;
	new->col = RED;
	intrin_insert_fixup(root, new);
}

void			rbt_insert(t_rbt_node **root, int dat)
{
	t_rbt_node	*z;

	z = (t_rbt_node*)malloc(sizeof(t_rbt_node));
	z->dat = dat;
	z->lft = NULL;
	z->rgt = NULL;
	z->up = NULL;
	if (*root == NULL)
	{
		z->col = BLACK;
		(*root) = z;
	}
	else
		bt_insert(root, z);
}
