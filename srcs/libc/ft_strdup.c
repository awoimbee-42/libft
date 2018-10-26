/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <awoimbee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 01:21:17 by awoimbee          #+#    #+#             */
/*   Updated: 2018/10/26 11:59:28 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s)
{
	char		*cpy;
	size_t		i;

	i = ft_strlen(s);
	cpy = malloc((i + 1) * sizeof(char));
	i = -1;
	while (s[++i])
		cpy[i] = s[i];
	cpy[i] = s[i];
	return (cpy);
}