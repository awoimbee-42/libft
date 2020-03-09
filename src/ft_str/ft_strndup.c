/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <awoimbee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 20:38:00 by awoimbee          #+#    #+#             */
/*   Updated: 2020/03/06 00:28:04 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft/ft_str.h>
#include <libft/ft_mem.h>

char	*ft_strndup(const char *s1, size_t maxlen)
{
	char		*cpy;
	size_t		len;

	len = ft_strlen(s1);
	if (maxlen < len)
		len = maxlen;
	cpy = malloc(len + 1);
	if (!cpy)
		return (NULL);
	ft_memcpy(cpy, s1, len);
	cpy[len] = '\0';
	return (cpy);
}
