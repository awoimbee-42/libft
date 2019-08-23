/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <awoimbee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 10:08:02 by awoimbee          #+#    #+#             */
/*   Updated: 2019/08/21 14:01:06 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <check.h>

START_TEST (ft_memcpy_general)
{
	char	*data_heap = malloc(4096);
	char	data_stack[9];
	char	*ft_res = malloc(4096);
	char	*sys_res = malloc(4096);

	for (unsigned int i = 0; i < 4096 / sizeof(long int); i++)
		((long int*)data_heap)[i] = random();
	for (unsigned int i = 0; i < 9; i += 1)
		data_stack[i] = random();

	ft_memcpy(ft_res, data_heap, 4096);
	   memcpy(sys_res, data_heap, 4096);
	ck_assert_msg(memcmp(ft_res, sys_res, 4096) == 0, "Failed top copy 4096 random bytes");

	ft_memcpy(ft_res, &data_heap[555], 1);
	   memcpy(sys_res, &data_heap[555], 1);
	ck_assert_msg(memcmp(ft_res, sys_res, 4096) == 0, "Failed to copy 1 byte");

	ft_memcpy(&ft_res[99], &data_stack[0], 9);
	   memcpy(&sys_res[99], &data_stack[0], 9);
	ck_assert_msg(memcmp(ft_res, sys_res, 4096) == 0, "Failed to copy a 9 bytes array on the stack");

	char	*unalligned_data0 = aligned_alloc(257, 4096);
	char	*unalligned_data1 = aligned_alloc(257, 4096);
	ft_memcpy(ft_res, unalligned_data0, 40);
	   memcpy(sys_res, unalligned_data0, 40);
	ck_assert_msg(memcmp(ft_res, sys_res, 4096) == 0, "Failed to copy a 40 bytes from unaligned data");

	*((size_t*)unalligned_data0) = 0;
	*((size_t*)unalligned_data1) = 0;
	ft_memcpy(unalligned_data0, data_stack, 3);
	   memcpy(unalligned_data1, data_stack, 3);
	ck_assert_msg(memcmp(unalligned_data0, unalligned_data1, 8) == 0, "Failed to copy 3 bytes from stack to unaligned ptr");

	ft_memcpy(unalligned_data0, data_stack, 0);
	   memcpy(unalligned_data1, data_stack, 0);
	ck_assert(ft_memcpy(unalligned_data0, data_stack, 0)
		== memcpy(unalligned_data0, data_stack, 0));
	ck_assert_msg(memcmp(unalligned_data0, unalligned_data1, 8) == 0, "Failed to copy 3 bytes from stack to unaligned ptr");


	free(data_heap);
	free(ft_res);
	free(sys_res);
	free(unalligned_data0);
	free(unalligned_data1);
}
END_TEST

Suite	*build_suite_ft_memcpy(void)
{
	Suite	*s = suite_create("ft_memcpy");
	TCase	*tc = tcase_create("ft_memcpy_general");
	suite_add_tcase(s, tc);
	tcase_add_test(tc, ft_memcpy_general);
	return (s);
}
