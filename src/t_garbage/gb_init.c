/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gb_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <awoimbee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 20:45:31 by awoimbee          #+#    #+#             */
/*   Updated: 2019/05/05 03:20:50 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_garbage		gb_init(void)
{
	t_garbage	gbc;

	gbc.pointers = ft_memalloc(10);
	gbc.arr_len = 0;
	if (__builtin_expect((long)gbc.pointers, 1))
		gbc.mem_len = 10;
	else
		gbc.mem_len = 0;
	return (gbc);
}
