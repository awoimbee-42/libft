/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <awoimbee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 20:34:49 by awoimbee          #+#    #+#             */
/*   Updated: 2019/05/07 22:25:49 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>
# include "intrisics.h"
# include "libft.gen"

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
void			*ft_mempcpy(void *dst, const void *src, size_t n);
void			ft_mem64set(uint64_t *mem, uint64_t data, size_t memlen);
void			ft_mem32set(uint32_t *mem, uint32_t data, size_t memlen);
void			ft_mem16set(uint16_t *mem, uint16_t data, size_t memlen);

/*
**	#################### LIBSTR ####################
*/
size_t			ft_strlen(const char *s);
char			*ft_strdup(const char *s1);
char			*ft_strcpy(char *dst, const char *src);
char			*ft_strncpy(char *dst, const char *src, size_t len);
char			*ft_strcat(char *s1, const char *s2);
char			*ft_strncat(char *s1, const char *s2, size_t n);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
char			*ft_strstr(const char *haystack, const char *needle);
char			*ft_strnstr(const char *haystack, const char *needle,
						size_t len);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_strnew(size_t size);
void			ft_strdel(char **as);
void			ft_strclr(char *s);
void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int				ft_strequ(char const *s1, char const *s2);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s);
char			**ft_strsplit(char const *s, char c);
char			*ft_strrev(char *str);
int				ft_strcat_join(char **s1, char const *s2);
char			*ft_stpcpy(char *dest, const char *src);
int				ft_strncat_join(char **s1, char const *s2, size_t size);
char			*ft_strndup(const char *s1, size_t maxlen);

/*
**	##################### LIBNB ####################
*/
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

/*
**	#################### LIBCHAR ###################
*/
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_toupper(int c);
int				ft_tolower(int c);

/*
**	##################### LIBFD ####################
*/
void			ft_putchar(char c);
void			ft_putstr(char const *s);
void			ft_putendl(char const *s);
void			ft_putnbr(int n);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char const *s, int fd);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putnbr_fd(int n, int fd);
int				get_next_line(const int fd, char **line);

/*
**	################### FT_PRINTF ##################
*/
int				ft_printf(const char *restrict format, ...);
int				ft_fprintf(int fd, const char *restrict format, ...);
int				ft_sprintf(char *str, const char *restrict format, ...);
int				ft_asprintf(char **strp, const char *fmt, ...);
char			*ft_cprintf(const char *fmt, ...);

/*
**	##################### T_LST ####################
*/
t_list			*ft_lstnew(void const *content, size_t content_size);
void			ft_lstdelone(t_list **alst, void (*del)(t_listed*, size_t));
void			ft_lstdel(t_list **alst, void (*del)(t_listed*, size_t));
void			ft_lstadd(t_list **alst, t_list *new);
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list			*ft_lst_push_back(t_list **lst, t_listed *data, size_t d_size);
t_list			*ft_list_at(t_list *begin_list, unsigned int nbr);
int				ft_lst_free_link(t_list **lst, t_list *link);

/*
**	##################### T_QUEUE ##################
*/
int				que_realloc(t_queue *que);
int				que_push(t_queue *que, t_queued data);
t_queued		que_pop(t_queue *que);
t_queue			*que_new(size_t len);
void			que_destroy(t_queue *que);
void			que_disp(const t_queue *que);
int				que_isempty(const t_queue *que);
t_queue			*que_flush(t_queue *q);

/*
**	##################### T_VEC4 ##################
*/

/*
**	t_vec4			vec4_newf(const float f);
**	t_vec4			vec4_newv(const float x, const float y, const float z,
**		const float w);
**	t_vec4			vec4_newa(const float f[4]);
**	t_vec4			vec4_newa3(const float f[3], float w);
**	t_vec4			vec4_newzero(void);
**	t_vec4			vec4_newnan(void);
**	t_vec4			vec4_add(const t_vec4 a, const t_vec4 b);
**	t_vec4			vec4_addf(const t_vec4 a, const float b);
**	t_vec4			vec4_sub(const t_vec4 a, const t_vec4 b);
**	t_vec4			vec4_subf(const t_vec4 a, const float b);
**	t_vec4			vec4_fsub(const float a, const t_vec4 b);
**	t_vec4			vec4_mul(const t_vec4 a, const t_vec4 b);
**	t_vec4			vec4_mulf(const t_vec4 a, const float b);
**	t_vec4			vec4_div(const t_vec4 a, const t_vec4 b);
**	t_vec4			vec4_divf(const t_vec4 a, const float b);
**	t_vec4			vec4_abs(const t_vec4 a);
**	t_vec4			vec4_sqrt(const t_vec4 a);
**	t_vec4			vec4_square(const t_vec4 a);
**	float			vec4_dot(const t_vec4 a, const t_vec4 b);
**	float			vec4_mod(const t_vec4 a);
**	float			vec4_mod2(const t_vec4 a);
**	t_vec4			vec4_cross(const t_vec4 a, const t_vec4 b);
**	t_vec4			vec4_matmul(const t_vec4 mat[4], const t_vec4 vec);
**	void			vec4_newmat_aa(t_vec4 mat[4], const float f[4][4]);
**	void			vec4_newmat_a(t_vec4 mat[4], const float f[16]);
*/

/*
**	T_VECTOR
*/
t_vector		*vector_init(t_vector *vec, const size_t reserved_len);
t_vector		*vector_push(t_vector *vec, t_vected d);
t_vector		*vector_realloc(t_vector *vec);
void			vector_mapvoid(t_vector *v, void (*f)(t_vected*));
t_vector		*vector_del_at(t_vector *v, size_t at);

/*
**	T_GARBAGE (sortof garbage collector)
*/
void			intrin__gb_fail(t_garbage *gb);
void			intrin_gb_extend(t_garbage *gb);
t_garbage		gb_init(void);
void			gb_freeall(t_garbage *gb);
void			gb_free(t_garbage *gb, void *ptr);
void			gb_remove(t_garbage *gb, void *freed);
void			*gb_malloc(t_garbage *gb, size_t size);
void			*gb_add(t_garbage *gb, void *malloced);
void			gb_defrag(t_garbage *gb);
void			*gb_memalloc(t_garbage *gb, size_t size);
void			*gb_realloc(t_garbage *gb, void *ptr, size_t new_size);
t_garbage		*gb_init_existing(t_garbage *gb);

/*
**	##################### other ####################
*/
void			msg_exit(const char *msg, const void *data);

#endif
