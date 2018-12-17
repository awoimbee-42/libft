/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_arg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <awoimbee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 15:20:26 by awoimbee          #+#    #+#             */
/*   Updated: 2018/12/17 20:04:10 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	retrieve_arg(t_string *ret, va_list *ap, t_arg *arg_info)
{
	char		type;

	type = arg_info->conv_typ;
	if (type == 'd' || type == 'i')
		prtf__nb_signed(ret, ap, arg_info);
	else if (type == 'u')
		prtf__nb_unsigned(ret, ap, 10, arg_info);
	else if (type == 'o')
		prtf__nb_unsigned(ret, ap, 8, arg_info);
	else if (type == 'x' || type == 'X')
		prtf__nb_unsigned(ret, ap, 16, arg_info);
	else if (type == 'b')
		prtf__nb_unsigned(ret, ap, 2, arg_info);
	else if (type == 'f')
		prtf__nb_double(ret, ap, arg_info);
	else if (type == 's')
		prtf__flag_s(ret, va_arg(*ap, char *), arg_info);
	else if (type == 'c')
		prtf__flag_c(ret, va_arg(*ap, int));
	else if (type == 'r')
		prtf__flag_r(ret, va_arg(*ap, int));
	else
		ret->str = NULL;
}

static char	*strcatp1(t_string *s1, t_string *s2, t_arg *arg_info, int spacer)
{
	char		*nw_str;
	char		*nw_str_spced;

	if (!(nw_str = ft_strnew(s1->len + arg_info->m_width)))
		prtf__msg_exit(MALLOC_ERR);
	nw_str_spced = ft_mempcpy(nw_str, s1->str, s1->len);
	if (arg_info->option & FLAG_ZERO)
	{
		ft_memset(nw_str_spced, '0', arg_info->m_width);
		if (s2->len && (s2->str[0] == '+' || s2->str[0] == '-') && ++spacer)
			nw_str_spced[0] = s2->str[0];
		else if (s2->len > 2 && (s2->str[1] == 'x' || s2->str[1] == 'b'
		|| s2->str[1] == 'X') && (spacer += 2))
			nw_str_spced[1] = s2->str[1];
		nw_str_spced += arg_info->m_width - s2->len + spacer;
		ft_mempcpy(nw_str_spced, s2->str + spacer, s2->len - spacer);
	}
	else
	{
		ft_memset(nw_str_spced, ' ', arg_info->m_width);
		if (!(arg_info->option & FLAG_MINUS))
			nw_str_spced += arg_info->m_width - s2->len;
		ft_mempcpy(nw_str_spced, s2->str, s2->len);
	}
	return (nw_str);
}

static void	strcat_arg(t_string *s1, t_string *s2, t_arg *arg_info)
{
	char		*nw_str;

	if (!s2->str)
		return ;
	if (s2->len < (unsigned int)arg_info->m_width)
	{
		nw_str = strcatp1(s1, s2, arg_info, 0);
		s1->len += arg_info->m_width;
	}
	else
	{
		(nw_str = ft_strnew(s1->len + s2->len)) ? 0 : prtf__msg_exit("Err @pf");
		s1->len = (char*)ft_mempcpy(
			ft_mempcpy(nw_str, s1->str, s1->len), s2->str, s2->len) - nw_str;
	}
	free(s1->str);
	s1->str = nw_str;
}

void		prtf__join_arg(t_string *out, t_arg *arg_info, va_list *ap)
{
	t_string	raw_arg;

	raw_arg.len = 0;
	raw_arg.str = NULL;
	retrieve_arg(&raw_arg, ap, arg_info);
	strcat_arg(out, &raw_arg, arg_info);
	if (arg_info->conv_typ != 's' && raw_arg.str && raw_arg.len)
		free(raw_arg.str);
}
