/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_part2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 16:49:46 by qfremeau          #+#    #+#             */
/*   Updated: 2015/12/08 18:02:24 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft_test.h"

static void		it_test(char *c)
{
	*c = *c + 1;
}

static void		iti_test(unsigned int i, char *c)
{
	*c = *c + i;
}

static char		map_test(char c)
{
	return (c + 1);
}

static char		mapi_test(unsigned int i, char c)
{
	return (c + i);
}

void			itoa_main(void)
{
	int i1 = 5;
	int i2 = 201;
	int i3 = 0;
	int i4 = 32;
	int i5 = -87;
	int i6 = -84259517;
	char *str1 = "5";
	char *str2 = "201";
	char *str3 = "0";
	char *str4 = "32";
	char *str5 = "-87";
	char *str6 = "-84259517";

	if (strcmp(ft_itoa(i1), str1) == 0)
	{
		if (strcmp(ft_itoa(i2), str2) == 0)
		{
			if (strcmp(ft_itoa(i3), str3) == 0)
			{
				if (strcmp(ft_itoa(i4), str4) == 0)
				{
					if (strcmp(ft_itoa(i5), str5) == 0)
					{
						if (strcmp(ft_itoa(i6), str6) == 0)
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

void			strnew_main(void)
{
	char *mem1;
	char *mem2 = "Hello World";
	int i = 0;

	mem1 = ft_strnew(2000);
	while (i <= 2000)
	{
		if (mem1[i] != '\0')
		{
			printf(KRED "FAILED!\n" RESET);
			return;
		}
		i++;
	}
	i = 0;
	mem2 = ft_strnew(100);
	while (i <= 100)
	{
		if (mem2[i] != '\0')
		{
			printf(KRED "FAILED!\n" RESET);
			return;
		}
		i++;
	}
	printf(KGRN "OKAY! =D\n" RESET);
}

void			strsplit_main(void)
{
	char **tab;

	tab = ft_strsplit("***salut****!**", '*');
	if ((strcmp(tab[0], "salut") == 0) &&
			(strcmp(tab[1], "!") == 0) &&
				(tab[2] == NULL))
	{
		tab = ft_strsplit("*****", '*');
		if (tab[0] == NULL)
		{
			tab = ft_strsplit("coucou", '*');
			if ((strcmp(tab[0], "coucou") == 0) &&
				(tab[1] == NULL))
			 {
			 	tab = ft_strsplit("", '*');
			 	if (tab && tab[0] == NULL)
				{
					printf(KGRN "OKAY! =D\n" RESET);
					return;
				}
			}
		}
	}
	printf(KRED "FAILED!\n" RESET);
}

void			striter_main(void)
{
	char	str[] = "aBcDeF";

	ft_striter(str, it_test);
	if (strcmp(str, "bCdEfG") == 0)
	{
		printf(KGRN "OKAY! =D\n" RESET);
		return;
	}
	printf(KRED "FAILED!\n" RESET);
}

void			striteri_main(void)
{
	char	str[] = "aBcDeF";

	ft_striteri(str, iti_test);
	if (strcmp(str, "aCeGiK") == 0)
	{
		printf(KGRN "OKAY! =D\n" RESET);
		return;
	}
	printf(KRED "FAILED!\n" RESET);
}

void			strmap_main(void)
{
	char	*src;
	char	*dst;

	src = strdup("abcde");
	dst = ft_strmap(src, map_test);
	free(src);
	src = NULL;
	if (strcmp(dst, "bcdef") == 0)
	{
		printf(KGRN "OKAY! =D\n" RESET);
		return;
	}
	printf(KRED "FAILED!\n" RESET);
}

void			strmapi_main(void)
{
	char	*src;
	char	*dst;

	src = strdup("abcde");
	dst = ft_strmapi(src, mapi_test);
	free(src);
	src = NULL;
	if (strcmp(dst, "acegi") == 0)
	{
		printf(KGRN "OKAY! =D\n" RESET);
		return;
	}
	printf(KRED "FAILED!\n" RESET);
}

void			strequ_main(void)
{
	char a[20] = "Hello World!";
	char b[20] = "Hello world!";
	char c[20] = "Hello-World!";
	char d[20] = "Hello World";
	char e[20] = "Hello World!";

	if (ft_strequ(a, b) == 0)
	{
		if (ft_strequ(a, c) == 0)
		{
			if (ft_strequ(a, d) == 0)
			{
				if (ft_strequ(a, e) == 1)
				{
					printf(KGRN "OKAY! =D\n" RESET);
					return;
				}
			}
		}
	}
	printf(KRED "FAILED!\n" RESET);
}

void			strnequ_main(void)
{
	char a[20] = "Hello World!";
	char b[20] = "Hello world!";
	char c[20] = "Hello-World!";
	char d[20] = "Hello World";
	char e[20] = "Hello World!";

	if (ft_strnequ(a, b, 12) == 0)
	{
		if (ft_strnequ(a, c, 5) == 1)
		{
			if (ft_strnequ(a, d, 12) == 0)
			{
				if (ft_strnequ(a, e, 35) == 1)
				{
					printf(KGRN "OKAY! =D\n" RESET);
					return;
				}
			}
		}
	}
	printf(KRED "FAILED!\n" RESET);
}

void			strjoin_main(void)
{
	char	b[8]="W0rld!";
	char	c[8]="Hello ";
	char	e[2]="";
	char	g[2]="";
	char	h[2]="";

	if ((strcmp("Hello W0rld!", ft_strjoin(c, b))) == 0)
	{
		if ((strcmp("", ft_strjoin(g, h)) == 0))
		{
			if ((strcmp("W0rld!", ft_strjoin(e, b)) == 0))
			{
				printf(KGRN "OKAY! =D\n" RESET);
				return;
			}
		}
	}
	printf(KRED "FAILED!\n" RESET);
}

void			strsub_main(void)
{
	char	str[12]="hello W0rld!";

	if ((strcmp("lo W0", ft_strsub(str, 3, 5))) == 0)
	{
		if ((strcmp(ft_strsub(str, 0, 0), "")) == 0)
		{
			if (ft_strsub(str, 4, -10) == NULL)
			{
				if ((strcmp(" ", ft_strsub(str, 5, 1)) == 0))
				{
					printf(KGRN "OKAY! =D\n" RESET);
					return;
				}
			}
		}
	}
	printf(KRED "FAILED!\n" RESET);
}

void			strtrim_main(void)
{
	char	str[12]="hello W0rld!";

	if ((strcmp("lo W0", ft_strsub(str, 3, 5))) == 0)
	{
		if ((strcmp(ft_strsub(str, 0, 0), "")) == 0)
		{
			if (ft_strsub(str, 4, -10) == NULL)
			{
				if ((strcmp(" ", ft_strsub(str, 5, 1)) == 0))
				{
					printf(KGRN "OKAY! =D\n" RESET);
					return;
				}
			}
		}
	}
	printf(KRED "FAILED!\n" RESET);
}

void			strclr_main(void)
{
	char str1[14] = "Hello World!";
	char str2[2] = "";
	int  i = 0;

	ft_strclr(str1);
	while (i < 13)
	{
		if (str1[i] != '\0')
		{
			printf(KRED "FAILED!\n" RESET);
			return;
		}
		i++;
	}
	ft_strclr(str2);
	i = 0;
	while (i < 2)
	{
		if (str2[i] != '\0')
		{
			printf(KRED "FAILED!\n" RESET);
			return;
		}
		i++;
	}
	printf(KGRN "OKAY! =D\n" RESET);
}

void			strdel_main(void)
{
	char *mem1;
	char *mem2;

	mem1 = malloc(2000);
	if (!mem1)
	{
		printf(KORG "UNEXPECTED MALLOC ERROR\n" RESET);
		return;
	}
	ft_strdel(&mem1);
	if (mem1 == NULL)
	{
		mem2 = malloc(0);
		if (!mem2)
		{
			printf(KORG "UNEXPECTED MALLOC ERROR\n" RESET);
			return;
		}
		ft_strdel(&mem2);
		if (mem2 == NULL)
		{
			printf(KGRN "OKAY! =D\n" RESET);
			return;
		}
	}
	printf(KRED "FAILED!\n" RESET);
}

void			putchar_main(void)
{
	int		out;
	int		p[2];
	char	buf[4];

	out = dup(1);
	pipe(p);
	dup2(p[1], 1);
	ft_putchar('a');
	ft_putchar('C');
	ft_putchar('2');
	dup2(out, 1);
	read(p[0], buf, 3);
	buf[3] = 0;
	close(p[0]);
	close(p[1]);
	close(out);
	if (strcmp(buf, "aC2") == 0)
	{
		printf(KGRN "OKAY! =D\n" RESET);
		return;
	}
	printf(KRED "FAILED!\n" RESET);
}

void			putchar_fd_main(void)
{
	int		p[2];
	char	buf[4];

	pipe(p);
	ft_putchar_fd('a', p[1]);
	ft_putchar_fd('C', p[1]);
	ft_putchar_fd('2', p[1]);
	read(p[0], buf, 3);
	buf[3] = 0;
	close(p[0]);
	close(p[1]);
	if (strcmp(buf, "aC2") == 0)
	{
		printf(KGRN "OKAY! =D\n" RESET);
		return;
	}
	printf(KRED "FAILED!\n" RESET);
}

void			putstr_main(void)
{
	int		out;
	int		p[2];
	char	buf[14];

	out = dup(1);
	pipe(p);
	dup2(p[1], 1);
	ft_putstr("-hello World!");
	dup2(out, 1);
	read(p[0], buf, 13);
	buf[13] = 0;
	close(p[0]);
	close(p[1]);
	close(out);
	if (strcmp(buf, "-hello World!") == 0)
	{
		printf(KGRN "OKAY! =D\n" RESET);
		return;
	}
	printf(KRED "FAILED!\n" RESET);
}

void			putstr_fd_main(void)
{
	int		p[2];
	char	buf[14];

	pipe(p);
	ft_putstr_fd("-hello World!", p[1]);
	read(p[0], buf, 13);
	buf[13] = 0;
	close(p[0]);
	close(p[1]);
	if (strcmp(buf, "-hello World!") == 0)
	{
		printf(KGRN "OKAY! =D\n" RESET);
		return;
	}
	printf(KRED "FAILED!\n" RESET);
}


void			putnbr_main(void)
{
	int		out;
	int		p[2];
	char	buf[100];

	out = dup(1);
	pipe(p);
	dup2(p[1], 1);
	ft_putnbr(0);
	ft_putnbr(1);
	ft_putnbr(-1);
	ft_putnbr(12300);
	ft_putnbr(10203);
	ft_putnbr(-56);
	ft_putnbr(2147483647);
	ft_putnbr(-2147483648);
	dup2(out, 1);
	buf[read(p[0], buf, 100)] = 0;
	close(p[0]);
	close(p[1]);
	close(out);
	if (strcmp(buf, "01-11230010203-562147483647-2147483648") == 0)
	{
		printf(KGRN "OKAY! =D\n" RESET);
		return;
	}
	printf(KRED "FAILED!\n" RESET);
}

void			putnbr_fd_main(void)
{
	int		p[2];
	char	buf[100];

	pipe(p);
	ft_putnbr_fd(0, p[1]);
	ft_putnbr_fd(1, p[1]);
	ft_putnbr_fd(-1, p[1]);
	ft_putnbr_fd(12300, p[1]);
	ft_putnbr_fd(10203, p[1]);
	ft_putnbr_fd(-56, p[1]);
	ft_putnbr_fd(2147483647, p[1]);
	ft_putnbr_fd(-2147483648, p[1]);
	buf[read(p[0], buf, 100)] = 0;
	close(p[0]);
	close(p[1]);
	if (strcmp(buf, "01-11230010203-562147483647-2147483648") == 0)
	{
		printf(KGRN "OKAY! =D\n" RESET);
		return;
	}
	printf(KRED "FAILED!\n" RESET);
}

void			putendl_main(void)
{
	int		out;
	int		p[2];
	char	buf[15];

	out = dup(1);
	pipe(p);
	dup2(p[1], 1);
	ft_putendl("-hello World!");
	dup2(out, 1);
	read(p[0], buf, 14);
	buf[14] = 0;
	close(p[0]);
	close(p[1]);
	close(out);
	if (strcmp(buf, "-hello World!\n") == 0)
	{
		printf(KGRN "OKAY! =D\n" RESET);
		return;
	}
	printf(KRED "FAILED!\n" RESET);
}

void			putendl_fd_main(void)
{
	int		p[2];
	char	buf[15];

	pipe(p);
	ft_putendl_fd("-hello World!", p[1]);
	read(p[0], buf, 14);
	buf[14] = 0;
	close(p[0]);
	close(p[1]);
	if (strcmp(buf, "-hello World!\n") == 0)
	{
		printf(KGRN "OKAY! =D\n" RESET);
		return;
	}
	printf(KRED "FAILED!\n" RESET);
}

void			memdel_main(void)
{
	void *mem1;
	void *mem2;

	mem1 = malloc(2000);
	if (!mem1)
	{
		printf(KORG "UNEXPECTED MALLOC ERROR\n" RESET);
		return;
	}
	ft_memdel(&mem1);
	if (mem1 == NULL)
	{
		mem2 = malloc(0);
		if (!mem2)
		{
			printf(KORG "UNEXPECTED MALLOC ERROR\n" RESET);
			return;
		}
		ft_memdel(&mem2);
		if (mem2 == NULL)
		{
			printf(KGRN "OKAY! =D\n" RESET);
			return;
		}
	}
	printf(KRED "FAILED!\n" RESET);
}

void			memalloc_main(void)
{
	size_t		len = 100;
	void		*mem1, *mem2;

	mem1 = malloc(len);
	if (!mem1)
	{
		printf(KORG "UNEXPECTED MALLOC ERROR\n" RESET);
		return;
	}
	bzero(mem1, len);
	mem2 = ft_memalloc(len);
	if (!mem2)
	{
		printf(KRED "FAILED!\n" RESET);
		return;
	}
	if (memcmp(mem1, mem2, 100) == 0)
	{
		printf(KGRN "OKAY! =D\n" RESET);
		return;
	}
	printf(KRED "FAILED!\n" RESET);
}
