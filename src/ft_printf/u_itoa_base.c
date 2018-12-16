/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_itoa_base.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <awoimbee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 16:55:01 by allespag          #+#    #+#             */
/*   Updated: 2018/12/16 20:40:11 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		u_count_base_digit(unsigned long long n, int base)
{
	int		i;

	i = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n /= base;
		i++;
	}
	return (i);
}

static char		*u_malloc_base_str(unsigned long long n, int base, t_arg *arg)
{
	char	*str;
	int		i;
	int		zero;
	int		digit;

	i = 0;
	digit = u_count_base_digit(n, base);
	zero = (arg->precis > digit) ? arg->precis - digit : 0;
	if (((arg->option & FLAG_HASH) && (n != 0)) || (arg->option & FLAG_SPEP))
	{
		zero += (arg->conv_typ == 'x' || arg->conv_typ == 'b'
			|| arg->conv_typ == 'X') ? 2 : 0;
		zero += (arg->conv_typ == 'o') ? 1 : 0;
	}
	if (!(str = (char *)malloc(digit + zero + 1)))
		prtf__msg_exit("cannot allocate memory: u_malloc_base_str");
	while (i < zero)
		str[i++] = '0';
	if ((n && ((arg->option & FLAG_HASH) && (arg->conv_typ == 'x'
	|| arg->conv_typ == 'X' || arg->conv_typ == 'b')))
	|| (arg->option & FLAG_SPEP))
		str[1] = arg->conv_typ;
	str[i] = '\0';
	return (str);
}

char			*prtf__u_itoa_base(unsigned long long n, int base, t_arg *arg)
{
	int		i;
	int		tmp;
	char	*str;
	char	*str_base;

	str = u_malloc_base_str(n, base, arg);
	str_base = (arg->conv_typ >= 'a' && arg->conv_typ <= 'z') ?
	"0123456789abcdef" : "0123456789ABCDEF";
	i = ft_strlen(str);
	tmp = i;
	if (!n)
		str[i++] = '0';
	while (n)
	{
		str[i++] = str_base[(n % base)];
		n /= base;
	}
	str[i++] = '\0';
	return (prtf__strsubrev(str, tmp));
}
