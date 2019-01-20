/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_hub.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <awoimbee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 17:02:00 by allespag          #+#    #+#             */
/*   Updated: 2018/12/17 20:06:02 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**	%d | %i with l ll h hh
*/

void		prtf__nb_signed(t_string *ret, va_list *ap, t_arg *arg_info)
{
	int					size;
	long long int		value;

	size = arg_info->size;
	value = 0;
	if (size == 1)
		value = va_arg(*ap, long);
	else if (size == 2)
		value = va_arg(*ap, long long);
	else if (size == -2)
		value = (signed char)va_arg(*ap, int);
	else if (size == -1)
		value = (short)va_arg(*ap, int);
	else
		value = va_arg(*ap, int);
	if (value == 0 && arg_info->precis == 0)
	{
		ret->str = (char*)1;
		return ;
	}
	ret->str = prtf__s_itoa_base(value, 10, arg_info);
	ret->len = ft_strlen(ret->str);
}

/*
**	%u | %o | %x | %X with l ll h hh
*/

void		prtf__nb_unsigned(t_string *ret, va_list *ap, int base,
								t_arg *arg_info)
{
	int					size;
	unsigned long long	value;

	size = arg_info->size;
	value = 0;
	if (size == 1)
		value = va_arg(*ap, unsigned long);
	else if (size == 2)
		value = va_arg(*ap, unsigned long long);
	else if (size == -2)
		value = (unsigned char)va_arg(*ap, int);
	else if (size == -1)
		value = (unsigned short)va_arg(*ap, int);
	else
		value = va_arg(*ap, unsigned int);
	if (value == 0 && arg_info->precis == 0)
	{
		ret->str = (char*)1;
		return ;
	}
	ret->str = prtf__u_itoa_base(value, base, arg_info);
	ret->len = ft_strlen(ret->str);
}

/*
**	%f with l L
*/

void		prtf__nb_double(t_string *ret, va_list *ap, t_arg *arg_info)
{
	long double			value;

	value = 0;
	if (arg_info->size == 3)
		value = va_arg(*ap, long double);
	else
		value = va_arg(*ap, double);
	ret->str = prtf__itoa_double(value, arg_info);
	ret->len = ft_strlen(ret->str);
}
