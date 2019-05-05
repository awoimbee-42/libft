/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <awoimbee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 01:16:55 by awoimbee          #+#    #+#             */
/*   Updated: 2019/05/05 17:45:10 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_vector	*vector_realloc(t_vector *vec)
{
	t_vected	*new_arr;

	vec->mem *= 2;
	if (!(new_arr = malloc(vec->mem * sizeof(t_vected))))
		return (NULL);
	ft_mempcpy(new_arr, vec->arr, vec->len * sizeof(t_vected));
	free(vec->arr);
	vec->arr = new_arr;
	return (vec);
}
