/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <awoimbee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 16:27:44 by allespag          #+#    #+#             */
/*   Updated: 2019/01/02 00:51:53 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_arg	*read_arg(const char **format)
{
	t_arg		*arg;
	const char	*save;

	save = (**format == '%') ? *format : *format - 1;
	if (**format != '%' && (arg = malloc(sizeof(t_arg))))
	{
		arg->conv_typ = 1;
		if (prtf__get_arg_option(arg, format)
		&& prtf__get_arg_m_width(arg, format)
		&& prtf__get_arg_precis(arg, format)
		&& prtf__get_arg_size(arg, format)
		&& prtf__get_arg_convtyp(arg, format))
		{
			return (arg);
		}
		if (arg->conv_typ == '%')
			save = *format - 1;
		free(arg);
	}
	*format = save;
	return (NULL);
}

void			prtf__vprintf(const char *format, va_list *ap, t_string *str)
{
	int			len;
	t_arg		*arg_info;

	len = -1;
	while (format[++len])
	{
		if (format[len] == '%')
		{
			prtf__t_strncat(str, format, len);
			format += len + 1;
			len = 0;
			if (!format[0] && --format && ++len)
				break ;
			if (((arg_info = read_arg(&format)) && (--len == -1)))
			{
				prtf__join_arg(str, arg_info, ap);
				free(arg_info);
			}
		}
	}
	if (format[0])
		prtf__t_strncat(str, format, len);
	(TXT_DECORATIONS) ? prtf__parse_bonus(str) : 0;
}
