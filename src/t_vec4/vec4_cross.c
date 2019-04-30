/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dot_mod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <awoimbee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 15:42:51 by awoimbee          #+#    #+#             */
/*   Updated: 2019/04/30 02:26:50 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <math.h>

/*
**	FST BUT DUNNO IF IT ACTUALLY WORKS
**	result = _mm_sub_ps(
**	_mm_mul_ps(b.sse, _mm_shuffle_ps(a.sse, a.sse, _MM_SHUFFLE(3, 0, 2, 1))),
**	_mm_mul_ps(a.sse, _mm_shuffle_ps(b.sse, b.sse, _MM_SHUFFLE(3, 0, 2, 1)))
**	);
**	return _mm_shuffle_ps(result, result, _MM_SHUFFLE(3, 0, 2, 1 ));
*/

static inline t_vec4	vec4_cross(const t_vec4 a, const t_vec4 b)
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
