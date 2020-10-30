/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_fd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <awoimbee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 22:03:06 by awoimbee          #+#    #+#             */
/*   Updated: 2020/10/30 23:42:56 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/t_fstream.h>
#include <libft/ft_exit.h>
#include <fcntl.h>

t_fstream		*ft_fstream_setup_fd(int fd, size_t c)
{
	t_fstream	*dat;
	size_t		buf_size;
	void		*buf;

	ft_assert(c > 0, "fstream: cannot operate on 0 size chunk !");
	dat = malloc_exit(sizeof(*dat));
	buf_size = c > _FSTREAM_MIN_READ ? c : (_FSTREAM_MIN_READ / c) * c;
	buf = malloc_exit(buf_size);
	*dat = (t_fstream){
		priv: (struct s_priv_fstream){
			type: FSTREAM_FD,
			fd: fd,
			fname: NULL,
			chunk_size: c,
			buf_size: buf_size,
			buf_dat_len: buf_size,
			buf: buf,
		},
		s: (struct s_pub_fstream){
			total_len: 0,
			len: 0,
			buf: buf + buf_size,
		}
	};
	return (dat);
}

t_fstream		*ft_fstream_setup_fname(const char *fname, size_t chunksiz)
{
	t_fstream	*dat;
	int			fd;

	ft_assert((fd = open(fname, O_RDONLY)) != -1, "Could not open %s", fname);
	dat = ft_fstream_setup_fd(fd, chunksiz);
	dat->priv.type = FSTREAM_FNAME;
	dat->priv.fname = fname;
	return (dat);
}
