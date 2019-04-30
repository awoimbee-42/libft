/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec4_mod.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <awoimbee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 02:27:07 by awoimbee          #+#    #+#             */
/*   Updated: 2019/04/30 02:46:53 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <math.h>

static inline float		vec4_mod(const t_vec4 a)
{
	return (sqrtf(vec4_dot(a, a)));
}

static inline float		vec4_mod2(const t_vec4 a)
{
	return (vec4_dot(a, a));
}