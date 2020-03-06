/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_garbage.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <awoimbee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 00:00:58 by awoimbee          #+#    #+#             */
/*   Updated: 2020/03/06 00:02:54 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_GARBAGE_H
# define T_GARBAGE_H

# include <stddef.h>
# include <sys/types.h>

typedef struct	s_garbage
{
	void			**pointers;
	size_t			arr_len;
	size_t			mem_len;
}				t_garbage;


void			intrin__gb_fail(t_garbage *gb);
void			intrin_gb_extend(t_garbage *gb);
t_garbage		gb_init(void);
void			gb_freeall(t_garbage *gb);
void			gb_free(t_garbage *gb, void *ptr);
void			gb_remove(t_garbage *gb, void *freed);
void			*gb_malloc(t_garbage *gb, size_t size);
void			*gb_add(t_garbage *gb, void *malloced);
void			gb_defrag(t_garbage *gb);
void			*gb_memalloc(t_garbage *gb, size_t size);
void			*gb_realloc(t_garbage *gb, void *ptr, size_t new_size);
t_garbage		*gb_init_existing(t_garbage *gb);


#endif
