/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gb_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <awoimbee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 20:45:31 by awoimbee          #+#    #+#             */
/*   Updated: 2020/03/06 00:28:04 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/t_garbage.h>
#include <unistd.h>
#include <stdlib.h>
#include <libft/ft_mem.h>

t_garbage		gb_init(void)
{
	t_garbage	gbc;

	gbc.arr_len = 0;
	gbc.mem_len = 10;
	gbc.pointers = ft_memalloc(gbc.mem_len * sizeof(*gbc.pointers));
	if (!__builtin_expect((long)gbc.pointers, 1))
	{
		write(STDERR_FILENO,
			"Memory allocation error, terminating cleanly.\n",
			46);
		exit(EXIT_FAILURE);
	}
	return (gbc);
}
