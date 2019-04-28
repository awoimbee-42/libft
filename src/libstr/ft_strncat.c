/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <awoimbee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 12:33:32 by awoimbee          #+#    #+#             */
/*   Updated: 2019/04/28 05:49:00 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	char	*result;

	result = dest;
	while (*dest != '\0')
	{
		++dest;
	}
	while (*src != '\0' && n > 0)
	{
		*dest = *src;
		++src;
		++dest;
		--n;
	}
	*dest = '\0';
	return (result);
}
