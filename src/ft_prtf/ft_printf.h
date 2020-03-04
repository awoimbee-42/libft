/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <awoimbee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 16:53:52 by awoimbee          #+#    #+#             */
/*   Updated: 2020/03/04 13:05:46 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

# define TXT_DECORATIONS 1
# define INT_MIN -2147483648
# define INT_MAX 2147483647
# define MALLOC_ERR "Malloc error: not enough memory!"

# define FLAG_PLUS  1
# define FLAG_SPACE 2
# define FLAG_MINUS 4
# define FLAG_ZERO  8
# define FLAG_HASH  16
# define FLAG_SPEP  32

typedef struct	s_cnt_args
{
	int		nb;
	int		req_buff_siz;
}				t_cnt_args;

/*
**	struct	s_arg:
**		option contains the flags, its bits are assigned like this :
**			| '+' | ' ' | '-' | '0' | '#' | NA | NA | NA |
**		m_width (minimum width):
**			what is called [width] in the specs, default = 0
**		precis:
**			what is called [.precision] in the specs, default = -1
**		size:
**			integer set according to [size]:
**				hh     => -2
**				h      => -1
**				(null) => 0
**				l|w    => 1
**				ll|L   => 2
**				z      => 10 (for size_t)
**		conv_typ:
**			type ('d' for int, ...)
*/
typedef	struct	s_arg
{
	uint8_t	option;
	int		m_width;
	int		precis;
	uint8_t	size;
	char	conv_typ;
}				t_arg;

/*
**	len = lengh of what should be printed (and is coherent)
**	siz = size of the memory reserved for the string
*/
typedef struct	s_string
{
	char	*str;
	size_t	len;
}				t_prtfstr;

/*
**	ft_printf + flags
*/
int				ft_printf(const char *restrict format, ...);
int				ft_fprintf(int fd, const char *restrict format, ...);
int				ft_sprintf(char *str, const char *restrict format, ...);
t_prtfstr		prtf__vprintf(const char *format, va_list *ap);

char			*prtf__s_itoa_base(long long int n, int base, t_arg *arg);
char			*prtf__u_itoa_base(unsigned long long n, int base, t_arg *arg);
char			*prtf__itoa_double(long double n, t_arg *arg);

void			prtf__flag_s(t_prtfstr *ret, char *str, t_arg *arg);
void			prtf__flag_c(t_prtfstr *ret, char c);
void			prtf__flag_r(t_prtfstr *ret, int fd);

/*
**	fill_arg_struct.c
*/
int				prtf__get_arg_option(t_arg *arg, const char **format);
int				prtf__get_arg_m_width(t_arg *arg, const char **format);
int				prtf__get_arg_precis(t_arg *arg, const char **format);
int				prtf__get_arg_size(t_arg *arg, const char **format);
int				prtf__get_arg_convtyp(t_arg *arg, const char **format);

/*
**	Parse the 'format' & output something
*/
void			prtf__join_arg(t_prtfstr *out, t_arg *arg_info, va_list *ap);
void			prtf__parse_bonus(t_prtfstr *out);

/*
**	sub_hub.c
*/
void			prtf__nb_signed(t_prtfstr *ret, va_list *ap, t_arg *arg_info);
void			prtf__nb_unsigned(t_prtfstr *ret, va_list *ap, int base,
								t_arg *arg);
void			prtf__nb_double(t_prtfstr *ret, va_list *ap, t_arg *arg_info);

/*
**	libN.c
*/
int				prtf__atoi_move(const char **nptr);
int				prtf__t_strncat(t_prtfstr *s1, char const *s2, size_t size);
int				prtf__msg_exit(char *msg);
char			*prtf__strsubrev(char *str, int begin);

#endif
