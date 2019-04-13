/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiplication.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <awoimbee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 03:32:58 by awoimbee          #+#    #+#             */
/*   Updated: 2019/04/13 03:54:54 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_vec4		vec4_mul(const t_vec4 a, const t_vec4 b)
{
	return ((t_vec4)_mm_mul_ps(a.sse, b.sse));
}

t_vec4		vec4_mulf(const t_vec4 a, const float b)
{
	return ((t_vec4)_mm_mul_ps(a.sse, vec4_newf(b).sse));
}

t_vec4		vec4_div(const t_vec4 a, const t_vec4 b)
{
	return ((t_vec4)_mm_div_ps(a.sse, b.sse));
}

t_vec4		vec4_divf(const t_vec4 a, const float b)
{
	return ((t_vec4)_mm_div_ps(a.sse, vec4_newf(b).sse));
}
