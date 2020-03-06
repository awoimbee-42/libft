/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gb_init_existing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <awoimbee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 19:21:25 by awoimbee          #+#    #+#             */
/*   Updated: 2020/03/06 00:28:04 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/t_garbage.h>
#include <unistd.h>
#include <stdlib.h>
#include <libft/ft_mem.h>

t_garbage		*gb_init_existing(t_garbage *gb)
{
	gb->arr_len = 0;
	gb->mem_len = 10;
	gb->pointers = ft_memalloc(gb->mem_len * sizeof(*gb->pointers));
	if (!__builtin_expect((long)gb->pointers, 1))
	{
		write(STDERR_FILENO,
			"Memory allocation error, terminating cleanly.\n",
			46);
		exit(EXIT_FAILURE);
	}
	return (gb);
}
