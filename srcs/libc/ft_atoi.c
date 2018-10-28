/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <awoimbee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 18:03:11 by awoimbee          #+#    #+#             */
/*   Updated: 2018/10/28 01:28:34 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *nptr)
{
	short int		sign;
	unsigned long	result;

	result = 0;
	while (*nptr == ' ' || *nptr == '\n' || *nptr == '\t'
		|| *nptr == '\f' || *nptr == '\v' || *nptr == '\r')
		++nptr;
	sign = (*nptr == '-' && ++nptr) ? -1 : 1;
	nptr += (*nptr == '+') ? 1 : 0;
	while ('0' <= *nptr && *nptr <= '9')
		result = result * 10 + ((unsigned long)*nptr++ - 48UL);
	if (result > 2147483647 && sign == 1)
		return (-1);
	else if (result > 2147483648 && sign == -1)
		return (0);
	else
		return ((int)result * sign);
}