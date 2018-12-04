/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <awoimbee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 20:57:23 by exam              #+#    #+#             */
/*   Updated: 2018/12/04 15:48:36 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static char	*f_strrev(char *str)
{
	char	*start;
	char	*end;
	char	buff;

	start = str;
	end = str;
	while (*(end + 1))
		++end;
	while (start < end)
	{
		buff = *start;
		*start = *end;
		*end = buff;
		start++;
		end--;
	}
	return (str);
}

char		*ft_itoa_base(int value, int base)
{
	char	*str_base;
	char	*result;
	int		i;
	int		sign;

	sign = (value < 0) ? -1 : 1;
	str_base = "0123456789ABCDEF";
	if (!(result = malloc(((value / base) * sign + 2))))
		return (NULL);
	i = 0;
	if (value == 0)
		result[i++] = '0';
	while (value != 0)
	{
		result[i++] = str_base[(value % base) * sign];
		value /= base;
	}
	if (sign == -1)
		result[i++] = '-';
	result[i++] = '\0';
	return (f_strrev(result));
}
