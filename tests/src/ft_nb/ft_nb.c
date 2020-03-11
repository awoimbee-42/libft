/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <awoimbee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 11:45:06 by awoimbee          #+#    #+#             */
/*   Updated: 2020/03/11 13:02:33 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <check.h>
#include "ft_nb.h"

void		build_tests_ft_nb(SRunner *sr)
{
	srunner_add_suite(sr, build_suite_ft_swap_endian());
}
