/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_del_at.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <awoimbee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 19:05:48 by awoimbee          #+#    #+#             */
/*   Updated: 2019/05/05 17:45:13 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_vector		*vector_del_at(t_vector *v, size_t at)
{
	if (at >= v->len)
		return (NULL);
	--v->len;
	ft_memcpy(&v->arr[at], &v->arr[at + 1], v->len - at);
	return (v);
}
