/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <awoimbee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 22:59:23 by awoimbee          #+#    #+#             */
/*   Updated: 2018/11/06 15:09:18 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static size_t	get_tab_size(const char *str, char c)
{
	size_t	i;

	i = 0;
	while (*str != '\0' && ++str)
	{
		while (*str != c && *str != '\0')
			++str;
		++i;
		while (*str == c)
			++str;
	}
	return (i + 1);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		i;
	size_t	lenstr;

	if (!s)
		return (NULL);
	while (*s == c)
		++s;
	if (!(tab = (char**)malloc(get_tab_size(s, c) * sizeof(char*))))
		return (NULL);
	i = 0;
	while (*s != '\0')
	{
		lenstr = 0;
		while (*s != c && *s != '\0' && ++s)
			++lenstr;
		if (!(tab[i] = ft_strnew(lenstr)))
			return (NULL);
		ft_strncpy(tab[i++], s - lenstr, lenstr);
		while (*s == c)
			++s;
	}
	tab[i] = 0;
	return (tab);
}
