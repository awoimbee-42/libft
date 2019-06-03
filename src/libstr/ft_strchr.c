/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <awoimbee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 12:47:06 by awoimbee          #+#    #+#             */
/*   Updated: 2019/06/03 17:18:16 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	This function basically works like strlen,
**	So I could bing the same optimizations that I did to ft_strlen to it
*/

char	*ft_strchr(const char *s, int c)
{
	if (c == '\0')
		return ((char*)&s[ft_strlen(s)]);
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		++s;
	}
	return (NULL);
}
