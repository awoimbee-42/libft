/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <awoimbee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 00:42:56 by awoimbee          #+#    #+#             */
/*   Updated: 2020/03/06 00:28:04 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/t_vector.h>

void		vector_mapvoid(t_vector *v, void (*f)(t_vected*))
{
	t_vected	*end;
	t_vected	*ptr;

	end = &v->arr[v->len];
	ptr = v->arr;
	while (ptr != end)
	{
		f(ptr);
		++ptr;
	}
}
