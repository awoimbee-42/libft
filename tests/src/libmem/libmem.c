/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libmem.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <awoimbee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 11:45:06 by awoimbee          #+#    #+#             */
/*   Updated: 2019/08/21 14:02:16 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <check.h>
#include "libmem.h"

void		build_tests_libmem(SRunner *sr)
{
	srunner_add_suite(sr, build_suite_ft_memcpy());
}
