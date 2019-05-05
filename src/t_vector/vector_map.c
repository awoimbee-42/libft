/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <awoimbee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 00:42:56 by awoimbee          #+#    #+#             */
/*   Updated: 2019/05/05 17:45:14 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
