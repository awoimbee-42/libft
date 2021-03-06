/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <awoimbee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 01:37:49 by awoimbee          #+#    #+#             */
/*   Updated: 2020/03/06 00:24:28 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/ft_str.h>
#include <unistd.h>

void	ft_putstr(char const *s)
{
	size_t	len;

	if (!s)
		return ;
	len = ft_strlen(s);
	write(STDOUT_FILENO, (const void *)s, len);
}
