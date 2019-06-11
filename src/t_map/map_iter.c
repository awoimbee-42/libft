/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_iter.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <awoimbee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 16:21:46 by awoimbee          #+#    #+#             */
/*   Updated: 2019/06/11 20:57:10 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	map_itervoid(t_map *root, void(*f)(t_map_key, t_map_data*))
{
	if (root == NULL)
		return;
	map_itervoid(root->lft, f);
	f(root->key, root->dat);
	map_itervoid(root->rgt, f);
}
