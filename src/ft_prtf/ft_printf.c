/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <awoimbee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 16:18:43 by allespag          #+#    #+#             */
/*   Updated: 2018/12/16 20:43:42 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_printf(const char *restrict format, ...)
{
	va_list		ap;
	t_string	str;

	str.len = 0;
	str.str = NULL;
	va_start(ap, format);
	prtf__vprintf((char*)format, &ap, &str);
	va_end(ap);
	write(1, str.str, str.len);
	free(str.str);
	return (str.len);
}

int			ft_fprintf(int fd, const char *restrict format, ...)
{
	va_list		ap;
	t_string	str;

	str.len = 0;
	str.str = NULL;
	va_start(ap, format);
	prtf__vprintf((char*)format, &ap, &str);
	va_end(ap);
	write(fd, str.str, str.len);
	free(str.str);
	return (str.len);
}

int			ft_sprintf(char *str, const char *restrict format, ...)
{
	va_list		ap;
	t_string	str1;

	str1.len = 0;
	str1.str = NULL;
	va_start(ap, format);
	prtf__vprintf((char*)format, &ap, &str1);
	va_end(ap);
	ft_strcpy(str, str1.str);
	free(str1.str);
	return (str1.len);
}
