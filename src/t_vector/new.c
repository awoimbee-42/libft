/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <awoimbee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 01:09:53 by awoimbee          #+#    #+#             */
/*   Updated: 2020/03/06 00:28:04 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/t_vector.h>
#include <stdlib.h>

t_vector	*vector_init(t_vector *vec, const size_t reserved_len)
{
	vec->mem = reserved_len;
	vec->len = 0;
	if (!(vec->arr = malloc(reserved_len * sizeof(t_vected))))
		return (NULL);
	return (vec);
}
