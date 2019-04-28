/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <awoimbee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/28 04:18:51 by awoimbee          #+#    #+#             */
/*   Updated: 2019/04/28 04:19:23 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC4_TYPE_H
# define VEC4_TYPE_H

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