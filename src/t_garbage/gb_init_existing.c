/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gb_init_existing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <awoimbee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 19:21:25 by awoimbee          #+#    #+#             */
/*   Updated: 2019/05/07 20:46:06 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_garbage		*gb_init_existing(t_garbage *gb)
{
	gb->pointers = ft_memalloc(10);
	gb->arr_len = 0;
	if (__builtin_expect((long)gb->pointers, 1))
		gb->mem_len = 10;
	else
		gb->mem_len = 0;
	return (gb);
}
