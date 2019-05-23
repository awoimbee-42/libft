/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec4_div.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <awoimbee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 02:30:26 by awoimbee          #+#    #+#             */
/*   Updated: 2019/05/21 00:14:56 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static inline t_vec4		vec4_div(t_vec4 a, const t_vec4 b)
{
	a.sse = _mm_div_ps(a.sse, b.sse);
	return (a);
}

static inline t_vec4		vec4_divf(t_vec4 a, const float b)
{
	a.sse = _mm_div_ps(a.sse, vec4_newf(b).sse);
	return (a);
}
