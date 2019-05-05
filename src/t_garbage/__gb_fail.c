/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __gb_fail.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <awoimbee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 21:08:41 by awoimbee          #+#    #+#             */
/*   Updated: 2019/05/04 21:22:34 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void		__gb_fail(t_garbage *gb)
{
	write(STDERR_FILENO, "Memory allocation error, terminating cleanly.\n", 46);
	gb_freeall(gb);
	exit(EXIT_FAILURE);
}
