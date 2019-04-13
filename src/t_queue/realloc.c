/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <awoimbee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 14:54:42 by awoimbee          #+#    #+#             */
/*   Updated: 2019/04/11 16:35:23 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int			que_realloc(t_queue *q)
{
	t_queued	*nw_data;

	if (!(nw_data = malloc(q->size * 2 * sizeof(t_queued))))
		return (0);
	if (q->start != -1 && q->end == -1)
		q->end = q->size - 1;
	if (q->start <= q->end)
	{
		q->end = q->end - q->start;
		ft_mempcpy(nw_data, &q->arr[q->start], (q->end + 1) * sizeof(t_queued));
	}
	else
	{
		ft_mempcpy(ft_mempcpy(nw_data,
				&q->arr[q->start], (q->size - q->start) * sizeof(t_queued)),
			q->arr, (q->end + 1) * sizeof(t_queued));
		q->end = q->size - q->start + q->end;
	}
	free(q->arr);
	q->size *= 2;
	q->arr = nw_data;
	q->start = 0;
	return (1);
}
