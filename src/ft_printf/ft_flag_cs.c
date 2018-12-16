/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_cs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <awoimbee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 17:06:21 by allespag          #+#    #+#             */
/*   Updated: 2018/12/16 20:38:37 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	prtf__flag_s(t_string *ret, char *str, t_arg *arg)
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

void	prtf__flag_c(t_string *ret, char c)
{
	if (!(ret->str = malloc(1)))
		prtf__msg_exit("Cannot allocate memory in flag_c");
	*ret->str = c;
	ret->len = 1;
}
