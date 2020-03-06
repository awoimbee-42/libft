/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <awoimbee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 01:21:17 by awoimbee          #+#    #+#             */
/*   Updated: 2020/03/06 00:28:04 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft/ft_str.h>
#include <libft/ft_mem.h>

char	*ft_strdup(const char *s1)
{
	char		*cpy;
	size_t		len;

	len = ft_strlen(s1) + 1;
	cpy = malloc(len);
	if (!cpy)
		return (NULL);
	ft_memcpy(cpy, s1, len);
	return (cpy);
}
