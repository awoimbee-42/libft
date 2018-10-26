/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <awoimbee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 01:07:04 by awoimbee          #+#    #+#             */
/*   Updated: 2018/10/23 02:08:26 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset (void *s, int c, size_t n)
{
  unsigned char *ptr;

  ptr = (unsigned char *)s;
  while (n-- > 0)
    *ptr++ = (unsigned char)c;
  return s;
}