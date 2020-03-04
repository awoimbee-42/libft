/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <awoimbee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 16:27:44 by allespag          #+#    #+#             */
/*   Updated: 2020/03/04 12:49:42 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		read_arg(const char **format, t_arg *arg)
{
	const char	*save;

	save = (**format == '%') ? *format : *format - 1;
	if (**format != '%')
	{
		ft_bzero(arg, sizeof(arg));
		arg->conv_typ = 1;
		if (prtf__get_arg_option(arg, format)
			&& prtf__get_arg_m_width(arg, format)
			&& prtf__get_arg_precis(arg, format)
			&& prtf__get_arg_size(arg, format)
			&& prtf__get_arg_convtyp(arg, format))
			return (1);
		if (arg->conv_typ == '%')
			save = *format - 1;
	}
	*format = save;
	return (0);
}

t_prtfstr		prtf__vprintf(const char *format, va_list *ap)
{
	int			len;
	t_arg		arg_info;
	t_prtfstr	str;

	ft_bzero(&str, sizeof(str));
	len = -1;
	while (format[++len])
	{
		if (format[len] != '%')
			continue ;
		prtf__t_strncat(&str, format, len);
		format += len + 1;
		len = 0;
		if (!format[0] && --format && ++len)
			break ;
		if ((read_arg(&format, &arg_info) && (--len == -1)))
			prtf__join_arg(&str, &arg_info, ap);
	}
	if (format[0])
		prtf__t_strncat(&str, format, len);
	(TXT_DECORATIONS) ? prtf__parse_bonus(&str) : 0;
	return (str);
}
