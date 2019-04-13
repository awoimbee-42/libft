/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <awoimbee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 13:36:47 by awoimbee          #+#    #+#             */
/*   Updated: 2019/04/11 14:59:23 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <stdlib.h>

static char		*ft_realloc(char *old_str, size_t addsize)
{
	char		*nw_str;
	size_t		old_size;

	old_size = old_str ? ft_strlen(old_str) : 0;
	if (!(nw_str = ft_strnew(old_size + addsize)))
		return (NULL);
	if (old_size)
	{
		nw_str = ft_strncpy(nw_str, old_str, old_size);
		free(old_str);
	}
	return (nw_str);
}

static void		shift_arr_left(t_list *link, size_t i)
{
	size_t		l;

	l = 0;
	while (l + i < link->content_size)
	{
		((char *)(link->content + 4))[l] = ((char *)(link->content + 4))[l + i];
		++l;
	}
	while (l < GNL_BUFF_SIZE)
		((char *)(link->content + 4))[l++] = '\0';
	return ;
}

static int		read_buff(t_list *link, char **line)
{
	size_t		i;
	void		*str;

	if (*(char*)(link->content + 4) == 0 && link->content_size == GNL_BUFF_SIZE)
		return (-1);
	if (*(char*)(link->content + 4) == 0)
		return (0);
	if ((str = ft_memchr(link->content + 4, '\n', link->content_size)) != NULL)
	{
		i = str - (link->content + 4);
		if (!(*line = ft_realloc(*line, i)))
			return (-1);
		ft_strncat(*line, (char *)(link->content + 4), i);
		shift_arr_left(link, i + 1);
		link->content_size -= i;
		return (1);
	}
	else
	{
		if (!(*line = ft_realloc(*line, link->content_size)))
			return (-1);
		ft_strncat(*line, (char *)(link->content + 4), link->content_size);
		shift_arr_left(link, link->content_size);
		return (0);
	}
}

/*
** lst->content_size = size string inside of buffer
** lst->content => first 4 bytes = fd,
**     the other BUFFER SIZE bytes are reserved for the actual buffer
*/

static t_list	*check_lst(t_list **lst, const int fd)
{
	t_list		*link;
	char		*buff;

	if (lst && (link = *lst))
	{
		while (link)
		{
			if (*((int *)(link->content)) == fd)
				return (link);
			link = link->next;
		}
	}
	if (!(buff = ft_memalloc(GNL_BUFF_SIZE + sizeof(int))))
		return (NULL);
	ft_memcpy(buff, &fd, sizeof(fd));
	if (!(link = ft_lst_push_back(lst, buff, GNL_BUFF_SIZE + 4)))
		return (NULL);
	link->content_size = 0;
	free(buff);
	return (link);
}

int				get_next_line(const int fd, char **line)
{
	static t_list	*lst;
	t_list			*link;
	int				i;
	ssize_t			cread;

	if (!line || (link = check_lst(&lst, fd)) == NULL)
		return (-1);
	if (line == GNL_FLUSH)
		return (ft_lst_free_link(&lst, link));
	*line = NULL;
	if ((i = read_buff(link, line)) != 0)
		return (i);
	while ((cread = read(fd, link->content + 4, GNL_BUFF_SIZE)) > 0)
	{
		link->content_size = cread;
		i = read_buff(link, line);
		if (i != 0)
			return (i);
	}
	if (cread > 0 || (*line && **line))
		return (1);
	ft_lst_free_link(&lst, link);
	return (cread);
}
