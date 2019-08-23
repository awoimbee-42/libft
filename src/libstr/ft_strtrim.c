/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <awoimbee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 22:35:49 by awoimbee          #+#    #+#             */
/*   Updated: 2019/08/21 12:13:22 by awoimbee         ###   ########.fr       */
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
	i = 0;
	while (s[i])
		++i;
	while (i > 0 && is_whitespace(s[i - 1]))
		--i;
	if (!(new_str = malloc(i + 1)))
		return (NULL);
	new_str[i] = '\0';
	ft_strncpy(new_str, s, i);
	return (new_str);
}
