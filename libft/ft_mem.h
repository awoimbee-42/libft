/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mem.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <awoimbee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 23:40:46 by awoimbee          #+#    #+#             */
/*   Updated: 2020/03/05 23:41:58 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MEM_H
# define FT_MEM_H
# include <stdint.h>

/*
**	#################### LIBMEM ####################
*/
void			*ft_memset (void *s, int c, size_t len);
void			ft_bzero(void *s, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_memalloc(size_t size);
void			ft_memdel(void **ap);
void			ft_memfree(void *ap);
void			*ft_mempcpy(void *dst, const void *src, size_t n);
void			ft_mem64set(uint64_t *mem, uint64_t data, size_t memlen);
void			ft_mem32set(uint32_t *mem, uint32_t data, size_t memlen);
void			ft_mem16set(uint16_t *mem, uint16_t data, size_t memlen);

#endif
