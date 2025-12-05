/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_max.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <awoimbee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/12 18:14:22 by awoimbee          #+#    #+#             */
/*   Updated: 2020/03/06 00:40:58 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>

int		ft_maxint(int a, int b)
{
	return (a > b ? a : b);
}

long	ft_maxlong(long a, long b)
{
	return (a > b ? a : b);
}

unsigned int	ft_maxuint(unsigned int a, unsigned int b)
{
	return (a > b ? a : b);
}
