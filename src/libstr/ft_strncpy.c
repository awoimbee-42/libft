/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <awoimbee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 12:04:37 by awoimbee          #+#    #+#             */
/*   Updated: 2019/04/28 05:48:45 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	char				*srccpy;

	srccpy = dest;
	++n;
	while (--n > 0 && *src != '\0')
	{
		*dest++ = *src++;
	}
	while (n-- > 0 && *dest != '\0')
	{
		*dest = '\0';
		++dest;
	}
	return (srccpy);
}
