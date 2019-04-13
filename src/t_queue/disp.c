/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_que_disp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <awoimbee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 14:53:56 by awoimbee          #+#    #+#             */
/*   Updated: 2019/04/11 14:54:20 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		que_disp(const t_queue *que)
{
	int			i;

	ft_printf("{YLW}Printing queue at address: %p{eoc}\n", que);
	if (que->start == -1)
	{
		ft_printf("Queue is Empty\n");
		return ;
	}
	if (que->end >= que->start)
	{
		i = que->start - 1;
		while (++i <= que->end)
			ft_printf("%u ", que->arr[i]);
	}
	else
	{
		i = que->start;
		while (i < que->size)
			ft_printf("%u ", que->arr[i++]);
		i = 0;
		while (i <= que->end)
			ft_printf("%u ", que->arr[i++]);
	}
	ft_printf("\n");
}
