/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memfree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <awoimbee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 16:34:03 by awoimbee          #+#    #+#             */
/*   Updated: 2019/05/22 16:36:39 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

/*
**	ft_memdel but with a generic pointer type (void*)
**	Because using void** is so F*** DUMB, WTF 42
*/

void	ft_memfree(void *ap)
{
	if (!ap || !*((void**)ap))
		return ;
	free(*((void**)ap));
	*((void**)ap) = NULL;
}
