/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_fstream.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <awoimbee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 15:10:17 by awoimbee          #+#    #+#             */
/*   Updated: 2020/10/30 23:45:02 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_FSTREAM_H
# define T_FSTREAM_H

# define _FSTREAM_MIN_READ 32768

# include <stdint.h>
# include <stdbool.h>
# include <string.h>

enum			e_fstream_type {
	FSTREAM_BUF_MUT,
	FSTREAM_BUF,
	FSTREAM_FNAME,
	FSTREAM_FD,
};

struct			s_priv_fstream {
	enum e_fstream_type		type;
	int						fd;
	const char				*fname;
	size_t					chunk_size;
	size_t					buf_size;
	size_t					buf_dat_len;
	uint8_t					*buf;
};

struct			s_pub_fstream {
	size_t					total_len;
	size_t					len;
	uint8_t					*buf;
};

typedef struct	s_fstream {
	struct s_priv_fstream	priv;
	struct s_pub_fstream	s;
}				t_fstream;

t_fstream		*ft_fstream_setup_fd(int fd, size_t chunksiz);
t_fstream		*ft_fstream_setup_str(const char *str, size_t chunksiz);
t_fstream		*ft_fstream_setup_str_mut(char *str, size_t chunksiz);
t_fstream		*ft_fstream_setup_fname(const char *fname, size_t chunksiz);
t_fstream		*ft_fstream_setup_buf(const void *buf, size_t siz, size_t csiz);
t_fstream		*ft_fstream_setup_buf_mut(void *buf, size_t siz, size_t csiz);
void			ft_fstream_kill(t_fstream **s);
bool			ft_fstream(t_fstream *dat);
bool			ft_fstream_autofree(t_fstream **dat);

#endif
