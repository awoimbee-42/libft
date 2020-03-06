/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_defines.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <awoimbee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 00:29:31 by awoimbee          #+#    #+#             */
/*   Updated: 2020/03/06 00:29:56 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DEFINES_H
# define FT_DEFINES_H

# ifdef __AVX__
#  define LFT_AVX 1
# else
#  define LFT_AVX 0
# endif
# ifdef __SSE2__
#  define LFT_SSE2 1
# else
#  define LFT_SSE2 0
# endif

# define GNL_BUFF_SIZE 32768
# define GNL_FLUSH (char**)INTPTR_MAX

#endif
