/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <awoimbee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 18:03:11 by awoimbee          #+#    #+#             */
/*   Updated: 2018/10/26 18:20:37 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *nptr)
{
	short int	sign;
	int			result;

	result = 0;
	while (*nptr == ' ' || *nptr == '\n' || *nptr == '\t'
		|| *nptr == '\f' || *nptr == '\v' || *nptr == '\r')
		++nptr;
	sign = (*nptr == '-' && ++nptr) ? -1 : 1;
	nptr += (*nptr == '+') ? 1 : 0;
	while ('0' <= *nptr && *nptr <= '9')
		result = result * 10 + (*nptr++ - '0');
	return (result * sign);
}