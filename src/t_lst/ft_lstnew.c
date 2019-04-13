/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <awoimbee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 14:39:12 by awoimbee          #+#    #+#             */
/*   Updated: 2018/11/06 15:19:49 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new_lst;

	if (!(new_lst = malloc(sizeof(t_list))))
		return (NULL);
	if (content == NULL)
	{
		new_lst->content = NULL;
		new_lst->content_size = 0;
	}
	else
	{
		new_lst->content_size = content_size;
		if (!(new_lst->content = malloc(content_size)))
		{
			free(new_lst);
			return (NULL);
		}
		ft_memcpy(new_lst->content, content, content_size);
	}
	new_lst->next = NULL;
	return (new_lst);
}
