/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <awoimbee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 01:48:00 by awoimbee          #+#    #+#             */
/*   Updated: 2018/10/23 20:38:16 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void 	*ft_memalloc(size_t size)
{
	char *ptr;

	if ((ptr = (char *)malloc(size)) == NULL)
		return (NULL);
	while (size-- > 0)
	{
		ptr[size] = 0;
	}
	return ((void *)ptr);
}