/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec4_add_sub.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <awoimbee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 03:25:07 by awoimbee          #+#    #+#             */
/*   Updated: 2019/05/21 00:11:29 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static inline t_vec4		vec4_add(t_vec4 a, const t_vec4 b)
{
	a.sse = _mm_add_ps(a.sse, b.sse);
	return (a);
}

static inline t_vec4		vec4_addf(t_vec4 a, const float b)
{
	return (vec4_add(a, vec4_newf(b)));
}

static inline t_vec4		vec4_sub(t_vec4 a, const t_vec4 b)
{
	a.sse = _mm_sub_ps(a.sse, b.sse);
	return (a);
}

static inline t_vec4		vec4_subf(t_vec4 a, const float b)
{
	a.sse = _mm_sub_ps(a.sse, vec4_newf(b).sse);
	return (a);
}

static inline t_vec4		vec4_fsub(const float a, t_vec4 b)
{
	t_vec4		res;

	res.sse = _mm_sub_ps(vec4_newf(a).sse, b.sse);
	return (res);
}
