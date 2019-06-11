/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <awoimbee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 16:21:46 by awoimbee          #+#    #+#             */
/*   Updated: 2019/06/11 18:32:48 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	rbt_print(struct s_rbt_node *root)
{
	if (root == NULL)
		return;
	rbt_print(root->lft);
	ft_printf("%d\n", root->dat);
	rbt_print(root->rgt);
}
