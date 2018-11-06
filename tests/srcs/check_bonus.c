/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 16:56:19 by qfremeau          #+#    #+#             */
/*   Updated: 2015/12/10 12:50:43 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft_test.h"

static int ____diddel;

static void	del_test(void *data, size_t i)
{
	(void)data;
	(void)i;
	____diddel++;
}

static t_list	*lstmap_test_fn(t_list *list)
{
	t_list	*l2;

	l2 = malloc(sizeof(t_list));
	bzero(l2, sizeof(t_list));
	l2->content = malloc(list->content_size * 2);
	l2->content_size = list->content_size * 2;
	return (l2);
}

static void	lstiter_test(t_list *ppp)
{
	ppp->content_size = 42;
}

void	lstadd_main(void)
{
	t_list	*list;
	t_list	*list2;

	list = malloc(sizeof(t_list));
	list2 = malloc(sizeof(t_list));
	bzero(list, sizeof(t_list));
	bzero(list2, sizeof(t_list));
	ft_lstadd(&list2, list);
	if (list == list2)
	{
		if (list->next != NULL)
		{
			printf(KGRN "OKAY! =D\n" RESET);
			return;
		}
	}
	printf(KRED "FAILED!\n" RESET);
}

void	lstnew_main(void)
{
	t_list	*list;
	int 	ft;

	ft = 42;
	list = ft_lstnew(&ft, sizeof(int));
	if (!!list)
	{
		if ((*(int*)(list->content)) == 42)
		{
			list = ft_lstnew(NULL, 386);
			if ((list->content_size) == 0)
			{
				printf(KGRN "OKAY! =D\n" RESET);
				return;
			}
		}
	}
	printf(KRED "FAILED!\n" RESET);
}

void	lstdel_main(void)
{
	t_list	*list;
	int		ft;

	ft = 42;
	____diddel = 0;
	list = malloc(sizeof(t_list));
	bzero(list, sizeof(t_list));
	list->next = malloc(sizeof(t_list));
	bzero(list->next, sizeof(t_list));
	list->content = &ft;
	list->next->content = (&ft) + 1;
	ft_lstdel(&list, del_test);
	if (list == NULL)
	{
		if (____diddel == 2)
		{
			printf(KGRN "OKAY! =D\n" RESET);
			return;
		}
	}
	printf(KRED "FAILED!\n" RESET);
}

void	lstdelone_main(void)
{
	t_list	*list;
	int		ft;

	____diddel = 0;
	ft = 42;
	list = (t_list *)malloc(sizeof(t_list));
	list->content = &ft;
	list->content_size = sizeof(int);
	ft_lstdelone(&list, del_test);
	if (list == NULL)
	{
		if (____diddel == 1)
		{
			printf(KGRN "OKAY! =D\n" RESET);
			return;
		}
	}
	printf(KRED "FAILED!\n" RESET);
}

void	lstmap_main(void)
{
	t_list	*list;
	t_list	*map;

	bzero((list = malloc(sizeof(t_list))), sizeof(t_list));
	bzero((list->next = malloc(sizeof(t_list))), sizeof(t_list));
	list->content_size = 21;
	list->content = strdup("abc");
	list->next->content_size = 100;
	list->next->content = strdup("abc");
	map = ft_lstmap(list, lstmap_test_fn);
	if (list->content_size == 21)
	{
		if (list->next->content_size == 100)
		{
			if (!!map && map->content_size == 42)
			{
				if (!!map && map->next->content_size == 200)
				{
					printf(KGRN "OKAY! =D\n" RESET);
					return;
				}
			}
		}
	}
	printf(KRED "FAILED!\n" RESET);
}

void	lstiter_main(void)
{
	t_list	*list;

	bzero((list = malloc(sizeof(t_list))), sizeof(t_list));
	bzero(((list->next) = malloc(sizeof(t_list))), sizeof(t_list));
	ft_lstiter(list, lstiter_test);

	if (list->content_size == 42)
	{
		if (list->next->content_size == 42)
		{
			printf(KGRN "OKAY! =D\n" RESET);
			return;
		}
	}
	printf(KRED "FAILED!\n" RESET);
}
