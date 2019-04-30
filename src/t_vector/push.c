/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <awoimbee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 01:13:56 by awoimbee          #+#    #+#             */
/*   Updated: 2019/04/29 01:23:26 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_vector		*vector_push(t_vector *vec, t_vected d)
{
	if (vec->len >= vec->mem)
	{
		if (!vector_realloc(vec))
			return (NULL);
	}
	vec->arr[vec->len++] = d;
	return (vec);
}