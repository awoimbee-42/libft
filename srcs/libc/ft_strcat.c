/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <awoimbee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 12:22:20 by awoimbee          #+#    #+#             */
/*   Updated: 2018/10/26 12:32:50 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strcat(char *dest, const char *src)
{
	char	*result;

	result = dest;
	while (*dest != '\0')
		++dest;
	while (*src != '\0')
		*dest++ = *src++;
	*dest = *src;
	return (result);
}