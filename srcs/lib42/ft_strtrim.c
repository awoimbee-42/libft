/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <awoimbee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 22:35:49 by awoimbee          #+#    #+#             */
/*   Updated: 2018/11/06 15:08:59 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_whitespace(char c)
{
	return (c == ' ' || c == '\n' || c == '\t');
}

char		*ft_strtrim(char const *s)
{
	size_t		i;
	char		*new_str;

	if (!s)
		return (NULL);
	while (is_whitespace(*s))
		++s;
	if (*s == '\0')
		return ("\0");
	i = 0;
	while (s[i])
		++i;
	while (is_whitespace(s[i - 1]))
		--i;
	if (!(new_str = ft_strnew(i)))
		return (NULL);
	ft_strncpy(new_str, s, i);
	return (new_str);
}
