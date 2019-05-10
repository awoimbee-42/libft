/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intrin_gb_extend.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <awoimbee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 22:21:52 by awoimbee          #+#    #+#             */
/*   Updated: 2019/05/07 22:30:07 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		intrin_gb_extend(t_garbage *gb)
{
	void		*tmp;

	if (gb->mem_len)
		gb->mem_len *= 2;
	else
		gb->mem_len = 10;
	tmp = realloc(gb->pointers, gb->mem_len * sizeof(*gb->pointers));
	if (!__builtin_expect((long)tmp, 1))
		intrin__gb_fail(gb);
	gb->pointers = tmp;
	ft_bzero(&gb->pointers[gb->arr_len], gb->mem_len - gb->arr_len);
}
