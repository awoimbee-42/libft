/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_fstream.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <awoimbee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 15:10:17 by awoimbee          #+#    #+#             */
/*   Updated: 2020/10/29 22:07:12 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_FSTREAM_H
# define T_FSTREAM_H

# define _FSTREAM_MIN_READ 32768

# include <stdint.h>
# include <stdbool.h>
# include <string.h>

struct s_priv_fstream {
	int						fd;
	char					*fname;
	size_t					chunk_size;
	size_t					buf_size;
	size_t					buf_dat_len;
	uint8_t					*buf;
};

struct s_pub_fstream {
	size_t					total_len;
	size_t					len;
	uint8_t					*buf;
};

typedef struct	s_fstream {
	struct s_priv_fstream	priv;
	struct s_pub_fstream	p;
}				t_fstream;

t_fstream		*ft_fstream_setup_fd(int fd, size_t chunksiz);
t_fstream		*ft_fstream_setup_str(char *str, size_t chunksiz);
t_fstream		*ft_fstream_setup_fname(char *fname, size_t chunksiz);
t_fstream		*ft_fstream_setup_buf(void *buf, size_t siz, size_t chunksiz);
void			ft_fstream_kill(t_fstream *s);

bool			ft_fstream(t_fstream *dat);

#endif
