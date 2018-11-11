/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_libft.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <awoimbee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 16:33:00 by awoimbee          #+#    #+#             */
/*   Updated: 2018/11/11 17:51:03 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

void	test_itoa(void)
{
	printf(COL_GRN "testing itoa...\n" COL_RST);
	char	*citoa;
	char	*cft_itoa;
	int		nbr[] = {INT_MIN, INT_MAX, 0, 1, -56, 9546, 100, 10};
	for (int i = 0; i < 8; ++i)
	{
		citoa = itoa(nbr[i]);
		cft_itoa = ft_itoa(nbr[i]);
		if (strcmp(citoa, cft_itoa) != 0)
			printf(COL_RED "ERROR !\nitoa gave:\t%s\nft_itoa gave:\t%s\noriginal number given:\t%d\n\n" COL_RST, citoa, cft_itoa, nbr[i]);
		free(citoa);
		free(cft_itoa);
	}
}

//DOES NOT COMPILE ON LINUX BECAUSE OF BSD LIBS SADLY
//EVEN AFTER INSTALLING THEM IT DOESNT WORK ON WSL ?

void	test_libc(void)
{
	test_memset();
	test_bzero();
	test_memcpy();
	test_memccpy();
	test_memmove();
	test_memchr();
	test_memcmp();
	test_strlen();
	test_strdup();
	test_strcpy();
	test_strncpy();
	test_strcat();
	test_strncat();
	test_strlcat();
	test_strchr();
	test_strrchr();
	test_strstr();
	test_strnstr();
	test_strcmp();
	test_strncmp();
	test_atoi();
	test_isthing();
	test_tothing();
}

int		main(void)
{

	printf("%d %d\n", strcmp("test1", "test"), ft_strcmp("test1", "test"));

	test_libc();
}