/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_vector.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <awoimbee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 23:32:51 by awoimbee          #+#    #+#             */
/*   Updated: 2020/03/05 23:39:01 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_VECTOR_H
# define T_VECTOR_H
# include <sys/types.h>
# include <stddef.h>

typedef int			t_vected;

typedef struct	s_vector
{
	t_vected		*arr;
	size_t			len;
	size_t			mem;
}				t_vector;

t_vector		*vector_init(t_vector *vec, const size_t reserved_len);
t_vector		*vector_push(t_vector *vec, t_vected d);
t_vector		*vector_realloc(t_vector *vec);
void			vector_mapvoid(t_vector *v, void (*f)(t_vected*));
t_vector		*vector_del_at(t_vector *v, size_t at);


#endif
