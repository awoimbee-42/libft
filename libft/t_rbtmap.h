/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_rbtmap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <awoimbee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 23:43:21 by awoimbee          #+#    #+#             */
/*   Updated: 2020/03/05 23:45:32 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_RBTMAP_H
# define T_RBTMAP_H
# include <stddef.h>

typedef int			t_map_key;
typedef long double	t_map_data;

enum			e_rbtn_color
{
	BLACK = 0,
	RED
};

typedef struct	s_rbtmap
{
	t_map_key			key;
	t_map_data			*dat;
	enum e_rbtn_color	col;
	struct s_rbtmap		*lft;
	struct s_rbtmap		*rgt;
	struct s_rbtmap		*up;
}				t_rbtmap;

void			intrin_insert_fixup(t_rbtmap **root, t_rbtmap *z);
void			intrin_rbtree_lft_rot(t_rbtmap **root, t_rbtmap *x);
void			intrin_rbtree_rgt_rot(t_rbtmap **root, t_rbtmap *y);
void			map_insert(t_rbtmap **root, t_map_key key, t_map_data *data);
void			map_iter(t_rbtmap *root, void(*f)(t_map_key, t_map_data*));
void			map_freeall(t_rbtmap **root);


#endif
