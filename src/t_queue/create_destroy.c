/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_destroy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <awoimbee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 14:40:12 by awoimbee          #+#    #+#             */
/*   Updated: 2020/03/06 00:28:04 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/t_queue.h>
#include <stdlib.h>

t_queue		*que_new(size_t len)
{
	t_queue		*que;

	if (!(que = malloc(sizeof(t_queue)))
		|| !(que->arr = malloc(len * sizeof(t_queued))))
		return (NULL);
	que->start = -1;
	que->end = -1;
	que->size = len;
	return (que);
}

void		que_destroy(t_queue *que)
{
	free(que->arr);
	free(que);
}
