/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 15:08:39 by qfremeau          #+#    #+#             */
/*   Updated: 2015/12/10 12:58:10 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft_test.h"
#include "../includes/libft_part1.h"
#include "../includes/libft_part2.h"
#include "../includes/libft_bonus.h"

static void		test_part1(void)
{
	printf(KORG "\n==============TESTING-PART1==============\n" RESET);
	printf("Testing isprint functions:-----");
	test_exc(isprint_main);
	printf("Testing isalnum functions:-----");
	test_exc(isalnum_main);
	printf("Testing isdigit functions:-----");
	test_exc(isdigit_main);
	printf("Testing isascii functions:-----");
	test_exc(isascii_main);
	printf("Testing isalpha functions:-----");
	test_exc(isalpha_main);
	printf("Testing toupper functions:-----");
	test_exc(toupper_main);
	printf("Testing tolower functions:-----");
	test_exc(tolower_main);
	printf("Testing atoi functions:--------");
	test_exc(atoi_main);

	printf("\nTesting bzero functions:-------");
	test_exc(bzero_main);
	printf("Testing memset functions:------");
	test_exc(memset_main);
	printf("Testing memchr functions:------");
	test_exc(memchr_main);
	printf("Testing memmove functions:-----");
	test_exc(memmove_main);
	printf("Testing memcpy functions:------");
	test_exc(memcpy_main);
	printf("Testing memccpy functions:-----");
	test_exc(memccpy_main);
	printf("Testing memcmp functions:------");
	test_exc(memcmp_main);

	printf("\nTesting strdup functions:------");
	test_exc(strdup_main);
	printf("Testing strlen functions:------");
	test_exc(strlen_main);
	printf("Testing strcat functions:------");
	test_exc(strcat_main);
	printf("Testing strncat functions:-----");
	test_exc(strncat_main);
	printf("Testing strlcat functions:-----");
	test_exc(strlcat_main);
	printf("Testing strstr functions:------");
	test_exc(strstr_main);
	printf("Testing strnstr functions:-----");
	test_exc(strnstr_main);
	printf("Testing strcpy functions:------");
	test_exc(strcpy_main);
	printf("Testing strncpy functions:-----");
	test_exc(strncpy_main);
	printf("Testing strchr functions:------");
	test_exc(strchr_main);
	printf("Testing strrchr functions:-----");
	test_exc(strrchr_main);
	printf("Testing strcmp functions:------");
	test_exc(strcmp_main);
	printf("Testing strncmp functions:-----");
	test_exc(strncmp_main);
	printf("\n");
}

static void		test_part2(void)
{
	printf(KORG "\n==============TESTING-PART2==============\n" RESET);
	printf("Testing itoa functions:--------");
	test_exc(itoa_main);
	
	printf("\nTesting memalloc functions:----");
	test_exc(memalloc_main);
	printf("Testing memdel functions:------");
	test_exc(memdel_main);


	printf("\nTesting strclr functions:------");
	test_exc(strclr_main);
	printf("Testing strdel functions:------");
	test_exc(strdel_main);
	printf("Testing strequ functions:------");
	test_exc(strequ_main);
	printf("Testing strnequ functions:-----");
	test_exc(strnequ_main);
	printf("Testing strjoin functions:-----");
	test_exc(strjoin_main);
	printf("Testing strsplit functions:----");
	test_exc(strsplit_main);
	printf("Testing strsub functions:------");
	test_exc(strsub_main);
	printf("Testing strnew functions:------");
	test_exc(strnew_main);

	printf("Testing striter functions:-----");
	test_exc(striter_main);
	printf("Testing striteri functions:----");
	test_exc(striteri_main);
	printf("Testing strmap functions:------");
	test_exc(strmap_main);
	printf("Testing strmapi functions:-----");
	test_exc(strmapi_main);

	printf("\nTesting putchar functions:-----");
	test_exc(putchar_main);
	printf("Testing putstr functions:------");
	test_exc(putstr_main);
	printf("Testing putnbr functions:------");
	test_exc(putnbr_main);
	printf("Testing putendl functions:-----");
	test_exc(putendl_main);
	printf("Testing putchar_fd functions:--");
	test_exc(putchar_fd_main);
	printf("Testing putstr_fd functions:---");
	test_exc(putstr_fd_main);
	printf("Testing putnbr_fd functions:---");
	test_exc(putnbr_fd_main);
	printf("Testing putendl_fd functions:--");
	test_exc(putendl_fd_main);
	printf("\n");
}

static void		test_bonus()
{
	printf(KORG "\n==============TESTING-BONUS==============\n" RESET);
	printf("Testing lstadd functions:------");
	test_exc(lstadd_main);
	printf("Testing lstdel functions:------");
	test_exc(lstdel_main);
	printf("Testing lstdelone functions:---");
	test_exc(lstdelone_main);
	printf("Testing lstiter functions:-----");
	test_exc(lstiter_main);
	printf("Testing lstmap functions:------");
	test_exc(lstmap_main);
	printf("Testing lstnew functions:------");
	test_exc(lstnew_main);
	printf("\n");
}

static void 	test_all(void)
{
	test_part1();
	test_part2();
	test_bonus();
}

static void		help(void)
{
	printf(KORG "\nHere is the help!\n" RESET 
		"This programm helps you to test your libft project made at 42 - or\n"
		"anyone willing to recode on his/her own the lib c. It's just another\n"
		"test among other available on Github, and it was at first made to\n"
		"help me understand how to debug a code.\n"
		"If you are learning, I advise you better debugg your functions your-\n"
		"self. Or you can still help me to improve this debugging programm,\n"
		"that is quite simple to understand for newbies ;)\n"
		"\n"
		KORG "How to use me?!\n" RESET
		"Just enter those few arguments while executing the code:\n"
		KGRN" part1"RESET" = test only part 1 of libft;\n"
		KGRN" part2"RESET" = test only part 2 of libft;\n"
		KGRN" bonus"RESET" = test only bonus of libft;\n"
		KGRN" all"RESET" = test the whole libft, bonus included;\n"
		KGRN" -debug"RESET" = enter the debugging mode (still beta);\n"
		" 	'xxx' : where xxx is the name of the function to debugg.\n"
		" 	There can be one or more functions separated by space.\n"
		" 	If you enter no argument, everything will be debbug.\n"
		"	'exit' ; tape exit to go back to normal mode.\n"
		KGRN" help"RESET" = show this help file;\n");
}

static void		debug(void)
{
	printf(KORG "Entering the debugging mode\n" RESET);
}

int				main(int argc, char const *argv[])
{
	int 	i = 1;
	int 	count_loop = 0;
	int 	count_part1 = 0;
	int 	count_part2 = 0;
	int 	count_bonus = 0;
	int 	count_help = 0;
	int 	count_error = 0;

	if (argc == 1)
	{
		help();
		return (0);
	}
	if (strcmp(argv[1], "help") == 0)
	{
		help();
		return(0);
	}
	if (strcmp(argv[1], "-debug") == 0)
	{
		debug();
		return(0);
	}
	if (argc >= 16)
	{
		printf(KORG "Fatal error: Too many arguments" RESET);
		if (argc > 25)
			printf(KORG ": And there are more after!!" RESET);
		if (argc > 42)
			printf(KRED " WAY MORE!! Did you try to fool me?!" RESET);
		printf("\n");
		return (0);
	}
	if (argc > 1)
	{
		while (i < argc)
		{
			if (count_error == 10)
			{
				printf(KORG "Fatal error: Too many errors reached.\n" RESET);
				return(0);
			}
			if (strcmp(argv[i], "part1") == 0)
			{
				if (count_part1 != 0)
				{
					printf(KORG "Error %d:" RESET " 'part1' argument was already used.\n", count_error);
					count_error++;
					i++;
					continue;
				}
				test_part1();
				i++;
				count_loop++;
				count_part1++;
				continue;
			}
			else if (strcmp(argv[i], "part2") == 0)
			{
				if (count_part2 != 0)
				{
					printf(KORG "Error %d:" RESET " 'part2' argument was already used.\n", count_error);
					count_error++;
					i++;
					continue;
				}
				test_part2();
				i++;
				count_loop++;
				count_part2++;
				continue;
			}
			else if (strcmp(argv[i], "bonus") == 0)
			{
				if (count_bonus != 0)
				{
					printf(KORG "Error %d:" RESET " 'bonus' argument was already used.\n", count_error);
					count_error++;
					i++;
					continue;
				}
				test_bonus();
				i++;
				count_loop++;
				count_bonus++;
				continue;
			}
			else if (strcmp(argv[i], "all") == 0)
			{
				if (count_loop != 0)
				{
					printf(KORG "Error %d:" RESET " 'all' argument was skipped because it has to be used alone.\n", count_error);
					count_error++;
					i++;
					continue;
				}
				test_all();
				i++;
				if (argv[i] != NULL)
				{
					printf(KORG "Error %d:" RESET " the next arguments were skipped because 'all' was used.\n", count_error);
					count_error++;
					break;
				}
				break;
			}
			else if (strcmp(argv[i], "help") == 0)
			{
				if (count_help == 5)
				{
					printf(KORG "Fatal error: Stop asking for help, don't panic and carry a towel!\n" RESET);
					count_error++;
					return (0);
				}
				if (count_help != 0)
				{
					i++;
					count_error++;
					count_help++;
					continue;
				}
				printf(KORG "Error %d:" RESET " '-help' argument was skipped because it has to be used alone.\n", count_error);
				count_error++;
				i++;
				count_help++;
				continue;
			}
			else
			{
				printf(KORG "Error %d:" RESET " the argument %s wasn't recognized.\n", count_error, argv[i]);
				count_error++;
				i++;
				continue;
			}
			i++;
		}
	}
	return (0);
}
