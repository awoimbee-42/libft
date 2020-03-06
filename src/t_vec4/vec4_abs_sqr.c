/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec4_abs_sqr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <awoimbee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 03:40:08 by awoimbee          #+#    #+#             */
/*   Updated: 2020/03/06 00:35:26 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/t_vec4.h>

/*
**	Creates a mask that removes the sign bit
*/

static inline t_vec4		vec4_abs(t_vec4 a)
{
	__m128		mask;

	mask = _mm_castsi128_ps(_mm_set1_epi32(0x7FFFFFFF));
	a.sse = _mm_and_ps(a.sse, mask);
	return (a);
}

static inline t_vec4		vec4_sqrt(t_vec4 a)
{
	a.sse = _mm_sqrt_ps(a.sse);
	return (a);
}

static inline t_vec4		vec4_square(t_vec4 a)
{
	return (vec4_mul(a, a));
}
