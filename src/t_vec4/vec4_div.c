/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec4_div.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <awoimbee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 02:30:26 by awoimbee          #+#    #+#             */
/*   Updated: 2019/04/30 02:30:36 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static inline t_vec4		vec4_div(const t_vec4 a, const t_vec4 b)
{
	return ((t_vec4)_mm_div_ps(a.sse, b.sse));
}

static inline t_vec4		vec4_divf(const t_vec4 a, const float b)
{
	return ((t_vec4)_mm_div_ps(a.sse, vec4_newf(b).sse));
}
