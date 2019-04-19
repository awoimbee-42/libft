/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <awoimbee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 12:07:38 by awoimbee          #+#    #+#             */
/*   Updated: 2019/04/19 12:14:02 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_vec4		vec4_newa(const float f[4])
{
	return ((t_vec4)_mm_load_ps(f));
}

/*
**	This is just here to make creating vec4 from flt3 easier
*/

t_vec4		vec4_newa3(const float f[3], float w)
{
	return (vec4_newv(f[0], f[1], f[2], w));
}
