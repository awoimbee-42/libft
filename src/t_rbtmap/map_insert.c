/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_insert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <awoimbee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 15:59:08 by awoimbee          #+#    #+#             */
/*   Updated: 2019/06/11 22:13:49 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static void		bt_insert(t_rbtmap **root, t_rbtmap *new)
{
	t_rbtmap	*y;
	t_rbtmap	*x;

	y = NULL;
	x = *root;
	while (x)
	{
		y = x;
		x = new->key < x->key ? x->lft : x->rgt;
	}
	new->up = y;
	if (new->key < y->key)
		y->lft = new;
	else
		y->rgt = new;
	new->col = RED;
	intrin_insert_fixup(root, new);
}

void			map_insert(t_rbtmap **root, t_map_key key, t_map_data *data)
{
	t_rbtmap	*z;

	z = (t_rbtmap*)malloc(sizeof(t_rbtmap));
	z->key = key;
	z->dat = data;
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
