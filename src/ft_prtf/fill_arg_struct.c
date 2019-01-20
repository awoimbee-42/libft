/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_arg_struct.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <awoimbee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 17:56:45 by awoimbee          #+#    #+#             */
/*   Updated: 2018/12/16 20:37:19 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**	In this file, every function has the role of filling a specific variable
**		in a t_arg structure.
**	They are designed to be called one after the other.
*/

int		prtf__get_arg_option(t_arg *arg, const char **format)
{
	arg->option = 0;
	while (1)
	{
		if (**format == '+' && ++(*format))
			arg->option |= FLAG_PLUS;
		else if (**format == ' ' && ++(*format))
			arg->option |= FLAG_SPACE;
		else if (**format == '-' && ++(*format))
			arg->option |= FLAG_MINUS;
		else if (**format == '0' && ++(*format))
			arg->option |= FLAG_ZERO;
		else if (**format == '#' && ++(*format))
			arg->option |= FLAG_HASH;
		else
			break ;
	}
	if ((arg->option & FLAG_PLUS) && (arg->option & FLAG_SPACE))
		arg->option -= FLAG_SPACE;
	if ((arg->option & FLAG_MINUS) && (arg->option & FLAG_ZERO))
		arg->option -= FLAG_ZERO;
	return (1);
}

int		prtf__get_arg_m_width(t_arg *arg, const char **format)
{
	if ('0' <= **format && **format <= '9')
		arg->m_width = prtf__atoi_move(format);
	else
		arg->m_width = 0;
	return (1);
}

int		prtf__get_arg_precis(t_arg *arg, const char **format)
{
	if (**format == '.' && ++(*format))
	{
		if (**format == '*' && ++(*format))
			arg->precis = -2;
		else
		{
			if (!ft_isdigit(**format))
				arg->precis = 0;
			else
				arg->precis = prtf__atoi_move(format);
		}
	}
	else
		arg->precis = -1;
	if (arg->precis > 0 && (arg->option & FLAG_ZERO))
		arg->option -= FLAG_ZERO;
	return (1);
}

int		prtf__get_arg_size(t_arg *arg, const char **format)
{
	if (**format == 'h' && ++(*format))
	{
		if (**format == 'h' && ++(*format))
			arg->size = -2;
		else
			arg->size = -1;
	}
	else if ((**format == 'l' && (*format)[1] == 'l' && (*format += 2)))
		arg->size = 2;
	else if (((**format == 'L') && ++*format))
		arg->size = 3;
	else if ((**format == 'l' || **format == 'w')
	&& ++(*format))
		arg->size = 1;
	else
		arg->size = 0;
	return (1);
}

/*
**	if type is 'p', we change some parmeters and pass it down as an 'x',
**		because it's easier & faster :)
**	if type is 'C' we change it to 'c' with size = 1
**		this way it's easier to handle "%C" like "%lc" or "%wc"
*/

int		prtf__get_arg_convtyp(t_arg *arg, const char **format)
{
	char	c;

	c = *((*format)++);
	if (c == 'p')
	{
		arg->option += FLAG_HASH;
		arg->option += FLAG_SPEP;
		arg->size = 1;
		c = 'x';
	}
	else if ((c == 'U') && (c = 'u'))
		arg->size = 1;
	arg->conv_typ = c;
	if (c == 'd' || c == 'i' || c == 'o'
	|| c == 'u' || c == 'x' || c == 'X'
	|| c == 's' || c == 'f' || c == 'p'
	|| c == 'c' || c == 'b' || c == 'r')
		return (1);
	else
		return (0);
}
