/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prtf.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <awoimbee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 23:50:55 by awoimbee          #+#    #+#             */
/*   Updated: 2020/03/05 23:52:23 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRTF_H
# define FT_PRTF_H
# include <stdarg.h>

int				ft_printf(const char *restrict format, ...);
int				ft_fprintf(int fd, const char *restrict format, ...);
int				ft_vfprintf(int fd, const char *restrict format, va_list *ap);
int				ft_asprintf(char **strp, const char *fmt, ...);
char			*ft_cprintf(const char *fmt, ...);

#endif
