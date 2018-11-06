/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 15:08:39 by qfremeau          #+#    #+#             */
/*   Updated: 2015/12/10 12:35:17 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft_test.h"

int		isprint_debug(void)
{
	int		i;

	i = 0;
	printf("*****isprint******\n");
	while (i <= 127)
	{
		printf("Test [%d]:%c   =  %d\n", i, i, isprint(i));
		i++;
	}
	printf("\n****ft_isprint****\n");
	i = 0;
	while (i <= 127)
	{
		printf("Test [%d]:%c   =  %d\n", i, i, ft_isprint(i));
		i++;
	}
	return (1);
}

int		toupper_debug(void)
{
	int		i;

	i = 0;
	printf("*****toupper******\n");
	while (i <= 127)
	{
		printf("Test [%d]:%c   =  %c\n", i, i, toupper(i));
		i++;
	}
	printf("\n****ft_toupper****\n");
	i = 0;
	while (i <= 127)
	{
		printf("Test [%d]:%c   =  %c\n", i, i, ft_toupper(i));
		i++;
	}
	return (1);
}

int		tolower_debug(void)
{
	int		i;

	i = 0;
	printf("*****tolower******\n");
	while (i <= 127)
	{
		printf("Test [%d]:%c   =  %c\n", i, i, tolower(i));
		i++;
	}
	printf("\n****ft_tolower****\n");
	i = 0;
	while (i <= 127)
	{
		printf("Test [%d]:%c   =  %c\n", i, i, ft_tolower(i));
		i++;
	}
	return (1);
}

int		isalnum_debug(void)
{
	printf("*****isalnum******\n");
	printf("Test a  =  %d\n", isalnum('a'));
	printf("Test G  =  %d\n", isalnum('G'));
	printf("Test 1  =  %d\n", isalnum('1'));
	printf("Test ~  =  %d\n", isalnum('~'));
	printf("****ft_isalnum****\n");
	printf("Test a  =  %d\n", ft_isalnum('a'));
	printf("Test G  =  %d\n", ft_isalnum('G'));
	printf("Test 1  =  %d\n", ft_isalnum('1'));
	printf("Test ~  =  %d\n", ft_isalnum('~'));
	return (1);
}

int		isdigit_debug(void)
{
	printf("*****isdigit******\n");
	printf("Test a  =  %d\n", isdigit('a'));
	printf("Test G  =  %d\n", isdigit('G'));
	printf("Test 1  =  %d\n", isdigit('1'));
	printf("Test ~  =  %d\n", isdigit('~'));
	printf("****ft_isdigit****\n");
	printf("Test a  =  %d\n", ft_isdigit('a'));
	printf("Test G  =  %d\n", ft_isdigit('G'));
	printf("Test 1  =  %d\n", ft_isdigit('1'));
	printf("Test ~  =  %d\n", ft_isdigit('~'));
	return (1);
}

int		isascii_debug(void)
{
	printf("*****isascii******\n");
	printf("Test a     =  %d\n", isascii('a'));
	printf("Test NUL   =  %d\n", isascii(0));
	printf("Test '133' =  %d\n", isascii(133));
	printf("****ft_isascii****\n");
	printf("Test a     =  %d\n", ft_isascii('a'));
	printf("Test NUL   =  %d\n", ft_isascii(0));
	printf("Test '133' =  %d\n", ft_isascii(133));
	return (1);
}

int		isalpha_debug(void)
{
	printf("*****isalpha******\n");
	printf("Test a  =  %d\n", isalpha('a'));
	printf("Test G  =  %d\n", isalpha('G'));
	printf("Test 1  =  %d\n", isalpha('1'));
	printf("Test ~  =  %d\n", isalpha('~'));
	printf("****ft_isalpha****\n");
	printf("Test a  =  %d\n", ft_isalpha('a'));
	printf("Test G  =  %d\n", ft_isalpha('G'));
	printf("Test 1  =  %d\n", ft_isalpha('1'));
	printf("Test ~  =  %d\n", ft_isalpha('~'));
	return (1);
}

int		memset_debug(void)
{
	char a[20] = "Hello World!";
	char b[20] = "Hello World!";
	
	printf("original string       =   %s\n\n", a);
	memset(a, '5', 6);
	printf("memset(a, '5', 6)     =   %s\n", a);
	ft_memset(b, '5', 6);
	printf("ft_memset(a, '5', 6)  =   %s\n", a);
	return (1);
}

int		strdup_debug(void)
{
	char a[20] = "Hello World!";

	printf("original a     =   %s\n\n", a);
	printf("strdup         =   %s\n", strdup(a));
	printf("ft_strdup      =   %s\n", ft_strdup(a));
	return (1);
}

int		itoa_debug(void)
{
	int i1 = 5;
	int i2 = 201;
	int i3 = 0;
	int i4 = 32;
	int i5 = -87;
	int i6 = -84259517;
	char *str1;
	char *str2;
	char *str3;
	char *str4;
	char *str5;
	char *str6;

	str1 = ft_itoa(i1);
	str2 = ft_itoa(i2);
	str3 = ft_itoa(i3);
	str4 = ft_itoa(i4);
	str5 = ft_itoa(i5);
	str6 = ft_itoa(i6);
	printf("%d  =  %s\n", i1, str1);
	printf("%d  =  %s\n", i2, str2);
	printf("%d  =  %s\n", i3, str3);
	printf("%d  =  %s\n", i4, str4);
	printf("%d  =  %s\n", i5, str5);
	printf("%d  =  %s\n", i6, str6);
	return (1);
}

int		atoi_debug(void)
{
	int i1;
	int i2; 
	int i3;
	int i4;
	int i5;
	int i6;
	int i7;
	char *str1 = "5";
	char *str2 = "2 087 561";
	char *str3 = "0";
	char *str4 = "-32";
	char *str5 = "-84	2    59 5 17";
	char *str6 = "45dd78z22-4d";
	char *str7 = "44-5";

	i1 = ft_atoi(str1);
	i2 = ft_atoi(str2);
	i3 = ft_atoi(str3);
	i4 = ft_atoi(str4);
	i5 = ft_atoi(str5);
	i6 = ft_atoi(str6);
	i7 = ft_atoi(str7);
	printf("%d  =  %s\n", i1, str1);
	printf("%d  =  %s\n", i2, str2);
	printf("%d  =  %s\n", i3, str3);
	printf("%d  =  %s\n", i4, str4);
	printf("%d  =  %s\n", i5, str5);
	printf("%d  =  %s\n", i6, str6);
	printf("%d  =  %s\n", i7, str7);
	return (1);
}

int		memchr_debug(void)
{
	char a[20] = "Hello World!";

	printf("original string        =   %s\n\n", a);
	
	printf("*****memchr******\n");
	printf("memchr(6) for 'r'      =   %s\n", memchr(a, 'r', 6));
	printf("memchr(12) for 'r'     =   %s\n", memchr(a, 'r', 12));
	printf("memchr(20) for 'y'     =   %s\n", memchr(a, 'y', 20));
	printf("memchr(20) for 'o'     =   %s\n\n", memchr(a, 'o', 20));

	printf("****ft_memchr****\n");
	printf("ft_memchr(6) for 'r'   =   %s\n", ft_memchr(a, 'r', 6));
	printf("ft_memchr(12) for 'r'  =   %s\n", ft_memchr(a, 'r', 12));
	printf("ft_memchr(20) for 'y'  =   %s\n", ft_memchr(a, 'y', 20));
	printf("ft_memchr(20) for 'o'  =   %s\n", ft_memchr(a, 'o', 20));

	return (1);
}

int		memmove_debug(void)
{
	char a[20] = "Hello World!";
	char b[20] = "Smile";
	
	printf("original a        =   %s\n", a);
	printf("original b        =   %s\n\n", b);
	memmove(a, b, 8);
	printf("memmove from b    =   %s\n", b);
	printf("memmove to a      =   %s\n\n", a);

	char c[20] = "Hello World!";
	char d[20] = "Smile";
	ft_memmove(c, d, 8);
	printf("ft_memmove from b =   %s\n", d);
	printf("ft_memmove to a   =   %s\n", c);
	return (1);
}

int		strcmp_debug(void)
{
	char a[20] = "Hello World!";
	char b[20] = "Hello world!";
	char c[20] = "Hello Yorld!";
	char d[20] = "Hello Sorld";
	char e[20] = "Hello World!";
	
	printf("original a       =   %s\n", a);
	printf("original b       =   %s\n", b);
	printf("original c       =   %s\n", d);
	printf("original d       =   %s\n", c);
	printf("original e       =   %s\n\n", e);

	printf("*****strcmp******\n");
	printf("strcmp a & b     =   %d\n", strcmp(a, b));
	printf("strcmp a & c     =   %d\n", strcmp(a, c));
	printf("strcmp a & d     =   %d\n", strcmp(a, d));
	printf("strcmp a & e     =   %d\n\n", strcmp(a, e));

	printf("****ft_strcmp****\n");
	printf("ft_strcmp a & b  =   %d\n", ft_strcmp(a, b));
	printf("ft_strcmp a & c  =   %d\n", ft_strcmp(a, c));
	printf("ft_strcmp a & d  =   %d\n", ft_strcmp(a, d));
	printf("ft_strcmp a & e  =   %d\n", ft_strcmp(a, e));
	return (1);
}


int		strncmp_debug(void)
{
	char a[20] = "Hello World!";
	char b[20] = "Hello world!";
	char c[20] = "Hello Yorld!";
	char d[20] = "Hello Sorld";
	char e[20] = "Hello World!";
	
	printf("original a       =   %s\n", a);
	printf("original b       =   %s\n", b);
	printf("original c       =   %s\n", d);
	printf("original d       =   %s\n", c);
	printf("original e       =   %s\n\n", e);

	printf("*****strncmp******\n");
	printf("strncmp(6) a & b     =   %d\n", strncmp(a, b, 6));
	printf("strncmp(8) a & c     =   %d\n", strncmp(a, c, 8));
	printf("strncmp(4) a & d     =   %d\n", strncmp(a, d, 4));
	printf("strncmp(20) a & e    =   %d\n\n", strncmp(a, e, 20));

	printf("****ft_strncmp****\n");
	printf("ft_strncmp(6) a & b  =   %d\n", ft_strncmp(a, b, 6));
	printf("ft_strncmp(8) a & c  =   %d\n", ft_strncmp(a, c, 8));
	printf("ft_strncmp(4) a & d  =   %d\n", ft_strncmp(a, d, 4));
	printf("ft_strncmp(20) a & e =   %d\n", ft_strncmp(a, e, 20));
	return (1);
}

int		strstr_debug(void)
{
	char a[20] = "Hello World!";
	char b[20] = "";
	char c[20] = "Hello yorld!";
	char d[20] = "Hello World! I am";
	char e[20] = "Hello World!";
	
	printf("original a       =   %s\n", a);
	printf("original b       =   %s\n", b);
	printf("original c       =   %s\n", d);
	printf("original d       =   %s\n", c);
	printf("original e       =   %s\n\n", e);

	printf("*****strstr******\n");
	printf("strstr a & b     =   %s\n", strstr(a, b));
	printf("strstr a & c     =   %s\n", strstr(a, c));
	printf("strstr a & d     =   %s\n", strstr(a, d));
	printf("strstr a & e     =   %s\n\n", strstr(a, e));

	printf("****ft_strstr****\n");
	printf("ft_strstr a & b  =   %s\n", ft_strstr(a, b));
	printf("ft_strstr a & c  =   %s\n", ft_strstr(a, c));
	printf("ft_strstr a & d  =   %s\n", ft_strstr(a, d));
	printf("ft_strstr a & e  =   %s\n", ft_strstr(a, e));
	return (1); 
}

int		strchr_debug(void)
{
	char a[20] = "Hello World!";
	int i1 = 'r';

	printf("%s\n", ft_strchr(a, i1));
	printf("%s\n", strchr(a, i1));
	return (1);
}

int		memcpy_debug(void)
{
	char a[20] = "Hello World!";
	char b[20] = "!dlroW olleH";
	
	printf("original a       =   %s\n", a);
	printf("original b       =   %s\n\n", b);
	memcpy(a, b, 6);
	printf("memcpy from b    =   %s\n", b);
	printf("memcpy to a      =   %s\n\n", a);

	char c[20] = "Hello World!";
	char d[20] = "!dlroW olleH";
	ft_memcpy(c, d, 6);
	printf("ft_memcpy from b =   %s\n", d);
	printf("ft_memcpy to a   =   %s\n", c);
	return (1);
}

int		memccpy_debug(void)
{
	char a[20] = "Hello World!";
	char b[20] = "Smile Everyday";
	
	printf("original a          =   %s\n", a);
	printf("original b          =   %s\n\n\n", b);

	printf("*****memccpy******\n");
	memccpy(a, b, '\0', 14);
	printf("memccpy(14) from b   =   %s    enchar is '\\0'\n", b);
	printf("memccpy(14) to a     =   %s\n\n", a);
	char c[20] = "Hello World!";
	memccpy(c, b, 'l', 6);
	printf("memccpy(6) from b    =   %s    enchar is 'l'\n", b);
	printf("memccpy(6) to a      =   %s\n\n", c);
	char f[20] = "Hello World!";
	memccpy(f, b, 'o', 6);
	printf("memccpy(6) from b    =   %s    enchar is 'o'\n", b);
	printf("memccpy(6) to a      =   %s\n\n\n", f);

	printf("****ft_memccpy*****\n");
	char d[20] = "Hello World!";
	memccpy(d, b, '\0', 14);
	printf("ft_memccpy(14) frm b =   %s    enchar is '\\0'\n", b);
	printf("ft_memccpy(14) to a  =   %s\n\n", d);
	char e[20] = "Hello World!";
	memccpy(e, b, 'l', 6);
	printf("ft_memccpy(6) from b =   %s    enchar is 'l'\n", b);
	printf("ft_memccpy(6) to a   =   %s\n\n", e);
	char g[20] = "Hello World!";
	memccpy(g, b, 'o', 6);
	printf("ft_memccpy(6) from b =   %s    enchar is 'o'\n", b);
	printf("ft_memccpy(6) to a   =   %s\n\n", g);
	return (1);
}

int		memalloc_debug(void)
{
	size_t size = 20;
	char *src;
	char *src1;

	src = ft_memalloc(20);
	src1 = calloc(5, 4);
	printf("***ft_memalloc***\n");
	printf("allocated  =  %s\n", src);
	printf("in array   =  %d-%d-%d-[...]-%d-[...]-%d-[...]-%d-%d-%d\n\n", src[1], src[2], src[3], src[10], src[12], src[18], src[19], src[20]);
	printf("*****calloc******\n");
	printf("allocated  =  %s\n", src1);
	printf("in array   =  %d-%d-%d-[...]-%d-[...]-%d-[...]-%d-%d-%d\n", src1[1], src1[2], src1[3], src1[10], src1[12], src1[18], src1[19], src1[20]);
	return (1);
}

int		bzero_debug(void)
{
	char a[20] = "Hello World!";
	char b[20] = "Hello World!";
	
	printf("original  =   %s\n\n", a);
	bzero(a, 6);
	printf("bzero     =   %s\n", a);
	ft_bzero(b, 6);
	printf("ft_bzero  =   %s\n", b);
	return (1);
}

int		strcat_debug(void)
{
	char	a[8]="Hello ";
	char	b[8]="World!";

	printf("original a       =   %s\n", a);
	printf("original b       =   %s\n\n", b);
	strcat(a, b);
	printf("strcat from b    =   %s\n", b);
	printf("strcat to a      =   %s\n\n", a);

	char	c[8]="Hello ";
	char	d[8]="World!";
	ft_strcat(c, d);
	printf("ft_strcat from b =   %s\n", d);
	printf("ft_strcat to a   =   %s\n", c);
	//printf("checking memory  =   7|%c| 8|%c| 9|%c| 10|%c|\n", c[7], c[8], c[9], c[10]);
	return (1);
}

int		strncat_debug(void)
{
	char	a[12]="Hello World";
	char	b[12]=" and Smile!";

	printf("original a          =   %s\n", a);
	printf("original b          =   %s\n\n", b);
	strncat(a, b, 6);
	printf("strncat(6) from b    =   %s\n", b);
	printf("strncat(6) to a      =   %s\n\n", a);

	char	c[12]="Hello World";
	char	d[12]=" and Smile!";
	ft_strncat(c, d, 6);
	printf("ft_strncat(6) frm b  =   %s\n", d);
	printf("ft_strncat(6) to a   =   %s\n", c);
	//printf("checking memory      =   17|%c| 18|%c| 19|%c| 20|%c|\n", c[17], c[18], c[19], c[20]);
	return (1);
}

int		strlcat_debug(void)
{
	char	a[13]="Hello World ";
	char	b[12]="and Smile!";

	printf("original a             =   %s\n", a);
	printf("original b             =   %s\n\n\n", b);

	char	c[13]="Hello World ";
	printf("*****strlcat******\n");
	printf("strlcat(0) returns     =   %lu\n", strlcat(c, b, 0));
	printf("if a was changed       =   %s\n", c);
	printf("if b was changed       =   %s\n\n", b);
	printf("strlcat(6) returns     =   %lu\n", strlcat(c, b, 6));
	printf("if a was changed       =   %s\n", c);
	printf("if b was changed       =   %s\n\n", b);

	char	d[13]="Hello World ";
	char	e[12]="and Smile!";
	printf("****ft_strlcat****\n");
	printf("ft_strlcat(0) returns  =   %zu\n", ft_strlcat(d, e, 0));
	printf("if a was changed       =   %s\n", d);
	printf("if b was changed       =   %s\n\n", e);
	printf("ft_strlcat(6) returns  =   %zu\n", ft_strlcat(d, e, 6));
	printf("if a was changed       =   %s\n", d);
	printf("if b was changed       =   %s\n\n", e);
	return (1);
}

/*void	parse_cmdline(int argc, char const *argv[])
{
	size_t		i;

	i = 0;
	if 
	while (i <= argc)
	{

	}
}

void	switch_functions(int place_enum)
{
	switch (place_enum)
	case 1:
	
}

int		main(int argc, char const *argv[])
{
	if (argc == 1)
	{
		while ( )
			try ()
	}
	parse_cmdline(argc - 1, argv + 1);
}*/
