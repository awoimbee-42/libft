/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <awoimbee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 00:09:36 by awoimbee          #+#    #+#             */
/*   Updated: 2018/11/06 15:05:37 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_itoa(int n)
{
	char		*result;
	int			i;
	short		sign;
	int			tenpow;

	sign = (n < 0) ? 2 : 1;
	i = 1;
	tenpow = 1;
	while ((n / tenpow / 10) != 0 && ++i)
		tenpow *= 10;
	if (!(result = malloc((unsigned long)(i + sign) * sizeof(char))))
		return (NULL);
	i = 0;
	if (sign == 2 && (sign = -1))
		result[i++] = '-';
	while (tenpow != 0)
	{
		result[i++] = (char)((int)n / tenpow * sign + 48);
		n %= tenpow;
		tenpow /= 10;
	}
	result[i++] = '\0';
	return (result);
}
