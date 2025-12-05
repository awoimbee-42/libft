/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nb.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <awoimbee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 00:42:16 by awoimbee          #+#    #+#             */
/*   Updated: 2020/03/11 19:21:47 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_NB_H
# define FT_NB_H

# include <inttypes.h>

void			ft_swap_int(int *a, int *b);
int				ft_atoi(const char *str);
char			*ft_itoa(int n);
int				ft_atoi_base(char *str, char *base);
char			*ft_itoa_base(int value, int base);
int				ft_abs(int i);
long			ft_labs(long i);
double			ft_atof(const char *nptr);
double			ft_atof_mv(char **nptr);
int				ft_atoi_mv(char **nptr);
int				ft_maxint(int a, int b);
long			ft_maxlong(long a, long b);
unsigned int	ft_maxuint(unsigned int a, unsigned int b);
unsigned int	ft_minuint(unsigned int a, unsigned int b);
uint64_t		ft_swap_endian64(uint64_t val);
uint32_t		ft_swap_endian32(uint32_t val);
uint16_t		ft_swap_endian16(uint16_t val);

#endif
