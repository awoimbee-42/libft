/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat_join.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <awoimbee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 17:53:56 by awoimbee          #+#    #+#             */
/*   Updated: 2020/03/06 00:28:04 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/ft_str.h>
#include <stdlib.h>

int		ft_strncat_join(char **s1, char const *s2, size_t size)
{
	char		*new_str;
	size_t		len;

	if (!s2 && !*s1)
		return (0);
	len = ft_strlen(s2);
	len > size ? len = size : 0;
	if (!*s1 && s2)
	{
		if (!(new_str = ft_strnew(len)))
			return (0);
		ft_strncpy(new_str, s2, len);
		*s1 = new_str;
	}
	else if (s2)
	{
		len += ft_strlen(*s1);
		if (!(new_str = ft_strnew(len)))
			return (0);
		ft_strcpy(new_str, *s1);
		ft_strncat(new_str, s2, size);
		free(*s1);
		*s1 = new_str;
	}
	return (1);
}
