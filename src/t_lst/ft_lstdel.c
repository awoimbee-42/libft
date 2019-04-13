/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <awoimbee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 14:55:47 by awoimbee          #+#    #+#             */
/*   Updated: 2019/04/11 14:52:38 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

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
