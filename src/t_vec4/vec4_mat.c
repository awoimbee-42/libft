/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <awoimbee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 15:35:20 by awoimbee          #+#    #+#             */
/*   Updated: 2019/04/28 19:29:58 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Here the matrix is defined by 4 vec4, each representing a row.
*/

static inline t_vec4	vec4_matmul(const t_vec4 mat[4], const t_vec4 vec)
{
	return (vec4_newv(
			vec4_dot(mat[0], vec),
			vec4_dot(mat[1], vec),
			vec4_dot(mat[2], vec),
			vec4_dot(mat[3], vec)));
}

static inline void		vec4_newmat_aa(t_vec4 mat[4], const float f[4][4])
{
	int		i;

	i = -1;
	while (++i < 4)
		mat[i] = vec4_newa(f[i]);
}

static inline void		vec4_newmat_a(t_vec4 mat[4], const float f[16])
{
	mat[0] = vec4_newa(&f[0]);
	mat[1] = vec4_newa(&f[4]);
	mat[2] = vec4_newa(&f[8]);
	mat[3] = vec4_newa(&f[12]);
}
