/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_max.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <awoimbee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/12 18:14:22 by awoimbee          #+#    #+#             */
/*   Updated: 2019/05/12 18:22:19 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <sys/types.h>

int		ft_maxint(int a, int b)
{
	return (a > b ? a : b);
}

long	ft_maxlong(long a, long b)
{
	return (a > b ? a : b);
}

uint	ft_maxuint(uint a, uint b)
{
	return (a > b ? a : b);
}
