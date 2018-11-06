/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <awoimbee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 01:40:26 by awoimbee          #+#    #+#             */
/*   Updated: 2018/11/06 15:06:14 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	int			i;
	short		sign;
	int			tenpow;

	sign = (n < 0) ? 2 : 1;
	i = 1;
	tenpow = 1;
	while ((n / tenpow / 10) != 0 && ++i)
		tenpow *= 10;
	i = 0;
	if (sign == 2 && (sign = -1))
		ft_putchar('-');
	while (tenpow != 0)
	{
		ft_putchar((char)((int)n / tenpow * sign + 48));
		n %= tenpow;
		tenpow /= 10;
	}
}
