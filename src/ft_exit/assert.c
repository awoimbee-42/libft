/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assert.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <awoimbee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 19:51:28 by awoimbee          #+#    #+#             */
/*   Updated: 2020/03/08 17:08:05 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/ft_prtf.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>

void	ft_assert(int true, const char *fmt, ...)
{
	va_list		ap;

	if (true)
	{
		return ;
	}
	va_start(ap, fmt);
	ft_vfprintf(2, fmt, &ap);
	va_end(ap);
	exit(EXIT_FAILURE);
}
