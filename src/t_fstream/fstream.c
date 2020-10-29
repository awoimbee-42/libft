/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fstream.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <awoimbee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 15:25:53 by awoimbee          #+#    #+#             */
/*   Updated: 2020/10/29 22:25:22 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

static t_fstream	*ft_fstream_setup_basics()
{
	t_fstream	*dat;

	dat = malloc_exit(sizeof(*dat));
	dat->priv.fd = -1;
	dat->priv.fname = NULL;
	dat->priv.chunk_size = 0;
	dat->priv.buf_size = 0;
	dat->priv.buf_dat_len = 0;
	dat->priv.buf = NULL;
	dat->p.total_len = 0;
	dat->p.len = 0;
	dat->p.buf = NULL;
	return (dat);
}

t_fstream		*ft_fstream_setup_fd(int fd, size_t chunksiz)
{
	t_fstream	*dat;

	ft_assert(chunksiz > 0, "fstream: cannot operate on 0 size chunk !");
	dat = ft_fstream_setup_basics();
	dat->priv.fd = fd;
	dat->priv.buf_size = chunksiz > _FSTREAM_MIN_READ ?
		chunksiz
		: (_FSTREAM_MIN_READ / chunksiz) * chunksiz;
	dat->priv.buf = malloc_exit(dat->priv.buf_size);
	dat->p.buf = dat->priv.buf + dat->priv.buf_size;
	dat->priv.chunk_size = chunksiz;
	return (dat);
}

t_fstream		*ft_fstream_setup_buf(void *buf, size_t siz, size_t chunksiz)
{
	t_fstream	*dat;

	ft_assert(chunksiz > 0, "fstream: cannot operate on 0 size chunk !");
	dat = ft_fstream_setup_basics();
	dat->priv.buf = buf;
	dat->p.buf = buf - chunksiz;
	dat->priv.buf_dat_len = siz;
	dat->priv.buf_size = siz;
	dat->priv.chunk_size = chunksiz;
	return (dat);
}

t_fstream		*ft_fstream_setup_str(char *str, size_t chunksiz)
{
	size_t		strlen;

	strlen = ft_strlen(str);
	if (chunksiz == 0)
		chunksiz = strlen;
	return (ft_fstream_setup_buf(str, strlen, chunksiz));
}

t_fstream		*ft_fstream_setup_fname(char *fname, size_t chunksiz)
{
	t_fstream	*dat;
	int			fd;

	ft_assert((fd = open(fname, O_RDONLY)) != -1, "Could not open %s", fname);
	dat = ft_fstream_setup_fd(fd, chunksiz);
	dat->priv.fname = fname;
	return (dat);
}

/*
**	if dat->fname != NULL:
**		- ft_fstream_setup_str was used
**		- fd was opened by us
*/

void			ft_fstream_kill(t_fstream *dat)
{
	if (dat == NULL)
		return ;
	if (dat->priv.fd != -1)
		free(dat->priv.buf);
	if (dat->priv.fname && __builtin_expect((close(dat->priv.fd) == -1), 0))
		ft_printf("Could not close %s: %s", dat->priv.fname, strerror(errno));
	free(dat);
}

bool			ft_fstream(t_fstream *dat)
{
	if (dat == NULL)
		return (false);
	dat->p.buf += dat->priv.chunk_size;
	if (dat->p.buf >= (dat->priv.buf + dat->priv.buf_dat_len))
	{
		if (dat->priv.fd == -1)
			return (false);
		if (dat->priv.fd == -1 || (dat->priv.buf_dat_len
					&& dat->priv.buf_dat_len != dat->priv.buf_size))
			return (false);
		ft_assert((dat->priv.buf_dat_len = read(dat->priv.fd, dat->priv.buf,
			dat->priv.buf_size)) != (size_t)-1,
			"Could not read from %d (%s)", dat->priv.fd, dat->priv.fname);
		dat->p.buf = dat->priv.buf;
		dat->p.len =
			dat->priv.buf_dat_len > dat->priv.chunk_size ?
				dat->priv.chunk_size : dat->priv.buf_dat_len;
	}
	else
	{
		dat->p.len = dat->priv.buf_dat_len
			- (dat->p.buf - dat->priv.buf);
		dat->p.len = dat->p.len > dat->priv.chunk_size
			? dat->priv.chunk_size : dat->p.len;
	}
	dat->p.total_len += dat->p.len;
	return (dat->p.len != 0);
}
