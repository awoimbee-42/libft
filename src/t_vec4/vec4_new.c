/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <awoimbee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 03:07:09 by awoimbee          #+#    #+#             */
/*   Updated: 2019/04/30 02:28:50 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Hopefully this all gets inlined
**		Please, dear gods of C programming, let the compler inline all of this
**	It was not inlined. Not until now at least hehehe.
**		(C compilers are good but not magical)
*/

static inline t_vec4	vec4_newf(const float f)
{
	return ((t_vec4)_mm_set1_ps(f));
}

static inline t_vec4	vec4_newv(const float x, const float y, const float z,
	const float w)
{
	return ((t_vec4)_mm_setr_ps(x, y, z, w));
}

static inline t_vec4	vec4_newzero(void)
{
	return ((t_vec4)_mm_setzero_ps());
}

/*
**	not sure about this one
*/

static inline t_vec4	vec4_newnan(void)
{
	return ((t_vec4)_mm_castsi128_ps(_mm_set1_epi32(0x7FC00000)));
}
