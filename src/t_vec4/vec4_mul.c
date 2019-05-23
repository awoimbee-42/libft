/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec4_mul.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <awoimbee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 03:32:58 by awoimbee          #+#    #+#             */
/*   Updated: 2019/05/21 01:13:15 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static inline t_vec4		vec4_mul(t_vec4 a, const t_vec4 b)
{
	a.sse = _mm_mul_ps(a.sse, b.sse);
	return (a);
}

static inline t_vec4		vec4_mulf(t_vec4 a, const float b)
{
	a.sse = _mm_mul_ps(a.sse, vec4_newf(b).sse);
	return (a);
}
