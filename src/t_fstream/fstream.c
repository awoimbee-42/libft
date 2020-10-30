/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fstream.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <awoimbee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 15:25:53 by awoimbee          #+#    #+#             */
/*   Updated: 2020/10/30 23:48:44 by awoimbee         ###   ########.fr       */
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
** d->priv.buf_dat_len == d->priv.buf_size could be problematic
*/

bool					ft_fstream(t_fstream *d)
{
	if (!d)
		return (false);
	d->s.buf += d->priv.chunk_size;
	if (__builtin_expect(d->s.buf < (d->priv.buf + d->priv.buf_dat_len), 1))
		d->s.len = szt_min(d->priv.buf_dat_len - (d->s.buf - d->priv.buf),
				d->priv.chunk_size);
	else if (d->priv.fd != -1 && d->priv.buf_dat_len == d->priv.buf_size)
	{
		ft_assert((d->priv.buf_dat_len = read(d->priv.fd, d->priv.buf,
			d->priv.buf_size)) != (size_t)-1,
			"Could not read from %d (%s)", d->priv.fd, d->priv.fname);
		d->s.buf = d->priv.buf;
		d->s.len = szt_min(d->priv.buf_dat_len, d->priv.chunk_size);
	}
	else
		return (false);
	d->s.total_len += d->s.len;
	return (d->s.len != 0);
}

bool					ft_fstream_autofree(t_fstream **dat)
{
	bool	res;

	res = ft_fstream(*dat);
	if (!res)
		ft_fstream_kill(dat);
	return (res);
}
