/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 16:27:44 by allespag          #+#    #+#             */
/*   Updated: 2018/12/14 20:45:43 by arthur           ###   ########.fr       */
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
		if (get_arg_option(arg, format)
		&& get_arg_m_width(arg, format)
		&& get_arg_precis(arg, format)
		&& get_arg_size(arg, format)
		&& get_arg_convtyp(arg, format))
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

void			ft_vprintf(const char *format, va_list *ap, t_string *str)
{
	int			len;
	t_arg		*arg_info;

	len = -1;
	while (format[++len])
	{
		if (format[len] == '%')
		{
			ft_t_strncat(str, format, len) ? 0 : msg_exit("err vprintf 1");
			format += len + 1;
			len = 0;
			if (!format[0] && --format && ++len)
				break ;
			if (((arg_info = read_arg(&format)) && (--len == -1)))
			{
				join_arg(str, arg_info, ap);
				free(arg_info);
			}
		}
	}
	if (format[0])
		ft_t_strncat(str, format, len) ? 0 : msg_exit("err vprintf 2");
	(TXT_DECORATIONS) ? parse_bonus(str) : 0;
}
