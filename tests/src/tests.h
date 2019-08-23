/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <awoimbee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 15:29:06 by awoimbee          #+#    #+#             */
/*   Updated: 2019/08/21 14:09:56 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_H
# define TESTS_H

# include <check.h>
# include <time.h>
# include <stdlib.h>
# include <stdio.h>
# include <libft.h>

# define PRTF_GRN "\e[32m"
# define PRTF_RED "\e[31m"
# define PRTF_EOC "\e[39m"

void	build_tests_libmem(SRunner *sr);
void	build_tests_libstr(SRunner *sr);

#endif
