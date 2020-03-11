/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <awoimbee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 11:46:25 by awoimbee          #+#    #+#             */
/*   Updated: 2020/03/11 13:00:40 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/ft_str.h>
#include <stdlib.h>
#include <check.h>
#include <string.h>

START_TEST (ft_strtrim_test)
{
	ck_assert(strcmp(ft_strtrim("    ThIs Is A tEsT !  "), "ThIs Is A tEsT !") == 0);
	ck_assert(strcmp(ft_strtrim("  \n  ThIs Is\tA tEsT!\t\n\t\n"), "ThIs Is\tA tEsT!") == 0);
	char *tmp = strdup("Another one ");
	ck_assert(strcmp(ft_strtrim(tmp), "Another one") == 0);
	free(tmp);
	char null = 0;
	ck_assert(strcmp(ft_strtrim(&null), &null) == 0);
}
END_TEST

START_TEST (ft_strtrim_test_only_spaces)
{
	ck_assert(strcmp(ft_strtrim("  \n  \t  \n  "), "") == 0);
}
END_TEST

Suite	*build_suite_ft_strtrim(void)
{
	Suite	*s = suite_create("ft_strtrim");
	TCase	*tc = tcase_create("ft_strtrim_all");

	suite_add_tcase(s, tc);
	tcase_add_test(tc, ft_strtrim_test);
	tcase_add_test(tc, ft_strtrim_test_only_spaces);
	return (s);
}
