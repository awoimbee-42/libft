/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <awoimbee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 18:03:11 by awoimbee          #+#    #+#             */
/*   Updated: 2018/11/12 12:12:08 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *nptr)
{
	short int		sign;
	unsigned long	result;

	result = 0;
	sign = 1;
	while (*nptr == ' ' || *nptr == '\n' || *nptr == '\t'
		|| *nptr == '\f' || *nptr == '\v' || *nptr == '\r')
		++nptr;
	if (*nptr == '-' && ++nptr)
		sign = -1;
	else if (*nptr == '+')
		++nptr;
	while ('0' <= *nptr && *nptr <= '9')
		result = result * 10UL + ((unsigned long)*nptr++ - 48UL);
	return ((int)result * sign);
}
