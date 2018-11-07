/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   head.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <awoimbee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 10:48:48 by awoimbee          #+#    #+#             */
/*   Updated: 2018/11/07 12:15:25 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEAD_H
# define HEAD_H

# include <stdlib.h>
# include <limits.h>
# include <stdio.h>
# include "../libft/libft.h"

# define COL_RED "\x1B[31m"
# define COL_GRN "\x1B[32m"
# define COL_RST "\033[0m"


char		*itoa(int n);
void		*malloc_safe(size_t size);


void	test_memset(void);
void	test_atoi(void);
void	test_itoa(void);
void	test_bzero(void);
void	test_memcpy(void);
void	test_memccpy(void);
void	test_memmove(void);


#endif