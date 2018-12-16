/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat_join.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 18:55:58 by awoimbee          #+#    #+#             */
/*   Updated: 2018/12/16 17:19:04 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int		ft_strcat_join(char **s1, char const *s2)
{
	char		*new_str;
	size_t		len;

	if (!s2 && !*s1)
		return (0);
	if (!*s1 && s2)
	{
		len = ft_strlen(s2);
		if (!(new_str = ft_strnew(len)))
			return (0);
		ft_strcpy(new_str, s2);
		*s1 = new_str;
	}
	else if (s2)
	{
		len = ft_strlen(*s1) + ft_strlen(s2);
		if (!(new_str = ft_strnew(len)))
			return (0);
		ft_stpcpy(ft_stpcpy(new_str, *s1), s2);
		free(*s1);
		*s1 = new_str;
	}
	return (1);
}
