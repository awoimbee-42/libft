/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_free_link.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <awoimbee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 11:40:24 by awoimbee          #+#    #+#             */
/*   Updated: 2018/11/15 12:03:04 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int		ft_lst_free_link(t_list **lst, t_list *link)
{
	t_list		*tmp;
	t_list		*tmp_late;

	tmp_late = NULL;
	if (!(tmp = *lst))
		return (0);
	while (tmp && tmp != link)
	{
		tmp_late = tmp;
		tmp = tmp->next;
	}
	if (tmp == link)
	{
		if (tmp_late)
			tmp_late->next = tmp->next;
		else
			*lst = link->next;
		if (link->content)
			free(link->content);
		free(link);
		return (1);
	}
	return (0);
}
