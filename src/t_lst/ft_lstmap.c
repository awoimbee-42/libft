/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <awoimbee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 15:06:32 by awoimbee          #+#    #+#             */
/*   Updated: 2018/11/06 15:24:47 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*malloc_res(t_list *elem, t_list *(*f)(t_list *elem))
{
	elem = (*f)(elem);
	elem = ft_lstnew(elem->content, elem->content_size);
	return (elem);
}

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new_lst_tmp;
	t_list	*new_lst_return;

	if (!lst)
		return (NULL);
	new_lst_return = malloc_res(lst, f);
	new_lst_tmp = new_lst_return;
	while (lst->next)
	{
		lst = lst->next;
		new_lst_tmp->next = malloc_res(lst, f);
		new_lst_tmp = new_lst_tmp->next;
	}
	return (new_lst_return);
}
