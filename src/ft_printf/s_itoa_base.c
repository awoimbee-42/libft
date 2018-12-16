/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_itoa_base.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <awoimbee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 15:14:07 by allespag          #+#    #+#             */
/*   Updated: 2018/12/16 20:40:11 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			s_count_base_digit(long long int n, int base)
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

char		*s_malloc_base_str(long long int n, int base, t_arg *arg, int sign)
{
	char	*str;
	int		i;
	int		zero;
	int		digit;

	i = 0;
	digit = s_count_base_digit(n, base);
	zero = (arg->precis > digit) ? arg->precis - digit : 0;
	if (!(str = (char *)malloc(digit + (sign
		|| arg->option & FLAG_PLUS || arg->option & FLAG_SPACE) + zero + 1)))
		prtf__msg_exit("Cannot allocate memory: s_malloc_base_str");
	if (sign && ++i)
		str[0] = '-';
	else if (!sign && (arg->option & FLAG_PLUS) && ++i)
		str[0] = '+';
	else if (!sign && (arg->option & FLAG_SPACE) && ++i)
		str[0] = ' ';
	while (i < zero + sign +
			((arg->option & FLAG_PLUS || arg->option & FLAG_SPACE) && !sign))
		str[i++] = '0';
	str[i] = '\0';
	return (str);
}

char		*prtf__s_itoa_base(long long int n, int base, t_arg *arg)
{
	int		i;
	int		tmp;
	int		sign;
	char	*str;
	char	*str_base;

	sign = (n < 0) ? 1 : 0;
	str = s_malloc_base_str(n, base, arg, sign);
	str_base = "0123456789ABCDEF";
	i = ft_strlen(str);
	tmp = i;
	n = (n < 0) ? -n : n;
	if (!n)
		str[i++] = '0';
	while (n)
	{
		str[i++] = str_base[ft_abs(n % base)];
		n /= base;
	}
	str[i++] = '\0';
	return (prtf__strsubrev(str, tmp));
}
