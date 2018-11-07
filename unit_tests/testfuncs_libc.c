/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testfuncs_libc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <awoimbee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 10:44:07 by awoimbee          #+#    #+#             */
/*   Updated: 2018/11/07 12:28:35 by awoimbee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

void	test_atoi(void)
{
	printf(COL_GRN "testing atoi...\n" COL_RST);
	int		iatoi;
	int		ift_atoi;
	char	nbr[][12] = {"02147483647", "-2147483648", "-52", "-0", "++5", "--9", "+-8", "0", "1", "500"};

	for (int i = 0; i < 10; ++i)
	{
		iatoi = atoi(nbr[i]);
		ift_atoi = ft_atoi(nbr[i]);
		if (iatoi != ift_atoi)
		{
			printf(COL_RED "ERROR !\natoi gave:\t%d\nft_atoi gave:\t%d\noriginal number:\t%s\n\n" COL_RST, iatoi, ift_atoi, nbr[i]);
			free(nbr);
		}
	}
}

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

void	test_bzero(void)
{
	printf(COL_GRN "testing ft_bzero...\n" COL_RST);

	char str[12] = "StR\0 test\0\0E";
	char str2[12] = "StR\0 test\0\0E";
	str2[4] = 255;
	str[4] = 255;
	ft_bzero((void*)&str[0], 10);
	int	i;
	for (i = 0; i < 10; ++i)
		if (str[i] != 0)
			printf("ERROR !\nft_bzero didnt clear the memory:\ntest str : char str[12] = \"StR\\0 test\\0\\0E\";, stumbled on char %d\n\n", i);
	for (; i < 12; ++i)
		if (str[i] != str2[i])
			printf("ERROR !\nft_bzero cleared too much memory:\ntest str : char str[12] = \"StR\\0 test\\0\\0E\";, stumbled on char %d\n\n", i);
}

void	test_memset(void)
{
	printf(COL_GRN "testing ft_memset..\n" COL_RST);

	void	*s = malloc_safe(32);
	void	*ft_s = malloc_safe(32);

	((char *)s)[31] = 0;
	((char *)ft_s)[31] = 0;

	for (int c = -500; c < 500; ++c)
	{
		s = memset(s, c, 31);
		ft_s = ft_memset(ft_s, c, 31);
		if (strcmp(s, ft_s) != 0)
		{
			printf("ft_emset error :\n\tmemset gave\t%s\n\tft_memset gave\t%s\n\tc = %d\tlen =  31\n\n", s, ft_s, c);
		}
	}
	int c = 'E';
	for (int len = 0; len < 31; ++len)
	{
		s = memset(s, c, 31);
		ft_s = ft_memset(ft_s, c, 31);
		if (strcmp(s, ft_s) != 0)
		{
			printf("ft_emset error :\n\tmemset gave\t%s\n\tft_memset gave\t%s\n\tc = %d\tlen =  31\n\n", s, ft_s, c);
		}
	}
}

void	test_memcpy(void)
{
	printf(COL_GRN "testing ft_memcpy..\n" COL_RST);

	void	*s = malloc_safe(32);
	void	*ft_s = malloc_safe(32);

	char	src[] = "testfuck\0fuckbobsagget\0\0\tnietEE";
	void	*src2 = NULL;

	((char *)s)[31] = 0;
	((char *)ft_s)[31] = 0;

	for (int len = 0; len < 31; ++len)
	{
		s = memcpy(s, (void*)src, len);
		ft_s = ft_memcpy(ft_s, (void*)src, len);
		if (memcmp(s, ft_s, len) != 0)
		{
			printf("\tError :\n\tmemcpy gave\t%s\n\tft_memcpy gave\t%s\n\tsrc = \"testfuck\\0fuckbobsagget\\0\\0\\tnietEE\"\tlen = %d\n\n", s, ft_s, len);
		}
	}
}

void	test_memccpy(void)
{
	printf(COL_GRN "testing ft_memccpy..\n" COL_RST);

	char src1[22] = "qwertyuioplkdjfuerEtest";
	char dst1_0[21];
	char dst1_1[21];
	bzero(dst1_0, 21);
	bzero(dst1_1, 21);

	//test 1
	ft_memccpy(dst1_0, src1, 'E', 20);
	memccpy(dst1_1, src1, 'E', 20);
	if (memcmp(dst1_0, dst1_1, 20) != 0)
		printf(COL_RED "\tError 1\tmemccpyt: %s\tft_memccpy:%s\n" COL_RST, dst1_1, dst1_0);
	else
		printf("\ttest 1 OK\n");

	//test 2
	bzero(dst1_0, 20);
	bzero(dst1_1, 20);
	ft_memccpy(src1, dst1_0, '\0', 5);
	memccpy(src1, dst1_1, '\0', 5);
	if (memcmp(dst1_0, dst1_1, 20) != 0)
		printf(COL_RED "\tError 2\n" COL_RST);
	else
		printf("\ttest 2 OK\n");

	//test 3
	bzero(dst1_0, 20);
	bzero(dst1_1, 20);
	ft_memccpy(src1, dst1_0, 'r', 20);
	memccpy(src1, dst1_1, 'r', 20);
	if (memcmp(dst1_0, dst1_1, 20) != 0)
		printf(COL_RED "\tError 3\n" COL_RST);
	else
		printf("\ttest 3 OK\n");
}

void	test_memmove(void)
{
	printf(COL_GRN "testing ft_memmove..\n" COL_RST);

	//TEST 1
	char	src1_0[19] = "dontfuckthisupdude";
	char	src1_1[19] = "dontfuckthisupdude";

	memmove(src1_0, &src1_0[10], 5);
	ft_memmove(src1_1, &src1_1[10], 5);
	if (memcmp(src1_0, src1_1, 19) != 0)
		printf(COL_RED "\tError 1\n" COL_RST);
	else
		printf("\ttest 1 OK\n");

	//TEST 2
	char	src2[29] = "bfsbvbubsev\0jkdkjd\t\vldsfljdf";
	char	dst2_0[29] = "\0";
	char	dst2_1[29] = "\0";


	memmove(src2, dst2_0, 29);
	ft_memmove(src2, dst2_1, 29);
	if (memcmp(dst2_0, dst2_1, 29) != 0)
		printf(COL_RED "\tError 2:\tmemmove=%s\tft_memove=%s\n" COL_RST, dst2_0, dst2_1);
	else
		printf("\ttest 2 OK\n");

	//TEST 3
	if (ft_memmove(0, 0, 0) == 0)
		printf("\ttest 3 OK\n");
	else
		printf(COL_RED "\tError 3\n" COL_RST);

	//TEST 4
	src2[2] = 254;
	bzero(dst2_0, 29);
	bzero(dst2_1, 29);

	memmove(src2, dst2_0, 29);
	ft_memmove(src2, dst2_1, 29);
	if (memcmp(dst2_0, dst2_1, 29) != 0)
		printf(COL_RED "\tError 4\n" COL_RST);
	else
		printf("\ttest 4 OK\n");
}

void	test_memchr(void)
{

}




















