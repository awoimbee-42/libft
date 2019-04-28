/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addition.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <awoimbee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 03:25:07 by awoimbee          #+#    #+#             */
/*   Updated: 2019/04/28 19:28:31 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static inline t_vec4		vec4_add(const t_vec4 a, const t_vec4 b)
{
	return ((t_vec4)_mm_add_ps(a.sse, b.sse));
}

static inline t_vec4		vec4_addf(const t_vec4 a, const float b)
{
	return (vec4_add(a, vec4_newf(b)));
}

static inline t_vec4		vec4_sub(const t_vec4 a, const t_vec4 b)
{
	return ((t_vec4)_mm_sub_ps(a.sse, b.sse));
}

static inline t_vec4		vec4_subf(const t_vec4 a, const float b)
{
	return ((t_vec4)_mm_sub_ps(a.sse, vec4_newf(b).sse));
}

static inline t_vec4		vec4_fsub(const float a, const t_vec4 b)
{
	return ((t_vec4)_mm_sub_ps(vec4_newf(a).sse, b.sse));
}
