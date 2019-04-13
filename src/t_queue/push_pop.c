/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_pop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <awoimbee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 14:55:14 by awoimbee          #+#    #+#             */
/*   Updated: 2019/04/12 18:13:52 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	/!\ returns 0 on error, else returns 1
*/

int			que_push(t_queue *que, t_queued data)
{
	if (que->end == que->size - 1)
		que->end = -1;
	if (que->end == que->start - 1)
		if (!que_realloc(que))
			return (0);
	if (que->start == -1)
		que->start = 0;
	que->arr[++que->end] = data;
	return (1);
}

/*
**	/!\ returns (t_queued)-1 on error
*/

t_queued	que_pop(t_queue *que)
{
	t_queued	res;

	if (que->start == -1)
	{
		ft_fprintf(2, "Warning: undefined behavior, reading an empty queue");
		return (que->arr[0]);
	}
	res = que->arr[que->start++];
	if (que->start == que->size)
		que->start = 0;
	if (que->start == que->end + 1)
	{
		que->start = -1;
		que->end = -1;
	}
	return (res);
}
