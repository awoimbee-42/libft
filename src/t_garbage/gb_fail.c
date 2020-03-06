/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gb_fail.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <awoimbee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 21:08:41 by awoimbee          #+#    #+#             */
/*   Updated: 2020/03/06 00:28:04 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/t_garbage.h>
#include <unistd.h>
#include <stdlib.h>

void		intrin__gb_fail(t_garbage *gb)
{
	write(STDERR_FILENO, "Memory allocation error, terminating cleanly.\n", 46);
	gb_freeall(gb);
	exit(EXIT_FAILURE);
}
