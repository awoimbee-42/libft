/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_r.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <awoimbee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 15:17:25 by allespag          #+#    #+#             */
/*   Updated: 2020/03/06 00:55:35 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <libft/ft_str.h>
#include <libft/ft_fd.h>

void	prtf__flag_r(t_prtfstr *ret, int fd)
{
	int		end;
	char	*line;

	end = 1;
	ret->str = NULL;
	line = NULL;
	while ((end = get_next_line(fd, &line)))
	{
		if (end == -1)
			prtf__msg_exit("failure while reading file.");
		ft_strcat_join(&ret->str, line);
		ret->len = ft_strlen(ret->str);
		ret->str[ret->len] = '\n';
		ret->str[ret->len + 1] = '\0';
		free(line);
	}
	ret->len = ft_strlen(ret->str);
}
