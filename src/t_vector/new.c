/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <awoimbee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 01:09:53 by awoimbee          #+#    #+#             */
/*   Updated: 2019/05/05 17:45:03 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_vector	*vector_init(t_vector *vec, const size_t reserved_len)
{
	vec->mem = reserved_len;
	vec->len = 0;
	if (!(vec->arr = malloc(reserved_len * sizeof(t_vected))))
		return (NULL);
	return (vec);
}
