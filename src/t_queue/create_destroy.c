/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_destroy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <awoimbee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 14:40:12 by awoimbee          #+#    #+#             */
/*   Updated: 2019/04/11 15:11:17 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
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
