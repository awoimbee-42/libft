/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_push_back.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <awoimbee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/04 02:37:22 by awoimbee          #+#    #+#             */
/*   Updated: 2019/04/11 14:51:16 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lst_push_back(t_list **lst, t_listed *data, size_t d_size)
{
	t_list		*tmp;

	if (*lst)
	{
		tmp = *lst;
		while (tmp->next)
			tmp = tmp->next;
		if (!(tmp->next = ft_lstnew(data, d_size)))
			return (NULL);
		tmp = tmp->next;
	}
	else
	{
		if (!(*lst = ft_lstnew(data, d_size)))
			return (NULL);
		tmp = *lst;
	}
	return (tmp);
}
