/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <awoimbee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 12:35:42 by awoimbee          #+#    #+#             */
/*   Updated: 2018/10/26 12:45:56 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	size_left;

	size_left = size;
	while (*dst && size_left-- > 0)
		dst++;
	while (*src && size_left-- > 1)
		*dst++ = *src++;
	if (size_left >= 1)
		*dst = '\0';
	return (size - size_left);
}