/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_pop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <awoimbee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 14:55:14 by awoimbee          #+#    #+#             */
/*   Updated: 2020/03/06 00:59:39 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/t_queue.h>
#include <libft.h>

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

t_queued	que_pop(t_queue *que)
{
	t_queued	res;

	ft_assert(que->start != -1, "t_queue: pop() on an empty queue");
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
