/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec4_dot.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <awoimbee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 02:25:16 by awoimbee          #+#    #+#             */
/*   Updated: 2019/04/30 02:49:37 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static inline __m128	__sse2_dot(const t_vec4 a, const t_vec4 b)
{
	__m128		mul;
	__m128		shuf;
	__m128		sums;

	mul = vec4_mul(a, b).sse;
	shuf = _mm_shuffle_ps(mul, mul, _MM_SHUFFLE(2, 3, 0, 1));
	sums = _mm_add_ps(mul, shuf);
	shuf = _mm_movehl_ps(shuf, sums);
	sums = _mm_add_ss(sums, shuf);
	return (sums);
}

static inline t_vec4	vec4_dotvec(const t_vec4 a, const t_vec4 b)
{
	if (LFT_AVX)
		return ((t_vec4)_mm_dp_ps(a.sse, b.sse, 0xff));
	else
		return ((t_vec4)__sse2_dot(a, b));
}

static inline float		vec4_dot(const t_vec4 a, const t_vec4 b)
{
	return (_mm_cvtss_f32(vec4_dotvec(a, b).sse));
}