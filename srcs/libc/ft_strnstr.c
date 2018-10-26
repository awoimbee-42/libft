/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <awoimbee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 13:04:05 by awoimbee          #+#    #+#             */
/*   Updated: 2018/10/26 17:41:12 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_found(const char *haystack, const char *needle, size_t n)
{
	int		i;

	i = 0;
	while (1)
	{
		if (needle[i] == '\0')
			return (1);
		else if (haystack[i] == needle[i])
			++i;
		else
			return (0);
	}
}

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	while (*s1 != '\0')
	{
		if (is_found(s1, s2, n))
			return ((char *)s1);
		++s1;
	}
	return (0);
}