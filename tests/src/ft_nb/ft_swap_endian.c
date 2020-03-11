/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_endian.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <awoimbee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 12:50:27 by awoimbee          #+#    #+#             */
/*   Updated: 2020/03/11 13:03:24 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/ft_nb.h>
#include <check.h>

START_TEST (swap_endian64)
{
	uint64_t nb = 0x0102030405060708;
	uint64_t rev = 0x0807060504030201;
	uint64_t res = ft_swap_endian64(nb);
	ck_assert_int_eq(rev, res);
}
END_TEST

START_TEST (swap_endian32)
{
	uint32_t nb = 0x01020304;
	uint32_t rev = 0x04030201;
	uint32_t res = ft_swap_endian32(nb);
	ck_assert_int_eq(rev, res);
}
END_TEST

START_TEST (swap_endian16)
{
	uint32_t nb = 0x0102;
	uint32_t rev = 0x0201;
	uint32_t res = ft_swap_endian16(nb);
	ck_assert_int_eq(rev, res);
}
END_TEST

Suite	*build_suite_ft_swap_endian(void)
{
	Suite	*s = suite_create("ft_swap_endian");
	TCase	*tc = tcase_create("ft_swap_endian64");
	suite_add_tcase(s, tc);
	tcase_add_test(tc, swap_endian64);
	tcase_add_test(tc, swap_endian32);
	tcase_add_test(tc, swap_endian16);
	return (s);
}
