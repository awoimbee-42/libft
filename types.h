/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <awoimbee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 23:27:57 by awoimbee          #+#    #+#             */
/*   Updated: 2019/04/29 23:32:32 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LFT_TYPES_H
# define LFT_TYPES_H
# include <inttypes.h>
# include <string.h>
# include <x86intrin.h>

typedef uint32_t	t_queued;
typedef void		t_listed;

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

#endif
