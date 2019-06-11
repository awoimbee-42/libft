/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intrisics.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <awoimbee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 23:27:57 by awoimbee          #+#    #+#             */
/*   Updated: 2019/06/11 19:11:00 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTRISICS_H
# define INTRISICS_H
# include <inttypes.h>
# include <string.h>
# include <x86intrin.h>

# ifdef __AVX__
#  define LFT_AVX 1
# else
#  define LFT_AVX 0
# endif
# ifdef __SSE2__
#  define LFT_SSE2 1
# else
#  define LFT_SSE2 0
# endif

# define GNL_BUFF_SIZE 32768
# define GNL_FLUSH (char**)INTPTR_MAX

typedef uint32_t	t_queued;
typedef void		t_listed;
typedef int			t_vected;

typedef struct	s_list
{
	t_listed		*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

typedef struct	s_queue
{
	int				start;
	int				end;
	int				size;
	t_queued		*arr;
}				t_queue;

typedef union	u_vec4
{
	struct
	{
		float	x;
		float	y;
		float	z;
		float	w;
	}				flt;
	__m128			sse __attribute__((aligned(16)));
}				t_vec4;

typedef struct	s_vector
{
	t_vected		*arr;
	size_t			len;
	size_t			mem;
}				t_vector;

typedef struct	s_garbage
{
	void			**pointers;
	size_t			arr_len;
	size_t			mem_len;
}				t_garbage;

/*
**	Red and Black tree
*/

enum			e_rbtn_color
{
	BLACK = 0,
	RED
};

typedef struct	s_rbt_node
{
	int					dat;
	enum e_rbtn_color	col;
	struct s_rbt_node	*lft;
	struct s_rbt_node	*rgt;
	struct s_rbt_node	*up;
}				t_rbt_node;

typedef t_rbt_node	t_rb_tree;

#endif
