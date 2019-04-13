/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_at.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <awoimbee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 13:24:33 by awoimbee          #+#    #+#             */
/*   Updated: 2018/11/15 11:44:00 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_list_at(t_list *begin_list, unsigned int nbr)
{
	unsigned int	i;

	if (begin_list == NULL)
		return (NULL);
	i = 0;
	while (begin_list->next || i == nbr)
	{
		if (i == nbr)
			return (begin_list);
		begin_list = begin_list->next;
		++i;
	}
	return (NULL);
}
