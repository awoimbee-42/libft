/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <awoimbee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 23:16:37 by awoimbee          #+#    #+#             */
/*   Updated: 2019/05/06 14:50:23 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <math.h>

static inline const char	*skip_whitespace(const char *cstr)
{
	while (*cstr == ' ' || *cstr == '\n' || *cstr == '\t'
		|| *cstr == '\f' || *cstr == '\v' || *cstr == '\r')
		++cstr;
	return (cstr);
}

static inline double		parse_decimal(const char **nptr)
{
	double			result;
	double			i;

	result = 0;
	i = 1;
	while (ft_isdigit(**nptr))
	{
		i *= 10;
		result += (double)(**nptr - 48) / i;
		*nptr += 1;
	}
	return (result);
}

static inline double		parse_exponent(const char *nptr)
{
	int				sign;
	int				exponent;
	double			res;

	exponent = 0;
	sign = 1;
	if (*nptr == '-' && ++nptr)
		sign = -1;
	else if (*nptr == '+')
		++nptr;
	while (ft_isdigit(*nptr))
		exponent = exponent * 10 + (*nptr++ - 48);
	if (exponent == 0)
		return (1);
	res = 1;
	if (sign == 1)
		while (exponent--)
			res *= 10;
	else if (sign == -1)
		while (exponent--)
			res /= 10;
	return (res);
}

double						ft_atof(const char *nptr)
{
	int				sign;
	double			result;

	result = 0;
	sign = 1;
	nptr = skip_whitespace(nptr);
	if (*nptr == '-' && ++nptr)
		sign = -1;
	else if (*nptr == '+')
		++nptr;
	if (!ft_strncmp(nptr, "inf", 3))
		return (INFINITY * sign);
	else if (!ft_strncmp(nptr, "nan", 3))
		return (NAN);
	while (ft_isdigit(*nptr))
		result = result * 10 + (*nptr++ - 48);
	if (*nptr == '.' && *++nptr)
		result += parse_decimal(&nptr);
	if (*nptr == 'e')
		result *= parse_exponent(nptr + 1);
	return (result * sign);
}
