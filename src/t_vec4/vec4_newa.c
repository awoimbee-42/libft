/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <awoimbee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 12:07:38 by awoimbee          #+#    #+#             */
/*   Updated: 2019/04/30 02:28:04 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static inline t_vec4		vec4_newa(const float f[4])
{
	return ((t_vec4)_mm_load_ps(f));
}

static inline t_vec4		vec4_newa3(const float f[3], float w)
{
	return (vec4_newv(f[0], f[1], f[2], w));
}
