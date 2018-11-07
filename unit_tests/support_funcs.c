/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   support_funcs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <awoimbee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 10:43:44 by awoimbee          #+#    #+#             */
/*   Updated: 2018/11/07 10:48:05 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

char	*itoa(int n)
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

void		*malloc_safe(size_t size)
{
	void	*tmp;

	if (!(tmp = malloc(size)))
	{
		write(2, "malloc failure !\n", 16);
		exit(EXIT_FAILURE);
	}
	return (tmp);
}


