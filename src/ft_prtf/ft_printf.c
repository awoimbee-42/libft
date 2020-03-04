/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <awoimbee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 16:18:43 by allespag          #+#    #+#             */
/*   Updated: 2020/03/04 16:23:01 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_printf(const char *restrict format, ...)
{
	va_list		ap;
	t_prtfstr	str;

	va_start(ap, format);
	str = prtf__vprintf((char*)format, &ap);
	va_end(ap);
	write(1, str.str, str.len);
	free(str.str);
	return (str.len);
}

int			ft_fprintf(int fd, const char *restrict format, ...)
{
	va_list		ap;
	t_prtfstr	str;

	va_start(ap, format);
	str = prtf__vprintf((char*)format, &ap);
	va_end(ap);
	write(fd, str.str, str.len);
	free(str.str);
	return (str.len);
}

int			ft_vfprintf(const int fd, const char *restrict format, va_list *ap)
{
	t_prtfstr	str;

	str = prtf__vprintf((char*)format, ap);
	write(fd, str.str, str.len);
	free(str.str);
	return (str.len);
}

int			ft_asprintf(char **strp, const char *fmt, ...)
{
	va_list		ap;
	t_prtfstr	str1;

	va_start(ap, fmt);
	str1 = prtf__vprintf((char*)fmt, &ap);
	va_end(ap);
	*strp = str1.str;
	return (str1.len);
}

/*
**	This one is custom, it works just like asprintf
**		but it returns directly the char* string
*/

char		*ft_cprintf(const char *fmt, ...)
{
	va_list		ap;
	t_prtfstr	str1;

	va_start(ap, fmt);
	str1 = prtf__vprintf((char*)fmt, &ap);
	va_end(ap);
	return (str1.str);
}
