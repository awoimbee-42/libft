
// C program for Red-Black Tree insertion
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "libft.h"

#define MAP_NB_ELEMS 100000
#define MAP_NB_TESTS 50

int g_tmp0 = 0;

void	check_map(t_map *root)
{
	static t_map_key last = -999999;

	if (root == NULL)
		return;
	check_map(root->lft);
	++g_tmp0;
	if (root->key < last)
		printf("RED AND BLACK TREE NOT IN ORDER !\n"
			"current: %d last: %d\n",
			root->key, last);
	if ((uintptr_t)root->key != (uintptr_t)root->dat)
		printf("Key and data doesn't match!\n");
	last = root->key;
	check_map(root->rgt);
	last = -999999;
}

void	test_map(void)
{
	t_map *root = NULL;

	for (int i = 0; i < 50; ++i)
	{
		clock_t t0 = clock();
		for (int i = 0; i < MAP_NB_ELEMS; ++i)
		{
			int	a = random();
			map_insert(&root, (t_map_key)a, (t_map_data*)a);
		}
		clock_t t1 = clock();
		check_map(root);
		if (g_tmp0 != MAP_NB_ELEMS)
			printf("Found %lu elems instead of %d\n", g_tmp0, MAP_NB_ELEMS);
		g_tmp0 = 0;
		printf("insertion took %fms -> %fus/elem\n",
			(float)(t1 - t0) / CLOCKS_PER_SEC * 1000,
			(float)(t1 - t0) / CLOCKS_PER_SEC * 1000 / MAP_NB_ELEMS * 1000);
		map_freeall(&root);
	}
}

int main()
{
	srandom(time(NULL));
	test_map();
	return 0;
}
