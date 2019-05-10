/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gb_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <awoimbee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 18:36:14 by awoimbee          #+#    #+#             */
/*   Updated: 2019/05/11 00:11:02 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void		*gb_realloc(t_garbage *gb, void *ptr, size_t new_size)
{
	void	*tmp;
	size_t	i;

	i = 0;
	while (i < gb->arr_len && gb->pointers[i] != ptr)
		++i;
	if (i == gb->arr_len)
		return (gb_malloc(gb, new_size));
	tmp = realloc(ptr, new_size);
	if (!__builtin_expect((long)tmp, 1))
		intrin__gb_fail(gb);
	gb->pointers[i] = tmp;
	return (tmp);
}
