/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <awoimbee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 12:01:44 by awoimbee          #+#    #+#             */
/*   Updated: 2018/11/06 15:16:27 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dest, const char *src)
{
	char *srccpy;

	srccpy = dest;
	while (*src != '\0')
	{
		*dest = *src;
		++dest;
		++src;
	}
	*dest = *src;
	return (srccpy);
}
