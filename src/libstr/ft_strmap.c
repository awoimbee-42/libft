/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <awoimbee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 22:56:19 by awoimbee          #+#    #+#             */
/*   Updated: 2019/04/28 04:52:44 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
