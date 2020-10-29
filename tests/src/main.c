/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <awoimbee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 12:49:23 by awoimbee          #+#    #+#             */
/*   Updated: 2020/10/28 16:44:23 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tests.h>

int		main(void)
{
	SRunner	*sr;
	int		nf;

	printf(PRTF_GRN "Testing libft..." PRTF_EOC "\n");
	srandom(time(NULL));
	sr = srunner_create(suite_create(""));

	build_tests_libmem(sr);
	build_tests_libstr(sr);
	build_tests_ft_nb(sr);
	build_tests_t_fstream(sr);

	srunner_run_all(sr, CK_ENV);
	nf = srunner_ntests_failed(sr);
	srunner_free(sr);

	return (nf == 0 ? 0 : 1);
}
