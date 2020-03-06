/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <awoimbee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 14:55:47 by awoimbee          #+#    #+#             */
/*   Updated: 2020/03/06 00:28:04 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft/t_lst.h>

void	ft_lstdel(t_list **alst, void (*del)(t_listed*, size_t))
{
	t_list	*next;

	while ((next = (*alst)->next))
	{
		ft_lstdelone(&*alst, del);
		free(*alst);
		*alst = next;
	}
	ft_lstdelone(&*alst, del);
	free(*alst);
	*alst = NULL;
}
