/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testfuncs_libc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awoimbee <awoimbee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 10:44:07 by awoimbee          #+#    #+#             */
/*   Updated: 2018/11/11 03:16:04 by awoimbee         ###   ########.fr       */
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
			printf(COL_RED "ERROR !\natoi gave:\t%d\nft_atoi gave:\t%d\noriginal number:\t%s\n\n" COL_RST, iatoi, ift_atoi, nbr[i]);
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
	str2[4] = (char)255;
	str[4] = (char)255;
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
			printf("ft_emset error :\n\tmemset gave\t%s\n\tft_memset gave\t%s\n\tc = %d\tlen =  31\n\n", (char *)s, (char *)ft_s, c);
		}
	}
	int c = 'E';
	for (int len = 0; len < 31; ++len)
	{
		s = memset(s, c, 31);
		ft_s = ft_memset(ft_s, c, 31);
		if (strcmp(s, ft_s) != 0)
		{
			printf("ft_emset error :\n\tmemset gave\t%s\n\tft_memset gave\t%s\n\tc = %d\tlen =  31\n\n", (char *)s, (char *)ft_s, c);
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
		s = memcpy(s, (void*)src, (size_t)len);
		ft_s = ft_memcpy(ft_s, (void*)src, (size_t)len);
		if (memcmp(s, ft_s, len) != 0)
		{
			printf("\tError :\n\tmemcpy gave\t%s\n\tft_memcpy gave\t%s\n\tsrc = \"testfuck\\0fuckbobsagget\\0\\0\\tnietEE\"\tlen = %d\n\n", s, ft_s, len);
		}
	}
}

void	test_memccpy(void)
{
	printf(COL_GRN "testing ft_memccpy..\n" COL_RST);

	char src1[22] = "qwertyuioplkdjfuerEtst";
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
	char a[12] = "Gneuhiat. -";

	if ((memchr(a, '.', 6)) == (ft_memchr(a, '.', 6))
		&& ((strcmp(memchr(a, '.', 12), ft_memchr(a, '.', 12))) == 0)
		&& ((memchr(a, 'E', 12)) == (ft_memchr(a, 'E', 12)))
		&& ((strcmp(memchr(a, 'a', 12), ft_memchr(a, 'a', 12))) == 0))
	{
		printf(COL_GRN "memchr OK\n" COL_RST);
		return;
	}
	printf(COL_RED "memchr FAILED!\n" COL_RST);
}

void	test_memcmp(void)
{
	char a[200] = "Temple OS is the greatest\0 achievment of mankind. \tRIP Terry A. Davis";
	char b[200] = "Temple OS is the greatest\0 achievment of mankind. \tRIP Terry A. Davis";
	char c[200] = "Temple OS is the greatest\0 achievment of mankind. \tRIP Terry A. Davis";
	char d[200] = "";
	char e[200] = "Temple OS is the greatest\0 achievment of mankind. \tRIP Terry A. Davis";
	int i = 0;

	if (  	memcmp(a, b, 10) == ft_memcmp(a, b, 10)		&& ++i
		&&	memcmp(a, c, 100) == ft_memcmp(a, c, 100)	&& ++i
		&&	memcmp(a, d, 20) == ft_memcmp(a, d, 20)		&& ++i
		)
	{
		printf(COL_GRN "memcmp OK\n" COL_RST);
		return;
	}
	printf(COL_RED "memcmp FAILED at test %d!\n" COL_RST, i);
}

void	test_strlen(void)
{
	int i = 0;

	if (ft_strlen("") == strlen("") && ++i
		&& ft_strlen("lol\0does it work") == strlen("lol\0does it work") && ++i
		&& ft_strlen("a") == strlen("a") && ++i
		&& ft_strlen("adfvhjoa\tkefgnksdfb") == strlen("adfvhjoa\tkefgnksdfb") && ++i
		)
	{
		printf(COL_GRN "strlen OK\n" COL_RST);
		return;
	}
	printf(COL_RED "strlen FAILED at test %d!\n" COL_RST, i);
}

void	test_strdup(void)
{
	int i = 0;

	if ( strcmp(strdup(""), ft_strdup(""))	== 0 && ++i
		&& strcmp(strdup("FUC\0K"), ft_strdup("FUC\0K")) == 0 && ++i
		&& strcmp(strdup(";JIO:FHoinbvOI\tdkg"), ft_strdup(";JIO:FHoinbvOI\tdkg")) == 0 && ++i
		)
	{
		printf(COL_GRN "strdup OK\n" COL_RST);
		return;
	}
	printf(COL_RED "strdup FAILED at test %d!\n" COL_RST, i);
}


void	test_strcpy(void)
{
	char a[50] = "I want to die";
	char b[50] = "this string is useless";
	char c[50] = "I want to die";
	char d[50] = "this string is useless";
	char e[2] = "";
	char f[2] = "";
	int i = 0;

	if (	memcmp(strcpy(a, b), ft_strcpy(c, d), 50) == 0 && ++i
		&&	memcmp(strcpy(b, e), ft_strcpy(d, f), 2) == 0 && ++i)
		{
			printf(COL_GRN "strcpy OK\n" COL_RST);
			return;
		}
	printf(COL_RED "strcpy FAILED test %d\n" COL_RST, i);
}

void	test_strncpy(void)
{
	char	a[50] = "I want to die";
	char	b[50] = "this string is useless";
	char	c[50] = "I want to die";
	char	d[50] = "this string is useless";
	char	e[2] = "";
	char	f[2] = "";
	int		i = 0;

	if (	memcmp(strncpy(a, b, 4), ft_strncpy(c, d, 4), 50) == 0 && ++i
		&&	memcmp(strncpy(b, e, 99), ft_strncpy(d, f, 99), 2) == 0 && ++i
		&&	memcmp(strncpy(e, b, 0), ft_strncpy(f, d, 0), 2) == 0 && ++i)
		{
			printf(COL_GRN "strncpy OK\n" COL_RST);
			return;
		}
	printf(COL_RED "strncpy FAILED test %d\n" COL_RST, i);
}

void	test_strcat(void)
{
	char	dest0_0[70] = "LKSJFGSGJDVPFBEPVBEFOGUHEGFABG";
	char	dest0_1[70] = "LKSJFGSGJDVPFBEPVBEFOGUHEGFABG";
	char	src0[50] = "TESTING IF IT WORKS";
	char	src1[1] = "";
	int		i = 0;

	if (
		memcmp(strcat(dest0_0, src0), ft_strcat(dest0_1, src0), 70) == 0 && ++i
		&& memcmp(strcat(dest0_0, src1), ft_strcat(dest0_0, src1), 70) == 0 && ++i
	)
	{
		printf(COL_GRN "strcat OK\n" COL_RST);
		return;
	}

	printf(COL_RED "strcat FAILED test %d\n" COL_RST, i);
}

void	test_strncat(void)
{
	char	dest0_0[70] = "LKSJFGSGJDVPFBEPVBEFOGUHEGFABG";
	char	dest0_1[70] = "LKSJFGSGJDVPFBEPVBEFOGUHEGFABG";
	char	src0[50] = "TESTING IF IT WORKS";
	char	src1[5] = "lol";
	int		i = 0;

	if (
		memcmp(strncat(dest0_0, src0, 60), ft_strncat(dest0_1, src0, 60), 70) == 0 && ++i
		&& memcmp(strncat(dest0_0, src0, 4), ft_strncat(dest0_0, src0, 4), 70) == 0 && ++i
		&& memcmp(strncat(src0, src1, 99), ft_strncat(src0, src1, 99), 50) == 0 && ++i
	)
	{
		printf(COL_GRN "strncat OK\n" COL_RST);
		return;
	}

	printf(COL_RED "strncat FAILED test %d\n" COL_RST, i);
}

void	test_strlcat(void)
{
	char	dest0_0[70] = "LKSJFGSGJDVPFBEPVBEFOGUHEGFABG";
	char	dest0_1[70] = "LKSJFGSGJDVPFBEPVBEFOGUHEGFABG";
	char	src0[50] = "TESTING IF IT WORKS";
	char	src0b[50] = "TESTING IF IT WORKS";
	char	src1[5] = "lol";
	int		i = 0;

	if (
		strlcat(dest0_0, src0, 60) == ft_strlcat(dest0_1, src0, 60)
		&& memcmp(dest0_0, dest0_1, 70) == 0 && ++i

		&& strlcat(dest0_0, src0, 4) == ft_strlcat(dest0_0, src0, 4)
		&& memcmp(dest0_0, dest0_1, 70) == 0 && ++i

		&& strlcat(src0, src1, 99) == ft_strlcat(src0, src1, 99)
		&& memcmp(src0, src0b, 50) == 0 && ++i
	)
	{
		printf(COL_GRN "strlcat OK\n" COL_RST);
		return;
	}

	printf(COL_RED "strlcat FAILED test %d\n" COL_RST, i);
}












