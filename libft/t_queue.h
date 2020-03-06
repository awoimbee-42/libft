/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_queue.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <awoimbee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 23:47:32 by awoimbee          #+#    #+#             */
/*   Updated: 2020/03/05 23:48:32 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_QUEUE_H
# define T_QUEUE_H

# include <sys/types.h>
# include <stdint.h>

typedef uint32_t	t_queued;

typedef struct	s_queue
{
	int				start;
	int				end;
	int				size;
	t_queued		*arr;
}				t_queue;

int				que_realloc(t_queue *que);
int				que_push(t_queue *que, t_queued data);
t_queued		que_pop(t_queue *que);
t_queue			*que_new(size_t len);
void			que_destroy(t_queue *que);
void			que_disp(const t_queue *que);
int				que_isempty(const t_queue *que);
t_queue			*que_flush(t_queue *q);


#endif
