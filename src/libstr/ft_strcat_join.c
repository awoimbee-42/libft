/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat_join.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <awoimbee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 18:55:58 by awoimbee          #+#    #+#             */
/*   Updated: 2019/05/20 16:20:11 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int		ft_strcat_join(char **s1, char const *s2)
{
	char		*new_str;
	size_t		len_s2;
	size_t		len_s1;

	if (!s2 && !*s1)
		return (0);
	if (!*s1 && s2)
	{
		*s1 = ft_strdup(s2);
		if (!*s1)
			return (0);
	}
	else if (s2)
	{
		len_s1 = ft_strlen(*s1);
		len_s2 = ft_strlen(s2);
		if (!(new_str = ft_strnew(len_s1 + len_s2)))
			return (0);
		ft_mempcpy(ft_mempcpy(new_str, *s1, len_s1), s2, len_s2 + 1);
		free(*s1);
		*s1 = new_str;
	}
	return (1);
}
