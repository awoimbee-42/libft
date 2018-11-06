/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_part1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 16:48:56 by qfremeau          #+#    #+#             */
/*   Updated: 2015/12/08 18:21:48 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft_test.h"

void	isprint_main(void)
{
	int		i;

	i = 0;
	while (i <= 127)
	{
		if (isprint(i) != ft_isprint(i))
			printf(KRED "FAILED!\n" RESET);
		i++;
	}
	printf(KGRN "OKAY! =D\n" RESET);
}

void	toupper_main(void)
{
	int		i;

	i = 0;
	while (i <= 127)
	{
		if (toupper(i) != ft_toupper(i))
			printf(KRED "FAILED!\n" RESET);
		i++;
	}
	printf(KGRN "OKAY! =D\n" RESET);
}

void	tolower_main(void)
{
	int		i;

	i = 0;
	while (i <= 127)
	{
		if (tolower(i) != ft_tolower(i))
			printf(KRED "FAILED!\n" RESET);
		i++;
	}
	printf(KGRN "OKAY! =D\n" RESET);
}

void	isalnum_main(void)
{
	int		i;

	i = 0;
	while (i <= 127)
	{
		if (isalnum(i) != ft_isalnum(i))
			printf(KRED "FAILED!\n" RESET);
		i++;
	}
	printf(KGRN "OKAY! =D\n" RESET);
}

void	isdigit_main(void)
{
	int		i;

	i = 0;
	while (i <= 127)
	{
		if (isdigit(i) != ft_isdigit(i))
			printf(KRED "FAILED!\n" RESET);
		i++;
	}
	printf(KGRN "OKAY! =D\n" RESET);
}

void	isascii_main(void)
{
	int		i;

	i = 0;
	while (i <= 127)
	{
		if (isascii(i) != ft_isascii(i))
			printf(KRED "FAILED!\n" RESET);
		i++;
	}
	printf(KGRN "OKAY! =D\n" RESET);
}

void	isalpha_main(void)
{
	int		i;

	i = 0;
	while (i <= 127)
	{
		if (isalpha(i) != ft_isalpha(i))
			printf(KRED "FAILED!\n" RESET);
		i++;
	}
	printf(KGRN "OKAY! =D\n" RESET);
}

void	atoi_main(void)
{
	int i1 = 5;
	int i2 = 2; 
	int i3 = 0;
	int i4 = -32;
	int i5 = -84;
	int i6 = 45;
	int i7 = 44;
	char *str1 = "5";
	char *str2 = "2 087 561";
	char *str3 = "0";
	char *str4 = "-32";
	char *str5 = "-84	2    59 5 17";
	char *str6 = "45dd78z22-4d";
	char *str7 = "44-5";

	if (ft_atoi(str1) == i1)
	{
		if (ft_atoi(str2) == i2)
		{
			if (ft_atoi(str3) == i3)
			{
				if (ft_atoi(str4) == i4)
				{
					if (ft_atoi(str5) == i5)
					{
						if (ft_atoi(str6) == i6)
						{
							if (ft_atoi(str7) == i7)
							{
								printf(KGRN "OKAY! =D\n" RESET);
								return;
							}
						}
					}
				}
			}
		}
	}
	printf(KGRN "FAILED!\n" RESET);
}

void	bzero_main(void)
{
	char a[20] = "Hello World!";
	char b[20] = "SmiLe-Idiot?";
	int i = 0;
	
	bzero(a, 6);
	ft_bzero(b, 6);
	while (i < 6)
	{
		if (a[i] == b[i])
			i++;
		else
		{
			printf(KRED "FAILED!\n" RESET);
			return;
		}
	}
	if (a[7] == b[7])
	{
		printf(KRED "FAILED!\n" RESET);
		return;
	}
	printf(KGRN "OKAY! =D\n" RESET);
}

void	memchr_main(void)
{
	char a[12] = "Hello World!";

	if ((memchr(a, 'r', 6)) == (ft_memchr(a, 'r', 6)))
	{
		if ((strcmp(memchr(a, 'r', 12), ft_memchr(a, 'r', 12))) == 0)
		{
			if ((memchr(a, 'y', 12)) == (ft_memchr(a, 'y', 12)))
			{
				if ((strcmp(memchr(a, 'o', 12), ft_memchr(a, 'o', 12))) == 0)
				{
					printf(KGRN "OKAY! =D\n" RESET);
					return;
				}
			}
		}
	}
	printf(KRED "FAILED!\n" RESET);
}

void	memmove_main(void)
{
	char b[20] = "Hello World!";
	char a[20] = "Smile";
	char d[20] = "Hello World!";
	char c[20] = "Smile";

	char i[20] = "Hello World!";
	char e[20] = "Smile";
	char f[20] = "Hello World!";
	char g[20] = "Smile";
	
	if ((strcmp(memmove(a, b, 8), ft_memmove(c, d, 8))) == 0)
	{
		if ((strcmp(memmove(i, e, 8), ft_memmove(f, g, 8))) == 0)
		{
			printf(KGRN "OKAY! =D\n" RESET);
			return;
		}
	}
	printf(KRED "FAILED!\n" RESET);
}

void	memset_main(void)
{
	char a[20] = "Hello World!";
	char b[20] = "Hello World!";
	
	if ((strcmp(memset(a, '5', 6), ft_memset(b, '5', 6))) == 0)
	{
		if ((strcmp(memset(a, 'o', 15), ft_memset(b, 'o', 15))) == 0)
		{
			printf(KGRN "OKAY! =D\n" RESET);
			return;
		}
	}
	printf(KRED "FAILED!\n" RESET);
}

void	memcpy_main(void)
{
	char a[20] = "Hello World!";
	char b[20] = "!dlroW olleH";
	char c[20] = "Hello World!";
	char d[20] = "!dlroW olleH";
	char e[2] = "";
	char f[2] = "";
	
	if ((strcmp(memcpy(a, b, 6), ft_memcpy(c, d, 6))) == 0)
	{
		if ((strcmp(memcpy(e, b, 6), ft_memcpy(f, d, 6))) == 0)
		{
			printf(KGRN "OKAY! =D\n" RESET);
			return;
		}
	}
	printf(KRED "FAILED!\n" RESET);
}

void	memccpy_main(void)
{

	char a[20] = "Hello World!";
	char b[20] = "Smile-Everyday";
	char c[20] = "Hello World!";
	char d[20] = "Hello World!";
	char e[20] = "Hello World!";
	char f[20] = "Hello World!";
	char g[20] = "Hello World!";

	char h[2] = "";
	char i[2] = "";
	char j[2] = "";
	
	memccpy(a, b, '\0', 12);
	ft_memccpy(d, b, '\0', 12);
	if ((strcmp(a, d)) == 0)
	{
		memccpy(c, b, 'l', 6);
		ft_memccpy(e, b, 'l', 6);
		if ((strcmp(c, e)) == 0)
		{
			memccpy(f, b, 'o', 6);
			ft_memccpy(g, b, 'o', 6);
			if ((strcmp(f, g)) == 0)
			{
				memccpy(i, h, 'a', 6);
				ft_memccpy(j, h, 'a', 6);
				if ((strcmp(i, j)) == 0)
				{
					printf(KGRN "OKAY! =D\n" RESET);
					return;
				}
			}
		}
	}
	printf(KRED "FAILED!\n" RESET);
}

void	memcmp_main(void)
{
	char a[20] = "Hello World!";
	char b[20] = "Hello world!";
	char c[20] = "Hello Yorld!";
	char d[20] = "";
	char e[20] = "Hello World!";

	if (memcmp(a, b, 6) == ft_memcmp(a, b, 6))
	{
		if (memcmp(a, c, 10) == ft_memcmp(a, c, 10))
		{
			if (memcmp(a, d, 6) == ft_memcmp(a, d, 6))
			{
				if (memcmp(a, e, 20) == ft_memcmp(a, e, 20))
				{
					printf(KGRN "OKAY! =D\n" RESET);
					return;
				}
			}
		}
	}
	printf(KRED "FAILED!\n" RESET);
}

void	strdup_main(void)
{
	char a[20] = "Hello World!";
	char b[1];

	if ((strcmp(strdup(a), ft_strdup(a))) == 0)
	{
		if ((strcmp(strdup(b), ft_strdup(b))) == 0)
		{
			printf(KGRN "OKAY! =D\n" RESET);
			return;
		}
	}
	printf(KRED "FAILED!\n" RESET);
}

void	strcmp_main(void)
{
	char a[20] = "Hello World!";
	char b[20] = "Hello world!";
	char c[20] = "Hello Yorld!";
	char d[20] = "Hello Sorld";
	char e[20] = "Hello World!";

	if (strcmp(a, b) == ft_strcmp(a, b))
	{
		if (strcmp(a, c) == ft_strcmp(a, c))
		{
			if (strcmp(a, d) == ft_strcmp(a, d))
			{
				if (strcmp(a, e) == ft_strcmp(a, e))
				{
					printf(KGRN "OKAY! =D\n" RESET);
					return;
				}
			}
		}
	}
	printf(KRED "FAILED!\n" RESET);
}

void	strncmp_main(void)
{
	char a[20] = "Hello World!";
	char b[20] = "Hello world!";
	char c[20] = "Hello Yorld!";
	char d[20] = "Hello Sorld";
	char e[20] = "Hello World!";
	
	if (strncmp(a, b, 6) == ft_strncmp(a, b, 6))
	{
		if (strncmp(a, c, 8) == ft_strncmp(a, c, 8))
		{
			if (strncmp(a, d, 4) == ft_strncmp(a, d, 4))
			{
				if (strncmp(a, e, 20) == ft_strncmp(a, e, 20))
				{
					printf(KGRN "OKAY! =D\n" RESET);
					return;
				}
			}
		}
	}
	printf(KRED "FAILED!\n" RESET);
}

void	strstr_main(void)
{
	char a[20] = "Hello World!";
	char b[20] = "";
	char c[20] = "Hello yorld!";
	char d[20] = "Hello World! I am";
	char e[20] = "Hello World!";
	
	if ((strcmp(strstr(a, b), ft_strstr(a, b))) == 0)
	{
		if (strstr(a, c) == ft_strstr(a, c))
		{
			if (strstr(a, d) == ft_strstr(a, d))
			{
				if ((strcmp(strstr(a, e), ft_strstr(a, e))) == 0)
				{
					printf(KGRN "OKAY! =D\n" RESET);
					return;
				}
			}
		}
	}
	printf(KRED "FAILED!\n" RESET);
}

void	strnstr_main(void)
{
	char	buf[10];

	bzero(buf, 10);
	strcpy(buf, "un deux 9");
	if (strcmp(ft_strnstr(buf, "deux", 10), "deux 9") == 0)
	{
		if (ft_strnstr(buf, "9", 3) == NULL)
		{
			if (strcmp(ft_strnstr(buf, "", 6), buf) == 0)
			{
				if (ft_strnstr(buf, "deux", 5) == NULL)
				{
					if (strcmp(ft_strnstr(buf, "9", 10), "9") == 0)
					{
						if (ft_strnstr(buf, "9", 8) == NULL)
						{
							printf(KGRN "OKAY! =D\n" RESET);
							return;
						}
					}
				}
			}
		}
	}
	printf(KRED "FAILED!\n" RESET);
}

void	strchr_main(void)
{
	char a[20] = "Hello World!";

	if ((strcmp(strchr(a, 'e'), ft_strchr(a, 'e'))) == 0)
	{
		if (strchr(a, 'w') == ft_strchr(a, 'w'))
		{
			if ((strcmp(strchr(a, 'W'), ft_strchr(a, 'W'))) == 0)
			{
				if (strchr(a, '1') == ft_strchr(a, '1'))
				{
					printf(KGRN "OKAY! =D\n" RESET);
					return;
				}
			}
		}
	}
	printf(KRED "FAILED!\n" RESET);
}

void	strrchr_main(void)
{
	char	buf[] = "abcdedcba";
	char	buf2[] = "abcd";

	if (strrchr(buf, 'a') == ft_strrchr(buf, 'a'))
	{
		if (strrchr(buf, 0) == ft_strrchr(buf, 0))
		{
			if (ft_strrchr(buf, 'z') == 0)
			{
				if (ft_strrchr(buf2, 'a') == buf2)
				{
					printf(KGRN "OKAY! =D\n" RESET);
					return;
				}
			}
		}
	}
	printf(KRED "FAILED!\n" RESET);
}

void	strcat_main(void)
{
	char	a[8]="Hello ";
	char	b[8]="W0rld!";
	char	c[8]="Hello ";
	char	d[2]="";
	char	e[2]="";
	char	f[2]="";
	char	g[2]="";
	char	h[2]="";

	if ((strcmp(strcat(a, b), ft_strcat(c, b))) == 0)
	{
		if ((strcmp(strcat(f, h), ft_strcat(g, h)) == 0))
		{
			if ((strcmp(strcat(d, b), ft_strcat(e, b)) == 0))
			{
				printf(KGRN "OKAY! =D\n" RESET);
				return;
			}
		}
	}
	printf(KRED "FAILED!\n" RESET);
}

void	strncat_main(void)
{
	char	buf[20];

	strcpy(buf, "To be ");
	ft_strncat(buf, "or not to be", 6);
	if (strcmp(buf, "To be or not") != 0)
	{
		printf(KRED "FAILED!\n" RESET);
		return;
	}
	ft_strncat(buf, "efefef", 0);
	if (strcmp(buf, "To be or not") != 0)
	{
		printf(KRED "FAILED!\n" RESET);
		return;
	}
	ft_strncat(buf, "", 0);
	if (strcmp(buf, "To be or not") != 0)
	{
		printf(KRED "FAILED!\n" RESET);
		return;
	}
	printf(KGRN "OKAY! =D\n" RESET);
}

void	strlcat_main(void)
{
	char	a[8]="Hello ";
	char	b[8]="W0rld!";
	char	c[8]="Hello ";
	char	d[2]="";
	char	e[2]="";
	char	f[2]="";
	char	g[2]="";
	char	h[2]="";

	if (strlcat(a, b, 6) == ft_strlcat(c, b, 6))
	{
		if (strlcat(f, h, 3) == ft_strlcat(g, h, 3))
		{
			if (strlcat(d, b, 15) == ft_strlcat(e, b, 15))
			{
				printf(KGRN "OKAY! =D\n" RESET);
				return;
			}
		}
	}
	printf(KRED "FAILED!\n" RESET);
}

void	strcpy_main(void)
{
	char a[20] = "Hello World!";
	char b[20] = "!dlroW olleH";
	char c[20] = "Hello World!";
	char d[20] = "!dlroW olleH";
	char e[2] = "";
	char f[2] = "";
	
	if ((strcmp(strcpy(a, b), ft_strcpy(c, d))) == 0)
	{
		if ((strcmp(strcpy(e, b), ft_strcpy(f, d))) == 0)
		{
			printf(KGRN "OKAY! =D\n" RESET);
			return;
		}
	}
	printf(KRED "FAILED!\n" RESET);
}

void	strncpy_main(void)
{
	char a[20] = "Hello World!";
	char b[20] = "!dlroW olleH";
	char c[20] = "Hello World!";
	char d[20] = "!dlroW olleH";
	char e[2] = "";
	char f[2] = "";
	
	if ((strcmp(strncpy(a, b, 20), ft_strncpy(c, d, 20))) == 0)
	{
		if ((strcmp(strncpy(e, b, 4), ft_strncpy(f, d, 4))) == 0)
		{
			if ((strcmp(strncpy(e, b, 0), ft_strncpy(f, d, 0))) == 0)
			{
				printf(KGRN "OKAY! =D\n" RESET);
				return;
			}
		}
	}
	printf(KRED "FAILED!\n" RESET);
}

void	strlen_main(void)
{
	char	a[12]="Hello World";
	char	b[6]="Smile!";
	char	c[2]="";


	if (ft_strlen(a) == strlen(a))
	{
		if (ft_strlen(b) == strlen(b))
		{
			if (ft_strlen(c) == strlen(c))
			{
				printf(KGRN "OKAY! =D\n" RESET);
				return;
			}
		}
	}
	printf(KRED "FAILED!\n" RESET);
}
