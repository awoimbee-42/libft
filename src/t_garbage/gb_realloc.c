/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gb_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <awoimbee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 18:36:14 by awoimbee          #+#    #+#             */
/*   Updated: 2019/05/07 20:46:15 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void		*gb_realloc(t_garbage *gb, void *ptr, size_t new_size)
{
	void	**i;
	void	*tmp;

	i = gb->pointers;
	while (*i != ptr)
		++i;
	tmp = realloc(ptr, new_size);
	if (!__builtin_expect((long)tmp, 1))
		intrin__gb_fail(gb);
	*i = tmp;
	return (tmp);
}
