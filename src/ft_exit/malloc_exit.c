/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_exit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <awoimbee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 15:32:23 by awoimbee          #+#    #+#             */
/*   Updated: 2020/10/29 15:52:48 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/ft_exit.h>
#include <stdlib.h>

void	*malloc_exit(size_t size)
{
	void	*res;

	res = malloc(size);
	if (res == NULL)
	{
		ft_msg_exit("ERR: Could not allocate enough heap memory.", NULL);
	}
	return (res);
}
