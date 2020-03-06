/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec4_norm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <awoimbee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/12 18:35:20 by awoimbee          #+#    #+#             */
/*   Updated: 2020/03/06 00:35:26 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/t_vec4.h>
#include <math.h>

static inline t_vec4	vec4_norm(const t_vec4 v)
{
	return (vec4_divf(v, vec4_mod(v)));
}
