/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stpcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <awoimbee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 15:02:11 by awoimbee          #+#    #+#             */
/*   Updated: 2018/12/05 15:02:31 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_stpcpy(char *dest, const char *src)
{
	while (*src != '\0')
	{
		*dest = *src;
		++dest;
		++src;
	}
	*dest = *src;
	return (dest);
}
