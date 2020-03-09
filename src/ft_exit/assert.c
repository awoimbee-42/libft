/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assert.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <awoimbee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 19:51:28 by awoimbee          #+#    #+#             */
/*   Updated: 2020/03/09 19:36:27 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/ft_prtf.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include <libft/ft_exit.h>

/*
**	This should be a macro :/
**	FFS assert.h does a great job too
**	I hate this
**	lets hope LTO fixes this bullshit
*/

void	ft_assert(int exp, const char *fmt, ...)
{
	va_list		ap;

	if (exp)
		return ;
	va_start(ap, fmt);
	ft_vfprintf(2, fmt, &ap);
	va_end(ap);
	exit(EXIT_FAILURE);
}

void	ft_assertp_safe(void *notnull, const char *msg, const void *d)
{
	if (notnull)
		return ;
	ft_msg_exit(msg, d);
}
