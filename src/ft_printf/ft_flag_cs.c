/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_cs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 17:06:21 by allespag          #+#    #+#             */
/*   Updated: 2018/12/16 18:11:23 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	flag_s(t_string *ret, char *str, t_arg *arg)
{
	if (str)
	{
		ret->str = str;
		ret->len = 0;
		while (str[ret->len])
			ret->len++;
		if ((unsigned int)arg->precis < ret->len)
			ret->len = arg->precis;
	}
	else
	{
		ret->str = "(null)";
		ret->len = 6;
	}
}

void	flag_c(t_string *ret, char c)
{
	if (!(ret->str = malloc(1)))
		msg_exit("Cannot allocate memory in flag_c");
	*ret->str = c;
	ret->len = 1;
}
