/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_test.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/05 18:43:23 by qfremeau          #+#    #+#             */
/*   Updated: 2015/12/08 16:35:13 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_TEST_H
# define LIBFT_TEST_H

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <setjmp.h>
#include "../../libft/libft.h"

void	test_exc(void (*f)(void));

#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KORG  "\x1B[33m"
#define RESET "\033[0m"

#endif
