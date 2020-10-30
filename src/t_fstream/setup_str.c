/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <awoimbee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 22:08:45 by awoimbee          #+#    #+#             */
/*   Updated: 2020/10/31 00:05:24 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/t_fstream.h>
#include <libft/ft_exit.h>
#include <libft/ft_str.h>
#include <libft/ft_mem.h>

t_fstream		*ft_fstream_setup_buf_mut(void *buf, size_t siz, size_t c)
{
	t_fstream	*dat;

	ft_assert(c > 0, "fstream: cannot operate on 0 size chunk !");
	dat = malloc_exit(sizeof(*dat));
	*dat = (t_fstream){
		priv: (struct s_priv_fstream){
			type: FSTREAM_BUF_MUT,
			fd: -1,
			fname: NULL,
			chunk_size: c,
			buf_size: siz,
			buf_dat_len: siz,
			buf: buf,
		},
		s: (struct s_pub_fstream){
			total_len: 0,
			len: 0,
			buf: buf - c,
		}
	};
	return (dat);
}

t_fstream		*ft_fstream_setup_buf(const void *buf, size_t siz, size_t c)
{
	t_fstream	*dat;
	void		*new_buf;

	new_buf = malloc_exit(siz < c ? c : siz);
	ft_memcpy(new_buf, buf, siz);
	dat = ft_fstream_setup_buf_mut(new_buf, siz, c);
	dat->priv.type = FSTREAM_BUF;
	return (dat);
}


t_fstream		*ft_fstream_setup_str_mut(char *str, size_t chunksiz)
{
	size_t		strlen;

	strlen = ft_strlen(str);
	chunksiz = chunksiz == 0 ? strlen : chunksiz;
	return (ft_fstream_setup_buf_mut(str, strlen, chunksiz));
}

t_fstream		*ft_fstream_setup_str(const char *str, size_t chunksiz)
{
	size_t		strlen;

	strlen = ft_strlen(str);
	chunksiz = chunksiz == 0 ? strlen : chunksiz;
	return (ft_fstream_setup_buf(str, strlen, chunksiz));
}
