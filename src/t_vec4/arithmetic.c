/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arithmetic.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <awoimbee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 03:40:08 by awoimbee          #+#    #+#             */
/*   Updated: 2019/04/13 04:34:57 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <math.h>

/*
**	god damn, not being able to use preproc if or SSE4/AVX SUCKS ASS
*/

/*
**	Creates a mask that removes the sign bit
*/
t_vec4		vec4_abs(const t_vec4 a)
{
	__m128		mask;

	mask = _mm_castsi128_ps(_mm_set1_epi32(0x7FFFFFFF));
	return ((t_vec4)_mm_and_ps(a.sse, mask));
}

t_vec4		vec4_sqrt(const t_vec4 a)
{
	return ((t_vec4)_mm_sqrt_ps(a.sse));
}

t_vec4		vec4_square(const t_vec4 a)
{
	return (vec4_mul(a, a));
}

/*
**	a 'sane' person would use _mm_dp_ps() but we work on older machines ccc:
**	(thanks stackoverflow, I understant nothing about this code)
*/
float		vec4_dot(const t_vec4 a, const t_vec4 b)
{
	__m128		mul;
	__m128		shuf;
	__m128		sums;

	mul = vec4_mul(a, b).sse;
	shuf = _mm_shuffle_ps(mul, mul, _MM_SHUFFLE(2, 3, 0, 1));
	sums = _mm_add_ps(mul, shuf);
	shuf = _mm_movehl_ps(shuf, sums);
	sums = _mm_add_ss(sums, shuf);
	return (_mm_cvtss_f32(sums));
}

float		vec4_mod(const t_vec4 a)
{
	return (sqrtf(vec4_dot(a, a)));
}

float		vec4_mod2(const t_vec4 a)
{
	return (vec4_dot(a, a));
}

t_vec4		vec4_cross(const t_vec4 a, const t_vec4 b)
{
	__m128		res;

	res = _mm_sub_ps(
			_mm_mul_ps(
				_mm_shuffle_ps(a.sse, a.sse, _MM_SHUFFLE(3, 0, 2, 1)),
				_mm_shuffle_ps(b.sse, b.sse, _MM_SHUFFLE(3, 1, 0, 2))),
			_mm_mul_ps(
				_mm_shuffle_ps(a.sse, a.sse, _MM_SHUFFLE(3, 1, 0, 2)),
				_mm_shuffle_ps(b.sse, b.sse, _MM_SHUFFLE(3, 0, 2, 1))));
	return ((t_vec4)res);

}

/* // FST BUT DUNNO IF IT ACTUALLY WORKS
	result = _mm_sub_ps(
		_mm_mul_ps(b.sse, _mm_shuffle_ps(a.sse, a.sse, _MM_SHUFFLE(3, 0, 2, 1))),
		_mm_mul_ps(a.sse, _mm_shuffle_ps(b.sse, b.sse, _MM_SHUFFLE(3, 0, 2, 1)))
	);
	return _mm_shuffle_ps(result, result, _MM_SHUFFLE(3, 0, 2, 1 ));
*/