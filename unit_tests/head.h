/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   head.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <awoimbee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 10:48:48 by awoimbee          #+#    #+#             */
/*   Updated: 2018/11/11 03:18:42 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEAD_H
# define HEAD_H

# include <stdlib.h>
# include <limits.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include "../libft.h"

# include <bsd/string.h>

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
void	test_memchr(void);
void	test_memcmp(void);
void	test_strlen(void);
void	test_strdup(void);
void	test_strcpy(void);
void	test_strncpy(void);
void	test_strcat(void);
void	test_strncat(void);
void	test_strlcat(void);


#endif