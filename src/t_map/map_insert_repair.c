/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_insert_repair.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <awoimbee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 13:14:06 by awoimbee          #+#    #+#             */
/*   Updated: 2019/06/11 21:05:08 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/*
**	Utility function to fixup the Red-Black tree after standard BST insertion
*/

static inline int	uncle_is_red(t_map *z)
{
	t_map	*y;

	y = z->up->up;
	y = z->up == y->lft ? y->rgt : y->lft;
	if (y && y->col == RED)
	{
		y->col = BLACK;
		z->up->col = BLACK;
		z->up->up->col = RED;
		z = z->up->up;
		return (1);
	}
	else
		return (0);
}

/*
**	Handle the L-L and L-R cases
*/

static inline void	case_lft(t_map **root, t_map *z)
{
	enum e_rbtn_color	tmp_col;

	if (z == z->up->lft)
	{
		tmp_col = z->up->col;
		z->up->col = z->up->up->col;
		z->up->up->col = tmp_col;
		intrin_rbtree_rgt_rot(root, z->up->up);
	}
	else
	{
		tmp_col = z->col ;
		z->col = z->up->up->col;
		z->up->up->col = tmp_col;
		intrin_rbtree_lft_rot(root, z->up);
		intrin_rbtree_rgt_rot(root, z->up->up);
	}
}

/*
**	Handle the R-R and R-L cases
*/

static inline void	case_rgt(t_map **root, t_map *z)
{
	enum e_rbtn_color	tmp_col;

	if (z == z->up->rgt)
	{
		tmp_col = z->up->col ;
		z->up->col = z->up->up->col;
		z->up->up->col = tmp_col;
		intrin_rbtree_lft_rot(root, z->up->up);
	}
	else
	{
		tmp_col = z->col;
		z->col = z->up->up->col;
		z->up->up->col = tmp_col;
		intrin_rbtree_rgt_rot(root, z->up);
		intrin_rbtree_lft_rot(root, z->up->up);
	}
}

void				intrin_insert_fixup(t_map **root, t_map *z)
{
	while (z != *root && z->up != *root && z->up->col == RED)
	{
		if (uncle_is_red(z))
			continue;
		else if (z->up == z->up->up->lft)
			case_lft(root, z);
		else if (z->up == z->up->up->rgt)
			case_rgt(root, z);
	}
	(*root)->col = BLACK;
}
