/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_f.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <awoimbee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 14:06:38 by allespag          #+#    #+#             */
/*   Updated: 2019/04/25 17:21:01 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*after_comma(char *str, int index, long double n, t_arg *arg)
{
	int			i;
	int			sign;

	i = 0;
	sign = (n < 0) ? -1 : 1;
	if (arg->precis)
		str[index - 1] = '.';
	while (i < arg->precis)
	{
		n = (n - (long)n) * 10;
		str[index + i] = ((long)n * sign) + '0';
		i++;
	}
	str[index + i] = '\0';
	return (str);
}

static char		*double_to_str(char *str, long double n, t_arg *arg, int sign)
{
	int			i;
	int			curpow;
	long double	tmp_n;
	int			tmp;

	i = 0;
	if (sign == -1 && ++i)
		str[0] = '-';
	else if (sign == 1 && (arg->option & FLAG_PLUS) && ++i)
		str[0] = '+';
	else if ((arg->option & FLAG_SPACE) && ++i)
		str[0] = ' ';
	curpow = 1;
	tmp_n = n * sign;
	while ((tmp_n /= 10.) >= 1.)
		curpow++;
	while (curpow--)
	{
		tmp_n *= 10;
		tmp = tmp_n;
		str[i++] = (tmp) + '0';
		tmp_n -= tmp;
	}
	return (after_comma(str, i + 1, n, arg));
}

static int		count_ldbl_digit(long double n)
{
	int		ret;

	ret = 0;
	if (n < 1.)
		return (1);
	while (n >= 1.)
	{
		n /= 10.;
		ret++;
	}
	return (ret);
}

static char		*prtf__itoa_double_malloc(char *str, long double n, t_arg *arg)
{
	int		to_malloc;

	to_malloc = count_ldbl_digit(n) + arg->precis + 3;
	if (to_malloc < arg->m_width)
	{
		if (!(str = (char *)malloc(arg->m_width + 1)))
			prtf__msg_exit(MALLOC_ERR);
		ft_memset(str, ' ', arg->m_width + 1);
		str[arg->m_width] = '\0';
	}
	else
	{
		if (!(str = (char *)malloc(to_malloc)))
			prtf__msg_exit(MALLOC_ERR);
		ft_memset(str, ' ', to_malloc);
	}
	return (str);
}

char			*prtf__itoa_double(long double n, t_arg *arg)
{
	int			i;
	int			tmp;
	int			sign;
	char		*str;
	long double	aux;

	i = 0;
	tmp = 0;
	sign = (n < 0) ? -1 : 1;
	str = NULL;
	aux = n;
	arg->precis = (arg->precis == -1) ? 6 : arg->precis;
	while (i++ <= arg->precis)
		n *= 10;
	i = 0;
	if (ft_labs((long)n % 10) >= 5)
		tmp = 1;
	n /= 10.L;
	i++;
	if (tmp)
		aux = (sign == -1) ? aux - 1 : aux + 1;
	while (i++ <= arg->precis)
		n /= 10.L;
	str = prtf__itoa_double_malloc(str, aux, arg);
	return (double_to_str(str, aux, arg, sign));
}
