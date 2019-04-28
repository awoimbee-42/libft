/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   abs_sqr_sqrt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <awoimbee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 03:40:08 by awoimbee          #+#    #+#             */
/*   Updated: 2019/04/28 04:49:27 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operators.h"

/*
**	god damn, not being able to use preproc if or SSE4/AVX SUCKS ASS
*/

/*
**	Creates a mask that removes the sign bit
*/

static inline t_vec4		vec4_abs(const t_vec4 a)
{
	__m128		mask;

	mask = _mm_castsi128_ps(_mm_set1_epi32(0x7FFFFFFF));
	return ((t_vec4)_mm_and_ps(a.sse, mask));
}

static inline t_vec4		vec4_sqrt(const t_vec4 a)
{
	return ((t_vec4)_mm_sqrt_ps(a.sse));
}

static inline t_vec4		vec4_square(const t_vec4 a)
{
	return (vec4_mul(a, a));
}
