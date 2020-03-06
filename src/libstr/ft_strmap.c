/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <awoimbee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 22:56:19 by awoimbee          #+#    #+#             */
/*   Updated: 2020/03/06 00:28:04 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/ft_str.h>

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*out;
	int		i;

	if (!s || !f)
		return (NULL);
	if (!(out = ft_strnew(ft_strlen(s))))
		return (NULL);
	i = -1;
	while (s[++i])
	{
		out[i] = (*f)((char)s[i]);
	}
	return (out);
}
