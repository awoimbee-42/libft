/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fstream.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <awoimbee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 15:25:53 by awoimbee          #+#    #+#             */
/*   Updated: 2020/10/31 22:51:38 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

static inline size_t	szt_min(size_t a, size_t b)
{
	return (a < b ? a : b);
}

/*
** f->priv.buf_len == f->priv.buf_siz could be problematic
*/

bool					ft_fstream(t_fstream *f)
{
	if (__builtin_expect(!f, 0))
		return (false);
	f->s.buf += f->priv.chunk_siz;
	if (__builtin_expect(f->s.buf < (f->priv.buf + f->priv.dat_len), 1))
		f->s.len = szt_min(f->priv.dat_len - (f->s.buf - f->priv.buf),
				f->priv.chunk_siz);
	else if (f->priv.fd != -1 && f->priv.dat_len != 0)
	{
		ft_assert((f->priv.dat_len = read(f->priv.fd, f->priv.buf,
			f->priv.buf_siz)) != (size_t)-1,
			"Could not read from %d (%s)", f->priv.fd, f->priv.fname);
		f->s.buf = f->priv.buf;
		f->s.len = szt_min(f->priv.dat_len, f->priv.chunk_siz);
	}
	else
		return (false);
	f->s.total_len += f->s.len;
	return (f->s.len != 0);
}

bool					ft_fstream_fullblock(t_fstream *f)
{
	ssize_t	tmp;
	size_t	new_dat_len;

	if (f->priv.dat_len == 0 || !ft_fstream(f))
		return (false);
	if (f->priv.dat_len == 0 || f->priv.dat_len == f->priv.buf_siz)
		return (true);
	new_dat_len = f->priv.dat_len;
	tmp = 1;
	while (tmp != 0 && new_dat_len != f->priv.buf_siz)
	{
		tmp = read(f->priv.fd,
			&f->priv.buf[new_dat_len], f->priv.buf_siz - new_dat_len);
		ft_assert(tmp != -1,
			"Could not read from %d (%s)", f->priv.fd, f->priv.fname);
		new_dat_len += (size_t)tmp;
	}
	f->priv.dat_len = 0;
	tmp =
		szt_min(new_dat_len - (f->s.buf - f->priv.buf), f->priv.chunk_siz);
	f->s.total_len += tmp - f->s.len;
	f->s.len = tmp;
	return (f->s.len != 0);
}

bool					ft_fstream_autofree(t_fstream **dat)
{
	bool	res;

	res = ft_fstream(*dat);
	if (!res)
		ft_fstream_kill(dat);
	return (res);
}

bool					ft_fstream_fullblock_autofree(t_fstream **dat)
{
	bool	res;

	res = ft_fstream_fullblock(*dat);
	if (!res)
		ft_fstream_kill(dat);
	return (res);
}
