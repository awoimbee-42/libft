/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat_join.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <awoimbee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 18:55:58 by awoimbee          #+#    #+#             */
/*   Updated: 2018/12/04 19:09:12 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcat_join(char **s1, char const *s2)
{
	char		*new_str;
	size_t		len;

	if (!s2 && !s1)
		return (0);
	if (!s2)
		return (1);
	if (!*s1)
	{
		len = ft_strlen(s2);
		if (!(new_str = ft_strnew(len)))
			return (NULL);
		ft_strcpy(new_str, s2);
		return (1);
	}
	else
	{
		len = ft_strlen(s1) + ft_strlen(s2);
		if (!(new_str = ft_strnew(len)))
			return (NULL);
		ft_strcpy(new_str, s1);
		ft_strcpy(new_str, s2);
		return (1);
	}
}
